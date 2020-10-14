/*


思路:
1. 老师这里是暴力枚举了所有点是否是正确答案,因为一共有10^4个点,但是有2s,足够用了
2. 考察了:
	1. 连通分量
		逻辑:如果a,b两个点不属于同一个,并且这次input中a,b是链接的,就会少一个连通分量
		使用:并查集find()
	2. 如果是树,若有N个点,一定是N-1条边,(不多不少),多了就有环,少了就不连通(存在多个连通分量)
	3. 但是如果N个点,N-1条边,不一定是树. 例如:6个点,其中4个点是环,另2个点链接.虽然也是5条边,但是一个是环,一个是连通分量.

3. 老师说:
	1. 可以用bfs来看某个节点的每个叶子节点到该节点的距离
	2. 可以用dfs来遍历所有的叶子,然后返回值+1(因为高度+1)
4. 因为是无向图,所以在遍历的过程中,我们可能会遍历到过来的点.
	例如,假设我们是认为a点是根节点,往下遍历
	其中b点是a的子节点,我们会遍历b,但是遍历b的临点的时候也会遍历到a(因为无向图存储)
	所以我们要判断b的子节点是否等于b的父亲a,如果等于,就continue
5. dfs()在本题中的语意是:参数是int u,也就是u的叶子节点中到u节点的最大高度.
6. dfs()中,叶子节点的高度是0, 如果是叶子结点,会返回depth == 0
7. 注意: h[a]中的a是节点的编号:从1-N,所以很多for(int i = 1; ...) 而不是for(int i = 0; ...)




*/
#include <iostream>
#include <vector> //因为要用到vector.clear(), 所以不用普通数组
#include <cstring> //memset()

using namespace std;

const int N = 10010, M = 2 * N; //因为边数是点数的2倍
int h[N], e[M], ne[M], ind; //因为h[N]是存储每个节点的token, e[M]是存储很多条边
int p[N]; //并查集

void add(int a, int b){
	e[ind] = b, ne[ind] = h[a], h[a] = ind++; //你会发现a,b是编号:1到N
}

int find(int a){
	if(p[a] != a) p[a] = find(p[a]); //如果我的爸爸不是我的爷爷,就让我的爸爸成为我的爷爷,一直到我的爸爸是我的祖宗
	return p[a]; //这里返回的条件是 p[a] == a, 也就是a其实就是祖先.
}

int dfs(int cur, int source){
	int depth = 0;
	for(int i = h[cur]; ~i; i = ne[i]){ //遍历以cur的所有不包括自己父亲的临边
		int son = e[i];
		if(son == source) continue;
		depth = max(depth, dfs(son, cur) + 1); //需要儿子的最大depth+1 == 我的最大depth
	}
	return depth;
}
int main(){
	int n;
	cin >> n;
    
    //初始化单链表
    memset(h, -1, sizeof h);
	//初始化并查集
	for(int i = 1; i <= n; i++) p[i] = i;

	//读入n-1条边
	int k = n; //用于计算连通分量
	int a, b;
	for(int i = 0; i < n-1; i ++) {
	    cin >> a >> b;
		add(a,b), add(b,a); //你会发现a,b是编号:1到N
		if(find(a) != find(b)) //假如他们之前不是一个集合,但是现在input他们之间有边了
		{
			k--;
			p[find(a)] = find(b);
		}
	}	

	vector<int> res; //存output需要的节点
	int max_depth = -1;
	if(k >= 2){
		printf("Error: %d components", k);
	}
	else{
		for(int id = 1; id <= n; id ++){ //你会发现id是编号:1到N
			int depth = dfs(id, -1); //返回的depth就已经是以id为根节点的最大高度了.
			if(max_depth < depth)
			{
				max_depth = depth;
				res.clear();
				res.push_back(id);
			}
			else if(max_depth == depth){ //说明有多个相同高度, 因为题目说了要按编号排序,刚好我们也是从id == 1开始
				res.push_back(id);
			}
		}
	}

	for(auto i : res) cout << i << endl;
	return 0;
}
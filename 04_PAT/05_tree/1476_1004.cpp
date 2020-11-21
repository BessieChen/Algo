/*
思路:
1.
	1. 存树的形状
	3. 一般用dfs能做的bfs也能做,但是dfs代码短,不像bfs需要维护queue

	1. 主要考察树: 
	h[a]其实是a这个节点的叶子节点的token,这个token其实是ind,可以帮我们索引到一个链表,也就是说这个链表的所有元素,都是a这个节点的叶子节点
	假设h[a] == ind, 那么e[ind] == b说明节点a的一个子节点是b
	ne[ind] == ind2说明这个子节点b也有一个链表, 这个链表的token是ind2
		因为之前设置的时候ne[ind] = h[b]?

	故事是这样的,假设我们要给a节点的链表中插入一个b节点, 现在空余的token是ind
	h[a]表示的是, a节点的链表的头结点的token, 我们要注意, 加的方式是新来的元素是插入头结点, 想象:
	刚开始是h[a] = -1是什么都没有加过,之后分别加入cdf之后,链表是-1 -- c -- d -- f(头结点), 所以最后一个进入的f是在头结点
	谁是谁的next!!! c是d的next, 所以这是我之前纠结的地方,next是在左边, 其实你如果想象成f -- d -- c -- -1就是next在右边了! 
	所以假设d当时拿到的token是ind, ne[ind] == c的token!! 也就是b的next是c

	 现在空余的token是ind,既然ind还没用过, 我们就用吧
	e[ind] = b, 将e[ind]这个没有用过的地方, 放入b的值
	ne[ind] = h[a], 也就是我们将b的next,设置为之前的老的头结点(h[a])
	h[a] = ind++, 现在a节点的新的头节点是ind了!

	我给一个例子吧, 刚开始ind == 0, h[]所有初始化是-1
	void add(int a(8), int b(9))
	{
	    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
	    相当于是:
	    e[0] = 9, ne[0] = -1, h[8] = 0, ind = 1;
	}
	void add(int a(8), int c(7))
	{
	    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
	    相当于是:
	    e[1] = 7, ne[1] = 0, h[8] = 1, ind = 2;
	}

	遍历的时候:
	for (int i = h[u]; ~i; i = ne[i]) //注意-1的0x是1111 1111,所以~(-1) == 0
	        dfs(e[i]);
	i = h[8] == 1
	e[i] == e[1] 也就是c的值7
	i = ne[i] == ne[1] == 0, 也就是去到token是0的地方
	e[i] == e[0] 也就是b的值8
	i = ne[i] == ne[0] == -1
	结束  
2. 注意
	1. 题目input是01,02, 我不一定要写成string, int也是可以的, 只要保证数字都不相同就好了
*/


#include <iostream>
#include <cstring> // memset()

using namespace std;

const int N = 110;
int h[N], e[N], ne[N];
int ind; //全局变量初始是0
int cnt[N];
int maxdepth;// 需要记录maxdepth, 因为我们打印的时候, 需要打印cnt[N]的前maxdepth个元素

void add(int a, int b){
	e[ind] = b, ne[ind] = h[a], h[a] = ind++;
}

void dfs(int a, int depth){
	if(h[a] == -1) //叶子,所以要插入到我们的cnt中
	{
		cnt[depth]++;
		maxdepth = max(maxdepth, depth);
		return;
	}

	for(int i = h[a]; i != -1; i = ne[i]){
		dfs(e[i], depth+1);
	}
}

int main(){
	int n, m;
	cin >> n >> m;

	memset(h, -1, sizeof h);

	while(m--){
		int id, k;
		cin >> id >> k;
		while(k--){
			int son;
			cin >> son;
			add(id, son);//将b链接到a上
		}
	}

	dfs(1,0); //为什么是(1,0),因为题目说了根节点的值是01, 所以a==01==1, 然后第一层高度是0

	cout << cnt[0]; //一定能保证有一个叶子,因为如果只有一个根节点, 根节点就是叶子
	for(int i = 1; i <= maxdepth; i++) cout << " " << cnt[i];

	cout << endl;

	return 0;
}

int main(){
	int n, m;
	cin >> n >> m;

	memset(h, -1, sizeof h);

	while(m--){
		int id, k;
		cin >> id >> k;
		while(k--){
			int son;
			cin >> son;
			add(id, son);//将b链接到a上
		}
	}

	dfs(1,0); //为什么是(1,0),因为题目说了根节点的值是01, 所以a==01==1, 然后第一层高度是0

	cout << cnt[0]; //一定能保证有一个叶子,因为如果只有一个根节点, 根节点就是叶子
	for(int i = 1; i <= maxdepth; i++) cout << " " << cnt[i];

	cout << endl;

	return 0;
}
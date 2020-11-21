/*
1. 这道题经常考
2. 知识点: 如果知道前序+中序, 或者后续+中序, 是可以求出二叉树的. 但是知道前序 + 后序就不行.\
3. 求的过程
	1. 后序的最后一个节点是root(前序是第一个节点是root)
	2. 在中序中找到这个root, 左侧就是root的左子树(求出左侧长度n),右侧柚子树(求出右侧长度m)
	3. 后续中,因为是左子树+右子树+root,所以可以知道左子树是哪一段(截取长度为n),右子树是哪一段
	4. 后序中,左子树的最后一个节点是root
	5. 重复到2.
	老师用了递归
------------------
重新构建二叉树方法:
1. 在在中序中找到这个root,就是已知值, 找index, 所以我们用哈希表存, 快, 知道某个值的下标是多少
2. 重建二叉树,是一个递归的过程. 返回当前子树的根节点.
3. 老师在构建二叉树的时候,没有使用链接表,而是使用了两个哈希表.其实非常好
	1. 二叉树的重要内容就是, 某个节点(值)的左右儿子的ind是多少
	2. 一个哈希表存某个节点(用值表示)的左子树,一个存右边的
------------------
1. build()两种思路: 
	已知左子树在中序的ind是[il, k-1]
	求左子树在后序的ind是[pl, ?]
	1. 长度
		因为在中序中, 左子树的长度是(k-il), 因为是[il, k), k是指向左子树最后一个节点的下一位
		所以在后续中, 右子树的最后一个节点的下一位是 pl + (k-il)
		但是我们要求的是右子树的最后一个节点的位置, 所以是 pl + (k-il) - 1;
	2. 差相等
		老师说 ? - pl == k - 1 - il
		? == pl + (k - 1 - il)
2. 解释l[root] = build(il, k - 1, pl, pl + (k - 1 - il));
	build(il, k - 1, pl, pl + (k - 1 - il))返回root的左子树的根
	root的左子树的根,也就是root的左儿子
------------------
3. bfs()中,tt是指向了元素的,而不是元素的下一个

-----------------
4. 思考:
中序: 需要建立值和位置之间的map
后序: 不需要建立上面的map, 因为每次只要取最后一位.

5. 思考:
中序: 左子树+根+右子树
后序: 左子树+右子树+根

6. 思考:
build的参数传入的是相同的一个树,但是build()里面又有两个build()分别服务于左子树和右子树

7. 易错
右子树的后序的右侧节点是Pr-1,不是pr,因为pr是根节点
build(k+1, ir, (pr-1) + (k+1-ir), pr-1);//bug!容易错的地方,pr是root(回忆int root_val = postorder[pr]]),所以是pr-1!

8. 思考
重构二叉树,除了记录每个节点left,right,还需要知道root,最后通过root找左右,通过左右继续找左右.

9. 其他错误:
似乎不能用left,会和系统重名

10. 语法
1. 定义的时候
	应该是 int h = 0, t = 0;
	而不是int h = t = 0;
2. 如果已经定义了
	int h,t;
	h = t = 0;是没问题的



*/

#include <iostream>
#include <unordered_map> //用户哈希表存LR

using namespace std;

const int N = 40;
int postorder[N];
int inorder[N];
unordered_map<int, int> pos; //给一个节点的值(节点的值都不相同),返回这个节点在inorder中的位置.
unordered_map<int, int> l, r; //因为我们要重构二叉树.但这里不用单链表,老师说是二叉,所以设置每个节点的左右孩子就好了.
									//存的是左右孩子的值,而不是ind
int q[N];//用于bfs
									
int build(int il, int ir, int pl, int pr){
	//找root的值
	int root_val = postorder[pr];//根节点的值
	int k = pos[root_val];//知道根节点在中序中的位置

	//判断有无左右子树, 通过看k在中序中的位置
	if(il < k) //有left, 如果il == k说明没有left树
	{
		l[root_val] = build(il, k-1, pl, pl + (k-1-il));//见解释
	}
	if(k < ir)
	{
		r[root_val] = build(k+1, ir, (pr-1) + (k+1-ir), pr-1);//bug!容易错的地方,pr是root(回忆int root_val = postorder[pr]]),所以是pr-1!
	}
	return root_val; //返回根的值
}

void bfs(int root){
	q[0] = root;
	
	int h, t;//queue的队首和队尾
	h = t = 0;//或者直接://int h = 0, t = 0; 
	
	while(h <= t) //说明还有元素
	{
		int top = q[h ++]; //如果有元素, 取出, h指向下一个
		if(l.count(top)) q[++t] = l[top]; //有左孩子, t移到空位, 放入孩子
		if(r.count(top)) q[++t] = r[top];
	}
	//走到这里,q里面留下来了所有的顺序,注意这里不是真的pop掉了,所以q里面是有数据的.

	cout << q[0];
	for(int i = 1; i < h; i++) cout << ' ' << q[i]; //之所以写在这里,因为h是局部变量
	cout << endl;
}

int main(){

	int n;
	cin >> n;
	for(int i = 0; i < n; i++) cin >> postorder[i];
	for(int i = 0; i < n; i++)
	{
		cin >> inorder[i];
		pos[inorder[i]] = i; //给一个节点的值(节点的值都不相同),返回这个节点在inorder中的位置.
	}

	int root_val = build(0, n-1, 0, n-1);

	bfs(root_val);

	return 0;
}
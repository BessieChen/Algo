#include <iostream>
using namespace std;

const int N = 100010;
int head, e[N], ne[N], ind;
//e[n]: 数组中第n个节点的值是e[n]
//ne[n]: 在数组中第n个节点的下一个节点的索引是ne[n],所以下一个节点的值:e[ne[n]]

void init(){
	head = -1;
	ind = 0;
}

void add_to_head(int x){
	e[ind] = x;
	ne[ind] = head; //索引为ind的元素的下一个索引是head, 我之前的疑问, 我的下一个是head, 那为什么我是往头插呢,不是往尾部插呢. 这是因为:想象一个数组左边是index=0,但是我们的head是指向了整个数组的最右侧,所以说明某个元素的next其实是指向了左侧. 遍历的时候,是从最右侧的head开始往next遍历也就是往左遍历.
	ind ++;
	//e[ind] = x, ne[ind] = head, head = ind, ind ++;
}

//在ind==k的后面加上x
void add(int k, int x)
{
	e[ind] = x;
	ne[ind] = ne[k];
	ne[k] = ind;
	ind ++;
	//e[ind] = x, ne[ind] = ne[k], ne[k] = ind, ind++;
}

void remove(int k){
	ne[k] = ne[ne[k]];
}

int main(){

}
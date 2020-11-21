#include <iostream>

using namespace std;

const int N = 100010;
int head, e[N], ne[N];
int ind;

void init(){
	head = -1;
	ind = 0;
}

void add_head(int a){
	e[ind] = a, ne[ind] = head, head = ind++;
}

//假设之前是 (头结点) a --> b --> c --> d --> -1, 其中b是a的next,现在要变成a --> b --> e --> c --> d --> -1
//其中b是第3个加入的节点, 在b的后面加上一个数, 这里的后面是next
void add_k(int a, int k){
	e[ind] = a, ne[ind] = ne[k], ne[k] = ind++; //也就是我ind要指向你k的下一位,你k指向我
}


void remove(int k){
	ne[k] = ne[ne[k]]; //我k不指向我的下一个了,我指向我next的next
}
int main(){

	init();

	int m;
	cin >> m;
	while(m--){
		char op; //老师用的是char
		int k, x;
		cin >> op;
		if(op == 'H'){
			cin >> x;
			add_head(x);
		}
		else if(op == 'I'){
			cin >> k >> x;
			add_k(x, k-1); //因为说的是第1个加入的元素,其实是ind==0的位置,所以k-1
		}
		else{
			cin >> k;
			if(!k) head = ne[head]; //head的next是ne[head], 所以head变成head的next
			remove(k-1);//因为说的是第1个加入的元素,其实是ind==0的位置,所以k-1
		}
	}

	for(int i = head; ~i; i = ne[i]){
		cout << e[i] << " ";
	}
	cout << endl;

	return 0;

}
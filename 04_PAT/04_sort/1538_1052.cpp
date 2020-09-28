#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct Node{
	string addr;
	int val;
	string next;

	bool operator< (const Node& t) const{
		return val < t.val; //我优先(排在左边)的条件, 我的值更小
	}
};

int main(){
	int n;
	char head[6];
	scanf("%d %s", &n, head);

	char addr[10], next[10];
	int val;
	unordered_map<string, Node> map;
	while(n --){
		scanf("%s %d %s", addr, &val, next);
		map[addr] = {addr, val, next};
	}	

	//制作链表,把每个节点都推入vector
	vector<Node> vec;
	for(string i = head; i != "-1"; i = map[i].next ) vec.push_back(map[i]);

    printf("%d ", (int)vec.size());
	//对vec排序, 会用到Node的小于号
	if(vec.size())
    {
        sort(vec.begin(), vec.end());
        printf("%s\n", vec[0].addr.c_str()); //打印头结点地址, 注意要c_str()

        for(int i = 0; i < (int)vec.size(); i++){ //注意如何判断是否是最后一个节点
            if(i == (int)vec.size()-1)
		        printf("%s %d %d\n", vec[i].addr.c_str(), vec[i].val, -1);  //尾结点的next是-1
		    else
		        printf("%s %d %s\n", vec[i].addr.c_str(), vec[i].val, vec[i+1].addr.c_str()); //小心bug! 最后是%s,不是%d, 另一个bug, 最后输出的是vec[i+1].addr而不是vec[i].next;
        }
	}
    else{
        puts("-1");
    }
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

vector<int> mul2(vector<int> &A, int b){
    vector<int> C;
    int t = 0;
    for(unsigned int i = 0; i < A.size() || t ; i++) //合并了while
    {
        if(i < A.size()) t = A[i] * b + t; // 还有上一次的
        C.push_back(t % 10);
        t /= 10;
    }
    
    while(C.size() > 1 && C.back() == 0) C.pop_back();

    
    return C;
}

vector<int> mul(vector<int> &A, int b){
    vector<int> C;
    int t = 0;
    for(unsigned int i = 0; i < A.size() ; i++)
    {
        t = A[i] * b + t; //还有上一次的
        C.push_back(t % 10);
        t /= 10;
    }
    
    while(t){
        C.push_back(t % 10);
        t /= 10;
    }
    
    //bug: 忘记删除前置0了, 例如C是300, 意味着是003, 但是答案应该是3
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}
int main(){
    string a;
    int b;
    cin >> a >> b;
    
    vector<int> A;
    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0'); //bug, 忘记- 0
    
    vector<int> C = mul(A,b);
    
    for(int i = C.size()-1; i >= 0 ; i--) cout<<C[i];
    
    cout<<endl;
    return 0;
}
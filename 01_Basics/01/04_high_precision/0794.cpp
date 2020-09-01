#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> div(vector<int> &A, int b, int &r){
    vector<int> C;
    
    r = 0;
    for(int i = A.size()-1; i >= 0; i--){ //是从最高位开始除 //bug! 这里不能用unsigned, 否则i是一直>=0
        r = r * 10 + A[i]; //首先看上一轮遗留下来的余数, *10, 然后加上这意味的
        C.push_back(r / b); //除以b,这里可能得到的是0.
        r %= b; //剩下的余数,给下一轮. 
    }
    
    reverse(C.begin(), C.end());//假设C是0013,其实代表是数字31,所以先翻转,变成3100,最后去掉末尾的0
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    
    return C;
}




int main(){
    string a;
    int b;
    
    cin >> a >> b;
    
    vector<int> A;
    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0'); //其实可以从i = 0推入,因为出发是从最高位开始.但是+-*都是从数字最低位开始
    
    int r; //余数
    vector<int> C = div(A,b,r); //用的是别名,也可以修改值
    
    for(int i = C.size()-1; i >= 0; i--) cout<<C[i]; //bug! unsigned int i不能用i--的情况
    cout<<endl<<r;
    
    return 0;

}

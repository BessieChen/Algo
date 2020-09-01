#include <iostream>
#include <vector>
using namespace std;

//if A >= B
bool cmp(vector<int> &A, vector<int> &B){
    if(A.size() != B.size()) return A.size() > B.size();
    
    //比较数字高位,也就是vector的index的高位
    for(int i = A.size()-1; i >= 0; i--){
        if(A[i] != B[i])
            return A[i] > B[i]; //小心:不要写成 >=
    }
    
    return true;
}

vector<int> sub(vector<int> &A, vector<int> &B){
    vector<int> C;
    
    int t = 0;//进位
    
    //先减数字低位,也就是index==0. 结果数字的低位,保存在了C 的index == 0
    for(int i = 0; i <= A.size()-1; i++){
        int temp = A[i] - t;//A首先看是否之前被借了1
        if(i <= B.size()-1) temp -= B[i]; //如果B还有第i位
        C.push_back( (temp + 10) % 10); //如果temp = -2, 那么就是8. 如果temp = 2, 那么就是2
        if(temp >= 0) t = 0; 
        else t = 1; //注意:一定要严格temp < 0才表明借了
    }
    
    //删除数字高位的0, 也就是C index末尾, 也就是C.back
    while(C.size() > 1 && C.back() == 0) C.pop_back(); //语意: while里面是要pop掉的条件, 所以允许0,但是不允许003

    return C;
}
int main(){
    string a, b;
    cin >> a >> b;
    vector<int> A;
    vector<int> B;
    
    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0'); //bug, 记得 - '0'
    for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');
    
    vector<int> C;
    
    if(cmp(A,B)){ //A>=B
        C = sub(A,B);
        for(int i = C.size()-1; i >= 0; i--) cout<<C[i];
    }
    else
    {
        C = sub(B,A);
        cout<<"-";
        for(int i = C.size()-1; i >= 0; i--) cout<<C[i];
    }
    cout<<endl;
    return 0;
}


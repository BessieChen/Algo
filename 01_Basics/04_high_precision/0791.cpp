#include <iostream>
#include <vector> //因为vector里面存有size的信息.不需要用额外空间获取
using namespace std;

vector<int> add2(vector<int> &A, vector<int> &B) //这里是传入地址.所以就不需要复制
{
    if(A.size() < B.size()) return add2(B,A);
    
    int t = 0; //进位
    vector<int> C;
    for(unsigned int i = 0; i < A.size(); i++) //需要选择最长的那个
    {
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10); //C的index==0位置是数字的最低位
        t /= 10;
    }
    if(t) C.push_back(t);
    return C;
}

vector<int> add(vector<int> &A, vector<int> &B) //这里是传入地址.所以就不需要复制
{
    int t = 0; //进位
    vector<int> C;
    for(unsigned int i = 0; i < A.size() || i < B.size(); i++) //需要选择最长的那个 //注意不能用 int i, 编译出错
    {
        if(i < A.size()) t += A[i];
        if(i < B.size()) t += B[i];
        C.push_back(t % 10); //C的index==0位置是数字的最低位
        t /= 10;
    }
    if(t) C.push_back(t);
    return C;
}

int main()
{
    string a,b;//传入的大数字
    vector<int> A, B; //存到数组
    
    cin >> a >> b;
    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
    for(int i = b.size()-1; i >= 0; i --) B.push_back(b[i] - '0'); //注意这里是char '0'
    
    auto C = add2(A, B); //相当于vector<int> C = add(A,B);
    for(int i = C.size()-1 ; i >= 0; i--) printf("%d",C[i]);
    cout << endl;
    return 0;
}
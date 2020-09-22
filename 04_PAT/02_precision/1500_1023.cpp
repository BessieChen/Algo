#include <iostream>
#include <cstring>
#include <vector> //数组存大input
#include <algorithm>

using namespace std;

int main(){
    string input;
    cin >> input;
    
    //从后往前push
    vector<int> num;
    for(int i = input.size()-1 ; i >= 0; i--) num.push_back(input[i] - '0'); //记得减去偏移
    
    //计算结果
    vector<int> res;
    int t = 0; //进位
    for(int i = 0; i < num.size(); i++){
        int temp = num[i] + num[i] + t;
        res.push_back(temp % 10);
        t = temp / 10;
    }
    if(t) res.push_back(t); //还剩余就继续插入
    
    //老师比较两个数字是不是具有相同的数字,是通过排序+比较
    vector<int> copy = res;
    sort(copy.begin(), copy.end());
    sort(num.begin(), num.end());
    
    if(copy == num) puts("Yes");
    else puts("No");
    
    for(int i = res.size()-1; i >= 0; i--) cout << res[i];
    
    return 0;
}
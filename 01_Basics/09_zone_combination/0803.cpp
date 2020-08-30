#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

int main(){
    int n;
    scanf("%d",&n);
    
    vector<PII> vec;
    for(int i = 0; i < n; i ++){
        int l, r;
        cin >> l >> r;
        vec.push_back({l,r});
    }
    
    sort(vec.begin(), vec.end()); //sort()默认是按照item的第一个元素来排序.所以是按照左侧端点l排序
    
    int s = -2e9; //只要< -1e9就可以
    int e = -2e9;
    
    int res = 0;
    for(auto item : vec){
        if(item.first <= e) { //说明上一个[s,e]的end可以被延长
            e = max(e, item.second); //小心,是item.second不是item.first
        }
        else //说明遇到一个新的[s,e]. 所以之前找到的[s,e]可以被加入答案数组中
        {
            if(s != -2e9) res ++; //之前找到的[s,e]可以被加入答案数组中. 但是主要要刨除s,t是初始值的情况
            s = item.first;
            e = item.second;
        }
    }
    
    //将最后一组[r,l]加入答案. 不过要判断s,t是不是初始值
    if(s != -2e9) res ++;
    cout<<res<<endl;
    
    return 0;
}
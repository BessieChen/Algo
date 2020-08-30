//因为可能需要输入n次样本, 测试m个区间(左右2个)
#include <iostream>
#include <vector>
#include <algorithm> //sort()
using namespace std;

typedef pair<int,int> PII;

const int N = 3 * 100000 + 10;
int a[N]; //相当于pdf
int S[N]; //相当于cdf

//因为find()会用到all当做全局变量
vector<int> all; //包括了从add和query的所有索引

int find(int x){
    int l = 0, r = all.size()-1;
    
    
    while(l < r){
        int mid = (r-l)/2 + l;
        if(all[mid] >= x) r = mid;
        else l = mid + 1;
    }
    
    return l + 1;//因为前缀和一般都是1开始处理
}


vector<int>::iterator unique(vector<int> &a)
{
    int j = 0;//指向非重数组的下一位
    for(int i = 0; i < (int)a.size();) 
    {
        if(i == 0) a[j++] = a[i]; //数组的第一位一定是满足条件的
        while(j <= i && a[j-1] != a[i]) a[j++] = a[i++];  //因为是递增的,所以一旦不等于,就说明不是重复
    }
    return a.begin() + j;
}

vector<int>::iterator unique_from_yxc(vector<int> &a)
{
    int j = 0;
    for (int i = 0; i < a.size(); i ++ )
        if (!i || a[i] != a[i - 1])
            a[j ++ ] = a[i];
    // a[0] ~ a[j - 1] 所有a中不重复的数

    return a.begin() + j;
}

int main(){
    int n, m;
    cin >> n >> m;
    
    vector<PII> add;
    vector<PII> query;

    
    for(int i = 0; i < n; i ++) 
    {
        int ind, v;
        cin >> ind >> v;
        
        all.push_back(ind);
        add.push_back({ind, v});
    }
    
    for(int i = 0; i < m; i++){
        int l, r;
        cin >> l >> r;
    
        all.push_back(l);
        all.push_back(r);
        query.push_back({l,r});
    }
    
    //将所有的索引,去重
    sort(all.begin(), all.end()); //unique()需要一个递增的数组
    all.erase(unique(all.begin(), all.end()), all.end());
    //all.erase(unique(all), all.end()); //unique()返回的是没有重复元素的数组的下一个元素的位置. 从这个位置开始,到末尾,都是重复元素被放置的地方. 这部分给erase()删除
    
    //为所有要实现加法运算的索引,找到压缩后的索引,并加入a数组中
    for(auto item : add){
        int cind = find(item.first); //cind是从1开始的
        a[cind] += item.second;
    }

    //将a数组累加
    for(int i = 1; i <= all.size(); i++) S[i] = S[i-1] + a[i]; //bug, 注意是 <= all.size(), 而不是 <= n, 因为是求出全部的cdf,cdf的有的地方是一条水平直线
    
    //为所有要找的l,r找到压缩后的index,并求出要找的区间和
    for(auto item : query){
        int cl = find(item.first), cr = find(item.second);
        cout << S[cr] - S[cl - 1] << endl;
    }
    
    return 0;
}

/*补充:
1. 为什么要把query的index都加入all?
    假设(ind, x)表示在ind加入元素x
    (1,x),(4,y),(6,z)
    假设没有将query加入all
        经过压缩之后:
            会变成(1,x),(2,y),(3,z)
        经过前缀和处理之后
            得到(1,x),(2,x+y),(3,x+y+z)
            这种表示,可以让我们求出:(x+y)-(x+y)=0, (x+y)-x=y
            但是我们不能求出x-x=0
        假设我们要[2,3](这个index是未经压缩的),无论将2,3如何映射.都不能求出正确答案0
2. 为什么要在all里面去重
    不去重也可以
        不去重的话,all也是递增序列,我们的find()因为返回的是第一个>=x的位置,所以没有影响
    去重的话
        会只有唯一的x
        所以find()返回第一个>=x的数,也就一定是x本身而不是>x的数
*/
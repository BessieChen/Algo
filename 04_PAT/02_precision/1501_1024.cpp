#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

bool is_p(vector<int>& num){
    for(int i = 0, j = num.size()-1 ; i < j; i ++ , j --) { //所以当i == j的时候,就只是最后一个中间元素, 或者 i == j+1, 就是两者相较
        if(num[i] != num[j]) return false;
    }
    return true;
}

vector<int> add(vector<int>& a, vector<int>& b){
    vector<int> res;
    int t = 0;
    for(int i = 0; i < a.size() || i < b.size(); i++) //只要有一个数组还剩,就继续加
    {
        int temp = 0;
        if(i < a.size()) temp += a[i];
        if(i < b.size()) temp += b[i];
        temp += t;

        res.push_back(temp % 10);
        t = temp / 10;
    }

    if(t) res.push_back(t);
    return res;
}
int main(){
    string input;
    int k;
    cin >> input >> k;

    //放入vector
    vector<int> num;
    for(int i = input.size()- 1; i >= 0; i--) num.push_back(input[i] - '0'); //bug,小心偏移

    //判断是否回文,不是就继续处理
    int cnt = 0; //处理次数
    if(!is_p(num)){
        while(cnt <= k-1){
            //复制一份颠倒的num
            vector<int> copy(num.rbegin(), num.rend()); //用了reverse
            num = add(copy, num); //是赋值给num,因为还有下一轮要继续用num
            cnt ++;
            if(is_p(num)) break;
        }
    }

    for(int i = num.size()-1; i >= 0 ;i --) cout << num[i];
    cout << endl << cnt << endl;

    return 0;
}
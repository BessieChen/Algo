#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;

const int N = 10010;//顾客个数
//构造和顾客相关的信息
struct Person{
    int arrive_time;
    int service_time;

    //需要用到sort给顾客排序
    bool operator< (const Person& t) const{ //一般都是重载 < 符号
        return arrive_time < t.arrive_time;
    }
}persons[N]; //这是一个数组

int main(){
    
    int n, k;
    cin >> n >> k;
    
    //读取每个客户的信息
    int hour, minutes, second, service_time; //需要计算,所以用int
    for(int i = 0; i < n ; i ++) {
        scanf("%d:%d:%d %d", &hour, &minutes, &second, &service_time);
        //为了方便比较,我们将口径统一转化成秒,服务时间是秒,到来时间是相对于凌晨的秒
        //不过注意,服务时间不能超过60min,所以取min
        service_time = min(service_time, 60);
        persons[i] = {hour * 3600 + minutes*60 + second, service_time * 60}; //注意语法是{},然后记得都是秒
    }
    
    //制作窗口,我们只需要记录每个窗口的起始空闲时间,然后存入小跟堆,因为我们需要的最早空闲的窗口
    priority_queue<int, vector<int>, greater<int>> windows; //注意小跟对的定义    
    
    //初始化堆,因为都是8点上班, 共有k个窗口
    for(int i = 0; i < k; i++) windows.push(8 * 3600);
    
    //开始服务:
    sort(persons, persons + n);

    int wait_sum = 0; //总共的等待时间
    int cnt = 0; //不一定是所有人都服务了,所以要记录服务了多少人
    for(int i = 0; i < n; i++){ //bug!!!用for(auto p : persons)即便里面有break也break不了!!!
        auto p = persons[i];
        //如果来晚了,不用再看后面的了
        if(p.arrive_time > 17 * 3600) break;
        
        //取出最早空闲的窗口
        int w = windows.top(); //w是int,是最早的空闲秒数
        windows.pop();//记得pop
        
        int start_service_time = max(p.arrive_time, w);

        //更新窗口的时间
        int end_time = start_service_time + p.service_time;
        windows.push(end_time);
        
        //更新累计等待时间
        wait_sum += start_service_time - p.arrive_time;
        cnt ++;
    }
    
    printf("%.1lf\n", (double)wait_sum/cnt/60);
    return 0;
    
}



#include <cstdio> //printf()
#include <cstring>
#include <iostream>
#include <algorithm> //sort()
#include <map>
#include <vector>

using namespace std;

const int N = 1010; //用户数量
const int M = 31*1440+10; //相对于每月初的分钟数. 也就是我们统一了口径


int cost[24]; //24h每小时的每分钟话费
double sum[M]; //某分钟的累计话费数, 如果以后求某一段的话费,就直接sum[j] - sum[i]
    
struct Record{
   int relative_minutes; //相对于月初的分钟数
   string state; //用于on-line, off-line
   string formated_time; //用于打印
   
   //操作符重载
   bool operator< (const Record& t) const{ //首先是重载<, 然后我们不破坏传入的参数, 最后还有一个const, 不太清楚什么意思
       return relative_minutes < t.relative_minutes; 
   }
};
map<string, vector<Record>> persons;

int main(){
    for(int i = 0; i <24; i ++ ) cin >> cost[i];
    for(int i = 1; i < M ;i ++) sum[i] = sum[i-1] + cost[ ((i-1) % 1440) / 60] / 100.0; 
    //注释: i % 1440, 是将分钟换成某一天的, 然后 / 60说明这个分钟属于几点, 最后 / 100.0因为我们是从美分到美元
    
    char name[25], state[10]; //输入的名字, 状态. 我觉得之所以不用string, 可能是因为这些变量是通过scanf输入的
    int month, day, hour, minutes; 
    char formated_time[20]; //我们要填入的信息
    
    int n;
    cin >> n;
    
    for(int i = 0 ; i < n; i ++){
        //因为输入的格式奇奇怪该的,所以用scanf()
        scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minutes, state);
        
        //填入formated_time
        sprintf(formated_time, "%02d:%02d:%02d", day, hour, minutes); //这个的功能是, 有格式的传入
        
        //相对时间
        int relative_minutes = (day - 1) * 1440 + hour * 60 + minutes;
        
        persons[name].push_back( {relative_minutes, state, formated_time} ); //注意,这里是有{}的
    }
    
    //现在我们要遍历每个人了, 因为是map<>数据结构,所以遍历的时候天然是按照item.first(name)的字典序排序的
    for(auto &person: persons) //老师这里用了引用,说是会快一点
    {
        auto name = person.first;
        
        //一个人对应了一个vector<Record>, 也就是一大堆的传入数据,我们既然有相对分钟数,就先排个序
        auto record_vec = person.second;
        sort(record_vec.begin(), record_vec.end()); //这里使用了record结构体中的操作符重载, 也就是按照相对分钟数排序
        
        //排好序之后,我们就是看这个排好序的vector里面, 是不是合法的
        double total = 0; //最终还需要打印总花费
        for(auto i = 0; i + 1 < record_vec.size(); i++) //注意需要保留一个
        {
            auto a = record_vec[i];
            auto b = record_vec[i+1];
            
            //你会发现,我们不考虑on-on, off-off, off-on, 只考虑on-off
            if(a.state == "on-line" && b.state == "off-line"){
                //如果是第一次找到合法的,就打印名字,月份
                if(!total) printf("%s %02d\n", name.c_str(), month); //注意,因为name是char*, 所以不能直接用%s打印, 所以需要name.c_str(), month是02d格式
                
                //我们需要计算ab间隔多少分钟,然后话费是多少
                int interval = b.relative_minutes - a.relative_minutes;
                double fee = sum[b.relative_minutes] - sum[a.relative_minutes]; //主义是double, 如果写成int的话,后面就会输出不了,因为%.2lf似乎不支持int
                
                //不能这么写: printf("%s %s %d $%.2lf\n", a.formated_time, b.formated_time, interval, fee); 
                cout << a.formated_time << " " << b.formated_time << " ";
                printf("%d $%.2lf\n", interval, fee); 
                
                //%.2lf意识是保留两位小数
                //注意我们要补充空行, \n
                
                total += fee;
            }
        }
        if(total) printf("Total amount: $%.2lf\n", total);
    }
    
    return 0;
}
#include <iostream>
#include <string.h> //包括strlen()
using namespace std;

int two_pointer_example(){
    char str[1000];
    cin.getline(str, 100);
    
    int n = strlen(str);
    
    for(int i = 0; i < n; i++){
        
        int j = i; //i的语意是: 指向一个单词的第一个字母
        while( j < n && str[j] != ' ') j++;
        
        //到此时: j指向的是单词之间的空格
        for(int k = i; i < j; k++) cout<<str[k];
        cout<<endl;
        
        i = j; //注意,因为后面有i++, 所以这里直接i = j就好
    }
    
    return 0;
}

//https://www.acwing.com/video/245/ 39:29

const int N = 100010;
int a[N];
int b[N];

int main(){
    
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n ;i ++) scanf("%d", &a[i]);
    
    int res = 0;
    for(int i = 0, j = 0; i < n; i ++){
        b[a[i]]++; //b[]的含义: 在[j,i]闭区间里面,元素xx的个数
        
        while( j < i && b[a[i]] >= 2) b[a[j++]]--; //可以去掉 j < i, 因为j == i的时候, b[a[i]] == 1, 当满足b[a[i]] >= 2的时候,一定存在j < i. 后面b[a[j++]--的语意: 将j指向的元素移除出去,然后j++
        
        res = max(res, i - j + 1);
    }
    
    cout<<res<<endl;
    return 0;
}
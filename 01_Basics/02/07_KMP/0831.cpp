#include <iostream>
using namespace std;

const int N = 100010;
const int M = 1000010;

int n, m;
char p[N];
char s[M];
int ne[N]; //注意不要用next,可能会重名


int main(){
    cin >> n >> (p + 1) >> m >> (s + 1); //意思是:abc存入p的index=1,2,3的位置, 记得加上括号
    
    for(int i = 2, j = 0; i <= n ; i++){ //p的第二个字符和p的第一个字符比较
        while(j && p[i] != p[j+1]) j = ne[j]; //不满足, 跳回到之前模式一样的地方
        if(p[i] == p[j+1]) j++; //满足,继续
        ne[i] = j;
    }
    
    for(int i = 1, j = 0; i <= m; i++){ //是s的第一个字符和p的第一个字符比较
        while(j && s[i] != p[j+1]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if( j == n){
            cout<< i - n + 1 - 1 <<" "; //注意是 i - n + 1 - 1. 因为index = i-n+1, 但是是从index==1开始的所以要-1
            j = ne[j]; //跳回到之前模式一样的地方
        }
    }
    
    return 0;
    
}
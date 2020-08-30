#include <iostream>
using namespace std;

const int N = 100010;
int a[N];
int b[N];

int main(){
    int n,m,v;
    scanf("%d%d%d", &n, &m, &v);
    
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < m; i++) scanf("%d", &b[i]);
    
    for(int i = 0, j = m-1; i < n; i++){ //作用: 初始化i,j. 并且是指导i向右走
        while(j >= 0 && a[i] + b[j] > v) j--; //指导j向左走
        //此时一定有a[i] + b[j] <= v;
        
        if(a[i] + b[j] == v) {  //题目保证: 有唯一解
            printf("%d %d\n", i, j );
            break;
        }
    }
    
    return 0;
}
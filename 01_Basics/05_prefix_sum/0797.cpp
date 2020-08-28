#include <iostream>

using namespace std;

const int N = 100010;
int a[N];
int b[N];

void insert(int l, int r, int v){
    b[l] += v;
    b[r+1] -= v;
    return;
}
int main(){
    int n,m;
    cin >> n >> m;
    
    for(int i = 1; i <= n ; i ++) scanf("%d",&a[i]); //填充a
    
    for(int i = 1; i <= n; i ++) insert(i, i, a[i]); //构建b
    
    while(m --){
        int l, r, v;
        scanf("%d%d%d", &l, &r, &v);
        
        insert(l, r, v);
    }
    
    for(int i = 1; i <= n; i++) a[i] = a[i-1] + b[i]; //将b累加,变成新的a
    for(int i = 1; i <= n ;i++) printf("%d ", a[i]);
    return 0;
}
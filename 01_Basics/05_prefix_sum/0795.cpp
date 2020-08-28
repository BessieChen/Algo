#include <iostream>
using namespace std;

const int N = 100010; //这样可以统一管理a[N], S[N]的长度

int a[N];
int S[N];

int main(){
    int n, m;
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]); //注意,这里特意从i = 1开始,因为我们要保证a[0] = 0;
    for(int i = 1; i <= n; i++) S[i] = S[i-1] + a[i]; //注意,这里同样是S[0] = 0
    
    while(m--){
        int l, r;
        cin >> l >> r;
        printf("%d\n", S[r] - S[l-1]);
    }
    return 0;
}
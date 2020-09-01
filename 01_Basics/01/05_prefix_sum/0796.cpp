#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N];
int S[N][N];

int main(){
    int n, m, p;
    scanf("%d%d%d", &n, &m, &p);
    
    for(int i = 1; i <= n; i++){ //bug, 注意是 i <= n
        for(int j = 1; j <= m; j++) //bug, 注意是 j <= m
        {
            scanf("%d", &a[i][j]); //method 1;
            //scanf("%d", &S[i][j]); //method 2;
        }
    }
    
    for(int i = 1; i <= n; i++){ //bug, 注意是 i <= n
        for(int j = 1; j <= m; j++) //bug, 注意是 j <= m
        {
           S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + a[i][j]; //method 1;
           //S[i][j] += S[i-1][j] + S[i][j-1] - S[i-1][j-1]; //method 2;
        }
    }
    
    while(p--){
        int x1,x2,y1,y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        
        int res = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
        printf("%d\n",res);
    }
    return 0;
}
#include <iostream>
using namespace std;

const int N = 1010;
int a[N][N];
int b[N][N];

void insert(int x1, int y1, int x2, int y2, int v){
    b[x1][y1] += v;
    b[x2+1][y1] -= v;
    b[x1][y2+1] -= v;
    b[x2+1][y2+1] += v;
    return;
}
int main(){
    int n, m, p;
    
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &a[i][j]);
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m ; j++){
            insert(i,j,i,j,a[i][j]); //生成b矩阵
        }
    }
    
    while(p --){
        int x1, y1, x2, y2, v;
        cin >> x1 >> y1 >> x2 >> y2 >> v;
        
        insert(x1,y1,x2,y2,v);//更新b矩阵
    }
    
    for(int i = 1; i <= n; i++){ //一定是从左往右,从上往下加总
        for(int j = 1; j <= m; j++)
            //更新a矩阵, 联系之前的二维前缀和, 这里的a相当于之前的S, 这里的b相当于之前的a
            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + b[i][j]; //注意,bug: 最后应该是+ b[i][j] 而不是 + a[i][j]
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)
            printf("%d ", a[i][j]);
        cout<<endl;
    }
    
    return 0;
}
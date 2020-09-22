#include <iostream>

using namespace std;

const int N = 1010;
double a[N];
double b[N];
double c[2*N]; //需要扩大

int k;

void input(double a[]){
    
    cin >> k;
    
    while(k --){
        int n;
        double v;
        cin >> n >> v;
        a[n] = v;
    }
}

int main(){

    input(a);
    input(b);
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N ; j++)
            {
                c[i+j] += a[j] * b[i] ;// 注意,是b的第0位分别和a的从0到最大的位乘积
                //不能是a[i] * b[j]!!
                //注意是 +=, 不是=
            }
    }
    //统计数组中有多少个非零
    int res = 0;
    for(int i = 0; i < 2*N; i++) 
        if(c[i]) res ++;
        
    //最后打印,从最高位开始
    cout << res;
    for(int i = 2 * N -1; i >= 0; i--){
        if(c[i])
            printf(" %d %.1lf", i, c[i]);
    }
    
    return 0;
}
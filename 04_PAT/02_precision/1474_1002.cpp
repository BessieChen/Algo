#include <iostream>

using namespace std;

const int N = 1010;
double a[N]; 
double b[N];
double c[N];

int k;//输入的系数个数

void input(double a[])
{
    while(k--)
    {
        int n;
        double v;
        cin >> n >> v;
        a[n] = v;
    }
}

int main(){
    
    cin >> k;
    input(a);
    
    cin >> k;
    input(b);
    
    for(int i = 0; i < N; i++) c[i] = a[i] + b[i];
    
    int res = 0;
    for(int i = 0; i < N; i++) if(c[i]) res++;
    
    cout << res; //因为严格控制空格, 所以下一句中, 在前面输入空格
    for(int i = N - 1; i >= 0; i--) 
        if(c[i])
            printf(" %d %.1lf", i, c[i]); //因为保留一位小数, 所以用printf()
    
    return 0;
}
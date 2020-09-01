#include <iostream>
using namespace std;

//打印补码
void test(){
    int x = 10;
    unsigned int a = -x;
    
    for(int i = 31; i >= 0; i--) cout << (a >> i & 1);
    
    return;
}

//例如: x = 101000 的 lowbit(x) = 1000
int lowbit(int x)
{
    return x & (-x);
}

int main(){
    //test();
    
    int n;
    scanf("%d", &n);
    
    while(n --){
        int x;
        scanf("%d", &x);
        
        int res = 0;
        while(x){
            x -= lowbit(x); //去到末尾的1
            res ++;
        }
        cout<<res<<" ";
    }
}
#include <iostream>
using namespace std;

const int N = 100010; //bug!!, 我写10010报错了
int q[N];

int n;
int m;

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
    
    while(m --){
        int x;
        scanf("%d", &x);
        
        int l = 0, r = n-1;
        while(l < r){
            int mid =  (r-l)/2 + l;
            if(q[mid] >= x) r = mid;
            else l = mid+1;
        }
       
        if(q[l] != x) cout<<"-1 -1"<<endl;
        else{
            cout << l << ' ';
            
            int l = 0, r = n-1;
            while(l < r){
                int mid = (r - l + 1)/2 + l;
                if(q[mid] <= x) l = mid;
                else r = mid - 1;
            }
            cout << l <<endl;
        }
    }
    
    return 0;
}
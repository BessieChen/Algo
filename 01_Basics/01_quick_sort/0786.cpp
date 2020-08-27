#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int n;
int k;
int q[N];

int quick_select(int q[], int l, int r, int k){
    if(l >= r) return q[l];
    
    int i = l - 1, j = r + 1;
    swap(q[l], q[rand() % (r-l+1) + l]);
    int x = q[l];
    
    while(i < j){
        while(q[++ i] < x);
        while(q[-- j] > x);
        if(i < j) swap(q[i], q[j]);
    }
    
    int sl = j-l+1;
    if(k <= sl) return quick_select(q, l, j, k);
    
    return quick_select(q, j+1, r, k - sl); //err_prone: k - sl
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    
    cout << quick_select(q, 0, n-1, k) << endl;
    return 0;
}
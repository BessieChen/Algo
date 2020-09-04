#include <iostream>
using namespace std;

typedef long long LL; //因为逆序对的数字可能会达到5*10^9; 因为(n*n-1)/2, n = 10^5
const int N = 1e5+10;
int q[N];
int temp[N];

int n;

LL merge_sort(int l, int r){ //易错!, 返回值不是int, 是LL!!, 否则返回值溢出,成了负数
    if(l >= r) return 0;
    
    int mid = (r-l)/2 + l; 
    LL res = merge_sort(l, mid) + merge_sort(mid+1, r);
    
    int k = 0;
    int i = l, j = mid+1;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) //注意,两个相等的数字不是逆序对
            temp[k++] = q[i++];
        else
        {
            temp[k++] = q[j++];
            res += (mid - i + 1); //逆序对
        }
    }
    
    while(i <= mid){
         temp[k++] = q[i++];
         //res += (mid - i + 1); //易错, 这里不应该有这一句,因为上面的代码res += (mid - i + 1)已经包含了从i到mid
    }
    while(j <= r) temp[k++] = q[j++];
    
    for(int i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];
    
    return res;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
    
    cout<<merge_sort(0, n-1)<<endl;
    return 0;
}
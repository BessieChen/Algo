#include <iostream>

using namespace std;

const int N = 110;

int a[N];
int b[N];

void siftdown(int pos, int size){
    int t = pos;
    if(2*pos+1 < size && b[t] < b[2*pos+1]) t = 2*pos+1; //bug,主义是t = 2*pos+1, 而不是pos = 2*pos+1 //这句话:如果存在做儿子 && left儿子比自己大
    if(2*pos+2 < size && b[t] < b[2*pos+2]) t = 2*pos+2; //bug, 这里是b[t] < b[2*pos+1]而不是b[pos] < b[2*pos+1], 因为这里一共有两个if,所以上面的t = 2*pos+1 可以影响我们这个t, 所以假设上一句 left比自己大, 但是现在发现right 比 left大, 那么我们就要把父亲和right交换.
    if(t != pos ){//是否被修改过
        swap(b[t], b[pos]); //交换
        siftdown(t, size); //注意这里是size,因为堆的大小没变
    }
}
int main(){
    int n;
    cin >> n;
    

    
    for(int i = 0 ; i < n ; i ++) cin >> a[i];
    for(int i = 0 ; i < n ; i ++) cin >> b[i];
    
    //插入排序比较容易检查,所以检查插入
    int p = 1; 
    while(p < n && b[p-1] <= b[p]) p++; //bug, 注意是 b[p-1] <= b[p], 也就是可以相等或者单调递增
    
    //此时的p是指向右侧的第一个元素
    int k = p;
    while(p < n && a[p] == b[p]) p++;
    
    if(p == n){ //说明是插入排序, bug, 容易错, p如果指向数组的最后一个ind,应该是n-1, 所以n-1+1 = n, 而不是if(p == n+1)
        puts("Insertion Sort");
    
        //进行插入排序之后的事情,从k开始向左打雷
        while( k >= 1 && b[k-1] > b[k]) { //只有k左边有人才能打,所以k至少是ind == 1
            swap(b[k-1], b[k]);
            k--;
        }
        
    }
    else{ //因为一定有解,所以是堆排序
        //接下来确定右侧在哪里
        int top = b[0];
        int p = n-1;
        while(p >= 1 && b[p] >= top) p--;
        
        //此时p是左侧堆的最末尾的节点
        swap(b[0],b[p]); //bug! 注意是先将堆顶给移到后面,然后我们在对前面0到q-1索引的元素排序
        siftdown(0, p); //因为是0到p-1,所以size == p
        puts("Heap Sort");
    }
    
    cout << b[0];
    for(int i = 1; i < n; i ++) cout << " " << b[i];
    cout << endl;
    
    return 0;
}
1. before 5.13
	1. AcWing 785. 快速排序
		1. bug
			#include <iostream>

			using namespace std;

			const int N = 100010; 

			int q[N];

			void quick_sort(int q[], int l, int r){
				if(l >= r) return;
				swap(q[l], q[l + rand() % (r - l + 1)]);
				int i = l - 1, j = r + 1, tar = q[l + (r - l >> 1)]; bug: 如果是用 rand(), 就不能选中间的

				while(i < j){
					do i++; while(q[i] < tar);
					do j--; while(tar < q[j]);
					if(i != j ) swap(q[i], q[j]); bug: 不是 != 
				}

				quick_sort(q, l, j);
				quick_sort(q, j + 1, r);
			}

			int main(){
				int n;
				scanf("%d", &n);

				for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
				quick_sort(q, 0, n-1);
				for(int i = 0; i < n; i++) printf("%d", q[i]);

				return 0;
			}
		2. recite
			1.
				#include <iostream>
				using namespace std;

				const int N = 100010;
				int q[N];
				int n;

				void quick_sort(int q[], int l, int r){
				    if(l >= r) return;
				    int ind = l + (rand() % (r - l + 1));
				    int x = q[ind]; -> 随机选一个x, 防止x是数组里面的min或者max;
				   	swap(q[l], q[ind]);	这样子, 我们就让x在最左边了, 因为分的结果也需要x在最左边
				    int i = l - 1, j = r + 1;
				    while(i < j){
				        do i++; while(q[i] < x);
				        do j--; while(x < q[j]);
				        if(i < j) swap(q[i], q[j]);
				    }
				    quick_sort(q, l, j);
				    quick_sort(q, j + 1, r);
				}

				int main(){
				    scanf("%d", &n);
				    for(int i = 0; i < n; i++)
				        scanf("%d", &q[i]);
				        
				    quick_sort(q, 0, n - 1);
				    for(int i = 0; i < n; i++)
				        printf("%d ", q[i]);
				    return 0;
				}

				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 100010;
				int q[N];
				int n;

				void quick_sort(int q[], int l, int r){
				    if(l >= r) return;
				    int ind = rand() % (r - l + 1) + l;
				    int x = q[ind];
				    swap(q[l], q[ind]);
				    
				    int i = l - 1, j = r + 1;
				    
				    while(i < j){
				        do i++; while(q[i] < x);
				        do j--; while(q[j] > x);
				        if(i < j) swap(q[i], q[j]);
				    }
				    
				    quick_sort(q, l, j);
				    quick_sort(q, j + 1, r);
				}

				int main(){
				    scanf("%d", &n);
				    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
				    quick_sort(q, 0, n - 1);
				    for(int i = 0; i < n; i++) printf("%d ", q[i]);
				}

				#include <iostream>
				using namespace std;

				const int N = 100010;
				int q[N];
				int n;

				void quick_sort(int q[], int l, int r){
				    if(l >= r) return;
				    int ind = rand() % (r - l + 1) + l;
				    int x = q[ind];
				    swap(q[l], q[ind]);
				    
				    int i = l - 1, j = r + 1;
				    while(i < j){
				        do i++; while(q[i] < x);
				        do j--; while(q[j] > x);
				        if(i < j) swap(q[i], q[j]);
				    }
				    
				    quick_sort(q, l, j);
				    quick_sort(q, j + 1, r);
				}

				int main(){
				    scanf("%d", &n);
				    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
				    quick_sort(q, 0, n - 1);
				    for(int i = 0; i < n; i++) printf("%d ", q[i]);
				    return 0;
				}
			2. 三路快排
				#include <iostream>
				using namespace std;
				const int N = 100010;
				int q[N];
				int n;

				void quick_sort(int q[], int l, int r){
				    if(l >= r) return;
				    int ind = l + rand() % (r - l + 1);
				    int x = q[ind];
				    swap(q[l], q[ind]);
				    
				    int test = l + 1, i = (l + 1) - 1, j = r + 1; 这里的i,j是[]闭区间, 闭区间的初始化是: [0,-1]这种逻辑的初始化
				    while(test < j){
				    	if(q[test] == x){
				            test++;
				        }else if(q[test] < x){
				        							执行i++前, q[i]指的是<v的最后一个元素
				            i++;					执行完i++后, q[i]指的是==v的第一个元素
				            swap(q[i], q[test]);
				            test++;		
				        }else{
				            j--;					执行完j--后, q[j]指的是一个不知道是什么的元素
				            swap(q[j], q[test]);	当执行完q[j]后, q[j]是>x的元素, 但是q[test]是一个不知道是什么的元素
				        }
				        //等于v部分：
		    				// arr[i+1,...test-1] == v, 所以test是最后==v的右端点
					    //小于v部分：
					    	// arr[l+1,...,i] < v, 所以i是最后<v的右端点
					    //大于v部分：
					    	// arr[j,...,r] > v
				    }


				    swap(q[l], q[i]);	//执行这一句之前, q[l]是==v的那个孤单的元素, q[i]是<v的最后一个元素

				    执行到这里:
				    	//等于v部分：
		    				// arr[i,...j-1] == v, 所以test是最后==v的右端点
					    //小于v部分：
					    	// arr[l,...,i-1] < v, 所以i是最后<v的右端点
					    //大于v部分：
					    	// arr[j,...,r] > v
				    quick_sort(q, l, i - 1);
				    quick_sort(q, j, r);	小心错误, 并不是 (q, j + 1, r)
				}
				int main(){
				    scanf("%d", &n);
				    for(int i = 0; i < n; i++)
				        scanf("%d", &q[i]);
				        
				    quick_sort(q, 0, n - 1);
				    for(int i = 0; i < n; i++)
				        printf("%d ", q[i]);
				    return 0;
				}

				---
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 100010;
				int q[N];
				int n;

				void quick_sort(int q[], int l, int r){
				    if(l >= r) return;
				    int ind = rand() % ( r - l + 1) + l;
				    int x = q[ind];
				    swap(q[l], q[ind]);
				    
				    int test = l + 1, i = l, j = r + 1;
				    while(test < j){
				        if(q[test] == x){
				            test++;
				        }else if(q[test] < x){
				            i++;
				            swap(q[test], q[i]);
				            test++;
				        }else{
				            j--;
				            swap(q[test], q[j]);
				        }
				    }
				    swap(q[i], q[l]);
				    quick_sort(q, l, i - 1);
				    quick_sort(q, j, r);
				}

				int main(){
				    scanf("%d", &n);
				    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
				    quick_sort(q, 0, n - 1);
				    for(int i = 0; i < n; i ++) printf("%d ", q[i]);
				}
				--
				#include <iostream>

				using namespace std;

				const int N = 100010;
				int q[N];
				int n;

				void quick_sort(int q[], int l, int r){
				    if(l >= r) return;
				    int ind = rand() % (r - l + 1) + l;
				    int x = q[ind];
				    swap(q[l], q[ind]);
				    
				    int test = l + 1, i = l, j = r + 1;
				    while(test < j){
				        if(q[test] == x){
				            test++;
				        }else if(q[test] < x){
				            i++;
				            swap(q[i], q[test]);
				            test++;
				        }else{
				            j--;
				            swap(q[j], q[test]);
				        }
				    }
				    swap(q[i], q[l]);
				    quick_sort(q, l, i - 1);
				    quick_sort(q, j, r);
				}
				int main(){
				    scanf("%d", &n);
				    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
				    quick_sort(q, 0, n - 1);
				    for(int i = 0; i < n ; i ++) printf("%d ", q[i]);
				    return 0;
				}
				--
				#include <iostream>
				using namespace std;

				const int N = 100010;
				int q[N];
				int n;

				void quick_sort(int q[], int l, int r){
				    if(l >= r) return;
				    int ind = rand() % (r - l + 1) + l;
				    int x = q[ind];
				    swap(q[l], q[ind]);
				    
				    int test = l + 1, i = l, j = r + 1;
				    while(test < j){
				        if(q[test] == x) test++;
				        else if(q[test] < x){
				            i++;
				            swap(q[test], q[i]);
				            test++;
				        }else{
				            j--;
				            swap(q[test], q[j]);
				        }
				    }
				    swap(q[l], q[i]);
				    quick_sort(q, l, i - 1);
				    quick_sort(q, j, r);
				}

				int main(){
				    scanf("%d", &n);
				    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
				    quick_sort(q, 0, n - 1);
				    for(int i = 0; i < n; i++) printf("%d ", q[i]);
				    return 0;
				}
	2. AcWing 786. 第k个数
		1. bug 
			#include <iostream>
			#include <algorithm>

			using namespace std;

			const int N = 100010;
			int q[N];
			int n, k;

			int quick_sort(int q[], int l , int r, int k){
			    if(l >= r) return q[l];					不是 l <= r, 也并不是 return 0;
			    int x = q[rand() % (r - l + 1) + l];	是%
			    int i = l - 1, j = r + 1;
			    while(i < j){
			        do i++; while(q[i] < x);
			        do j--; while(q[j] > x);
			        if(i < j) swap(q[i], q[j]);
			    }
			    if(j - l + 1 >= k) return quick_sort(q, l, j, k);
			    else return quick_sort(q, j + 1, r, k - (j - l + 1));
			}

			int main(){
			    scanf("%d%d", &n, &k);	不是一个%d
			    for(int i = 0; i < n; i++){
			        scanf("%d", &q[i]);
			    }
			    printf("%d", quick_sort(q, 0, n - 1, k));
			}
		2. ok
			#include <iostream>
			#include <algorithm>

			using namespace std;

			const int N = 100010;
			int q[N];
			int n, k;

			int quick_sort(int q[], int l, int r, int k){
			    if(l >= r) return q[l];
			    int x = q[rand() % (r - l + 1) + l];
			    int i = l - 1, j = r + 1;
			    while(i < j){
			        do i++; while(q[i] < x);
			        do j--; while(q[j] > x);
			        if(i < j) swap(q[i], q[j]);
			    }
			    if(k <= j - l + 1) return quick_sort(q, l, j, k);
			    else return quick_sort(q, j + 1, r, k - (j - l + 1));
			}

			int main(){
			    scanf("%d%d", &n, &k);
			    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
			    printf("%d", quick_sort(q, 0, n - 1, k));
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int q[N];
			int n, k;

			int qs(int q[], int l, int r, int k){
			    if(l >= r) return q[l];
			    int ind = rand() % (r - l + 1) + l;
			    int x = q[ind];
			    swap(q[l], q[ind]);
			    
			    int i = l - 1, j = r + 1;
			    while(i < j){
			        do i++; while(q[i] < x);
			        do j--; while(q[j] > x);
			        if(i < j) swap(q[i], q[j]);
			    }
			    if(k <= j - l + 1) return qs(q, l, j, k);
			    else return qs(q, j + 1, r, k - (j - l + 1));
			}

			int main(){
			    scanf("%d%d", &n, &k);
			    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
			    printf("%d", qs(q, 0, n - 1, k));
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int q[N];
			int n, k;

			int qs(int q[], int l, int r, int k){
			    if(l >= r) return q[l];
			    int ind = rand() % (r - l + 1) + l;
			    int x = q[ind];
			    swap(q[l], q[ind]);
			    
			    int i = l - 1, j = r + 1;
			    while(i < j){
			        do i++; while(q[i] < x);
			        do j--; while(q[j] > x);
			        if(i < j) swap(q[i], q[j]);
			    }
			    
			    if(k <= j - l + 1) return qs(q, l, j, k);
			    else return qs(q, j + 1, r, k - (j - l + 1));
			}
			int main(){
			    scanf("%d%d", &n, &k);
			    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
			    printf("%d", qs(q, 0, n - 1, k));
			    return 0;
			}
	3. AcWing 787. 归并排序
		1. bug
		2. ok 
			#include <iostream>
			#include <algorithm>

			using namespace std;

			const int N = 100010;
			int q[N];
			int n;
			int tmp[N];

			void merge_sort(int q[], int l, int r){
			    if(l >= r) return;
			    int mid = l + (r - l >> 1);
			    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
			    
			    int k = 0, i = l, j = mid + 1;
			    while(i <= mid && j <= r){
			        if(q[i] <= q[j]) tmp[k++] = q[i++];
			        else tmp[k++] = q[j++];
			    }
			    while(i <= mid) tmp[k++] = q[i++];
			    while(j <= r) tmp[k++] = q[j++];
			    
			    for(int i = l, j = 0; i <= r; i++, j++) q[i] = tmp[j];
			}

			int main(){
			    scanf("%d", &n);
			    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
			    merge_sort(q, 0, n - 1);
			    for(int i = 0; i < n; i++) printf("%d ", q[i]);
			}
			--
			#include <iostream>
			#include <algorithm>

			using namespace std;

			const int N = 100010;
			int q[N];
			int n;
			int temp[N];

			void merge_sort(int q[], int l, int r){
			    if(l >= r) return;
			    int mid = (r - l >> 1) + l;
			    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
			    
			    int k = 0, i = l, j = mid + 1;
			    while(i <= mid && j <= r){
			        if(q[i] <= q[j]) temp[k++] = q[i++];
			        else temp[k++] = q[j++];
			    }
			    while(i <= mid) temp[k++] = q[i++];
			    while(j <= r) temp[k++] = q[j++];
			    
			    for(int i = l, j = 0; i <= r; i ++ , j++) q[i] = temp[j];
			}

			int main(){
			    scanf("%d", &n);
			    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
			    merge_sort(q, 0, n - 1);
			    for(int i = 0; i < n; i++) printf("%d ", q[i]);
			} 
			--
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int q[N];
			int n;
			int temp[N];

			void ms(int q[], int l, int r){
			    if(l >= r) return;
			    int mid = (r - l) / 2 + l;
			    ms(q, l, mid), ms(q, mid + 1, r);
			    
			    int k = 0, i = l, j = mid + 1;
			    while(i <= mid && j <= r){
			        if(q[i] <= q[j]) temp[k++] = q[i++];
			        else temp[k++] = q[j++];
			    }
			    while(i <= mid) temp[k++] = q[i++];
			    while(j <= r) temp[k++] = q[j++];
			    
			    for(int i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];
			}
			int main(){
			    scanf("%d", &n);
			    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
			    ms(q, 0, n - 1);
			    for(int i = 0; i < n; i++) printf("%d ", q[i]);   
			}
	4. AcWing 788. 逆序对的数量
		1. bug
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 100010;
			int q[N];
			int temp[N];
			int n;

			typedef long long LL;

			LL ms(int q[], int l, int r){
			    if(l >= r) return 0;
			    int mid = l + r >> 1; -不能是 r - l >> 1 + l, 一定要加很多括号 ((r - l) >> 1) + l. 我还是用/2吧, 也就是 (r - l) / 2 + l;
			    LL res = ms(q, l, mid) + ms(q, mid + 1, r);
			    
			    int k = 0, i = l, j = mid + 1;
			    while(i <= mid && j <= r){
			        if(q[i] <= q[j]) temp[k++] = q[i++];
			        else{
			            temp[k++] = q[j++];
			            res += mid - i + 1;
			        }
			    }
			    while(i <= mid) temp[k++] = q[i++];
			    while(j <= r) temp[k++] = q[j++];
			    for(int i = l, j = 0; i <= r; i++, j ++) q[i] = temp[j];
			    return res;
			}

			int main(){
			    scanf("%d", &n);
			    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
			    // printf("%l", ms(q, 0, n - 1));  这里错了, 我发现longlong不能用printf. 应该是 %ld用于long类型，%lld用于long long类型。
			    cout << ms(q, 0, n - 1) << endl;	或者直接cout
			    return 0;
			}
		2.
			#include <iostream>
			#include <algorithm>

			using namespace std;
			typedef long long LL;
			const int N = 100010;
			int q[N];
			int n;
			int temp[N];

			LL ms(int q[], int l, int r){
			    if(l >= r) return 0;
			    int mid = (r - l) / 2 + l;	就老老实实/2吧
			    LL res = ms(q, l, mid) + ms(q, mid + 1, r);
			    int k = 0, i = l, j = mid + 1;
			    while(i <= mid && j <= r){
			        if(q[i] <= q[j]) temp[k++] = q[i++];	注意是 <=, 不是 <
			        else{
			            temp[k++] = q[j++];
			            res += mid - i + 1;
			        }
			    }
			    while(i <= mid) temp[k++] = q[i++];
			    while(j <= r) temp[k++] = q[j++];
			    
			    for(int i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];
			    return res;
			}
			int main(){
			    scanf("%d", &n);
			    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
			    printf("%lld", ms(q, 0, n - 1));
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int q[N];
			int n;
			int temp[N];

			typedef long long LL;

			LL ms(int q[], int l, int r){
			    if(l >= r) return 0;
			    int mid = (r - l) / 2 + l;
			    
			    LL res = ms(q, l, mid) + ms(q, mid + 1, r);
			    
			    int k = 0, i = l, j = mid + 1;
			    while(i <= mid && j <= r){
			        if(q[i] <= q[j]) temp[k++] = q[i++];
			        else{
			            temp[k++] = q[j++];
			            res += mid - i + 1;
			        }
			    }
			    while(i <= mid) temp[k++] = q[i++];
			    while(j <= r) temp[k++] = q[j++];
			    
			    for(int i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];
			    return res;
			}

			int main(){
			    scanf("%d", &n);
			    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
			    printf("%lld", ms(q, 0, n - 1));
			}
	5. AcWing 789. 数的范围 
		1. bug 
		2. ok 
			#include <iostream>
			#include <algorithm>

			using namespace std;

			const int N = 100010;
			int q[N];
			int n, m, k;

			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
			    while(m--){
			        scanf("%d", &k);
			        int l = 0, r = n - 1;
			        while(l < r){
			            int mid = (r - l) / 2 + l;
			            if(k <= q[mid]) r = mid;
			            else l = mid + 1;
			        }
			        if(q[l] != k) printf("-1 -1\n");
			        else{
			            printf("%d ", l);
			            l = 0, r = n - 1;
			            while(l < r){
			                int mid = (r - l) / 2 + l + 1;
			                if(q[mid] <= k) l = mid;
			                else r = mid - 1;
			            }
			            printf("%d\n", l);
			        }
			    }
			    return 0;
			}

			#include <iostream>
			#include <algorithm>

			using namespace std;
			const int N = 100010;
			int q[N];
			int n, m, x;

			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 0 ; i < n; i++) scanf("%d", &q[i]);
			    while(m--){
			        scanf("%d", &x);
			        int l = 0, r = n - 1;
			        while(l < r){
			            int mid = (r - l) / 2 + l;
			            if(x <= q[mid]) r = mid;
			            else l = mid + 1;
			        }
			        if(q[l] != x) printf("-1 -1\n");
			        else{
			            printf("%d ", l);
			            l = 0, r = n - 1;
			            while(l < r){
			                int mid = (r - l)/ 2 + l + 1;
			                if(q[mid] <= x) l = mid;
			                else r = mid - 1;
			            }
			            printf("%d\n", l);
			        }
			    }
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int n, m, k;
			int q[N];



			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
			    while(m -- ){
			        scanf("%d", &k);
			        
			        int l = 0, r = n - 1;
			        while(l < r){
			            int mid = (r - l) / 2 + l;
			            if(k <= q[mid]) r = mid;
			            else l = mid + 1;
			        }
			        
			        if(q[l] != k) printf("-1 -1\n");
			        else{
			            printf("%d ", l);
			            int l = 0, r = n - 1;
			            while(l < r){
			                int mid = (r - l) / 2 + l + 1;
			                if(q[mid] <= k) l = mid;
			                else r = mid - 1;
			            }
			            printf("%d\n", l);
			        }
			    }
			    return 0;
			}
	6. AcWing 790. 数的三次方根
		1. bug
			#include <iostream>
			using namespace std;

			double x;

			int main(){
			    scanf("%lf", &x);
			    double l = -100.0, r = 100.0;
			    错误: while(l - r < 1e-8){ 	正确: while(r - l > 1e-8){ while(合法)
			        double mid = (r - l) / 2 + l;
			        if(x <= mid * mid * mid) r = mid;
			        else l = mid;
			    }
			   	错误: printf("%lf", l);	 正确: printf("%.6lf", l);	
			    return 0;
			}
		2. ok
			#include <iostream>
			using namespace std;

			double x;

			int main(){
			    scanf("%lf", &x);
			    double l = -100.0, r = 100.0;
			    while(r - l > 1e-8){
			        double mid = (r - l) / 2 + l;
			        if(x <= mid * mid * mid) r = mid;
			        else l = mid;
			    }
			    printf("%.6lf", l);
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;

			int main(){
			    double x;
			    scanf("%lf", &x);
			    double l = -100.0, r = 100.0;
			    while(r - l > 1e-8){
			        double mid = (r - l) / 2 + l;
			        if(mid * mid * mid <= x) l = mid;
			        else r = mid;
			    }
			    printf("%.6lf", l);
			    return 0;
			}
	7. AcWing 791. 高精度加法
		1. bug
			#include <iostream>
			#include <vector>

			using namespace std;

			vector<int> add(const vector<int> &A, const vector<int> &B){
			    vector<int> res;
			    int t = 0;
			    for(int i = 0; i < (int)A.size() || i < (int)B.size(); i++){
			        if(i < (int)A.size()) t += A[i];
			        if(i < (int)B.size()) t += B[i];
			        res.push_back(t % 10);
			        t /= 10;
			    }
			    if(t) res.push_back(t);
			    return res;
			}

			int main(){
			    string a, b;
			    cin >> a >> b;
			    	错误: 我也不知道为何, 一直出错, 所以string还是用cin来读吧
			    		scanf("%s", &a[0]);
	    				scanf("%s", &b[0]);
			    vector<int> A, B;
			    for(int i = (int)a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
			    for(int i = (int)b.size() - 1; ~i; i--) B.push_back(b[i] - '0');
			    vector<int> C = add(A, B);
			    for(int i = (int)C.size() - 1; ~i; i--) printf("%d", C[i]);
			    return 0;
			    
			}
		2. ok
			#include <iostream>
			#include <vector>

			using namespace std;

			string a, b;

			vector<int> add(const vector<int> &A, const vector<int> &B){
			    int t = 0;
			    vector<int> res;
			    for(int i = 0; i < (int)A.size() || i < (int)B.size() || t; i++){
			        if(i < (int)A.size()) t += A[i];
			        if(i < (int)B.size()) t += B[i];
			        res.push_back(t % 10);
			        t /= 10;
			    }
			    return res;
			}
			int main(){
			    cin >> a >> b;
			    vector<int> A, B;
			    for(int i = (int)a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
			    for(int i = (int)b.size() - 1; ~i; i--) B.push_back(b[i] - '0');
			    vector<int> C = add(A, B);
			    for(int i = (int)C.size() - 1; ~i; i--) printf("%d", C[i]);
			    return 0;
			}
			--
			#include <iostream>
			#include <vector>

			using namespace std;
			string a, b;

			vector<int> add(const vector<int> &A, const vector<int> &B){
			    int t = 0;
			    vector<int> res;
			    for(int i = 0; i < (int)A.size() || i < (int)B.size(); i++){
			        if(i < (int)A.size()) t += A[i];
			        if(i < (int)B.size()) t += B[i];
			        res.push_back(t % 10);
			        t /= 10;
			    }
			    if(t) res.push_back(t);
			    return res;
			}

			int main(){
			    cin >> a >> b;
			    vector<int> A, B;
			    for(int i = (int)a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
			    for(int i = (int)b.size() - 1; ~i; i--) B.push_back(b[i] - '0');
			    vector<int> C = add(A, B);
			    for(int i = (int)C.size() - 1; ~i; i--) printf("%d", C[i]);
			    return 0;
			}
			--
			#include <iostream>
			#include <vector>

			using namespace std;

			vector<int> add(const vector<int> &A, const vector<int> &B){
			    int t = 0;
			    vector<int> res;
			    for(int i = 0; i < A.size() || i < B.size() || t; i++){
			        if(i < A.size()) t += A[i];
			        if(i < B.size()) t += B[i];
			        res.push_back(t % 10);
			        t /= 10;
			    }
			    return res;
			}

			int main(){
			    string a, b;
			    cin >> a >> b;
			    vector<int> A, B;
			    for(int i = a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
			    for(int i = b.size() - 1; ~i; i--) B.push_back(b[i] - '0');
			    vector<int> C = add(A, B);
			    for(int i = C.size() - 1; ~i; i--) printf("%d", C[i]);
			    return 0;
			}
	8. AcWing 792. 高精度减法
		1. bug
			#include <iostream>
			#include <vector>

			using namespace std;

			string a, b;

			bool cmp(const vector<int> &A, const vector<int> &B){
			    错误: if(A.size() > B.size()) return true;
			    	之所以错误是:
			    		我们没有考虑到 A.size() < B.size() 的情况
			    		如果 A.size() < B.size(), 我们会继续往下走, 但是走到下面的时候, 其实要保证A.size() == B.size();
			    		例如 a是12, b是123
			    		A是21, B是321
			    		走for loop会一切都正确, 最后返回的是true, 但其实应该是false
			    正确: if(A.size() != B.size()) return A.size() > B.size();
			    for(int i = A.size() - 1; ~i; i--){
			        if(A[i] != B[i]) {
			            return A[i] > B[i];
			        }
			    }
			    return true;
			}

			vector<int> sub(const vector<int> &A, const vector<int> &B){
			    int t = 0;
			    vector<int> res;
			    for(int i = 0; i < (int)A.size(); i++){
			        int temp = A[i] - t;
			        if(i < (int)B.size()) temp -= B[i];
			        if(temp < 0) t = 1;
			        else t = 0;
			        res.push_back((temp + 10) % 10);
			    }
			    错误: 忘记pop掉真实数字中的前导0, 也就是pop掉res的末位的0
			    正确: while(res.size() > 1 && res.back() == 0) res.pop_back(); 
			    	注意, 不能写成 while("res.size()" && res.back() == 0) res.pop_back(); 
			    	如果答案就是0, 我们要保留一个0, 所以 res.size() >= 2
			    return res;
			}

			int main(){
			    cin >> a >> b;
			    vector<int> A, B;
			    for(int i = (int)a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
			    for(int i = (int)b.size() - 1; ~i; i--) B.push_back(b[i] - '0');
			    if(cmp(A, B)){
			        vector<int> C = sub(A, B);
			        for(int i = (int)C.size() - 1; ~i; i--) printf("%d", C[i]);
			    }else{
			        printf("-");
			        vector<int> C = sub(B, A);
			        for(int i = (int)C.size() - 1; ~i; i--) printf("%d", C[i]);
			    }
			}
		2. ok
			#include <iostream>
			#include <vector>

			using namespace std;
			string a, b;
			vector<int> A, B;

			bool cmp(const vector<int> &A, const vector<int> &B){
			    if(A.size() != B.size()) return A.size() > B.size();
			    for(int i = A.size() - 1; ~i; i--){
			        if(A[i] != B[i]) return A[i] > B[i];
			    }
			    return true;
			}

			vector<int> sub(const vector<int> &A, const vector<int> &B){
			    int t = 0;
			    vector<int> res;
			    for(int i = 0; i < A.size(); i++){
			        int temp = A[i] - t;
			        if(i < B.size()) temp -= B[i];
			        if(temp < 0) t = 1;
			        else t = 0;
			        res.push_back((temp + 10) % 10);
			    }
			    while(res.size() >= 2 && res.back() == 0) res.pop_back();
			    return res;
			}

			int main(){
			    cin >> a >> b;
			    for(int i = a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
			    for(int i = b.size() - 1; ~i; i--) B.push_back(b[i] - '0');
			    vector<int> C;
			    if(cmp(A, B)){
			        C = sub(A, B);
			    }else{
			        printf("-");
			        C = sub(B, A);
			    }
			    for(int i = C.size() - 1; ~i; i--) printf("%d", C[i]);
			    return 0;
			}
			--
			#include <iostream>
			#include <vector>

			using namespace std;

			bool cmp(const vector<int> &A, const vector<int> &B){
			    if(A.size() != B.size()) return A.size() > B.size();
			    for(int i = A.size() - 1; ~i; i--){
			        if(A[i] != B[i]) return A[i] > B[i];
			    }
			    return true;
			}

			vector<int> sub(const vector<int> &A, const vector<int> &B){
			    int t = 0;
			    vector<int> res;
			    for(int i = 0; i < A.size(); i++){
			        int temp = A[i] - t;
			        if(i < B.size()) temp -= B[i];
			        if(temp < 0) t = 1;
			        else t = 0;
			        res.push_back((temp + 10) % 10);
			    }
			    while(res.size() >= 2 && res.back() == 0) res.pop_back();
			    return res;
			}

			int main(){
			    string a, b;
			    cin >> a >> b;
			    vector<int> A, B;
			    for(int i = a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
			    for(int i = b.size() - 1; ~i; i--) B.push_back(b[i] - '0');
			    vector<int> C;
			    if(cmp(A, B)){
			        C = sub(A, B);
			    }else{
			        printf("-");
			        C = sub(B, A);
			    }
			    for(int i = C.size() - 1; ~i; i--) printf("%d", C[i]);
			    return 0;
			}
	9. AcWing 793. 高精度乘法
		1. bug
			#include <iostream>
			#include <vector>

			using namespace std;

			vector<int> mul(const vector<int> &A, int b){
			    int t = 0;
			    vector<int> res;
			    for(int i = 0; i < A.size() || t; i++){	错误: 忘记写 || t
			        if(i < A.size()) t = A[i] * b + t;
			        res.push_back(t % 10);
			        t /= 10;
			    }
			    错误: 忘记去除前导0
			    正确: 需要去除前导0: while(res.size() >= 2 && res.back() == 0) res.pop_back();
			    	为什么呢?
			    		因为不去除的话, 这个样例就fail:
			    			12345
			    			0
			    			正确答案是0, 但是我们会输出 00000
			    	总之需要去除前导0的:
			    		1. 减法: 12345 - 12345 = 00000
			    		2. 乘法: 12345 * 0 = 00000
			    return res;
			}

			int main(){
			    string a;
			    int b;
			    cin >> a >> b;
			    vector<int> A;
			    for(int i = a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
			    vector<int> C = mul(A, b);
			    for(int i = C.size() - 1; ~i; i--) printf("%d", C[i]);
			    return 0;
			}
		2. ok
			#include <iostream>
			#include <vector>

			using namespace std;

			vector<int> mul(const vector<int> &A, int b){
			    int t = 0;
			    vector<int> res;
			    for(int i = 0; i < A.size() || t ; i++){
			        if(i < A.size()) t = A[i] * b + t;
			        res.push_back(t % 10);
			        t /= 10;
			    }
			    while(res.size() >= 2 && res.back() == 0) res.pop_back();
			    return res;
			}

			int main(){
			    string a;
			    int b;
			    cin >> a >> b;
			    vector<int> A;
			    for(int i = a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
			    vector<int> C = mul(A, b);
			    for(int i = C.size() - 1; ~i; i--) printf("%d", C[i]);
			    return 0;
			}
			--
			#include <iostream>
			#include <vector>

			using namespace std;

			vector<int> mul(const vector<int> &A, int b){
			    int t = 0;
			    vector<int> res;
			    for(int i = 0; i < A.size() || t; i++){
			        t = A[i] * b + t;
			        res.push_back(t % 10);
			        t /= 10;
			    }
			    while(res.size() >= 2 && res.back() == 0) res.pop_back();
			    return res;
			}

			int main(){
			    string a;
			    int b;
			    cin >> a >> b;
			    vector<int> A;
			    for(int i = a.size() - 1; ~i; i--) A.push_back(a[i] - '0');
			    vector<int> C = mul(A, b);
			    for(int i = C.size() - 1; ~i; i--) printf("%d", C[i]);
			    return 0;
			}
	10. AcWing 794. 高精度除法
		1. bug
			#include <iostream>
			#include <vector>
			#include <algorithm>	别忘了加algorithm: 否则 reverse(res.begin(), res.end()); 会报错

			using namespace std;

			vector<int> div(const vector<int> &A, int b, int &r){
			    vector<int> res;
			    for(int i = 0; i < A.size(); i++){	除法从高位开始, 所以从0开始 
			        r = r * 10 + A[i];
			        res.push_back(r / b);
			        r %= b;
			    }
			    reverse(res.begin(), res.end());
			    错误: 忘记去除前导0
					样例:
						7319951122
						19
					忘记去除前导0的输出: 	
						0385260585
						7
					正确输出:
						385260585
						7
			    正确: while(res.size() >= 2 && res.back() == 0) res.pop_back(); 因为没有 pop_front(), 所以我们就干脆颠倒过来

			    return res;	因为颠倒了, 所以res的左侧是低位
			}

			int main(){
			    string a;
			    int b;
			    cin >> a >> b;
			    vector<int> A;
			    for(int i = 0; i < a.size(); i++) A.push_back(a[i] - '0');	这里的A的左侧是高位, 和a一样
			    int r = 0;
			    vector<int> C = div(A, b, r);
			    for(int i = C.size() - 1; ~i; i--) printf("%d", C[i]);
			    printf("\n%d", r);
			    return 0;
			}
		2. ok 
			#include <iostream>
			#include <vector>
			#include <algorithm>

			using namespace std;

			vector<int> div(const vector<int> &A, int b, int &r){
			    r = 0;
			    vector<int> res;
			    for(int i = 0; i < (int)A.size(); i++){
			        r = r * 10 + A[i];
			        res.push_back(r / b);
			        r %= b;
			    }
			    reverse(res.begin(), res.end());
			    while(res.size() >= 2 && res.back() == 0) res.pop_back();
			    return res;
			}

			int main(){
			    string a;
			    int b;
			    cin >> a >> b;
			    int r;
			    vector<int> A;
			    for(int i = 0; i < (int)a.size(); i++) A.push_back(a[i] - '0');
			    vector<int> C = div(A, b, r);
			    for(int i = (int)C.size() - 1; ~i ; i--) printf("%d", C[i]);
			    printf("\n%d", r);
			    return 0;
			}
			--
			#include <iostream>
			#include <vector>
			#include <algorithm>

			using namespace std;

			vector<int> div(const vector<int> &A, int b, int &r){
			    r = 0;
			    vector<int> res;
			    for(int i = 0; i < A.size(); i++){
			        r = r * 10 + A[i];
			        res.push_back(r / b);
			        r %= b;
			    }
			    reverse(res.begin(), res.end());
			    while(res.size() >= 2 && res.back() == 0) res.pop_back();
			    return res;
			}

			int main(){
			    string a;
			    int b;
			    int r;
			    cin >> a >> b;
			    vector<int> A;
			    for(int i = 0; i < a.size(); i++) A.push_back(a[i] - '0');
			    vector<int> C = div(A, b, r);
			    for(int i = C.size() - 1; ~i; i--) printf("%d", C[i]);
			    printf("\n%d", r);
			    return 0;
			    
			}
	11. AcWing 795. 前缀和
		1. bug
		2. ok
			#include <iostream>
			using namespace std;
			const int N = 100010;
			int a[N];
			int S[N];

			int main(){
			    int n, q, l, r;
			    scanf("%d%d", &n, &q);
			    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
			    for(int i = 1; i <= n; i++) S[i] = S[i-1] + a[i];
			    
			    while(q--){
			        scanf("%d%d", &l, &r);
			        printf("%d\n", S[r] - S[l-1]);
			    }
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int a[N], S[N];
			int n, m;

			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
			    for(int i = 1; i <= n; i++) S[i] = S[i-1] + a[i];
			    while(m --){
			        int l, r;
			        scanf("%d%d", &l, &r);
			        printf("%d\n", S[r] - S[l-1]);
			    }
			    return 0;
			}
	12. AcWing 796. 子矩阵的和
		1. bug
			#include <iostream>
			using namespace std;

			错误: const int N = 100010; -> 开的太大了, 输出奇怪的error
			正确: const int N = 1010;
			int a[N][N];
			int S[N][N];

			int main(){
			    int n, m, q;
			    scanf("%d%d%d", &n, &m, &q);
			    for(int i = 1; i <= n; i++){
			        for(int j = 1; j <= m; j++){
			            scanf("%d", &a[i][j]);
			        }
			    }
			    for(int i = 1; i <= n; i++){
			        for(int j = 1; j <= m; j++){
			            S[i][j] =  S[i-1][j] + S[i][j-1] + a[i][j] - S[i-1][j-1];
			        }
			    }
			    int x1, x2, y1, y2;
			    while(q--){
			        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			        int res = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
			        printf("%d\n", res);
			    }
			    return 0;
			}
		2. ok
			#include <iostream>
			using namespace std;

			const int N = 1010;
			int a[N][N];
			int S[N][N];

			int main(){
			    int n, m, q;
			    scanf("%d%d%d", &n, &m, &q);
			    for(int i = 1; i <= n; i++){
			        for(int j = 1; j <= m; j++){
			            scanf("%d", &a[i][j]);
			        }
			    }
			    for(int i = 1; i <= n; i++){
			        for(int j = 1; j <= m; j++){
			            S[i][j] =  S[i-1][j] + S[i][j-1] + a[i][j] - S[i-1][j-1];
			        }
			    }
			    int x1, x2, y1, y2;
			    while(q--){
			        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			        int res = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
			        printf("%d\n", res);
			    }
			    return 0;
			}
			==
			#include <iostream>
			using namespace std;

			const int N = 1010;
			int a[N][N], S[N][N];
			int n, m, q;

			int main(){
			    scanf("%d%d%d", &n, &m, &q);
			    for(int i = 1; i <= n; i++)
			        for(int j = 1; j <= m; j++) 
			            scanf("%d", &a[i][j]);
			    
			    for(int i = 1; i <= n; i++)
			        for(int j = 1; j <= m; j++)
			            S[i][j] = S[i-1][j] + S[i][j-1] + a[i][j] - S[i-1][j-1];
			            
			    while(q--){
			        int x1, y1, x2, y2;
			        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			        int res = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
			        printf("%d\n", res);
			    }
			    return 0;
			}
	13. AcWing 797. 差分
		1. bug
		2. 
			#include <iostream>

			using namespace std;

			const int N = 100010;
			int a[N], b[N];
			int n, m;

			void insert(int l, int r, int k){
			    b[l] += k;
			    b[r + 1] -= k;
			}

			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 1; i <= n; i++) {
			        scanf("%d", &a[i]);
			        insert(i, i, a[i]);
			    }
			    while(m--){
			        int l, r, k;
			        scanf("%d%d%d", &l, &r, &k);
			        insert(l, r, k);
			    }
			    for(int i = 1; i <= n; i++) a[i] = a[i-1] + b[i];
			    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
			    return 0;
			    
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int a[N], b[N];
			int n, m, l, r, k;

			void insert(int l, int r, int k){
			    b[l] += k;
			    b[r + 1] -= k;
			}

			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 1 ; i <= n ; i++) {
			        scanf("%d", &a[i]);
			        insert(i, i, a[i]);
			    }
			    while(m--){
			        scanf("%d%d%d", &l, &r, &k);
			        insert(l, r, k);
			    }
			    for(int i = 1; i <= n; i++) a[i] = a[i-1] + b[i];
			    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
			    return 0;
			    
			}
	14. AcWing 798. 差分矩阵
		0. 总结一下:
			前缀和:
				一维:
					原材料:
						for(int i = 1; i <= n; i++) 
							scanf("%d", &a[i]);
					构建:
						for(int i = 1; i <= n; i++) 
							S[i] = S[i-1] + a[i];
					求答案:
						int res = S[r] - S[l-1]
				二维:
					原材料:
						for(int i = 1; i <= n; i++)
					        for(int j = 1; j <= m; j++)
					            scanf("%d", &a[i][j]);
					构建:
						for(int i = 1; i <= n; i++)
					        for(int j = 1; j <= m; j++)
					            S[i][j] =  S[i-1][j] + S[i][j-1] + a[i][j] - S[i-1][j-1];
					求答案:
						int res = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
							前缀和的二维的求答案 和 差分的二维的构建非常像:
								b[x1][y1] += k;
							    b[x2+1][y1] -= k;
							    b[x1][y2+1] -= k;
							    b[x2+1][y2+1] += k;
			差分:
				一维:
					原材料:
						for(int i = 1; i <= n; i++)
					        scanf("%d", &a[i]);
					构建:
						0. insert()
							void insert(int l, int r, int k){
							    b[l] += k;
							    b[r + 1] -= k;
							}
						1. 构建初始的b: 
							for(int i = 1; i <= n; i++)
								insert(i, i, a[i]);
						2. 往[l, r]区间加上值k
							insert(l, r, k);
					求答案:
						for(int i = 1; i <= n; i++) a[i] = a[i-1] + b[i];
					    for(int i = 1; i <= n; i++) printf("%d ", a[i]);
				二维:
					原材料:
						for(int i = 1; i <= n; i++)
					        for(int j = 1; j <= m; j++)
					            scanf("%d", &a[i][j]);
					构建:
						0. insert()
							void insert(int l, int r, int k){
							    b[x1][y1] += k;
							    b[x2+1][y1] -= k;
							    b[x1][y2+1] -= k;
							    b[x2+1][y2+1] += k;
							}
						1. 构建初始的b: 
							for(int i = 1; i <= n; i++)
								for(int j = 1; j <= m; j++)
									insert(i, j, i, j, a[i][j]);
						2. 往[x1, y1], [x2, y2] 矩形中加上值k
							insert(x1, y1, x2, y2, k);
					求答案:
						 for(int i = 1; i <= n; i++)
					        for(int j = 1; j <= m; j++)
					            a[i][j] = a[i-1][j] + a[i][j-1] + b[i][j] - a[i-1][j-1];

					        	差分的二维的求答案 和 前缀和的二维的构建非常像:
					        		S[i][j] =  S[i-1][j] + S[i][j-1] + a[i][j] - S[i-1][j-1];

					    for(int i = 1; i <= n; i++)
					        for(int j = 1; j <= m ; j ++)
					            printf("%d ", a[i][j]);

		1. bug
			#include <iostream>
			using namespace std;

			const int N = 1010;
			int a[N][N], b[N][N];
			int n, m, q;

			void insert(int x1, int y1, int x2, int y2, int k){
			    b[x1][y1] += k;
			    错误: b[x2-1][y1] -= k; 正确: b[x2+1][y1] -= k;
			    错误: b[x1][y2-1] -= k; 正确: b[x1][y2+1] -= k;
			    b[x2+1][y2+1] += k;
			}

			int main(){
			    scanf("%d%d%d", &n, &m, &q);
			    for(int i = 1; i <= n; i++){
			        for(int j = 1; j <= m; j++){
			            scanf("%d", &a[i][j]);
			            insert(i, j, i, j, a[i][j]);
			        }
			    }
			    while(q--){
			        int x1, y1, x2, y2, k;
			        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
			        insert(x1, y1, x2, y2, k);
			    }
			    for(int i = 1; i <= n; i++){
			        for(int j = 1; j <= m; j++){
			            a[i][j] = a[i-1][j] + a[i][j-1] + b[i][j] - a[i-1][j-1];
			        }
			    }
			    for(int i = 1; i <= n; i++){
			        for(int j = 1; j <= m ; j ++){
			            printf("%d ", a[i][j]);
			        }
			        printf("\n");
			    }
			    return 0;
			}
		2.
			#include <iostream>
			using namespace std;

			const int N = 1010;
			int a[N][N], b[N][N];
			int n, m, q, x1, y1, x2, y2, k;

			void insert(int x1, int y1, int x2, int y2, int k){
			    b[x1][y1] += k;
			    b[x2+1][y1] -= k;
			    b[x1][y2+1] -= k;
			    b[x2+1][y2+1] += k;
			}
			int main(){
			    scanf("%d%d%d", &n, &m, &q);
			    for(int i = 1; i <= n; i++) {
			        for(int j = 1; j <= m; j++){
			            scanf("%d", &a[i][j]);
			            insert(i, j, i, j, a[i][j]);
			        }
			    }
			    while(q--){
			        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &k);
			        insert(x1, y1, x2, y2, k);
			    }
			    for(int i = 1; i <= n; i++){
			        for(int j = 1; j <= m; j++){
			            a[i][j] = a[i-1][j] + a[i][j-1] + b[i][j] - a[i-1][j-1];
			            printf("%d ", a[i][j]);
			        }
			        printf("\n");
			    } 
			    return 0;
			}
	15. AcWing 799. 最长连续不重复子序列 
		1. bug
		2. ok
			1.
				#include <iostream>
				using namespace std;

				const int N = 100010;
				int q[N], b[N];
				int n;

				int main(){
				    scanf("%d", &n);
				    for(int i = 0; i < n; i++) scanf("%d", &q[i]);
				    int res = 0;
				    for(int i = 0, j = 0; i < n; i++){
				        b[q[i]]++;
				        while(j < i && b[q[i]] >= 2){	如果新加入的a[i]是两个, 那我们的j就追赶i, 直到a[i]只剩一个
				        								你如果不相信, 你可以从头开始加元素.
				            b[q[j]]--;
				            j++;
				        }
				        res = max(res, i - j + 1);
				    }
				    cout << res << endl;
				    return 0;
				}
				--
				#include <iostream>
				using namespace std;

				const int N = 100010;
				int a[N], b[N];
				int n;

				int main(){
				    scanf("%d", &n);
				    int res = 0;
				    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
				    for(int i = 0, j = 0; i < n; i++){
				        b[a[i]]++;
				        while( j < i && b[a[i]] >= 2) b[a[j++]]--;
				        res = max(res, i - j + 1);
				    }
				    cout << res << endl;
				    return 0;
				}
			2. 截取空格分割的单词
				#include <iostream>
				#include <cstring>
				using namespace std;

				int main(){
				    char str[1000];
				    cin.getline(str, 100);
				    int n = strlen(str);
				    for(int i = 0; i < n; i++){
				        int j = i;	j指向单词的第一个字母
				        while(j < n && str[j] != ' ') j++;
				        	走出来后, j指向 ' '
				        for(int k = i; k < j; k++) cout << str[k];
				        cout << endl;
				        i = j;
				    }
				    return 0;
				}
				--
				#include <iostream>
				#include <cstring>

				using namespace std;

				int main(){
				    char str[1000];
				    cin.getline(str, 100);
				    int n = strlen(str);
				    for(int i = 0; i < n; i++){
				        int j = i;
				        while(j < n && str[j] != ' ') j++;
				        for(int k = i; k < j; k++) cout << str[k];
				        cout << endl;
				        i = j;
				    }
				    return 0;
				}
	16. AcWing 800. 数组元素的目标和
		1. bug
		2. ok
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int a[N], b[N];
			int n, m, v;

			int main(){
			    cin >> n >> m >> v;
			    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
			    for(int i = 0; i < m; i++) scanf("%d", &b[i]);
			    
			    for(int i = 0, j = m - 1; i < n; i++){			就是一个for + 一个while的双指针
			        while(j >= 0 && a[i] + b[j] > v) j--;
			        if(j >= 0 && a[i] + b[j] == v){
			            printf("%d %d", i, j);
			            break;
			        }
			    }
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int a[N], b[N];
			int n, m, k;

			int main(){
			    scanf("%d%d%d", &n, &m, &k);
			    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
			    for(int i = 0; i < m; i++) scanf("%d", &b[i]);
			    for(int i = 0, j = m - 1; i < n; i++){
			        while(j >= 0 && a[i] + b[j] > k) j--;
			        if(j >= 0 && a[i] + b[j] == k){
			            cout << i << " " << j << endl;
			            break;
			        }
			    }
			    return 0;
			}
	17. AcWing 2816. 判断子序列
		1. bug
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int a[N], b[N];
			int n, m;

			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
			    for(int i = 0; i < m; i++) scanf("%d", &b[i]);
			    int i = 0, j = 0;	byb, 这里还是很好想的, 就是两个指针
			    while(i < n && j < m){	指针要合法
			        if(a[i] == b[j]) i++;
			        错误: else j++; 正确: j++;

			        我的理解:
			        	j就像是衣服, i就是一个人
			        	不过i喜不喜欢第j个衣服, 我们每次都要把第j个衣服换掉
			        	如果i喜欢第j个衣服, 那就看下一个人i+1
			        	如果i不喜欢第j个衣服, 就给i看下一件衣服j+1
			        	总之 j是无条件++
			    }
			    if(i == n) puts("Yes");
			    else puts("No");
			    return 0;
			}
		2. ok
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int a[N], b[N];
			int n, m;

			int main(){
			    cin >> n >> m;
			    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
			    for(int i = 0; i < m; i++) scanf("%d", &b[i]);
			    int i = 0, j = 0;		
			    while(i < n && j < m){
			        if(a[i] == b[j]) i++;
			        j++;
			    }
			    if(i == n) puts("Yes");
			    else puts("No");
			    return 0;
			}
	18. AcWing 801. 二进制中1的个数
		1. bug
		2. ok
			#include <iostream>
			using namespace std;

			int n;

			int lowbit(int x){
			    return x & -x;	渔夫, 与负
			    	负数 == 补码 == 反码 + 1
			    	异或: 同0异1, 不进位加法, 我们口语中的或就是异或
			}

			int main(){
			    cin >> n;
			    while(n--){
			        int x;
			        cin >> x;
			        int res = 0;
			        while(x){
			            x -= lowbit(x);
			            res ++;
			        }
			        cout << res << " ";
			    }
			    cout << endl;
			}
			--
			#include <iostream>
			using namespace std;

			int n;

			int lowbit(int x){
			    return x & -x;
			}
			int main(){
			    cin >> n;
			    while(n --){
			        int x;
			        cin >> x;
			        int res = 0;
			        while(x){
			            x -= lowbit(x);
			            res ++;
			        }
			        cout << res << " ";
			    }
			    cout << endl;
			    return 0;
			}
	19. AcWing 802. 区间和
		1. bug
			#include <iostream>
			#include <algorithm>
			#include <vector>

			using namespace std;

			错误: const int N = 100010;	 正确: const int N = 3 * 100010;		因为add有1e5个index, query的l有1e5, r也有1e5, 所以一共是三倍. 否则segment fault
			typedef pair<int, int> PII;

			vector<int> index;
			vector<PII> add;
			vector<PII> query;

			int a[N], S[N];

			vector<int>::iterator uniq(vector<int> &A){		小心, 这里是传引用, 因为要修改A的值
			    int j = 0;
			    for(int i = 0; i < A.size(); i++){
			        if(!i || A[i] != A[i-1]) A[j++] = A[i];
			    }
			    return A.begin() + j;
			}

			int find(int v){
			    int l = 0, r = index.size() - 1;
			    while(l < r){
			    	写法1: 推荐
				        int mid = (r - l) / 2 + l;
				        if(v <= index[mid]) r = mid;
				        else l = mid + 1;

			        写法2:
			        	int mid = (r - l) / 2 + l + 1;
				        if(index[mid] <= v) l = mid;
				        else r = mid - 1;
			    }
			    return l + 1;			小心, 这里是+1, 因为前缀和一般从1开始
			}

			int main(){
			    int n, m;
			    scanf("%d%d", &n, &m);
			    while(n--){
			        int ind, v;
			        scanf("%d%d", &ind, &v);	我之前错写成了 %d, 应该是%d%d
			        index.push_back(ind);
			        add.push_back({ind, v});
			    }
			    while(m--){
			        int l, r;
			        scanf("%d%d", &l, &r);
			        index.push_back(l);
			        index.push_back(r);
			        query.push_back({l, r});
			    }
			    sort(index.begin(), index.end());
			    index.erase(uniq(index), index.end());
			    // index.erase(unique(index.begin(), index.end()), index.end());
			    
			    for(auto item : add){
			        int ind = find(item.first);
			        a[ind] += item.second;
			    }
			    
			    for(int i = 1; i <= index.size(); i++) S[i] = S[i-1] + a[i];
			    
			    for(auto item : query){
			        int l = find(item.first), r = find(item.second);
			        cout << S[r] - S[l-1] << endl;
			    }
			    return 0;
			}
		2. ok
			#include <iostream>
			#include <algorithm>
			#include <vector>

			using namespace std;

			const int N = 3 * 1e5 + 10;

			typedef pair<int, int> PII;
			vector<int> index;
			vector<PII> add;
			vector<PII> query;

			int a[N], S[N];

			vector<int>::iterator uniq(vector<int> &a){
			    int j = 0;
			    for(int i = 0 ; i < a.size(); i++){
			        if(!i || a[i] != a[i-1]) a[j++] = a[i];
			    }
			    return a.begin() + j;
			}

			int find(int v){
			    int l = 0, r = index.size() - 1;
			    while(l < r){
			        int mid = (r - l) / 2 + l;
			        if(v <= index[mid]) r = mid;
			        else l = mid + 1;
			    }
			    return l + 1;
			}

			int main(){
			    int n, m;
			    cin >> n >> m;
			    while(n --){
			        int ind, v;
			        scanf("%d%d", &ind, &v);
			        index.push_back(ind);
			        add.push_back({ind, v});
			    }
			    while(m --){
			        int l, r;
			        scanf("%d%d", &l, &r);
			        index.push_back(l);
			        index.push_back(r);
			        query.push_back({l, r});
			    }
			    sort(index.begin(), index.end());
			    index.erase(uniq(index), index.end());
			    
			    for(auto item : add){
			        int ind = find(item.first);
			        a[ind] += item.second;
			    }
			    
			    for(int i = 0; i <= index.size(); i++) S[i] = S[i-1] + a[i];
			    for(auto item : query){
			        int l = find(item.first), r = find(item.second);
			        cout << S[r] - S[l-1] << endl;
			    }
			    return 0;
			}
	20. AcWing 803. 区间合并
		1. bug
		2. ok
			1. 思路清楚版: 做这种题, 就是先默认我们已经在流程中间了, 也就是[begin, end]是上一个符合要求的区间, 然后判断 b <= end这样我们就可以延长当前区间
				#include <iostream>
				#include <vector>
				#include <algorithm>

				using namespace std;
				const int N = 100010;

				typedef pair<int, int> PII;

				vector<PII> q;

				int main(){
				    int n;
				    cin >> n;
				    while(n--){
				        int l, r;
				        scanf("%d%d", &l, &r);
				        q.push_back({l, r});
				    }
				    sort(q.begin(), q.end());
				    
				    int beg = -2 * 1e9;
				    int end = -2 * 1e9;	注意是-2*1e9, 其实只要小于 -1*1e9 就可以, 因为l的最小值就是 -1*1e9
				    
				    bool first = true;
				    int res = 0;
				    for(auto item : q){
				        int b = item.first;
				        int e = item.second;
				        if(first){	如果是第一次
				            beg = b;
				            end = e;
				            res ++;
				            first = false;
				        }else{
				            if(b <= end){
				                end = max(end, e);	可以延长之前的
				            }else{	遇到新区间
				                res++;
				                beg = b;
				                end = e;
				            }
				        }
				    }
				    cout << res << endl;
				    return 0;
				}
			2. 简略版
				#include <iostream>
				#include <vector>
				#include <algorithm>

				using namespace std;
				int n;
				vector<pair<int, int>> q;
				int main(){
				    cin >> n;
				    while(n--){
				       int l, r;
				       scanf("%d%d", &l, &r);
				       q.push_back({l, r});
				    }
				    
				    int begin = -2 * 1e9;
				    int end = -2 * 1e9;
				    
				    sort(q.begin(), q.end());
				    int res = 0;
				    for(auto item : q){
				        int b = item.first, e = item.second;
				        if(b <= end){		因为第一次绝对不可能进入这个if, 因为第一次, end == -2 * 1e9, b不可能小于他
				            end = max(e, end);
				        }else{		第一次 || 遇到新区间
				            begin = b;
				            end = e;
				            res ++;
				        }
				    }
				    cout << res << endl;
				    return 0;
				}
	21. AcWing 826. 单链表
		1. bug
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int head, e[N], ne[N], ind;

			void init(){
			    head = -1;
			    ind = 0;
			}

			void addh(int v){
			    e[ind] = v, ne[ind] = head, head = ind ++;
			}

			往第k个加入元素后面的加入元素v
			void insert(int k, int v){
			    e[ind] = v, ne[ind] = ne[k], ne[k] = ind++;
			}

			把第k个加入元素后面的元素去掉
			void remove(int k){
			    ne[k] = ne[ne[k]];
			}

			int main(){
			    int n;
			    cin >> n;
			    init();			忘记 init();
			    while(n--){
			        int k, v;
			        char op;
			        cin >> op;
			        if(op == 'H'){
			            cin >> v;
			            addh(v);
			        }else if(op == 'D'){
			            cin >> k;
			            if(!k) head = ne[head];		题目说了: k==0的时候, 取出头结点
			            else remove(k - 1);			题意: 去掉第k个元素 == 把第k-1个加入元素后面的元素去掉. 这里的第k个是从1开始, 第1个就是k==1. 其实我觉得这道题出的不好. 
			        }else{
			            cin >> k >> v;
			            insert(k - 1, v);			因为k是从1开始的, 第一个就是k==1, 但是我们实现是从0开始的, 所以 k - 1. 其实我觉得这道题出的不好. 
			        }
			    }
			    错误!!!!: for(int i = 0; i < ind; i++) cout << e[i] << " ";
			    正确: for(int i = head; ~i; i = ne[i]) cout << e[i] << " ";
			    cout << endl;
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;
			const int N = 100010;
			int head, e[N], ne[N], ind;

			void init(){
			    head = -1;
			    ind = 0;
			}

			void addh(int v){
			    e[ind] = v, ne[ind] = head, head = ind++;
			}

			void insert(int k, int v){
			    e[ind] = v, ne[ind] = ne[k], ne[k] = ind++;
			}

			void remove(int k){
			    ne[k] = ne[ne[k]];
			}

			int main(){
			    int n;
			    cin >> n;
			    init();
			    while(n--){
			        int k, v;
			        char op;
			        cin >> op;
			        if(op == 'H'){
			            cin >> v;
			            addh(v);
			        }else if(op == 'D'){
			            cin >> k;
			            if(!k) head = ne[head];
			            else remove(k - 1);
			        }else{
			            cin >> k >> v;
			            错误: insert(k, v);	
			            正确: insert(k - 1, v);	
			        }
			    }
			    for(int i = head; ~i; i = ne[i]) cout << e[i] << " ";
			    cout << endl;
			    return 0;
			}
		2. ok
			#include <iostream>

			using namespace std;

			const int N = 100010;
			int head, e[N], ne[N], ind;

			void init(){
			    head = -1;
			    ind = 0;
			}

			void addh(int v){
			    e[ind] = v, ne[ind] = head, head = ind ++;
			}

			void remove(int k){
			    ne[k] = ne[ne[k]];
			}

			void insert(int k, int v){
			    e[ind] = v, ne[ind] = ne[k], ne[k] = ind++;
			}

			int main(){
			    int n;
			    cin >> n;
			    
			    init();
			    while(n--){
			        int k, v;
			        char op;
			        cin >> op;
			        if(op == 'H'){
			            cin >> v;
			            addh(v);
			        }else if(op == 'D'){
			            cin >> k;
			            if(!k) head = ne[head];
			            else remove(k - 1);
			        }else{
			            cin >> k >> v;
			            insert(k - 1, v);
			        }
			    }
			    
			    for(int i = head; ~i; i = ne[i]) cout << e[i] << " ";
			    cout << endl;
			    return 0;
			}
	22. AcWing 827. 双链表
		1. bug
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int e[N], l[N], r[N], ind;

			void init(){
			    r[0] = 1, l[1] = 0;
			    ind = 2;
			}

			void insert(int k, int v){
			    e[ind] = v, l[ind] = k, r[ind] = r[k], l[r[k]] = ind, r[k] = ind;
			    ind ++;		忘记加 ind++; 
			}

			void remove(int k){
			    l[r[k]] = l[k];
			    r[l[k]] = r[k];
			}

			int main(){
			    init();
			    int n;
			    cin >> n;
			    while(n--){
			        int k, v;
			        string op;
			        cin >> op;
			        if(op == "L"){
			            cin >> v;
			            insert(0, v);
			        }else if(op == "R"){
			            cin >> v;
			            insert(l[1], v);
			        }else if(op == "D"){
			            cin >> k;
			            remove(k + 1);	我的理解: 假设k==1, 也就是将第1个插入的数字删除, 因为我们分配 idx是从2开始的, 所以 k+1
			        }else if(op == "IL"){
			            cin >> k >> v;
			            insert(l[k + 1], v);	这里是 k + 1. 首先, k+1上面解释过了{因为index从2开始}, 其次, 这里说第 k 个插入的数左侧插入, 但是我们的insert只能往右侧插入, 所以也就是从 第 k 个插入的数左侧{l[k+1]}的右侧插入
			        }else{
			            cin >> k >> v;
			            insert(k + 1, v);	这里是 k + 1. 
			        }
			    }
			    for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
			    cout << endl;
			    return 0;
			}
		2. ok
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int e[N], l[N], r[N], ind;

			void init(){
			    r[0] = 1, l[1] = 0;
			    ind = 2;
			}

			void insert(int t, int v){ //t == token
			    e[ind] = v, l[ind] = t, r[ind] = r[t], l[r[t]] = ind, r[t] = ind;
			    	思考流程:
			    		先是e
			    		然后想ind的左右是什么: l[ind] = t, r[ind] = r[t],
			    		然后再想t的右侧的左侧, t自己的右侧: l[r[t]] = ind, r[t] = ind;
			    ind ++;
			}

			void remove(int t){
			    l[r[t]] = l[t];
			    r[l[t]] = r[t];
			}

			int main(){
			    int n;
			    cin >> n;
			    init();
			    while(n--){
			        int k, v;
			        string op;
			        cin >> op;
			        if(op == "L"){
			            cin >> v;
			            insert(0, v);
			        }else if(op == "R"){
			            cin >> v;
			            insert(l[1], v);
			        }else if(op == "D"){
			            cin >> k;
			            remove(k + 1);
			        }else if(op == "IL"){
			            cin >> k >> v;
			            insert(l[k + 1], v);
			        }else{
			            cin >> k >> v;
			            insert(k + 1, v);
			        }
			    }
			    for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
			    cout << endl;
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int e[N], l[N], r[N], ind;

			void init(){
			    r[0] = 1, l[1] = 0;
			    ind = 2;
			}

			void insert(int t, int v){
			    e[ind] = v, l[ind] = t, r[ind] = r[t], l[r[t]] = ind, r[t] = ind;
			    ind ++;
			}

			void remove(int t){
			    l[r[t]] = l[t];
			    r[l[t]] = r[t];
			}

			int main(){
			    int n;
			    cin >> n;
			    init();
			    while(n--){
			        int k, v;
			        string op;
			        cin >> op;
			        if(op == "L"){
			            cin >> v;
			            insert(0, v);
			        }else if(op == "R"){
			            cin >> v;
			            insert(l[1], v);
			        }else if(op == "D"){
			            cin >> k;
			            remove(k + 1);
			        }else if(op == "IL"){
			            cin >> k >> v;
			            insert(l[k + 1], v);
			        }else{
			            cin >> k >> v;
			            insert(k + 1, v);
			        }
			    }
			    for(int i = r[0]; i != 1; i = r[i]) cout << e[i] << " ";
			    cout << endl;
			    return 0;
			}
	23. AcWing 828. 模拟栈
		1. bug
			[1, tt]区间是有元素的, 所以栈顶是 st[tt], 栈底是 st[1]
		2. ok
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int st[N], tt;

			int main(){
			    int n;
			    cin >> n;
			    while(n--){
			        string op;
			        int v;
			        cin >> op;
			        if(op == "push"){
			            cin >> v;
			            st[++ tt] = v;
			        }else if(op == "pop"){
			            tt--;
			        }else if(op == "empty"){
			            if(!tt) puts("YES");
			            else puts("NO");
			        }else{
			            cout << st[tt] << endl;
			        }
			    }
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int st[N], tt;

			int main(){
			    int n;
			    cin >> n;
			    while(n--){
			        string op;
			        int v;
			        cin >> op;
			        if(op == "push"){
			            cin >> v;
			            st[++ tt] = v;
			        }
			        else if(op == "pop"){
			            tt--;
			        }else if(op == "query"){
			            cout << st[tt] << endl;
			        }else{
			            if(!tt) puts("YES");
			            else puts("NO");
			        }
			    }
			    return 0;
			}
	todo s 24. AcWing 3302. 表达式求值
	25. AcWing 829. 模拟队列
		1. bug
			总结: 
				模拟栈/队列中的 tt起始是不同的. 
					栈: tt初始是0
						tt = 0, 没有元素
					队列: hh初始是0, tt初始是-1 {你看到tt初始为0的都是因为dijkstra初始就插入了队头}
						hh > tt, 没有元素
						while(hh <= tt): while(有元素), 元素是在[hh,tt]
				模拟栈/队列中, 插入元素都是 xx[++ tt] = yy
		2. ok
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int q[N], hh, tt = -1;

			int main(){
			    int n;
			    cin >> n;
			    while(n--){
			        string op;
			        int v;
			        cin >> op;
			        if(op == "push"){
			            cin >> v;
			            q[++tt] = v;
			        }else if(op == "pop"){
			            hh++;
			        }else if(op == "empty"){
			            if(hh > tt) puts("YES");
			            else puts("NO");
			        }else{
			            cout << q[hh] << endl; 
			        }
			    }
			    return 0;
			    
			}	
	26. AcWing 830. 单调栈
		1. bug
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int stack[N], tt;

			int main(){
			    int n, v;
			    cin >> n;
			    while(n--){
			        cin >> v;
			        while(tt && stack[tt] >= v) tt--;		如果左边的元素都大于等于v, 就把左侧的元素删掉. 注意是 >=, 不是 >, 我们要把所有stack中大于v的干掉. 所以就是: 当"有元素, 并且元素大于等于v"的就干掉
			        	走到这里的tt, 就是 tt == 0, 或者 stack[tt] 是小于v的
			        if(!tt) cout << "-1 ";
			        else cout << stack[tt] << " ";
			        stack[++ tt] = v;		这一句是写在 if else 的后面. 最后才是插入元素 
			        						注意是 stack[++ tt], 而不是 stack[tt ++]因为tt初始是0, 我们第一个元素是从tt==1的地方插入. 如果tt==0说明stack没有元素
			    							
			    							此时把x加入栈顶. 
					        					之后如果遇到一个比x小的数b, 我们还会把x给删除掉, 一直到找到一个合适的. 
					        					如果遇到的比x大的c, 我们输出的就是x. 因为这个x是离c最近的比c小的数
			    }
			    cout << endl;
			    return 0;
			}
		2. ok
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int stack[N], tt;

			int main(){
			    int n, v;
			    cin >> n;
			    while(n--){
			        cin >> v;
			        while(tt && stack[tt] >= v) tt--;
			        if(!tt) printf("-1 ");
			        else printf("%d ", stack[tt]);
			        stack[++tt] = v;
			    }
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int stack[N], n, tt, v;

			int main(){
			    cin >> n;
			    while(n--){
			        cin >> v;
			        while(tt && stack[tt] >= v) tt--;
			        if(!tt) cout << "-1 ";
			        else cout << stack[tt] << " ";
			        stack[++tt] = v;
			    }
			    return 0;
			}
	* 27. AcWing 154. 滑动窗口
		0. 小总结:
			单调栈: 
				左边第一个比它a[i]小的数
					stack是"单增"的
					stack顶部元素, 是不是有比当前a[i]更大的元素, 因为我们求得是比当前a[i]小的元素, "更大的没用", 删除
					stack的顶部元素就是 左边第一个比它a[i]小的数
			滑动窗口: 
				窗口min
					队列是"单增"的
					q的队尾是不是比当前a[i]更大的元素, 因为我们求得是min, "大的没用", 删除
					队首就是min
				求窗口max
					队列是"递减"的
					q的队尾是不是比当前a[i]更小的元素, 因为我们求得是max, "小的没用", 删除
					队首就是max
		1. bug
			#include <iostream>
			using namespace std;

			错误: const int N = 100010;
			正确: const int N = 1000010; 题目是1e6
			int a[N], q[N], n, k, hh, tt;

			int main(){
			    cin >> n >> k;
			    hh = 0, tt = -1;
			    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
			    for(int i = 0; i < n; i++){
			        if(hh <= tt && q[hh] < i - k + 1) hh++;		
			        while(hh <= tt && a[q[tt]] >= a[i]) tt--;	
			        "错误: q[++tt] = a[i]; 正确: q[++tt] = i;"
			        if(i >= k - 1) printf("%d ", a[q[hh]]);
			     }
			     puts("");
			     hh = 0, tt = -1;
			     for(int i = 0; i < n; i++){
			         if(hh <= tt && q[hh] < i - k + 1) hh++;
			         while(hh <= tt && a[q[tt]] <= a[i]) tt--;
			         错误: q[++tt] = a[i]; 正确: q[++tt] = i;
			         if(i >= k - 1)printf("%d ", a[q[hh]]);
			     }
			     return 0;
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 1000010;
			int a[N], q[N], n, k, hh, tt = -1;

			int main(){
			    cin >> n >> k;
			    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
			    for(int i = 0; i < n; i++){
			        if(hh <= tt && q[hh] < i - k + 1) hh++;
			        错误: while(hh <= tt && a[q["hh"]] >= a[i]) tt--; 正确: while(hh <= tt && a[q["tt"]] >= a[i]) tt--;
			        q[++tt] = i;
			        if(i >= k - 1) cout << a[q[hh]] << " ";
			    }
			    puts("");
			    hh = 0, tt = -1;
			    for(int i = 0; i < n; i++){
			        if(hh <= tt && q[hh] < i - k + 1) hh++;
			        错误: while(hh <= tt && a[q["hh"]] <= a[i]) tt--; 正确: while(hh <= tt && a[q["tt"]] <= a[i]) tt--;
			        q[++tt] = i;
			        if(i >= k - 1) cout << a[q[hh]] << " ";
			    }
			    cout << endl;
			    return 0;
			}
		2. ok 非常顺: 
			#include <iostream>
			using namespace std;

			const int N = 1000010;
			int a[N], n;
			int q[N], hh, tt = -1;
			int k;

			int main(){
			    cin >> n >> k;
			    for(int i = 0 ; i < n; i ++) scanf("%d", &a[i]);
			    for(int i = 0 ; i < n; i ++){					遍历窗口的终点i
			        if(hh <= tt && q[hh] < i - k + 1) hh++;		看q的队头是否在窗口内: 也就是是否 起点 <= 队头
			        while(hh <= tt && a[q[tt]] >= a[i]) tt--;	看q的队尾是否有更大的元素, 因为我们求得是min, 大的没用, 删除
			        q[++tt] = i;								先插入i, 因为打印的hh可能就是++tt
			        if(i >= k - 1) printf("%d ", a[q[hh]]);
			    }
			    puts("");
			    hh = 0, tt = -1;
			    for(int i = 0 ; i < n; i++){					遍历窗口的终点i
			        if(hh <= tt && q[hh] < i - k + 1) hh++;		看q的队头是否在窗口内: 也就是是否 起点 <= 队头
			        while(hh <= tt && a[q[tt]] <= a[i]) tt--;	看q的队尾是否有更小的元素, 因为我们求得是max, 小的没用, 删除
			        q[++tt] = i;								先插入i, 因为打印的hh可能就是++tt
			        if(i >= k - 1) printf("%d ", a[q[hh]]);
			    }
			    puts("");
			    return 0;
			}
	* 28. AcWing 831. KMP字符串
		0. 小总结:
			+1的
				知道[l, r], 求区间长度: r - l + 1
				知道终点r, 知道区间长度j, 求起点: r - j + 1
			-1的
				知道起点l, 知道区间长度j, 求终点: l + j - 1
			从一个东西变成另一个东西: 这里就不是什么区间长度了, 而是走的距离
				知道一个点是 l - 1, 想去另一个点 r, 应该怎么走: 也就是 l - 1 + ?? = r
					?? = r - (l - 1) == r - l + 1
					举例: 字符串哈希 h[r] - h[l - 1] * p[r - l + 1];
					这里如果是区间长度, [l-1, r]的区间长度是 r - (l - 1) + 1 == r - l. 
		1. bug
		2. ok
			1. 介绍一下我心里是怎么想的, 动画是什么
				#include <iostream>
				using namespace std;

				const int N = 1000010;
				char p[N];
				char s[N];
				int ne[N];
				int n, m;

				int main(){
				    cin >> n >> (p + 1) >> m >> (s + 1); 	首先, 我们是
				    for(int i = 2, j = 0; i <= n; i++){
				        while(j && p[i] != p[j + 1]) j = ne[j];
				        // j == 0 or p[i] == p[j+1]
				        if(p[i] == p[j+1]) j++;
				        ne[i] = j;
				    }
				    for(int i = 1, j = 0; i <= m; i++){
				        while(j && s[i] != p[j + 1]) j = ne[j];
				        // j == 0 or s[i] == p[j+1]
				        if(s[i] == p[j + 1]) j++;
				        if(j == n){
				            cout << i - n + 1 - 1 << " ";
				            j = ne[j];
				        }
				    }
				    return 0;
				}
			2. 
				#include <iostream>
				using namespace std;

				const int N = 1000010;
				char p[N];
				char s[N];
				int ne[N];
				int n, m;

				int main(){
				    cin >> n >> (p + 1) >> m >> (s + 1);
				    for(int j = 0, i = 2; i <= n; i++){
				        while(j && p[i] != p[j + 1]) j = ne[j];
				        //有路可退 && 打不过
				        //无路可退 or 打得过
				        if(p[i] == p[j+1]) j++;
				        ne[i] = j; //不管是打得过{j!=0}还是无路可退{j==0}, 都要记录ne[i]
				    }
				    for(int j = 0, i = 1; i <= m; i++){
				        while(j && s[i] != p[j + 1]) j = ne[j];
				        if(s[i] == p[j + 1]) j++;
				        if(j == n){
				            cout << i - n + 1 - 1 << " ";
				            j = ne[j];
				        }
				    }
				    return 0;
				}
			3.
				#include <iostream>
				using namespace std;

				const int N = 1000010;
				char p[N], s[N];
				int ne[N], n, m;

				int main(){
				    cin >> n >> (p + 1) >> m >> (s + 1);	"注意是从index == 1开始输入"
				    for(int j = 0 "一开始是无路可退的", i = 2 "一开始我们是要比较p的第2个元素和第1个元素, 这里i指向的是第2个元素"; i <= n; i++){	
				    	"我们一上来就是保守打法: 也就是看我有没有退路, 如果有退路 并且 被打败{也就是不匹配}的话, 我们就到上一个退路. 也就是到简单的一关
				    	while(有路可退 && 打不过)"
				        while(j "j >= 1表明还有退路" && p[i] != p[j + 1] "不匹配,也就是打不过") j = ne[j]; "我们退到更加简单的一关游戏"
				        	"什么是有退路:
				        		走到这里, 就相当于我们代码是执行到中间了, 上下文都有了. 此时的j, 你想想是什么意思.
				        		j的意思是, 对于上一轮: [1, j]前缀区间a == [xx, i - 1]后缀区间b, 这里的 xx = i - 1 - j + 1, 因为区间长度是j
				        		我们这一轮要站在上一轮的肩膀上, 如果这一轮失败了: p[i] != p[j + 1]. 我们就要看 前缀区间a的 小前缀aa 和 小后缀ab
				        		j = ne[j], 其实是: 新j = ne[老j]
				        		之前: [1, 老j]前缀区间a == [xx, i - 1]后缀区间b
				        		现在: [1, 新j] == [yy, 老j] == [zz, i - 1]
				        			yy = 老j - 新j + 1. 因为区间长度是新j
				        			zz = i - 1 - 新j + 1. 因为区间长度是新j
				        		所以我们要比较的是 index == [新j + 1] 的这个点, 和 p[i]是否一样
				        		如果最后 j == 0, 说明区间长度是0, 也就是一点退路都没有, 要重新来了
				        		"

				        "走到这里, 有两种可能:	无路可退 or 打得过"
				        if(p[i] == p[j + 1]) j++; 		"打得过, 就j++"
				        ne[i] = j;		"不管是打得过{j!=0}  还是无路可退{j==0}, 都要记录ne[i]"
				    }
				    for(int j = 0 "一开始是无路可退的", i = 1 "一开始我们是要比较s的第1个元素和p的第1个元素, 这里i指向的是s的第1个元素";  i <= m; i++){
				        while(j "j >= 1表明还有退路" && s[i] != p[j + 1] "不匹配,也就是打不过") j = ne[j];
				        "走到这里, 有两种可能:	无路可退 or 打得过"
				        if(s[i] == p[j + 1]) j++;	"打得过, 就j++"
				        if(j == n){					"不需要构造 ne, 这里是看赢了没有, 赢了就是区间长度刚好是pattern的长度n"
				            cout << i - n + 1 - 1 << " ";	"因为终点是i, 长度是n, 所以起点是 i - n + 1, 因为题目是从0开始, 我们代码从1开始, 所以要-1"
				            j = ne[j];	"其实这一句要不要没所谓, 不写也是ok的, 这句话就代表着人生, 不能一直在巅峰, 你刚刚才站在山顶, 现在应该退一步, 因为你不可能一直在山顶"
				        }
				    }
				    "补充一下, 永远都有: ne[0] == 0, ne[1] == 0
				    ne[0] = 0, 因为第0位没用
				    ne[1] == 0, 因为最长后缀不能和最长前缀重合
				    	例如: a a a a a a a a a 一共9个字母
				    		i: 9 	ne[i]: 8  	前8个a 和 后8个a 是最长前后缀. 
				    		说明最长前后缀是不能完全重叠的, 也就是不能是全部九个a"
				    return 0;
				}
	* 29. AcWing 835. Trie字符串统计
		1. bug
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int s[N][26], ind;
			int cnt[N], n;

			---错误: void insert(string str){ 正确: void insert(char* str) 
			    int p = 0;
			   ---错误: for(int i = 0 ; str; i++){ 正确: for(int i = 0; str[i]; i++){
			        int l = str[i] - 'a';
			        if(!s[p][l]) s[p][l] = ++ ind;	注意, 是 ++ind, 因为index==0是根节点, 第一个son是从ind==1开始
			        p = s[p][l];
			    }
			    cnt[p] ++;
			}

			---错误: int query(string str){	正确: int query(char* str). 
			    int p = 0;
			    ---错误: for(int i = 0 ; str; i++){ 正确: for(int i = 0; "str[i]"; i++){
			        int l = str[i] - 'a';
			        if(!s[p][l]) return 0;
			        p = s[p][l];
			    }
			    return cnt[p];
			}



			int main(){
			    scanf("%d", &n);
			    while(n--){
			        char op[2];		注意, 因为输入是 'I xxx' 有空格, 所以用了op[2]
			        ---错误: string str; 正确: char str[N];	如果用string, 就是会 segment fault
			        scanf("%s%s", op, str);
			        if(*op == 'I'){			注意是 *op
			            insert(str);
			        }else{
			            printf("%d", query(str));
			        }
			    }
			    return 0;
			}
		2. ok
			#include <iostream>
			using namespace std;

			const int N = 100010;
			int s[N][26], cnt[N * 26], ind;	 
				ind最多有 N*26个, 所以 cnt[N * 26]
				s[N][26], 如果某个string的长度刚好是 1e5, 例如全是aaaa...{1e5个}, 就把第一列全填满了

			void insert(char* str){
			    int root = 0;
			    for(int i = 0; str[i]; i++){
			        int son = str[i] - 'a';
			        if(!s[root][son]) s[root][son] = ++ ind;	看第root行, 有没有这个字母
			        root = s[root][son];	跳到第ind行
			    }
			    cnt[root] ++;
			}

			int query(char* str){
			    int root = 0;
			    for(int i = 0;  str[i]; i++){
			        int son = str[i] - 'a';
			        if(!s[root][son]) return 0;
			        root = s[root][son];
			    }
			    return cnt[root];
			}

			int main(){
			    int n;
			    scanf("%d", &n);
			    while(n--){
			        char op[2], str[N];
			        scanf("%s%s", op, str);
			        if(*op == 'I') insert(str);
			        else printf("%d\n", query(str));
			    }
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 1e5 + 10;
			int s[N][26], cnt[N * 26], ind;

			void insert(char* str){
			    int root = 0;
			    for(int i = 0; str[i]; i++){
			        int son = str[i] - 'a';
			        if(!s[root][son]) s[root][son] = ++ ind;
			        root = s[root][son];
			    }
			    cnt[root] ++;
			}

			int query(char* str){
			    int root = 0;
			    for(int i = 0; str[i]; i++){
			        int son = str[i] - 'a';
			        if(!s[root][son]) return 0;
			        root = s[root][son];
			    }
			    return cnt[root];
			}

			int main(){
			    int n;
			    scanf("%d", &n);
			    while(n--){
			        char op[2], str[N];
			        scanf("%s%s", op, str);
			        if(*op == 'I') insert(str);
			        else printf("%d\n", query(str));
			    }
			    return 0;
			    
			}
	* 30. AcWing 143. 最大异或对
		1. bug
			另外的思考:
				为什么上一题, 不能一边插入, 一边查找? 这道题却可以
				答案:
					上一题: 
						insert的单词 和 query的单词, 都不是同一套单词
					这一题:
						insert的单词 和 query的单词, 是同一套单词, 也就是单词两两之间比较, 既然是两两, a和b握手后, b就不需要再次和a握手了
			#include <iostream>
			using namespace std;

			const int N = 1e5 + 10;
			int s[N * 31][2], ind;	注意, 不要忘了[2]

			void insert(int v){
			    int root = 0;
			    错误: for(int i = 31; i; i--){ 	正确: for(int i = 30; ~i; i--){ 
			    									我们的数字v只有31位{也就是int吧, 首位是符号, 后31位是实际的}. 
			    									最高位是 v >> 30 & 1, 最低位是 v >> 0 & 1
			    									反正你就记得, 一共31位,右移了30位只剩下最后1位

			    									如果 i >= 0 是 ~i, 也就是 i != -1
			    									如果 i > 0 是 i, 也就是 i >= 1 或者 i != 0

			        int son = v >> i & 1;
			        int &temp = s[root][son];	注意: 这里是别名 &temp, 所以我们可以就把temp当成 s[root][son]
			        							修改temp相当于修改s[root][son]. temp是左值?
			        if(!temp) temp = ++ ind;
			        root = temp;
			    }
			}

			int query(int v){
			    int root = 0;
			    int res = 0;
			    错误: for(int i = 31; i; i--){ 	正确: for(int i = 30; ~i; i--){
			        int son = v >> i & 1;
			        if(s[root][!son]){			找的是和son不同的, 如果son是1, 我们就找0. 如果有的话, 我们异或就是1
			            res += 1 << i;			如果有的话, 我们异或就是1. 所以第i位是1. 注意这里第i位也是从0开始 
			            root = s[root][!son];	然后我们就走 !son的路线, 为什么不是 son的路线, 因为我们走的路线, 本来就不是数字v代表的路线, 而是数字v的异或值代表的路线
			        }else root = s[root][son];	如果找不到, 就找v的第i位数字代表的路线, 所以有种杂糅的感觉
			    }
			    return res;
			}

			int main(){
			    int n;
			    int v;
			    int res = 0;
			    scanf("%d", &n);
			    while(n--){
			        scanf("%d", &v);
			        insert(v);
			        res = max(res, query(v));	因为每个数字v, 都有他能找到的最大疑惑res. 我们要找到所有res里面的最大的res
			    }
			    cout << res << endl;
			    return 0;
			}
		2. ok
			#include <iostream>
			using namespace std;

			const int N = 1e5 + 10;
			int s[N * 31][2], ind;

			void insert(int v){
			    int root = 0;
			    for(int i = 30; i >= 0; i--){
			        int son = v >> i & 1;
			        if(!s[root][son]) s[root][son] = ++ ind;
			        root = s[root][son];
			    }
			}

			int query(int v){
			    int root = 0, res = 0;
			    for(int i = 30; i >= 0; i --){
			        int son = v >> i & 1;
			        if(s[root][!son]){
			            res += 1 << i;
			            root = s[root][!son];
			        }else root = s[root][son];
			    }
			    return res;
			}

			int main(){
			    int n, v;
			    scanf("%d", &n);
			    int res = 0;
			    while(n--){
			        scanf("%d", &v);
			        insert(v);
			        res = max(res, query(v));
			    }
			    cout << res << endl;
			    return 0;
			}
	31. AcWing 836. 合并集合
		1. bug
		2. ok
			#include <iostream>
			using namespace std;

			const int N = 1e5 + 10;
			int p[N];

			int find(int x){
			    if(p[x] != x) p[x] = find(p[x]);	如果我不是祖宗{那我就要找我的祖宗}, 我的父亲 = 父亲的父亲 = 父亲的父亲的父亲 = ... = 祖宗
			    return p[x];	返回父亲{祖宗}
			}

			int main(){
			    int n, m;
			    cin >> n >> m;
			    for(int i = 1; i <= n; i++) p[i] = i;
			    while(m--){
			        char op[2];
			        int a, b;
			        scanf("%s%d%d", op, &a, &b);			 防止题目出现莫名其妙的空格等
			        if(*op == 'M') p[find(a)] = find(b);
			        else{
			            if(find(a) == find(b)) puts("Yes");
			            else puts("No");
			        }
			    }
			}
	32. AcWing 837. 连通块中点的数量
		1. bug
		2. ok
			看上去是图的问题, 其实连通块其实是 并查集的问题
			#include <iostream>
			using namespace std;

			const int N = 1e5 + 10;
			int p[N], cnt[N];

			int find(int x){
			    if(x != p[x]) p[x] = find(p[x]);
			    return p[x];
			}

			int main(){
			    int n, m;
			    scanf("%d%d", &n, &m);
			    for(int i = 1; i <= n; i++){
			        p[i] = i;
			        cnt[i] = 1;
			    }
			    while(m--){
			        string op;
			        int a, b;
			        cin >> op;
			        if(op == "C"){
			            cin >> a >> b;
			            int pa = find(a), pb = find(b);
			            if(pa != pb){
			                p[pa] = pb;
			                cnt[pb] += cnt[pa];
			            }
			        }else if(op == "Q1"){
			            cin >> a >> b;
			            if(find(a) != find(b)) puts("No");
			            else puts("Yes");
			        }else{
			            cin >> a;
			            cout << cnt[find(a)] << endl;
			        }
			    }
			    return 0;
			}
	todo s 33. AcWing 240. 食物链
	34. AcWing 838. 堆排序
		1. bug
			void down(int u){
			    int l = u * 2, r = u * 2 + 1;
			    int t = u;
			    if(l <= cnt && h[l] < h[t]) t = l;
			    if(r <= cnt && h[r] < h[t]) t = r;
			    错误:
			    	if(t != u) swap(h[t], h[u]);
			    	down(t);
			    正确:
				    if(t != u){
				        swap(h[t], h[u]);
				        down(t);			注意, 不是 down(u), u是树靠上方的index, t是树下方的index
				    }
			}
		2. ok
			#include <iostream>
			using namespace std;

			const int N = 1e5 + 10;
			int h[N], cnt;
			int n, m;

			void down(int u){
			    int l = u * 2, r = u * 2 + 1;
			    int t = u;
			    if(l <= cnt && h[l] < h[t]) t = l;
			    if(r <= cnt && h[r] < h[t]) t = r;
			    if(t != u){
			        swap(h[t], h[u]);
			        down(t);			注意, 不是 down(u), u是树靠上方的index, t是树下方的index
			    }
			    
			}

			int main(){
			    cin >> n >> m;
			    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
			    cnt = n;		因为之后有 h[cnt --]; 所以cnt是会变化的 
			    
			    这里是堆排序, 只用到down
			    for(int i = n / 2; i; i--) down(i); 注意: 最后一个非叶子节点是 cnt / 2, 然后 i >= 1, 写成 i 
			    		"for(int i = 100; i >= 0; i--)	--> i != -1 --> ~i
						for(int i = 100; i >= 1; i--)	--> i != 0 --> i"
			    
			    while(m--){
			        printf("%d ", h[1]);
			        h[1] = h[cnt --];
			        down(1);
			    }
			    puts("");
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 1e5 + 10;
			int h[N], cnt;
			int n, m;

			void down(int u){
			    int l = u * 2, r = u * 2 + 1;
			    int t = u;
			    if(l <= cnt && h[l] < h[t]) t = l;
			    if(r <= cnt && h[r] < h[t]) t = r;
			    if(t != u){
			        swap(h[t], h[u]);
			        down(t);
			    }
			}

			int main(){
			    cin >> n >> m;
			    for(int i = 1; i <= n; i++) scanf("%d", &h[i]);
			    cnt = n;
			    for(int u = cnt / 2; u; u--) down(u);
			    while(m--){
			        printf("%d ", h[1]);
			        h[1] = h[cnt--];
			        down(1);
			    }
			    return 0;
			}
	* 35. AcWing 839. 模拟堆
		1. bug
			#include <iostream>
			#include <cstring>
			using namespace std;

			const int N = 1e5 + 10;
			int heap[N], hindex[N], order[N];
			int cnt;

			void hswap(int i, int j){
			    int oi = order[i], oj = order[j];	oi: a是第oi个到来的人, oj: b是第oj个到来的人. 这个oi和oj是纸质的表上的左侧的内容
			    swap(hindex[oi], hindex[oj]);
			    swap(heap[i], heap[j]);
			    swap(order[i], order[j]);
			}

			联想故事:
				1.
					1. heap的下标: 一座座房子, 是固定的, 一个数组的下标怎么可能会移动呢
					2. 值: 一个人, 人是可以移动的, 可以从一个房子转移到另一个房子
					3. 某个人是第o个加入的: o是这个人的固定属性, o和这个人是绑定的, 不管这个人从哪个房子搬家到了哪个房子, 他都是第o个插入的, 永不变
				2. 现在要交换:
					1. 人a 和 人b 要互换房子
						a是第oi个到来的人, b是第oj个到来的人
						换之前, 他们的房子的编号分别是 参数: i, j
					2. 如果要换, 有以下的信息需要改:
						1. swap(hindex[oi], hindex[oj]);
							我们联想有一张纸质的表 hindex, 上面记载着第o个人的房子的编号: hindex[o]
							我们把两个人的房子编号换一换就好了, 也就是纸质的表里面 oi 上面记录的内容 hindex[oi] 和 oj上面记录的内容 hindex[oj] 调换
						2. swap(heap[i], heap[j]);
							房子i,j都换了新主人, 把主人换了吧{把值换了}
						3. swap(order[i], order[j]);
							房子i,j的主人的属性也要换, 因为属性和主人是绑定的. 


			void down(int u){
			    int l = u * 2, r = u * 2 + 1;
			    int t = u;
			    if(l <= cnt && heap[l] < heap[t]) t = l;
			    if(r <= cnt && heap[r] < heap[t]) t = r;
			    错误:
			    	if(t != u) hswap(t, u);
				    down(t);
			    正确:
				    if(t != u) {
				        hswap(t, u);
				        down(t);
				    }
			}

			void up(int u){
			    while(u / 2 && heap[u] < heap[u / 2]){
			       hswap(u, u / 2);
			       u = u / 2;
			    } 
			}

			int main(){
			    int n, o = 0;
			    scanf("%d", &n);
			    char op[5]; // 错误: string op;
			    int k, v;
			    while(n--){
			        scanf("%s", op);
			        if (!strcmp(op, "I")) // 错误: if(op == "I")
			        {
			            scanf("%d", &v);
			            o++, cnt++;		先++, 也就是第o个插入的+1, 下标cnt + 1. 所以下标都是从1开始
			            hindex[o] = cnt, order[cnt] = o, heap[cnt] = v;	第o个加入的在heap中的index是cnt, 下标是cnt是第o个加入的, 下标是cnt是值是v
			            up(cnt);
			        } 
			        else if (!strcmp(op, "PM"))// 错误:  else if(op == "PM") 
			        {
			            printf("%d\n", heap[1]);
			        }
			        else if (!strcmp(op, "DM"))// 错误: else if(op == "DM")
			        {
			            hswap(1, cnt);
			            cnt --;
			            down(1);
			        }else if (!strcmp(op, "D")){
			            scanf("%d", &k);
			            int ind = hindex[k];	找到第k个加入的在heap中的下标
			            错误: 忘记写这两句
			            正确:
				            hswap(ind, cnt);	
				            cnt --;
			            up(ind), down(ind);
			        }
			        else{
			            scanf("%d%d", &k, &v);
			            int ind = hindex[k];
			            heap[ind] = v;
			            up(ind), down(ind);
			        }
			    }
			    return 0;
			}
		2. ok
			#include <iostream>
			#include <cstring> //strcmp
			using namespace std;

			const int N = 1e5 + 10;
			int heap[N];
			int hindex[N], o;
			int order[N], cnt;

			void hswap(int ind1, int ind2){
			    int o1 = order[ind1], o2 = order[ind2];
			    swap(hindex[o1], hindex[o2]);	纸质表更换
			    swap(heap[ind1], heap[ind2]);	主人更换
			    swap(order[ind1], order[ind2]);	主人的属性更换 
			}

			void down(int u){
			    int l = u * 2, r = l + 1;
			    int t = u;
			    if(l <= cnt && heap[l] < heap[t]) t = l;
			    if(r <= cnt && heap[r] < heap[t]) t = r;
			    if(t != u){
			        hswap(t, u);
			        down(t);
			    }
			}

			void up(int u){
			    while(u / 2 && heap[u] < heap[u / 2]){
			        hswap(u, u / 2);
			        u /= 2;
			    }
			}


			int main(){
			    int n;
			    char op[5];
			    cin >> n;
			    while(n--){
			        scanf("%s", op);
			        int k, v;
			        if(strcmp(op, "I") == 0){
			            scanf("%d", &v);
			            o++, cnt++;
			            hindex[o] = cnt, order[cnt] = o, heap[cnt] = v;
			            up(cnt);
			        }else if(strcmp(op, "PM") == 0){
			            printf("%d\n", heap[1]);
			        }else if(strcmp(op, "DM") == 0){
			            hswap(1, cnt);
			            cnt--;
			            down(1);
			        }else if(strcmp(op, "D") == 0){ //-> 这个就是老师说的, 我们自己的heap, 可以实现删除任意个元素. 而不一定是堆顶
			            scanf("%d", &k);
			            int ind = hindex[k];
			            hswap(ind, cnt);
			            cnt--;
			            up(ind), down(ind);
			        }else{
			            scanf("%d%d", &k, &v);
			            int ind = hindex[k];
			            heap[ind] = v;
			            up(ind), down(ind);
			        }
			    }
			    return 0;
			}
2. 5.13
	36. AcWing 840. 模拟散列表
		1. bug
			1. 求大于2e5的最小质数:
				int main(){
				    for(int i = 2e5; ; i++){
				        bool f = false;
				        for(int j = 2; j <= i / j; j++){
				        	错误: if(i / j == 0){
				            正确: if(i % j == 0){
				                f = true;
				                错误: 忘记写: break;
				                正确: break; -> 说明i可以被某个j整除, 所以break掉内层for loop, 继续看下一个i. 注意这里是break, 不是continue
				            }
				        }
				        错误: if(f) cout << i << endl; f == true代表不是质数, 而且没有break, 会无限循环i, 就TLE了
				        正确: 
				        	if(!f) {
					            cout << i << endl; 
					            break;
					        }
				    }
				    return 0;
				}
			2. 模拟hash {开放寻址法}
				#include <iostream>
				#include <cstring>
				using namespace std;

				const int N = 2e5 + 3, null = 0x3f3f3f3f;
				错误: int hash[N]; 这个是一个系统的struct
				正确: int h[N];

				void insert(int v){
				    int ind = (v % N + N) % N;
				    while(h[ind] != null && h[ind] != v){
				        ind++;
				        if(ind == N + 1) ind = 0;
				    }
				    h[ind] = v;
				}

				bool query(int v){
				    int ind = (v % N + N) % N;
				    while(h[ind] != null && h[ind] != v){
				        ind ++;
				        if(h == N + 1) ind = 0;
				    }
				    return h[ind] == v;
				}
				int main(){
				    错误: 忘记写这一句memset
				    正确: memset(h, 0x3f, sizeof h);
				    int n;
				    cin >> n;
				    错误: string op; 因为之后 scanf("%s%d", op, &v); 这样op会读出一整行, 包括了v的内容
				    正确: char op[2]; 限定为2个字符
				    int v;
				    while(n--){
				        scanf("%s%d", op, &v);
				        if(*op == 'I') insert(v);
				        else{
				            if(query(v)) puts("Yes");
				            else puts("No");
				        }
				    }
				    return 0;
				}
			3. 模拟hash{拉链法}, 更短代码
				#include <iostream>
				#include <cstring>
				using namespace std;

				const int N = 2e5 + 3;
				int hh[N], e[N], ne[N], ind;	就是正常的链表

				void insert(int v){
				    int k = (v % N + N ) % N;	k: 读作坑
				    e[ind] = v, ne[ind] = hh[k], hh[k] = ind ++;
				}

				bool query(int v){
				    int k = (v % N + N) % N;
				    for(int i = hh[k] ; ~i; i = ne[i]){	遍历
				        if(e[i] == v) return true;
				    }
				    return false;
				}

				int main(){
					错误: memset(hh, 0x3f, sizeof hh);
				    正确: memset(hh, -1, sizeof hh);
				    int n, v;
				    char op[2];
				    cin >> n;
				    while(n--){
				        scanf("%s%d", op, &v);
				        if(*op == 'I') insert(v);
				        else{
				            if(query(v)) puts("Yes");
				            else puts("No");
				        }
				    }
				    return 0;
				}
		2. ok{有3个知识}
			1. 求大于2e5的最小质数:
				背这个:
					#include <iostream>
					using namespace std;
					int main(){
					    int i;
					    for(i = 2e5 ; ; i ++){
					        int j;
					        for(j = 2; j <= i / j; j++) if(i % j == 0) break; 也就是看下一个
					        if(i % j != 0) break;	也就是如果不能被整除, 说明i就是我们要找的质数
					    }
					    cout << i << endl;
					}
				---
				#include <iostream>
				using namespace std;

				int main(){
				    for(int i = 2e5; ; i++){
				        int j;
				        for(j = 2; j <= i / j; j++){
				            if(i % j == 0){
				                break;
				            }
				        }
				        if(i % j != 0){	如果不能被整除, 说明i就是我们要找的质数
				            cout << i << endl;
				            break;
				        }
				    }
				}
				--
				#include <iostream>
				using namespace std;

				int main(){
				    for(int i = 200000; ; i++){
				        bool is_prime = true;
				        for(int j = 2; j <= i / j; j++){
				            if(i % j == 0){
				                is_prime = false;
				                break;
				            }
				        }
				        if(is_prime) {
				            cout << i << endl; 
				            break;
				        }
				    }
				    
				    return 0;
				}
				--
				#include <iostream>
				using namespace std;

				int main(){
				    for(int i = 2e5; ; i++){
				        bool isp = true;
				        for(int j = 2; j <= i / j ; j ++){
				            if(i % j == 0){
				                isp = false;
				                break;
				            }
				        }
				        if(isp){
				            cout << i << endl;
				            break;
				        }
				    }
				}
			2. 模拟hash
				注意的点:
					hash数组的长度
						需要是数据范围的2倍以上, 数据是1e5, 所以我们要2e5以上
						另外长度, 需要是质数, 因为我们找坑位是 馍加馍, 需要质数: int ind = (v % N + N) % N;
					初始化hash
						需要是 0x3f3f3f3f, 对应的10进制是: 1 061 109 567 = 1e9
						为什么不是0, 因为你插入的数据, 值的范围是 −10^9≤x≤10^9
						所以用 const int null = 0x3f3f3f3f;

				#include <iostream>
				#include <cstring>
				using namespace std;

				const int N = 2e5 + 3, null = 0x3f3f3f3f; 注意, 这里的null不是关键词. nullptr和NULL才是. 另外N是大于2e5的最小质数 
				int heap[N];

				void insert(int v){
				    int ind = (v % N + N) % N;	馍加馍, 肉夹馍
				    while(heap[ind] != null && heap[ind] != v){	如果这个坑有人, 并且, 这个人不是我
				        ind++;
				        if(ind == N + 1) ind = 0;	小心超出范围
				    }
				    跳出来的时候, 这个坑没有人, 或者, 坑里的人就是我
				    if(heap[ind] == null) heap[ind] = v; 总之就把我放进去
				}

				bool query(int v){
				    int ind = (v % N + N) % N;
				    while(heap[ind] != null && heap[ind] != v){
				        ind ++;
				        if(ind == N + 1) ind = 0;
				    }
				    return heap[ind] == v;
				}
				int main(){
				    memset(heap, 0x3f, sizeof heap);
				    int n;
				    cin >> n;
				    char op[2];
				    int v;
				    while(n--){
				        scanf("%s%d", op, &v);
				        if(*op == 'I') insert(v);
				        else{
				            if(query(v)) puts("Yes");
				            else puts("No");
				        }
				    }
				    return 0;
				}
				--
				#include <iostream>
				#include <cstring>
				using namespace std;

				const int N = 2e5 + 3, null = 0x3f3f3f3f;
				int hh[N];

				void insert(int v){
				    int ind = (v % N + N) % N;
				    while(hh[ind] != null && hh[ind] != v){
				        ind++;
				        if(ind == N + 1) ind = 0;
				    }
				    if(hh[ind] == null) hh[ind] = v;
				}

				bool query(int v){
				    int ind = (v % N + N) % N;
				    while(hh[ind] != null && hh[ind] != v){
				        ind++;
				        if(ind == N + 1) ind = 0;
				    }
				    return hh[ind] == v;
				}

				int main(){
				    memset(hh, 0x3f, sizeof hh);
				    int n, v;
				    // string op;
				    char op[2];
				    cin >> n;
				    while(n--){
				        scanf("%s%d", op, &v);
				        if(*op == 'I') insert(v);
				        else{
				            if(query(v)) puts("Yes");
				            else puts("No");
				        }
				    }
				    return 0;
				}
			3. 模拟hash{拉链法}, 更短代码
				#include <iostream>
				#include <cstring>
				using namespace std;

				const int N = 2e5 + 3, null = 0x3f3f3f3f;
				int hh[N], e[N], ne[N], ind;	就是正常的链表

				void insert(int v){
				    int k = (v % N + N ) % N;	k: 读作坑
				    e[ind] = v, ne[ind] = hh[k], hh[k] = ind ++;
				}

				bool query(int v){
				    int k = (v % N + N) % N;
				    for(int i = hh[k] ; ~i; i = ne[i]){	遍历
				        if(e[i] == v) return true;
				    }
				    return false;
				}

				int main(){
				    memset(hh, -1, sizeof hh);
				    int n, v;
				    char op[2];
				    cin >> n;
				    while(n--){
				        scanf("%s%d", op, &v);
				        if(*op == 'I') insert(v);
				        else{
				            if(query(v)) puts("Yes");
				            else puts("No");
				        }
				    }
				    return 0;
				}
	* 37. AcWing 841. 字符串哈希
		0. 小总结:
			hash: 
				1. 上一题: 
					将很多数据放在hash表, 方便查找
					有点像 离散化, 不过离散化是排好序, 然后通过二分得到的ind来聚合
				2. 这一题: 找字符串匹配
					很像 kmp
		1. bug
			#include <iostream>
			using namespace std;

			typedef unsigned long long UII; 	因为hash值可能很大, 所以用 UII
												typedef只能用于类型: {pair<int,int>, unsigned long long}, 不能用于宏定义, 例如 x first y second

			const int N = 1e5 + 10, P = 131;
			int h[N], p[N];

			UII get(int l, int r){
			    return h[r] - h[l - 1] * p[r - l + 1];  -> 含义: p[r - l + 1] == P^(r - l + 1)
			}

			int main(){
			    int n, m;
			    scanf("%d%d", &n, &m);
			    错误: string str; 用  scanf("%s", ...) 的写法就是用 char [], 如果是string就cin>>
			    正确: char str[N]; 
			    scanf("%s", str + 1);
			    错误: 忘记写下一句
			    正确: p[0] = 1; // p[0] == P^0 == 1
			    for(int i = 1; i <= n; i++){		注意是 i == 1 开始, 很像 S[i] = S[i - 1] + a[i] 也是从 i == 1开始 
			        h[i] = h[i - 1] * P + str[i];	因为index小的是高位, 我们往右边面加字符的时候, 左侧{高位}的地位要抬高: h[i - 1] * P
			        p[i] = p[i - 1] * P; 			这个就是累乘: -> 含义: p[i] == P^i
			    }
			    while(m--){
			        int l1, r1, l2, r2;
			        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
			        if(get(l1, r1) == get(l2, r2)) puts("Yes");
			        else puts("No");
			    }
			    return 0;
			}
		2. ok
			#include <iostream>
			using namespace std;

			const int N = 1e5 + 10, P = 131;
			char str[N];
			int h[N], p[N];


			unsigned long long get(int l, int r){
			    return h[r] - h[l - 1] * p[r - l + 1];	要抬高多少? 就是 l - 1 + ?? == r, ?? == r - (l - 1) == r - l + 1, 注意这里不是求区间长度啊! 是走的距离
			    这里
			    	1. h[r] 对应着 a + b + c, 也就是前r个字母的hash
						    	|\
								| a\
								|--- \
								| b | c\
								|--------
						ind 	0        size
								高位 	 低位
						三角形高  高 		 低
					2. h[l - 1] 对应着 a, 也就是前l-1个字母的hash
								|\
								| a\
								|--- \
					3. 我们的要求的是 c, , 也就是[l,r]字母的hash
										|\
										| c\
										-----
					4. 所以要把 h[l - 1]抬高成 h[l - 1] * p[r - l + 1], 也就是 a + b
								|\
								| a\
								|--- 
								| b |
								|----
							要抬高多少? 就是 l - 1 如何变成 r
								l - 1 + ?? == r, ?? == r - (l - 1) == r - l + 1, 注意这里不是求区间长度啊! 是走的距离
					5. 直观:
						因为h[r]左侧高位[1,l-1]是已经被抬高了
						h[l-1]就是上面说的高位部分[1,l-1], 但是没有被抬高
						所以我们要抬高之后再减去
					6. 联想前缀和:
						[l, r]: S[r] - S[l-1], 不存在什么抬高
			}

			画面:
				str 0 		1		2		3		4		5		6
					'0'		|\		|\		
							| a\	| c\
							|---\	|--- \

				h 	0 		1		2		3		4		5		6
					'0'   	|\		|\		
							| a\	| a\
							|---\ 	|--- \
									| b | c\
									|--------	

				p 	0 		1		2		3		4		5		6
					'1' 	'131' 	'131^2'

			int main(){
			    int n, m;
			    scanf("%d%d", &n, &m);
			    scanf("%s", str + 1);	图中我们的三角形a,c是从str的ind==1开始的
			    p[0] = 1;				P^0 == 1
			    for(int i = 1; i <= n; i++){
			        h[i] = h[i - 1] * P + str[i];	将左侧的三角形a抬高 加上 新的小三角形c
			        p[i] = p[i - 1] * P;			记录P^i		
			    }
			    while(m--){
			        int a, b, c, d;
			        scanf("%d%d%d%d", &a, &b, &c, &d);
			        if(get(a, b) == get(c, d)) puts("Yes");
			        else puts("No");
			    }
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;

			typedef unsigned long long ULL;
			const int N = 1e5 + 10, P = 131;
			char str[N];
			int h[N], p[N];

			ULL get(int l, int r){
			    return h[r] - h[l - 1] * p[r - l + 1];
			}

			int main(){
			    int n, m;
			    scanf("%d%d", &n, &m);
			    scanf("%s", str + 1);
			    p[0] = 1;
			    for(int i = 1; i <= n; i++){
			        h[i] = h[i-1] * P + str[i];
			        p[i] = p[i-1] * P;
			    }
			    while(m--){
			        int a, b, c, d;
			        scanf("%d%d%d%d", &a, &b, &c, &d);
			        if(get(a, b) == get(c, d)) puts("Yes");
			        else puts("No");
			    }
			    return 0;
			    
			}
	* 38. AcWing 842. 排列数字
		1. bug
			#include <iostream>
			using namespace std;

			const int N = 10;
			int path[N];
			int n;

			void dfs(int cnt, int state){
			    if(cnt == n){
			        for(int i = 0; i < n; i++) printf("%d ", path[i]);
			        puts("");
			        return;
			    }

			    错误: for(int i = n - 1; i >= 0; i--)	要求字典序
			    正确: for(int i = 0; i < n; i++){		之所以从0开始, 是因为题目要求字典序输出, 所以第一个输出的是 1234567, 第二个是 1 2 3 4 5 7 6. 
			        if(!(state >> i & 1)){
			            path[cnt++] = i + 1;
			            state += 1 << i;
			            dfs(cnt, state);
			            state -= 1 << i;
			            错误: 忘记加: cnt--;
			            正确: cnt--;
			        }
			    }
			}
			int main(){
			    cin >> n;
			    dfs(0, 0);
			}

		2. ok{多种版本}
			关键的点: "填写的位置一直都是从左往右依次填写, 只是填写的值是需要通过dfs全排列出来"
			#include <iostream>
			using namespace std;

			const int N = 10;
			int path[N];
			int n;

			void dfs(int size, int state){	已经添加了 size 个数字, state是状态{00010}代表数字2被填写过了. 
											其实这里不需要管细节: 
												你也可以是{01000}代表数字2被填写过了
													for(int i = 0; i < n; i++){
												        if((state >> (n - 1 - i) & 1) == 0){
												            path[size] = i + 1;
												            dfs(size + 1, state | (1 << (n - 1 - i)));
												        }
												    }
												反正我们都能遍历完所有情况
			    if(size == n){
			        for(int i = 0; i < n; i++) printf("%d ", path[i]);
			        puts("");
			        return;
			    }


				题目要求字典序, 所以 path[0] = 1, 所以从 i == 0 开始. 这里的i代表填入的数值. size代表已经添加的数字, 也是下一个要填入的位置的下标
					写法1: state和cnt都要恢复现场
						for(int i = 0; i < n; i++){
					        if(!(state >> i & 1)){
					            path[size++] = i + 1;
					            state += 1 << i;	
					            dfs(size, state);
					            state -= 1 << i;	恢复现场
					            size--;				恢复现场
					        }
					    }
					写法2: state不需要恢复现场
					    for(int i = 0 ; i < n; i++){
					        if((state >> i & 1) == 0){	==0说明这个数值没有被填写过 {注意不是填写位置的下标,"填写的位置一直都是从左往右依次填写, 只是填写的值是需要通过dfs全排列出来"}
					            path[size++] = i + 1;
					            dfs(size, state | (1 << i)); 这里没有改变 state, 不需要恢复现场, 但是下一层 dfs()的的确确收到了已经改变的 state
					            size --;						恢复现场
					        }
					    }
					写法3: state和cnt都不需要恢复现场
					    for(int i = 0 ; i < n; i++){
					        if((state >> i & 1) == 0){
					            path[size] = i + 1;				
					            dfs(size + 1, state | (1 << i)); 这里没有改变 state 和 cnt, 不需要恢复现场, 但是下一层 dfs()的的确确收到了已经改变的 state 和 cnt
					        }
					    }
				如果题目不要求字典序: 我们可以从高位开始判断 
				    for(int i = n - 1; i >= 0; i--){
				    	if(!(state >> i & 1)){
				    		path[size++] =  i + 1;
				    		dfs(size, state | (1 << i));	
				    		size --;	恢复现场
				    	}
				    }
			}
			int main(){
			    cin >> n;
			    dfs(0, 0);
			}


			想象: 其实就是一棵树
								  (....)					第一层 for()可以遍历所有n种情况
							  /  /  |   |  \  \
					(...) (...) (...) (...) (...) (...)		因为state有1位已经置为1了, 所以第二层的 for()中的 if(!(state >> i & 1)) 只能进入n-1次. 是一定是n-1, 而且 for()里面没有什么break
					/\
				(..) (..) (..) (..)	(..)....		(..)	因为state有2位已经置为1了, 所以第3层的 for()中的 if(!(state >> i & 1)) 只能进入n-2次, 而且 for()里面没有什么break
				/\
				(.) (.) (.) .... 					  (.)	因为state有3位已经置为1了, 所以第4层的 for()中的 if(!(state >> i & 1)) 只能进入n-3次, 而且 for()里面没有什么break

				从上到下的一条路径, 就是一个答案
				写代码, 写 dfs()这一句的时候, 是想着某一条路径怎么走到底, 而不是联想第一层, 第二层
					也就是写 dfs()这一句, 想的是一条条到底的路径的图画, 而不是像 bfs()一层一层的想图画
			--
			边写边"讲故事"
			#include <iostream>
			using namespace std;

			const int N = 10;
			int path[N], n;

			void dfs(int size, int state){
			    if(size == n){
			        for(int i = 0; i < n; i ++) printf("%d ", path[i]);
			        puts("");
			        return;
			    }
			    for(int i = 1; i <= n; i++){ 	要填写的数字是i, 从1开始
			        int ind = i - 1; 			数字i, 对应状态中的右数第i-1位. 例如数字1对应state的右数第0位
			        if((state >> ind & 1) == 0){	如果这个数字没有被填写过
			            path[size] = i;
			            dfs(size + 1, state | (1 << ind)); 	
			            				注意, 这个 dfs()是写在 if((state >> ind & 1) == 0) 里面的!! 不要写到外面 
			            				写的时候, 就想着一条路就这么到底了
			            					第一条: 1234567	倒数第二层的 for(), if(!(state >> i & 1)) 只能6,7进去了{因为12345都填好了}, 假设6进去, 下一层for只能是7. 所以输出1234567
			            					第二条: 1234576 倒数第二层的 for(), if(!(state >> i & 1)) 只能6,7进去了{因为12345都填好了}, 假设遍历到了7进去, 下一层for只能是6. 所以输出1234576
			        }
			    }
			}

			int main(){
			    cin >> n;
			    dfs(0, 0);
			}
			--
			#include <iostream>
			using namespace std;
			const int N = 10;
			int path[N], n;

			void dfs(int size, int state){
			    if(size == n){
			        for(int i = 0; i < n; i++) printf("%d ", path[i]);
			        puts("");
			        return;
			    }
			    for(int i = 1; i <= n; i++){
			        int ind = i - 1;
			        if((state >> ind & 1) == 0){
			            path[size] = i;
			            dfs(size + 1, state | (1 << ind));
			        }
			    }
			}

			int main(){
			    cin >> n;
			    dfs(0, 0);
			}
	* 39. AcWing 843. n-皇后问题
		0. 小总结
			相似性:
				1. 全排问题的path的从左到右的每个格子 
					== n皇后的棋盘从上到下每一行
				2. 全排中path的第i个格子填了数字3, 第i+1个格子就不能填3 
					== n皇后的棋盘第i行的第3列填了皇后, 第i+1行的第3列就不能填皇后{外加对角线/斜对角线的限制} 
		1. bug
			#include <iostream>
			using namespace std;

			错误: const int N = 10;
			正确: const int N = 20;	注意, 对角线是两倍的行数/列数

			错误: char g[N][N], n; 我的n设置成了char. 那肯定不对啊, TLE
			正确:
				char g[N][N];
				int n;
			bool col[N], dg[N], cdg[N]; //clinodiagonal
				注意 
					这里是bool类型
					只是一维数组, 不是二维, 因为 col[3] == false 就代表了整个第4列都是没有填的. 只要第4列有一个地方填了皇后, col[3] == true;
					注意没有row[N], 因为dfs就是一行一行来的, 一行不漏

			void dfs(int r){
				错误: if(r == n - 1){
			    正确: if(r == n){	这里要小心啊, 只有当最后一层 n - 1层摆放好了之后, 到dfs的第n层越界了才是结束了
			        for(int i = 0; i < n; i++) puts(g[i]); 这里的 g[i]是一整行
			        puts("");
			        return;
			    }
			    for(int i = 0; i < n; i++){
			        if(!col[i] && !dg[r + i] && !cdg[i - r + n]){ 不管是 i - r + n 还是 r - i + n 都行, 只要是相减皆可以, 然后 + n, 防止相减后负数
			            col[i] = dg[r + i] = cdg[i - r + n] = true;
			            g[r][i] = 'Q';
			            dfs(r + 1);
			            g[r][i] = '.';
			            col[i] = dg[r + i] = cdg[i - r + n] = false;
			        }
			    }
			}

			int main(){
			    cin >> n;
			    我们先画好, 而不是在dfs里面画{虽然在里面也可以}
			    for(int i = 0 ; i < n; i ++)
			        for(int j = 0; j < n; j++)
			            g[i][j] = '.';
			    dfs(0);
			}
		2. ok {只实现第二种方法, 第一种见 practice_basic, recite. 不容易理解} "讲故事"
			#include <iostream>
			using namespace std;

			const int N = 2 * 10;	开两倍, 因为有对角线
			char g[N][N];
			int n; //需要是全局, 因为这是所有dfs()都要用到的
			bool col[N], diag[N], clinodiag[N];

			void dfs(int r){	现在将要填的是第r行
			    if(r == n){	先递归到底, 也就是越界了
			        for(int i = 0; i < n; i++) puts(g[i]);	打印行
			        puts("");
			        return;
			    }
			    for(int c = 0; c < n; c ++){	好了, 我们就挨个检查第c列
			        if(!col[c] && !diag[c + r] && !clinodiag[c - r + n]){			如果第c列是空的, 如果第xx对角线是空的, 如果第yy斜对角线是空的, 注意是c, c + r, c - r + n. 我老是错写成只是 c
			            col[c] = diag[c + r] = clinodiag[c - r + n] = true;
			            g[r][c] = 'Q';
			            dfs(r + 1); 
			                //第c列填了皇后, 到了下一行, 这个第c列就不能放了. 因为 if(!col[c] && !diag[c] && !clinodiag[c]) 就通不过了
			                //因为col[N], diag[N], clinodiag[N]都是全局变量
			            		//在 dfs(r + 1)里面, if(!col[c] && !diag[c] && !clinodiag[c]) 就通不过了, 因为col[c] = diag[c] = clinodiag[c] == true
			                //这种第r行干的坏事{放皇后}, 第r+1行就干不了的, 就是和全排一样, 路径越往后, 能有的选项越少, 大白话: 路越走越窄.
			            g[r][c] = '.';
			            col[c] = diag[c + r] = clinodiag[c - r + n] = false;
			        }
			    }
			}
			int main(){
			    cin >> n;
			    
			    // 别忘了把初始的图画出来
			    for(int i = 0; i < n; i++)
			        for(int j = 0; j < n; j++)
			            g[i][j] = '.';
			    dfs(0);	现在将要填的是第0行
			}
			--
			#include <iostream>
			using namespace std;

			const int N = 2 * 10;
			char g[N][N];
			int n;
			bool col[N], diag[N], cdiag[N];

			void dfs(int r){
			    if(r == n){
			        for(int i = 0; i < n; i++) puts(g[i]);
			        puts("");
			        return;
			    }
			    for(int c = 0; c < n; c++){
			        if(!col[c] && !diag[c + r] && !cdiag[c - r + n]){
			            col[c] = diag[c + r] = cdiag[c - r + n] = true;
			            g[r][c] = 'Q';
			            dfs(r + 1);
			            g[r][c] = '.';
			            col[c] = diag[c + r] = cdiag[c - r + n] = false;
			        }
			    }
			}

			int main(){
			    cin >> n;
			    for(int i = 0 ; i < n ; i++)
			        for(int j = 0 ; j < n; j++)
			            g[i][j] = '.';
			    dfs(0);
			}
	40. AcWing 844. 走迷宫
		1. bug	
			#include <iostream>
			#include <cstring>
			#include <queue>
			using namespace std;

			const int N = 110;
			int g[N][N], dist[N][N];
			int n, m;
			typedef pair<int, int> PII;

			int bfs(){
			    memset(dist, -1, sizeof dist);
			    dist[0][0] = 0;
			    
			    queue<PII> q;
			    q.push({0, 0}); 					错误: q.push_back({0, 0});
			    
			    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
			    	上右下左
			    	dx和dy是关于 | 对称的
			    
			    while(q.size()){
			        auto t = q.front(); 						错误: auto t = q.top();
			        q.pop();
			        
			        int ox = t.first, oy = t.second;
			        for(int i = 0; i < 4 ; i++){
			            int x = ox + dx[i], y = oy + dy[i];
			            if(0 <= x && x < n && 0 <= y && "y < m" && !g[x][y] && dist[x][y] == -1){ 		错误: if(0 <= x && x < n && 0 <= y && "y < n" && !g[x][y] && dist[x][y] == -1){
			                dist[x][y] = dist[ox][oy] + 1;
			                if(x == n - 1 && y == m - 1) return dist[x][y];
			                q.push({x, y});			错误: q.push_back({x, y});
			            }
			        }
			    }
			    return dist[n - 1][m - 1];
			}
			int main(){
			    cin >> n >> m;
			    for(int i = 0; i < n; i++){
			        for(int j = 0; j < m; j++){
			            scanf("%d", &g[i][j]);
			        }
			    }
			    printf("%d", bfs());
			}
		2. ok
			因为是二维地图, 所以我们需要 pair<int, int> PII 记录二维坐标
			这种是无距离题目
				所以一个点{x,y}, 只能进入queue一次
				一旦进入了, dist[x][y]就是距离起点的最短距离, 之后不会再被更新{放松}
				所以合法性判断是 dist[x][y] == -1
					如果 dist[x][y] != -1, 说明已经进入过queue了, 再进入也没用因为肯定不是最短距离了, 因为bfs层数越大, 距离起点是越来越远的
			#include <iostream>
			#include <queue>
			#include <cstring>
			using namespace std;

			const int N = 110;
			int g[N][N], dist[N][N], n, m;
			typedef pair<int, int> PII;

			int bfs(){
				看看都有什么东西要初始化: dist, queue
			    memset(dist, -1, sizeof dist); 都是 0xfffffff, 也就是max最大值
			    dist[0][0] = 0;
			    
			    queue<PII> q;
			    q.push({0,0});
			    
			    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
			    
			    while(q.size()){
			        auto t = q.front();
			        q.pop();
			        
			        int ox = t.first, oy = t.second;
			        for(int i = 0; i < 4; i++){
			            int x = ox + dx[i], y = oy + dy[i];
			            if(0 <= x && x < n && 0 <= y && y < m && g[x][y] == 0 && dist[x][y] == -1){
			                dist[x][y] = dist[ox][oy] + 1;	更新距离
			                if(x == n - 1 && y == m - 1) return dist[x][y];
			                q.push({x, y});
			            }
			        }
			    }
			}

			int main(){
			    cin >> n >> m;
			    for(int i = 0 ; i < n; i++)
			        for(int j = 0 ; j < m; j++)
			            scanf("%d", &g[i][j]);
			    cout << bfs() << endl;
			    return 0;
			}
	* 41. AcWing 845. 八数码/华容道
		0. 小总结
			1. 什么时候需要恢复状态:
				本题需要, 如果字符串t被修改
					老师没有备份t, 所以要恢复状态
					我备份了, 所以不需要回复
				上一题不需要, 因为{ox,oy}没有修改
					上一题代码, 其中ox, oy在 for(i < 4) 中一直不变
					int ox = t.first, oy = t.second;
			        for(int i = 0; i < 4 ; i++){
			            int x = ox + dx[i], y = oy + dy[i];
			            if(0 <= x && x < n && 0 <= y && "y < m" && !g[x][y] && dist[x][y] == -1){ 		错误: if(0 <= x && x < n && 0 <= y && "y < n" && !g[x][y] && dist[x][y] == -1){
			                dist[x][y] = dist[ox][oy] + 1;
			                if(x == n - 1 && y == m - 1) return dist[x][y];
			                q.push({x, y});			错误: q.push_back({x, y});
			            }
			        }
			2. 
				1. queue
					存状态: 
						queue<string> q;
					存二维地图: 
						queue<pair<int,int>> q;

				2. dist
					存状态:	
						unordered_map<string, int> dist;
						dist["start"] = 0;
					存二维地图: 
						dist[N][N];
						memset(dist, -1, sizeof dist);
						dist[0][0] = 0;
		1. bug
			#include <iostream>
			#include <queue>
			#include <unordered_map>
			using namespace std;

			const string ending = "12345678x";
			string start;

			int bfs(){
			    queue<string> q;
			    q.push(start);
			    
			    unordered_map<string, int> dist;
			    dist[start] = 0;
			        
			    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
			    while(q.size()){
			        string os = q.front();
			        q.pop();
			        
			        int oind = os.find('x');
			        int ox = oind / 3, oy = oind % 3;
			        for(int i = 0; i < 4; i ++){
			            int x = ox + dx[i], y = oy + dy[i];
			            string ns = os;
			            if(0 <= x && x < 3 && 0 <= y && y < 3){
			                int nind = 3 * x + y;
			                swap(ns[nind], ns[oind]);
			                错误:
			                	if(!dist.count(ns)) dist[ns] = dist[os] + 1;
			                    if(ns == ending) return dist[ns];
			                    q.push(ns);	这个是要在括号里面的!
			                正确:
				                if(!dist.count(ns)) {  如果dist中没有, 注意是dist, 不是queue中有没有. 对比之前是 dist[x][y] == -1.
				                    dist[ns] = dist[os] + 1;
				                    if(ns == ending) return dist[ns];
				                    q.push(ns);
				                }
			            }
			        }
			    }
			    错误: return ending;	另外, 不能用end, 这是关键字
			   	正确: return -1;
			}
	 
			int main(){
			    char s[2];
			    for(int i = 0; i < 9; i++){
			        cin >> s;	或者 scanf("%s", s); 都可以!!
			        start += *s;
			    }
			    cout << bfs() << endl;
			}
		2. ok
			1. 我的不恢复现场
				#include <iostream>
				#include <queue>
				#include <unordered_map>
				using namespace std;

				const string ending = "12345678x"; 
				string start;

				int bfs(){
				    queue<string> q;
				    q.push(start);
				    
				    unordered_map<string, int> dist;
				    dist[start] = 0;
				    
				    // 1. 旧x的string -> 坐标{ox, oy}
			        //     old.find(), / 3, % 3
			        // 2. 新x的坐标{x, y}
			        //     	1. ox + 4个偏移, oy + 4个偏移
			        // 		2. {x, y}合法的话
			        //      3. 坐标 -> string
			        // 			swap(news[x * 3 + y], news[ox * 3 + oy]);
			        //			这一步很关键:
			        //				for里面的每一次, 都要初始化原料, 是 string news = olds
			        //				
			        //         如果 dist 中有没有, 注意是dist不是queue. 对比之前是 dist[x][y] == -1.
			        //             更新: dist[new] = dist[old] + 1 
			        //             插入queue

				    // 主要是怎么从 老string -> 新string
					    // 0. 知道老'x'在string中的位置: find() -> 老ind
					    // 1. 找到老'x'的坐标{ox, oy}: /3, %3
					    // 2. 新'x'的坐标: 4个偏移 + 判断是否出界
					    // 3. 合法的新x的坐标{x, y}在string的位置: x * 3 + y -> 新ind
					    // 4. 用swap来处理string: 交换: 老ind, 新ind -> 实现了'x'在string中的转移
				    
				    总结的不错: 
				        // 1. find()               -> 老ind
				        // 2. /3,%3                -> 老坐标{ox, oy}
				        // 3. 偏移 + 判断合法      -> 新坐标{x, y}
				        // 4. x*3+y                -> 新ind
				        // 5. swap(老ind, 新ind)   -> 实现了'x'在string中的转移
				        
				    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
				    while(q.size()){
				        string os = q.front();	//old string
				        q.pop();
				        
				        int oind = os.find('x');	//old ind, 旧'x'在string中的位置
				        int ox = oind / 3, oy = oind % 3; 
				        for(int i = 0; i < 4; i ++){
				            int x = ox + dx[i], y = oy + dy[i]; // 新'x'在矩阵中的坐标{x, y}
				            string ns = os;		//new string, 4次中, 每次都要有: 没被污染的原材料ns
				            if(0 <= x && x < 3 && 0 <= y && y < 3){
				                int nind = 3 * x + y; //new indx, 新'x'在string中的位置
				                swap(ns[nind], ns[oind]); //swap()是用在string上, 所以要知道新旧'x'在string中的位置
				                if(!dist.count(ns)) { //如果dist中没有, 注意是dist, 不是queue中有没有. 对比之前是 dist[x][y] == -1.
				                    dist[ns] = dist[os] + 1;
				                    if(ns == ending) return dist[ns];
				                    q.push(ns);
				                }
				            }
				        }
				    }
				    return -1;
				}

				// 其实, 为什么只会进入一次queue, 只要有一次就是最短距离? 
				    // 	因为这道题, 只是'x'在string中移动的方式fancy了一些
				    // 	你就当做这是一个地图, 'x'只能上下左右移动, 就是无距离的dfs
				    // 	另外, 这道题, 我们实现上是移动'x', 其实题目的意思是移动数字, 然后移动数字的时候把'x'挤开了
					//  相当于我们要把数字挪成这个样子:
					// 	123
					// 	456
					// 	78


				int main(){
				    char s[2];
				    for(int i = 0; i < 9; i++){
				        cin >> s;
				        start += *s;
				    }
				    cout << bfs() << endl;
				}



			2. 老师的恢复现场{不背}
				老师没有备份, 所以swap两次
				while (q.size())
			    {
			        auto t = q.front();
			        q.pop();

			        if (t == end) return d[t]; 如果t是终点, 我们就提前结束 

			        int distance = d[t]; 先存一下这个节点t到起点的距离. 
			        int k = t.find('x'); 求一下, 'x'这个字符, 在状态{字符串}中的下标 
			        int x = k / 3, y = k % 3;	将下标转化为 第x行, 第y列 

			        for (int i = 0; i < 4; i ++ )
			        {
			            int a = x + dx[i], b = y + dy[i]; 3*3矩阵中, 新位置是{a,b}
			            if (a >= 0 && a < 3 && b >= 0 && b < 3) 如果{a,b}是合法的 
			            {
			                swap(t[a * 3 + b], t[k]); 3*3矩阵中的位置, 转换到string后, 就是 a * 3 + b
			                							这里的 t[a * 3 + b]是某个字符, 例如'1'
			                							t[k]是我们的字符'x'
			                							所以我们交换'x'和'1'
			                if (!d.count(t)) 如果这个新状态, 没有计算过. 
			                {
			                    d[t] = distance + 1; 我们就更新下它到起点状态的距离 
			                    q.push(t); 把这个状态装到queue中, 为了下一层的遍历
			                }

			                这个是恢复现场, 给下一个方向做准备. 因为下一个方向也是需要老状态t
			                swap(t[a * 3 + b], t[k]);
			            }
			        }
			    }
	42. AcWing 846. 树的重心
		1. bug
			#include <iostream>
			#include <cstring>
			using namespace std;

			const int N = 1e5 + 10, M = 2e5 + 10; //题目的节点数1e5, 题目给的边数也是1e5, 无向边开2倍
			int h[N], e[M], ne[M], ind;	注意, e,ne的大小是M, 因为边要记录 M==2*1e5, 每记录一次用一个ind, 所以e和ne也要M个
			bool st[N];
			int res;
			int n; //全局变量, 因为dfs()需要用

			void add(int a, int b){
			    e[ind] = b, ne[ind] = h[a], h[a] = ind ++;
			}

			int dfs(int u){
			    st[u] = true;
			    int maxsonsize = 0, allsize = 1; //是1是因为计算节点u自己
			    for(int i = h[u]; ~i; i = ne[i]){
			        int v = e[i];
			        if(!st[v]){
			            int sonsize = dfs(v);
			            maxsonsize = max(sonsize, maxsonsize);	最大的儿子的大小
			            allsize += sonsize;
			        }
			    }
			    错误: 忘写了
			    正确: maxsonsize = max(maxsonsize, n - allsize); //将点u删除后，剩余各个连通块中点数的最大值
			    
			    错误: res = max(res, maxsonsize);
			    正确: res = min(res, maxsonsize); //对于重心, 删除它后的{连通块中点数的最大值}, 最小的
			    return allsize;
			}

			int main(){
			    cin >> n;
			    memset(h, -1, sizeof h);

			    错误: res = 0;
			    正确: res = 0x3f3f3f3f;

			    错误: while(n--){ n之后还要用的啊!!
			    正确: for(int i = 0 ; i < n - 1; i ++ ){
			        int a, b;
			        scanf("%d%d", &a, &b);
			        add(a, b), add(b, a);
			    }
			    dfs(1);
			    cout << res << endl;
			    return 0;
			}
		2. ok{很顺}
			#include <iostream>
			#include <cstring>
			using namespace std;

			const int N = 1e5 + 10, M = 2 * N;
			int h[N], e[M], ne[M], ind;
			bool st[N];
			int res, n;

			void add(int a, int b){
			    e[ind] = b, ne[ind] = h[a], h[a] = ind ++;
			}

			int dfs(int u){
			    st[u] = true;						先记录遍历过了 
			    int maxsonsize = 0, allsize = 1;	最大儿子块的大小, 所有儿子块们的大小+u节点字节
			    for(int i = h[u]; ~i; i = ne[i]){
			        int v = e[i];
			        if(!st[v]){
			            int sonsize = dfs(v);
			            maxsonsize = max(sonsize, maxsonsize);	
			            allsize += sonsize;
			        }
			    }
			    maxsonsize = max(maxsonsize, n - allsize);	看u的父亲块是不是更大 
			    res = min(res, maxsonsize);
			    return allsize;
			}


			int main(){
			    memset(h, -1, sizeof h);
			    res = 0x3f3f3f3f;
			    
			    cin >> n;
			    for(int i = 0; i < n - 1; i++){
			        int a, b;
			        scanf("%d%d", &a, &b);
			        add(a, b), add(b, a);
			    }
			    dfs(2);	其实 dfs(谁)都可以, 但是可能怕没有节点2吧, 老师就写了 dfs(1)
			    cout << res << endl;
			    return 0;
			}
	------------------
			for(xx)
				if(合法)
					dfs(xx)

			for(h[i]; ...)
				int j = ne[i]
				if(!st[i]){
					bfs(xx)
				}
	------------------
			既然 add()两次, 无向图
			疑问:
				给定一个节点必定会遍历所有和它相连的子节点，这样不就无所谓父子节点了。
				比如从4开始遍历的话，上面的和下面两个连通块点数, 都被计算过并被加到sum中, 最后sum == N
				max(n-sum,res)就不合理了
			回答:
				max(n-sum,res)对于首次遍历的节点来说是没必要的
				但对后续的子节点dfs时由于已经过滤掉其父节点{来源的点}了
					for循环中就不能获取到以父节点为根的子树，这种情况就需要 max(n-sum,res)来保证

				例如:
					 1 ---
					 | \   \
					 2  \   7
					 | \ \
					 |  5 \
					 8	   4
					 	   |\
					 	   | 6
					 	   3
					 	   |
					 	   9
			继续疑问:
				为什么不能只用一个 add(a,b)?
			回答:
				因为你这样指明了方向, 可能就有问题
				因为你 dfs(起始点)中起始点可能会找错, 然后就不能遍历整张图
			我的其他观察:
				老师的代码, 起始dfs(不管是多少), 最后的答案都是正确的
	------------------
	43. AcWing 847. 图中点的层次{经典bfs简单题}
		0. 我感觉就是简化版的spfa
			不过spfa存在负权边, 所以并不是一进入queue中就是最小值
			但是这道题, 权重都是+1, 一进入queue就是最小值
		1. bug
			#include <iostream>
			#include <cstring>
			#include <queue>
			using namespace std;

			const int N = 1e5;
			int h[N], e[N], ne[N], ind;
			int n, m;
			int dist[N];
			bool st[N]; 其实可以不用st, 直接看dist[v] ?== -1.

			void add(int a, int b){
			    e[ind] = b, ne[ind] = h[a], h[a] = ind ++;
			}

			int bfs(int u){
			    错误: 忘记写
			    正确: memset(dist, -1, sizeof dist);
			    
			    dist[1] = 0;
			    
			    queue<int> q;
			    q.push(1);
			    
			    st[1] = true;
			    
			    while(q.size()){
			        int u = q.front();
			        q.pop();
			        
			        for(int i = h[u]; ~i; i = ne[i]){
			            int v = e[i];
			            if(!st[v]){
			                st[v] = true;	其实可以不用st, 直接看dist[v] ?== -1.
			                dist[v] = dist[u] + 1;
			                if(v == n) return dist[v];
			                q.push(v);
			            }
			        }
			    }
			    return -1;
			}

			int main(){
			    memset(h, -1, sizeof h);
			    cin >> n >> m;
			    while(m--){
			        int a, b;
			        scanf("%d%d", &a, &b);
			        add(a, b);
			    }
			    cout << bfs(1) << endl;
			}
		2. ok
			最短路问题, 是否连通问题: 都用bfs. dfs要遍历所有的路径太慢了
			#include <iostream>
			#include <queue>
			#include <cstring>
			using namespace std;

			const int N = 1e5 + 10;
			int h[N], e[N], ne[N], ind;
			queue<int> q;
			int dist[N];
			int n;

			void add(int a, int b){
			    e[ind] = b, ne[ind] = h[a], h[a] = ind ++;
			}

			int bfs(){
				插入起点: 
			    dist[1] = 0;
			    q.push(1);
			    
			    while(q.size()){
			        int u = q.front();
			        q.pop();
			        
			        for(int i = h[u]; ~i; i = ne[i]){
			            int v = e[i];
			            if(dist[v] == -1){				边权==1的联通问题, 一个节点要进就只能进入一次queue
			                dist[v] = dist[u] + 1;
			                if(v == n) return dist[v];
			                q.push(v);
			            }
			        }
			    }
			    return -1;
			}

			int main(){
				就看谁需要初始化, h还有dist.
			    memset(h, -1, sizeof h);
			    memset(dist, -1, sizeof dist);
			    
			    int m;
			    cin >> n >> m;
			    while(m--){
			        int a, b;
			        scanf("%d%d", &a, &b);
			        add(a, b);
			    }
			    
			    cout << bfs() << endl;
			    return 0;
			}
	--------
		思考: 
		图中可能存在重边和自环, 为什么邻接表ok? 
	44. AcWing 848. 有向图的拓扑序列
	1. bug
		#include <iostream>
		#include <cstring>
		using namespace std;

		const int N = 1e5 + 10;
		int h[N], e[N], ne[N], ind;
		int degree[N];
		int q[N], hh, tt = -1; //queue
		int n, m;

		void add(int a, int b){
		    e[ind] = b, ne[ind] = h[a], h[a] = ind ++;
		}

		bool topsort(){
		    for(int i = 1; i <= n; i++){
		        if(!degree[i]) q[++tt] = i;
		    }
		    while(hh <= tt){
		        错误: int u = q[hh--];
		        正确: int u = q[hh++];
		        for(int i = h[u]; ~i; i = ne[i]){
		            int v = e[i];
		            degree[v]--;					因为没有了u, 也就是v的源头少一个
		            if(!degree[v]) q[++tt] = v;
		        }
		    }
		    return tt == n - 1;
		}

		int main(){
		    错误: 忘写了
		    正切: memset(h, -1, sizeof h);
		    cin >> n >> m;
		    while(m--){
		        int a, b;
		        scanf("%d%d", &a, &b);
		        add(a, b);
		        degree[b]++;		b的源头多了一个, 那就是a
		    }
		    
		    if(!topsort()) puts("-1");
		    else{
		        方法1: for(int i = 0; i <= tt; i ++) printf("%d ", q[i]);
		        方法2: for(int i = 0; i < n; i ++) printf("%d ", q[i]);
		    }
		}
	2. ok
3. 5.14
	45. AcWing 849. Dijkstra求最短路 I
		0. 本题条件:
			稠密图:
				点: 1≤n≤500
				边: 1≤m≤10^5
			都是正权
		1. bug
			1. 遇到的错误:
				#include <iostream>
				#include <cstring>
				using namespace std;

				const int N = 510;
				int g[N][N], dist[N];	虽然g是二维数组, 但是不是代表二维地图, 而是邻接矩阵: 代表两个节点之间的距离. dist是一维数组, 某点到起点的最短距离
				bool st[N];				
				int n, m;

				int dijkstra()
				{
				    dist[1] = 0;	插入起点 
				    错误: st[1] = true;
				    正确: 不写, 因为 for(int i = 0; i < n - 1; i ++)第一个处理的就是节点1, 所以会在for里面 st[1] = true;

				    保险的写法: for(int i = 0; i < n; i ++) 
				    正确但是需要注意搭配的写法: for(int i = 0; i < n - 1; i ++){	老师是这么写的, 可以这么写, 但是需要最后不能直接无脑 return -1; 而是 return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
				        int t = -1;	
				        for(int j = 1; j <= n; j++){	因为题目的节点编号是1-n, 所以j从1开始 
				            错误: if(!st[j] || (t == -1 || dist[j] < dist[t])){
		            		正确: if(!st[j] && (t == -1 || dist[j] < dist[t])){
				                t = j;
				            }
				        }
				        st[t] = true;	
				        	只要st[t] == true, 代表 dist[t]就一定是点t到起点的最短距离, 点t之后再也不用被更新{不会有更短的距离了}, 为什么?
				        		为什么 st[t] == true, 就代表u的最近距离找到了
								为什么 heap弹出的节点t, 代表u的最近距离找到了
									因为 第一个从heap弹出的节点, 就是全局距离起点最近的
									我的疑惑, 有没可能这个节点t后来发现还有更近的路
										不可能, 因为如果有更近的路, 假设这个路径是 a->b->c->t
										那么 第一个从heap弹出的节点就应该是a, 而不是t
				        if(t == n) break;
				        for(int j = 1; j <= n; j++){	放松点t的所有临边, 因为是稠密图, 应该有很多临边, t的临边是矩阵的其中一行的所有元素: g[t][j]. 因为题目的节点编号是1-n, 所以j从1开始 
				            dist[j] = min(dist[j], dist[t] + g[t][j]);
				        }
				    }
				    if(dist[n] == 0x3f3f3f3f) return -1;
				    return dist[n];
				}
				int main(){
				    memset(g, 0x3f, sizeof g);
				    memset(dist, 0x3f, sizeof dist);
				    
				    cin >> n >> m;
				    for(int i = 0 ; i < m; i++){
				        int a, b, c;
				        scanf("%d%d%d", &a, &b, &c);
				        错误: 
				        	g[a][b] = min(g[a][b], c);
				        	g[b][a] = min(g[b][a], c); -> 不能加这一句, 因为是有向图
				        正确: g[a][b] = min(g[a][b], c);
				    }
				    cout << dijkstra() << endl;
				}
			2. 如果 for(int i = 0; i < n - 1; i ++) 搭配 return -1; 会出现错误
				以下是错误代码: 修改方法: i < n - 1; 变为 i < n;
					#include <iostream>
					#include <cstring>
					using namespace std;

					const int N = 510;
					int g[N][N], dist[N], n, m;
					bool st[N];

					int dijkstra(){
					    dist[1] = 0;
					    for(int i = 0; i < n - 1; i++){	  i < n - 1 搭配 return -1; 就错误了. 
					    							为什么, 因为可能存在一种情况, 在遍历第i == n-1次的时候, 放松点t的临边, 我们最后的dist[终点n]求出来了
					    								这时候的dist[终点n]是最短距离, 也就是 != 正无穷. 
					    								但是恐怖的是, 我们不会再遍历 i == n次, 而是直接跳出, 最后返回的是无脑的-1
					    								不信, 用例子: 并且uncomment掉我们的打印过程
					    									3 3
															1 2 2
															2 3 1
															1 3 4
					        int t = -1;
					        for(int j = 1; j <= n; j++){
					            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
					        }
					        st[t] = true;
					        // cout << t << " " << dist[t] << endl;
					        if(t == n) {
					            return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
					        }
					        for(int j = 1; j <= n; j ++){
					            dist[j] = min(dist[j], dist[t] + g[t][j]);
					        }
					        // cout << dist[3] << endl;
					    }
					    return -1; 
					}

					int main(){
					    memset(g, 0x3f, sizeof g);
					    memset(dist, 0x3f, sizeof dist);
					    cin >> n >> m;
					    while(m--){
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);
					        g[a][b] = min(g[a][b], c);
					    }
					    cout << dijkstra() << endl;
					    return 0;
					}
		2. ok
			#include <iostream>
			#include <cstring>
			using namespace std;

			const int N = 510;
			int g[N][N], dist[N];
			bool st[N];
			int n, m;

			int dij()
			{
			    dist[1] = 0;
			    for(int i = 0; i < n - 1; i++){
			        int t = -1;
			        for(int j = 1; j <= n; j++){
			            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;	如果j不是脱颖而出的人{!st[j]} 并且&&{也就是进一步判断} (t还没有主人{j就可以占有她} || t她有主人了但我比她主人更好) 
			        }
			        st[t] = true;	
			        	只要st[t] == true, 代表 dist[t]就一定是点t到起点的最短距离, 点t之后再也不用被更新{不会有更短的距离了}, 为什么?
			        		为什么 st[t] == true, 就代表u的最近距离找到了
							为什么 heap弹出的节点t, 代表u的最近距离找到了
								因为 第一个从heap弹出的节点, 就是全局距离起点最近的
								我的疑惑, 有没可能这个节点t后来发现还有更近的路
									不可能, 因为如果有更近的路, 假设这个路径是 a->b->c->t
									那么 第一个从heap弹出的节点就应该是a, 而不是t
			        if(t == n) break;
			        for(int j = 1; j <= n; j++){	放松点t的临边, 因为临边多, 所以是遍历邻接矩阵的整一行的所有元素 g[t][j]
			            dist[j] = min(dist[j], dist[t] + g[t][j]);	
			            思考tj不连通的情况:
			            	例如 0x3f3f3f3f = min(0x3f3f3f3f, 3 + 0x3f3f3f3f) == 0x3f3f3f3f
			        }
			    }
			    return dist[n] == 0x3f3f3f3f ? -1 : dist[n]; //因为只遍历了i==n-1次, 所以不能return -1;
			}
			int main(){
			    memset(g, 0x3f, sizeof g);
			    memset(dist, 0x3f, sizeof dist);
			    	看哪些东西要初始化
					为什么是 0x3f
						因为 dist[j] = min(dist[j], dist[t] + g[t][j])
							例如 0x3f3f3f3f = min(0x3f3f3f3f, 3 + 0x3f3f3f3f) == 0x3f3f3f3f
							dist[j]: 可能是0x3f
							dist[t]: 一般是正常值
							g[t][j]: 可能是0x3f
						我们怕g[t][j]和别的东西相加之后 溢出吧, 一般都不用 0xfffffff == -1
			    
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        scanf("%d%d%d", &a, &b, &c);
			        g[a][b] = min(g[a][b], c);
			    }
			    cout << dij() << endl;
			}
			--
			#include <iostream>
			#include <cstring>
			using namespace std;

			const int N = 510;
			int g[N][N], dist[N];
			bool st[N];
			int n, m;

			int dijkstra(){
			    dist[1] = 0;
			    for(int i = 0; i < n - 1; i++){			放松n-1次 
			        int t = -1;							找归宿
			        for(int j = 1; j <= n; j++){
			            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
			        }
			        st[t] = true;						回忆: 为何st[t] == true, dist[t]就一定是点t到起点的最短距离
			        if(t == n) break;
			        for(int j = 1; j <= n; j++){
			            dist[j] = min(dist[j], dist[t] + g[t][j]);	如果tj不联通, 就是 0x3f3f3f3f = min(0x3f3f3f3f, 3 + 0x3f3f3f3f) == 0x3f3f3f3f
			        }
			    }
			    return dist[n] == 0x3f3f3f3f ? - 1 : dist[n];
			}

			int main(){
			    memset(g, 0x3f, sizeof g);
			    memset(dist, 0x3f, sizeof dist);
			    
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        g[a][b] = min(g[a][b], c);
			    }
			    cout << dijkstra() << endl;
			    return 0;
			}
	46. AcWing 850. Dijkstra求最短路 II
		0. 小总结:
			优化版本:
				dist[j]也就是点j可能多次被放松, 每次放松, 就会放到queue里面. 
			    放到queue里面的是边{其实说是路径更好}, 因为dist[j]代表 i->j的最短路径的距离
			    	每次放松就会插入queue中
			    	也就是每次放松就是 logv 的操作
			    	最多放松多少次?
			    		也就是每条边都放松一次, 也就是一共放松e次, 稠密图中: e == v^2, 所以不适合稠密图

			    所以dist[j]一直被放松, 什么时候不被别人放松, 就是dist[j]是整个dist数组里面, 所有st[xx]==false的节点xx中, 最小的时候
		1. bug
			#include <iostream>
			#include <cstring>
			#include <queue>
			using namespace std;

			const int N = 2e5;
			int h[N], e[N], ne[N], w[N], ind;
			int dist[N];
			bool st[N]; st[]的目的是记录是否是神仙
			int n, m;

			typedef pair<int, int> PII;
			错误: priority_queue<PII> q;
			正确: priority_queue<PII, vector<PII>, greater<PII>> q;

			void add(int a, int b, int c){
			    e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind++;
			}


			int dijkstra(){
			    dist[1] = 0;
			    q.push({0, 1});
			    
			    while(q.size()){
			        auto t = q.top();
			        q.pop();
			        
			        int ver = t.second, dis = t.first;
			        if(st[ver]) continue;
			        	解释: if(st[j]) continue;	
					    	因为queue中存在:
					    		某个节点j之前被加入过
					    		在j被pop之前, 因为dist[j]被再次放松, 所以又再次被加入到了queue中 
					    	错误的想法, 认为还有另外一种写法:
					    		错误:
						    		pop()之后, 设置为false
						    		并判断:
						    			if(!st[u]) q.push({dist[u], u});
						    	错误原因:
						    		认为st[]的目的是提高效率, 其实st[]的目的是记录是否是神仙
										提高效率: st[]可以从true变成false
										是否是神仙: 一旦是true, 就不可能是false

			        st[ver] = true;
			        
			        for(int i = h[ver]; ~i; i = ne[i]){
			            int u = e[i];
			            错误: if(dist[u] + dis < dist[v]){
			            正确: if(dist[ver] + w[i] < dist[u]){
			            	错误: dist[u] = dist[ver] + dis;
			                正确: dist[u] = dist[ver] + w[i];
			                q.push({dist[u], u});
			            }
			        }
			    }
			    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
			}


			int main(){
			    memset(dist, 0x3f, sizeof dist);
			    memset(h, -1, sizeof h);
			    
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        scanf("%d%d%d", &a, &b, &c);
			        add(a, b, c);
			    }
			    cout << dijkstra() << endl;
			    return 0;
			}
			一个致命的bug, 认为st[]的目的是提高效率, 其实st[]的目的是记录是否是神仙
				提高效率: st[]可以从true变成false
					spfa中的st[]为什么能提高效率, 因为 spfa其实是bfs算法, 并且这里的层序遍历可能遇到环
					也就是一个点, 可能会被插入queue两次, 但是没有必要插入两次, 我们插入一次就好, 因为先前插入的点可以用到未来信息{后点会放松我们的边,dist[j]变小}
				是否是神仙: 一旦是true, 就不可能是false

				bug:
					#include <iostream>
					#include <queue>
					#include <cstring>
					using namespace std;

					typedef pair<int, int> PII;
					const int N = 1e5 + 10;
					int h[N], e[N], w[N], ne[N], ind;
					priority_queue<PII, vector<PII>, greater<PII>> q;
					int dist[N];
					bool st[N];
					int n, m;

					void add(int a, int b, int c){
					    e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind ++;
					}

					int dijkstra(){
					    dist[1] = 0;
					    q.push({0, 1});
					    错误: st[1] = true; 
					    
					    while(q.size()){
					        PII t = q.top(); q.pop();
					        int v = t.second, dis = t.first;
					        错误: st[v] = false;
					        
					        for(int i = h[v]; ~i; i = ne[i]){
					            int u = e[i];
					            if(dist[v] + dis < dist[u]){
					                dist[u] = dist[v] + dis;
					                if(!st[u]) {
					                    q.push({dist[u], u});
					                    错误: st[u] = true;
					                }
					            }
					        }
					    }
					    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
					}

					int main(){
					    memset(dist, 0x3f, sizeof dist);
					    memset(h, -1, sizeof h);
					    cin >> n >> m;
					    while(m--){
					        int a, b, c;
					        add(a, b, c);
					    }
					    cout << dijkstra() << endl;
					    return 0;
					}

		2. ok
			#include <iostream>
			#include <cstring>
			#include <queue>
			using namespace std;

			const int N = 2e5;
			int h[N], e[N], ne[N], w[N], ind;
			int dist[N];
			typedef pair<int, int> PII;
			priority_queue<PII, vector<PII>, greater<PII>> q;
			bool st[N]; st[]的目的是记录是否是神仙
			int n, m;

			void add(int a, int b, int c){
			    e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind++;
			}

			int dijkstra(){
			    dist[1] = 0;
			    q.push({0, 1}); //第一个关键词排序, 所以第一个关键词是距离0, 第二个关键词是节点1
			    
			    while(q.size()){ //存所有放松过的边, 也就是知道这个被放松过的节点t, 和它的dist[t]
			        auto t = q.top();
			        q.pop();
			        
			        int ver = t.second; 其实 int dis = t.first 没有用到, 只是插入heap的时候排序用到
			        // 保守写法: if(st[ver]) continue; 
			        	//ver已经成仙了, 因为ver如果被放松多次, 会被多次push进入heap, 一旦修仙成功, 后面的放入都是过期无效的
			        	//相当于, 一个ver有很多个克隆体{影子}, 只要有一个克隆体成仙了, 所有的克隆体就都功德圆满
			        st[ver] = true; // 相当于非优化版的找灵魂, 最后的t就是神仙
			        
			        for(int i = h[ver]; ~i; i = ne[i]){
			            int u = e[i];
			            if(dist[ver] + w[i] < dist[u]){
			                dist[u] = dist[ver] + w[i];
			                if(!st[u]) q.push({dist[u], u}); 
			                	// st[u] == true, 已经成仙, 不需要插入heap中, 来判断是否是最短的边
			                	// 如果还是凡人, 就加入, 也就是将这个 放松过的边就加入, 这个边是 ver -> u;
			            }
			        }
			    }
			    
			    return dist[n] == 0x3f3f3f3f ? -1 : dist[n];
			}

			int main(){
			    memset(dist, 0x3f, sizeof dist);
			    memset(h, -1, sizeof h);
			    
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        add(a, b, c);
			    }
			    cout << dijkstra() << endl;
			}
	47. AcWing 853. 有边数限制的最短路{bellman ford}
		0. 注意, 这道题, 有负环, 但是依旧可以用 bellman()做
		1. bug{竟然把需要注意的地方写错了...下次不许了}
			1.
				#include <iostream>
				#include <cstring>
				using namespace std;

				const int N = 510, M = 1e4 + 10;
				struct Edge{
				    int a, b, c;
				}edges[M];

				int dist[N], last[N];
				int n, m, k;

				void bellman(){
				    dist[1] = 0;
				    for(int i = 0; i < k; i++){
				        错误: memset(last, dist, sizeof dist); // invalid conversion from 'int*' to 'int'
				        正确: memcpy(last, dist, sizeof dist);
				        for(int j = 0 ; j < m ; j++){
				            auto e = edges[j];
				            int u = e.a, v = e.b, w = e.c;	注意起点终点不要弄混, u -> v
				            错误: dist[v] = min(dist[v], dist[u] + w);
				            正确: dist[v] = min(dist[v], last[u] + w);
				        }
				    }
				    错误: if(dist[n] == 0x3f3f3f3f) puts("impossible");
				    正确: if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
				    else cout << dist[n] << endl;
				}

				int main(){
				    memset(dist, 0x3f, sizeof dist);
				    cin >> n >> m >> k;
				    for(int i = 0; i < m; i++){
				        int a, b, c;
				        cin >> a >> b >> c;
				        edges[i] = {a,b,c};
				    }
				    bellman();
				    return 0;
				}
			2. 一个非常容易错的地方, 要理解清楚
				#include <iostream>
				#include <cstring>
				using namespace std;

				const int N = 510, M = 1e4 + 10;
				struct Edge{
				    int a, b, c;
				}edges[M];

				int dist[N], last[N];
				int n, m, k;

				void bellman(){
				    dist[1] = 0;
				    for(int i = 0 ; i < k ; i++){
				        memcpy(last, dist, sizeof dist);
				        for(int j = 0; j < m; j++){
				            auto e = edges[j];
				            int u = e.a, v = e.b, w = e.c;
				            错误: if(dist[u] + w < last[v]) dist[v] = dist[u] + w; 	都是些乱七八糟的
				            错误: if(last[u] + w < last[v]) dist[v] = dist[u] + w;	都是些乱七八糟的
				            正确: if(last[u] + w < dist[v]) dist[v] = last[u] + w;
				            	想象画面:
				            		上层地图{版本优}	dist[起点u] -'走法c: 不行'-> dist[终点v]
				            							↑					↑    
				            							|             	   / '走法b: ok'
				            							| '走法a: ok'      /
				            		底层地图{版本低} 	last[起点u] ----------

				            	我的错误: 我都是什么混乱逻辑啊
				            	思考故事:
					            	平行时空: 
					            		走法a和b, 是两种世界, 你只能走一种
					            		因为题目限定了步数, 从版本低到版本高, 代表走一步, 要么是走方式a, 要么是走方式b
					            	什么是占便宜
					            		你走走法b, 就是走了1步
					            		你如果走走法c, 实际上是走了2步
					            			因为从last[u]到dist[v]是经过了2步: a+c
					            			题目要你走1步, 你走了2步, 就是欺诈!
					            正确: if(last[u] + w < "dist[v]") dist[v] = last[u] + w;
					            	解释为什么是 "dist[v]", 而不是 last[v]
					            	我之前的疑惑是: 
					            		假设还没走, 我们备份的last[v] 不就等于 待更新的dist[v]吗, 所以用last[v]也没错吧
					            	答案:
					            		可能dist[v]已经被其他的节点xx更新过了, 所以 dist[v] != last[v]
					            		如果真的发生了 dist[v]已经被其他的1个节点xx更新过了, 我之前的疑惑是:
					            			这个被节点xx更新过的点v, 是不是也算是走了1步了, 然后u更新v就算是走了第二步了
					            		答案:
					            			其实不是的, 当last[xx]更新v, dist[v]减小
					            			当last[u]更新v, 如果dist[v]进一步减小, 说明这一步应该是从 u->v, 而不是从 xx->v
					            			我们只是保留min, 所以谁最优, 这一步就是从谁走, 不存在说多走了一步的说法
					            所以思考的故事是:
					            	for(k步)
					            		for(m条边)
					            			地图怎么更新? 思考下面的图像
							            	对比:
								            	之前的dijk什么都是一维平面的辐射
												现在last是二维的, 也就是一层一层的平面
													last是低层平面, dist是高层平面, dist通过last更新
													走k步就是k层平面

					            					
				        }
				    }
				    if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
				    else cout << dist[n] << endl;
				}

				int main(){
				    memset(dist, 0x3f, sizeof dist);
				    
				    cin >> n >> m >> k;
				    for(int i = 0; i < m; i++){
				        int a, b, c;
				        cin >> a >> b >> c;
				        edges[i] = {a, b, c};
				    }
				    bellman();
				    return 0;
				}
		2. ok
			#include <iostream>
			#include <cstring>
			using namespace std;

			const int N = 510, M = 1e5 + 10;
			struct Edge{
			    int a, b, c;
			}edge[M];
			int dist[N], last[N];
			int n, m, k;

			void bellman(){
			    dist[1] = 0;
			    for(int i = 0; i < k; i++){
			        memcpy(last, dist, sizeof dist);		 //目标, 源, 源长
			        for(int j = 0; j < m; j++){
			            Edge e = edge[j];
			            int u = e.a, v = e.b, w = e.c;
			            dist[v] = min(dist[v], last[u] + w);   //高层终点v, 可以由低层的起点u来更新. 哪个底层的起点能给我v更优秀的dist[v], 我就从哪个底层起点过来.
			        }
			    }
			    if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
			    else cout << dist[n] << endl;
			}

			int main(){
			    memset(dist, 0x3f, sizeof dist);
			    cin >> n >> m >> k;
			    for(int i = 0; i < m; i++){
			        int a, b, c;
			        cin >> a >> b >> c;
			        edge[i] = {a, b, c};
			    }
			    bellman();
			    return 0;
			}
			--
			#include <iostream>
			#include <cstring>
			using namespace std;

			const int N = 510, M = 1e5 + 10;
			int dist[N], last[N];
			int n, m, k;
			struct Edge{
			    int a, b, w;
			}edges[M];

			void bellman(){
			    dist[1] = 0;
			    for(int i = 0; i < k; i++){
			        memcpy(last, dist, sizeof dist);
			        for(int j = 0; j < m; j++){
			            auto e = edges[j];
			            int u = e.a, v = e.b, w = e.w;
			            dist[v] = min(dist[v], last[u] + w); 
			        }
			    }
			    if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
			    else cout << dist[n] << endl;
			}

			int main(){
			    memset(dist, 0x3f, sizeof dist);
			    cin >> n >> m >> k;
			    for(int i = 0; i < m; i++){
			        int a, b, c;
			        cin >> a >> b >> c;
			        edges[i] = {a, b, c};
			    }
			    bellman();
			    return 0;
			}
	48. AcWing 851. spfa求最短路
		0. 小总结:
			dijkstra:
				priority_queue插入{dist[u], u}, 最小堆排序
				st[]记录是否成仙
			spfa:
				queue用于bfs层序遍历
				st[]提高效率, 让前面的点用到后来的点的未来信息
		1. bug
			st[]的目的:
				spfa: 提高效率: st[]可以从true变成false
					spfa中的st[]为什么能提高效率, 因为 spfa其实是bfs算法, 这里的层序遍历可能遇到环
						也就是一个点, 可能会被插入queue两次
					但是没有必要插入两次, 我们插入一次就好, 因为先前插入的点可以用到未来信息{后点会放松我们的边,dist[j]变小}
				优化dijkstra: 是否是神仙: 一旦是true, 就不可能是false
			#include <iostream>
			#include <cstring>
			#include <queue>
			using namespace std;
			错误: const int N = 1e5;	因为样例真的来个 n == m == 1e5的
			正确: const int N = 1e5 + 10; 
			int h[N], e[N], ne[N], w[N], ind;	因为边数 == 点数, 所以用邻接表
			int dist[N];
			queue<int> q;
			int n, m;
			bool st[N];

			void add(int a, int b, int c){
			    e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind++;
			}

			void spfa(){
			    dist[1] = 0;
			    q.push(1);
			    st[1] = true;
			    
			    while(q.size()){
			        错误: int t = q.top(); priority_queue是top(), queue是front()
			        正确: int t = q.front();
			        q.pop();
			        st[t] = false;	小心别忘了
			        
			        for(int i = h[t]; ~i; i = ne[i]){
			            int u = e[i], dis = w[i];
			            if(dist[t] + dis < dist[u]){
			                dist[u] = dist[t] + dis;
			                if(!st[u]) {
			                    q.push(u);
			                    st[u] = true;	小心别忘了
			                }
			            }
			        }
			    }
			    
			    保守写法: if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
			    if(dist[n] == 0x3f3f3f3f) puts("impossible");
			    else cout << dist[n] << endl;
			}

			int main(){
			    memset(h, -1, sizeof h);
			    memset(dist, 0x3f, sizeof dist);
			    
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        add(a, b, c);
			    }
			    spfa();
			    return 0;
			}
			--
			#include <iostream>
			#include <queue>
			#include <cstring>

			using namespace std;
			const int N = 1e5 + 10;
			int h[N], e[N], w[N], ne[N], ind;
			queue<int> q;
			int dist[N];
			bool st[N];
			int n, m;

			void add(int a, int b, int c){
			    e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind++;
			}

			void spfa(){
			    dist[1] = 0;
			    q.push(1);
			    st[1] = true;
			    
			    while(q.size()){
			        int t = q.front(); q.pop();
			        st[t] = false;
			        for(int i = h[t]; ~i; i = ne[i]){
			            int u = e[i];
			            if(dist[t] + w[i] < dist[u]){
			                dist[u] = dist[t] + w[i];
			                if(!st[u]){
			                    q.push(u);
			                    st[u] = true;
			                }
			            }
			        }
			    }
			    if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
			    else cout << dist[n] << endl;
			}

			int main(){
			    memset(dist, 0x3f, sizeof dist);
			    memset(h, -1, sizeof h);
			    
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        add(a, b, c);
			    }
			    spfa();
			    return 0;
			}
		2. ok
			注意, 题目说了没有负权回路, 所以才可以不用设置cnt卡圈数, 来求最短路
			#include <iostream>
			#include <cstring>
			#include <queue>
			using namespace std;

			const int N = 1e5 + 10;
			int h[N], e[N], ne[N], w[N], ind;
			queue<int> q; //记录dist[j]变小的节点j. 也就是从起点开始层序遍历, 辐射全部点
			bool st[N]; //提高效率, 一个节点j没必要进入两次queue
			int dist[N];
			int n, m;

			void add(int a, int b, int c){
			    e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind++;
			}

			void spfa(){
			    dist[1] = 0;
			    q.push(1);
			    st[1] = true;
			    
			    while(q.size()){
			        int t = q.front(); q.pop();
			        st[t] = false;
			        
			        for(int i = h[t]; ~i; i = ne[i]){
			            int j = e[i], dis = w[i];
			            if(dist[t] + dis < dist[j]){
			                dist[j] = dist[t] + dis;
			                if(!st[j]){
			                	//如果j不在queue里面,就放入. 如果这个点j本身就在queue,那以后会在queue中取出它的
			                			//对比, 之前优化版 dijkstra()的克隆体故事, 其实也可以这么写, 也就是 st[u] == false 的时候 push进去
			                			//即, 没有成仙的u, 我们加入heap中, 然后让最小堆排序

			                	//spfa中, 如果节点j被push两次, 说明层序遍历中遇到了环
			                	//之前push进去的节点j是浅层的点, 现在push进去的节点j是深层的点. 既然遍历到了2次, 说明有环
			                	//但是这个环不是负权环, 因为题目说了没有负权环.
			                	//为什么我们要遍历浅层时候的j, 而不是深层时候的j
			                		//我个人认为, 这就有种用到未来信息的感觉
			                		//因为遍历深层的j的时候, dist[j]更小了
			                		//当queue中pop出来浅层j的时候, 这个j是用这个更小的dist[j]来放松它的邻点. 这就是用了未来信息
			                	//你就背下吧: 用到了未来信息
			                    q.push(j);
			                    st[j] = true;
			                }
			            }
			        }
			    }
			    //因为没有负权环, 所以是可以最后出来的, 也就是 dfs()层序遍历了所有点, 从起点辐射到了所有的点. 并更新了所有点的dist

			    if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
			    else cout << dist[n] << endl;
			}


			int main(){
			    memset(dist, 0x3f, sizeof dist);
			    memset(h, -1, sizeof h);
			    
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        add(a, b, c);
			    }
			    spfa();
			    return 0;
			}
			--
			#include <iostream>
			#include <queue>
			#include <cstring>
			using namespace std;

			const int N = 1e5 + 10;
			int h[N], e[N], ne[N], w[N], ind;
			int dist[N];
			queue<int> q;
			bool st[N]; //方便使用, 未来信息
			int n, m;

			void add(int a, int b, int c){
			    e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind++; // 回忆++ind的是trie, 因为ind==0是根节点, 第一个son是从ind==1开始
			}

			void spfa(){
			    dist[1] = 0;
			    q.push(1);
			    st[1] = true; //回忆 普通dijkstra()是在 for(int i = 0 ; i < n - 1; i++) 里面才设置 st[1] = true, 因为第一个灵魂t找到的就是节点1, 所以不需要在for外面写 st[1] = true
			    
			    while(q.size()){
			        int t = q.front(); q.pop();
			        st[t] = false;
			        
			        for(int i = h[t]; ~i; i = ne[i]){
			            int u = e[i], dis = w[i];
			            if(dist[t] + dis < dist[u]){
			                dist[u] = dist[t] + dis; //这里只是让dist[u]更小, 如果u已经在queue中, 那个在queue中的浅层u就可以用到这个未来信息 dist[u]
			                if(!st[u]){
			                    q.push(u);
			                    st[u] = true;
			                }
			            }
			        }
			    }
			    //如果存在负权环, 总会有一个点z, dist[z]会不停地变小, 所以会queue中始终会有这个节点z: 有就不插入z, 没有就插入z, 反正保证一定有z
			    //所以如果有负权环, while()永远出不来
			    if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
			    else cout << dist[n] << endl;
			    
			}

			int main(){
			    memset(h, -1, sizeof h);
			    memset(dist, 0x3f, sizeof dist);
			    
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        add(a, b, c);
			    }
			    spfa();
			    return 0;
			}
			--
			#include <iostream>
			#include <queue>
			#include <cstring>
			using namespace std;
			const int N = 1e5 + 10;
			int h[N], e[N], w[N], ne[N], ind;
			queue<int> q;
			int dist[N];
			bool st[N];
			int n, m;

			void add(int a, int b, int c){
			    e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind++;
			}

			void spfa(){
			    dist[1] = 0;
			    q.push(1);
			    st[1] = true;
			    
			    while(q.size()){
			        int t = q.front(); q.pop();
			        st[t] = false;
			        
			        for(int i = h[t]; ~i; i = ne[i]){
			            int u = e[i];
			            if(dist[t] + w[i] < dist[u]){
			                dist[u] = dist[t] + w[i];
			                if(!st[u]) q.push(u);
			            }
			        }
			    }
			    if(dist[n] > 0x3f3f3f3f / 2) puts("impossible");
			    else cout << dist[n] << endl;
			}

			int main(){
			    memset(dist, 0x3f, sizeof dist);
			    memset(h, -1, sizeof h);
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        add(a, b, c);
			    }
			    spfa();
			    return 0;
			}
4. 5.16 
	49. AcWing 852. spfa判断负环
		1. bug
			#include <iostream>
			#include <queue>
			#include <cstring>
			using namespace std;

			const int N = 2010, M = 1e4 + 10;
			错误: int h[N], e[N], ne[M], w[M], ind;
			正确: int h[N], e[M], ne[M], w[M], ind;
			queue<int> q;
			bool st[N];
			int n, m;
			int dist[N], cnt[N];

			void add(int a, int b, int c){
			    e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind++;
			}

			bool spfa(){
				错误: for(int i = 0; i < n; i++){
			    正确: for(int i = 1; i <= n; i++){
			        q.push(i);
			        st[i] = true;
			    }
			    
			    while(q.size()){
			        int t = q.front();
			        q.pop();
			        st[t] = false;

			        for(int i = h[t]; ~i; i = ne[i]){
			            int j = e[i];
			            if(dist[t] + w[i] < dist[j]){
			                dist[j] = dist[t] + w[i];
			                // cout << j << " " << dist[j] << endl;
			                cnt[j] = cnt[t] + 1;
			                if(cnt[j] >= n) return true;
			                if(!st[j]){
			                    q.push(j);
			                    st[j] = true;
			                }
			            }
			        }
			    }
			    return false;
			}

			int main(){
			    memset(h, -1, sizeof h);
			    memset(dist, 0x3f, sizeof dist); //初始化为0x3f, 或者0都可以
			    cin >> n >> m;
			    错误: for(int i = 0; i < n; i++){
			    正确: while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        add(a, b, c);
			    }
			    if(spfa()) puts("Yes");
			    else puts("No");
			    return 0;
			}
		2. ok
			初始化:
				memset(dist, 0x3f, sizeof dist);
				for(int i = 1; i <= n; i++){	注意编号从1开始 
			        dist[i] = 0;	每个点到虚拟源点的距离都是0, 其实老师没有加这一句也是accept
			        q.push(i);
			        st[i] = true;
			    }
			精华:
				1. 如果 边数 == 点数, 说明有环 {正常的是 边数 == 点数 - 1, 例如1条边连接2个点}
				2. 因为只有距离减小才会更新, 才会多一条边, 所以形成的环一定是距离不断减小的, 说明是负权环
				3. cnt{和虚拟源点连接的最短路径的边数}两种方式:
					初始化都是1, 然后判断 cnt[u] >= n + 1
						因为初始化是1, 代表我们是真的有 n + 1 个点, 边数 == 点数, 说明有环, 是负权环
					习惯用这个, 因为方便: 初始化都是0, 然后判断 cnt[u] >= n
						其实就是等价于上面, 只不过大家都从0开始
			#include <iostream>
			#include <queue> 
			#include <cstring>
			using namespace std;
			const int N = 2010, M = 1e4 + 10;
			int h[N], e[M], w[M], ne[M], ind;
			int dist[N], cnt[N], n, m;
			queue<int> q;
			bool st[N];

			void add(int a, int b, int c){
			    e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind++;
			}

			bool spfa(){
			    // dist[1] = 0;
			    // q.push(1);
			    // st[1] = true;
			    
			    for(int i = 1; i <= n; i++){	注意编号从1开始 
			        dist[i] = 0;	每个点到虚拟源点的距离都是0, 其实老师没有加这一句也是accept
			        q.push(i);
			        st[i] = true;
			    }
			    while(q.size()){
			        int t = q.front(); q.pop();
			        st[t] = false;
			        
			        for(int i = h[t]; ~i; i = ne[i]){
			            int u = e[i];
			            if(dist[t] + w[i] < dist[u]){	如果可以放松临边
			                dist[u] = dist[t] + w[i];	放松吧
			                cnt[u] = cnt[t] + 1;		记得记录路径长度{边数}
			                if(cnt[u] >= n) return true;	边数 == 点数 == n, 说明有环
			                if(!st[u]){
			                    q.push(u);
			                    st[u] = true;
			                }
			            }
			        }
			    }
			    return false;
			}

			int main(){
			    memset(dist, 0x3f, sizeof dist);
			    memset(h, -1, sizeof h);
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        add(a, b, c);
			    }
			    if(spfa()) puts("Yes");
			    else puts("No");
			    return 0;
			}
			--
			#include <iostream>
			#include <queue>
			#include <cstring>
			using namespace std;
			const int N = 2010, M = 1e4 + 10;
			int h[N], e[M], w[M], ne[M], ind;
			int dist[N], cnt[N];
			queue<int> q;
			bool st[N];
			int n, m;

			void add(int a, int b, int c){
			    e[ind] = b, w[ind] = c, ne[ind] = h[a], h[a] = ind++;
			}

			bool spfa(){
			    for(int i = 1; i <= n; i++){
			        dist[i] = 0;
			        q.push(i);
			        st[i] = true;
			    }
			    while(q.size()){
			        int t = q.front(); q.pop();
			        st[t] = false;
			        for(int i = h[t]; ~i; i = ne[i]){
			            int u = e[i];
			            if(dist[t] + w[i] < dist[u]){
			                dist[u] = dist[t] + w[i];
			                cnt[u] = cnt[t] + 1;
			                if(cnt[u] >= n) return true;
			                if(!st[u]){
			                    q.push(u);
			                    st[u] = true;
			                }
			            }
			        }
			    }
			    return false;
			}

			int main(){
			    memset(h, -1, sizeof h);
			    memset(dist, 0x3f, sizeof dist);
			    
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        add(a, b, c);
			    }
			    if(spfa()) puts("Yes");
			    else puts("No");
			    return 0;
			}
	50. AcWing 854. Floyd求最短路
		1. bug
			注意只有 d[N][N], 没有多的f[N][N]
			图中是有负权边, 所以能够解决负权边问题:
				bellman()
				spfa()
				floyed()
		2. ok
			初始化:
				因为是多源, 所以我们某个点到自己的距离初始就是0
				memset(d, 0x3f, sizeof d);	
			    for(int i = 1; i <= n; i++) d[i][i] = 0;	

			#include <iostream>
			#include <cstring>
			using namespace std;

			const int N = 210;
			int d[N][N];
			int n, m, q;

			void floyed(){
			    for(int k = 1; k <= n; k++)
			        for(int i = 1; i <= n; i++)
			            for(int j = 1; j <= n; j++)
			                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			            //d[k][i][j] = min(d[k-1][i][j], d[k-1][i][k] + d[k-1][k][j]);
			}

			int main(){
			    cin >> n >> m >> q;
			    memset(d, 0x3f, sizeof d);	
			    for(int i = 1; i <= n; i++) d[i][i] = 0;		
			            
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        d[a][b] = min(d[a][b], c);
			    }
			    
			    floyed();
			    while(q--){
			        int a, b;
			        cin >> a >> b;
			        if(d[a][b] > 0x3f3f3f3f / 2) puts("impossible");
			        else cout << d[a][b] << endl;
			    }
			    return 0;
			}
			--
			#include <iostream>
			#include <cstring>
			using namespace std;

			const int N = 210;
			int d[N][N];
			int n, m, Q;

			void floyed(){
			    for(int k = 1; k <= n; k++)
			        for(int i = 1; i <= n; i++)
			            for(int j = 1; j <= n; j++)
			                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			                //d[k][i][j] = min(d[k-1][i][j], d[k-1][i][k] + d[k-1][k][j]);
			}

			int main(){
			    memset(d, 0x3f, sizeof d);
			    cin >> n >> m >> Q;
			    for(int i = 1; i <= n; i++) d[i][i] = 0;
			    
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        d[a][b] = min(d[a][b], c);
			    }
			    
			    floyed();
			    while(Q--){
			        int a, b;
			        cin >> a >> b;
			        if(d[a][b] > 0x3f3f3f3f / 2) puts("impossible");
			        else cout << d[a][b] << endl;
			    }
			    return 0;
			}
	* 51. AcWing 858. Prim算法求最小生成树
		0. 小总结:
			1. 求MST:
				稠密图: prim {记忆: 稠 -> c -> pc}
				稀疏图: 堆优化prim{少用}, kruskal{常用, 用edges[M]}
			2. prim的算法:
				注意, 因为是每个点都要在树中, 不同于之前的求路径并不是所有点都在路径中
				所以我们这里就随意假设一个点一开始就在神仙集合中
					st[1] = true;
				prim算法:
					连接两个集合{神仙集合/凡人集合}的边中, 而不是集合内部的边, 连接两个集合{神仙集合/凡人集合}的边中选择最短的边
						for(int i = 1; i <= n; i++)
				        	dist[i] = min(dist[i], d[1][i]);
				    最短的边, 所对应的邻点, 就是我们下一个神仙:
				    	int t = -1;
				        for(int j = 2; j <= n; j++)
				            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
				       	st[t] = true;
				    不过, 我们要判断, 最短的边, 是不是0x3f, 只要有一个点{包括点1}是0x3f的话, 说明图根本不连通, 不存在MST
				    	if(dist[t] > 0x3f3f3f3f / 2) return false;
			        否则的话, 这个最短的边, 就是MST的一条边, 把边长加入到res中
			        	res += dist[t];
					dist[j]的意思是: 点j, 距离神仙集合的最短距离, 这个最短距离的确定, 需要一个通往神仙集合的后门, 也就是点t 
						for(int j = 1; j <= n; j++)
			            	dist[j] = min(dist[j], d[t][j]);
			3. 相似性:
				1.
					堆优化dijkstra: priority_queue
					spfa: queue
				2.
				 	朴素版dijkstra: 
						int t = -1;
				        for(int j = 2; j <= n; j++){
				            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
				        }
				    prim也是:
			    		int t = -1;
				        for(int j = 2; j <= n; j++){
				            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
				        }
			1. bug
			错误: 我以为是稀疏图
			正确: 这个还是属于稠密图
				1≤n≤500, n^2 = 2.5e5
				1≤m≤1e5

			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 510;

			int d[N][N], dist[N];
			bool st[N];
			int n, m, res;

			bool prim(){
				st[1] = true;
			    for(int i = 1; i <= n; i++){
			        dist[i] = min(dist[i], d[1][i]);
			    }
			    for(int i = 0; i < n - 1; i++){
			        int t = -1;
			        for(int j = 2; j <= n; j++){
			            错误: if(!st[j] && (t == 1 || dist[j] < dist[t])) t = j;	害我找半天!!
			            正确: if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
			        }
			        if(dist[t] > 0x3f3f3f3f / 2) return false;	最近的点都是不连通的, 说明这个图不连通, 不存在MST
			        res += dist[t];
			        st[t] = true;	成为神仙
			        
			        for(int j = 2; j <= n; j++) dist[j] = min(dist[j], d[t][j]); //或者d[j][t]都可以因为是无向图
			    }
			    return true;
			}

			int main(){
			    memset(dist, 0x3f, sizeof dist);记得都要初始化
			    memset(d, 0x3f, sizeof d);		记得都要初始化
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        d[a][b] = d[b][a] = min(d[a][b], c);	注意: 无向图
			    }
			    
			    if(prim())  cout << res << endl;
			    else puts("impossible");
			    return 0;
			}
		2. ok
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 510, M = 1e5 + 10;
			int d[N][N], dist[N];
			bool st[N];
			int n, m, res;

			bool prim(){
			    st[1] = true;
			    for(int i = 1; i <= n; i++){
			        dist[i] = min(dist[i], d[1][i]);
			    }
			    for(int i = 0; i < n - 1; i++){
			        int t = -1;
			        for(int j = 2; j <= n; j++){
			            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
			        }
			        if(dist[t] > 0x3f3f3f3f / 2) return false;
			        res += dist[t];
			        
			        st[t] = true;
			        
			        for(int j = 1; j <= n; j++){
			            dist[j] = min(dist[j], d[t][j]);
			        }
			    }
			    return true;
			}

			int main(){
			    memset(d, 0x3f, sizeof d);
			    memset(dist, 0x3f, sizeof dist);
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        d[a][b] = d[b][a] = min(d[a][b], c);
			    }
			    if(prim()) cout << res << endl;
			    else puts("impossible");
			}
			--
			#include <iostream>
			#include <cstring>
			using namespace std;

			const int N = 510, M = 1e5 + 10;
			int d[N][N], dist[N];
			bool st[N];
			int n, m, res;

			bool prim(){
			    st[1] = true;
			    错误: 为啥想着稀疏图??
				    // for(int i = h[1]; ~i; i = ne[i]){
				    //     int u = e[i];
				    //     dist[u] = min(dist[u], d[1][u]);
				    // }
			    
			    for(int i = 1; i <= n; i++){
			        dist[i] = min(dist[i], d[1][i]);
			        因为点1是神仙, 所有点i中, 被放松的邻点和点1的边, 就是我们两个集合之间的边
			    }
			    
			    for(int i = 0; i < n - 1; i++){	因为之前点1已经被处理了, 现在只剩下n-1个点, 所以遍历n-1次
			        int t = -1;
			        for(int j = 2; j <= n; j++){
			            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j; 我们找到 {两个集合之间的边} 里面, 边长最短的
			        }
			        if(dist[t] > 0x3f3f3f3f / 2) return false;
			        res += dist[t];
			        st[t] = true;
			        for(int j = 1; j <= n; j ++) dist[j] = min(dist[j], d[t][j]);
			    }
			    return true;
			}

			int main(){
			    memset(d, 0x3f, sizeof d);
			    memset(dist, 0x3f, sizeof dist);
			    
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        d[a][b] = d[b][a] = min(d[a][b], c);
			    }
			    if(prim()) cout << res << endl;
			    else puts("impossible");
			    return 0;
			}
			--
			#include <iostream>
			#include <cstring>
			using namespace std;

			const int N = 510;
			int d[N][N], dist[N];
			bool st[N];
			int res, n, m;

			bool prim(){
			    st[1] = true;
			    for(int i = 1; i <= n; i++) dist[i] = min(dist[i], d[1][i]);
			    for(int i = 0; i < n - 1; i++){
			        int t = -1;
			        for(int j = 2; j <= n; j++) if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
			        if(dist[t] > 0x3f3f3f3f / 2) return false;
			        st[t] = true;
			        res += dist[t];
			        for(int j = 2; j <= n; j++) dist[j] = min(dist[j], d[t][j]);
			    }
			    return true;
			}

			int main(){
			    memset(d, 0x3f, sizeof d);
			    memset(dist, 0x3f, sizeof dist);
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        d[a][b] = d[b][a] = min(d[a][b], c);
			    }
			    if(prim()) cout << res << endl;
			    else puts("impossible");
			    return 0;
			}
			--
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 510;

			int d[N][N], dist[N];
			int res, n, m;
			bool st[N];

			bool prim(){
			    st[1] = true;
			    for(int i = 2; i <= n; i++) dist[i] = min(dist[i], d[1][i]);
			    for(int i = 0; i < n - 1; i ++){
			        int t = -1;
			        for(int j = 2; j <= n; j++){
			            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
			        }
			        if(dist[t] > 0x3f3f3f3f / 2) return false;
			        res += dist[t];
			        st[t] = true;
			        for(int j = 2; j <= n; j++) dist[j] = min(dist[j], d[t][j]);
			    }
			    return true;
			}

			int main(){
			    memset(d, 0x3f, sizeof d);
			    memset(dist, 0x3f, sizeof dist);
			    cin >> n >> m;
			    while(m--){
			        int a, b, c;
			        cin >> a >> b >> c;
			        d[a][b] = d[b][a] = min(d[a][b], c);
			    }
			    if(prim()) cout << res << endl;
			    else puts("impossible");
			    return 0;
			}
	52. AcWing 859. Kruskal算法求最小生成树
		0. 小总结:
			主要就是:
				1. edges[M], operator<(const Edge &e) const, sort()
				2. p[N], find(int x);
				3. cnt 记录边数, 来判断是否整个图是联通的
				4. res MST的边长之和
		1. bug
			注意, 如何判断是否连通, 需要通过 cnt{我们的MST里面有多少条边}
			应该有n-1条边, 连接n个点, 所以 if(cnt != n - 1) return false; 不是联通图
		2. ok
			#include <iostream>
			#include <algorithm>
			using namespace std;

			const int N = 1e5 + 10, M = 2e5 + 10;
			int n, m, res, cnt;
			int p[N];
			struct Edge{
			    int a, b, w;
			    bool operator<(const Edge &e){	注意, 需要比较 	
			        return w < e.w;
			    }
			}edges[M];

			int find(int x){
			    if(p[x] != x) p[x] = find(p[x]);
			    return p[x];
			}

			bool kruskal(){
			    for(int i = 1; i <= n; i++) p[i] = i;
			    sort(edges, edges + m);
			    for(int i = 0; i < m; i++){
			        auto e = edges[i];
			        int a = e.a, b = e.b, w = e.w;
			        
			        int pa = find(a), pb = find(b);
			        if(pa != pb){
			            p[pa] = pb;
			            res += w;
			            cnt ++;
			        }
			    }
			    if(cnt != n - 1) return false;
			    return true;
			    
			}

			int main(){
			    cin >> n >> m;
			    for(int i = 0; i < m; i++){
			        int a, b, c;
			        cin >> a >> b >> c;
			        edges[i] = {a, b, c};
			    }
			    if(kruskal()) cout << res << endl;
			    else puts("impossible");
			    return 0;
			}
			--
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 1e5 + 10, M = 2e5 + 10;
			struct Edge{
			    int a, b, w;
			    bool operator<(const Edge& e) const{
			        return w < e.w;
			    }
			}edges[M];
			int p[N], res, cnt, n, m;

			int find(int x){
			    if(p[x] != x) p[x] = find(p[x]);
			    return p[x];
			}

			bool kruskal(){
			    for(int i = 1; i <= n; i++) p[i] = i;
			    sort(edges, edges + m);
			    for(int i = 0; i < m; i++){
			        auto e = edges[i];
			        int u = e.a, v = e.b, w = e.w;
			        int pu = find(u), pv = find(v);
			        if(pu != pv){
			            p[pu] = pv;
			            res += w;
			            cnt ++;
			        }
			    }
			    if(cnt < n - 1) return false;
			    return true;
			}

			int main(){
			    cin >> n >> m;
			    for(int i = 0; i < m; i++){
			        int a, b, c;
			        cin >> a >> b >> c;
			        edges[i] = {a, b, c};
			    }
			    if(kruskal()) cout << res << endl;
			    else puts("impossible");
			    return 0;
			}
			--
			#include <iostream>
			#include <algorithm>
			using namespace std;

			const int N = 1e5 + 10, M = 2e5 + 10;
			int p[N], res, cnt;
			int n, m;
			struct Edge{
			    int a, b, w;
			    bool operator<(const Edge& e) const{
			        return w < e.w;
			    }
			}edges[M];

			int find(int x){
			    if(p[x] != x) p[x] = find(p[x]);
			    return p[x];
			}

			bool kruskal(){
			    for(int i = 1; i <= n; i++) p[i] = i;
			    sort(edges, edges + m);
			    for(int i = 0; i < m; i++){
			        auto e = edges[i];
			        int u = e.a, v = e.b, w = e.w;
			        int pu = find(u), pv = find(v);
			        if(pu != pv){
			            p[pu] = pv;
			            res += w;
			            cnt ++;
			        }
			    }
			    if(cnt != n - 1) return false;
			    return true;
			}

			int main(){
			    cin >> n >> m;
			    for(int i = 0; i < m; i++){
			        int a, b, c;
			        cin >> a >> b >> c;
			        edges[i] = {a, b, c};
			    }
			    if(kruskal()) cout << res << endl;
			    else puts("impossible");
			}
	53. AcWing 860. 染色法判定二分图
		1. bug
			我的经验, 如果实在是觉得自己的代码没问题, 就一定是哪个小细节写错了
				1.
					for(int i = h[u]; ~i; i = ne[i]){
				        错误: int v = e[v];
				        正确: int v = e[i];
				    }
				2. 
					错误: if(!st[j] && (t == 1 || dist[j] < dist[t])) t = j;	害我找半天!!
			        正确: if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
			
			#include <iostream>
			#include <cstring>
			using namespace std;

			错误了2次: const int N = 1e5 + 10;
			正确: const int N = 1e5 + 10, M = 2e5 + 10; 因为是无向边 
			int h[N], e[M], ne[M], ind;
			int color[N];
			int n, m;

			void add(int a, int b){
			    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
			}

			bool dfs(int u, int c){ 	如果这个联通块存在奇数环, 返回false, 如果通过全部验证, 返回true.
			    color[u] = c;
			    for(int i = h[u]; ~i; i = ne[i]){
			        错误: int v = e[v];
			        正确: int v = e[i];
			        if(!color[v]){
			            错误: return dfs(v, 3 - c); ----------- 注意! 这个错误很致命! 这里是不管 dfs(v, 3 - c)是true还是false, 都会返回
			            正确: if (!dfs(v, 3 - c)) return false;	但是, 应该的是: 只有是返回false的时候, 我们才返回. 如果是true, 我们还要继续判断
			        }
			        else if(color[v] == c) return false;
			    }
			    return true;
			}

			int main(){
			    错了2次: 忘了初始化 memset(h, -1, sizeof h);	
			    cin >> n >> m;
			    while(m--){
			        int a, b;
			        cin >> a >> b;
			        错误: add(a, b); 
			        正确: add(a, b), add(b, a);  因为是无向边 
			        	如果你写成了有向边, 可能的情况是, 本来是一个环, 你愣是找不到
			        		a -- b 
			        		 \   /
			        		   c

			        		如果是有向, 就找不成一个环了
			        			a -> b
			        			 \  /
			        			  ↓ ↓
			        			   c
			    }
			    bool f = true;
			    错误: for(int i = 0; i < n; i++){
			   	正确: for(int i = 1; i <= n; i++){
			        错误: 忘写了: if(!color[i]){
			        正确: if(!color[i]){
			            if(!dfs(i, 1)){ 将点i染成颜色1, 如果这个联通块存在奇数环, 即 dfs(i,1) == false, 直接结束
			                f = false;
			                break;
			            }
			        }
			    }
			    if(!f) puts("No");
			    else puts("Yes");
			}
		2. ok
			#include <iostream>
			#include <cstring>
			using namespace std;

			const int N = 2e5 + 10;
			int h[N], e[N], ne[N], ind;
			int color[N], n, m;

			void add(int a, int b){
			    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
			}

			bool dfs(int u, int c){	不需要写递归到底的情况, 因为如果 临边都是有颜色, for()直接走出来, 返回true
			    color[u] = c; 
			    for(int i = h[u]; ~i; i = ne[i]){
			        int v = e[i];
			        if(!color[v]){
			            if(!dfs(v, 3 - c)) return false;
			        }else if(color[v] == c) return false;
			    }
			    return true;
			}

			int main(){
			    memset(h, -1, sizeof h);
			    cin >> n >> m;
			    while(m--){
			        int a, b;
			        cin >> a >> b;
			        add(a, b), add(b, a);
			    }
			    bool f = true;
			    for(int i = 1; i <= n; i++){
			        if(!color[i]){
			            if(!dfs(i, 1)){
			                f = false;
			                break;
			            }
			        }
			    }
			    if(f) cout << "Yes" << endl;
			    else cout << "No" << endl;
			    return 0;
			}
5. 5.17
	54. AcWing 861. 二分图的最大匹配
		0.
			图是二分图, 找里面的
			找里面可以连接的边 
		1. bug
			1. 错的离谱, 连st都忘了
				#include <iostream>
				#include <cstring>
				using namespace std;

				const int N = 510, M = 1e5 + 10;
				int h[N], e[M], ne[M], ind;
				int match[N], res;

				void add(int a, int b){
				    e[ind] = b, ne[ind] = h[a], h[a] = ind ++;
				}

				bool find(int u){
				    for(int i = h[u]; ~i; i = ne[i]){
				        int v = e[i];
				        if(!match[v] || find(match[v])){
				            match[v] = u;
				            return true;
				        }
				    }
				    return false;
				}


				int main(){
				    int n1, n2, m;
				    cin >> n1 >> n2 >> m;
				    while(m--){
				        int a, b;
				        add(a, b);
				    }
				    for(int i = 1; i <= n1; i++){
				        memset(match, 0, sizeof match);
				        if(find(i)) res++;
				    }
				    cout << res << endl;
				    return 0;
				}
			2.
				#include <iostream>
				#include <cstring>
				using namespace std;
				const int N = 510, M = 1e5 + 10;
				int h[N], e[M], ne[M], ind;		注意边是M
				int match[N], res, n1, n2, m;
				bool st[N];

				void add(int a, int b){
				    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
				}

				bool find(int u){
				    for(int i = h[u]; ~i; i = ne[i]){
				        笔误了两次: int v = e[u];
				        正确: int v = e[i];
				        if(!st[v]){	别忘了
				            错误: 忘了写 st[v] = true;	
				            正确 st[v] = true;
				            if(!match[v] || find(match[v])){
				                match[v] = u;
				                return true;
				            }
				        }
				    }
				    return false;
				}

				int main(){
				    忘记写: 
				    正确: memset(h, -1, sizeof h);
				    cin >> n1 >> n2 >> m;
				    while(m--){
				        int a, b;
				        cin >> a >> b;
				        add(a, b);
				    }
				    错误: for(int i = 0; i < n1; i++){
				    正确: for(int i = 1; i <= n1; i++){	这是编号
				        memset(st, false, sizeof st);	这个是点睛之笔
				        if(find(i)) res++;
				    }
				    cout << res << endl;
				    return 0;
				}

		2. ok
			//不要仅仅从稠密图/稀疏图, 判断用邻接矩阵/邻接表. 这里我们主要关注一个固定的点的所有临边, 我们用邻接表更好
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 510, M = 1e5 + 10;
			int h[N], e[M], ne[M], ind;
			int match[N], n1, n2, m, res;
			bool st[N];

			void add(int a, int b){
			    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
			}

			bool find(int x){
			    for(int i = h[x]; ~i; i = ne[i]){
			        int g = e[i];	女生 
			        if(!st[g]){
			            st[g] = true;
			            if(!match[g] || find(match[g])){
			                match[g] = x;
			                return true;
			            }
			        }
			    }
			    return false;
			}

			int main(){
			    memset(h, -1, sizeof h);
			    cin >> n1 >> n2 >> m;
			    while(m--){
			        int a, b;
			        cin >> a >> b;
			        add(a, b);
			    }
			    for(int i = 1; i <= n1; i++){
			        memset(st, false, sizeof st);
			        if(find(i)) res++;
			    }
			    cout << res << endl;
			    return 0;
			}
	55. AcWing 2. 01背包问题
		0. 小总结:
			1. 01背包:
				朴素 -> 优化:
					1. 删去第一维, 最终: f[N], f[j] = max(f[j], v[i] + f[j - w[i]]), 输出 f[m]
					2. 必须从右到左遍历: for(int j = 0; j <= m; j++){ 变为 for(int j = m; j - w[i] >= 0; j--){
							注意是 j--
			2. 完全背包:
				朴素 -> 优化:
					1. 删去第一维, 最终: f[N], f[j] = max(f[j], v[i]+ f[j - w[i]]), 输出 f[m]
					2. 必须, 依旧是是从左到右遍历: 
						从 
							for(int j = 0; j <= m; j++)
					            if(j - w[i] >= 0) 
					                f[i][j] = max(f[i-1][j], v[i] + f[i][j - w[i]]);
					            else
					                f[i][j] = f[i-1][j];
					    改为
					    	for(int j = w[i]; j <= m; j++)
            					f[j] = max(f[j], f[j - w[i]] + v[i]);
			3. 多重背包:
				1. max 
					这里的取0个第i个物品, ... 取第k个第i物品, 都是在这个公式中
					所以注意bug:
						for(int k = 0; k <= s[i]; k++){
							if(j - k * w[i] >= 0) 
			                	错误2次: 	f[i][j] = max(f["i-1"][j], k * v[i] + f[i-1][j - k * w[i]]);
			                	错误1次: f[i][j] = max(f[i][j], k * v[i] + f["i"][j - k * w[i]]);			注意max的第二项, 是考虑前i-1个选法受到的影响 
			                    正确:	f[i][j] = max(f["i"][j], k * v[i] + f["i-1"][j - k * w[i]]);	因为k==0的时候, 相当于 f[i-1][j];
			                错误, 不应该写下面这两句: 如果 j - k * w[i] < 0, 也就是什么都别执行. 如果你执行了这一句, 相当于上面的max都白干了
				                else
				                    f[i][j] = f[i-1][j];
				2. for (int k = 0; k <= s[i] && j - k * v[i] >= 0; k ++ )
						f[i][j] = max(f[i][j], k * v[i] + f[i-1][j - k * w[i]]);
                	写的时候, 想着: 
                		有k种选法, 选0个, 1个两个: k * v[i] 
                		但是然后前i-1种的选法里面, 就要受到影响 f[i-1][j - k * w[i]]
                		所以所有合法的选法{k <= s[i] && j - k * w[i] >= 0}, 我们用max来滚动判断
                3. 小优化:
                	从 
                		for(int k = 0; k <= s[i]; k++){
							if(j - k * w[i] >= 0) 		也就是即便 j - k * v[i] < 0 也不会终止, 会一直到 k == s[i] + 1
								f[i][j] = max()
					到 
						for (int k = 0; k <= s[i] && j - k * v[i] >= 0; k ++ )	也就是一旦 j - k * v[i] < 0, for 就终止
							f[i][j] = max()
				4. 删除一个维度的优化
					1. 删去第一维, 最终: f[N], f[j] = max(f[j], v[i] + f[j - w[i]]), 输出 f[m]
					2. 必须从右到左遍历: for(int j = 0; j <= m; j++){ 变为 for(int j = m; j >= 0; j--){ 
						因为需要的是左上
			4. 数据量大的多重背包:
				1. 二分优化
				2. 01背包: 只剩一维, 从右到左遍历
		1. bug
			1. 非优化 
				#include <iostream>
				using namespace std;

				const int N = 1010;
				int f[N][N], v[N], w[N];
				int n, m;

				int main(){
				    cin >> n >> m;
				    错误: for(int i = 0; i < n; i++){ 
				    正确: for(int i = 1; i <= n; i++){	物品这里需要的从1开始编号
				        cin >> w[i] >> v[i];
				    }
				    
				    for(int i = 1; i <= n; i++){
				        for(int j = 0; j <= m; j++){
				            错误: if(j - v[i] > 0) 
				            正确: if(j - w[i] >= 0) 首先是体积w, 其次是 >= 0, 也就是==0刚好够一个物品的时候, 也要 max(选项1, 选项2)
				                错误: f[i][j] = min(f[i-1][j], f[i-1][j - w[i]] + v[i]);
				                正确: f[i][j] = max(f[i-1][j], f[i-1][j - w[i]] + v[i]);
				            else 
				                f[i][j] = f[i-1][j];
				        }
				    }
				    cout << f[n][m] << endl;
				    return 0;
				}
			2. 优化
				#include <iostream>
				using namespace std;
				const int N = 1010;
				int f[N], w[N], v[N];
				int n, m;

				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
				    for(int i = 1; i <= n; i++){
				    	错误: for(int j = m; j - w[i] >= 0; j++){
				        正确: for(int j = m; j - w[i] >= 0; j--){
				            f[j] = max(f[j], f[j - w[i]] + v[i]);
				        }
				    }
				    cout << f[m] << endl;
				    return 0;
				    
				}
		2. ok
			1. 非优化
				#include <iostream>
				using namespace std;

				const int N = 1010;
				int f[N][N], w[N], v[N];
				int n, m;

				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
				    for(int i = 1; i <= n; i++){		之所以是1开始, 我认为是有 f[i-1], 所以要保证 i - 1 >= 0, 并且 f(1,0)是有意义的, 也就是取第一个物品, 但是重量不超过0, 其实就是什么都不取, 所以 f(1,0)应该是0
				        for(int j = 0; j <= m; j++){	之所以是可以从0开始, 因为保证 j - v[i] >= 0, 可以等于0是因为 f(1,0)是有意义的, 也就是取第一个物品, 但是重量不超过0, 其实就是什么都不取, 所以 f(1,0)应该是0
				            if(j - w[i] >= 0) 			装了 v[i]体积后, 还有空位
				            	f[i][j] = max(f[i-1][j], f[i-1][j-w[i]] + v[i]);
				            else f[i][j] = f[i-1][j];
				        }
				    }
				    cout << f[n][m] << endl;
				    return 0;
				}
				--
				#include <iostream>
				using namespace std;
				const int N = 1010;
				int f[N][N], w[N], v[N];
				int n, m;
				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
				    for(int i = 1; i <= n; i++){
				        for(int j = 0; j <= m; j++){
				            if(j - w[i] >= 0) f[i][j] = max(f[i-1][j], f[i-1][j - w[i]] + v[i]);
				            else f[i][j] = f[i-1][j];
				        }
				    }
				    cout << f[n][m] << endl;
				    return 0;
				}
				--
				#include <iostream>
				using namespace std;

				const int N = 1010;
				int f[N][N], w[N], v[N], n, m;

				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; i ++) cin >> w[i] >> v[i];
				    for(int i = 1; i <= n; i++){
				        for(int j = 0; j <= m; j++){
				            if(j - w[i] >= 0)
				                f[i][j] = max(f[i-1][j], f[i-1][j - w[i]] + v[i]);
				            else 
				                f[i][j] = f[i-1][j];
				        }
				    }
				    cout << f[n][m] << endl;
				    return 0;
				}
			2. 优化 
				#include <iostream>
				using namespace std;

				const int N = 1010;
				int v[N], w[N];
				int f[N];

				int n, m;
				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; ++i) cin >> w[i] >> v[i];
				   	for(int i = 1; i <= n; ++i){ 		
				        for(int j = m; j >= 0; --j){ 	
				            if(j - w[i] >= 0){ 
				                f[j] = max(f[j], f[j-w[i]] + v[i]); 相当于: f[i][j] = max(f[i-1][j], f[i-1][j-v[i]] + w[i]); 因为此时等号右侧的东西, 都是上一轮 i - 1的
				            }else{
				                f[j] = f[j]; 相当于 f[i][j] = f[i-1][j];
				            }
				        }
				    }
				    cout << f[m] << endl;
				}
			3. 进一步:
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 1010;

				int n, m;
				int v[N], w[N];
				int f[N];

				int main()
				{
				    cin >> n >> m;

				    for (int i = 1; i <= n; i ++ ) cin >> w[i] >> v[i];
				    for (int i = 1; i <= n; i ++ )
				        for (int j = m; j - w[i] >= 0; j -- )
				            f[j] = max(f[j], f[j - w[i]] + v[i]);

				    cout << f[m] << endl;

				    return 0;
				}
	56. AcWing 3. 完全背包问题
		1. bug
		2. ok
			1. 朴素 
				#include <iostream>
				using namespace std;

				const int N = 1010;
				int f[N][N], w[N], v[N];
				int n, m;

				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
				    for(int i = 1; i <= n; i++){
				        for(int j = 0; j <= m; j++){
				            if(j - w[i] >= 0) 	如果能放下至少一个第i个物品, 我们就比较 max(上方, 左方)
				            	f[i][j] = max(f[i-1][j], v[i] + f[i][j - w[i]]); 	
				            else 				放不下, 就只能从上方来, 也就是只选择前i-1个物品
				            	f[i][j] = f[i-1][j];
				        }
				    }
				    cout << f[n][m] << endl;
				    return 0;
				}
			2. 优化 
				#include <iostream>
				using namespace std;

				const int N = 1010;
				int f[N], w[N], v[N];
				int n, m;

				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
				    for(int i = 1; i <= n; i++){
				        for(int j = 0; j <= m; j++){
				            if(j - w[i] >= 0) 
				                f[j] = max(f[j], f[j - w[i]] + v[i]);	相当于 f[i][j] = max(f[i-1][j], f[i][j - v[i]] + w[i]);
				            else 
				                f[j] = f[j];							相当于 f[i][j] = f[i-1][j];
				        }
				    }
				    cout << f[m] << endl;
				    return 0;
				}
			3. 进一步
				#include <iostream>
				using namespace std;

				const int N = 1010;
				int f[N], w[N], v[N];
				int n, m;

				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
				    for(int i = 1; i <= n; i++){
				        for(int j = w[i]; j <= m; j++){
				            f[j] = max(f[j], f[j - w[i]] + v[i]);	
				        }
				    }
				    cout << f[m] << endl;
				    return 0;
				}
	57. AcWing 4. 多重背包问题	
		1. bug
			#include <iostream>
			using namespace std;
			const int N = 1010;
			int f[N][N], w[N], v[N], s[N];
			int n, m;
			int main(){
			    cin >> n >> m;
			    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i] >> s[i];
			    for(int i = 1; i <= n; i++){
			        for(int j = 0; j <= m; j++){
			            for(int k = 0; k <= s[i]; k++){
			                if(j - k * w[i] >= 0) 
			                	错误2次: 	f[i][j] = max(f["i-1"][j], k * v[i] + f[i-1][j - k * w[i]]);
			                	错误1次: f[i][j] = max(f[i][j], k * v[i] + f["i"][j - k * w[i]]);			注意max的第二项, 是考虑前i-1个选法受到的影响 
			                    正确:	f[i][j] = max(f["i"][j], k * v[i] + f["i-1"][j - k * w[i]]);	因为k==0的时候, 相当于 f[i-1][j];
			                错误, 不应该写这两句: 如果 j - k * w[i] < 0, 也就是什么都别执行. 如果你执行了这一句, 相当于上面的max都白干了
				                else
				                    f[i][j] = f[i-1][j];
			            }
			        }
			    }
			    cout << f[n][m] << endl;
			    return 0;
			}
		2. ok
			1. 无优化
				#include <iostream>
				using namespace std;
				const int N = 110;
				int f[N][N], w[N], v[N], s[N];
				int n, m;
				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i] >> s[i];
				    for(int i = 1; i <= n; i++){
				        for(int j = 0; j <= m; j++){
				            for(int k = 0; k <= s[i]; k++){
				                if(j - k * w[i] >= 0) 
				                	f[i][j] = max(f[i][j], k * v[i] + f[i-1][j - k * w[i]]);
				                	写的时候, 想着: 
				                		有k种选法, 选0个, 1个两个: k * v[i] 
				                		但是然后前i-1种的选法里面, 就要受到影响 f[i-1][j - k * w[i]]
				                		所以所有合法的选法{k <= s[i] && j - k * w[i] >= 0}, 我们用max来滚动判断
				                	而不是想着: 不选第i种{f[i-1][j]}, 选第i种{k * v[i] + f[i-1][j - k * w[i]]}
				            }
				        }
				    }
				    cout << f[n][m] << endl;
				    return 0;
				}
			2. k的小优化: k <= s[i] && j - k * v[i] >= 0
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 110;

				int n, m;
				int v[N], w[N], s[N];
				int f[N][N];

				int main()
				{
				    cin >> n >> m;

				    for (int i = 1; i <= n; i ++ ) cin >> w[i] >> v[i] >> s[i];

				    for (int i = 1; i <= n; i ++ )
				        for (int j = 0; j <= m; j ++ )
				            for (int k = 0; k <= s[i] && j - k * w[i] >= 0; k ++ )	之所以没有优化, 应该是很难确定k的最大值是多少吧. 其实也好确定: k = s[i]; while(j - k * v[i] < 0) k--;
				                f[i][j] = max(f[i][j], k * v[i] + f[i - 1][j - k * w[i]]);

				    cout << f[n][m] << endl;
				    return 0;
				}
				--
				#include <iostream>
				using namespace std;
				const int N = 110;
				int f[N][N], w[N], v[N], s[N], n, m;
				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i] >> s[i];
				    for(int i = 1; i <= n; i++){
				        for(int j = 0; j <= m; j++){
				            for(int k = 0; k <= s[i] && j - k * w[i] >= 0; k++){
				                f[i][j] = max(f[i][j], k * v[i] + f[i-1][j - k * w[i]]);
				            }
				        }
				    }
				    cout << f[n][m] << endl;
				}
				--
				#include <iostream>
				using namespace std;
				const int N = 110;
				int f[N][N], w[N], v[N], s[N], n, m;
				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i] >> s[i];
				    for(int i = 1; i <= n; i++){
				        for(int j = 0 ; j <= m; j++){
				            for(int k = 0; k <= s[i] && j - k * w[i] >= 0; k++)
				                f[i][j] = max(f[i][j], k * v[i] + f[i-1][j - k * w[i]]);
				        }
				    }
				    cout << f[n][m] << endl;
				    return 0;
				}
			3. 删除一个维度 
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 110;

				int n, m;
				int v[N], w[N], s[N];
				int f[N];

				int main()
				{
				    cin >> n >> m;

				    for (int i = 1; i <= n; i ++ ) cin >> w[i] >> v[i] >> s[i];

				    for (int i = 1; i <= n; i ++ )
				        for (int j = m; j >= 0; j -- )
				            for (int k = 0; k <= s[i] && j - k * w[i] >= 0; k ++ )
				                f[j] = max(f[j], k * v[i] + f[j - w[i] * k]);

				    cout << f[m] << endl;
				    return 0;
				}
				--
				#include <iostream>
				using namespace std;
				const int N = 110;
				int f[N], w[N], v[N], s[N], n, m;
				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i] >> s[i];
				    for(int i = 1; i <= n; i++){
				        for(int j = m ; j >= 0; j--){
				            for(int k = 0; k <= s[i] && j - k * w[i] >= 0; k++)
				                f[j] = max(f[j], k * v[i] + f[j - k * w[i]]);
				        }
				    }
				    cout << f[m] << endl;
				    return 0;
				}
	58. AcWing 5. 多重背包问题 II
		1. bug
			1. 很多bug
				#include <iostream>
				using namespace std;
				const int N = 2010; 			因为体积 0<V≤2000
				const int M = 11 * 1000 + 10; 	因为有1k个输入, 每个输入的数量有2k个, log2(2k) = 11
				错误: int f[M][N], w[M], v[M], s[N], n, m;	不需要s[N]
				正确: int f[N], w[M], v[M], n, m;
				int main(){
				    cin >> n >> m;
				    错误: int cnt = 0, k = 1; k要在for里面 
				    int cnt = 0;
				    for(int i = 1; i <= n; i++){
				        int ww, vv, cc;
				        cin >> ww >> vv >> cc;
				        正确: int k = 1;
				        错误: while(cc - k){	这里是非0就会进入, 也就是正数负数都会进入. 
				        正确Lwhile(cc - k >= 0){
				            cnt ++;
				            w[cnt] = k * ww;
				            v[cnt] = k * vv;
				            cc -= k;
				            错误: k >> 1;
				            错误: k << 1;
				            正确: k <<= 1;
				        }
				        if(cc){
				            cnt++;
				            w[cnt] = cc * ww;
				            v[cnt] = cc * vv;
				        }
				    }
				    n = cnt;
				    不能用二维, 内存限制: 
					    for(int i = 1; i <= n; i++){
					        for(int j = 0; j <= m; j++){
					            if(j - w[i] >= 0){
					                f[i][j] = max(f[i-1][j], v[i] + f[i-1][j - w[i]]);
					            }else{
					                f[i][j] = f[i-1][j];
					            }
					        }
					    }
					    cout << f[n][m] << endl;
					正确:
						for(int i = 1; i <= n ; i++){
					        for(int j = m; j >= w[i]; j--)
					            f[j] = max(f[j], v[i] + f[j - w[i]]);
					    }
					    cout << f[m] << endl;
				    return 0;
				}
		2. 
			#include <iostream>
			using namespace std;
			const int N = 2010; 			因为体积 0<V≤2000
			const int M = 11 * 1000 + 10; 	因为有1k个输入, 每个输入的数量有2k个, log2(2k) = 11
			int f[N], w[M], v[M], s[M]; 	这道题, 似乎只能用优化后的一维, 否则MemoryExceed
			int n, m;
			int main(){
			    cin >> n >> m;
			    int cnt;
			    for(int i = 1; i <= n; i++){
			        int ww, vv, cc;
			        cin >> ww >> vv >> cc;
			        int k = 1;	每个小组, 有k个物品
			        while(cc - k >= 0){
			            cnt++;  			下标从1开始比较好, 因为平时的题也都是cin >> w[i]从1开始
			            w[cnt] = ww * k;
			            v[cnt] = vv * k;
			            cc -= k;
			            k <<= 1;
			        }
			        if(cc){
			            cnt++;
			            w[cnt] = ww * cc;
			            v[cnt] = vv * cc;
			        }
			    }
			    n = cnt;
			    
			    优化版的01背包: 
			    for(int i = 1; i <= n ; i++){
			        for(int j = m; j >= w[i]; j--)
			            f[j] = max(f[j], v[i] + f[j - w[i]]);
			    }
			    cout << f[m] << endl;
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;
			const int N = 2010, M = 11 * 1010;
			int f[N], w[M], v[M], n, m;
			int main(){
			    cin >> n >> m;
			    int cnt = 0;
			    for(int i = 1; i <= n; i++){
			        int ww, vv, cc;
			        cin >> ww >> vv >> cc;
			        int k = 1;
			        while(cc - k >= 0){
			            cnt++;
			            w[cnt] = k * ww, v[cnt] = k * vv;
			            cc -= k;
			            k <<= 1;
			        }
			        if(cc){
			            cnt++;
			            w[cnt] = cc * ww, v[cnt] = cc * vv;
			        }
			    }
			    n = cnt;
			    for(int i = 1; i <= n; i++){
			        for(int j = m; j - w[i] >= 0; j--)
			            f[j] = max(f[j], v[i] + f[j - w[i]]);
			    }
			    cout << f[m] << endl;
			    return 0;
			}
	59. AcWing 9. 分组背包问题
		1. 
		2. ok {很顺}
			1. 未优化
			#include <iostream>
			using namespace std;
			const int N = 110;
			int f[N][N], w[N][N], v[N][N], s[N];
			int n, m;
			int main(){
			    cin >> n >> m;
			    for(int i = 1; i <= n; i++){
			        cin >> s[i];
			        for(int j = 1; j <= s[i]; j++){
			            cin >> w[i][j] >> v[i][j];		第i组的j个物品, 每个物品的价值和重量都不同
			        }
			    }
			    for(int i = 1; i <= n; i++){			这里说的是选前i组的东西{不是之前的前i个物品}
			        for(int j = 0; j <= m; j++){
			            for(int k = 0; k <= s[i]; k++){	这里是泛化了 v和k, 这里是第i组中可以选的物品有 s[i]个, 我们一个一个看 
			                if(j - w[i][k] >= 0)
			                    f[i][j] = max(f[i][j], v[i][k] + f[i-1][j - w[i][k]]);
			            }
			        }
			    }
			    cout << f[n][m] << endl;
			    return 0;
			}
			2. 优化{一维}
				#include <iostream>
				using namespace std;
				const int N = 110;
				int f[N], w[N][N], v[N][N], s[N];
				int n, m;
				int main(){
				    cin >> n >> m;
				    for(int i = 1; i <= n; i++){
				        cin >> s[i];
				        for(int j = 1; j <= s[i]; j++){
				            cin >> w[i][j] >> v[i][j];
				        }
				    }
				    for(int i = 1; i <= n; i++){
				        for(int j = m; j >= 0; j--){
				            for(int k = 0; k <= s[i]; k++){
				                if(j - w[i][k] >= 0)
				                    f[j] = max(f[j], v[i][k] + f[j - w[i][k]]);
				            }
				        }
				    }
				    cout << f[m] << endl;
				    return 0;
				}
6. 5.21
	60. AcWing 898. 数字三角形
		1. 
		2. ok{很顺}
			#include <iostream>
			using namespace std;
			const int N = 510, INF = 1e5; //老师: INF = 1e9;
			int a[N][N], f[N][N], n;

			int main(){
			    scanf("%d", &n);
			    for(int i = 1; i <= n; i++){
			        for(int j = 1; j <= i; j ++)
			            scanf("%d", &a[i][j]);
			    }
			    for(int i = 1; i <= n; i++){
			        for(int j = 0; j <= i + 1; j ++)
			            f[i][j] = -INF;	这是一个在矩阵的左下角的三角形
			    }
			    f[1][1] = a[1][1];
			    for(int i = 2; i <= n; i++){
			        for(int j = 1; j <= i ; j++){
			            f[i][j] = max(f[i-1][j] + a[i][j], f[i-1][j-1] + a[i][j]);	{左上方, 上方}
			        }
			    }
			    int res = 0;
			    for(int i = 1; i <= n; i++){
			        res = max(res, f[n][i]);	这是求最底下的一行, 从左往右的最大值, 这个最大值就是全局的路径之和的最大值
			    }
			    printf("%d\n", res);
			    return 0;
			}

			f[][]的初始化:
				0	0	0	0	0	0	0
				
				I 	1,1 I 
				
				I 	In 	In 	I
				
				I 	In 	In 	In 	I
				
				I 	In 	In 	In 	In 	I 

				I 	In 	In 	In 	In 	In 	I 

				解释: 
					I: INF
					In: 和a[][]中的n重叠的部分 
					1,1: f[1][1] = a[1][1];
			a[][]的初始化:
				0	0	0	0	0	0	

				0	n

				0	n 	n

				0 	n 	n 	n

				0	n 	n 	n 	n

				0 	n 	n 	n 	n 	N
	61. AcWing 895. 最长上升子序列
		0. 小总结:
			朴素法: O(n*n) == 状态数(n) * 转移数(n)
				f[i]: 以第i个数字为结尾的, 最长上升子序列的"长度", f[以第i个数字结尾的最长上升子序列] == 最长上升子序列的长度
					所有的f[i]初始化为1, 意思是: 我的左边没有比我小的数字, 所以以我结尾的最长上升子序列只有我, 长度为1
					我们要遍历完所有i左侧的数字, 才能获得最终的正确的f[i], 因为有n个i, 所以n*n复杂度较高
					例如:
						原序列:
							3 1 2 1 8 5 6
						对应的f[1]:
							1 1 2 1 3 3 4 
			优化: O(nlogn) == 状态数(n) * 转移数(logn)
				f[i]: 所有的长度为i的最长上升子序列中, 结尾数字最小的最长上升子序列, f[最长上升子序列长度为i] == 结尾数字最小的最长上升子序列
					我们要遍历完所有数字, 才能获得最终的正确的f[i]
					两种情况:
						1. if(a[i] > f[len]) f[++len] = a[i]; //如果这个数字大于我们的 长度为len的最长xx的最小的最后数字, 我们可以继续延伸
						2. 否则 
							否则a[i]就拉低前面的某个数字, 假设要拉低的是 f[x], 那么会满足: f[x-1] < a[i] <= f[x]
								所以我们要找到所有满足大于等于target{a[i]}的所有f[xx]中"最左侧"的f[x]
       						不存在 f[x-1] == f[x] 的情况, 因为题目说的是: 数值严格单调递增的子序列的长度最长是多少
       							例如题目的原序列: 	1	3	3	3
       							我们的最长上升子序列长度是2, 也就是 {1,3}.
       							而不是最长上升子序列长度是4
		1. bug
			#include<iostream>
			using namespace std;
			const int N = 1010;
			int a[N], f[N], n;
			int main(){
			    cin >> n;
			    for(int i = 1; i <= n; i++) cin >> a[i];
			    错误: f[1] = a[1];	是==长度
			    错误: f[1] = 1;		每个f[i]都是初始化为1
			    for(int i = 1; i <= n; i++){
			        错误: f[1] = 1;	每个f[i]都是初始化为1
			        正确: f[i] = 1;
			        for(int j = 1; j < n; j++)
			            if(a[j] < a[i])
			                f[i] = max(f[i], f[j] + 1);
			    }
			    int res = 0;
			    for(int i = 1; i <= n; i++) res = max(res, f[i]);	易错: 不要以为f[n]是最大值, 不是的, f[n]可能==1也就是第n个数字是最小的
			    cout << res << endl;
			    return 0;
			}
		2. ok: O(n*n) == 状态数(n) * 转移数(n)
			#include <iostream>
			using namespace std;
			const int N = 1010;
			int a[N], f[N], n, res;
			int main(){
			    cin >> n;
			    for(int i = 1; i <= n; i++) cin >> a[i];
			    for(int i = 1; i <= n; i++){
			        f[i] = 1;					只有a[i]一个数, 所以长度为1
			        for(int j = 1; j < i; j++) 	检查所有第i个数字的左侧的数字, 不包括第i个数字
			            if(a[j] < a[i]) 
			            	f[i] = max(f[i], f[j] + 1);	第j个数他也有自己的最长上升子序列吧, 那就是f[j], 我们站在他的肩膀上, 求我的f[i]的最大值
			    }
			    for(int i = 1; i <= n; i++) res = max(res, f[i]);	看所有的 最长上升子序列 中的最大值 
			    cout << res << endl;
			    return 0;
			}
	62. AcWing 896. 最长上升子序列 II 
		1. bug
			#include <iostream>
			using namespace std;
			const int N = 1e5 + 10;
			int a[N], f[N], n, len; 注意: 不能用size代替len, size是cpp的关键词, bobo老师是用java所以不冲突
			int main(){
			    cin >> n;
			    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
			    f[++len] = a[1];
			    for(int i = 2; i <= n; i++){
			        if(a[i] > f[len]) f[++len] = a[i];
			        else{
			            错误: int l = 1, r = i;
			            正确: int l = 1, r = len;
			            while(l < r){
			                int mid = (r - l) / 2 + l;
			                if(f[mid] >= a[i]) r = mid;	这是"大于等于target"{a[i]}的所有f[xx], 如果是true, 我们要找"最左侧"的f[x], 往左找, 并且mid可能是答案, 所以是r = mid
			                else l = mid + 1;
			            }
			            f[r] = a[i];
			        }
			    }
			    cout << len << endl;
			    return 0;
			}
		2. ok: O(nlogn) == 状态数(n) * 转移数(logn)
			0. 我的 很顺:
				#include <iostream>
				using namespace std;
				const int N = 1e5 + 10;
				int a[N], f[N], n, len;
				int main(){
				    cin >> n;
				    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
				    f[++len] = a[1];						长度为1的最长上升子序列的最后一个数字是a[1];
				    for(int i = 2; i <= n; i++){			往右看每个数字
				        if(a[i] > f[len]) f[++len] = a[i];	如果这个数字大于我们的 长度为len的最长xx的最小的最后数字, 我们可以继续延伸
				        else{								否则a[i]就拉低前面的某个数字, 假设要拉低的是 f[x], 那么会满足: f[x-1] < a[i] <= f[x]
				        									所以我们要找到所有满足大于等于target{a[i]}的所有f[xx]中"最左侧"的f[x]
				        									注意: 不存在 f[x-1] == f[x] 的情况, 因为题目说的是: 数值严格单调递增的子序列的长度最长是多少
								       							例如题目的原序列: 	1	3	3	3
								       							我们的最长上升子序列长度是2, 也就是 {1,3}.
								       							而不是最长上升子序列长度是4
				            int l = 1, r = len;				这个是f里面, 下标的范围[1, len]
				            while(l < r){
				                int mid = (r - l) / 2 + l;
				                if(f[mid] >= a[i]) r = mid;	这是"大于等于target"{a[i]}的所有f[xx], 如果是true, 我们要找"最左侧"的f[x], 往左找, 并且mid可能是答案, 所以是r = mid
				                else l = mid + 1;
				            }
				            f[l] = a[i];
				        }
				    }
				    cout << len << endl;
				    return 0;
				}
				--
				#include <iostream>
				using namespace std;
				const int N = 1e5 + 10;
				int a[N], f[N], n, len;
				int main(){
				    cin >> n;
				    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
				    f[++len] = a[1];
				    for(int i = 2; i <= n; i++){
				        if(a[i] > f[len]) f[++len] = a[i];
				        else{
				            int target = a[i];
				            int l = 1, r = len;
				            while(l < r){
				                int mid = (r - l) / 2 + l;
				                if(f[mid] >= target) r = mid;
				                else l = mid + 1;
				            }
				            f[l] = target;
				        }
				    }
				    cout << len << endl;
				    return 0;
				}
			1. 老师的, 没背
				#include <iostream>
				#include <algorithm>
				using namespace std;
				const int N = 100010;
				int n;
				int a[N];
				int q[N];
				int main()
				{
				    scanf("%d", &n);
				    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
				    int len = 0;
				    for (int i = 0; i < n; i ++ )
				    {
				        int l = 0, r = len;
				        while (l < r){
				            int mid = l + r + 1 >> 1;
				            if (q[mid] < a[i]) l = mid;
				            else r = mid - 1;
				        }
				        len = max(len, r + 1);
				        q[r + 1] = a[i];
				    }
				    printf("%d\n", len);
				    return 0;
				}
	63. AcWing 897. 最长公共子序列
		1.
		2. ok 很顺 
			#include <iostream>
			using namespace std;
			const int N = 1010;
			int f[N][N], n, m;
			char a[N], b[N];
			int main(){
			    scanf("%d%d%s%s", &n, &m, a + 1, b + 1);   //这里会自动处理空格, 换行
			    for(int i = 1; i <= n; i++){
			        for(int j = 1; j <= m; j++){
			            if(a[i] == b[j])
			                f[i][j] = f[i-1][j-1] + 1;
			            else{
			                简化版: f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			                详细版:
				                f[i][j] = max(f[i-1][j-1], f[i-1][j]);
				                f[i][j] = max(f[i][j], f[i][j-1]);
			            }
			        }
			    }
			    cout << f[n][m] << endl;
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;
			const int N = 1010;
			int f[N][N], n, m;
			char a[N], b[N];
			int main(){
			    scanf("%d%d%s%s", &n, &m, a + 1, b + 1);
			    for(int i = 1; i <= n; i++){
			        for(int j = 1; j <= m; j++){
			            if(a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
			            else f[i][j] = max(f[i-1][j], f[i][j-1]);
			        }
			    }
			    cout << f[n][m] << endl;
			    return 0;
			}
	64. AcWing 902. 最短编辑距离
		0. 小总结:
			过程很简单:
				1. 初始化
					如果a是空的{只有0个元素}, 要匹配j个b[1到j], 就要添加所有b里面的元素, 即添加j次
					如果b是空的{只有0个元素}, a[1到j]要匹配b, 就要删除所有的a里面的元素, 即删除i次
				2. 遍历行和列
					min(4个选项)
						左上: 改掉a[i], 包含两个选项					上方: 删除a[i]
							a[i] != b[j]: f[i-1][j-1] + 1
							a[i] == b[j]: f[i-1][j-1] + 0

				    	左方: a[i]后插入
		1. bug
		2. ok 很顺
		 	#include <iostream>
			using namespace std;
			const int N = 1010;
			int f[N][N], n, m;
			char a[N], b[N];
			int main(){
			    scanf("%d%s%d%s", &n, a + 1, &m, b + 1);
			    //求的是min, 按道理说你的初始化是+INF, 但是这里可以不需要
			    for(int i = 0; i <= n; i++) f[i][0] = i; //[0,n], 一共n+1个数字要遍历
			    for(int i = 0; i <= m; i++) f[0][i] = i;

			    for(int i = 1; i <= n; i ++){
			        for(int j = 1; j <= m; j++)
			        {
			            f[i][j] = min(f[i-1][j] + 1, f[i][j-1] + 1);	min(上方, 左方)
			            f[i][j] = min(f[i][j], f[i-1][j-1] + (a[i] != b[j])); //我们希望a[i]==b[i]什么都不用改, 什么动作都不要是0, 所以需要a[i] == b[j]是false
			        
			        	总结:

				    		左上: 改掉a[i]			上方: 删除a[i]

				    		左方: a[i]后插入
			        }
			    }
			    cout << f[n][m] << endl;
			    return 0;
			}
	65. AcWing 899. 编辑距离
		0. 补充:	
			1. 
				sizeof(...)是 运算符，而不是一个函数。
					如果传入char*, 返回的长度大小包括'\0'。
				strlen(...)是函数, 参数必须是字符型指针（char*）, 且必须是以'\0'结尾的。
					返回的长度大小不包括'\0', strlen考虑细密, 会帮你-1
		1. bug
		2. ok
			保守写法: dp问题都是从i==1读入char[]
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 1010, M = 15;
			char a[N][M], t[N][M];
			int f[M][M];	不需要设置在 query()里面, 因为我们有l1,l2限定了查找的范围. 
			int query(char x[], char y[]){
			    int l1 = strlen(x + 1), l2 = strlen(y + 1);	注意, 这里是 (x + 1), (y + 1).
			    for(int i = 0; i <= l1; i++) f[i][0] = i;
			    for(int i = 0; i <= l2; i++) f[0][i] = i;
			    for(int i = 1; i <= l1; i++){
			        for(int j = 1; j <= l2; j++){
			            f[i][j] = min(f[i-1][j] + 1, f[i][j-1] + 1);
			            f[i][j] = min(f[i][j], f[i-1][j-1] + (x[i] != y[j]));
			        }
			    }
			    return f[l1][l2];
			}
			int main(){
			    int n, q;
			    scanf("%d%d", &n, &q);
			    for(int i = 0; i < n; i++) scanf("%s", a[i] + 1);
			    for(int i = 0; i < q; i++){
			        int limit;
			        scanf("%s%d", t[i] + 1, &limit);
			        int res = 0;
			        for(int j = 0; j < n; j++){
			            if(query(a[j], t[i]) <= limit) res ++;
			        }
			        cout << res << endl;
			    }
			    return 0;
			}
			--
			易错写法: 从i==0读入char[]
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 1010, M = 15;
			char a[N][M], t[N][M];
			int f[M][M];
			int query(char x[], char y[]){
			    int l1 = strlen(x), l2 = strlen(y);
			    for(int i = 0; i <= l1; i++) f[i][0] = i;
			    for(int i = 0; i <= l2; i++) f[0][i] = i;
			    for(int i = 1; i <= l1; i++){
			        for(int j = 1; j <= l2; j++){
			            f[i][j] = min(f[i-1][j] + 1, f[i][j-1] + 1);
			            f[i][j] = min(f[i][j], f[i-1][j-1] + (x[i-1] != y[j-1]));	注意, 这里是(x[i-1] != y[j-1])
			        }
			    }
			    return f[l1][l2];
			}
			int main(){
			    int n, q;
			    scanf("%d%d", &n, &q);
			    for(int i = 0; i < n; i++) scanf("%s", a[i]);
			    for(int i = 0; i < q; i++){
			        int limit;
			        scanf("%s%d", t[i], &limit);
			        int res = 0;
			        for(int j = 0; j < n; j++){
			            if(query(a[j], t[i]) <= limit) res ++;
			        }
			        cout << res << endl;
			    }
			    return 0;
			}
	66. AcWing 282. 石子合并
		1. bug
			#include <iostream>
			using namespace std;
			const int N = 310;
			int a[N], s[N], f[N][N], n;
			int main(){
			    cin >> n;
			    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
			    for(int i = 1; i <= n; i++) s[i] = s[i-1] + a[i];
			    for(int len = 2; len <= n; len++){
			        错误: for(int l = 1; len - l + 1 <= n; l++){ 你错在求的是区间长度
			        正确: for(int l = 1; l + len - 1 <= n; l++){ 我们要求的是右端点...
			            错误: int r = len - l + 1;
			            正确: int r = l + len - 1;
			            正确: f[l][r] = 1e8;
			            错误: for(int k = l; k < len - l + 1; k ++){
			            正确: for(int k = l; k < r; k ++){
			                错误: f[l][r] = 1e8; 那每次for一次k就又回到原点了
			                错误: f[l][r] = max(f[l][r], f[l][k] + f[k+1][r] + s[r] - s[l - 1]); 不是max啊
			                正确: f[l][r] = min(f[l][r], f[l][k] + f[k+1][r] + s[r] - s[l - 1]);
			            }
			        }
			    }
			    cout << f[1][n] << endl;
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;
			const int N = 310;
			int a[N], s[N], f[N][N], n;
			int main(){
			    cin >> n;
			    for(int i = 1; i <= n; i++){
			        scanf("%d", &a[i]);
			        s[i] = s[i-1] + a[i];
			    }
			    for(int i = 1; i <= n; i++)
			        for(int j = 1; j <= n; j++)
			        	错误: f[i][j] = 1e8; f[i][i] == 0, 也就是第i个元素自己是不需要有任何代价的
			            正确: if(i != j) f[i][j] = 1e8; //300 * 1000 = 3e5
			            	初始化问题:
								f[i][i] == 0, 也就是第i个元素自己是不需要有任何代价的
								但是f[i][非i], 也就是长度>=2的区间, 是有代价的
							另外, 我们遍历的区间[i,j]
								我们是先遍历小区间, 然后遍历大区间
								有种树从底部叶子节点开始, 逐层往上的感觉 
			    for(int len = 2; len <= n; len++){
			        for(int l = 1; l + len - 1 <= n; l++){
			            int r = l + len - 1;
			            for(int k = l; k < r; k++){
			                f[l][r] = min(f[l][r], f[l][k] + f[k+1][r] + s[r] - s[l-1]);
			            }
			        }
			    }
			    cout << f[1][n] << endl;
			    return 0;
			}
		2. ok
			#include <iostream>
			using namespace std;
			const int N = 310, INF = 310 * 1e4; //INF如果是 310 * 1e3就会报错, 尽可能开大一些
			int a[N], s[N], f[N][N], n;
			int main(){
			    cin >> n;
			    for(int i = 1; i <= n; i++){    //初始化前缀和, 用于计算代价
			        scanf("%d", &a[i]);
			        s[i] = s[i-1] + a[i];
			    }
			    for(int i = 1; i <= n; i++){    //初始化f, 我们dp问题一般都是从1开始
			        for(int j = 1; j <= n; j++){
			            if(i != j) f[i][j] = INF;   //f[i][i] == 0, 也就是第i个元素自己是不需要有任何代价的
			        }
			    }
			    for(int len = 2; len <= n; len ++){
			        for(int l = 1; l + len - 1 <= n; l ++){
			            for(int k = l; k < l + len - 1; k++){
			                int r = l + len - 1;
			                f[l][r] = min(f[l][r], f[l][k] + f[k+1][r] + s[r] - s[l - 1]);
			            }
			        }
			    }
			    cout << f[1][n] << endl;
			    return 0;
			}
7. 5.22
	* 67. AcWing 900. 整数划分
		0. 小总结:
			1. 求的是max, 初始化一般为0或者-INF
				题目 		min/max 		初始化
				各种背包 		max 			0
				数字三角形 	max 			-INF
				最长上升子序列 max 			f[i] = 1 / f[++len] = a[1]
				最长公共子序列 max 			0


			2. 求的是min, 初始化一般为INF{1e8}, 或者大数
				题目 		min/max 		初始化
				最短编辑距离 	min 			for(int i = 0; i <= n; i++) f[i][0] = i; //[0,n], 一共n+1个数字要遍历
			    							for(int i = 0; i <= m; i++) f[0][i] = i;

			    石子合并  	min 			for(int i = 1; i <= n; i++){    //初始化f, 我们dp问题一般都是从1开始
										        for(int j = 1; j <= n; j++){
										            if(i != j) f[i][j] = INF;   //f[i][i] == 0, 也就是第i个元素自己是不需要有任何代价的
										        	else f[i][i] = 0;
										        }
										    }
			3. 求方案数{加总}
				题目 		方法 		初始化 			状态转移
				整数划分		方案数加总 	f[0] = 1;		if(j - i >= 0) f[j] = (f[j] + f[j-i]) % mod;
		1. bug
			不知道为什么, 就是通不过
				#include <iostream>
				using namespace std;
				const int N = 1010, mod = 1e9 + 7;
				int f[N][N], n;
				int main(){
				    cin >> n;
				    for(int i = 0; i <= n; i++) f[i][0] = 1;
				    for(int i = 1; i <= n; i++){
				        for(int j = 0; j <= n; j++){
				            if(j - i >= 0) f[i][j] = (f[i-1][j] + f[i][j-i]) % mod;
				        }
				    }
				    cout << f[n][n] << endl;
				    return 0;
				}
			--
			#include <iostream>
			using namespace std;
			const int N = 1010, mod = 1e9 + 7;
			int f[N], n;
			int main(){
			    cin >> n;
			    f[0] = 1;
			    for(int i = 1; i <= n; i++){
			        for(int j = 0; j <= n; j++){
			            错误: if(j - 1 >= 0) f[j] = (f[j] + f[j-1]) % mod; 注意, 往左走i步, 因为我们的取一个i数字, 我们的总和是从j到j-i. 
			            正确: if(j - i >= 0) f[j] = (f[j] + f[j-i]) % mod;
			        }
			    }
			    cout << f[n] << endl;
			    return 0;
			}
		2. ok {总之就是用一维优化来做, 从左到右遍历}
			#include <iostream>
			using namespace std;
			const int N = 1010, mod = 1e9 + 7;
			int f[N], n;
			int main(){
			    cin >> n;
			    f[0] = 1;
			    	//的本质其实是f[0][0] f[1][0]......f[n][0] = 1: 
			    	//从 1到0 中选, 总体积恰好是0 的所有选法的"数量"是1, 也就是一个都不选的选法是1
			    	//...
			    	//从 1到n 中选, 总体积恰好是0 的所有选法的"数量"是1, 也就是一个都不选的选法是1
			    for(int i = 1; i <= n; i++){
			        for(int j = 0; j <= n; j++){
			            if(j - i >= 0) f[j] = (f[j] + f[j-i]) % mod;
			        }
			    }
			    cout << f[n] << endl;
			    return 0;
			}
	* 68. AcWing 338. 计数问题
		0. 小总结:
			1. 预处理: 5个东西
				一共几位数 d: while (n) ++ res, n /= 10;	res++: 最右侧位的计数加一, n /= 10: 将最右侧位删除
				右侧的指数: int p = pow(10, j - 1);		计算右边j-1个数字的0有多少个
				左侧数字的值: int l = n / pow(10, j);		把右边的j个数字都删掉
				右侧数字的值: int r = n % p; 				只留下右边j-1个数字
				第j位数字的值: dj = n / p % 10;			把右边的j-1个数字都删掉, 然后留下最后一个数字
			2. 思路:
				1. 如果目标数字是 i != 0
					从右到左遍历第j位
						1. 预处理得到 p, l, r, dj 
						2. 情况1: xxx = [000, abc - 1]
							无条件地计算: 1. res += l * p;
						3. 情况1: xxx = [abc]
							二选一的计算:
								1. 我们喜欢的 i < dj{i在dj大佬下面躲着}
									res += p;
								2. i == dj {注意是 else if 不是 else, 如果是else就变成 i >= dj}
									res += r + 1;
								}
				2. 如果目标数字是 i == 0
					从右到左遍历第j位, "注意第j位不包括最左边一位"
						1. 预处理得到 p, l, r, dj 
						2. 情况1: xxx = ["001", abc - 1], 注意从001开始
							无条件地计算: 1. res += (l - 1) * p;
						3. 情况1: xxx = [abc]
							二选一的计算:
								1. dj > 0	{0在dj大佬下面躲着}
									res += p;
								2. dj == 0
									res += r + 1;
			3. 其他技巧 
				1. 用前缀和思想: 
					cnt(a, x): 意思是: 求从1到a数, x这个数字的出现个数
					所以 从a到b数, x这个数字的出现个数就是 
						cnt(b, x) - cnt(a-1, x)
				2. 读入
					依旧是用int, 而不是用什么 char[]
					while(cin >> a >> b, a || b){    先读入a, b. 如果 a == 0 && b == 0就停止
		1. bug
			#include <iostream>
			#include <cmath>
			using namespace std;
			const int N = 1e8;

			int dig(int n){
			    int res = 0;
			    while(n) ++ res, n /= 10; //res++: 最右侧位的计数加一, n /= 10: 将最右侧位删除
			    return res;
			}

			int cnt0(int n){
			    int res = 0, d = dig(n);
			    for(int j = 1; j <= d - 1; j++){
			        int p = pow(10, j - 1), l = n / pow(10, j), r = n % p, dj = n / p % 10;
			        res += (l - 1) * p;
			        if(0 < dj) res += p;
			        else res += r + 1;
			    }
			    错误: 忘记写 return, 竟然也会返回一个错误值
			    正确: return res;
			}

			int cnt(int n, int i){
			    int res = 0, d = dig(n);
			    错误: for(int j = 1; j <= n; j++){
			    正确: for(int j = 1; j <= d; j++){
			        int p = pow(10, j - 1), l = n / pow(10, j), r = n % p, dj = n / p % 10;
			        res += l * p;
			        if(i < dj) res += p;
			        错误: else res += r + 1;
			        正确: else if(i == dj) res += r + 1;
			    }
			    return res;
			}

			int main(){
			    int a, b;
			    while(cin >> a >> b, a || b){    //先读入a, b. 如果 a == 0就停止
			        if(a > b) swap(a, b);
			        int res = cnt0(b) - cnt0(a - 1);
			        cout << res << " ";
			        for(int i = 1; i <= 9; i++){
			            res = cnt(b, i) - cnt(a - 1, i);
			            cout << res << " ";
			        }
			        cout << endl;
			    }
			    return 0;
			}
		2. ok{保守写法}
			# include <iostream>
			# include <cmath>
			using namespace std;
			int dgt(int n) // 计算整数n有多少位
			{
			    int res = 0;
			    while (n) ++ res, n /= 10;
			    return res;
			}
			int cnt(int n, int i) // 计算从1到n的整数中数字i出现多少次 
			{
			    int res = 0, d = dgt(n);
			    for (int j = 1; j <= d; ++ j) // 从右到左第j位上数字i出现多少次
			    {
			        // l和r是第j位左边和右边的整数 (视频中的abc和efg); dj是第j位的数字
			        int p = pow(10, j - 1), l = n / pow(10, j), r = n % p, dj = n / p % 10;
			        // 1. 视频中xxx = [000, abc - 1])的情况
			        res += l * p;  
			        // 2. 视频中xxx = abc 的情况
			        if(i < dj) res += p; //{视频中xxx = abc, yyy = [0, 999]共1000个 的情况}
			        else if (i == dj) res += r + 1; //{视频中xxx = abc, yyy = [0, edg] 的情况}
			    }
			    return res;
			}
			int cnt0(int n) // 计算从1到n的整数中数字0出现多少次 
			{
			    int res = 0, d = dgt(n);
			    for (int j = 1; j <= d - 1; ++ j) // 从右到左第j位上数字i出现多少次
			    {
			        // l和r是第j位左边和右边的整数 (视频中的abc和efg); dj是第j位的数字
			        // 这里我们因为 j <= d - 1; 所以保证了左侧还剩一位数, 所以 l != 0.
			        int p = pow(10, j - 1), l = n / pow(10, j), r = n % p, dj = n / p % 10;
			        //1. 视频中xxx = [001, abc - 1]的情况, 注意xxx不能为000, 所以l-1
			        res += (l - 1) * p;  
			        //2. 视频中xxx = abc 的情况
			        if(0 < dj) res += p; //{视频中xxx = abc, yyy = [0, 999]共1000个 的情况}
			        else res += r + 1; //{视频中xxx = abc, yyy = [0, edg] 的情况}
			    }
			    return res;
			}
			int main()
			{
			    int a, b;
			    while (cin >> a >> b , a || b)
			    {
			        if (a > b) swap(a, b);
			        cout << cnt0(b) - cnt0(a - 1) << ' ';
			        for (int i = 1; i <= 9; ++ i) cout << cnt(b, i) - cnt(a - 1, i) << ' ';
			        cout << endl;
			    }
			    return 0;
			}
			--{很顺}
			#include <iostream>
			#include <cmath>
			using namespace std;
			const int N = 1e8 + 10;
			int a, b;

			int dig(int n){
			    int res = 0;
			    while(n) ++res, n /= 10;
			    return res;
			}
			int cnt0(int n){
			    int res = 0, d = dig(n);
			    for(int j = 1; j <= d - 1; j++){
			        int p = pow(10, j - 1), l = n / pow(10, j), r = n % p, dj = n / p % 10;
			        res += (l - 1) * p;
			        if(dj) res += p;
			        else res += r + 1;
			    }
			    return res;
			}
			int cnt(int n, int i){
			    int res = 0, d = dig(n);
			    for(int j = 1; j <= d; j++){
			        int p = pow(10, j - 1), l = n / pow(10, j), r = n % p, dj = n / p % 10;
			        res += l * p;
			        if(i < dj) res += p;
			        else if(i == dj) res += r + 1;
			    }
			    return res;
			}
			int main(){
			    while(cin >> a >> b, a || b){
			        if(a > b) swap(a, b);
			        int res = cnt0(b) - cnt0(a - 1);
			        cout << res << " ";
			        for(int i = 1; i <= 9; i++){
			            res = cnt(b, i) - cnt(a - 1, i);
			            cout << res << " ";
			        }
			        cout << endl;
			    }
			    return 0;
			}
	* 69. AcWing 291. 蒙德里安的梦想
		1. bug
			#include <iostream>
			#include <vector>
			#include <cstring>
			using namespace std;
			错误: M = 2 ^ 11 + 10; 这里的^是异或运算啊亲
			正确: const int N = 15, M = 1 << N;
			错误2次: int f[N][M]; 如果是12*12的矩阵f的值会很大,会溢出为负值
			正确: long long f[N][M];
			int n, m;
			bool st[M];
			错误: vector<vector<int>> state;
			正确: vector<vector<int>> state(M);	要预先开好大小

			void prep(int n){
			    //预处理st[M];
			    memset(st, false, sizeof st);	 因为我们有很多个矩阵, 每个矩阵的行数n不同
			    for(int s = 0; s < 1 << n; s ++){
			    	错误: bool isvalid = false;
			        正确: bool isvalid = true;
			        int cnt = 0;
			        for(int i = 0; i < n; i++){
			            if(s >> i & 1){
			                if(cnt & 1){
			                    isvalid = false;
			                    break;
			                }
			            }else{
			                cnt++;
			            }
			        }
			        if(cnt & 1) isvalid = false;
			        st[s] = isvalid;
			    }
			    
			    //预处理state[j] = k;
			    for(int s = 0; s < 1 << n; s ++){
			        state[s].clear();			 因为我们有很多个矩阵, 每个矩阵的行数n不同
			        for(int k = 0; k < 1 << n; k++){
			            if((s & k) == 0 && st[s | k]) state[s].push_back(k);
			        }
			    }
			}

			int main(){
			    错误: while(cin >> n >> m";" n || m){ 
			    正确: while(cin >> n >> m, n || m){ 
			        prep(n);
			        错误2次: 忘写了memset
			        正确: memset(f, 0, sizeof f); 因为我们有很多个矩阵, 每个矩阵的行数n不同
			        f[0][0] = 1;
			        for(int i = 1; i <= m - 1; i++){
			            for(int s = 0; s < 1 << n; s++){
			                for(int k : state[s]){
			                    f[i][s] += f[i-1][k];
			                }
			            }
			        }
			        for(int k : state[0]){
			            错误: f[m][0] = f[m-1][k];
			            正确: f[m][0] += f[m-1][k];
			        }
			        cout << f[m][0] << endl;
			    }
			}
		2. ok
			#include <iostream>
			#include <vector>
			#include <cstring>
			using namespace std;
			const int N = 13, M = 1 << N;
			long long f[N][M];
			bool st[M];
			vector<vector<int>> state(M);
			int n, m;

			void prep(int n){
			    //预处理st[M]
			    memset(st, false, sizeof st);
			    for(int s = 0; s < 1 << n; s++){
			        bool isvalid = true;
			        int cnt = 0;
			        for(int i = 0; i < n ; i++){
			            if(s >> i & 1){
			                if(cnt & 1){
			                    isvalid = false;
			                    break;
			                }
			            }else cnt ++;
			        }
			        if(cnt & 1) isvalid = false;
			        st[s] = isvalid;
			    }
			    
			    //预处理state[j] = k; 其中k是j的左侧的一列 
			    for(int j = 0 ; j < 1 << n; j++){
			        state[j].clear();
			        for(int k = 0; k < 1 << n; k++){
			            if((j & k) == 0 && st[j | k]) state[j].push_back(k);
			        }
			    }
			    return;
			}

			int main(){
			    while(cin >> n >> m, n || m){
			        prep(n);
			        memset(f, 0, sizeof f);
			        f[0][0] = 1;
			        for(int i = 1; i <= m; i++){
			            if(i < m){
			                for(int s = 0; s < 1 << n; s ++){
			                    for(auto k : state[s]){
			                        f[i][s] += f[i-1][k];
			                    }
			                }
			            }else{
			                for(auto k : state[0]){
			                    f[m][0] += f[m-1][k];
			                }
			            }
			        }
			        cout << f[m][0] << endl;
			    }
			    return 0;
			}
			--
			#include <iostream>
			#include <vector>
			#include <cstring>
			using namespace std;
			const int N = 12, M = 1 << N;
			long long f[N][M]; //N列, 每列M个状态
			bool st[M]; //状态 j | k 的合法性
			vector<vector<int>> state(M); //M个状态需要记录合法的上一个状态
			int n, m;

			void prep(int n){
			    memset(st, false, sizeof st);
			    for(int s = 0; s < 1 << n; s++){ //既然是准备st, 就要遍历每个状态
			        bool isvalid = true;
			        int cnt = 0; 
			        for(int i = 0; i < n; i++) //从状态的最后一位开始判断 
			        {
			            if(s >> i & 1){     //遇到1
			                if(cnt & 1){    //是否是奇数
			                    isvalid = false;
			                    break;
			                }
			            }else cnt ++;
			        }
			        if(cnt & 1) isvalid = false;
			        st[s] = isvalid;
			    }
			    
			    for(int j = 0; j < 1 << n; j++){        //既然是准备state, 就要遍历每个状态
			        state[j].clear();
			        for(int k = 0; k < 1 << n; k++){    //要遍历左边一列的每一个状态
			            if((j & k) == 0 && st[j | k]) state[j].push_back(k);
			        }
			    }
			    return;
			}

			int main(){
			    while(cin >> n >> m, n || m){
			        prep(n); //准备st和state
			        memset(f, 0, sizeof f);
			        f[0][0] = 1;
			        for(int i = 1; i < m; i++){          //从第2列{i==1}开始
			            for(int s = 0; s < 1 << n; s++){ //看所有的状态
			                for(auto k : state[s]) f[i][s] += f[i-1][k];    //s状态可以从k状态转移过来 
			            }
			        }
			        for(auto k : state[0]) f[m][0] += f[m-1][k];
			        cout << f[m][0] << endl;
			    }
			    return 0;
			}
			--
			#include <iostream>
			#include <vector>
			#include <cstring>
			using namespace std;
			const int N = 12, M = 1 << N;
			long long f[N][M];
			bool st[M];
			vector<vector<int>> state(M);
			int n, m, alls;	

			void prep(int n){
				错误: int alls = 1 << n; 这样alls就是局部变量, 全局变量alls就一直是0了
			    正确: alls = 1 << n;
			    //st[s]
			    memset(st, false, sizeof st);
			    for(int s = 0; s < alls; s ++){
			        bool isvalid = true;
			        int cnt = 0;
			        for(int i = 0; i < n; i++){
			            if(s >> i & 1){
			                if(cnt & 1){
			                    isvalid = false;
			                    break;
			                }
			            }else cnt++;
			        }
			        if(cnt & 1) isvalid = false;
			        st[s] = isvalid;
			    }
			    
			    //state[j] = k;
			    for(int j = 0; j < alls; j ++){
			        state[j].clear();
			        for(int k = 0; k < alls ; k++){
			            if((j & k) == 0 && st[j | k]) state[j].push_back(k);
			        }
			    }
			    return;
			}

			int main(){
			    while(cin >> n >> m, n || m){
			        prep(n);
			        memset(f, 0, sizeof f);
			        f[0][0] = 1;
			        for(int i = 1; i < m; i++){
			            for(int s = 0; s < alls; s++){
			                for(int k : state[s]) f[i][s] += f[i-1][k];
			            }
			        }
			        for(int k : state[0]){
			            f[m][0] += f[m-1][k];
			        }
			        cout << f[m][0] << endl;
			    }
			    return 0;
			}
	* 70. AcWing 91. 最短Hamilton路径
		1. bug 
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 21, M = 1 << N; 错误: INF = 1e9;
			int d[N][N], f[M][N];
			int n;
			int main(){
			    cin >> n;
			    for(int i = 0 ; i < n; i++){
			        for(int j = 0; j < n; j++){
			            cin >> d[i][j];
			        }
			    }
			    错误: memset(f, INF, sizeof f); 这个数目还是不够 
			    正确: memset(f, 0x3f, sizeof f); 保守的做法 
			    f[1][0] = 0;
			    for(int s = 0; s < 1 << n; s ++){
			        for(int i = 0; i < n; i++){
			            if(s >> i & 1){
			                for(int j = 0 ; j < n; j++){
			                    int last = s - (1 << i);
			                    if(last >> j & 1){	//上一个状态: (s - (1 << i)), 如果走了第j步
			                        f[s][i] = min(f[s][i], f[last][j] + d[j][i]);
			                    }
			                }
			            }
			        }
			    }
			    cout << f[(1 << n) - 1][n - 1] << endl;
			    return 0;
			}
		2. ok
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 21, M = 1 << N;	//21个要走的地点, 状态是 1 << 21
			int d[N][N], f[M][N], n;
			int main(){
			    cin >> n;
			    for(int i = 0 ; i < n; i++)
			        for(int j = 0 ; j < n; j++)
			            cin >> d[i][j];
			    memset(f, 0x3f, sizeof f);
			    f[1][0] = 0;	//状态000..001 是只走了第0个点, 终点是第0个点, 距离就是0
			    for(int s = 0 ; s < 1 << n; s ++){
			        for(int i = 0; i < n ; i++){	//从第0个点出发, 当前的走到的点是i
			            if(s >> i & 1){	
			                for(int j = 0 ; j < n; j++){	/i的上一个点是j
			                    int last = s - (1 << i);
			                    if(last >> j & 1){	//上一个状态: (s - (1 << i)), 如果走了第j步
			                        f[s][i] = min(f[s][i], f[last][j] + d[j][i]);
			                        				不走j  	走j, 那就是上一步的状态是没走过i: s - (1 << i)
			                    }
			                }
			            }
			        }
			    }
			    cout << f[(1 << n) - 1][n - 1] << endl;
			    return 0;
			}
			--
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 21, M = 1 << N; //21个要走的地点, 状态是 1 << 21
			int d[N][N], f[M][N], n;
			int main(){
			    cin >> n;
			    for(int i = 0; i < n; i++){
			        for(int j = 0; j < n; j++) cin >> d[i][j];
			    }
			    memset(f, 0x3f, sizeof f);
			    f[1][0] = 0; //状态000..001 是只走了第0个点, 终点是第0个点, 距离就是0
			    for(int s = 0; s < 1 << n; s ++){
			        for(int i = 0; i < n; i++){ //从第0个点出发, 当前的走到的点是i
			            if(s >> i & 1){
			                for(int j = 0; j < n; j++) {//i的上一个点是j
			                    int last = s - (1 << i);
			                    if(last >> j & 1){	//上一个状态: (s - (1 << i)), 如果走了第j步
			                        f[s][i] = min(f[s][i], f[last][j] + d[j][i]);
			                    }
			                }
			            }
			        }
			    }
			    cout << f[(1 << n) - 1][n - 1] << endl;
			    return 0;
			}
			--
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 21, M = 1 << N;
			int d[N][N], f[M][N];
			int n;
			int main(){
			    cin >> n;
			    for(int i = 0 ; i < n; i++){
			        for(int j = 0 ; j < n; j++)
			            cin >> d[i][j];
			    }
			    memset(f, 0x3f, sizeof f); //因为求最短, 所以初始化正无穷
			    f[1][0] = 0;
			    for(int s = 0; s < 1 << n; s ++){
			        for(int i = 0; i < n; i++){
			            if(s >> i & 1){
			                for(int j = 0 ; j < n; j++){
			                    int last = s - (1 << i);
			                    if(last >> j & 1){	//上一个状态: (s - (1 << i)), 如果走了第j步
			                        f[s][i] = min(f[s][i], f[last][j] + d[j][i]);
			                        				不走j  	走j, 那就是上一步的状态是没走过i: s - (1 << i)
			                    }
			                        				
			                }
			            }
			        }
			    }
			    cout << f[(1 << n) - 1][n - 1] << endl;
			    return 0;
			}
	* 71. AcWing 285. 没有上司的舞会
		1. bug 
		2. ok {很顺}
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 6010;
			int h[N], e[N], ne[N], ind;
			int ha[N], n, f[N][2];
			bool hasf[N];

			void add(int a, int b){
			    e[ind] = b, ne[ind] = h[a], h[a] = ind ++;
			}

			void dfs(int u){
			    f[u][1] = ha[u];
			    f[u][0] = 0;		其实这一句可以不写, 因为本身全局变量就是0
			    for(int i = h[u]; ~i; i = ne[i]){
			        int v = e[i];
			        dfs(v);
			        	我之前的疑惑: 为什么先dfs到最底层叶子
			        	答案:
			        		不然呢, 如果你写成 
			        			f[u][1] += f[v][0];
			        			f[u][0] += max(f[v][1], f[v][0]);
			        			dfs(v);
			        		那这样你的f[j][0], f[j][1]的值都还不知道啊
			        f[u][1] += f[v][0];
			        	当前u结点选，子结点一定不能选: f[u][1]=∑(f[si,0])
			        f[u][0] += max(f[v][1], f[v][0]);
			        	当前u结点不选，子结点可选可不选, 具体是选还是不选, 看哪个大: f[u][0]=∑max(f[si,0],f[si,1])
			    }
			}

			int main(){
			    memset(h, -1, sizeof h);
			    cin >> n;
			    for(int i = 1; i <= n; i++){
			        scanf("%d", &ha[i]);
			    }
			    for(int i = 0; i < n - 1; i++){
			        int s, f;
			        scanf("%d%d", &s, &f);
			        add(f, s);
			        hasf[s] = true;
			    }
			    
			    int root = 1;
			    while(hasf[root]) root++;
			    
			    dfs(root);
			    cout << max(f[root][1], f[root][0]) << endl;
			}
			--
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 6010;
			int h[N], e[N], ne[N], ind;
			int ha[N], f[N][2], n;
			bool hasf[N];

			void add(int a, int b){
			    e[ind] = b, ne[ind] = h[a], h[a] = ind ++;
			}

			void dfs(int u){
			    f[u][1] = ha[u], f[u][0] = 0;
			    for(int i = h[u]; ~i; i = ne[i]){
			        int v = e[i];
			        dfs(v); 
			        f[u][1] += f[v][0];
			        f[u][0] += max(f[v][1], f[v][0]);
			    }
			    return;
			}
			int main(){
			    memset(h, -1, sizeof h);
			    cin >> n;
			    for(int i = 1; i <= n; i++) cin >> ha[i];
			    for(int i = 0; i < n - 1; i++){
			        int s, f;
			        cin >> s >> f;
			        add(f, s);
			        hasf[s] = true;
			    }
			    int root = 1;
			    while(hasf[root]) root++;
			    dfs(root);
			    cout << max(f[root][1], f[root][0]) << endl;
			    return 0;
			}
	* 72. AcWing 901. 滑雪
		1. bug 
		2. ok{很顺}
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 310;
			int g[N][N], f[N][N]; //f[i][j]是从{i,j}点出发, 能滑的最长长度 
			int n, m;
			int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

			其实是dfs深搜算法, 一条路到底 
			int dfs(int x, int y) //返回f[x][y]: 从{x, y}点出发, 能滑的最长长度
			{
			    if(f[x][y] != -1) return f[x][y];
			    	判断 f[x][y]是否已经被计算过, 计算过就不是==-1了, 计算过就返回 
			    	我的疑惑, 为什么f[x][y]被计算过就不能再被计算了 
			    		理解:
			    			如果 f[x][y]被计算过, 那么它就只能为其他人贡献自己的值 f[x][y], 而不能被其他人在更新成最优值 
			    			因为如果 f[x][y]被计算过, 那么这个 f[x][y]就肯定是最优值
			    				为什么, 因为这是深搜, 只有遍历完整个路径, 才会计算出 f[x][y]
			    				这个路径的终点, 要么就是终点的是一个海拔洼地, 要么处于四个边界的点
			    		理解2:
			    			这里是因为信息的传导是单向的, 也就是一个 dp(x2, y2)能调用 dp(x1, y1)是因为 {x2, y2}的点的高度更高
			    			也就是只有海拔更高的点 dp(), 能调用海拔更低的点的 dp()
			    			调用这个dp函数的上一个dp函数, 上一个dp函数对应的点海拔肯定比这个dp函数对应的点的海拔高
			    f[x][y] = 1; // 如果哪里都走不了, 起码路径长度也是1. 其实这个也是递归到底的情况
			    for(int i = 0; i < 4; i++){
			        int a = x + dx[i], b = y + dy[i];
			        if(a >= 1 && a <= n && b >= 1 && b <= m && g[a][b] < g[x][y]){	我们要判断是否出界, 并且海拔必须是减少的
			            写法1:
				            f[a][b] = dfs(a, b);	dp(a, b): 如果点{a,b}的四周都走不通, dp(a, b)返回的给我们的是v==1
				            if(f[a][b] + 1 > f[x][y]) f[x][y] = f[a][b] + 1;
				        写法2:
				            int fab = dfs(a, b);
				            if(fab + 1 > f[x][y]) f[x][y] = fab + 1;
			        }
			    }
			    return f[x][y];
			}

			int main(){
			    cin >> n >> m;
			    for(int i = 1; i <= n; i++)
			        for(int j = 1; j <= m; j++)
			            cin >> g[i][j];
			    memset(f, -1, sizeof f);	因为求的是max, 所以初始化为-1
			    int res = 0;
			    for(int i = 1; i <= n; i++){
			        for(int j = 1; j <= m; j++){
			            res = max(res, dfs(i, j));	每个点都试一试, 总有一个点返回的路径是最长的 
			        }
			    }
			    cout << res << endl;
			    return 0;
			}
			--
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 310;
			int g[N][N], f[N][N], n, m;
			int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

			int dfs(int x, int y) //返回f[x,y]: 从{x,y}出发的最长长度
			{
			    if(f[x][y] != -1) return f[x][y];
			    f[x][y] = 1; //起码长度是1
			    for(int i = 0; i < 4; i++){
			        int a = x + dx[i], b = y + dy[i];
			        if(a >= 1 && a <= n && b >= 1 && b <= m && g[a][b] < g[x][y]){
			            int fab = dfs(a, b);
			            if(fab + 1 > f[x][y]) f[x][y] = fab + 1;
			        }
			    }
			    return f[x][y];
			}
			int main(){
			    cin >> n >> m;
			    for(int i = 1; i <= n; i++)
			        for(int j = 1; j <= m; j++)
			            cin >> g[i][j];
			    memset(f, -1, sizeof f);
			    int res = 0;
			    for(int i = 1; i <= n; i++)
			        for(int j = 1; j <= m; j++)
			            res = max(res, dfs(i, j));
			    cout << res << endl;
			    return 0;
			}
			--
			你如果要弄个清楚, 可以打印一下遍历的深度:
				#include <cstring>
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 310;

				int n, m;
				int g[N][N];
				int f[N][N];

				int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 

				int dp(int x, int y, int dep)
				{
				    for(int i = 0; i < dep; i++){
				        cout << "-*";
				    }
				    cout << "{" <<  x << ", " << y << "}:" << g[x][y] << " " << f[x][y] << endl;
				    
				    int &v = f[x][y];
				    if (v != -1) return v; 
				    v = 1;
				    for (int i = 0; i < 4; i ++ )
				    {
				        int a = x + dx[i], b = y + dy[i];
				        if (a >= 1 && a <= n && b >= 1 && b <= m && g[x][y] > g[a][b]) 
				            v = max(v, dp(a, b, dep + 1) + 1);
				    }

				    return v;
				}

				int main()
				{
				    scanf("%d%d", &n, &m);
				    for (int i = 1; i <= n; i ++ )
				        for (int j = 1; j <= m; j ++ )
				            scanf("%d", &g[i][j]);

				    memset(f, -1, sizeof f);

				    int res = 0;
				    for (int i = 1; i <= n; i ++ )
				        for (int j = 1; j <= m; j ++ )
				            res = max(res, dp(i, j, 1));

				    printf("%d\n", res);

				    return 0;
				} 
					题目样例的输出:
						-*{1, 1}:1 -1
						-*{1, 2}:2 -1
						-*-*{1, 1}:1 1
						-*{1, 3}:3 -1
						-*-*{1, 2}:2 2
						-*{1, 4}:4 -1
						-*-*{1, 3}:3 3
						-*{1, 5}:5 -1
						-*-*{1, 4}:4 4
						-*{2, 1}:16 -1	这里就是找到一条长长的路径, 当f[2][1]也就是16这个点更新好后, 就是最优值, 因为这条长长的路径是找到底了 
						-*-*{1, 1}:1 1
						-*-*{3, 1}:15 -1
						-*-*-*{4, 1}:14 -1
						-*-*-*-*{5, 1}:13 -1
						-*-*-*-*-*{5, 2}:12 -1
						-*-*-*-*-*-*{5, 3}:11 -1
						-*-*-*-*-*-*-*{5, 4}:10 -1
						-*-*-*-*-*-*-*-*{5, 5}:9 -1
						-*-*-*-*-*-*-*-*-*{4, 5}:8 -1
						-*-*-*-*-*-*-*-*-*-*{3, 5}:7 -1
						-*-*-*-*-*-*-*-*-*-*-*{2, 5}:6 -1
						-*-*-*-*-*-*-*-*-*-*-*-*{1, 5}:5 5 	这个就是路径的底部, 然后路径长度: 5 + 1 + 1 + ... + 1 = 16, 最后 f[2][1] = 16
						-*{2, 2}:17 -1
						-*-*{1, 2}:2 2
						-*-*{2, 1}:16 16
						-*{2, 3}:18 -1
						-*-*{1, 3}:3 3
						-*-*{2, 2}:17 17
						-*{2, 4}:19 -1
						-*-*{1, 4}:4 4
						-*-*{2, 5}:6 6
						-*-*{2, 3}:18 18
						-*{2, 5}:6 6
						-*{3, 1}:15 15
						-*{3, 2}:24 -1
						-*-*{2, 2}:17 17
						-*-*{4, 2}:23 -1
						-*-*-*{4, 3}:22 -1
						-*-*-*-*{4, 4}:21 -1
						-*-*-*-*-*{3, 4}:20 -1
						-*-*-*-*-*-*{2, 4}:19 19
						-*-*-*-*-*-*{3, 5}:7 7
						-*-*-*-*-*{4, 5}:8 8
						-*-*-*-*-*{5, 4}:10 10
						-*-*-*-*{5, 3}:11 11
						-*-*-*{5, 2}:12 12
						-*-*-*{4, 1}:14 14
						-*-*{3, 1}:15 15
						-*{3, 3}:25 -1
						-*-*{2, 3}:18 18
						-*-*{3, 4}:20 20
						-*-*{4, 3}:22 22
						-*-*{3, 2}:24 24
						-*{3, 4}:20 20
						-*{3, 5}:7 7
						-*{4, 1}:14 14
						-*{4, 2}:23 23
						-*{4, 3}:22 22
						-*{4, 4}:21 21
						-*{4, 5}:8 8
						-*{5, 1}:13 13
						-*{5, 2}:12 12
						-*{5, 3}:11 11
						-*{5, 4}:10 10
						-*{5, 5}:9 9
						25
8. 5.25
	73. AcWing 905. 区间选点
		0. 题意:
			给定 N 个闭区间 [ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。
			输出选择的点的最小数量。
			位于区间端点上的点也算作区间内。
		1. bug
		2. ok{很顺}
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 1e5 + 10;
			struct Edge{
			    int l, r;
			    bool operator<(const Edge &e) const{
			        return r < e.r;
			    }
			}edges[N];
			int n;
			int main(){
			    scanf("%d", &n);
			    for(int i = 0 ; i < n; i++){
			        int a, b;
			        scanf("%d%d", &a, &b);
			        edges[i] = {a, b};
			    }
			    sort(edges, edges + n);
			    int ed = edges[0].r, res = 1;	 //当最小的右端点当做支撑
			    for(int i = 1; i < n; i++){
			        if(ed < edges[i].l){	//如果ed支撑不了了
			            res ++;
			            ed = edges[i].r; 
			        }
			        //如果 edges[i].l < ed, 说明我们的ed还能支撑, 所以没必要res++, 因为我们希望res尽可能小
			        	// 注意如果 edges[i].l < ed, 不能 ed = edges[i].r; 因为一旦 ed = edges[i].r 就要 res++
			    }
			    cout << res << endl;
			    return 0;
			}
			--
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 1e5 + 10;
			struct Edge{
			    int l, r;
			    bool operator<(const Edge &e) const{
			        return r < e.r;
			    }
			}edges[N];
			int main(){
			    int n;
			    scanf("%d", &n);
			    for(int i = 0; i < n; i++){
			        int a, b;
			        scanf("%d%d", &a, &b);
			        edges[i] = {a, b};
			    }
			    sort(edges, edges + n);
			    int ed = edges[0].r, res = 1; 
			    for(int i = 1; i < n; i++){
			        if(ed < edges[i].l) {
			            res ++;
			            ed = edges[i].r;
			        }
			    }
			    cout << res << endl;
			    return 0;
			}
	74. AcWing 908. 最大不相交区间数量
		0. 题意:
			上一题:
				给定 N 个闭区间 [ai,bi]，请你在数轴上选择尽量少的点，使得每个区间内至少包含一个选出的点。
				输出选择的点的最小数量。
				位于区间端点上的点也算作区间内。
			本题: {有种希望区间互斥的感觉}
				给定 N 个闭区间 [ai,bi]，请你在数轴上选择若干区间，使得选中的区间之间互不相交（包括端点）.
				输出可选取区间的最大数量
		1. bug
		2. ok{完全可以把上一题的代码复制到这道题...}
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 1e5 + 10;
			struct Edge{
			    int l, r;
			    bool operator<(const Edge &e) const{
			        return r < e.r;
			    }
			}edges[N];
			int main(){
			    int n;
			    scanf("%d", &n);
			    for(int i = 0; i < n; i++){
			        int a, b;
			        scanf("%d%d", &a, &b);
			        edges[i] = {a, b};
			    }
			    sort(edges, edges + n);
			    int ed = edges[0].r, res = 1; //当最小的右端点当做支撑
			    for(int i = 1; i < n; i++){
			        if(ed < edges[i].l) {//如果ed支撑不了了
			            res ++;
			            ed = edges[i].r;
			        }
			    }
			    cout << res << endl;
			    return 0;
			}
	75. AcWing 906. 区间分组
		1. bug
			0. 传统做法
				#include <iostream>
				#include <algorithm>
				#include <queue>
				using namespace std;
				const int N = 1e5 + 10;
				struct Edge{
				    int l, r;
				    bool operator<(const Edge &e) const{
				    	错误: return l < e.r;
				        正确: return l < e.l;
				    }
				}edges[N];
				int n;
				int main(){
				    cin >> n;
				    for(int i = 0; i < n; i++){
				        int a, b;
				        cin >> a >> b;
				        edges[i] = {a, b};
				    }
				    sort(edges, edges + n);
				    priority_queue<int, vector<int>, greater<int>> heap;
				    for(int i = 0; i < n; i++){
				        auto ne = edges[i];
				        if(heap.empty()) heap.push(ne.r);
				        错误: else if(ne.l < heap.top()) heap.push(ne.r);
				        正确: else if(ne.l <= heap.top()) heap.push(ne.r);
				        else{
				            heap.pop();
				            heap.push(ne.r);
				        }
				    }
				    cout << heap.size() << endl;
				    return 0;
				}
			1. 教室做法{很顺}
		2. ok 
			0. 传统做法
				#include <iostream>
				#include <algorithm>
				#include <queue>
				using namespace std;
				const int N = 1e5 + 10;
				struct Edge{
				    int l, r;
				    bool operator<(const Edge &e) const{
				        return l < e.l;
				    }
				}edges[N];
				int n;
				int main(){
				    cin >> n;
				    for(int i = 0; i < n; i++){
				        int a, b;
				        cin >> a >> b;
				        edges[i] = {a, b};
				    }
				    sort(edges, edges + n);	上课时间从小到大排序
				    priority_queue<int, vector<int>, greater<int>> heap;	heap是最小堆, 返回最早下课的课, 所以插入的是下课时间 
				    heap.push(edges[0].r); 			插入第一节课的下课时间
				    for(int i = 1; i < n; i++){
				    	if(heap.top() < edges[i].l){    下一个上课时间{edges[i].l} 晚于 我们的最早下课时间{heap.top()}, 不需要新教室
				            heap.pop();
				            heap.push(edges[i].r);		我们就可以等那节课下课后, 再上课, 所以不需要新教室, 所以pop后再push. 此时heap的size还是1
				        }else{                          下一个上课时间 早于等于 我们的最早下课时间, 需要新教室
				            heap.push(edges[i].r);
				            	如果下一个课的上课时间, 早或者等于, 第一个要下课的课{heap.top()是最早下课的课}. 
				            	注意等于也算, 也就是一个课的下课时间要严格大于一个课的上课时间
				        		那么我们就要多开一个新的教室, 然后把这个课的下课时间插入 heap. 此时heap的size是2
				        }
				    }
				    cout << heap.size() << endl;	
				    	我觉得很神奇的地方就是heap的size记录的是历史上最大的教室数
				    	为什么? 
				    		1. 我们的size是只增或者不变, 但是绝对不减的
				    			因为:
				    				1. 要么push{size增加}
				    				2. 如果pop就一定有push{size不变}
				    		2. 具体的样例我没想到
				    return 0;
				}
				--
				#include <iostream>
				#include <algorithm>
				#include <queue>
				using namespace std;
				const int N = 1e5 + 10;
				struct Edge{
				    int l, r;
				    bool operator<(const Edge &e) const{
				        return l < e.l;
				    }
				}edges[N];
				int n;
				int main(){
				    scanf("%d", &n);
				    for(int i = 0; i < n; i++){
				        int a, b;
				        scanf("%d%d", &a, &b);
				        edges[i] = {a, b};
				    }
				    sort(edges, edges + n); 			上课时间排序
				    priority_queue<int, vector<int>, greater<int>> heap;
				    heap.push(edges[0].r);  			最早下课的下课时间
				    for(int i = 1; i < n; i++){
				        if(heap.top() < edges[i].l){    下一个上课时间 晚于 我们的最早下课时间, 不需要新教室
				            heap.pop();
				            heap.push(edges[i].r);
				        }else{                          下一个上课时间 早于等于 我们的最早下课时间, 需要新教室
				            heap.push(edges[i].r);
				        }
				    }
				    cout << heap.size() << endl;
				    return 0;
				}
			1. 至少需要几个教室
				求最大”区间厚度的问题。
				大家可以把这个问题想象成活动安排问题
				有若干个活动，第i个活动开始时间和结束时间是[SiSi,fifi]，同一个教室安排的活动之间不能交叠，求要安排所有活动，少需要几个教室？
				有时间冲突的活动不能安排在同一间教室，与该问题的限制条件相同，即最小需要的教室个数即为该题答案。
				我们可以把所有开始时间和结束时间排序，遇到开始时间就把需要的教室加1，遇到结束时间就把需要的教室减1,在一系列需要的教室个数变化的过程中，峰值就是多同时进行的活动数，也是我们至少需要的教室数。
	
				#include <iostream>
				#include <algorithm>
				using namespace std;
				const int N = 1e5 + 10;
				int a[N * 2], ind, n;
				int main(){
				    scanf("%d", &n);
				    for(int i = 0; i < n; i++){
				        int l, r;
				        scanf("%d%d", &l, &r);
				        a[ind ++] = l * 2;
				        a[ind ++] = r * 2 + 1; 一定是+1, 不是-1
				        	这么做的好处:
				        		1. 离散化处理并不会影响上下课时间的顺序, 
				        			题目保证: l <= r
				        			同时: l*2 < r*2 + 1, 所以我们保证在sort之后, 某一堂课的上课时间是在下课时间之前
				        		2. 如果一堂课的下课时间r1 == 另一堂课的上课时间l2, 经过我们的离散化处理后, 上课时间 早于 下课时间, 所以依旧可以保证我们会开新的教室
				        			因为上课时间是 l2 * 2,
				        			下课时间是 r1 * 2 + 1, 
				        			所以我们 l2 * 2 < r1 * 2 + 1, 依旧会开新教室
				        		3. 就是离散化, 两个格子代表一个时间t, 左边的格子代表上课为t, 右边的格子代表下课为t
				    }
				    sort(a, a + n + n); 最精华的一句就在这里了, 去掉了就都错了
				    	如果去掉了这一句, 全错了, 因为去掉这一句, a[i]肯定是一个奇数一个偶数的来 
				    int t = 0, res = 0;
				    for(int i = 0; i < ind; i++){	
				        if(a[i] & 1) t--;		如果是奇数, 说明是下课, 且之前一定有上课才会有下课.
				        else t++;				偶数, 说明是上课
				        	我们的t:
				        		1. 增加: 某堂课上课
				        		2. 减少: 某堂课下课
				        		3. 肯定是先增后减, 最后减到0
				        			例如调试的打印t:
				        				1 2 3 4 3 4 5 6 7 8 9 10 9 10 11 10 11 12 13 14 15 16 15 16 15 14 13 12 11 10 11 10 11 12 11 10 11 12 11 10 11 10 11 10 9 8 9 10 9 8 9 8 7 6 5 4 3 2 1 0
				        res = max(res, t); 		记录最大的t
				    }
				    cout << res << endl;
				    return 0;
				}
				--
				#include <iostream>
				#include <algorithm>
				using namespace std;
				const int N = 1e5 + 10;
				int a[N * 2], ind, n;
				int main(){
				    cin >> n;
				    for(int i = 0; i < n; i++){
				        int l, r;
				        cin >> l >> r;
				        a[ind++] = l * 2;
				        a[ind++] = r * 2 + 1;
				    }
				    sort(a, a + n + n);
				    int t = 0, res = 0;
				    for(int i = 0; i < ind; i++){
				        if(a[i] & 1) t--;
				        else t++;
				        res = max(res, t);
				    }
				    cout << res << endl;
				    return 0;
				}
	* 76. AcWing 907. 区间覆盖
		0. 小总结:
			之前的3道题, 我都是先将排序后的第一个区间push到我们的heap, 或者 int ed = edges[0].r, 然后从第二个区间开始判断
			但是这道题, 我没有特别对待第一个区间, 为什么?
				因为前3道题, 我们都是自由的玩儿区间
				可是这道题, 是已知st, ed. 所以我们不能擅自用第一个区间来自己制造st, ed
		1. bug
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 1e5 + 10;
			struct Edge{
			    int l, r;
			    bool operator<(const Edge &e) const{
			        return l < e.l;
			    }
			}edges[N];
			int st, ed, n;
			int main(){
			    cin >> st >> ed;
			    cin >> n;
			    for(int i = 0; i < n; i++){
			        int l, r;
			        cin >> l >> r;
			        edges[i] = {l, r};
			    }
			    sort(edges, edges + n);
			    int tempr = -2e9, res = 0;
			    错误: bool success = true;
			    	因为假如说下面的 for()是全部执行完, 没有经过什么break, 说明其实是没有成功的
			    	为什么, 因为成功的标志是 if(tempr >= ed) 为真.
			    正确: bool success = false;
			    for(int i = 0; i < n; i++){
			        int j = i;
			        while(j < n && edges[j].l <= st){
			            tempr = max(tempr, edges[j].r);
			            错误: 忘写了
			            正确: j ++;
			        }
			        错误: if(tempr < st){	如果这么写, tempr == st的话, 也不会break, 之后 st = tempr, 然后j还是原来的j, 下一个while就会无限循环下去没有结果 
			        正确: if(tempr <= st){
			            错误: success = false; 正确的是 bool success = false; 所以不需要写这一句
			            正确: 直接break
			            break;
			        }
			        res++;
			        if(tempr >= ed){
			            success = true;
			            break;
			        }
			        st = tempr;
			        i = j - 1;
			    }
			    if(success) cout << res << endl;
			    else cout << -1 << endl;
			    return 0;
			}
		2. ok
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 1e5 + 10;
			int st, ed, n;
			struct Edge{
			    int l, r;
			    bool operator<(const Edge &e) const{
			        return l < e.l;
			    }
			}edges[N];
			int main(){
			    cin >> st >> ed;
			    cin >> n;
			    for(int i = 0; i < n; i++){
			        int l, r;
			        cin >> l >> r;
			        edges[i] = {l, r};
			    }
			    sort(edges, edges + n);
			    int mostr = -2e9, res = 0;
			    bool s = false;				自然退出for的情况下也是false, 只有mostr >= ed才是成功
			    for(int i = 0; i < n; i++){
			        int j = i;
			        while(j < n && edges[j].l <= st){
			            mostr = max(mostr, edges[j].r);
			            j++;
			        }
			        if(mostr > st) res++;	说明往前走了, res++, 选到了一个能够覆盖st的区间, 并且这个区间的右端点是最右的
			        else break;				说明没找到, 存在缝隙
			        	
			        if(mostr >= ed){		这个才是成功的标志
			            s = true;
			            break;
			        }
			        st = mostr;
			        i = j - 1; 				注意双指针, 如果有j=i, 都要看一下上一步的i是多少
			    }
			    if(s) cout << res << endl;
			    else cout << -1 << endl;
			    return 0;
			}
			--
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 1e5 + 10;
			struct Edge{
			    int l, r;
			    bool operator<(const Edge &e) const{
			        return l < e.l;
			    }
			}edges[N];
			int n, st, ed;
			int main(){
			    cin >> st >> ed >> n;
			    for(int i = 0; i < n; i++){
			        int l, r;
			        cin >> l >> r;
			        edges[i] = {l, r};
			    }
			    sort(edges, edges + n);
			    int mostr = -2e9, res = 0;
			    bool s = false; 	自然退出for的情况下也是false, 只有mostr >= ed才是成功
			    for(int i = 0; i < n; i++){
			        int j = i;
			        while(j < n && edges[j].l <= st){
			            mostr = max(mostr, edges[j].r);
			            j++;
			        }
			        if(mostr > st) res++;
			        else break;
			        if(mostr >= ed){
			            s = true;
			            break;
			        }
			        st = mostr, i = j - 1;
			    }
			    if(s) cout << res << endl;
			    else cout << -1 << endl;
			    return 0;
			}
	77. AcWing 148. 合并果子
		1. bug
			#include <iostream>
			#include <queue>
			using namespace std;
			const int N = 1e4 + 10;
			typedef long long LL;
			int n;
			int main(){
			    cin >> n;
			    priority_queue<int, vector<int>, greater<int>> heap;
			    int a;
			    while(n--){
			        cin >> a;
			        heap.push(a);
			    }
			    错误: LL res; 局部变量未初始化, 是乱值
			    正确: LL res = 0;
			    while(heap.size() >= 2){
			        int a = heap.top(); heap.pop();
			        int b = heap.top(); heap.pop();
			        res += (a + b);
			        错误: heap.push(res); 写啥呢!
			        正确: heap.push(a + b);
			    }
			    cout << res << endl;
			    return 0;
			}
		2. ok 
			这道题, 说的不是连续的堆, 任意两堆合并起来就好
			符合二叉树的性质, 一种选法就是一棵二叉树, 另一种选法是另一棵二叉树
			我们要构建代价最小的二叉树
				代价 == 到根的路径长度 * 该节点的值
				因为叶子节点的路径最长, 所以叶子节点需要是值最小的
			所以思路就是:
				找到值最小的两个, 合并, 组成新节点
				再找到值最小的两个, 再合并, 再组成新节点
			#include <iostream>
			#include <queue>
			using namespace std;
			const int N = 1e4 + 10;
			typedef long long LL;
			int n, a;
			priority_queue<int, vector<int>, greater<int>> heap;
			int main(){
			    cin >> n;
			    while(n--){
			        cin >> a;
			        heap.push(a);
			    }
			    LL res = 0;
			    while(heap.size() >= 2){
			        int a = heap.top(); heap.pop();
			        int b = heap.top(); heap.pop();
			        res += (a + b);
			        heap.push(a + b);
			    }
			    cout << res << endl;
			    return 0;
			}
	78. AcWing 913. 排队打水
		1. bug
		2. ok{超级顺}
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 1e5 + 10;
			int q[N], n;
			int main(){
			    cin >> n;
			    for(int i = 0; i < n; i++){
			        cin >> q[i];
			    }
			    sort(q, q + n);
			    long long res = 0;
			    for(int i = 0; i < n; i++){
			        res += q[i] * (n - 1 - i);	(n - 1 - i)也就是第i个人后面有几个人在等他: [i+1, n-1]的区间长度: n-1 - (i+1) + 1 = n - i - 1;
			    }
			    cout << res << endl; //或者 printf("%lld\n", res);
			    return 0;
			}
			--
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 1e5 + 10;
			int n, q[N];
			int main(){
			    cin >> n;
			    for(int i = 0 ; i < n; i++) cin >> q[i];
			    sort(q, q + n);
			    long long res = 0;
			    for(int i = 0 ; i < n; i++){
			        res += q[i] * (n - 1 - i);
			    }
			    printf("%lld\n", res);
			    return 0;
			}
	79. AcWing 104. 货仓选址
		1. bug
		2. ok{超级顺}
			因为 
				|xa - n| + |xb - n| >= xb - xa
				要满足 |xa - n| + |xb - n| == xb - xa, 就要让n在[xa, xb]内部
				对于所有的[x1, xn], [x2, x_{n-1}], [x_{n/2}, x_{n/2+1}]]都要满足在区间的内部, 在最中间的区间的内部, 就是中位数了
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 1e5 + 10;
			int q[N], n;
			long long res;
			int main(){
			    scanf("%d", &n);
			    for(int i = 0 ; i < n; i++) scanf("%d", &q[i]);
			    sort(q, q + n);
			    for(int i = 0 ; i < n; i++){
			        res += abs(q[i] - q[n / 2]);	q[n / 2]就是中位数 
			    }
			    cout << res << endl;
			    return 0;
			}
	* 80. AcWing 125. 耍杂技的牛
		1. bug
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 5e5 + 10;
			typedef pair<int, int> PII;
			PII q[N];
			int n;
			int main(){
			    scanf("%d", &n);
			    for(int i = 0 ; i < n; i++){
			        int w, s;
			        scanf("%d%d", &w, &s);
			        q[i] = {w + s, s};	注意: 很容易想着插入 w + s, s, w. 但是w可以由相减得到 
			    }
			    sort(q, q + n);
			    错误: int res = 0, sum = 0; 因为res可以是负数 
			    正确: int res = -2e9, sum = 0;	注意, sum很容易不知道怎么实现 
			    for(int i = 0 ; i < n; i++){
			        auto t = q[i];
			        int s = t.second, w = t.first - t.second;
			        int risk = sum - s;			这一层的risk值
			        if(risk > res) res = risk;  第一层的风险值是负值, 因为第一层的上面没有东西sum==0
			        sum += w;
			    }
			    cout << res << endl;
			    return 0;
			}
		2. ok 
			逻辑非常简单, 就是w+s从小到大排序, 然后最上面的是w+s最小的
			证明很不错: https://www.acwing.com/solution/content/26316/
				结论:
					如果存在上面的第i层的 wi + si, 大于或者等于底下的第i+1层的 w(i+1) + s(i+1)
					我们就交换这两层, 交换后, max(交换后) <= max(交换后), 达到更优的地步
					所以, 最优的状态就是对于每一层: wi + si < w(i+1) + s(i+1)
						即上层的 w + s, 要更小, 所以直接是sort.
				记住一个:
					当满足 wi + si ≥ w(i+1) + s(i+1): 所有危险值中的"最大值", 在交换后, 只会不变或者变小
				详细:
					变化			第i个位置上的牛	第i+1个位置上的牛
					交换前		s(i+1)			wi + si
					交换后		si 				w(i+1) + s(i+1)
				目标, 证明: max(交换前) ≥ max(交换后)
					1. 即: max(s(i+1), wi + si) ≥ max(si , w(i+1) + s(i+1))
					2. 证明:
						1.
							1. 已知:
								wi + si > si 			 : 显而易见
								wi + si ≥ w(i+1) + s(i+1): 这个是假设的条件
							2. 得到:
								wi + si ≥ max(si, w(i+1) + s(i+1))
						2.
							1. 已知:
								wi + si ≥ w(i+1) + s(i+1)
							2. 得到:	
								wi + si > s(i+1)
								max(s(i+1), wi + si) = wi + si
						3. 综上: max(s(i+1), wi + si) >= max(si, w(i+1) + s(i+1))
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 5e5 + 10;
			typedef pair<long long, long long> PLL;
				这里是一个数组, 每个元素是tuple {w + s, s}, 我们sort是按照数组的第一个关键词, 也就是{w + s}
			PLL q[N];
			int n;
			int main(){
			    scanf("%d", &n);
			    for(int i = 0 ; i < n; i++){
			        int w, s;
			        scanf("%d%d", &w, &s);
			        q[i] = {w + s, s};
			    }
			    sort(q, q + n);
			    int res = -2e9, sum = 0;	sum是第i头牛上面的0到i-1头牛的重量之和 
			    for(int i = 0; i < n; i++){
			    	auto t = q[i];
			        int w = t.first - t.second, s = t.second;
			        int risk = sum - s;		这一层的risk值
			        if(risk > res) res = risk;	注意, 我们求的是 res = max(第0头牛的危险值, 第1头牛的危险值, ..., 第n-1头牛的危险值). 我们希望一个方案使得res最小, 这个方案就是: w+s从小到大排序, 然后最上面的是w+s最小的
			        sum += w;
			    }
			    cout << res << endl;
			    return 0;
			}
			--
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int N = 5e5 + 10;
			typedef pair<long long, long long> PLL;
			PLL q[N];
			int n;
			int main(){
			    scanf("%d", &n);
			    for(int i = 0 ; i < n; i++){
			        int w, s;
			        scanf("%d%d", &w, &s);
			        q[i] = {w + s, s};
			    }
			    sort(q, q + n);
			    int sum = 0, res = -2e9;
			    for(int i = 0; i < n; i++){
			        auto t = q[i];
			        int w = t.first - t.second, s = t.second;
			        int risk = sum - s;
			        if(risk > res) res = risk;
			        sum += w;
			    }
			    cout << res << endl;
			    return 0;
			}
	81. AcWing 866. 试除法判定质数
		1. bug
			#include <iostream>
			using namespace std;
			const int N = 110;
			int n, a;
			bool isp(int n){
			    错误: 忘写了
			    正确: if(n < 2) return false;	如果是n==0,1. 直接return false
			    for(int i = 2; i <= n / i; i++){
			        if(n % i == 0) return false;
			    }
			    return true;	如果是n==2,3. 那么for就根本走不进去, 直接return true
			}
			int main(){
			    cin >> n;
			    while(n--){
			        cin >> a;
			        if(isp(a)) puts("Yes");
			        else puts("No");
			    }
			    return 0;
			}
		2. ok
			#include <iostream>
			using namespace std;
			const int N = 110;
			int n, a;
			bool isp(int n){
			    if(n < 2) return false; 		n == 0, 1都是false
			    for(int i = 2; i <= n / i; i++){
			        if(n % i == 0) return false;
			    }
			    return true; 					n == 2, 3都是true
			}
			int main(){
			    cin >> n;
			    while(n--){
			        cin >> a;
			        if(isp(a)) puts("Yes");
			        else puts("No");
			    }
			}
	82. AcWing 867. 分解质因数
		1. bug 
			#include <iostream>
			using namespace std;
			const int N = 110;
			int n, a;
			void dis(int n){
			    其实这个可以不写, 见ok: if(n < 2){
			        cout << n << " " << 1 << endl;
			        return;
			    }
			    for(int i = 2; i <= n / i; i++){
			        int cnt = 0;
			        while(n % i == 0){
			            cnt++;
			            n /= i;
			        }
			        错误: cout << i << " " << cnt << endl; 	否则会输出什么 3 0
			        正确: if(cnt) cout << i << " " << cnt << endl;
			    }
			    错误: if(n) cout << n << " " << 1 << endl; 	否则一定会输出 1 1	
			    正确: if(n > 1) cout << n << " " << 1 << endl;
			}
			int main(){
			    cin >> n;
			    while(n--){
			        cin >> a;
			        dis(a);
			        puts("");
			    }
			    return 0;
			}
		2. ok
			#include <iostream>
			using namespace std;
			const int N = 110;
			int n, a;
			void div(int n){
			    for(int i = 2; i <= n / i; i++){	从2开始看 一直到 sqrt(x)
			        int cnt = 0;
			        while(n % i == 0){				如果i能整除x, 说明i是一个质因子. 能满足这个条件的i一定是质数.
			            n /= i;
			            cnt++;
			        }
			        if(cnt) cout << i << " " << cnt << endl;
			    }
			    if(n > 1) cout << n << " " << 1 << endl; 		如果输入的参数n == 1, 2, 3. 直接跳过for走到这里
			}
			int main(){
			    cin >> n;
			    while(n--){
			        cin >> a;
			        div(a);
			        puts("");
			    }
			    return 0;
			}
	* 83. AcWing 868. 筛质数
		1. bug
			#include <iostream>
			using namespace std;
			const int N = 1e6 + 10;
			int n, cnt, prime[N];
			bool st[N];

			void get_primes(int n){
			    错误: for(int i = 2; i <= n / i; i++){, 是每个数字都要判断呀
			    正确: for(int i = 2; i <= n; i++){
			        if(!st[i]) prime[cnt++] = i;
			        for(int j = i; j <= n; j += i) st[j] = true;
			    }
			}

			void get_primes2(int n){
			    错误: for(int i = 2; i <= n / i; i++){, 是每个数字都要判断呀
			    正确: for(int i = 2; i <= n; i++){
			        if(!st[i]){
			            prime[cnt++] = i;
			            for(int j = i; j <= n; j += i) st[j] = true;
			        }
			    }
			}

			void get_primes3(int n){
			    错误: for(int i = 2; i <= n / i; i++){, 是每个数字都要判断呀
			    正确: for(int i = 2; i <= n; i++){
			        if(!st[i]) prime[cnt++] = i;
			        for(int j = 0; prime[j] <= n / i; j++){
			            if(i % prime[j] == 0){
			                st[prime[j] * i] = true;
			                break;
			            }
			            st[prime[j] * i] = true;
			        }
			    }
			}
			int main(){
			    cin >> n;
			    get_primes3(n);
			    cout << cnt << endl;
			    return 0;
			}
		2. ok
			#include <iostream>
			using namespace std;
			const int N = 1e6 + 10;
			int n, cnt, prime[N];
			bool st[N];

			//朴素筛法-O(nlogn): 对于每个数字i, 无论i是质数还是合数, 我们都无脑的将后面的(n - i)/2数字都设置为合数
			void get_primes(int n){
			    for(int i = 2; i <= n; i++){
			        if(!st[i]) prime[cnt ++] = i; //如果i不是合数, 那我们记录prime, 注意是函数的一开始, 就可以知道数字i是不是合数, 因为我们早就筛选好了
			        //写法1:
			            for(int j = 2; j <= n / i; j++) st[j * i] = true; 
			        //写法2:
			        	for(int j = i; j <= n; j += i) st[j] = true;  //不管i是合数还是质数, 我们都用将 i, 2i, 3i, ...ki <= n 都设置为合数, 这个没问题吧? 

			    }
			}

			//埃式筛法-O(nloglogn)
			//上面的方法, 每个合数都被前面很多个质因子多次设置了 st[j] = true. 其实很多是重复没必要的
			//优化, 只用质数i, 来将后面的(n - i)/2数字都设置为合数
			void get_primes2(int n){
			    for(int i = 2; i <= n; i++){
			        if(!st[i]){             //如果i不是合数
			            prime[cnt ++] = i;  //i是质数
			            //写法1:
			            for(int j = 2; j <= n / i; j++) st[j * i] = true;   //i是质数, 我们都用将 i, 2i, 3i, ...j*i <= n 都设置为合数, 这个没问题吧? 
			                            //之所以是 j < n / i, 因为我们只需判断n之前的数字是否是合数, 所以我们只需要判断 j * i <= n的数字
			            //写法2:
			            for(int j = i; j <= n; j += i) st[j] = true;  //i是质数, 我们都用将 i, 2i, 3i, ...k*i <= n 都设置为合数, 这个没问题吧? 
			        }
			        
			    }
			}

			//线性筛法-O(n), n = 1e7的时候基本就比埃式筛法快一倍了
			//最好的优化: 数字i, 只会被其最小质因子筛去, 而不是被所有的质因子筛去, 速度就很快了
			void get_primes3(int n){
			    for(int i = 2; i <= n; i++){
			        if(!st[i]) prime[cnt++] = i;
			        //下面的故事: 我们遍历所有的质数prime[j], 如果这个质数prime[j]小于数字i的最小质因子, 我们就筛去prime[j] * i这个合数;
			        // 这里是固定了 i, 但是我们会看所有小于等于i的最小质因数的质数: 
			        	//遍历的是: 	prime[0], prime[1], prime[2], ... , prime[xx]. 只要prime[xx] <= i的最小质因数
			        	//筛的是:  	prime[0]*i, prime[1]*i, prime[2]*i, ... , prime[xx]*i
			        for(int j = 0; prime[j] <= n / i; j++){ //为什么是 prime[j] <= n / i: 我们想筛的是的数字是不大于n的, 这里筛的是 prime[j] * i, 所以prime[i] * j没必要大于n
			            // 1.i % pj == 0, pj是i的最小质因子, pj也是pj*i的最小质因子 {i是否是合数, 在一开头的if(!st[i])就知道了, 但是pj*i肯定是合数}
			            // 2.i % pj != 0, pj小于i的最小质因子, 但pj就是pj*i的最小质因子, 这句话能理解吧, pj肯定是pj的最小质因子, 但是pj<i的最小质因子, 所以pj就是pj*i的最小质因子
			            if(i % prime[j] == 0){
			                st[prime[j] * i] = true;    //我们的pj*i被它的最小质因子筛去了
			                break;                      //需要结束了, 否则之后接着用st[primes[j+1]*i]=true去筛合数时，就不是用最小质因子去筛了
			            }
			            else st[prime[j] * i] = true;
			        }
			    }
			}
			int main(){
			    cin >> n;
			    get_primes(n);
			    cout << cnt << endl;
			    return 0;
			}
	84. AcWing 869. 试除法求约数
		1. bug
		2. ok 
			求n的约数
				思路很简单, 就是求所有小于n的所有的数字i是否可以整除n
				如果i能整除n, 那么n/i也可以整除n, 因为是成对出现的
			#include <iostream>
			#include <vector>
			#include <algorithm>
			using namespace std;
			vector<int> res;
			int n, a;
			void divisor(int n){
			    res.clear();
			    for(int i = 1; i <= n / i; i++){	注意是从1开始, 因为1也是约数 
			        if(n % i == 0){
			            res.push_back(i);
			            if(i != n / i) res.push_back(n / i);
			        }
			    }		
			    sort(res.begin(), res.end());		注意写法 
			    for(auto i : res) cout << i << " ";
			}
			int main(){
			    cin >> n;
			    while(n--){
			        cin >> a;
			        divisor(a);
			        puts("");
			    }
			    return 0;
			}
	* 85. AcWing 870. 约数个数
		1. bug{错的很厉害}
			下面的整个逻辑都错了:
				错在哪里:
				 	我的错误逻辑是:
				 		对于每个数字a, 都求出它的: α1, α2, αk.
				 			然后res * (α1 + 1) * (α2 + 1) * ... * (αk + 1)
				 			然后看下一个数字
				 	正确逻辑:
				 		求出全部数字a的 α1, α2, αk
				 		求完之后: (α1 + 1) * (α2 + 1) * ... * (αk + 1)
				全都错了:
					#include <iostream>
					#include <unordered_map>
					using namespace std;
					const int N = 110, mod = 1e9 + 7;
					int n, a;
					int main(){
					    cin >> n;
					    long long res = 1;
					    while(n--){
					        cin >> a;
					        unordered_map<int, int> prime;
					        for(int i = 2; i <= a / i; i++){
					            int cnt = 0;
					            while(a % i == 0){
					                cnt ++;
					                a /= i;
					            }
					            if(cnt) prime[i] = cnt;	不能是=cnt, 这样会覆盖掉前面数字的prime[i], 我们的正确的逻辑是 prime[i]++
					        }
					        if(a > 1) prime[a] = 1;
					        for(auto item : prime){
					            res = (res * (item.second + 1)) % mod;
					        }
					    }
					    cout << res << endl;
					    return 0;
					}
				正确:
					#include <iostream>
					#include <unordered_map>
					using namespace std;
					const int N = 110, mod = 1e9 + 7;
					int n, a;
					int main(){
					    cin >> n;
					    long long res = 1;
					    unordered_map<int, int> prime;	这里放置的是全部数字的prime的个数, 为什么不是 prime[N], 而是用map
					    									因为我们要记录的是两个信息: {质因子的值 : 这个质因子有多少个}.
					    									如果用prime[N], 就只能记录质因子的值 和 一共多少个不同的质因子
					    while(n--){
					        cin >> a;
					        for(int i = 2; i <= a / i; i++){
					            while(a % i == 0){
					                prime[i] ++;
					                a /= i;
					            }
					        }
					        if(a > 1) prime[a]++;
					    }
					    for(auto item : prime){
					        res = (res * (item.second + 1)) % mod;
					    }
					    cout << res << endl;
					    return 0;
					}
			2. ok 
				#include <iostream>
				#include <unordered_map>
				using namespace std;
				unordered_map<int, int> prime;
				const int mod = 1e9 + 7;
				int n, a;
				int main(){
				    cin >> n;
				    int res = 1; //不能是全局变量, 否则res = 0;
				    while(n--){
				        cin >> a;
				        for(int i = 2; i <= a / i; i ++){  //质因数是从2开始的
				            while(a % i == 0){ //i是质因子
				                prime[i] ++;
				                a /= i;
				            }
				        }
				        if(a > 1) prime[a]++;
				    }
				    for(auto item : prime) res = (res * (item.second + 1)) % mod;
				    cout << res << endl;
				    return 0;
				}
	* 86. AcWing 871. 约数之和
		1. bug 
			#include <iostream>
			#include <algorithm>
			using namespace std;
			const int mod = 1e9 + 7;
			unordered_map<int, int> prime;
			int n, a;
			int main(){
			    cin >> n;
			    while(n--){
			        cin >> a;
			        for(int i = 2; i <= a / i; i++){
			            while(a % i == 0){
			                prime[i]++;
			                a /= i;
			            }
			        }
			        if(a > 1) prime[a] ++;
			    }
			    错误: long long res;
			    正确: long long res = 1;
			    for(auto item : prime){
			        int p = item.first, pcnt = item.second;
			        long long t = 1;
			        while(pcnt--) t = (t * p + 1) % mod;
			        res = (res * t) % mod;
			    }
			    cout << res << endl;
			    return 0;
			}
		2. ok
			#include <iostream>
			#include <unordered_map>
			using namespace std;
			typedef long long LL;
			const int mod = 1e9 + 7;
			unordered_map<int, int> prime;
			int n, a;
			int main(){
			    cin >> n;
			    while(n--){
			        cin >> a;
			        for(int i = 2; i <= a / i; i++){
			            while(a % i == 0){
			                prime[i]++;
			                a /= i;
			            }
			        }
			        if(a > 1) prime[a]++;
			    }
			    LL res = 1;
			    for(auto item : prime){
			        int p = item.first, pcnt = item.second;
			        LL t = 1;
			        while(pcnt--) t = (t * p + 1) % mod; //这一句是计算 (p1^0+p1^1+…+p1^α1) ∗ … ∗ (pk^0+pk^1+…+pk^αk) 中的 (pk^0+pk^1+…+pk^αk)
			                                            // t抬高p个高度, 然后后面跟一个小尾巴1
			        res = (res * t) % mod; //这一句是计算 () * () * ()
			    }
			    cout << res << endl;
			    return 0;
			}
	87. AcWing 872. 最大公约数
		0. 小总结:
			1. 一个数字 N
				1. 属性: 是否是质数 
					方法: 
						1. 从2开始看, 因为1不是质数也不是合数 
						2. 如果某个数能够整除N, N就不是质数 
				2. 分解: 分到不能再分 
					1. N = p1^α1 ∗ p2^α2 ∗ ⋯ ∗ pk^αk, 其中pk是质因子, ak是这个质因子出现的个数
						方法:
							1. 质因子就是质数, 从2开始看, 每找到一个质因子就用 while()把这个质因子都除掉
								for (int i = 2; i <= x / i; i ++ )
						            while (x % i == 0)
						            {
						                x /= i;
						                primes[i] ++ ;	质因数i的个数有prime[i]个
						            }
								不用怕i是合数, 合数是不会进入while的
									例如: 前面的质因子2已经让后面的合数4无法整除N了
							2. 最后需要写一句:
								if (x > 1) primes[x] ++ ;
								因为上面的 for()只是判断了小于 sqrt(x)的情况, 有的质因子在右边
								例如 
									1. 47本身就是质数, 所以for结束也找不到整除47的, 所以走 if (47 > 1) primes[47] ++ ;
									2. 6的for结束之后也是剩余一个在 sprt(6)=2.44 右侧的质数3, 所以走 if (3 > 1) primes[3] ++ ;
									2. 15的for结束之后也是剩余一个在 sprt(15)=3.87 右侧的质数5, 所以走 if (5 > 1) primes[5] ++ ;
					2. 利用分解的相关题目: 
						1. 求N的所有约数的个数: 
							约数d = p1^β1 ∗ p2^β2 ∗ ⋯ ∗ pk^βk
								d想要几个质因数p1? 那β1是在[0,α1]的值中选一个
								d想要几个质因数p2? 那β2是在[0,α2]的值中选一个
								…
								d想要几个质因数pk? 那βk是在[0,αk]的值中选一个
							约数个数是: (α1 + 1) * (α2 + 1) * ... * (αk + 1)
						2. 求N的所有约数的和:
							你能想到就是全排没错吧
											β1 		β2 	 	... 	βk   	也就是d想要几个质因数pk
								第1个约数d:   0 		0 		0  		0
								第2个约数d:   1 		0 		0  		0
								第3个约数d:   2 		0 		0  		0
								第3个约数d:   2 		1 		0  		0
								...
								最后一个约数d: α1 		α2 		... 	αk
							全排的一个实现方法, 神奇而又平凡的结合律:
								 (p1^0+p1^1+…+p1^α1) ∗ … ∗ (pk^0+pk^1+…+pk^αk)
				3. 它的约数:
					0. 最小的约数: 1, 最大的约数: N本身
					1. 约数可以是{质数},{合数},{非质数非合数}
						非质数非合数: 1 
						质数: 2, 3, ...
						合数: 4, 6, 8, 15, ...
					3. 相关题目:
						1. N的约数有哪些?
							方法: 
								1. 约数从1开始判断, 因为约数可以是1
								2. 约数是成对的, 如果i能整除n, 那么 n/i 也能整除n
									因为是成对的, 所以 n/i 在 sprt(n)的右侧, 所以我们不需要写 if (x > 1) primes[x] ++ ;
			2. 求最大公约数:
				1. {a, b}的公约数集合和{b, a % b}的公约数集合相同, 他们的最大公约数d也相同 
					d == gcd(a, b) == gcd(b, a % b), 其中d是a 和 b 的最大公约数, 也是 b 和 a % b 的最大公约数
					证明: 为什么{a, b}的公约数集合和{b, a % b}的公约数集合相同
						1. 我们约定: d | a 称为d可以整除a, 也就是 a % d == 0
						2. 如果 d | a 且 d | b , 则有 d | (x*a + y*b)
							为什么?
								d | a 说明a / d == s, 其中s是整数
								d | b 说明b / d == t, 其中t是整数
								(x*a + y*b) / d = x*a / d + y*b / d = x*s + y*t, 这个肯定是整数
									所以d可以整除:(x*a + y*b), 所以 d | (x*a + y*b) 
						3. 回到我们的题目:
							a % b == a - k*b, 其中 k = a/b下取整. 举例: 16 % 5 == 3余1, k = 16/5 = 3
						4. 记{b, a - k*b}的最大公约数 d
							意味着d可以整除b, d也可以整除a - k*b
								即, d|b 且 d | (a − k*b)
							那么这个d也是{a, b}的公约数
								因为 d|b 且 d | (a − k*b), 则 d | (a − k*b + k*b) = d | a 
						5. 因此{a, b}的公约数集合和{b, a % b}的公约数集合相同 所以他们的最大公约数也相同 
				2. int gcd(int a, int b)	return b ? gcd(b, a % b) : a; 
					1. 递归到底的情况是b == 0
						gcd(24, 15)
						gcd(15, 9)
						gcd(9, 6)
						gcd(6, 3)
						gcd(3, 0) = 3, 所以答案是3
					2. 我们不需要担心 a < b的情况, 因为会自动翻转过来 
						gcd(15, 24)
						gcd(24, 15)
					3. 如果是两个质数 
						gcd(47, 13)
						gcd(13, 8)
						gcd(8, 5)
						gcd(5, 3)
						gcd(3, 2)
						gcd(2, 1)
						gcd(1, 0) = 1, 所以答案是1
		1. bug
		2. ok{很顺}
			#include <iostream>
			using namespace std; 
			int n, a, b;
			int gcd(int a, int b){
			    return b ? gcd(b, a % b) : a;	记忆: b, b, ab, a 
			}
			int main(){
			    cin >> n;
			    while(n--){
			        cin >> a >> b;
			        cout << gcd(a, b) << endl;
			    }
			    return 0;
			}
	88. AcWing 873. 欧拉函数
		0. 只要知道公式就好了
			phi(i) = i × {(p1−1)/p1} × {(p2−1)/p2} × … × {(pm−1)/pm}
			老师的证明:
				互斥原理:
					一个数a和i互斥, 这个数a, 可以是p1, p2, ..., pm
					但是我们有些会重叠, 例如p1*p2, p1*p3..., 减去这些
					我们会减多了, 例如p1*p2*p3, p1*p3*p4... 之后再加上这些
				总之最后就是公式
		1. bug 
			#include <iostream>
			using namespace std;
			const int N = 1e6 + 10;
			int q, n, prime[N], cnt;
			int main(){
			    cin >> q;
			    while(q--){
			        cnt = 0;
			        cin >> n;
			        正确: long long res = n;
			        for(int i = 2; i <= n / i; i++){
			            if(n % i == 0){
			               prime[cnt++] = i;
			               while(n % i == 0) n /= i;
			            }
			        }
			        if(n > 1) prime[cnt++] = n;
			        错误: long long res = n; 不能放在这里n已经不是原来的n了 
			        for(int i = 0; i < cnt; i++){
			            res = (res / prime[i] * (prime[i] - 1));
			        }
			        cout << res << endl;
			    }
			    return 0;
			}
		2. ok{很顺}
			#include <iostream>
			using namespace std;
			int q, n;
			int main(){
			    cin >> q;
			    while(q--){
			        cin >> n;
			        long long phi = n;
			        for(int i = 2; i <= n / i; i++){	i是遍历质因子, 从2开始
			            if(n % i == 0){					如果i是质因子 
			                phi = phi / i * (i - 1); //这里是 phi * (i-1)/i, 但是怕*会溢出所以先除/
			                while(n % i == 0) n /= i;
			            }
			        }
			        if(n > 1) phi = phi / n * (n - 1);
			        cout << phi << endl;
			    }
			    return 0;
			}
	* 89. AcWing 874. 筛法求欧拉函数
		1. bug
			#include <iostream>
			using namespace std;
			const int N = 1e6 + 10;
			int phi[N], prime[N];
			bool st[N]; //st[i] == true, 则i是合数
			int n, cnt;
			int main(){
			    cin >> n;
			    错误: 忘了写
			    正确: phi[1] = 1; 	这里需要特殊对待
			    错误: for(int i = 1; i <= n; i++){ 	不能从1开始, 因为st[1]是不会被算的, 因为不是质数也不是合数, 否则答案会错
			    正确: for(int i = 2; i <= n; i++){    //遍历数字i, for里面做的事: i是否是质数, phi[i]是多少 
			        if(!st[i]){
			            prime[cnt++] = i;   //记录质数, 相当于也是筛质数
			            phi[i] = i - 1;     //质数i, 前面[1, i-1]和i都是互质的
			        }
			        for(int j = 0; prime[j] <= n / i; j++){
			            if(i % prime[j] == 0){ //prime[j]是i的最小质因子, 也是prime[j]*i的最小质因子
			                st[prime[j] * i] = true;
			                phi[prime[j] * i] = phi[i] * prime[j]; 
			                break;
			            }else{
			                st[prime[j] * i] = true;
			                phi[prime[j] * i] = phi[i] * (prime[j] - 1);
			            }
			        }
			    }
			    long long res = 0;
			    for(int i = 1; i <= n; i++) res += phi[i];
			    cout << res << endl;
			    return 0;
			}
		2. ok 
			解释的很好:
				首先, 我们的 phi()函数, 只和质因子的值有关, 和某个质因子有多少个无关
					所以: i, prime[j]*i 有很特殊的关系:
						如果 i % primes[j] == 0: 即 prime[j] == i的最小质因子p1
							prime[j]*i 的所有质因子 == i 的所有质因子
						如果 i % primes[j] != 0: 即 prime[j] < i的最小质因子p1
							prime[j]*i 的所有质因子 == i 的所有质因子 + prime[j]这个质因子
				如果 i % primes[j] == 0: prime[j] == i的最小质因子p1, 但是prime[j] == prime[j]*i 的最小质因子p1
					phi(i) 			= i 			× {(p1−1)/p1} × {(p2−1)/p2} × … × {(pm−1)/pm}, 其中p1就是 prime[j]
					phi(prime[j]*i) = (prime[j]*i) 	× {(p1−1)/p1} × {(p2−1)/p2} × … × {(pm−1)/pm}, 其中p1就是 prime[j]
									= prime[j] * phi(i)
				如果 i % primes[j] != 0: prime[j] < i的最小质因子p1, 但是prime[j] == prime[j]*i 的最小质因子p1
					phi(i) 			= i 										× {(p1−1)/p1} × {(p2−1)/p2} × … × {(pm−1)/pm}, 其中p1就是 prime[j]
					phi(prime[j]*i) = (prime[j]*i) 	× {(prime[j]-1)/prime[j]}	× {(p1−1)/p1} × {(p2−1)/p2} × … × {(pm−1)/pm}, 其中p1就是 prime[j]
									= prime[j] * phi(i) × {(prime[j]-1)/prime[j]}
									= phi(i) × (prime[j]-1)
	* 90. AcWing 875. 快速幂
		1. bug
			#include <iostream>
			using namespace std;
			typedef long long LL;
			int q;
			错误: int a, b, p; 因为 1 ≤ ai, bi, pi ≤ 2×1e9, 所以 a * a 会溢出
			正确: LL a, b, p;

			错误: int qmi(int a, int b, int p){
			正确: int qmi(LL a, LL b, LL p){
				错误: LL res = 0;
			    正确: LL res = 1;
			    while(b){
			    	错误: if(b & 1) res = (res + a) % p;
			        正确: if(b & 1) res = (res * a) % p;		幂是加法, 所以底数就是乘法. 所以我们为了实现b的二分的加法, 就是实现底数res和a的乘法
			        b >>= 1;
			        a = a * a % q;
			    }
			    return res;
			}
			int main(){
			    cin >> q;
			    while(q--){
			        cin >> a >> b >> p;
			        cout << qmi(a, b, p) << endl;
			    }
			    return 0;
			}
		2. ok 
			二分:
				k = k0*(1 << 0) + k1*(1 << 1) + k2*(1 << 2) + ... + kn*(1 << n), kn == 0或者1
				a^k = a^{k0 * (1 << 0)} * a^{k1 * (1 << 1)} * ... * a^{kn * (1 << n)}
						 		aa 				bb 						nn 
					如何计算aa, bb?
						我们使用叠罗汉的方法						
						所以一个重要的事情:
							aa: a^{k0 * (1 << 0)} = a^1
							bb: a^{k1 * (1 << 1)} = a^2, 也就是 a = a * a % p;
							cc: a^{k2 * (1 << 2)} = a^4, 也就是 a = a * a % p;
								因为 a * a = a^2 = (a^2)^2
					上面求aa, bb, ..., nn, 基于的假设是: k0 == k1 == k2 == ... == kn == 1
						但是我们的题目的k, 可能kn是0
						所以:
							如果末位kn的确是1, 那么就真的 res * a
							如果末位kn是0, 那么什么都不用做
				对于模运算有一个重要结论：AB%M=(A%M)*(B%M)%M
			#include <iostream>
			using namespace std;
			typedef long long LL;
			int n;
			LL a, b, p;
			LL qmi(LL a, LL b, LL p){
			    LL res = 1;
			    while(b){   //我们是把b二分, 例如b的二进制是 1110101...0111. 
			        if(b & 1) res = (res * a) % p;  //末位是1的话, 我们就把幂的加法, 变为底数的乘法: (res * a)
			        b >>= 1;
			        a = a * a % p;                  //这是为了准备b的下一位, 因为我们的是分解成了 a^b = a^1 * a^2 * a^4 * a^8 ... * a^32. 
			    }
			    return res;
			}
			int main(){
			    cin >> n;
			    while(n--){
			        cin >> a >> b >> p;
			        cout << qmi(a, b, p) << endl;
			    }
			    return 0;
			}
9. after 5.25 
	91. AcWing 876. 快速幂求逆元
	92. AcWing 877. 扩展欧几里得算法
	93. AcWing 878. 线性同余方程
	94. AcWing 204. 表达整数的奇怪方式
	95. AcWing 883. 高斯消元解线性方程组
	96. AcWing 884. 高斯消元解异或线性方程组
	97. AcWing 885. 求组合数 I
	98. AcWing 886. 求组合数 II
	99. AcWing 887. 求组合数 III
	100. AcWing 888. 求组合数 IV
	101. AcWing 889. 满足条件的01序列
	102. AcWing 890. 能被整除的数
	103. AcWing 891. Nim游戏
	104. AcWing 892. 台阶-Nim游戏
	105. AcWing 893. 集合-Nim游戏
	106. AcWing 894. 拆分-Nim游戏
	零散笔记:
		--------
			1. 为什么是 0x3f, 不是-1{0xfffffff},
				0xff: 只是判断是否是-1, 然后 dist[v] = dist[u] + 1
				0x3f: 因为要加值 dist[j] = min(dist[j], dist[t] + g[t][j])
								例如 0x3f3f3f3f = min(0x3f3f3f3f, 3 + 0x3f3f3f3f)
					加值后怕溢出, 如果是0xffff还会溢出为负数 
			2. 
			3. heap存的是 pair<int, int>  -> pair<dis, ver>
				对应 dist[ver] = dis;
			4. 优化版本:
				for (int i = h[ver]; i != -1; i = ne[i])
				因为边数少, 所以用邻接表, 所以遍历的是邻接表
				
				未优化:
					for (int j = 1; j <= n; j ++ )
						dist[j] = min(dist[j], dist[t] + g[t][j]);
					因为边数多, 所以用邻接矩阵, 所以遍历的是邻接矩阵的第t行: g[t][j]
			5. dijkstra优化
				瓶颈在于, 每条边插入heap的效率比较低: loge
				有e条边, 如果边很多,插入的效率就会很慢
					可能不如不优化, 因为不优化根本不需要插入heap这个动作
		--------------
			1. edge[]
				因为bellmanford要遍历所有的边
				所以干脆把边都记录下来
				邻接矩阵的边很分散
				邻接表的边其实倒还好, 可以一行一行航遍历
			2. last:
				防止占便宜
				如果是用dist[]
				因为遍历所有的边
					所以如果有的边, a>b变得更小了, b->c变得更小了, 其实是占了便宜的
					因为不能 a->b->c 
					最多只能一步
				有了 last
					a->b能变小
						dist[b点] = min(dist[b点], last[a点] + w[a->b] )
									= min(0x3f3f3f3f, 0 + 1)
					但是b->c不能更新 
						dist[c点] = min(dist[c点], last[b点] + w[b->c] )
									= min(0x3f3f3f3f, 0x3f3f3f3f + 1)

			3. 0x3f3f3f3f / 2
				因为由负权边

				
		-------
			/列%行: 	除列强, 模航{航模}
			*列+y: 	乘着列强
		------
			bellman
			------- 
			\  \
			 \  \

			------|------
			\  \
			 \  \ |-----
			  -  -
			   \  \
			    \  \	

			感觉 bellmanford 就像是一盏灯, 一闪一闪, 每次闪就向外辐射一层{仅仅一层}
				上次闪的地方原封不动, 并且更外层的层也是原封不动

			之所以负环问题
				应该是负环问题, 我们限定 k == n吧{或者n+1,n-1}我也不确定
				如果辐射完k次还是能够继续 min, 说明有负环? 

			for(辐射k次){
				for(每条边都试着辐射, 但是只有某一层的边能辐射成功){

				}
			}
		-----
			spfa
				queue<int> q; 记录所有距离变小的节点 
					很像 priority_queue中放入被放松的边
					但是queue 的top不需要是当前距离最短的点
			为什么spfa是bellman的优化:
				bellmanford 就像是一盏灯, 一闪一闪, 每次闪就向外辐射一层{仅仅一层}
				上次闪的地方原封不动, 并且更外层的层也是原封不动
				所以bellman的瓶颈就在于, 他做了很多无用功: 辐射了每条边, 但并不是所有边都能成功放松, 即上次闪的地方还是原封不动, 并且更外层的层还是原封不动

				spfa, 就是类似 dfs()的层序遍历, 每次只辐射某一层
			我的感觉
				bellman, spfa就是层序遍历所有的点, 并把每个点到起点的距离都做更新
				如果有环也不怕, 就当做是走了无限层数.
				所以通过卡层数来防止在环里无限绕圈

				他们的理论逻辑, 就和负权边没有什么关系了, 因为存在负权边也不会影响正确性
				因为他们就不是找{当前状态下最强的那个}
					这里感觉dij属于近视的算法, 只找当前状态下最强的, 殊不知在未来某个负权边能有更大的威力


		----
		dijks
			a修仙 -> 人间最强b{放松别人} -> 

		为什么dijk不能有负权边:
			因为dijk的思路是: 只要st[t] == true, 代表 dist[t]就一定是点t到起点的最短距离, 点t之后再也不用被更新{不会有更短的距离了}, 为什么?
				为什么 st[t] == true, 就代表u的最近距离找到了
				为什么 heap弹出的节点t, 代表u的最近距离找到了
					因为 第一个从heap弹出的节点, 就是全局距离起点最近的
					我的疑惑, 有没可能这个节点t后来发现还有更近的路
						不可能, 因为如果有更近的路, 假设这个路径是 a->b->c->t
						那么 第一个从heap弹出的节点就应该是a, 而不是t
				如果有负权边c
					因为 第一个从heap弹出的节点, 就是全局距离起点最近的
					我的疑惑, 有没可能这个节点t后来发现还有更近的路
						不可能, 因为如果有更近的路, 假设这个路径是 a{dist[a] > dist[t]}->b->c{c是非常负的负数}->t
						我们应该的答案是这个 a->b->c->t, 因为{c是非常负的负数}
						但是我们的 dij 第一个从heap弹出的节点是t, dij 的方法就一定是先走t. 但答案应该先走a,因为路径上有个负数可以抵消掉a
		----
10. 5.27
	1. AcWing 1097. 池塘计数
		1. bug
			#include <iostream>
			using namespace std;
			错误: const int N = 1010;
			正确: const int N = 1010, M = N * N;
			typedef pair<int, int> PII;
			错误: PII q[N];
			正确: PII q[M];
			char g[N][N];
			bool st[N][N];  
			int n, m, res;

			void bfs(int ox, int oy){
			    错误: int hh = tt = 0;
			    正确: int hh = 0, tt = 0;
			    q[0] = {ox, oy};
			    
			    写法1: st[ox][oy] = true; 写法1写法2任选一个, 写法1更好, 因为写法2会有重复, 也就是push的时候设置了st=true, pop的时候又设置了一次st=true
			    while(hh <= tt){
			        auto t = q[hh++];
			        int x = t.first, y = t.second;
			        写法2次一点: st[x][y] = true;
			        for(int i = x - 1; i <= x + 1; i++){
			            for(int j = y - 1; j <= y + 1; j ++){
			                错误: 忘记写 if(i == x && j == y) continue;
			                正确: if(i == x && j == y) continue;
			                if(i < 0 || i >= n || j < 0 || j >= m || st[i][j]) continue;
			                if(g[i][j] == '.') continue;
			                st[i][j] = true;
			                q[++ tt] = {i, j};
			            }
			        }
			    }
			}

			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 0; i < n; i ++) scanf("%s", g[i]);	注意这里可以读取一行 
			    for(int i = 0; i < n; i++){
			        for(int j = 0 ; j < m; j++){
			            if(g[i][j] == 'W' && !st[i][j]){
			                bfs(i, j);
			                res++;
			            }
			        }
			    }
			    cout << res << endl;
			    return 0;
			}
		2. ok 
			#include <iostream>
			using namespace std;
			const int N = 1010, M = N * N;  // 边长是1010, 所有的坐标的个数是 边长*边长 
			typedef pair<int, int> PII;     // 我们的bfs队列存的是坐标, 所以用PII
			#define x first
			#define y second 
			PII q[M];                       //q可能会插入所有坐标, 所以是M个 
			char g[N][N];
			bool st[N][N];                  //st[i][j] == true, 说明ij坐标已经遍历过, 一旦遍历就是最近的一层 
			int n, m, res;

			void dfs(int ox, int oy){
			    int hh = 0, tt = -1;
			    q[++ tt] = {ox, oy};
			    st[ox][oy] = true;
			    while(hh <= tt){
			        auto t = q[hh ++];
			        //开始遍历点t周围的8个合法元素
			        for(int i = t.x - 1; i <= t.x + 1; i++){
			            for(int j = t.y - 1; j <= t.y + 1; j++){
			                if(i == t.x && j == t.y) continue;
			                if(i < 0 || i >= n || j < 0 || j >= m || st[i][j]) continue;
			                if(g[i][j] == '.') continue;
			                st[i][j] = true;
			                q[++ tt] = {i, j};
			            }
			        }
			    }
			}
			int main(){
			    scanf("%d%d", &n, &m);
				for(int i = 0; i < n; i ++) scanf("%s", g[i]);
				for(int i = 0; i < n; i++){
				    for(int j = 0; j < m; j++){
				        if(g[i][j] == 'W' && !st[i][j]){
				            dfs(i, j);
				            res ++;
				        }
				    }
				}
				cout << res << endl;
				return 0;
			}
			--
			#include <iostream>
			using namespace std;
			const int N = 1010, M = N * N;
			typedef pair<int, int> PII;
			PII q[M];
			bool st[N][N];
			char g[N][N];
			int n, m, cnt;
			void dfs(int ox, int oy){
			    int hh = 0, tt = -1;
			    q[++ tt] = {ox, oy};
			    st[ox][oy] = true;
			    while(hh <= tt){
			        auto t = q[hh ++];
			        int x = t.first, y = t.second;
			        for(int i = x - 1; i <= x + 1; i++){
			            for(int j = y - 1; j <= y + 1; j++){
			                if(i == x && j == y) continue;
			                if(i < 0 || i >= n || j < 0 || j >= m || st[i][j] || g[i][j] == '.') continue;
			                q[++ tt] = {i, j};
			                st[i][j] = true;
			            }
			        }
			    }
			}
			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 0; i < n; i++) scanf("%s", g[i]);
			    for(int i = 0; i < n; i++){
			        for(int j = 0; j < m; j++){
			            if(!st[i][j] && g[i][j] == 'W'){
			                dfs(i, j);
			                cnt ++;
			            }
			        }
			    }
			    cout << cnt << endl;
			}
	2. AcWing 1098. 城堡问题
		1. bug 
		2. ok {顺利}
			#include <iostream>
			using namespace std;
			const int N = 60, M = N * N;
			typedef pair<int, int> PII;
			#define x first
			#define y second
			PII q[M];
			bool st[N][N];
			int g[N][N];
			int n, m, area, cnt;
			int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
			int bfs(int ox, int oy){
			    int hh = 0, tt = -1;
			    写法1: int temparea = 0;
			    q[++tt] = {ox, oy};
			    st[ox][oy] = true;
			    while(hh <= tt){
			        auto t = q[hh ++];
			        写法1: 记录q中历史上存了多少个元素, 就看q弹出了几个
			        写法1: temparea ++;
			        for(int i = 0; i < 4 ; i++){
			            int tx = t.x + dx[i], ty = t.y + dy[i];
			            if(tx < 0 || tx >= n || ty < 0 || ty >= m || st[tx][ty]) continue;
			            if(g[t.x][t.y] >> i & 1) continue;
			            q[++ tt] = {tx, ty};
			            st[tx][ty] = true;
			        }
			    }
			    写法2: return tt + 1; 因为tt是从0开始的, 写法2适用于我们用数组创建的queue
			    写法1: return temparea; 写法1适用于stl的queue
			}
			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 0; i < n; i++){
			        for(int j = 0; j < m ; j++) scanf("%d", &g[i][j]);
			    }
			    for(int i = 0; i < n; i++){
			        for(int j = 0 ; j < m; j++){
			            if(!st[i][j]){
			                area = max(area, bfs(i, j));
			                cnt ++;
			            }
			        }
			    }
			    cout << cnt << endl;
			    cout << area << endl;
			    return 0;
			}
			--
			#include <iostream>
			using namespace std;
			const int N = 60, M = N * N;
			typedef pair<int, int> PII;
			#define x first
			#define y second
			PII q[M];
			bool st[N][N];
			int g[N][N];
			int n, m, maxa, cnt;
			int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
			int bfs(int ox, int oy){
			    int hh = 0, tt = -1;
			    q[++ tt] = {ox, oy};// 先挪出空地, 然后放入 ++ tt
			    st[ox][oy] = true;
			    while(hh <= tt){
			        auto t = q[hh ++];
			        for(int i = 0; i < 4; i++){
			            int x = t.x + dx[i], y = t.y + dy[i];
			            if(x < 0 || x >= n || y < 0 || y >= m || st[x][y]) continue;
			            if(g[t.x][t.y] >> i & 1) continue; //精华: 我想去的格子是{x,y}, 但是我们要看{t.x, t.y}到{x, y}之间是否有墙
			            st[x][y] = true;
			            q[++ tt] = {x, y};
			        }
			    }
			    return tt + 1;
			}
			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 0; i < n; i++){
			        for(int j = 0; j < m ; j++) scanf("%d", &g[i][j]);
			    }
			    for(int i = 0 ; i < n; i++){
			        for(int j = 0 ; j < m; j++){
			            if(!st[i][j]){
			                maxa = max(maxa, bfs(i, j));
			                cnt ++;
			            }
			        }
			    }
			    cout << cnt << endl;
			    cout << maxa << endl;
			    return 0;
			}
11. 5.31
	3. AcWing 1106. 山峰和山谷
		0. 这道题不难, 注意逻辑就好
			0. 我们dfs的联通块是高度相同的元素
				不仅要涂满高度相同的元素
				而且对于连通块的边缘轮廓部分, 都要看看是否有高于或者低于自己的部分{我觉得有意思的地方!!}
			1. 4个分类:
				has_lower && has_higher: 
					这个连通块a的四周, 有比a高的, 也有比a低的
					所以a什么都不是
				!has_lower && has_higher: 
					这个连通块a的四周, 有比a高的, 但是没有比a低的
					所以a是 valley
				has_lower && !has_higher: 
					这个连通块a的四周, 有比a低的, 但是没有比a高的
					所以a是 peak
				!has_lower && !has_higher: 
					这个连通块a的四周, 没有比a低的, 也没有比a高的
					题目说: 说明a就是整个地图, 说明整个地图都有相同的高度，那么a即是山峰，又是山谷
					所以 valley ++, peak ++ 
			2. dfs的连通块
				1. 如果我的邻居{i,y}和我高度不同:
					1. 那么邻居不需要 !st[i,j], 也就是即便 邻居是被遍历过的 st[i,j] == true, 也没关系
					2. 如果邻居高, has_higher = true
					3. 如果邻居矮, has_lower = true
				2. 如果我的邻居{i,y}和我高度相同:
					就是普通的遍历联通块的逻辑
						q[++ tt] = {i, j};
			            st[i][j] = true;
		1. bug
			#include <iostream>
			using namespace std;
			const int N = 1010, M = N * N;
			typedef pair<int, int> PII;
			#define x first
			#define y second
			int g[N][N];
			PII q[M];
			bool st[N][N];
			int n, peak, valley;
			void dfs(int ox, int oy, bool &has_higher, bool &has_lower){
			    int hh = 0, tt = -1;
			    q[++ tt] = {ox, oy};
			    st[ox][oy] = true;
			    while(hh <= tt){
			        auto t = q[hh ++];
			        for(int i = t.x - 1; i <= t.x + 1; i++){
			            for(int j = t.y - 1; j <= t.y + 1; j++){
			                if(i == t.x && j == t.y) continue;
			                错误: if(i < 0 || i >= n || j < 0 || j > = n || st[i][j]) continue;
			                	一个非常无语的错误, 又是小书写错误导致了很难找: if(i < 0 || i >= n || j < 0 || j >= 0) continue; 发现了吗, 错在: j >= 0
			                正确: if(i < 0 || i >= n || j < 0 || j >= n) continue;
			                if(g[i][j] != g[t.x][t.y]){
			                    if(g[i][j] > g[t.x][t.y]) has_higher = true;
			                    else has_lower = true;
			                }
			                错误: else{
			                正确: else if(!st[i][j]){
			                    q[++ tt] = {i, j};
			                    st[i][j] = true;
			                }
			            }
			        }
			    }
			}

			int main(){
			    cin >> n;
			    for(int i = 0 ; i < n; i++){
			        for(int j = 0 ; j < n; j++) cin >> g[i][j];
			    }
			    for(int i = 0; i < n; i++){
			        for(int j = 0 ; j < n; j++){
			            正确: if(!st[i][j]){
			                bool has_higher = false, has_lower = false;
			                dfs(i, j, has_higher, has_lower); 
			                错误:
				                if(!has_higher) valley++;
				                if(!has_lower) peak++;
			                正确:
				                if(!has_higher) peak++;
				                if(!has_lower) valley++;
			            }
			            错误: 错在 if(!has_lower)应该写在 if(!st[i][j]) {} 里面
			            	if(!st[i][j])
				                dfs(i, j, has_higher, has_lower); // 为什么是传引用, 因为不像python可以返回两个值
				            if(!has_lower) peak++;
				            if(!has_higher) valley++;
			        }
			    }
			    cout << peak << " " << valley << endl;
			    return 0;
			}
		2. ok 
			#include <iostream>
			using namespace std;
			const int N = 1010, M = N * N;
			typedef pair<int, int> PII;
			#define x first
			#define y second
			PII q[M];
			int g[N][N];
			bool st[N][N];
			int n, peak, valley;
			void bfs(int ox, int oy, bool &has_higher, bool &has_lower){ // 为什么是传引用, 因为不像python可以返回两个值
			    int hh = 0, tt = -1;
			    q[++ tt] = {ox, oy};
			    st[ox][oy] = true;
			    while(hh <= tt){
			        auto t = q[hh ++];
			        for(int i = t.x - 1; i <= t.x + 1; i++){
			            for(int j = t.y - 1; j <= t.y + 1; j++){
			                if(i == t.x && j == t.y) continue;
			                if(i < 0 || i >= n || j < 0 || j >= n) continue;
			                int &nn = g[i][j], &oo = g[t.x][t.y];
			                if(nn != oo){
			                    if(nn < oo) has_lower = true;
			                    else has_higher = true;
			                }else if(!st[i][j]){
			                    q[++ tt] = {i, j};
			                    st[i][j] = true;
			                }
			            }
			        }
			    }
			}
			int main(){
			    scanf("%d", &n);
			    for(int i = 0 ; i < n; i ++)
			        for(int j = 0 ; j < n; j++) scanf("%d", &g[i][j]);
			    for(int i = 0 ; i < n; i++){
			        for(int j = 0 ; j < n; j++){
			            if(!st[i][j]){
			                bool has_higher = false, has_lower = false;
			                bfs(i, j, has_higher, has_lower);
			                if(!has_higher) peak++;
			                if(!has_lower) valley++;
			            }
			        }
			    }
			    cout << peak << " " << valley << endl;
			    return 0;
			}
	4. AcWing 1076. 迷宫问题
		0. 注意语法:
			PII cur(0, 0);	也就是初始化: PII cur = {0, 0};
			cur = ne[cur.x][cur.y];
		1. bug
			1. 写法1: 我更习惯: 用st, 输出的时候考虑是否 == -1
				#include <iostream>
				#include <cstring>
				using namespace std;
				const int N = 1010, M = N * N;
				typedef pair<int, int> PII;
				#define x first
				#define y second
				PII q[M];
				PII ne[N][N];
				写法1: bool st[N][N];
				int g[N][N], n;
				int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 
				void bfs(int ox, int oy){
				    int hh = 0, tt = -1;
				    q[++ tt] = {ox, oy};
				    st[ox][oy] = true;
				    while(hh <= tt){
				        auto t = q[hh ++];
				        for(int i = 0 ; i < 4 ; i++){
				            int a = t.x + dx[i], b = t.y + dy[i];
				            if(a < 0 || a >= n || b < 0 || b >= n) continue;
				            写法1: if(st[a][b] || g[a][b]) continue;
				            st[a][b] = true;
				            q[++ tt] = {a, b};
				            错误: ne[a][b] = {ox, oy}; --------
				            正确: ne[a][b] = {t.x, t.y};
				            if(a == 0 && b == 0) break;
				        }
				    }
				}
				int main(){
				    cin >> n;
				    for(int i = 0 ; i < n; i++){
				        for(int j = 0 ; j < n; j++) cin >> g[i][j];
				    }
				    memset(ne, -1, sizeof ne);
				    bfs(n - 1, n - 1);
				    PII cur(0, 0);
				    while(true){
				        cout << cur.x << " " << cur.y << endl;
				        cur = ne[cur.x][cur.y];
				        写法1: if(cur.x == -1 && cur.y == -1) break;
				    }
				}
			写法2: 老师的: 不用st, 输出的时候考虑是否 == n - 1. 
				原因, 因为不用st, 我们是用 ne ?== -1来判断是否遍历过
				我们会让所有的点, 包括终点的pre最后都是 != -1
				所以输出的时候就不能是 ne ?== -1, 因为都不等于-1, 于是就会无穷尽输出 

				#include <iostream>
				#include <cstring>
				using namespace std;
				const int N = 1010, M = N * N;
				typedef pair<int, int> PII;
				#define x first
				#define y second
				PII q[M];
				PII ne[N][N];
				int g[N][N], n;
				int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 
				void bfs(int ox, int oy){
				    int hh = 0, tt = -1;
				    q[++ tt] = {ox, oy};
				    st[ox][oy] = true;
				    while(hh <= tt){
				        auto t = q[hh ++];
				        for(int i = 0 ; i < 4 ; i++){
				            int a = t.x + dx[i], b = t.y + dy[i];
				            if(a < 0 || a >= n || b < 0 || b >= n) continue;
				            错误: if(ne[a][b].x == -1 || g[a][b]) continue;	
				            正确: if(ne[a][b].x != -1 || g[a][b]) continue;	如果已经被遍历过: != -1, 就下一个
				            if(st[a][b] || g[a][b]) continue;
				            st[a][b] = true;
				            q[++ tt] = {a, b};
				            错误: ne[a][b] = {ox, oy}; --------
				            正确: ne[a][b] = {t.x, t.y};
				            if(a == 0 && b == 0) break;
				        }
				    }
				}
				int main(){
				    cin >> n;
				    for(int i = 0 ; i < n; i++){
				        for(int j = 0 ; j < n; j++) cin >> g[i][j];
				    }
				    memset(ne, -1, sizeof ne);
				    bfs(n - 1, n - 1);
				    PII cur(0, 0);
				    while(true){
				        写法1:
					        cout << cur.x << " " << cur.y << endl;
					        cur = ne[cur.x][cur.y];
					        if(cur.x == -1 && cur.y == -1) break;	如果刚才下一个的数字是非法值, ok可以停了
					    写法2:
					    	cout << cur.x << " " << cur.y << endl;
					        if(cur.x == n - 1 && cur.y == n - 1) break; 如果刚才输出的数字是终点, ok可以停了
					        cur = ne[cur.x][cur.y];
				    }
				}
		2. ok
			#include <iostream>
			#include <cstring>
			using namespace std;
			const int N = 1010, M = N * N;
			typedef pair<int, int> PII;
			#define x first
			#define y second
			PII q[M];
			PII ne[N][N];
			bool st[N][N];
			int g[N][N], n;
			int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 
			void bfs(int ox, int oy){
			    int hh = 0, tt = -1;
			    q[++ tt] = {ox, oy};
			    st[ox][oy] = true;
			    while(hh <= tt){
			        auto t = q[hh ++];
			        for(int i = 0; i < 4; i++){
			            int a = t.x + dx[i], b = t.y + dy[i];
			            if(a < 0 || a >= n || b < 0 || b >= n) continue;
			            if(st[a][b] || g[a][b]) continue;
			            q[++ tt] = {a, b};
			            st[a][b] = true;
			            ne[a][b] = {t.x, t.y};
			            if(a == 0 && b == 0) break;
			        }
			    }
			    
			}
			int main(){
			    cin >> n;
			    for(int i = 0 ; i < n; i++){
			        for(int j = 0 ; j < n; j++) cin >> g[i][j];
			    }
			    memset(ne, -1, sizeof ne);
			    bfs(n - 1, n - 1);
			    PII cur = {0, 0};
			    while(true){
			        cout << cur.x << " " << cur.y << endl;
			        cur = ne[cur.x][cur.y];
			        if(cur.x == -1) break;
			    }
			    return 0;
			}
	5. AcWing 188. 武士风度的牛
		1. bug
		2. ok{很顺}
			#include <iostream>
			using namespace std;
			const int N = 160, M = N * N;
			typedef pair<int, int> PII;
			#define x first
			#define y second
			PII q[M];
			int dist[N][N];
			bool st[N][N];
			char g[N][N];
			int n, m, res;
			int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
			int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
			int bfs(int ox, int oy){
			    int hh = 0, tt = -1;
			    q[++ tt] = {ox, oy};
			    st[ox][oy] = true;
			    while(hh <= tt){
			        auto t = q[hh ++];
			        for(int i = 0 ; i < 8; i++){
			            int a = t.x + dx[i], b = t.y + dy[i];
			            if(a < 0 || a >= n || b < 0 || b >= m) continue;
			            if(st[a][b] || g[a][b] == '*') continue;
			            q[++ tt] = {a, b};
			            st[a][b] = true;
			            dist[a][b] = dist[t.x][t.y] + 1;	说明从 {t.x, t.y} -> {a, b}跳了一步
			            if(g[a][b] == 'H') return dist[a][b];
			        }
			    }
			    return -1; 
			}
			int main(){
			    cin >> m >> n;
			    for (int i = 0; i < n; i ++ ) cin >> g[i];
			    for(int i = 0 ; i < n; i++){
			        for(int j = 0; j < m; j++){
			            if(g[i][j] == 'K'){
			                res = bfs(i, j);
			                break;
			            }
			        }
			    }
			    cout << res << endl;
			    return 0;
			}
	6. AcWing 1100. 抓住那头牛
		1. bug
		2. ok {之前觉得复杂, 现在觉得超级简单, 顺利}
			#include <iostream>
			using namespace std;
			const int N = 1e5 + 10;
			int g[N], q[N], dist[N]; 	dist[i]: 数字i在图上距离数字起点a的最短距离 
			bool st[N];
			int a, b;
			int bfs(int a, int b){
			    int hh = 0, tt = -1;
			    q[++ tt] = a;
			    st[a] = true;
			    dist[a] = 0;
			    while(hh <= tt){
			        int t = q[hh ++];
			        if(t == b) return dist[b];
			        //遍历3个邻点:
			        int ne[3] = {t - 1, t + 1, t * 2};
			        for(int i : ne){
			            if(0 <= i && i < N && !st[i]){	只要是合法的
			                q[++ tt] = i;
			                st[i] = true;
			                dist[i] = dist[t] + 1;
			            }
			        }
			    }
			    return dist[b];
			}
			int main(){
			    cin >> a >> b;
			    cout << bfs(a, b) << endl;
			    return 0;
			}
	7. AcWing 173. 矩阵距离
		1. bug{无语的bug, 输入的问题, 其他都很顺}
			#include <iostream>
			using namespace std;
			const int N = 1010, M = N * N;
			typedef pair<int, int> PII;
			#define x first
			#define y second
			char g[N][N];
			PII q[M];
			bool st[N][N];
			int dist[N][N];
			int n, m;
			int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
			void bfs(){
			    int hh = 0, tt = -1;
			    for(int i = 0 ; i < n; i++){
			        for(int j = 0 ; j < m; j++){
			            if(g[i][j] == '1'){
			                q[++ tt] = {i, j};
			                st[i][j] = true;
			            }
			        }
			    }
			    while(hh <= tt){
			        auto t = q[hh ++];
			        for(int i = 0 ; i < 4; i ++){
			            int a = t.x + dx[i], b = t.y + dy[i];
			            if(a < 0 || a >= n || b < 0 || b >= m) continue;
			            错误: if(st[a][b] || g[a][b]) continue;
			            正确: if(st[a][b] || g[a][b] == '1') continue; 因为读入是char
			            dist[a][b] = dist[t.x][t.y] + 1;
			            st[a][b] = true;
			            q[++ tt] = {a, b};
			        }
			    }
			}
			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 0; i < n; i++) scanf("%s", g[i]); 读的是一整行 
			    bfs();
			    for(int i = 0 ; i < n; i++){
			        for(int j = 0; j < m; j++)
			        {
			            cout << dist[i][j] << " ";
			        }
			        cout << endl;
			    }
			    return 0;
			}
		2. ok: 我还是习惯用 st[] 来代替 dist[]是否为-1
			逻辑非常简单, 见 practice_advanced.cpp 
			#include <iostream>
			using namespace std;
			const int N = 1010, M = N * N;
			typedef pair<int, int> PII;
			#define x first
			#define y second
			char g[N][N];
			PII q[M];
			bool st[N][N];
			int dist[N][N]; //dist[i][j] 这是0类点{i,j}距离最近的1类点的最近距离
			int n, m;
			int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
			void bfs(){
			    int hh = 0, tt = -1;
			    for(int i = 0 ; i < n; i++){
			        for(int j = 0; j < m; j++){
			            if(g[i][j] == '1'){
			                q[++ tt] = {i, j};
			                st[i][j] = true;
			            }
			        }
			    }
			    while(hh <= tt){
			        auto t = q[hh ++];
			        for(int i = 0 ; i < 4; i ++){
			            int a = t.x + dx[i], b = t.y + dy[i];
			            if(a < 0 || a >= n || b < 0 || b >= m) continue;
			            if(st[a][b] || g[a][b] == '1') continue; //如果这个点已经被遍历过, 或者这个点是1类点{我们要去的终点是0类点, 所以不要理会1类点}, 就跳过
			            dist[a][b] = dist[t.x][t.y] + 1; //这个就是1类点的连通块, bfs层序遍历, 先遍历到的距离最近, 因为每个dis == 1 
			            q[++ tt] = {a, b};
			            st[a][b] = true;
			        }
			    }
			}
			int main(){
			    scanf("%d%d", &n, &m);
			    for(int i = 0; i < n; i++) scanf("%s", g[i]);
			    bfs();
			    for(int i = 0; i < n; i++){
			        for(int j = 0 ; j < m; j++){
			            cout << dist[i][j] << " ";
			        }
			        cout << endl;
			    }
			    return 0;
			}
	8. AcWing 1107. 魔板
		0. 小总结:
			其实这道题, 并不难.
			主要是: 我们怎么计算从一个 string -三种操作-> 另一个string
				需要一个 char g[2][4];
				一个 string "--变为-->" g[2][4] "--在g[][]上才能进行三种操作-->" 另一个string
		0. 比较:
			二维图 vs string:
				st:
					bool st[N][N];
					unordered_map<string, bool> st;
				queue:
					PII q[N] / queue<PII> q;
					string q[N] / queue<string> q;
				dist:
					int dist[N][N];		想象画面, 容器的形状: [][], 容器装的: int
					unordered_map<string, int> dist;
				pre:
					PII pre[N][N];
					unordered_map<string, string> pre; / unordered_map<string, pair<int, string>> pre; 后者主要是记录了操作编号
		1. bug{不难, 主要是细节}
			主要的bug都是小bug:
				1. 
					错误: string q[N]; 没有pop, 所以会有segmentation fault 
					正确: 应该是 queue<string> q; 因为有pop, 所以不会超出界限
				2. 输出的截止, 见code 
			#include <iostream>
			#include <unordered_map>
			#include <algorithm>
			#include <queue>
			using namespace std;
			const int N = (1 << 8) + 10;
			char g[3][5];
			string start, endd;
			queue<string> q;
			unordered_map<string, bool> st;
			unordered_map<string, pair<int, string>> pre;
			unordered_map<string, int> dist;
			void tog(string str){
			    for(int i = 0; i < 4; i++) g[0][i] = str[i];
			    for(int i = 7, j = 0; j < 4; i --, j ++) g[1][j] = str[i]; 
			}
			string tostr(){
			    string res;
			    for(int i = 0; i < 4; i ++) res += g[0][i];
			    for(int i = 3; i >= 0; i--) res += g[1][i];
			    return res;
			}
			string act1(string prev){
			    tog(prev);
			    for(int i = 0; i < 4; i++) swap(g[0][i], g[1][i]);
			    return tostr();
			}

			string act2(string prev){
			    tog(prev);
			    int a = g[0][3], b = g[1][3];
			    for(int i = 3; i >= 1; i--){
			        g[0][i] = g[0][i-1];
			        g[1][i] = g[1][i-1];
			    }
			    g[0][0] = a, g[1][0] = b;
			    return tostr();
			}

			string act3(string prev){
			    tog(prev);
			    int a = g[0][1];
			    g[0][1] = g[1][1];
			    g[1][1] = g[1][2];
			    g[1][2] = g[0][2];
			    g[0][2] = a;
			    return tostr();
			}

			int bfs(){
			    if (start == endd) return 0;
			    int hh = 0, tt = -1;
			    q.push(start);
			    st[start] = true;
			    dist[start] = 0;
			    pre[start] = {-1, ""};
			    while(q.size()){
			        string t = q.front(); q.pop();
			        string ne[3];
			        ne[0] = act1(t);
			        ne[1] = act2(t);
			        ne[2] = act3(t);
			        for(int i = 0 ; i < 3; i++){
			            string nn = ne[i];
			            if(st.count(nn)) continue;
			            dist[nn] = dist[t] + 1;
			            pre[nn] = {i, t};
			            q.push(nn);
			            st[nn] = true;
			        }
			    }
			}
			int main(){
			    for(int i = 1; i <= 8; i++){
			        char c;
			        cin >> c;
			        start += (i + '0');
			        endd += c;
			    }
			    bfs();
			    cout << dist[endd] << endl;
			    if(dist[endd] > 0){
				    string res;
				    string cur = endd;
				    错误: 因为我们的res, 不需要 start的pre, 所以我们不希望cur是start, 
			    	    while(true){
			    	        char op = pre[cur].first + 'A';
			    	        res += op;
			    	        cur = pre[cur].second;
			    	        if(cur == "") break;
			    	    } //错在: 最后的op是"@", 因为最后的 pre[cur].first 是  pre[start].first = -1;
			    	正确: 
			    		while(true){
			    			if(cur == start) break;
			    	        char op = pre[cur].first + 'A';
			    	        res += op;
			    	        cur = pre[cur].second;
			    	    }
			    	    更简洁的:
			    	    while(cur != start){
			    	        char op = pre[cur].first + 'A';
			    	        res += op;
			    	        cur = pre[cur].second;
			    	    }
				    错误: reverse(res, res + 8);
				    正确: reverse(res.begin(), res.end());
				    cout << res << endl;
			    }
			    return 0;
			}
		2. ok 
	9. AcWing 175. 电路维修
		0. 小总结:
			1. dfs() 什么时候 st[xx] = true?
				代码:
					...
					while(hh <= tt){
						auto t = q[hh ++];
						"如果st[xx] = true写在这里: 保守写法", 在这里弹出来的肯定是找到了 dist[t]的最小值 
							我们的q如果是queue, 说明我们可以保证queue中是单增的, 例如dis都==1的简单层序bfs
							我们的q如果是priorirty_queue, 说明我们需要priorirty_queue帮我们排序
						"保守写法适用于": 存在 !=1的边权，所以某些点可能需要被扩展多次。例如本题, 边权==0或者==1都有可能

						for(遍历t的邻点i){
							if(各种条件){
								"如果st[xx] = true写在这里: 激进写法"
									之所以激进, 是因为我们敢说, 一插入q就是已经找到了 dist[t]的最小值 
								"激进写法适用于": 只存在-=1的边权，点只会被扩展一次。
							}
						}

					}
			2. 各种偏移:
				1. 4联通
					int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
				2. 8联通
					for(int i = t.x - 1; i <= t.x + 1; i ++)
						for(int j = t.y - 1; j <= t.y + 1; j ++)
				3. 日字
					int dx[4] = {-2, -1, 1, 2, 2, 1, -1, -2};
					int dy[4] = {1, 2, 2, 1, -1, -2, -2, -1}; //
				4. 本题的对角线连接:
				    要去的目标点: 
				    	int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
				    到目标点需要经过的格子: 
				    	int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};	
				    格子的对角线, 如果是以下的情况, 则代价==0: 
				    	char cs[] = "\\/\\/";
				记忆:
					1. easy
					2. easy
					3. 图画:
				    		{-2, -1, 1, 2, 2, 1, -1, -2} 美国: 楼起楼落

				    		2			/ \
				    		1		   /   \
				    		-1		  /     \
				    		-2		 /       \

				    		{1, 2, 2, 1, -1, -2, -2, -1}; 中国近代: 顶峰, 谷底, 恢复 {恢复的不如以前}
				    		2			/ \
				    		1		   /   \
				    		-1		  	    \    /
				    		-2		 	     \  /
				    4. 图画:
				    	int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
				    		1 		- - 	 - - 
				    		       /        /   \
				    		-1	- -     , --     --
				    	int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};	
				    		0 		- - 	 - - 
				    		       /        /   \
				    		-1	- -     , --     --
				    	char cs[] = "\\/\\/";
		1. bug
			#include <iostream>
			#include <queue>
			#include <cstring>
			using namespace std;
			const int N = 510;
			typedef pair<int, int> PII;
			#define x first
			#define y second
			错误: queue<PII> q;
			正确: deque<PII> q;	我们需要双端的 
			bool st[N][N];
			int dist[N][N];
			char g[N][N];
			int n, m, w;
			int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
			int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};
			char cs[] = "\\/\\/";

			int bfs(){
			    q.push_back({0, 0});
			    dist[0][0] = 0;
			    错误: 这是激进写法, 也就是一插入queue就是dist[x][y]找到最优: st[0][0] = true;
			    	但是我们会有一句 if(st[t.x][t.y]) continue; 筛除, 所以不能写这里
			    正确: 不写 
			    while(q.size()){
			        错误:  auto t = q.front(); q.pop();
			        正确: auto t = q.front(); q.pop_front(); 是pop前面的
			        if(st[t.x][t.y]) continue;
			        st[t.x][t.y] = true; //保守写法, 因为存在 !=1的边权, 所以可能某个点会被多次更新
			        
			        for(int i = 0; i < 4; i++){
			            int a = t.x + dx[i], b = t.y + dy[i];
			            错误: if(a < 0 || a >= n || b < 0 || b >= m) continue;	这里是对角线问题, 所以我们的有效范围是[0, n], 以前格子的问题有效范围只是[0, n-1]
			            正确: if(a < 0 || a >= n + 1 || b < 0 || b >= m + 1) continue;
			            if(st[a][b]) continue;
			            //走肯定能走到: 左上, 右上, 左下, 右下, 但是代价是多少?
			            int ga = t.x + ix[i], gb = t.y + iy[i]; //需要查看的格子的坐标{ga, gb}
			            int cost = 0;
			            if(g[ga][gb] != cs[i]) cost = 1;
			            if(dist[t.x][t.y] + cost < dist[a][b]){
			                dist[a][b] = dist[t.x][t.y] + cost;
			                if(cost) q.push_back({a, b});
			                else q.push_front({a, b});
			            }
			        }
			    }
			    错误: return dist[n-1][m-1];
			    正确: return dist[n][m];		这里是对角线, 所以我们的有效范围是[0, n]
			}

			int main(){
			    cin >> w;
			    while(w--){
			        cin >> n >> m;
			        memset(dist, 0x3f, sizeof dist);
			        memset(st, 0, sizeof st);
			        q.clear();
			        for(int i = 0; i < n; i++) scanf("%s", g[i]);
			        int res = bfs();
			        if(res >= 0x3f3f3f3f / 2) puts("NO SOLUTION");
			        else cout << res << endl;
			    }
			    return 0;
			}
		2. ok 

	-- 10. AcWing 190. 字串变换
	todo 11. AcWing 178. 第K短路
	todo 12. AcWing 179. 八数码
	-- 13. AcWing 1112. 迷宫
	-- 14. AcWing 1113. 红与黑
	-- 15. AcWing 1116. 马走日
	-- 16. AcWing 1117. 单词接龙
	-- 17. AcWing 1118. 分成互质组
	-- 18. AcWing 165. 小猫爬山
	todo 19. AcWing 166. 数独
	todo 20. AcWing 167. 木棒
	todo 21. AcWing 168. 生日蛋糕
	-- 22. AcWing 170. 加成序列
	todo 23. AcWing 171. 送礼物
	todo 24. AcWing 180. 排书
	todo 25. AcWing 181. 回转游戏
12. 6.2 
	26. AcWing 1015. 摘花生
	27. AcWing 1018. 最低通行费
	28. AcWing 1027. 方格取数
	29. AcWing 275. 传纸条
	30. AcWing 1017. 怪盗基德的滑翔翼
	31. AcWing 1014. 登山
	32. AcWing 482. 合唱队形
	33. AcWing 1012. 友好城市
	34. AcWing 1016. 最大上升子序列和
	35. AcWing 1010. 拦截导弹
	36. AcWing 187. 导弹防御系统
	37. AcWing 272. 最长公共上升子序列
	38. AcWing 423. 采药
	39. AcWing 1024. 装箱问题
	40. AcWing 1022. 宠物小精灵之收服
	AcWing 278. 数字组合
	AcWing 1023. 买书
	AcWing 1021. 货币系统
	AcWing 532. 货币系统
	AcWing 6. 多重背包问题 III
	AcWing 1019. 庆功会
	AcWing 7. 混合背包问题
	AcWing 8. 二维费用的背包问题
	AcWing 1020. 潜水员
	AcWing 1013. 机器分配8
	AcWing 426. 开心的金明
	AcWing 10. 有依赖的背包问题
	AcWing 11. 背包问题求方案数
	AcWing 12. 背包问题求具体方案
	AcWing 734. 能量石
	AcWing 487. 金明的预算
	AcWing 1049. 大盗阿福
	AcWing 1057. 股票买卖 IV
	AcWing 1058. 股票买卖 V
	AcWing 1052. 设计密码
	AcWing 1053. 修复DNA
	AcWing 1064. 小国王
	AcWing 327. 玉米田
	AcWing 292. 炮兵阵地
	AcWing 524. 愤怒的小鸟
	AcWing 529. 宝藏
	AcWing 1068. 环形石子合并
	AcWing 320. 能量项链
	AcWing 479. 加分二叉树
	AcWing 1069. 凸多边形的划分
	AcWing 321. 棋盘分割
	AcWing 1072. 树的最长路径
	AcWing 1073. 树的中心
	AcWing 1075. 数字转换
	AcWing 1074. 二叉苹果树
	AcWing 323. 战略游戏
	AcWing 1077. 皇宫看守
	AcWing 1081. 度的数量
	AcWing 1082. 数字游戏
	AcWing 1083. Windy数
	AcWing 1084. 数字游戏 II
	AcWing 1085. 不要62
	AcWing 1086. 恨7不成妻
	AcWing 135. 最大子序和
	AcWing 1087. 修剪草坪
	AcWing 1088. 旅行问题
	AcWing 1089. 烽火传递
	AcWing 1090. 绿色通道
	AcWing 1091. 理想的正方形
	AcWing 300. 任务安排
	AcWing 301. 任务安排
	AcWing 302. 任务安排
	AcWing 303. 运输小猫
12. 6.3
	-- AcWing 1129. 热浪
	-- AcWing 1128. 信使
	-- AcWing 1127. 香甜的黄油
	todo AcWing 1126. 最小花费
	todo AcWing 920. 最优乘车
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	todo AcWing 903. 昂贵的聘礼
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	xx AcWing 1135. 新年好
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 340. 通信线路
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 342. 道路与航线
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 341. 最优贸易
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1137. 选择最佳线路
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1131. 拯救大兵瑞恩
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1134. 最短路计数
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 383. 观光
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1125. 牛的旅行
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 343. 排序
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 344. 观光之旅
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 345. 牛站
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1140. 最短网络
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1141. 局域网
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1142. 繁忙的都市
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1143. 联络员
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1144. 连接格点
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1146. 新的开始
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1145. 北极通讯网络
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 346. 走廊泼水节
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1148. 秘密的牛奶运输
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 904. 虫洞
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 361. 观光奶牛
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1165. 单词环
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1169. 糖果
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 362. 区间
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1170. 排队布局
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 393. 雇佣收银员
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1172. 祖孙询问
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1171. 距离
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 356. 次小生成树
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 352. 闇の連鎖
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1174. 受欢迎的牛
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 367. 学校网络
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1175. 最大半连通子图
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 368. 银河
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 395. 冗余路径
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1183. 电力
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 396. 矿场搭建
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 257. 关押罪犯
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 372. 棋盘覆盖
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 376. 机器任务
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 378. 骑士放置
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 379. 捉迷藏
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1123. 铲雪车
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1184. 欧拉回路
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1124. 骑马修栅栏
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1185. 单词游戏
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1191. 家谱树
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 1192. 奖金
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 164. 可达性统计
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	AcWing 456. 车站分级
		0. bug
		1. 笔记
		2. 注释
		3. 5次
			r1.
			r2.
			r3.
			r4.
			r5.
	3. 基础算法
		位运算
			AcWing 90. 64位整数乘法
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		递推与递归
			AcWing 95. 费解的开关
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 97. 约数之和
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 98. 分形之城
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		前缀和与差分
			AcWing 99. 激光炸弹
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 100. 增减序列
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		二分
			AcWing 102. 最佳牛围栏
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 113. 特殊排序
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		排序
			AcWing 105. 七夕祭
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 106. 动态中位数
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 107. 超快速排序
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		RMQ
			AcWing 1273. 天才的记忆
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
	4. 高级数据结构 
		并查集
			AcWing 1250. 格子游戏
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1252. 搭配购买
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 237. 程序自动分析
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 239. 奇偶游戏
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 238. 银河英雄传说
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		树状数组
			AcWing 241. 楼兰图腾
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 242. 一个简单的整数问题
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 243. 一个简单的整数问题
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 244. 谜一样的牛
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		线段树
			AcWing 1275. 最大数
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 245. 你能回答这些问题吗
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 246. 区间最大公约数
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 243. 一个简单的整数问题
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 247. 亚特兰蒂斯
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1277. 维护序列
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		可持久化数据结构
			AcWing 256. 最大异或和
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 255. 第K小数
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		平衡树
			AcWing 253. 普通平衡树
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 265. 营业额统计
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		AC自动机
			AcWing 1282. 搜索关键词
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1285. 单词
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
	5. 动态规划 
		数字三角形模型
			AcWing 1015. 摘花生
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1018. 最低通行费
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1027. 方格取数
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 275. 传纸条
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		最长上升子序列模型
			AcWing 1017. 怪盗基德的滑翔翼
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1014. 登山
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 482. 合唱队形
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1012. 友好城市
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1016. 最大上升子序列和
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1010. 拦截导弹
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 187. 导弹防御系统
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 272. 最长公共上升子序列
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		背包模型
			AcWing 423. 采药
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1024. 装箱问题
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1022. 宠物小精灵之收服
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 278. 数字组合
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1023. 买书
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1021. 货币系统
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 532. 货币系统
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 6. 多重背包问题 III
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1019. 庆功会
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 7. 混合背包问题
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 8. 二维费用的背包问题
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1020. 潜水员
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1013. 机器分配
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 426. 开心的金明
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 10. 有依赖的背包问题
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 11. 背包问题求方案数
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 12. 背包问题求具体方案
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 734. 能量石
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 487. 金明的预算方案
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		状态机模型
			AcWing 1049. 大盗阿福
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1057. 股票买卖 IV
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1058. 股票买卖 V
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1052. 设计密码
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1053. 修复DNA
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		状态压缩DP
			AcWing 1064. 小国王
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 327. 玉米田
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 292. 炮兵阵地
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 524. 愤怒的小鸟
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 529. 宝藏
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		区间DP
			AcWing 1068. 环形石子合并
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 320. 能量项链
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 479. 加分二叉树
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1069. 凸多边形的划分
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 321. 棋盘分割
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		树形DP
			AcWing 1072. 树的最长路径
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1073. 树的中心
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1075. 数字转换
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1074. 二叉苹果树
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 323. 战略游戏
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1077. 皇宫看守
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		数位DP
			AcWing 1081. 度的数量
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1082. 数字游戏
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1083. Windy数
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1084. 数字游戏 II
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1085. 不要62
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1086. 恨7不成妻
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		单调队列优化DP
			AcWing 135. 最大子序和
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1087. 修剪草坪
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1088. 旅行问题
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1089. 烽火传递
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1090. 绿色通道
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1091. 理想的正方形
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		斜率优化DP
			AcWing 300. 任务安排1
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 301. 任务安排2
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 302. 任务安排
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 303. 运输小猫
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
	6. 数学知识 
		筛质数
			AcWing 1292. 哥德巴赫猜想
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1293. 夏洛克和他的女朋友
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 196. 质数距离
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		分解质因数
			AcWing 197. 阶乘分解
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		快速幂
			AcWing 1289. 序列的第k个数
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1290. 越狱
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		约数个数
			AcWing 1291. 轻拍牛头
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1294. 樱花
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 198. 反素数
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 200. Hankson的趣味题
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		欧拉函数
			AcWing 201. 可见的点
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 220. 最大公约数
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		同余
			AcWing 203. 同余方程
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 222. 青蛙的约会
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 202. 最幸运的数字
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1298. 曹冲养猪
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		矩阵乘法
			AcWing 1303. 斐波那契前 n 项和
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1304. 佳佳的斐波那契
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1305. GT考试
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		组合计数
			AcWing 1307. 牡牛和牝牛
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1308. 方程的解
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1309. 车的放置
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1310. 数三角形
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1312. 序列统计
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1315. 网格
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1316. 有趣的数列
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		高斯消元
			AcWing 207. 球形空间产生器
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 208. 开关问题
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		容斥原理
			AcWing 214. Devu和鲜花
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 215. 破译密码
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		概率与数学期望
			AcWing 217. 绿豆蛙的归宿
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 218. 扑克牌
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
		博弈论
			AcWing 1319. 移棋子游戏
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1321. 取石子
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			AcWing 1322. 取石子游戏
				0. bug
				1. 笔记
				2. 注释
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
13. 6.3
	第十四章 基础算法与数据结构
		1. AcWing 1506. 中位数150人打卡
		2. AcWing 1530. 最短距离130人打卡
		3. AcWing 1571. 完美序列116人打卡
		4. AcWing 1581. 急性中风93人打卡
		5. AcWing 1641. 狼人杀-简单版91人打卡
		6. AcWing 1535. 弹出序列97人打卡
		7. AcWing 1541. 世界首富75人打卡
		8. AcWing 1543. 栈64人打卡
		9. AcWing 1607. 爱丁顿数87人打卡
		10. AcWing 1528. 火星购物71人打卡
		11. AcWing 1524. 最长回文子串94人打卡
	第十三章 链表
		1. AcWing 1516. 共享135人打卡
		2. AcWing 1560. 反转链表133人打卡
		3. AcWing 1587. 链表重复数据删除124人打卡
		4. AcWing 1626. 链表元素分类116人打卡
	第十二章 贪心
		1. AcWing 1521. 魔术卷99人打卡
		2. AcWing 1522. 排成最小的数字91人打卡
		3. AcWing 1553. 用 Swap(0, i) 操作进行排序76人打卡
		4. AcWing 1556. 月饼88人打卡
		5. AcWing 1603. 整数集合划分81人打卡
		6. AcWing 1618. 结绳80人打卡
		7. AcWing 1517. 是否加满油47人打卡
	第十一章 模拟
		1. AcWing 1480. 电梯145人打卡
		2. AcWing 1483. 世界杯投注125人打卡
		3. AcWing 1486. 排队等候78人打卡
		4. AcWing 1515. U 形 Hello World110人打卡
		5. AcWing 1525. 独一无二110人打卡
		6. AcWing 1526. 洗牌机101人打卡
		7. AcWing 1531. 课程学生列表96人打卡
		8. AcWing 1540. 主导颜色99人打卡
		9. AcWing 1542. 老鼠和大米88人打卡
		10. AcWing 1548. 才华与德行90人打卡
		11. AcWing 1551. A + B 和 C96人打卡
		12. AcWing 1555. 数字黑洞94人打卡
		13. AcWing 1566. 研究生入学62人打卡
		14. AcWing 1569. 成绩单87人打卡
		15. AcWing 1582. 买还是不买89人打卡
		16. AcWing 1585. 校园内的汽车63人打卡
		17. AcWing 1595. 螺旋矩阵78人打卡
		18. AcWing 1599. 合影68人打卡
		19. AcWing 1614. 单身狗84人打卡
		20. AcWing 1621. N 皇后问题72人打卡
		21. AcWing 1622. 推荐系统73人打卡
		22. AcWing 1625. 切整数78人打卡
		23. AcWing 1633. 外观数列70人打卡
		24. AcWing 1640. 堆74人打卡
	第十章 并查集
		1. AcWing 1485. 战争中的城市153人打卡
		2. AcWing 1604. 家产114人打卡
		3. AcWing 1608. 森林里的鸟137人打卡
		4. AcWing 1597. 社会集群117人打卡
		5. AcWing 836. 合并集合103人打卡
	第九章 哈希表
		1. AcWing 1532. 找硬币159人打卡
		2. AcWing 1549. 集合相似度147人打卡
		3. AcWing 1610. 朋友数144人打卡
		4. AcWing 1637. 漏掉的数字141人打卡
		5. AcWing 1642. 危险品装箱139人打卡
		6. AcWing 1564. 哈希128人打卡
		7. AcWing 1630. 期终成绩115人打卡
		8. AcWing 1638. 哈希 - 平均查找时间107人打卡
	第八章 动态规划
		1. AcWing 1479. 最大子序列和111人打卡
		2. AcWing 1529. 最佳彩色带93人打卡
		3. AcWing 1554. 找更多硬币81人打卡
		4. AcWing 1583. PAT 计数88人打卡
		5. AcWing 1591. 快速排序86人打卡
	第七章 数学完成情况：1/10
		1. AcWing 1533. 1 的个数125人打卡
		2. AcWing 1545. 质因子127人打卡
		3. AcWing 1567. 有理数的和115人打卡
		4. AcWing 1578. 有理数运算108人打卡
		5. AcWing 1586. 连续因子113人打卡
		6. AcWing 1593. 整数分解59人打卡
		7. AcWing 1594. 数段之和110人打卡
		8. AcWing 1602. 卡住的键盘91人打卡
		9. AcWing 1606. C 语言竞赛86人打卡
		10. AcWing 1646. 谷歌的招聘88人打卡
	第六章 图论完成情况：16/19
		1. AcWing 1475. 紧急情况198人打卡
		2. AcWing 1507. 旅行计划184人打卡
		3. AcWing 1518. 团伙头目155人打卡
		4. AcWing 1577. 条条大路通罗马155人打卡
		5. AcWing 1601. 在线地图129人打卡
		6. AcWing 1615. 哈密顿回路149人打卡
		7. AcWing 1619. 欧拉路径142人打卡
		8. AcWing 1624. 地铁地图75人打卡
		9. AcWing 1627. 顶点覆盖128人打卡
		10. AcWing 1632. 第一次接触96人打卡
		11. AcWing 1635. 最大集团114人打卡
		12. AcWing 1639. 拓扑顺序119人打卡
		13. AcWing 1643. 旅行商问题105人打卡
		14. AcWing 1648. 顶点着色113人打卡
		15. AcWing 1495. 公共自行车管理56人打卡
		16. AcWing 1558. 加油站75人打卡
		17. AcWing 1562. 微博转发82人打卡 
		18. AcWing 849. Dijkstra求最短路 I115人打卡
		19. AcWing 850. Dijkstra求最短路 II84人打卡
	第五章 树完成情况：27/27
		1. AcWing 1476. 数叶子结点250人打卡
		2. AcWing 1497. 树的遍历235人打卡
		3. AcWing 1498. 最深的根211人打卡
		4. AcWing 1527. 判断二叉搜索树194人打卡
		5. AcWing 1550. 完全二叉搜索树197人打卡
		6. AcWing 1576. 再次树遍历184人打卡
		7. AcWing 1589. 构建二叉搜索树188人打卡
		8. AcWing 1592. 反转二叉树183人打卡
		9. AcWing 1600. 完全二叉树182人打卡
		10. AcWing 1605. 二叉搜索树最后两层结点数量178人打卡
		11. AcWing 1609. 前序和后序遍历153人打卡
		12. AcWing 1620. Z 字形遍历二叉树161人打卡
		13. AcWing 1631. 后序遍历167人打卡
		14. AcWing 1552. AVL树的根129人打卡
		15. AcWing 1616. 判断完全 AVL 树122人打卡
		16. AcWing 1628. 判断红黑树103人打卡
		17. AcWing 1539. 等重路径141人打卡
		18. AcWing 1584. 最大的一代147人打卡
		19. AcWing 1565. 供应链总销售额116人打卡
		20. AcWing 1580. 供应链最高价格115人打卡
		21. AcWing 1596. 供应链最低价格112人打卡
		22. AcWing 1649. 堆路径115人打卡
		23. AcWing 1623. 中缀表达式117人打卡
		24. AcWing 1636. 最低公共祖先108人打卡
		25. AcWing 1644. 二叉树中的最低公共祖先104人打卡
		26. AcWing 826. 单链表105人打卡
		27. AcWing 836. 合并集合101人打卡
	第四章 排序完成情况：11/11
		1. AcWing 1484. 最佳排名185人打卡
		2. AcWing 1499. 数字图书馆171人打卡
		3. AcWing 1502. PAT 排名169人打卡
		4. AcWing 1505. 列表排序166人打卡
		5. AcWing 1523. 学生课程列表161人打卡
		6. AcWing 1538. 链表排序151人打卡
		7. AcWing 1561. PAT 评测127人打卡
		8. AcWing 1588. 插入还是堆排序130人打卡
		9. AcWing 1579. 插入还是归并98人打卡
		10. AcWing 789. 数的范围103人打卡
		11. AcWing 838. 堆排序108人打卡
	第三章 进位制完成情况：5/5
		1. AcWing 1482. 进制176人打卡
		2. AcWing 1492. 可逆质数196人打卡
		3. AcWing 1504. 火星颜色198人打卡
		4. AcWing 1590. 火星数字173人打卡
		5. AcWing 1496. 普通回文数149人打卡
	第二章 高精度完成情况：6/6
		1. AcWing 1474. 多项式 A + B251人打卡
		2. AcWing 1481. 多项式乘积235人打卡
		3. AcWing 1500. 趣味数字237人打卡
		4. AcWing 1501. 回文数228人打卡
		5. AcWing 1544. 霍格沃茨的 A + B151人打卡
		6. AcWing 1629. 延迟的回文数145人打卡
	第一章 字符串处理完成情况：19/20
		1. AcWing 1473. A + B 格式399人打卡
		2. AcWing 1477. 拼写正确382人打卡
		3. AcWing 1478. 签到与签出359人打卡
		4. AcWing 1519. 密码340人打卡
		5. AcWing 1520. 男孩 vs 女孩324人打卡
		6. AcWing 1534. 字符串减法322人打卡
		7. AcWing 1557. 说话方式302人打卡
		8. AcWing 1547. 约会270人打卡
		9. AcWing 1493. 电话账单189人打卡
		10. AcWing 1494. 银行排队166人打卡
		11. AcWing 1503. 乒乓球66人打卡
		12. AcWing 1546. 它们是否相等121人打卡
		13. AcWing 1559. 科学计数法119人打卡
		14. AcWing 1563. Kuchiguse116人打卡
		15. AcWing 1568. 中文读数字78人打卡
		16. AcWing 1570. 坏掉的键盘119人打卡
		17. AcWing 1598. 求平均值108人打卡
		18. AcWing 1617. 微博转发抽奖114人打卡
		19. AcWing 1634. PAT单位排行105人打卡
		20. AcWing 1647. 解码PAT准考证
14. 6.2 - 6.5
	第二十讲完成情况：0/7
		AcWing 703. 数独检查43人打卡
		AcWing 697. 蒙斯特39人打卡
		AcWing 698. 读电话号码33人打卡
		AcWing 696. 哈默队长29人打卡
		AcWing 1109. 等式25人打卡
		AcWing 914. 樱桃网26人打卡
		AcWing 78. 左旋转字符串38人打卡
	第十九讲完成情况：0/7
		AcWing 647. 懒惰拼字赛38人打卡
		AcWing 627. 排灯节照明33人打卡
		AcWing 631. Googol字符串30人打卡
		AcWing 643. 动态网格30人打卡
		AcWing 695. 劣马27人打卡
		AcWing 592. 雨21人打卡
		AcWing 72. 平衡二叉树34人打卡
	第十八讲完成情况：0/6
		AcWing 687. 扫雷38人打卡
		AcWing 562. 壁画35人打卡
		AcWing 595. 夏洛克和括号34人打卡
		AcWing 620. 安全区34人打卡
		AcWing 628. 美丽的数30人打卡
		AcWing 76. 和为S的连续正数序列36人打卡
	第十七讲完成情况：0/7
		AcWing 591. 国家领导者45人打卡
		AcWing 587. 吃蛋糕40人打卡
		AcWing 561. 大按钮35人打卡
		AcWing 571. 数学编码器35人打卡
		AcWing 623. 投票30人打卡
		AcWing 578. 去观光22人打卡
		AcWing 80. 骰子的点数31人打卡
	第十六讲完成情况：0/7
		AcWing 1768. H 指数50人打卡
		AcWing 1769. H 指数 II47人打卡
		AcWing 1158. H指数39人打卡
		AcWing 1108. 读书37人打卡
		AcWing 558. 乘积三元组30人打卡
		AcWing 1060. 墙的重建26人打卡
		AcWing 53. 最小的k个数39人打卡
	第十五讲完成情况：0/6
		AcWing 1318. 取石子游戏56人打卡
		AcWing 1302. 矩阵 A × B54人打卡
		AcWing 1262. 鱼塘钓鱼42人打卡
		AcWing 1274. 奶牛排队43人打卡
		AcWing 1306. 迷路16人打卡
		AcWing 89. a^b42人打卡
	第十四讲完成情况：0/6
		AcWing 1254. 找树根和孩子57人打卡
		AcWing 1255. 医院设置55人打卡
		AcWing 1256. 扩展二叉树53人打卡
		AcWing 1764. 修塔游戏38人打卡
		AcWing 1120. 埃及分数33人打卡
		AcWing 79. 滑动窗口的最大值45人打卡
	第十三讲完成情况：0/6
		AcWing 1099. 仙岛求药64人打卡
		AcWing 1102. 移动骑士60人打卡
		AcWing 1103. 棋盘游戏58人打卡
		AcWing 1111. 字母60人打卡
		AcWing 1114. 棋盘问题52人打卡
		AcWing 75. 和为S的两个数字59人打卡
	第十二讲完成情况：0/6
		AcWing 1051. 最大的和68人打卡
		AcWing 1026. 乘积最大62人打卡
		AcWing 1698. 余数的最大值58人打卡
		AcWing 1025. 开餐馆58人打卡
		AcWing 1028. 复制书稿50人打卡
		AcWing 1090. 绿色通道36人打卡
	第十一讲完成情况：0/6
		AcWing 48. 复杂链表的复刻69人打卡
		AcWing 680. 剪绳子74人打卡
		AcWing 1645. 不同的二叉搜索树73人打卡
		AcWing 415. 栈62人打卡
		AcWing 50. 序列化二叉树59人打卡
		AcWing 60. 礼物的最大价值64人打卡
	第十讲完成情况：0/6
		AcWing 730. 机器人跳跃问题81人打卡
		AcWing 845. 八数码72人打卡
		AcWing 167. 木棒50人打卡
		AcWing 731. 毕业旅行问题54人打卡
		AcWing 45. 之字形打印二叉树64人打卡
		AcWing 46. 二叉搜索树的后序遍历序列62人打卡
	第九讲完成情况：0/6
		AcWing 1611. 寻找峰值95人打卡
		AcWing 843. n-皇后问题85人打卡
		AcWing 1613. 数独简单版78人打卡
		AcWing 1612. 最大正方形88人打卡
		AcWing 52. 数组中出现次数超过一半的数字89人打卡
		AcWing 901. 滑雪70人打卡
	第八讲完成情况：0/6
		AcWing 131. 直方图中最大的矩形93人打卡
		AcWing 152. 城市游戏81人打卡
		AcWing 1574. 接雨水80人打卡
		AcWing 1575. 盛水最多的容器76人打卡
		AcWing 454. 表达式求值71人打卡
		AcWing 43. 不分行从上往下打印二叉树79人打卡
	第七讲完成情况：0/6
		todo AcWing 1572. 递归实现指数型枚举 II90人打卡
		todo AcWing 93. 递归实现组合型枚举92人打卡
		todo AcWing 1573. 递归实现组合型枚举 II85人打卡
		AcWing 55. 连续子数组的最大和
			1. 有意思. 一维的dp问题, 优化成一个点了
			2. 解释:
				f[k]: 
					集合: 所有 以ind==k为结尾的连续子数组的元素和 的集合 
					属性: 元素和 
					状态转移: f[k] = max(0 + a[k], f(k-1) + a[k]) = max(a[k], f(k-1))
						解释: f[k] 一定选了a[k]元素 
							f[k]对应的连续子数组:
								第一种情况: {a[0], a[1], a[], a[k-1], a[k]} 	|
								第二种情况: {				..., a[k-1], a[k]} 	|-> 前面的情况都可以用 f(k-1) + a[k] 表示, 也就是一定选了 a[k-1], a[k]
								...											|
								第xx种情况: {					 a[k-1], a[k]} 	|
								最后一种情况: {					 	 a[k]} 	 -> 最后一种情况用 0 + a[k] 表示 
				计算完所有的f[0], f[1], ..., f[n-1] 之后, 我们求这些f[xx]的max
			3. 因为 f[k] 只需要 前一个f[k-1]的值, 所以可以优化成一个点s
			4. 
				class Solution {
				public:
				    int maxSubArray(vector<int>& a) {
				        int res = a[0], f = a[0];
				        for (int i = 1; i < a.size(); i ++ )
				        {
				            f = a[i] + max(0, f); -> 对应了 f[k] = max(a[k], f[k-1])
				            res = max(res, f);
				        }

				        return res;
				    }
				};
		AcWing 62. 丑数

		AcWing 29. 删除链表中重复的节点

	第六讲
		todo AcWing 92. 递归实现指数型枚举
			#include <iostream>
			using namespace std;
			const int N = 20;
			int n;
			bool st[N];
			void dfs(int u)
			{
			    if (u > n)  // 叶子节点
			    {
			        for (int i = 1; i <= n; i ++ )
			            if (st[i])
			                cout << i << ' ';
			        cout << endl;
			        return;
			    }
			    st[u] = true;
			    dfs(u + 1);  // 选择当前数的分支

			    st[u] = false;
			    dfs(u + 1);  // 不选当前数的分支
			}
			int main()
			{
			    cin >> n;
			    dfs(1);
			    return 0;
			}
		todo AcWing 94. 递归实现排列型枚举
			1. 和全排列的逻辑是一样的, 只不过全排列我们排列的是1,2,3,...,n是值
				这里的1,2,3,...,n是ind, 对应的值是a[1], a[2], ... , a[n]
			2. 
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 10;

				int n;
				int a[N], nums[N];
				bool st[N];

				void dfs(int u)
				{
				    if (u == n)
				    {
				        for (int i = 0; i < n; i ++ ) cout << nums[i] << ' ';
				        cout << endl;
				        return;
				    }

				    for (int i = 0; i < n; i ++ )
				        if (!st[i])
				        {
				            nums[u] = a[i];
				            st[i] = true;
				            dfs(u + 1);
				            st[i] = false;
				            while (i + 1 < n && a[i + 1] == a[i]) i ++ ;
				            	我的很棒的想法:
				            		求下一个不一样的数字
				            		你要不一样的, 那我while就和你反着来就很好了, 我就偏while一样的
				            		那么 while(下一个下标合法 && 下一个数字还是和当前数字一样) 往下看 
				        }
				}

				int main()
				{
				    cin >> n;
				    for (int i = 0; i < n; i ++ ) cin >> a[i];

				    sort(a, a + n);

				    dfs(0);

				    return 0;
				}
		todo AcWing 1537. 递归实现排列类型枚举 II
		AcWing 145. 超市
			#include <iostream>
			#include <algorithm>
			#include <queue>

			#define x first
			#define y second

			using namespace std;

			typedef pair<int, int> PII;

			int main()
			{
			    int n;
			    while (cin >> n)
			    {
			        vector<PII> prod(n);
			        for (int i = 0; i < n; i ++ ) cin >> prod[i].y >> prod[i].x;
			        sort(prod.begin(), prod.end()); //过期时间排序

			        priority_queue<int, vector<int>, greater<int>> heap; //存的都是要卖的东西, 不在heap中的就是要抛弃的东西
			        for (auto p : prod) //最早过期的东西先出来
			        {
			            heap.push(p.y);
			         //   写法1:
			         //   if (p.x >= heap.size()) // 我过期的时间 晚于 要卖的东西{包括我在内}卖光的那天
			         //   	continue;
			         //   heap.pop();
			            
			         // 写法2: 保守
			         //   while(heap.size() > p.x) heap.pop();  //如果堆太拥挤了, 就抛弃最没用的, 注意这里抛弃的可能是我, 可是没关系
			         
			         // 写法3:
			            if(heap.size() > p.x) heap.pop();
			         //   注意过期时间是绝对值, 不是相对值. 也就是大家都从第1天开始, 第p.x天到期, 而不是说自己过了p.x天到期
			         //   我p已经在堆里面了, 然后我要看看这个堆里面有多少人
			         //   我是第p.x天到期, 如果堆里面的人超过了p.x个人, 就一定有一个人要被删除了 
			         //       不用担心说, 之前加入的人, 他们会不会遇到堆里的人多过他们的第p.x天到期
			         //       因为我这里是在证明我这一环没问题, 因为前面的他们也是和我同样的方法
			         //       所以我没问题, 他们也没问题. 有种递归的感觉哈
			         //       我没问题依赖于他们也没问题, 可是, 我没问题可以导致历史的他们也没问题
			         //   至于删除谁, 不用考虑日期, 因为删掉那个人之后, 大家的日期肯定都是合格的 
			         //       所以就删除最没用的

			         //   为什么不用while? 因为没必要 
			         //   很好的故事: 这个题目的确是可以体现贪心思想 
			         //   	1. 每次往堆里加入一个元素, 如果加入的元素太多, 很挤的话, 我们就删掉一个
			         //   	2. 删掉对没用的那一个 
			         //   每次只是往堆里加入一个元素, 所以增加的速度是恒为1
			         //   我们判断的限制{p.x}, 因为排序好的, 所以增加的速度最少为0, 最大是无穷
			                 //   我们不考虑过期日期是无穷, 我们考虑最紧张的值, 也就是最晚的过期日期不变, 那也依旧是每次加一个删一个就好了, 用if就好了
			         //   所以没必要用while, 用if就好了, 用while也可以{更保守}
			         // 举例
    			         //加入了第一个元素, 这个元素的过期是第一天, ok, 继续
    			         //再加入一个元素, 这个元素的过期还是第一天, 删除, 保证堆不拥挤, 还是 heap.size() <= 最晚过期的第一天
    			         //再加入一个元素, 这个元素的过期还是第一天, 删除, 保证堆不拥挤, 还是 heap.size() <= 最晚过期的第一天
    			         //所以每次pop一次就够了

			        }

			        int res = 0;
			        while (heap.size()) res += heap.top(), heap.pop();

			        cout << res << endl;
			    }

			    return 0;
			}
			--
			贪心策略：
				在不过期的时间内优先卖出利润更大的产品。
			新方法:
				按照价值降序，每次扫描到一个价值，尝试一下在过期之前能不能卖出去；
				此时可能已经有比它更大价值的产品占用了一些日期，于是从过期时间往前面找，直到找到一个空位置。
				如果这个空位置大于0，那么就把这个产品安排在这天卖出。

			暴力
				找位置最坏复杂度可以达到 O(n^2)，所以用并查集优化
				ff(i)返回的是, 记录他最近的前面的没卖东西的日期是哪天
					区别于f[i], f[]是并查集, 存的是属于那一个集合. 也就是连续卖出东西的那一段日子
				第i天: 	0		1		2		3		4		5
					  	根		卖过		卖过				卖过
				ff(1) = 0, 说明不能在第1天之前卖东西, 0是特殊值, 表示之前的天数都卖过东西了
				ff(2) = 0, 说明不能在第2天之前卖东西, 0是特殊值, 表示之前的天数都卖过东西了
				ff(3) = 3, 说明在第3天之前, 能卖东西的日子, 就是第3天
				ff(4) = 3, 说明在第4天之前, 能卖东西的日子, 是第3天
				ff(5) = 3, 说明在第5天之前, 能卖东西的日子, 就是第5天

				更新也非常巧妙:
					int pos = ff(e);	第e天过期, 那么第e天的前一个可以卖东西的日子是第pos天 
					f[pos]--;
					例如, pos == 4
						刚开始, f[4] = 3, 于是我们在第3天卖东西
						现在 f[4] --;
							也就是原先, 第4天的前一个可以卖东西的日子是第3天, 现在第3天卖过了, 可以卖东西的日子就往前推
							f[4] = 2;
							你可能会疑惑了, 第2天已经卖了呀. 
							别忘了, f[4] == 2 并不是说第4天的前一个卖东西的日子是第2天, 而是4的爸爸是2, 也就是4和2属于同一个集合
							我们 ff(4) == 0
			实测比优先队列快了三倍
				#include <iostream>
				#include <vector>
				#include <algorithm>
				using namespace std;
				const int INF = 1e4 + 233;
				typedef pair<int, int> PII;
				vector<PII> a;
				int f[INF];
				int ff(int x)	
				{
				    if(f[x] == x) return x;
				    return f[x] = ff(f[x]);
				}
				int main()
				{
				    int n;
				    while(cin >> n)
				    {
				        int ans = 0;
				        a.clear();
				        int maxe = 0;

				        for(int i = 1; i <= n; i++)
				        {
				            int v, e;
				            scanf("%d%d", &v, &e);
				            a.push_back({-v, e});
				            maxe = max(maxe, e);
				        }
				        for(int i = 0; i <= maxe; i++) f[i] = i;	第i天的前一个没卖东西的是第i天, 其中f[0]=0是为了表示前面的日子都卖过了
				        sort(a.begin(), a.end());					价值从大到小排序 
				        for(int i = 0; i < (int)a.size(); i++)
				        {
				            int v = -a[i].first, e = a[i].second;
				            int pos = ff(e);	第e天过期, 那么第e天的前一个可以卖东西的日子是第pos天 
				            if(pos != 0) 		如果pos != 0, 说明可以卖东西
				            {
				                ans += v;		卖价值最大的
				                f[pos]--;		这个非常巧妙
				            }
				        }
				        printf("%d\n", ans);
				    }
				}
		AcWing 1057. 股票买卖 IV {leetcode的题目:https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/}
			注意:
				第j笔交易: 买卖一轮算一笔交易
			代码:
				#include <cstring>
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 100010, M = 110, INF = 0x3f3f3f3f;

				int n, m;
				int w[N];
				int f[N][M][2];

				int main()
				{
				    scanf("%d%d", &n, &m);
				    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);

				    memset(f, -0x3f, sizeof f);
				    for (int i = 0; i <= n; i ++ ) f[i][0][0] = 0; -> 前0,1,2,...,n天没有进行过股票交易, 没有持有股票的收益 == 0
				    for (int i = 0; i <= n; i ++ ) f[i][0][1] = 0; -> 这一句写不写都行, 意为, 前0,1,2,...,n天没有进行过股票交易, 持有股票的收益{不可能的事情, 没交易怎么有股票} == 0
				    	其实是否是0都无所谓, 因为我们求得是max
				    	不过不能全都是-INF, 至少需要一个0来扩散

				    for (int i = 1; i <= n; i ++ )
				        for (int j = 1; j <= m; j ++ )
				        {
				            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);
				            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);
				        }

				    int res = 0;
				    for (int i = 0; i <= m; i ++ ) res = max(res, f[n][i][0]);

				    printf("%d\n", res);

				    return 0;
				}
			核心代码:
			    for (int i = 1; i <= n; i ++ )
			        for (int j = 1; j <= m; j ++ )
			        {
			            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);
			            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);
			        }
		    解释:
		    	f[i][j][0/1]
					表示第i天，正在位于或者已经完成了j笔交易{一买一卖}，现在手中有/没有票
			代码解释:
				注意, 这里的持有还是不持有, 都是闭市之后的状态
					所以, 昨天持有, 今天没有{意味着是今天卖出的}
					所以转移应该是:
						"[j][1] 	-> 	[j][0]" --> "[j+1][1] -> [j+1][0]"
						正在位于第j笔交易  完成第j笔	
				f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);
					第i天, 已经完成第j笔交易, 且手里没有持有股票
						两种解释, 对应不同的途径来:
							1. 昨天持有:
								f[i][j][0]解释为: 卖了第j笔股票
								所以来源是: f[i - 1][j][1] : 昨天依旧是第j笔股票持有的状态
							2. 昨天没持有:
								f[i][j][0]解释为: 没有动股票, 依旧是第j笔交易 
								所以来源是: f[i - 1][j][0]
		        f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);
		        	第i天, 闭市之后手里持有股票
						两种解释, 对应不同的途径来:
							1. 昨天持有:
								f[i][j][1]解释为: 没有动股票, 依旧是第j笔交易 
								所以来源是: f[i - 1][j][1]
							2. 昨天没持有:
								f[i][j][1]解释为: 说明今天买的股, 开启了第j笔交易
								所以来源是: f[i - 1][j - 1][0] : 昨天第j-1笔交易已经结束
			初始化
				代码:
					memset(f, -0x3f, sizeof f); 负无穷
				    for (int i = 0; i <= n; i ++ ) f[i][0][0] = 0;

				解释:
					如果一种状态不合法，或者不希望从这个状态转移过来 ，那么就把它设成正无穷或负无穷
					因为这个题要求最大值，所以把不合法的设成负无穷，也这样这个状态不可能用来更新后来的状态
					f[i][0][1] = 负无穷
						例如这道题中f[i][0][1]表示，如果我们处理了0笔股票，并且我们手中居然还有票，这显然是不可能的
					f[0][j][0]
						例如这道题中f[0][j][0]表示，第0天就有一笔已经完成的第j个股票, 那难道是第-1天买入的这只股票? 这显然是不可能的
					如果我们处理了0笔股票并且目前手里没有票，那收入就是0
						即f[i][0][0] = 0

			老师的另一种写法:
				#include <cstring>
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 100010, M = 110, INF = 0x3f3f3f3f;

				int n, m;
				int w[N];
				int f[N][M][2];

				int main()
				{
				    scanf("%d%d", &n, &m);
				    for (int i = 1; i <= n; i ++ ) scanf("%d", &w[i]);

				    memset(f, -0x3f, sizeof f);
				    f[0][0][0] = 0;

				    for (int i = 1; i <= n; i ++ )
				        for (int j = 0; j <= m; j ++ )
				        {
				            f[i][j][0] = f[i - 1][j][0];
				            if (j) f[i][j][0] = max(f[i][j][0], f[i - 1][j - 1][1] + w[i]);
				            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j][0] - w[i]);
				        }

				    int res = 0;
				    for (int k = 0; k <= m; k ++ ) res = max(res, f[n][k][0]);

				    printf("%d\n", res);

				    return 0;
				}
		AcWing 36. 合并两个排序的链表
			1. 我特别喜欢链表
				一个是可以把lt, lt->next看成实实在在的节点
				另一个我们可以设置结构: lt->next = xx, 就是说明了 lt节点 和 xx节点 的关系
			2. 解释 
				1. 新建头部的保护结点dummy，设置cur指针指向dummy。
				2. 若
					1. 当前l1指针指向的结点的值val比l2指针指向的结点的值val小
						则令cur的next指针指向l1，且l1后移, cur也后移
					2. 否则
						令cur的next指针指向l2，且l2后移, cur也后移
				3. 循环以上步骤直到l1或l2为空。
				4. 将剩余的l1或l2接到cur指针后边。
				5. 返回链表的实际首部: dummy->next;
			2. 代码
				/**
				 * Definition for singly-linked list.
				 * struct ListNode {
				 *     int val;
				 *     ListNode *next;
				 *     ListNode(int x) : val(x), next(NULL) {}
				 * };
				 */
				class Solution {
				public:
				    ListNode* merge(ListNode* l1, ListNode* l2) {
				        ListNode* dummy = new ListNode(0);
				        ListNode* cur = dummy;
				        while (l1 && l2) {
				            if (l1->val < l2->val) cur = cur->next = l1, l1 = l1->next;	很流畅, 我喜欢 
            				else cur = cur->next = l2, l2 = l2->next;
				        }
				        if (l1) cur->next = l1;
				        if (l2) cur->next = l2;
				        ListNode* res = dummy->next;
				        delete dummy;
				        return res;
				    }  
				};

	第五讲
		AcWing 104. 货仓选址
		AcWing 1536. 均分纸牌
			1. 这道题有意思, 画面就跟, 起伏的海浪, 最后都是根据势能, 逐个向左回落或者上涨, 最后海面恢复平静
				//每一堆牌只会受相邻的牌影响，因此从左开始，每一堆牌为了达到平均值，就得向右边的牌索取（或给予），并且步数+1
				//于是这堆达到平均值的牌就可以当做已经不存在，继续处理接下来的牌
			2. 
				#include <iostream>
				using namespace std;
				const int N = 110;
				int a[N];
				int n , total;
				int ans;
				int main()
				{
				    cin >> n;
				    for(int i = 1 ; i <= n ; i++) cin >> a[i] , total += a[i];
				    int avg = total / n;
				    for(int i = 1 ; i <= n ; i++)
				        if(a[i] != avg) a[i + 1] += a[i] - avg , ans++;
				    cout << ans << endl;
				    return 0;
				}
			3. 举例: (9, 8, 17, 6) -> (10, 10, 10, 10)
					(10, 7, 17, 6)
					(10, 10, 14, 6)
					(10, 10, 10, 10)
				a[2] += a[1] - 10 
					 += 9 - 10 = -1
					 == 8 - 1 == 7
				a[3] += a[2] - 10 
					 += 7 - 10 = -3
					 == 17 - 3 == 14
				a[4] += a[3] - 10 
					 += 14 - 10 = 4
					 == 6 + 4 == 10
		* AcWing 122. 糖果传递
			1. 本题+上题: 微软出过, 答对就special offer
			2. 推导:
				1. 公式:
					a1 - x1 + xn 			= avg
					a2 - x2 + x1 			= avg
					a3 - x3 + x2 			= avg
					...
					a(n-1) - x(n-1) + x(n-2) = avg
					an - xn + x(n-1) = avg
				2. 分析
					这里有n个已知数: a1, a2, ..., an, avg
					这里有n个未知数: x1, x2, ..., xn
					有n个方程, 因为解是唯一的, 所以我们一个方程是多余的, 可以删去, 我们删去第一个方程
				3. 变形, 把所有的等号左侧的 -x1, -x2, ..., -xn 挪到等号右侧
					// a1 + xn - avg 			= x1
					a2 + x1 - avg 			= x2
					a3 + x2 - avg 			= x3
					...
					a(n-1) + x(n-2) - avg 	= x(n-1)
					an - xn + x(n-1) - avg 	= xn
				4. 将所有的x2, x3... 都表示成x1的函数
					x2 = x1 + a2 - avg
					x3 = (x1 + a2 - avg) + a3 - avg  	= x1 + (a2 + a3) - 2*avg
					...
					xn = ...							= x1 + (a2 + a3 + ... + an) - (n-1)*avg
				5. 简化:
					设 c1 = 0 = 0*avg
					设 c2 = a2 - 1*avg
					设 c3 = (a2 + a3) - 2*avg
					设 cn = (a2 + a3 + ... + an) - (n-1)*avg
					错了! 不能这么设置, 需要取反
						上述的错误设置, 会让 xn = x1 + cn, 但是我们要的是 xn = x1 - cn 
					正确:
						设 c1 = 0 = 0*avg
						设 c2 = -(a2 - avg)	= 1*avg - a2
						设 c3 = -((a2 + a3) - 2*avg) = 2*avg - (a2 + a3)
						设 cn = -((a2 + a3 + ... + an) - (n-1)*avg) = (n-1)*avg - (a2 + a3 + ... + an)
					实现:
						c1, ..., cn都是常数, 都是可以计算出来的值!!! 
						用前缀和来计算: (a2 + a3 + ... + an) = S[n] - a[1]
						cn = (n-1) * avg - (S[n] - a[1])
				6. 目标: 所有人传递糖果的个数最少
					希望: |x1| + |x2| + ... + |xn| 最小
					希望: |x1 - 0| + |x1 - c2| + |x1 - c3| + ... + |x1 - cn| 最小 
				7. 这样就ok了
					x1的取值就是 c1, ... cn的中位数 
			3. 
				#include <cstdio>
				#include <iostream>
				#include <algorithm>

				using namespace std;

				typedef long long LL;

				const int N = 1000010;

				int n;
				LL s[N], c[N];

				int main()
				{
				    scanf("%d", &n);
				    for (int i = 1; i <= n; i ++ )
				    {
				        scanf("%lld", &s[i]);
				        s[i] += s[i - 1];
				    }

				    LL avg = s[n] / n;
				    求c1到cn:
				    for (int i = 2; i <= n; i ++ ) c[i] = (i - 1) * avg - (s[i] - s[1]);	完全按照公式来 {c1, ..., cn}

				    sort(c + 1, c + n + 1);

				    LL md = c[(n + 1) / 2];	求{cn}序列的中位数的
				    LL res = 0;
				    for (int i = 1; i <= n; i ++ ) res += abs(c[i] - md);

				    printf("%lld\n", res);

				    return 0;
				}
		AcWing 106. 动态中位数
			0. 非常智慧的一道题
			1. 对顶堆
				左边: 大根堆heap1, 堆顶ht1, ht1是堆的最大值
				右边: 小根堆heap2, 堆顶ht2, ht2是堆的最小值

					|\		  	  /|
					| \		 	 / |
					|  \ht1	 ht2/  |
					|  /	    \  |
	  				| /		     \ |
	  				|/		      \|
	  		2. 
	  			#include <cstdio>
				#include <cstring>
				#include <iostream>
				#include <algorithm>
				#include <queue>

				using namespace std;

				int main()
				{
				    int T;
				    scanf("%d", &T);
				    while (T -- )
				    {
				        int id, n;
				        scanf("%d%d", &id, &n);
				        printf("%d %d\n", id, (n + 1) / 2);	输出编号, 输出的中位数的个数

				        priority_queue<int> left;							左边: 大根堆
				        priority_queue<int, vector<int>, greater<int>> right;	右边: 小根堆

				        int cnt = 0;
				        for (int i = 0; i < n; i ++ )
				        {
				            int x;
				            scanf("%d", &x);	读入每个数字 

				            看看读入的这个数字应该插在左边还是右边 
				            if (left.empty() || x <= left.top()) 	如果左边是空的, 或者数字x小于左边的堆顶, x就属于左侧 
				            	left.push(x);	
				            else right.push(x);						否则就是右侧 

				            接下来看看左右堆是否个数相当: 
				            	我们的目标是: 
				            		如果左右一共有偶数个数字, 那么移动完之后: 左 == 右
				            		如果左右一共有奇数个数字, 那么移动完之后: 左比右多一个, 即, 左 == 右 + 1 > 右

				            左比右多2个, 即, 左 - 右 >= 2, 例如{5个,3个}, 那么移动完之后, 左 == 右, 例如{4个,4个}
				            if (left.size() - right.size() >= 2) 		左边多了2个
				            	right.push(left.top()), left.pop();		右边加上左边的堆顶

				            右比左多1个, 即, 右 - 左 >= 1, 例如{2个,3个}, 那么移动完之后, 左 == 右 + 1 > 右, 例如{3个,2个}
				            if (right.size() - left.size() >= 1) 
				            	left.push(right.top()), right.pop();	左边加上右边的堆顶
				            我之前的疑问:
				            	1. 如果右比左多2个呢, 那么我们只从右边移动了一个数字给左边是不是不够, 是不是用while而不是用if
				            		其实不需要, 为什么, 要出现: 右比左多2个 的情况需要两个条件:
				            			1. 前面代码中, right.push(x);	
				            			2. 并且, 在此之前 右比左已经多1个 -> 这个条件不可能成立
				            		所以还没等 右比左多1个 呢, 右就已经被打回原形了, 所以永远不会有 右比左多2个
				            	2. 存不存在, 插入了偶数个数字, 左比右多几个数字, 而不是我们目标的左==右?
				            		不存在, 为什么? 分情况讨论:
				            			1. 情况1: 左比右多1个, 那他们两个之和就是奇数, 矛盾了
				            			2. 情况2: 左比右多2个, 我们的代码会让左给右, 最后左==右
				            			3. 情况3: 左比右多3个, 多2个都没可能, 你怎么来的3个
				            	3. 存不存在, 插入了奇数个数字, 最后: 左 == 右, 不可能, 显而易见, 他们两个之和就是偶数, 矛盾了
				            	3. 总结: 
				            		如果左右一共有偶数个数字, 那么移动完之后: 左 == 右
				            		如果左右一共有奇数个数字, 那么移动完之后: 左比右多一个, 即, 左 == 右 + 1 > 右

				            如果插入了奇数个数字, 打印的就是左的顶, 因为左比右多一个
				            if (i % 2 == 0){
				                printf("%d ", left.top());
				                if ( ++ cnt % 10 == 0) puts("");
				            }
				        }
				        if (cnt % 10) puts("");
				    }

				    return 0;
				}
		* AcWing 146. 序列
			1. 多路归并, 实在是太漂亮了, 我喜欢, 老师说面试必面多路归并
			2. 故事:
				1. 首先是题意:
					1. 画面:	
									第1个数字		第2个数字 	... 		第n个数字
						第1行序列		x11  ----   x12 ---- x13 --------------			-> 挑一个数字 b1
						第2行序列		--------------------------------------- 		-> 挑一个数字 b2
						...
						第m行序列		--------------------------------------- 		-> 挑一个数字 bm
					2. {b1, b2, b3, ..., bm} -> 新序列, 序列的元素和 S = b1 + b2 + ... + bm 
					3. 新序列{b}有多少种, 有 n^m 种
						为什么?
							第一行序列有n种选法, 第二行序列有n种选法, ..., 第m行序列有n种选法
							n * n * n * ... * n = n^m
					4. 每个新序列{b}都有它的序列的元素和 S = b1 + b2 + ... + bm 
						所以有 n^m 个S
					5. 题目是求S中, 最小的那n个的值 //这里是最小的n个, 而不是什么最小的100个200个, 而是最小的n个, 这是有讲究的 
				2. 数学归纳法 + 多路归并
					既然是元素和, 我们就可以用归纳法
					1. 假设不是在前m行序列中选, 而是在前2行序列中选
						会得到 n^2种不同的新序列: {b1, b2}
						所以元素和S也是有 n^2 种 
						我们将S里面的值都从小到大排序: {s1, s2, ... s{n^2}}
							s1 = b1 + b2, 这里的b1肯定是第1行的最小值, b2肯定是第2行的最小值 
							s2 = b1 + b2, 这里的b1是第1行的哪个数字? b2是第2行的哪个数字?
								这里就用到了多路归并!!
									1. 图画
												-------------------------> 第一行的数字从小到大排序
											|		A1 			A2 			A3 .... 		An
											|B1   	{A1,B1}  	{A2,B1}		{A3,B1}        	{An,B1}
											|
											|B2 	{A1,B2}  	{A2,B2}		{A3,B2}			{An,B2}
											|
											|B3 	{A1,B3} 
											|
											↓Bn		{A1,Bn} 

										第二行的数字不需要排序
									2. 想象画面:
										{A1,B1}, {A2,B1}, {A3,B1}, {An,B1} 
											他们的和S = Ax+Bx, 这是一条递增的线a, 没错吧
											因为A1到An是递增的, B1是不变的, 所以和是一条递增的线
										{A1,B2}, {A2,B2}, {A3,B2}, {An,B2} 
											他们的和S = Ax+Bx, 这是一条递增的线b, 没错吧
											因为A1到An是递增的, B2是不变的, 所以和是一条递增的线
										线a和线b的形状是一样的, 只是高低平移的关系没错吧
										想象很多形状一样, 但是高低不同的线在一个空间里面 
									3. 看S的最小值, 第二小的值
										1. 最小值在哪里? 将第一列的所有元素放入一个集合中, 集合的最小值 
												-------------------------> 第一行的数字从小到大排序
											|		A1 			A2 			A3 .... 		An
											|B1   	"{A1,B1}"  	{A2,B1}		{A3,B1}        	{An,B1}
											|
											|B2 	"{A1,B2}"  	{A2,B2}		{A3,B2}			{An,B2}
											|
											|B3 	"{A1,B3}"-> 假设这个是第一列最小值, 也就是全局的最小值
											|		...
											|
											↓Bn		"{A1,Bn} "
										2. 第二小的值在哪里? 将{A1,B3}从集合中删除, {A2,B3}插入我们的集合中, 集合的最小值就是
												-------------------------> 第一行的数字从小到大排序
											|		A1 			A2 			A3 .... 		An
											|B1   	"{A1,B1}"  	{A2,B1}		{A3,B1}        	{An,B1}
											|
											|B2 	"{A1,B2}"  	{A2,B2}		{A3,B2}			{An,B2}
											|
											|B3 	x 			"{A2,B3}"
											|		...
											|
											↓Bn		"{A1,Bn} "
											解释:
												1. 下一个最小值, 肯定在刚刚描述的集合中
												2. 下一个最小值, 不可能是 {A2,B1}, 因为有 {A1,B1} < {A2,B1}, 所以轮不到{A2,B1}做最小值
													其他的类似 
					2. 现在我们已经通过多路归并, 找到S里面的最小的n个值: {s1, s2, ... sn}
						那么现在数学归纳法, 考虑第3行序列, 那么第3行序列的S = b1 + b2 + b3, 我们要找到最小的前n个
							1. 最小的一个, 很简单, 那就是b1,b2,b3对应的是第1,2,3行序列的最小值
							2. 第二小的, 怎么求?
								是b1,b2对应的是第1,2行序列的最小值 + b3对应的是第3行的第二小值
								还是b1+b2对应的是第1,2行序列的第二小S + b3对应的是第3行的最小值
							3. 又变成了上面的多路归并问题
								只不过, 新的b1是上一轮的{b1+b2}, 新的b2是这一轮的b3 
							4. 疑问, 我们是真的只会用到上一轮{b1+b2}的前n小的和吗, 会不会用到第n+1小的和 
								不可能, 有更小的, 为什么不用更小的, 却要用第n+1小的
			3. 
				#include <cstdio>
				#include <cstring>
				#include <algorithm>
				#include <queue>

				#define x first
				#define y second

				using namespace std;

				typedef pair<int, int> PII;		记录的是{b1+b2的和, 棋盘中的b2数字对应的行, 我们要遍历它的第i列, 也就是要看a[i] + b2}

				const int N = 2010;				

				int m, n;
				int a[N], b[N], temp[N];

				void merge()
				{
				    priority_queue<PII, vector<PII>, greater<PII>> heap;		小根堆, 记录最小的n个和

				    for (int i = 0; i < n; i ++ ) heap.push({b[i] + a[0], 0}); 	把棋盘中的第一列元素推入, 第一列元素是 S = b[i] + a[0]
				    															第二个维度是xx, 赛马场景中, b[i]对应的那一行, 我们应该判断的是第xx列, 也就是a[xx]
				    for (int i = 0; i < n; i ++ ){
				        auto p = heap.top();									最小值从集合里取出
				        heap.pop();
				        temp[i] = p.x;
				        heap.push({p.x - a[p.y] + a[p.y + 1], p.y + 1});		非常的简洁:
				        														刚推出的是 p.x == S = b[i] + a[0]
				        														现在插入的是 b[i] + a[1] == S - a[0] + a[1] 
				        																			   == p.x - a[p.y] + a[p.y + 1]
				    }

				    memcpy(a, temp, sizeof temp);								将temp数组, 复制到a中 {目标, 源, 源长}
				}

				int main()
				{
				    int T;
				    scanf("%d", &T);
				    while (T -- )
				    {
				        scanf("%d%d", &m, &n);				
				        for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);	读入第一行的n个元素
				        sort(a, a + n);										这一行排序 
				        for (int i = 0; i < m - 1; i ++ ){					剩下的行
				            for (int j = 0; j < n; j ++ ) scanf("%d", &b[j]);	读入下一行的n个元素, 不需要排序
				            merge();										合并两行
				        	merge完之后, 我们获得的新a[]依旧是排好序
				        }
				        for (int i = 0; i < n; i ++ ) printf("%d ", a[i]);
				        puts("");
				    }

				    return 0;
				}
		AcWing 33. 链表中倒数第k个节点
			0. 熟练:
				1. 倒数第k个数, 就是ind == n-k的数字
					很简单, 倒数第1个数 == 最后一个数 == ind是n-1
				2. for()找到链表的第i个节点, 假设头结点的ind == 0
					去第i个节点, 需要走i条边, for(遍历边数i)
					去ind==1个节点, 需要走1条边, for(遍历边数), 即 for(int i = 0 ; i < 1; i++)
				3. 总结
					去倒数第k个数, 就是ind == n-k的数字
					去ind==n-k个节点, 需要走n-k条边, for(遍历边数), 即 for(int i = 0 ; i < n-k; i++)
				4. 宏观: 链表和数组是一模一样的:
					数组: 访问ind==n-k个节点, arr[n-k]
					链表: 访问ind==n-k个节点, for(int i = 0 ; i < n-k; i++) p = p->next; 最后的p就是
			1.
				/**
				 * Definition for singly-linked list.
				 * struct ListNode {
				 *     int val;
				 *     ListNode *next;
				 *     ListNode(int x) : val(x), next(NULL) {}
				 * };
				 */
				class Solution {
				public:
				    ListNode* findKthToTail(ListNode* pListHead, int k) {
				        int n = 0;
				        for (auto p = pListHead; p; p = p->next) n ++ ;     //为了得到链表长度需要遍历一次
				        if (k > n) return nullptr;                          //k大于链表长度
				        auto p = pListHead;
				        for (int i = 0; i < n - k; i ++ ) p = p->next;      //倒数第k个数, 就是ind == n-k的数字

				        return p;
				    }
				};
		AcWing 786. 第k个数: 快排的应用 
	第四讲
		AcWing 1490. 最长上升子串 
			1. 子串 != 子序列 
			2. 有限集合的最值问题: 方案的个数是有限的, 在所有的方案中找min/max
			3. 思路:
				#include <cstdio>
				#include <cstring>
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 100010;

				int n;
				int a[N], f[N], g[N];

				int main()
				{
				    scanf("%d", &n);
				    for (int i = 1; i <= n; i ++ ) scanf("%d", &a[i]);

				    // 预处理f[i]：以i结尾的单调上升子串的最大长度
				    for (int i = 1; i <= n; i ++ )
				        if (a[i] > a[i - 1]) f[i] = f[i - 1] + 1;
				        else f[i] = 1;

				    // 预处理g[i]：以i开头的单调上升子串的最大长度
				    for (int i = n; i; i -- )
				        if (a[i] < a[i + 1]) g[i] = g[i + 1] + 1;
				        else g[i] = 1;

				    int res = 0;
				    // 枚举删除哪个数
				    for (int i = 1; i <= n; i ++ )
				        if (a[i - 1] >= a[i + 1]) res = max(res, max(f[i - 1], g[i + 1]));	如果 a[i - 1], a[i + 1] 不能拼为上升子串, 取两段的max
				        else res = max(res, f[i - 1] + g[i + 1]);							如果 a[i - 1], a[i + 1] 能拼为上升子串, 将两段合并 

				    printf("%d\n", res);

				    return 0;
				}
		* AcWing 1259. 二叉树遍历{面试题中属于较难的题, 的确, 厉害了}
			1. 中序 + 前/后/层序 
			2. 对比
				1. 中序 + 前序:
					中序的作用, 找到根节点在中序的位置后, 通过判断左右段的大小, 来确定前序的根节点的左右子树的大小
				2. 中序 + 层序:
					树是一层一层复现出来
					中序的作用, 找到根节点在中序的位置后, 通过判断左右段是否为空, 来确定层序的根节点是否有左右子节点
				3. 
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					struct Node
					{
					    char val;
					    Node *left, *right;
					    Node(char _val) : val(_val), left(NULL), right(NULL) {}
					};

					string res;

					void dfs(Node *root)	前序输出 
					{
					    if (!root) return;
					    res += root->val;	
					    dfs(root->left);
					    dfs(root->right);
					}

					int main()
					{
					    string inorder, level;
					    cin >> inorder >> level;

					    unordered_map<char, int> pos;		记录前序遍历的: {值, 对应的坐标}, 之后我们要通过元素的值, 知道这个元素在中序数组中的位置
					    for (int i = 0; i < inorder.size(); i ++ ) pos[inorder[i]] = i;

					    bool st[30] = {0};	看中序数组中的某个元素是否被遍历过, 如果没有遍历过, 我们认为这就是有左右儿子
					    Node* q[30];		我们的结果存在队列q里面, q其实是保存的是层序遍历的顺序

					    q[0] = new Node(level[0]);	根节点: 层序数组的第0个
					    for (int i = 0, j = 1; j < level.size();)  // 按成遍历，i是当前这层的起点，j是下一层的起点
					    	i: 看成指针, 指向level层序数组的, i遍历的每一层
					    	j: 看成指针, 指向level层序数组的, j是指向下一层的起点{也就是这一层的终点} 
					    {
					    	外层for: 遍历不同的层, 由j确定每一层的起点在哪里
					    	内层for: 遍历某一层中的每个元素, 由i指向每个元素
					        for (int end = j; i < end; i ++ )  // 遍历当前这层
					        	end = j, j是指向下一层的起点{也就是这一层的终点} 
					        	i < end, i实现遍历这一层中的每个元素

					        	如果每个节点都有左右儿子, 那么回到外层for的时候, j的变化是:
					        		第一层: i初始是0, end = j = 1, i < end, 所以i遍历的是第0个元素
					        			有左右儿子, j++ 执行了两次
					        		第二层: i初始是1, end = j = 3, i < end, 所以i遍历的是第1, 2个元素
					        			第1个元素, 有左右儿子, j++ 执行了两次
					        			第2个元素, 有左右儿子, j++ 执行了两次
					        		第三层: i初始是3, end = j = 7, i < end, 所以i遍历的是第3, 4, 5, 6个元素
					        			...
					        {
					            // 判断左儿子是否存在
					            int p = pos[level[i]];		我们的i是一直++的, 因为层序数组中level[i]也是一直按顺序翻阅, 不要担心层序数组会不会乱, 不会的, 就是按顺序, 也就是i++, 那么就是树的第xx层的从左往右元素, 一个不多一个不少 
					            							找到层序数组的第i个元素, 在中序数组中的下标p
					            st[p] = true;				标记一下中序数组的这个下标是看过的		
					            							如果层序数组的第i个元素, 有左右儿子, 那么中序数组的下标p-1就是左儿子, 下标p+1就是右儿子	
					            if (p - 1 > 0 && !st[p - 1])			如果p-1下标合法, 并且中序数组的这个下标是没有看过, 说明左儿子存在 
					            {
					                q[i]-> left = new Node(level[j]);	q保存的是层序遍历的顺序, 所以q[i]对应的就是level[i]
					                									注意, 因为第一次执行这段代码时候, i == 0, 我们初始化的时候 q[0] = new Node(level[0]);
					                									所以 q[0]->left = new Node(level[j==1]), 没错吧, 左儿子就是层序数组的 level[1] 
					                q[j ++ ] = q[i]->left;				q保存的是层序遍历的顺序, 所以q[j]对应的就是level[j]
					                									j: 看成指针, 指向level层序数组的, 这里的q[j]就是左儿子的位置, 指向刚刚new出来的Node == q[i]->left;
					            }
					            if (p + 1 < level.size() && !st[p + 1])	如果p+1下标合法, 并且中序数组的这个下标是没有看过, 说明右儿子存在 
					            {
					                q[i]->right = new Node(level[j]);	q保存的是层序遍历的顺序, 所以q[i]对应的就是level[i]
					                									注意, 因为第一次执行这段代码时候, i == 0, 我们初始化的时候 q[0] = new Node(level[0]);
					                									如果根节点没有左儿子, 只有右儿子, 那么j现在还是1
					                									所以 q[0]->right = new Node(level[j==1]), 没错吧, 右儿子就是层序数组的level[1], 不要担心层序数组会不会乱, 不会的, 就是按顺序, 也就是i++, 那么就是树的第xx层的从左往右元素, 一个不多一个不少 
					                q[j ++ ] = q[i]->right;				逻辑同上
					            }
					        }
					    }

					    到这里, q记录的就是整个层序遍历的顺序了, 并且把每个节点的父子关系都保存了 
					    dfs(q[0]); 前序遍历, 传入根节点 

					    cout << res << endl;

					    return 0;
					}
		AcWing 1491. 圆桌座位
			0. 对比全排列问题:
				#include <iostream>
				using namespace std;

				const int N = 10;
				int path[N], n;

				void dfs(int size, int state){
				    if(size == n){
				        for(int i = 0; i < n; i ++) printf("%d ", path[i]);
				        puts("");
				        return;
				    }
				    for(int i = 1; i <= n; i++){ 	要填写的数字是i, 从1开始
				        int ind = i - 1; 			数字i, 对应状态中的右数第i-1位. 例如数字1对应state的右数第0位
				        if((state >> ind & 1) == 0){	如果这个数字没有被填写过
				            path[size] = i;
				            dfs(size + 1, state | (1 << ind)); 	
				            				注意, 这个 dfs()是写在 if((state >> ind & 1) == 0) 里面的!! 不要写到外面 
				            				写的时候, 就想着一条路就这么到底了
				            					第一条: 1234567	倒数第二层的 for(), if(!(state >> i & 1)) 只能6,7进去了{因为12345都填好了}, 假设6进去, 下一层for只能是7. 所以输出1234567
				            					第二条: 1234576 倒数第二层的 for(), if(!(state >> i & 1)) 只能6,7进去了{因为12345都填好了}, 假设遍历到了7进去, 下一层for只能是6. 所以输出1234576
				        }
				    }
				}

				int main(){
				    cin >> n;
				    dfs(0, 0);
				}
				--
				简洁:
				#include <iostream>
				using namespace std;
				const int N = 10;
				int path[N], n;

				void dfs(int size, int state){
				    if(size == n){
				        for(int i = 0; i < n; i++) printf("%d ", path[i]);
				        puts("");
				        return;
				    }
				    for(int i = 1; i <= n; i++){
				        int ind = i - 1;
				        if((state >> ind & 1) == 0){
				            path[size] = i;
				            dfs(size + 1, state | (1 << ind));
				        }
				    }
				}

				int main(){
				    cin >> n;
				    dfs(0, 0);
				}
			1. 
				#include <iostream>

				using namespace std;

				const int N = 11;

				int n, m;
				bool g[N][N], st[N];    g表示朋友关系, st表示人是否使用过的状态
				int pos[N];             圆桌上每个位置上是谁

				int dfs(int u)	现在要往圆桌的ind==u的地方开始填人, u从0开始
				{
				    if (u == n)         要往圆桌的ind == n的地方开始填人, 表示圆桌的[0,n-1]都已经排满
				    {
				        if (g[pos[n - 1]][pos[0]]) return 0;    判断圆桌上最后一人pos[n - 1] 是否与 第一人pos[0] 为朋友关系
				        return 1;
				    }

				    int res = 0;
				    for (int i = 1; i <= n; i ++ )              遍历第i个人, 题干中给出人是从编号1开始的
				        if (!st[i] && !g[i][pos[u - 1]])        第i个人没用过, 且, 第i个人和圆桌上的前一个人pos[u - 1], 是非朋友关系
				        {
				            pos[u] = i;							往圆桌上填的是第u个人	
				            st[i] = true;						设置为true
				            res += dfs(u + 1);
				            st[i] = false;                      还原现场. 我的改进, 可以通过初始化pos == -1来代替st 
				        }

				    return res;
				}

				int main()
				{
				    cin >> n >> m;
				    while (m -- )
				    {
				        int a, b;
				        cin >> a >> b;
				        g[a][b] = g[b][a] = true;       //朋友关系初始化
				    }

				    pos[0] = 1;                         圆桌的第0个位置, 放上第1个人
				    st[1] = true;                       第1个人已经用过了

				    cout << dfs(1) << endl;				现在要往圆桌的ind == 1的地方开始填人	

				    return 0;
				}
		todo 难 AcWing 30. 正则表达式匹配
			1. 
				class Solution {
				public:
				    bool isMatch(string s, string p) {
				        int n = s.size(), m = p.size();
				        s = ' ' + s, p = ' ' + p;                               //为了让字符串从1开始,前面补一个空格

				        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));     //定义状态数组,补了空格,长度相应加1
				        f[0][0] = true;     //f[i][j]=true 表示前i个字符串与前j个模式串是匹配的

				        //i要从0开始枚举,因为可能出现s为空p为"a*"的情况
				        for (int i = 0; i <= n; i ++ )
				            for (int j = 1; j <= m; j ++ )
				            {
				                if (j + 1 < m && p[j + 1] == '*') continue;

				                if (i && p[j] != '*')
				                {
				                    //s和p通过字符或'.'匹配的情况
				                    f[i][j] = f[i - 1][j - 1] && (s[i] == p[j] || p[j] == '.');
				                }
				                else if (p[j] == '*')
				                {
				                    //后一个条件已经判断i>0了,f[i][j-2]用来特判s为空且p为"a*"模式的情况,即f[0][0]=true
				                    //f[i-1][j]表示s上一个字符匹配到p的j时是否为真,只有上一个时为真,这次加上*号才能也为真
				                    f[i][j] = f[i][j - 2] || i && f[i - 1][j] && (s[i] == p[j - 1] || p[j - 1] == '.');
				                }
				            }

				        return f[n][m];
				    }
				};
		AcWing 18. 重建二叉树
			0. 对比:
				1. 以前的重建:
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>

					using namespace std;

					const int N = 40;

					int n;
					int postorder[N], inorder[N];
					unordered_map<int, int> l, r, pos;
					int q[N];

					int build(int il, int ir, int pl, int pr)
					{
					    int root = postorder[pr];
					    int k = pos[root];
					    if (il < k) l[root] = build(il, k - 1, pl, pl + (k - 1 - il));
					    if (k < ir) r[root] = build(k + 1, ir, pl + (k - 1 - il) + 1, pr - 1);
					    return root;
					}
					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ ) cin >> postorder[i];
					    for (int i = 0; i < n; i ++ )
					    {
					        cin >> inorder[i];
					        pos[inorder[i]] = i;
					    }
					    int root = build(0, n - 1, 0, n - 1); //那道题还要求写出层序遍历, 所以写了bfs, 本题不要求, 所以我把bfs删掉了
					    return 0;
					}
				2. 本题:
					class Solution {
					public:

					    map<int, int> hash;
					    vector<int> preorder, inorder;

					    TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder) {
					        preorder = _preorder, inorder = _inorder;
					        for (int i = 0; i < inorder.size(); i ++ ) hash[inorder[i]] = i;
					        return dfs(0, preorder.size() - 1, 0, inorder.size() - 1);
					    }

					    TreeNode* dfs(int pl, int pr, int il, int ir) {
					        if (pl > pr) return nullptr;
					        auto root = new TreeNode(preorder[pl]);
					        int k = hash[root->val];
					        写法1:
						        auto left = dfs(pl + 1, pl + k - il, il, k - 1);
						        auto right = dfs(pl + k - il + 1, pr, k + 1, ir);
						        root->left = left, root->right = right;
						    写法2简洁:
						    	root->left = dfs(pl + 1, pl + k - il, il, k - 1);
					        	root->right = dfs(pl + k - il + 1, pr, k + 1, ir);
					        return root;
					    }
					};
			1. 
				/**
				 * Definition for a binary tree node.
				 * struct TreeNode {
				 *     int val;
				 *     TreeNode *left;
				 *     TreeNode *right;
				 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
				 * };
				 */
				class Solution {
				public:

				    map<int, int> hash;
				    vector<int> preorder, inorder;

				    TreeNode* buildTree(vector<int>& _preorder, vector<int>& _inorder) {
				        preorder = _preorder, inorder = _inorder;
				        for (int i = 0; i < inorder.size(); i ++ ) hash[inorder[i]] = i;
				        return dfs(0, preorder.size() - 1, 0, inorder.size() - 1);
				    }

				    TreeNode* dfs(int pl, int pr, int il, int ir) {
				        if (pl > pr) return nullptr;
				        auto root = new TreeNode(preorder[pl]);
				        int k = hash[root->val];
				        auto left = dfs(pl + 1, pl + k - il, il, k - 1);
				        	解释:
				        		中序数组的left段: [il, k - 1]
				        		区间长度是 k - 1 - il + 1 == k - il 
				        		前序数组的起点是: pl + 1, 所以终点是 pl + 1 + (k - il) - 1 == pl + k - il
				        	我以前学的时候的解释: 差相等
								? - pl == (k - 1) - (il) 	
				        auto right = dfs(pl + k - il + 1, pr, k + 1, ir);
				        root->left = left, root->right = right;
				        return root;
				    }
				};
		AcWing 19. 二叉树的下一个节点
			1. 分情况:
				1. 如果当前节点a有右儿子r
					则右子树中最左侧的节点rl就是当前节点a的后继。
						比如"F的后继是H"
				2. 如果当前节点a没有右儿子r
					则需要沿着father域一直向上找，找到第一个是其father{f}左儿子的节点xx，该节点xx的father{f}就是当前节点a的后继。
						我来解释:
							1. 例如B的下一个节点, 因为B没有右儿子, 所以看自己是不是爸爸D的左儿子
								发现是, 那么爸爸D就是B的下一个节点
							2. 例如D的下一个节点, 因为D没有右儿子, 所以看自己是不是爸爸C的左儿子
								发现不是, 看爸爸C是不是它的爸爸F的左儿子
								发现是, 那么这个新爸爸F就是D的下一个节点
				图画:
							F
						/      \
					   C 		E 
					  / \ 	   / \
					 A   D 	  H   G 
					    /		 /
					    B  		M
					   /
					  N
			2. 
				/**
				 * Definition for a binary tree node.
				 * struct TreeNode {
				 *     int val;
				 *     TreeNode *left;
				 *     TreeNode *right;
				 *     TreeNode *father;
				 *     TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
				 * };
				 */
				class Solution {
				public:
				    TreeNode* inorderSuccessor(TreeNode* p) {
				    	若当前节点有右儿子,就一直找它右儿子的最后一个左儿子
				        if (p->right)   
				        {
				            p = p->right;
				            while (p->left) p = p->left;
				            return p;
				        }

				        下面是当前节点没有右儿子的情况
				        我们的目标是: 找到自己是爸爸的左儿子的自己
				        实现: while(自己由父亲 && 自己是父节点的右儿子) 则一直往上找, 直到自己是爸爸的左儿子
				        while (p->father && p == p->father->right) p = p->father;
				        最后答案就是爸爸:
				        return p->father;
				    }
				};
	第三讲
		AcWing 1056. 股票买卖 III
			1. 您看我是否哪个细节描述的不清楚, 我再描述一遍
			2. g和f的区间, 其中 g[0] == f[n] == 0, 最后 g[i] + f[i + 1]
			3. 样例: 严格递增/递减 
		AcWing 1487. 取硬币
			1. 复习一下01/完全的朴素版
			2. 为什么能够无差异的衔接? 01把完全的值作为前辈信息
				混着算也没有影响, 先谁都没影响 
				最多可以开: 64M / 4字节 = 1.6 x 1e6 个int
		AcWing 1488. 最短距离
			0. 面试, 算法题写对了一半也是可以的. 可以让面试官提示自己
			1. 最暴力:
				对于每个村庄, 找到去所有有商店的村庄的距离, 距离的最小值 
					n个村庄 * k个有商店的村庄 * (一次单元最短路的复杂度)
			2. 就是那道题!!! 0类点, 到最近的1类点的问题, 求得不是最近的1类点是哪个, 而是最近的距离. 我们用的就是模拟源点
				1. spfa: O(m边数)
				2. 堆优化的dijkstra 
			3. spfa:
				用了循环队列
					需要回忆一下, 也就是从队列中出来的话, st[]设置为false, 进入的话设置为true 
				不存在无解的情况, 也就是所有的村庄都能找到商店, 因为整个图是联通的 
			4. 
				#include <cstdio>
				#include <cstring>
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 100010, M = 300010;

				int n, m;
				int h[N], e[M], w[M], ne[M], idx;
				int dist[N], q[N];
				bool st[N];

				void add(int a, int b, int c)
				{
				    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
				}

				void spfa()
				{
				    int hh = 0, tt = 1;
				    memset(dist, 0x3f, sizeof dist);
				    dist[0] = 0;
				    st[0] = 0;

				    while (hh != tt)
				    {
				        int t = q[hh ++ ];
				        if (hh == N) hh = 0;

				        st[t] = false;
				        for (int i = h[t]; ~i; i = ne[i])
				        {
				            int j = e[i];
				            if (dist[j] > dist[t] + w[i])
				            {
				                dist[j] = dist[t] + w[i];
				                if (!st[j])
				                {
				                    st[j] = true;
				                    q[tt ++ ] = j;
				                    if (tt == N) tt = 0;
				                }
				            }
				        }
				    }
				}

				int main()
				{
				    scanf("%d%d", &n, &m);

				    memset(h, -1, sizeof h);
				    while (m -- )
				    {
				        int a, b, c;
				        scanf("%d%d%d", &a, &b, &c);
				        add(a, b, c), add(b, a, c);
				    }

				    scanf("%d", &m);
				    while (m -- )
				    {
				        int v;
				        scanf("%d", &v);
				        add(0, v, 0);
				    }

				    spfa();

				    scanf("%d", &m);
				    while (m -- )
				    {
				        int v;
				        scanf("%d", &v);
				        printf("%d\n", dist[v]);
				    }

				    return 0;
				}
		semi AcWing 1489. 田忌赛马
			0. 故事是这样的:
				1. 
					f1 <-----> s1
						f1是我的最强, s1是我的最弱
					f2 <-----> s2
						f2是对手的最强, s2是对手的最弱
				2. 分情况讨论:
					1. s1 < s2:
						我的最弱 < 对手最弱, 我的最弱比对手的谁都会输
						s1 vs f2, 既然比谁都输, 就让它死得其所, 耗掉对手的最强 
					2. s1 > s2:
						我的最弱 > 对手最弱, 能战胜对手最弱
						s1 vs s2, 就直接比对手最弱, 起码能胜一场. 其实耗掉对手的最强应该也可以, 不过两个选择都是赢一场, 没有差别 
							我的极端例子:
									 强 <----------> 弱
								我的:		||||||
								对手: |||||			| 
							在这里, 不管是 s1 vs s2, 还是 s1 vs f2, 我都只是胜出一场, 没差别 
					3. s1 == s2:
						1. f1 < f2:	我的最强 < 对手最强
							选择1 no!: f1 vs f2
							选择2 更好: s1 vs f2
								解释: 
									选择1 . 如果 f1 vs f2 == 我输, 就只能 s1 vs s2 == 平
									选择2 . 如果 s1 vs f2 == 我输, 我不管找谁 vs s2 都能赢, 更好
										解释: 我不管找谁 vs s2 都能赢, 因为 s1 == s2, 那我剩下的都是比s2厉害的
						2. f1 > f2:	我的最强 > 对手最强
							f1 vs f2, 因为我肯定能赢一场 
						3. f1 == f2:
							选择1 no!: f1 vs f2
							选择2 更好: s1 vs f2
								解释: 
									选择1 . 如果 f1 vs f2 == 平, 就只能 s1 vs s2 == 平
									选择2 . 如果 s1 vs f2 == 我输, 我不管找谁 vs s2 都能赢, 更好
										一般的都是选择2优于选择1, 举例:
												我: 3 2 1
												对: 3 2 1
												就完完全全是田忌赛马的例子: 我1比对3, 我2比对1, 我3比对2
										特殊的情况是 f1 == s1 == f2 == s2, 也就是大家全都一样 
											这种情况 选择1 == 选择2
			1. 
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 1010;

				int n;
				int a[N], b[N];

				int judge(int x, int y)                     //judge判断两匹马速度
				{
				    if (a[x] > b[y]) return 1;
				    if (a[x] < b[y]) return -1;
				    return 0;
				}

				int main()
				{
				    while (cin >> n, n)
				    {
				        for (int i = 0; i < n; i ++ ) cin >> a[i];
				        for (int i = 0; i < n; i ++ ) cin >> b[i];

				        sort(a, a + n, greater<int>());     //从大到小排序
				        sort(b, b + n, greater<int>());

				        int f1 = 0, f2 = 0, s1 = n - 1,  s2 = n - 1;    //田忌编号1,主公编号2
				        int res = 0;
				        while (f1 <= s1)                    //判断田忌是否还有🐎
				        {   
				            //田忌的慢马比主公的慢马快,田忌胜1,双方慢马减1
				            if (judge(s1, s2) > 0) res ++ , s1 -- , s2 -- ;

				            //田忌的慢马比主公的慢马慢,这里可以用res--,田忌必负1,田忌慢马减1,主公快马减1
				            else if (judge(s1, s2) < 0) res += judge(s1, f2) , s1 -- , f2 ++ ;
				            else 
				            {   
				                //复杂情况,田忌慢马与主公慢马一样慢时
				                //先判断田忌快马比主公快马快,田忌胜1,双方快马减1
				                if (judge(f1, f2) > 0) res ++ , f1 ++ , f2 ++ ;

				                //若主公快马不弱于田忌快马,则田忌用上面那匹慢马与之竞赛,可达到最优解
				                //注意这里不能用res--,因为此处包含了等于的情况,考虑主公只剩一匹马和田忌最后一匹马同速的情况
				                else res += judge(s1, f2), s1 -- , f2 ++ ;
				            }
				        }

				        cout << res * 200 << endl;
				    }

				    return 0;
				}
		semi AcWing 77. 翻转单词顺序
			1. 两种解法 
				1. 
					1.使用vector来存储一个个单词
					2.用双指针算法来找到一个个单词
						1.用快慢指针找出一个单词
						2.用substr函数截取当前单词段
						3.将单词段放入vector中
					3.反转单词（reverse函数可以实现）
					4.将单词用空格拼接起来
					class Solution {
					public:
					    string reverseWords(string s) 
					    {
					        if(!s.size()) return "" ;             //特判
					        vector<string> words ;                //1 存储单词
					        for(int i=0,j=0;i<s.size();i=++j)     //遍历循环，i为快指针，j为慢指针，i=++j是为了跳出空格，找出下一个单词
					        {
					            while(s[j]!=' '&&j<s.size()) j++ ;//2-1 双指针模板，找到单词结尾
					            words.push_back(s.substr(i,j-i)) ;//2-2&2-3 存入vector
					        }
					        reverse(words.begin(),words.end()) ;  //3 反转vector
					        string res ;                          //答案
					        for(int i=0;i<words.size()-1;i++)
					            res+=words[i]+" " ;               //4 拼接单词
					        res+=words[words.size()-1] ;
					        // 注意，最后一个单词后面没有空格，需要特判
					        return res ;                         //返回结果
					    }
					};
				2.
					1.反转整个单词 （reverse函数实现）//所有单词顺序反转，每个单词本身也反转了 例：abc def 变成 fed cba
					2.用双指针算法来找到一个个单词    //让单词本身反转 例：fed cba 变成 def abc 题目解决
						1.用快慢指针找出一个单词
						2.反转这个单词段
					class Solution {
					public:
					    string reverseWords(string s) {
					        reverse(s.begin(), s.end());
					        for (int i = 0; i < s.size(); i ++ )
					        {
					            int j = i;
					            while (j < s.size() && s[j] != ' ') j ++ ;
					            reverse(s.begin() + i, s.begin() + j);
					            i = j;
					        }
					        return s;
					    }
					};
		semi AcWing 851. spfa求最短路
			1. 做过
	第二讲
		AcWing 35. 反转链表
			1. bug
				ListNode* reverseList(ListNode* head) {
				        if(!head || !head->next) return head; 
				        错误: ListNode* tail = reverseList(head);  TLE, 因为这样就是永远的: reverseList(head) 调用 reverseList(head)
				        正确: ListNode* tail = reverseList(head->next);  
						head->next->next = head;
				        head->next = nullptr;
				        return tail; 
				    }
			2. ok {很顺}
				class Solution {
				public:
				    	// ListNode* reverseList(ListNode* head) 做的事情:
				        // 1. 将以head为首的链表, 翻转了
				        // 2. 返回的是翻转之前的链表的最后一个非null节点 
				    ListNode* reverseList(ListNode* head) {
				        if(!head || !head->next) return head; 		//递归到底的情况 
				        ListNode* tail = reverseList(head->next);   //返回的是翻转之前的链表的最后一个非null节点 
				            //为什么 ListNode* tail = reverseList(head->next); 加在这里, 因为在它下面的代码
				            //我们希望在它下面的代码, 在找到最末尾的节点之后执行, 所以写在这里 
				            //意思是, 我们一进入 reverseList()就有一个 reverseList()函数
				            //也就是一进来就是递归到底, 递归到底之后, 执行的第一段代码, 就是我们底下的代码
				            //递归到底的时候: 找到最末尾的节点
				        head->next->next = head;
				        head->next = nullptr;
				        return tail; 
					        其实是很有意思的故事:
					        	head->next->next = head;
					        	head->next = nullptr;
					        		我head的下一位, 我叫他b, b的下一位却指向了我, 我很莫名其妙
					        		于是我也学他, 我的下一位也指向我的左边, 我的左边是nullptr
					        举例:
					        	2个节点: 
					        		head: a -> b -> nullptr 
						        		ListNode* tail = reverseList(head->next); 
						        			tail 在2节点例子里面就是 节点b
						        		head->next->next = head;	执行完后  a <=> b  	,他们相互指着
						        		head->next = nullptr;		执行完后  nullptr <- a <- b 
						        		函数最后返回 tail == 节点b 
						        3个节点: 
						        	head: c -> a -> b -> nullptr 
						        	简洁版:
						        		1. 原始:
						        			c -> a -> b 
						        					  ↓
						        					  nullptr 
						        		2. b和null断开, ab相互指着:
						        			c -> a <=> b 
						        		3. a指向nullptr
			        						c -> a <- b 
			        							 ↓
			        							 nullptr
				        				4. a和null断开, ca相互指着:
				        					c <=> a -> b 
	        						 	5. c指向nullptr
	        						 		c <- a <- b 
	        						 		↓
			        						nullptr
					        		详细版:
					        			第一次调用 ListNode* tail = reverseList(c->next);  
					        				这里的 ListNode* tail = reverseList(c->next);  相当于执行了上面的2节点的例子
						        			返回的tail是节点b
						        									 c
						        									 ↓
						        				并且结构是: nullptr <- a <- b 
						        		head->next->next = head;	执行完后  
						        																 c
													        									↓ ↑
													        					结构是: 			 a <- b 	也就是a把指向nullptr断开了, 然后a和c相互指着
						        		
						        		head->next = nullptr;		执行完后  
						        											nullptr <- c <- a <- b 
						        		函数最后返回 tail == 节点b 
						    总结:
						    	head->next->next = head;
					        	head->next = nullptr;
					        	这个是翻转了 head 和 head->next两个节点之间的关系
					        	但是从尾结点开始, 向左, 一直执行这两句函数, 就能把全部节点都翻转过来 
					        	回忆:
					        		1. 原始:
					        			c -> a -> b 
					        					  ↓
					        					  nullptr 
					        		2. b和null断开, ab相互指着:
					        			c -> a <=> b 
					        		3. a指向nullptr
		        						c -> a <- b 
		        							 ↓
		        							 nullptr
			        				4. a和null断开, ca相互指着:
			        					c <=> a -> b 
        						 	5. c指向nullptr
        						 		c <- a <- b 
        						 		↓
		        						nullptr
				    }
				};
				--
				class Solution {
				public:
				    ListNode* reverseList(ListNode* head) {
				        if(!head || !head->next) return head;
				        ListNode* tail = reverseList(head->next);
				        head->next->next = head;
				        head->next = nullptr;
				        return tail;
				    }
				};
		AcWing 1453. 移掉K位数字
			0. 小总结:
				其实很简单, 你不需要知道为什么, 记住怎么做就好了:
					0. 我们的原始数字, 很长, 用 string num. 
					1. 其实是一个单调栈, 保存的是递增的序列, 最后我们返回的答案也是这个单调栈
						1. 这个单调栈不是用stack或者数组实现, 而是用 string res, string的左侧是栈底, 右侧是栈顶
							1. 栈的top: string.back()
							2. pop: string.pop_back()
							3. push: string += xxx 	
					2. 从左到右遍历num的每个数字
						栈顶数字, 如果严格大于num的下一个数字, 我们就一直砍掉栈顶
							砍掉一次, k就--, 如果k==0, 就没有几乎继续砍了
						最后把num的下一个数字插入res栈顶
							如果k==0, 就是一直往res栈顶插入num的下一个数字
					3. 如果k > 0, 还有机会, 就把res栈顶pop掉. 也就是把原始数字的末位都去掉
					4. 去掉前导0
				举例:
					1.
						1432219
						3
						单调栈去掉: 4, 3, 2. 没有机会了 
						答案: 1219
					2.
						10
						2
						单调栈去掉: 1. 
						末尾去掉: 0
						剩余0
						答案: 0

			1. bug
			2. ok{非常顺}
				#include <iostream>
				using namespace std;
				string num, res;
				int k;
				int main(){
				    cin >> num;
				    cin >> k;
				    res = num[0];							我的写法: res = num[0], 老师的写法: res = "0". 我的更好一些
				    for(int i = 1; i < num.size(); i++){
				        while(k && res.back() > num[i]){
				            res.pop_back(); k--;
				        }
				        res += num[i];
				    }
				    while(k--) res.pop_back();
				    int i = 0;
				    while(i < res.size() && res[i] == '0') i++;	注意是'0'
				    if(i == res.size()) puts("0");
				    else cout << res.substr(i) << endl;
				    return 0;
				}
				--
				#include <iostream>
				using namespace std;
				const int N = 1e5 + 10;
				int main(){
				    string num;
				    int k;
				    cin >> num;
				    cin >> k;
				    
				    string res = "0";							这里是模拟栈, 初始是0, 因为第一个数字一定 > 0, 所以一定第一次就是 res += num[0]
				    for(int i = 0; i < (int)num.size(); i++){	注意强制转换: (int)
				        while(k && res.back() > num[i]){		栈顶数字, 如果严格大于num的下一个数字, 我们就一直砍掉栈顶
				            res.pop_back();
				            k--;
				        }
				        res += num[i];							最后把num的下一个数字插入res栈顶, 如果k==0, 就是一直往res栈顶插入num的下一个数字
				    }
				    while(k--) res.pop_back();					如果k > 0, 还有机会, 就把res栈顶pop掉. 也就是把原始数字的末位都去掉
				    int i = 0;
				    while(i < (int)res.size() && res[i] == '0') i ++;	保证i是合法的 i < res.size(), 如果是 == 0
				    													出来while, i要么指向一个 res[i] != 0, 要么i出界: i == res.size()
				    if(i == (int)res.size()) puts("0");			i出界, 说明res是全零"0000..."
				    else cout << res.substr(i) << endl;			从i开始打印 
				    return 0;
				}
		semi AcWing 1454. 异或和是质数的子集数
		semi AcWing 1455. 招聘
		semi AcWing 797. 差分
		semi AcWing 173. 矩阵距离
	第一讲完成情况：4/6
		AcWing 756. 蛇形矩阵
			1. bug
				1. {错的离谱}
					完全错了: 并不是上下左右四个方向轮流, 是一直往右, 直到不行了, 才往下
					完全错了:
						#include <iostream>
						using namespace std;
						const int N = 110;
						int g[N][N], n;
						int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
						int main(){
						    cin >> n;
						    for(int a = 0, b = 0, = 1; k <= n * n; ){
						        for(int i = 0 ; i < 4 ;i++){
						            int ta = a + dx[i], tb = b + dy[i];
						            if(ta < 0 || ta >= n || tb < 0 || tb >= n || g[ta][tb]) 
						                continue;
						            g[ta][tb] = k++;
						        }
						    }
						}
				2. 也是几乎完全错
					#include <iostream>
					using namespace std;
					const int N = 110;
					int g[N][N], n, m;
					int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
					int main(){
					    cin >> n >> m;
					    int i = 0, j = 0, d = 0;
					    for(int k = 1; k <= n * m; k++){
					        g[i][j] = k;
					        错误: i += dx[d], j += dy[d];	错在: 如果这个i,j是不合法的就错了
					        if(i < 0 || i >= n || j < 0 || j >= m || g[i][j]){
					            d = (d + 1) % 4;
					            错误: i += dx[d], j += dy[d]; 看到了吗, 错在我们还是在错误的ij上面 +=
					        }
					    }
					    for (int i = 0; i < n; i ++ ){
					        for (int j = 0; j < m; j ++ ) cout << g[i][j] << ' ';
					            cout << endl;
					    }
					}
				3. 
					#include <iostream>
					using namespace std;
					const int N = 110;
					int g[N][N], n, m;
					int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
					int main(){
					    cin >> n >> m;
					    int i = 0, j = 0, d = 0;
					    for(int k = 1; k <= n * m; k++){
					        g[i][j] = k;
					        int a = i + dx[d], b = j + dy[d];
					        错误: while(a < 0 || a >= n || b < 0 || b >= m || g[a][b]){	如果是这么写, 等到我们遍历到最后一个元素的时候, 我们会while个没完, 因为全部都不是我们要的合法的{i,j}
					        正确: if(a < 0 || a >= n || b < 0 || b >= m || g[a][b]){	如果是这么写, 等到我们遍历到最后一个元素的时候, 虽然{ij}是不合法的, 但是我们还是能够跳出来, 因为 d = (d + 1) % 4; 只执行一次
					            d = (d + 1) % 4;
					            a = i + dx[d], b = j + dy[d];
					        }
					        i = a, j = b;
					    }
					    for (int i = 0; i < n; i ++ ){
					        for (int j = 0; j < m; j ++ ) cout << g[i][j] << ' ';
					            cout << endl;
					    }
					}
			2. ok 
				#include <iostream>
				using namespace std;
				const int N = 110;
				int g[N][N], n, m;
				int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
				int main(){
				    cin >> n >> m;
				    int i = 0, j = 0, d = 0;
				    for(int k = 1; k <= n * m; k++){		//合法的状态就是 k <= n * m
				        g[i][j] = k;
				        int a = i + dx[d], b = j + dy[d];	//不能用 += 是因为我们如果错了, 还是需要原始的i和j
				        if(a < 0 || a >= n || b < 0 || b >= m || g[a][b]){
				            d = (d + 1) % 4;
				            a = i + dx[d], b = j + dy[d];
				        }
				        i = a, j = b;
				    }
				    for (int i = 0; i < n; i ++ ){
				        for (int j = 0; j < m; j ++ ) cout << g[i][j] << ' ';
				            cout << endl;
				    }
				}	
		AcWing 1451. 单链表快速排序
			0. 小总结:
				1.
					for(起始; 合法状态; 如何去下一个)
					while(合法状态)
						所以while跳出来后就是非法状态
						技巧: 如果我们用了next, 如果next是非法状态, 那么cur就是最后一个合法状态 
						举例:
							ListNode* get_tail(ListNode* node){
						        while(node->next: 如果next是和法状态) node = node->next;
						        跳出来的时候, node->next 是非法的, 但是我们有node, node是最后一个合法状态 
						        return node;
						    }
				2. 思考链表
					其实所有的不管是 node, node->next, 你就想成一个真实的节点, 不要管什么细节的指针问题, 这样就会简单很多
					本题中:
						l: 想成一个存了 -1的节点
						l->next: 我们真实要的left段的那个首节点
						lt: left段的最后一个非null节点
						对于m/r, 逻辑都是一样的
				2. 总结思路:
					1. 链表快排
						1. 选出target
						2. new三个链表头{l,m,r}, 和3个链表尾{lt,mt,rt}
						3. 开始遍历我们的原始链表 
							通过判断某个节点的val ?== target, 将这个节点插入相应的链表尾{lt,mt,rt}
						4. 链表尾截断
							lt->next = mt->next = rt->next = nullptr;	
						5. 3个{l,m,r}部分递归调用快排代码, 返回的是三个部分的头结点
						6. 三个部分首尾相连
							需要找到每个部分的尾结点{因为已经排了序, 所以尾结点不再是{lt,mt,rt}}
							找排序后的每个部分的尾节点: get_tail()
						7. delete
					2. 数组快排:
						二路:
							1. 选择val
								1. 随机选一个x, 防止x是数组里面的min或者max;
								2. 这样子, 我们就让x在最左边了, 因为分的结果也需要x在最左边
							2. 开始用while + 双指针{i,j}
								两个指针指向不符合的部分, 用 swap()互换
								while结束, 互换结束
							3. 直接递归两个部分
								quick_sort(q, l, j);
						    	quick_sort(q, j + 1, r);
						三路:
							1. 选择val
								1. 随机选一个x, 防止x是数组里面的min或者max;
								2. 这样子, 我们就让x在最左边了, 因为分的结果也需要x在最左边
							2. 开始用while + 三指针{test,i,j}
								核心代码:
									int test = l + 1, i = (l + 1) - 1, j = r + 1; 这里的i,j是[]闭区间, 闭区间的初始化是: [0,-1]这种逻辑的初始化
								    while(test < j){
								    	if(q[test] == x){
								            test++;
								        }else if(q[test] < x){
								            i++;					执行i++前, q[i]指的是<v的最后一个元素执行完i++后, q[i]指的是==v的第一个元素
								            swap(q[i], q[test]);
								            test++;		
								        }else{
								            j--;					执行完j--后, q[j]指的是一个不知道是什么的元素
								            swap(q[j], q[test]);	当执行完q[j]后, q[j]是>x的元素, 但是q[test]是一个不知道是什么的元素
								        }
								    }
								    swap(q[l], q[i]); 
								    	执行这句话之前, <v的部分: [l+1, i]
								    	执行这句话之前, <v的部分: [l, i-1], 即[l, i), 此时i才是开区间
							3. 直接递归两个部分
								quick_sort(q, l, i - 1);
						    	quick_sort(q, j, r);	小心错误, 并不是 (q, j + 1, r)


				3. 比较数组的快排:
					0. 数组快排的确不适合工作
						因为只是数组之间的元素, 都是小元素
						我们这里的链表的快排, 是指针, 所以是struct大元素
					1. 二路:
						#include <iostream>
						using namespace std;

						const int N = 100010;
						int q[N];
						int n;

						void quick_sort(int q[], int l, int r){
						    if(l >= r) return;
						    int ind = l + (rand() % (r - l + 1));
						    int x = q[ind]; -> 随机选一个x, 防止x是数组里面的min或者max;
						   	swap(q[l], q[ind]);	这样子, 我们就让x在最左边了, 因为分的结果也需要x在最左边
						    int i = l - 1, j = r + 1;
						    while(i < j){
						        do i++; while(q[i] < x);
						        do j--; while(x < q[j]);
						        if(i < j) swap(q[i], q[j]);
						    }
						    quick_sort(q, l, j);
						    quick_sort(q, j + 1, r);
						}

						int main(){
						    scanf("%d", &n);
						    for(int i = 0; i < n; i++)
						        scanf("%d", &q[i]);
						        
						    quick_sort(q, 0, n - 1);
						    for(int i = 0; i < n; i++)
						        printf("%d ", q[i]);
						    return 0;
						}
					2. 三路 
						#include <iostream>
						using namespace std;
						const int N = 100010;
						int q[N];
						int n;

						void quick_sort(int q[], int l, int r){
						    if(l >= r) return;
						    int ind = l + rand() % (r - l + 1);
						    int x = q[ind];
						    swap(q[l], q[ind]);
						    
						    int test = l + 1, i = (l + 1) - 1, j = r + 1; 这里的i,j是[]闭区间, 闭区间的初始化是: [0,-1]这种逻辑的初始化
						    while(test < j){
						    	if(q[test] == x){
						            test++;
						        }else if(q[test] < x){
						        							执行i++前, q[i]指的是<v的最后一个元素
						            i++;					执行完i++后, q[i]指的是==v的第一个元素
						            swap(q[i], q[test]);
						            test++;		
						        }else{
						            j--;					执行完j--后, q[j]指的是一个不知道是什么的元素
						            swap(q[j], q[test]);	当执行完q[j]后, q[j]是>x的元素, 但是q[test]是一个不知道是什么的元素
						        }
						        //等于v部分：
				    				// arr[i+1,...test-1] == v, 所以test是最后==v的右端点
							    //小于v部分：
							    	// arr[l+1,...,i] < v, 所以i是最后<v的右端点
							    //大于v部分：
							    	// arr[j,...,r] > v
						    }
						    swap(q[l], q[i]);	//执行这一句之前, q[l]是==v的那个孤单的元素, q[i]是<v的最后一个元素

						    执行到这里:
						    	//等于v部分：
				    				// arr[i,...j-1] == v, 所以test是最后==v的右端点
							    //小于v部分：
							    	// arr[l,...,i-1] < v, 所以i是最后<v的右端点
							    //大于v部分：
							    	// arr[j,...,r] > v
						    quick_sort(q, l, i - 1);
						    quick_sort(q, j, r);	小心错误, 并不是 (q, j + 1, r)
						}
						int main(){
						    scanf("%d", &n);
						    for(int i = 0; i < n; i++)
						        scanf("%d", &q[i]);
						        
						    quick_sort(q, 0, n - 1);
						    for(int i = 0; i < n; i++)
						        printf("%d ", q[i]);
						    return 0;
						}
			1. bug
			2. ok{超级顺}
				/**
				 * Definition for singly-linked list.
				 * struct ListNode {
				 *     int val;
				 *     ListNode *next;
				 *     ListNode(int x) : val(x), next(NULL) {}
				 * };
				 */
				class Solution {
				public:
				    ListNode* get_tail(ListNode* node){
				        while(node->next) node = node->next;
				        return node;
				    }
				    ListNode* quickSortList(ListNode* head) {
				        if(!head || !head->next) return head;
				        int val = head->val;
				        auto l = new ListNode(-1), m = new ListNode(-1), r = new ListNode(-1);
				        auto lt = l, mt = m, rt = r;
				        for(auto cur = head; cur ; cur = cur->next){
				            if(cur->val == val) mt = mt->next = cur;
				            else if(cur->val < val) lt = lt->next = cur;
				            else rt = rt->next = cur;
				        }
				        lt->next = mt->next = rt->next = nullptr;
				        l->next = quickSortList(l->next);
				        r->next = quickSortList(r->next);
				        get_tail(l)->next = m->next;
				        get_tail(l)->next = r->next;
				        auto res = l->next;
				        delete l, m, r;
				        return res;
				    }
				};
				---
				/**
				 * Definition for singly-linked list.
				 * struct ListNode {
				 *     int val;
				 *     ListNode *next;
				 *     ListNode(int x) : val(x), next(NULL) {}
				 * };
				 */
				class Solution {
				public:
				    ListNode* get_tail(ListNode* node){			找到链表的最后一个非null节点
				        while(node->next) node = node->next;
				        return node;
				    }
				    ListNode* quickSortList(ListNode* head) {
				        易错: if(!head->next || !head) 因为有时候left->next是nullptr,所以head是nullptr,head->next自然会报错
						正确: if(!head || !head->next) 记得要先判断head, 然后才是 head->next
				        ListNode* l = new ListNode(-1);
				        ListNode* m = new ListNode(-1);
				        ListNode* r = new ListNode(-1);
				        int val = head->val;
				        auto lt = l, mt = m, rt = r;
				        for(ListNode* cur = head; cur; cur = cur->next){
				            if(cur->val < val){
				                // lt->next = cur;
				                // lt = lt->next;
				                lt = lt->next = cur;	因为是从右侧开始执行, 所以是上面两句的合并 
				            }else if(cur->val == val) mt = mt->next = cur;
				            else rt = rt->next = cur;
				        }
				        易错, 忘记写:
				        正确: lt->next = mt->next = rt->next = nullptr;	
				        	记得结尾清空, 否则不知道哪里结尾, 因为此时这些tail就是原先的p, 而原先的p->next都是保留着原先的下一个节点{非空的}: 
			        		另外, 你清空是为了让递归调用 quickSortList()的时候知道什么时候是结束
				        l->next = quickSortList(l->next);
				        r->next = quickSortList(r->next);
				        get_tail(l)->next = m->next;	left段的尾结点的下一个 == middle段的第一个节点
				        易错: get_tail(m)->next = r->next; 	注意我们可能没有middle段, 所以我们还是要从left开始找
				        正确: get_tail(l)->next = r->next;
				        
				        auto res = l->next;
				        delete l;
				        delete m;
				        delete r;
				        return res;
				    }
				};
		AcWing 1452. 寻找矩阵的极小值
			1. bug
				无语的bug:
					错误:
						if(left < t) mid = r - 1;
			            else mid = l + 1;
		            正确:
			            if(left < min) r = mid - 1;
			            else l = mid + 1;
			2. ok{非常顺}
				// Forward declaration of queryAPI.
				// int query(int x, int y);
				// return int means matrix[x][y].

				class Solution {
				public:
				    vector<int> getMinimumValue(int n) {
				        typedef long long LL;
				        const LL INF = 1e15;
				        
				        int l = 0, r = n - 1;
				        while(l < r){
				            int mid = l + (r - l) / 2; //第mid列
				            
				            //以下是找第mid列的最小的元素: min 和 行号row
				            LL min = INF;
				            int row = -1;
				            for(int i = 0; i < n; i++){
				                int v = query(i, mid);
				                if(v < min){
				                    min = v;
				                    row = i;
				                }
				            }
				            
				            //看这个最小元素的左右元素是多少, 注意mid列是第0列和第n-1列的特殊情况 
				            LL left = mid >= 1 ? query(row, mid - 1) : INF; 
				            LL right = mid + 1 < n ? query(row, mid + 1) : INF;
				            
				            //判断下一个mid, 往左边的列找还是往右边的列找
				            if(min < left && min < right) return {row, mid};
				            if(left < min) r = mid - 1;
				            else l = mid + 1;
				        }
				        //出来就是 l == r, 挤到了某一列, 可以是任意一列. 求出这一列的最小元素就好
				        LL min = INF;
				        int row = -1;
				        for(int i = 0; i < n; i++){
				            int v = query(i, l);
				            if(v < min){
				                min = v;
				                row = i;
				            }
				        }
				        return {row, l};
				    }
				};
				--
				// Forward declaration of queryAPI.
				// int query(int x, int y);
				// return int means matrix[x][y].

				class Solution {
				public:
				    vector<int> getMinimumValue(int n) {
				        typedef long long LL;	因为题目是int范围 
				        const LL INF = 1e15;
				        int l = 0, r = n - 1;
				        while(l < r){
				            int mid = l + (r - l) / 2;
				            int k = 0;		
				            LL t = INF;
				            for(int i = 0 ; i < n; i++){
				                int v = query(i, mid);
				                if(v < t){
				                    t = v;
				                    k = i;
				                }
				            }
				            LL left = mid >= 1 ? query(k, mid - 1) : INF;
				            LL right = mid + 1 < n ? query(k, mid + 1) : INF;
				            if(t < left && t < right) return {k, mid};
				            if(left < t) r = mid - 1;
				            else l = mid + 1;
				        }
				        int k = 0;
				        LL t = INF;
				        for(int i = 0 ; i < n; i++){
				            int v = query(i, l);
				            if(v < t){
				                t = v;
				                k = i;
				            }
				        }
				        return {k, r};
				    }
				};
		todo AcWing 1048. 鸡蛋的硬度
		AcWing 41. 包含min函数的栈
			0. 解释:
				还是很简单的, 现在仅考虑 minstack的情况, stack的情况不考虑
					push:
						如果 minstack 为空, 可以直接push
						如果新的元素比 minstack 的最上面的元素 相等或者小于, 可以直接push
					pop:
						如果要删除的元素 == minstack, 就直接pop
					top:
						直接返回最上层元素就好
				举例:
					push:
						需要加的:		4 2 5 9 2 3  	-> 全部都push进去 
						stack:		4 2 5 9 2 3		-> 最后结果 {栈底 ... 栈顶}
						minstack:	4 2     2		-> 最后结果 {栈底 ... 栈顶}
					getmin: 
						minstack.top() == 2
					pop:
						pop第1个: 3
							stack:		4 2 5 9 2
							minstack:	4 2     2
						pop第2个: 2
							stack:		4 2 5 9
							minstack:	4 2    
					getmin:
						依旧是: minstack.top() == 2
					pop:
						pop第3个: 9
							stack:		4 2 5
							minstack:	4 2  
						pop第4个: 5
							stack:		4 2
							minstack:	4 2  
						pop第5个: 2
							stack:		4
							minstack:	4
					getmin:
						依旧是: minstack.top() == 4
			1. bug
			2. ok{很顺} 
				class MinStack {
				public:
				    /** initialize your data structure here. */
				    stack<int> st;
				    stack<int> minst;
				    
				    MinStack() {
				        
				    }
				    
				    void push(int x) {
				        st.push(x);
				        if(minst.empty() || x <= minst.top()) minst.push(x);	
				    }
				    
				    void pop() {
				        if(minst.size() && st.size() && st.top() <= minst.top()) minst.pop();
				        st.pop();
				    }
				    
				    int top() {
				        return st.top();
				    }
				    
				    int getMin() {
				        return minst.top();
				    }
				};

				/**
				 * Your MinStack object will be instantiated and called as such:
				 * MinStack obj = new MinStack();
				 * obj.push(x);
				 * obj.pop();
				 * int param_3 = obj.top();
				 * int param_4 = obj.getMin();
				 */
		todo AcWing 34. 链表中环的入口结点



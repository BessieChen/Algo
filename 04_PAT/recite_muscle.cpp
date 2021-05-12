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
			    
			    int test = l + 1, i = (l + 1) - 1, j = r + 1;
			    while(test < j){
			        if(q[test] > x) {
			            j--;	执行完j--后, q[j]指的是一个不知道是什么的元素
			            swap(q[test], q[j]);	当执行完q[j]后, q[j]是>x的元素, 但是q[test]是一个不知道是什么的元素
			        }else if(q[test] < x){
			            i++;	执行完i++后, q[i]指的是==v的第一个元素
			            swap(q[test], q[i]); 
			            test++;
			        }else{
			            test++;
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
				队列: hh初始是0, tt初始是-1
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
		另一种说法:
			知道起点是l, 想去终点r, 应该怎么走: r - l + 1
				举例: 字符串哈希 h[r] - h[l - 1] * p[r - l + 1];
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
			        ne[i] = j;	不管是打得过{j!=0} 	"还是无路可退{j==0}, 都要记录ne[i]"
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
		    									如果 i > 0 是 i, 也就是 i != 0

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
35. AcWing 839. 模拟堆
	1. bug
	2. ok


	哈希, 离散化, kmp算法
				







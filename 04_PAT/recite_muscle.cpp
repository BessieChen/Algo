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
43. AcWing 847. 图中点的层次
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



dijkstra优化
	瓶颈在于, 每条边插入heap的效率比较低: loge
	有e条边, 如果边很多,插入的效率就会很慢
		可能不如不优化, 因为不优化根本不需要插入heap这个动作

		


		
		



				







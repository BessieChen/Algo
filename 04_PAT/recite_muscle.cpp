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
			            j--;
			            swap(q[test], q[j]);
			        }else if(q[test] < x){
			            i++;
			            swap(q[test], q[i]); 执行完i++后, q[i]指的是==v的第一个元素
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

			    quick_sort(q, l, i - 1);
			    quick_sort(q, j, r);
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
2. AcWing 786. 第k个数
	1. bug 
		#include <iostream>
		#include <algorithm>

		using namespace std;

		const int N = 100010;
		int q[N];
		int n, k;

		int quick_sort(int q[], int l , int r, int k){
		    if(l >= r) return q[l];					不是 l <= r
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
12. AcWing 796. 子矩阵的和





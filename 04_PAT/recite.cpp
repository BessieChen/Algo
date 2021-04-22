目标:
	1. 面试:
		1. 基础 
		2. 提高 
		3. 面试/剑指offer
		4. pat 
	2. pat证书, ccf比赛, google比赛:
		1. 进阶
		2. ccf 
		3. 算法竞赛进阶指南
		4. 蓝桥杯
	3. 日常切瓜:
		1. leetcode
1. 基础
	1. 基础算法
		1. 快速排序
			1. AcWing 785. 快速排序
				1. 网址
					https://www.acwing.com/problem/content/787/
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int q[N];

					void quick_sort(int q[], int l, int r)
					{
					    if (l >= r) return; 如果区间里面没有数字, 或者一个数字, 直接返回 

					    int i = l - 1, j = r + 1, x = q[l + r >> 1];
					    两个指针:
					    	i: 指向l的左边一位
					    	j: 指向r的右边一位

					    while (i < j)
					    {
					        do i ++ ; while (q[i] < x); 不管三七二十一, 先i往右移, 然后看是否满足条件. 总之最后的i都是不满足条件的i
					        do j -- ; while (q[j] > x);
					        if (i < j) swap(q[i], q[j]);
					    }

					    quick_sort(q, l, j);
					    quick_sort(q, j + 1, r);
					}

					int main()
					{
					    int n;
					    scanf("%d", &n);

					    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

					    quick_sort(q, 0, n - 1);

					    for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);

					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int q[N];

					void quick_sort(int q[], int l, int r)
					{
					    if (l >= r) return;

					    int i = l - 1, j = r + 1, x = q[l + r >> 1];
					    while (i < j)
					    {
					        do i ++ ; while (q[i] < x);
					        do j -- ; while (q[j] > x);
					        if (i < j) swap(q[i], q[j]);
					    }

					    quick_sort(q, l, j);
					    quick_sort(q, j + 1, r);
					}

					int main()
					{
					    int n;
					    scanf("%d", &n);

					    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

					    quick_sort(q, 0, n - 1);

					    for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);

					    return 0;
					}
				4. 复杂度
			2. AcWing 786. 第k个数
				1. 网址
					https://www.acwing.com/problem/content/788/
				2. 代码{解析}
					快速排序 != 快速选择{只排左右其中一个部分}
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int q[N];

					int quick_sort(int q[], int l, int r, int k)
					{
					    if (l >= r) return q[l];

					    int i = l - 1, j = r + 1, x = q[l + r >> 1];
					    while (i < j)
					    {
					        do i ++ ; while (q[i] < x);
					        do j -- ; while (q[j] > x);
					        if (i < j) swap(q[i], q[j]);
					    }

					    if (j - l + 1 >= k) return quick_sort(q, l, j, k); {只排左右其中一个部分}
					    else return quick_sort(q, j + 1, r, k - (j - l + 1)); {只排左右其中一个部分}
					}

					int main()
					{
					    int n, k;
					    scanf("%d%d", &n, &k);

					    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

					    cout << quick_sort(q, 0, n - 1, k) << endl;

					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int q[N];

					int quick_sort(int q[], int l, int r, int k)
					{
					    if (l >= r) return q[l];

					    int i = l - 1, j = r + 1, x = q[l + r >> 1];
					    while (i < j)
					    {
					        do i ++ ; while (q[i] < x);
					        do j -- ; while (q[j] > x);
					        if (i < j) swap(q[i], q[j]);
					    }

					    if (j - l + 1 >= k) return quick_sort(q, l, j, k); 
					    else return quick_sort(q, j + 1, r, k - (j - l + 1)); 
					}

					int main()
					{
					    int n, k;
					    scanf("%d%d", &n, &k);

					    for (int i = 0; i < n; i ++ ) scanf("%d", &q[i]);

					    cout << quick_sort(q, 0, n - 1, k) << endl;

					    return 0;
					}
				4. 复杂度
					nlogn
		2. 归并排序
			1. AcWing 787. 归并排序
				1. 网址
					https://www.acwing.com/problem/content/789/
				2. 代码{解析}
					1. 
						快排: 用数组的某个数字的值来分左右两侧
							先分完, 再递归{往下走}左右两个部分, 左右两个部分不一定平均
							不稳定, 但是快排经过简单修改, 就可以变为稳定
								例如 ai --> {ai, i} 双关键字排序
								于是所有的值都不同了, 就稳定了
							复杂度:
								平均: nlogn
								最坏: n^2, 也就是每次拿到的值都是min或者max, 于是左右两个部分就很不平均
						归并: 用数组中间点来分
							先递归{往下走}左右两个部分, 最后往上归{归才是精华}
							需要一个辅助的数组存, 往上归的时候, 排序的结果
							是稳定排序
							复杂度:
								妥妥的 nlogn 
									解释:
										1. 我们递归了 logn层, 没错吧. 每次都是二分, 所以层数是 logn 
										2. 每一层, a里面的所有元素和b里面的所有元素, 都要比较大小吧, 每一层就是 n
											|-----------n-----------|

											|-----------|-----------|
												   a          b 
											|-----|-----|-----|-----|
											   a     b      a     b
											|--|--|--|--|--|--|--|--|
											  a  b  a  b  a  b  a  b
										3. n*logn = nlogn
					2.
						#include <iostream>

						using namespace std;

						const int N = 1e5 + 10;

						int a[N], tmp[N];

						void merge_sort(int q[], int l, int r)
						{
						    if (l >= r) return;

						    int mid = l + r >> 1; 中点

						    merge_sort(q, l, mid), merge_sort(q, mid + 1, r); 递归 

						    精华: 
						    int k = 0, i = l, j = mid + 1;
						    while (i <= mid && j <= r) 当左边和右边都没有遍历完, 只要有一个遍历完了, 就跳出while
						        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
						        else tmp[k ++ ] = q[j ++ ];

						    扫尾: 把剩余的部分都填满, 这两个 while()只会走一个
						    while (i <= mid) tmp[k ++ ] = q[i ++ ];
						    while (j <= r) tmp[k ++ ] = q[j ++ ];

						    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
						    	i是从左端点开始
						    	j是临时数组 
						}

						int main()
						{
						    int n;
						    scanf("%d", &n);
						    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

						    merge_sort(a, 0, n - 1);

						    for (int i = 0; i < n; i ++ ) printf("%d ", a[i]);

						    return 0;

				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 1e5 + 10;

					int a[N], tmp[N];

					void merge_sort(int q[], int l, int r)
					{
					    if (l >= r) return;

					    int mid = l + r >> 1;

					    merge_sort(q, l, mid), merge_sort(q, mid + 1, r);

					    int k = 0, i = l, j = mid + 1;
					    while (i <= mid && j <= r)
					        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
					        else tmp[k ++ ] = q[j ++ ];
					    while (i <= mid) tmp[k ++ ] = q[i ++ ];
					    while (j <= r) tmp[k ++ ] = q[j ++ ];

					    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
					}

					int main()
					{
					    int n;
					    scanf("%d", &n);
					    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

					    merge_sort(a, 0, n - 1);

					    for (int i = 0; i < n; i ++ ) printf("%d ", a[i]);

					    return 0;
					}

				4. 复杂度
					nlogn
			2. AcWing 788. 逆序对的数量
				1. 网址
					https://www.acwing.com/problem/content/790/
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					typedef long long LL;

					const int N = 1e5 + 10;

					int a[N], tmp[N];

					LL merge_sort(int q[], int l, int r)
					{
					    if (l >= r) return 0;

					    int mid = l + r >> 1;

					    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

					    int k = 0, i = l, j = mid + 1;
					    while (i <= mid && j <= r)
					        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
					        else
					        {
					            res += mid - i + 1; 精华之处, 这里是 q[i] >= q[j]
					            						因为 q[i] <= q[i+1] <= q[i+2] ... <= q[mid]
					            						所以从i到mid的数, 都大于 q[j], 都是逆序对
					            tmp[k ++ ] = q[j ++ ]; 
					        }
					    while (i <= mid) tmp[k ++ ] = q[i ++ ];
					    while (j <= r) tmp[k ++ ] = q[j ++ ];

					    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];

					    return res;
					}

					int main()
					{
					    int n;
					    scanf("%d", &n);
					    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

					    cout << merge_sort(a, 0, n - 1) << endl;

					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					typedef long long LL;

					const int N = 1e5 + 10;

					int a[N], tmp[N];

					LL merge_sort(int q[], int l, int r)
					{
					    if (l >= r) return 0;

					    int mid = l + r >> 1;

					    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);

					    int k = 0, i = l, j = mid + 1;
					    while (i <= mid && j <= r)
					        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
					        else
					        {
					            res += mid - i + 1;
					            tmp[k ++ ] = q[j ++ ]; 
					        }
					    while (i <= mid) tmp[k ++ ] = q[i ++ ];
					    while (j <= r) tmp[k ++ ] = q[j ++ ];

					    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];

					    return res;
					}

					int main()
					{
					    int n;
					    scanf("%d", &n);
					    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

					    cout << merge_sort(a, 0, n - 1) << endl;

					    return 0;
					}
				4. 复杂度
					nlogn
		3. 二分
			1. AcWing 789. 数的范围
				1. 网址
					https://www.acwing.com/problem/content/791/
				2. 代码{解析}
					1. 
						0. 其他更加灵活的cmin和cmax (不再是从小到大,而是从大到小排), 见1527.
						1. 细节
							1. 先直接上 int mid = l + (r-l) / 2;
								r - l >> 2 + l;
								l + r >> 2;
							2. 然后思考一个true的情况:
								1. 画面中, xx[mid]是固定在xx数组中间的
								2. 但是, 你的目标值是移动的,
									想象如何变成true
										1. 如果是求==target的起始位置
											就想着: 这个位置的点有什么特点?
												特点是, 这个位置右侧的点a都 >= target
												所以我们干脆就让这个点a作为我们的xx[mid], xx[mid] >= target; 这样就满足了右侧的点的条件.
												但是, 我们希望找最左边的右侧点, 所以缩小范围的时候, 向mid的左缩小.
											no no no no target yes yes yes yes
											所以就想着target在xx[mid]的左侧才是true
												画面是 l ----- target -----xx[mid]固定 ---------------- r
											所以就是If(target <= xx[mid])
										2. 如果是求==target的终止位置
											就想着: 这个位置的点有什么特点?
												特点是, 这个位置左侧的点都 <= target
												所以我们干脆就让xx[mid] <= target; 这样就满足了左侧的点的条件.
												但是, 我们希望找最右边的左侧点, 所以缩小范围的时候, 向mid的右侧缩小.
											yes yes yes target no no no
											所以就想着target在xx[mid]的右侧才是true
												画面是 l --------------xx[mid]固定 --------target---- r
											所以就是If(xx[mid] <= target)
							3. 如果是 true 的话, 有两种选择:
								1. 如果我们的想要的区间在左侧[l, mid]. 例如求==target的起始位置, 就是希望继续往左边找
									也就是从[l, r]变成[l, mid], 所以l不变, r = mid;
										感性理解, 如果 target <= xx[mid], 所以 mid 也有可能是 ==target的起始位置, 所以往左边找 r = mid.
									此时, 怎么写 else, 不用想, false 的情况就是l = mid + 1;
										l 比 r 优越, 所以是 + 1

									对应的模板:
										区间 [l, r]被划分成 [l, mid] + [mid + 1, r], 也就是mid属于左侧
											int func(int l, int r){
												while(l < r){
													int mid = r - l >> 2 + l;
													if(check(mid) == true) r = mid;
													else l = mid + 1;
												}
												return l;
											}

								2. 如果我们的想要的区间在右侧[mid, r]. 例如求==target的终止位置, 就是希望继续往右边找
									也就是从[l, r]变成[mid, r], 所以r不变, l = mid;
										感性理解, 如果 xx[mid] <= target, 所以 mid 也有可能是 ==target的终止位置, 所以往右边找 l = mid.
									一旦l = mid; 二话不说, 将之前的mid加一: int mid = l + (r-l)/2 + 1; 否则还是用原先的 int mid = r - l >> 2 + l; 就会导致循环
									此时, 怎么写 else, 不用想, false 的情况就是r = mid - 1;
										r 比 l 低贱, 所以是 - 1

									对应的模板:
										区间 [l, r]被划分成 [l, mid-1] + [mid, r], 也就是mid属于右侧
											int func(int l, int r){
												while(l < r){
													int mid = r - l >> 2 + l + 1; 二话不说, 将之前的mid加一: int mid = l + (r-l)/2 + 1; 否则还是用原先的 int mid = r - l >> 2 + l; 就会导致循环
													if(check(mid) == true) l = mid;
													else r = mid - 1;
												}
												return l;
											}
						2. 总结: 右改mid(谐音, 又改mid)
							1. 思考一个xx[mid]满足要求的情况, 也就是true的情况,
								通过固定xx[mid], 移动target
							2. 如果true, 你是想继续往左还是往右? 
								举例:
									1. 求==target的起始位置, 就是希望如果 true的话, 继续往左边找
										感性理解, 如果 target <= xx[mid] 为true, 所以 mid 也有可能是 ==target 的起始位置, 所以往左边找 r = mid.
									2. 求==target的终止位置, 就是希望如果 true{当然这个check的判断和上一例子不同了}的话, 继续往右边找
										感性理解, 如果 xx[mid] <= target 为true, 所以 mid 也有可能是 ==target的终止位置, 所以往右边找 l = mid.

								就是想象画面
									往左走, mid没有抛弃, 我们找的是: [l,mid], 也就是 r = mid.
										所以对应的false怎么写, 就是接下去找右侧 [mid + 1, r], 也就是 l = mid + 1;
									往右走, mid也没有抛弃, 我们找的是: [mid,r], 也就是 l = mid. {因为怕常规的 mid = l + (r-l)/2; 会导致 mid死循环}, 记得要改为: mid = l + (r-l)/2 + 1;
										所以对应的false怎么写, 就是接下去找左侧 [l, mid-1], 也就是 r = mid - 1;
					2. 
						#include <iostream>
						using namespace std;

						const int N = 100010; //bug!!, 我写10010报错了
						int q[N];

						int n;
						int m;

						int main(){
						    scanf("%d%d", &n, &m);
						    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);

						    while(m --){ //good
						        int x;
						        scanf("%d", &x);

						        int l = 0, r = n-1; 判断起始位置
						        while(l < r){ 
						            int mid =  r-l >> 1 + l; mid需不需要补上 + 1, 最后看是 l = mid{则mid要补上1}, 还是 l = mid + 1
						            if(q[mid] >= x) r = mid; //good: 因为mid是true的时候,也就是右侧都是x或者>=x的时候. 
						            else l = mid+1;
						        }
						        //出来一定是 l == r, 并且l指向的是==x或者第一个>x的数字

						        if(q[l] != x) cout<<"-1 -1"<<endl;
						        else{ //能进入这里,保证了已经有一个是==x的值了
						            cout << l << ' '; //把之前的index打印出来

						            int l = 0, r = n-1; 判断终止位置
						            while(l < r){
						                int mid = (r - l + 1)/2 + l; //因为 l = mid, 所以为了防止死循环,我们就要保证mid一直都是取右侧
						                if(q[mid] <= x) l = mid;
						                else r = mid - 1;
						            }
						            cout << l <<endl;
						        }
						    }

						    return 0;
						}
				3. 纯代码
					#include <iostream>
					using namespace std;

					const int N = 100010; 
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
					            int mid =  r-l >> 1 + l; 
					            if(q[mid] >= x) r = mid; 
					            else l = mid+1;
					        }

					        if(q[l] != x) cout<<"-1 -1"<<endl;
					        else{ 
					            cout << l << ' '; 

					            int l = 0, r = n-1; 判断终止位置
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
				4. 复杂度
					logn 
			2. AcWing 790. 数的三次方根
				1. 网址
					https://www.acwing.com/problem/content/792/
				2. 代码{解析}
					#include <iostream>
					using namespace std;

					int main()
					{
					    double x;
					    scanf("%lf", &x); //如果写成scanf("%f", &x)就会报错,因为这时候x就不是浮点数了

					    double l = -100, r = 100;
					    while(r - l > 1e-8) //因为题目要求精确到-6次方,所以这里再减小两位小数
					    {
					        double mid = (r - l)/2 + l;
					        if(mid * mid * mid >= x) r = mid; //说明mid^3 >= x,应该往左找
					        else l = mid; //因为是浮点,所以依旧是=mid
					    }
					    printf("%.6lf",l);
					    return 0;
					}
				3. 纯代码
					#include <iostream>
					using namespace std;

					int main()
					{
					    double x;
					    scanf("%lf", &x);

					    double l = -100, r = 100;
					    while(r - l > 1e-8) 
					    {
					        double mid = (r - l)/2 + l;
					        if(mid * mid * mid >= x) r = mid; 
					        else l = mid;
					    }
					    printf("%.6lf",l);
					    return 0;
					}
				4. 复杂度
					logn
		3. 高精度
			1. AcWing 791. 高精度加法
				1. 网址
					https://www.acwing.com/problem/content/793/
				2. 代码{解析}
					#include <iostream>
					#include <vector> //因为vector里面存有size的信息.不需要用额外空间获取
					using namespace std;

					不背这个了, 大同小异, add2()只是用到了这个技巧: if(A.size() < B.size()) return add2(B,A);
					// vector<int> add2(vector<int> &A, vector<int> &B) //这里是传入地址.所以就不需要复制
					// {
					//     if(A.size() < B.size()) return add2(B,A);

					//     int t = 0; //进位
					//     vector<int> C;
					//     for(unsigned int i = 0; i < A.size(); i++) //需要选择最长的那个
					//     {
					//         if(i < A.size()) t += A[i];
					//         if(i < B.size()) t += B[i];
					//         C.push_back(t % 10); //C的index==0位置是数字的最低位
					//         t /= 10;
					//     }
					//     if(t) C.push_back(t);
					//     return C;
					// }

					vector<int> add(vector<int> &A, vector<int> &B) //这里是传入地址.所以就不需要复制
					{
					    int t = 0; //进位
					    vector<int> C;
					    for(unsigned int i = 0; i < A.size() || i < B.size(); i++) 只要A和B还有一个没有完, 就继续下去 //需要选择最长的那个 //注意不能用 int i, 编译出错
					    {
					        if(i < A.size()) t += A[i];
					        if(i < B.size()) t += B[i];
					        C.push_back(t % 10); //C的index==0位置是数字的最低位
					        t /= 10; 给下一次的进位
					    }
					    if(t) C.push_back(t); 如果还有进位
					    return C;
					}

					int main()
					{
					    string a,b;//传入的大数字
					    vector<int> A, B; //存到数组

					    cin >> a >> b;
					    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0'); 把数字低位{也就是末位, a.size()-1} 先push
					    for(int i = b.size()-1; i >= 0; i --) B.push_back(b[i] - '0'); //注意这里是char '0'

					    auto C = add2(A, B); //相当于vector<int> C = add(A,B);
					    for(int i = C.size()-1 ; i >= 0; i--) printf("%d",C[i]); 输出的时候, 也是先输出数字高位, 也就是vector的末尾: C.size()-1
					    cout << endl;
					    return 0;
					}
				3. 纯代码
					#include <iostream>
					#include <vector> 
					using namespace std;

					vector<int> add(vector<int> &A, vector<int> &B) 
					{
					    int t = 0;
					    vector<int> C;
					    for(unsigned int i = 0; i < A.size() || i < B.size(); i++)
					    {
					        if(i < A.size()) t += A[i];
					        if(i < B.size()) t += B[i];
					        C.push_back(t % 10); 
					        t /= 10; 
					    }
					    if(t) C.push_back(t); 
					    return C;
					}

					int main()
					{
					    string a,b;
					    vector<int> A, B;

					    cin >> a >> b;
					    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0'); 
					    for(int i = b.size()-1; i >= 0; i --) B.push_back(b[i] - '0');

					    auto C = add2(A, B); 
					    for(int i = C.size()-1 ; i >= 0; i--) printf("%d",C[i]); 

					    cout << endl;
					    return 0;
					}
				4. 复杂度
			2. AcWing 792. 高精度减法
				1. 网址
					https://www.acwing.com/problem/content/794/
				2. 代码{解析}
					#include <iostream>
					#include <vector>
					using namespace std;

					//if A >= B
					bool cmp(vector<int> &A, vector<int> &B){
					    if(A.size() != B.size()) return A.size() > B.size();

					    //比较数字高位,也就是vector的index的高位
					    for(int i = A.size()-1; i >= 0; i--){
					        if(A[i] != B[i])
					            return A[i] > B[i]; //小心:不要写成 >=
					    }

					    return true;
					}

					vector<int> sub(vector<int> &A, vector<int> &B){
					    vector<int> C;

					    int t = 0;//进位

					    //先减数字低位,也就是index==0. 结果数字的低位,保存在了C 的index == 0
					    for(int i = 0; i <= A.size()-1; i++){
					        int temp = A[i] - t;//A首先看是否之前被借了1
					        if(i <= B.size()-1) temp -= B[i]; //如果B还有第i位
					        	如果B已经遍历完了, 那之后剩下的A的高位, 就直接是 C里面 push_back(temp)了
					        C.push_back( (temp + 10) % 10); //如果temp = -2, 那么就是8. 如果temp = 2, 那么就是2
					        if(temp >= 0) t = 0; 
					        else t = 1; //注意:一定要严格temp < 0才表明借了
					    }

					    //删除数字高位的0, 也就是C index末尾, 也就是C.back
					    注意, 可能存在 A == B的情况, 例如 123 == 123, 这样就会导致C里面存的是 000, 我们去掉前导0, 也就是至少还要剩余最后一个0
					    while(C.size() > 1 && C.back() == 0) C.pop_back(); //语意: while里面是要pop掉的条件, 所以允许0,但是不允许003

					    return C;
					}
					int main(){ 这道题, 假定两个数都是正数, 不存在负数
					    string a, b;
					    cin >> a >> b;
					    vector<int> A;
					    vector<int> B;

					    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0'); //bug, 记得 - '0'
					    for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');

					    vector<int> C;

					    if(cmp(A,B)){ //A>=B
					        C = sub(A,B);
					        for(int i = C.size()-1; i >= 0; i--) cout<<C[i];
					    }
					    else
					    {
					        C = sub(B,A);
					        cout<<"-";
					        for(int i = C.size()-1; i >= 0; i--) cout<<C[i];
					    }
					    cout<<endl;
					    return 0;
					}
				3. 纯代码
					#include <iostream>
					#include <vector>
					using namespace std;

					bool cmp(vector<int> &A, vector<int> &B){
					    if(A.size() != B.size()) return A.size() > B.size();
					    for(int i = A.size()-1; i >= 0; i--){
					        if(A[i] != B[i])
					            return A[i] > B[i]; 
					    }

					    return true;
					}
					vector<int> sub(vector<int> &A, vector<int> &B){
					    vector<int> C;

					    int t = 0;

					    for(int i = 0; i <= A.size()-1; i++){
					        int temp = A[i] - t;
					        if(i <= B.size()-1) temp -= B[i];
					        C.push_back( (temp + 10) % 10); 
					        if(temp >= 0) t = 0; 
					        else t = 1; 
					    }

					    while(C.size() > 1 && C.back() == 0) C.pop_back(); 

					    return C;
					}
					int main(){ 
					    string a, b;
					    cin >> a >> b;
					    vector<int> A;
					    vector<int> B;

					    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0'); 
					    for(int i = b.size()-1; i >= 0; i--) B.push_back(b[i] - '0');

					    vector<int> C;

					    if(cmp(A,B)){ 
					        C = sub(A,B);
					        for(int i = C.size()-1; i >= 0; i--) cout<<C[i];
					    }
					    else
					    {
					        C = sub(B,A);
					        cout<<"-";
					        for(int i = C.size()-1; i >= 0; i--) cout<<C[i];
					    }
					    cout<<endl;
					    return 0;
					}
				4. 复杂度
			3. AcWing 793. 高精度乘法
				1. 网址
					https://www.acwing.com/problem/content/795/
				2. 代码{解析}
					#include <iostream>
					#include <vector>
					using namespace std;

					背这个:
					vector<int> mul2(vector<int> &A, int b){
					    vector<int> C;
					    int t = 0;
					    for(unsigned int i = 0; i < A.size() || t ; i++) //合并了while
					    {
					        if(i < A.size()) t = A[i] * b + t; //还有上一次的
					        	注意, 最大就是9*9=81, 也就是t最大81
					        C.push_back(t % 10);
					        t /= 10;
					    }

					    //bug: 忘记删除前置0了, 例如C是300, 意味着是003, 但是答案应该是3
					    while(C.size() > 1 && C.back() == 0) C.pop_back();


					    return C;
					}

					不背这个了:
					// vector<int> mul(vector<int> &A, int b){
					//     vector<int> C;
					//     int t = 0;
					//     for(unsigned int i = 0; i < A.size() ; i++)
					//     {
					//         t = A[i] * b + t; //还有上一次的
					//         C.push_back(t % 10);
					//         t /= 10;
					//     }

					//     while(t){
					//         C.push_back(t % 10);
					//         t /= 10;
					//     }

					//     //bug: 忘记删除前置0了, 例如C是300, 意味着是003, 但是答案应该是3
					//     while(C.size() > 1 && C.back() == 0) C.pop_back();

					//     return C;
					// }
					int main(){
					    string a;
					    int b;
					    cin >> a >> b;

					    vector<int> A;
					    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0'); //bug, 忘记- 0

					    vector<int> C = mul(A,b);

					    for(int i = C.size()-1; i >= 0 ; i--) cout<<C[i];

					    cout<<endl;
					    return 0;
					}
				3. 纯代码
					#include <iostream>
					#include <vector>
					using namespace std;

					vector<int> mul(vector<int> &A, int b){
					    vector<int> C;
					    int t = 0;
					    for(unsigned int i = 0; i < A.size() || t ; i++) 
					    {
					        if(i < A.size()) t = A[i] * b + t; 
					        C.push_back(t % 10);
					        t /= 10;
					    }
					    while(C.size() > 1 && C.back() == 0) C.pop_back();


					    return C;
					}

					int main(){
					    string a;
					    int b;
					    cin >> a >> b;

					    vector<int> A;
					    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');

					    vector<int> C = mul(A,b);

					    for(int i = C.size()-1; i >= 0 ; i--) cout<<C[i];

					    cout<<endl;
					    return 0;
					}
				4. 复杂度
			4. AcWing 794. 高精度除法
				1. 网址
					https://www.acwing.com/problem/content/796/
				2. 代码{解析}
					#include <iostream>
					#include <vector>
					#include <algorithm>
					using namespace std;

					vector<int> div(vector<int> &A, int b, int &r){
					    vector<int> C;

					    r = 0;
					    for(int i = A.size()-1; i >= 0; i--){ //是从最高位开始除 //bug! 这里不能用unsigned, 否则i是一直>=0
					        r = r * 10 + A[i]; //首先看上一轮遗留下来的余数, *10, 然后加上这一位的
					        C.push_back(r / b); //除以b,这里可能得到的是0.
					        r %= b; //剩下的余数,给下一轮. 
					    }


					    reverse(C.begin(), C.end());//假设C是0013,其实代表就是数字13{加减乘中, 放入C数组的第一个数其实是答案的低位}, 是人类的视角
					    	但是为了, 和之前的写法统一, 也就是为了能用下面的这一句"while(C.size() > 1 && C.back() == 0) C.pop_back();", 所以先翻转,变成3100,最后去掉末尾的0, 变为31, 最后打印的时候我们是逆序打印, 所以打印出来是13
					    	这里之所以 reverse, 是因为计算除法是先从最高位开始除, 所以放入C数组的第一个数其实是答案的高位, 其实这个视角是我们人类的视角. 回忆 : 加减乘中, 放入C数组的第一个数其实是答案的低位
					    while(C.size() > 1 && C.back() == 0) C.pop_back();

					    return C;
					}




					int main(){
					    string a;
					    int b;

					    cin >> a >> b;

					    vector<int> A;
					    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0'); //其实可以从数字高位推入vec,因为除法是从最高位开始.回忆: +-*都是从数字最低位开始. 但是为了统一, y总还是从数字低位推入vec

					    int r; //余数
					    vector<int> C = div(A,b,r); //用的是别名,也可以修改值

					    for(int i = C.size()-1; i >= 0; i--) cout<<C[i]; //bug! unsigned int i不能用i--的情况
					    cout<<endl<<r;

					    return 0;

					}
				3. 纯代码
					#include <iostream>
					#include <vector>
					#include <algorithm>
					using namespace std;

					vector<int> div(vector<int> &A, int b, int &r){
					    vector<int> C;

					    r = 0;
					    for(int i = A.size()-1; i >= 0; i--){
					        r = r * 10 + A[i]; 
					        C.push_back(r / b);
					        r %= b;
					    }


					    reverse(C.begin(), C.end());
					    while(C.size() > 1 && C.back() == 0) C.pop_back();

					    return C;
					}




					int main(){
					    string a;
					    int b;

					    cin >> a >> b;

					    vector<int> A;
					    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0'); 

					    int r; 
					    vector<int> C = div(A,b,r);

					    for(int i = C.size()-1; i >= 0; i--) cout<<C[i];

					    cout<<endl<<r;

					    return 0;

					}
				4. 复杂度
		4. 前缀和与差分
			1. AcWing 795. 前缀和
				1. 网址
				2. 代码{解析}
					#include <iostream>
					using namespace std;

					const int N = 100010; //这样可以统一管理a[N], S[N]的长度

					int a[N];
					int S[N];

					int main(){
					    int n, m;
					    cin >> n >> m;

					    for(int i = 1; i <= n; i++) scanf("%d", &a[i]); //注意,这里特意从i = 1开始,因为我们要保证a[0] = 0;
					    for(int i = 1; i <= n; i++) S[i] = S[i-1] + a[i]; //注意,这里同样是S[0] = 0

					    while(m--){
					        int l, r;
					        cin >> l >> r;
					        printf("%d\n", S[r] - S[l-1]);
					    }
					    return 0;
					}
				3. 纯代码
					#include <iostream>
						using namespace std;

						const int N = 100010;

						int a[N];
						int S[N];

						int main(){
						    int n, m;
						    cin >> n >> m;

						    for(int i = 1; i <= n; i++) scanf("%d", &a[i]); 
						    for(int i = 1; i <= n; i++) S[i] = S[i-1] + a[i]; 

						    while(m--){
						        int l, r;
						        cin >> l >> r;
						        printf("%d\n", S[r] - S[l-1]);
						    }
						    return 0;
						}
				4. 复杂度
			2. AcWing 796. 子矩阵的和
				1. 网址
				2. 代码{解析}
					#include <iostream>
					using namespace std;

					const int N = 1010;
					int a[N][N];
					int S[N][N];

					int main(){
					    int n, m, p;
					    scanf("%d%d%d", &n, &m, &p);

					    for(int i = 1; i <= n; i++){ //bug, 注意是 i <= n
					        for(int j = 1; j <= m; j++) //bug, 注意是 j <= m
					        {
					            scanf("%d", &a[i][j]); //method 1;
					            //scanf("%d", &S[i][j]); //method 2;
					        }
					    }

					    for(int i = 1; i <= n; i++){ //bug, 注意是 i <= n
					        for(int j = 1; j <= m; j++) //bug, 注意是 j <= m
					        {
					           S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + a[i][j]; //method 1;
					           //S[i][j] += S[i-1][j] + S[i][j-1] - S[i-1][j-1]; //这个是需要搭配scanf()的method 2;
					        }
					    }

					    while(p--){
					        int x1,x2,y1,y2;
					        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

					        int res = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
					        printf("%d\n",res);
					    }
					    return 0;
					}
				3. 纯代码
					#include <iostream>
					using namespace std;

					const int N = 1010;
					int a[N][N];
					int S[N][N];

					int main(){
					    int n, m, p;
					    scanf("%d%d%d", &n, &m, &p);

					    for(int i = 1; i <= n; i++){
					        for(int j = 1; j <= m; j++)
					        {
					            scanf("%d", &a[i][j]); //method 1;
					            //scanf("%d", &S[i][j]); //method 2;
					        }
					    }

					    for(int i = 1; i <= n; i++){ 
					        for(int j = 1; j <= m; j++)
					        {
					           S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + a[i][j]; //method 1;
					           //S[i][j] += S[i-1][j] + S[i][j-1] - S[i-1][j-1]; //这个是需要搭配scanf()的method 2;
					        }
					    }

					    while(p--){
					        int x1,x2,y1,y2;
					        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

					        int res = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
					        printf("%d\n",res);
					    }
					    return 0;
					}
				4. 复杂度
			3. AcWing 797. 差分
				1. 网址
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int a[N];
					int b[N];

					void insert(int l, int r, int v){ 如果要在[l,r]区间的元素, 加上v这个值
							根据公式: 
					    b[l] += v;
					    b[r+1] -= v;
					    return;
					}
					int main(){
					    int n,m;
					    cin >> n >> m;

					    for(int i = 1; i <= n ; i ++) scanf("%d",&a[i]); //填充a

					    for(int i = 1; i <= n; i ++) insert(i, i, a[i]); 在[i,i]区间的元素, 加上a[i]这个值 //构建b

					    while(m --){
					        int l, r, v;
					        scanf("%d%d%d", &l, &r, &v);

					        insert(l, r, v);
					    }

					    for(int i = 1; i <= n; i++) a[i] = a[i-1] + b[i]; 相当于 S[i] = S[i-1] + a[i]; //将b累加,变成新的a
					    for(int i = 1; i <= n ;i++) printf("%d ", a[i]);
					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int a[N];
					int b[N];

					void insert(int l, int r, int v){ 
					    b[l] += v;
					    b[r+1] -= v;
					    return;
					}
					int main(){
					    int n,m;
					    cin >> n >> m;

					    for(int i = 1; i <= n ; i ++) scanf("%d",&a[i]); 

					    for(int i = 1; i <= n; i ++) insert(i, i, a[i]); 

					    while(m --){
					        int l, r, v;
					        scanf("%d%d%d", &l, &r, &v);

					        insert(l, r, v);
					    }

					    for(int i = 1; i <= n; i++) a[i] = a[i-1] + b[i]; 
					    for(int i = 1; i <= n ;i++) printf("%d ", a[i]);
					    return 0;
					}
				4. 复杂度
			4. AcWing 798. 差分矩阵
				1. 网址
				2. 代码{解析}
					#include <iostream>
					using namespace std;

					const int N = 1010;
					int a[N][N];
					int b[N][N];

					void insert(int x1, int y1, int x2, int y2, int v){
					    b[x1][y1] += v;
					    b[x2+1][y1] -= v;
					    b[x1][y2+1] -= v;
					    b[x2+1][y2+1] += v;
					    return;
					}
					int main(){
					    int n, m, p;

					    cin >> n >> m >> p;
					    for(int i = 1; i <= n; i++){
					        for(int j = 1; j <= m; j++){
					            scanf("%d", &a[i][j]);
					        }
					    }

					    for(int i = 1; i <= n; i++){
					        for(int j = 1; j <= m ; j++){
					            insert(i,j,i,j,a[i][j]); //生成b矩阵
					        }
					    }

					    while(p --){
					        int x1, y1, x2, y2, v;
					        cin >> x1 >> y1 >> x2 >> y2 >> v;

					        insert(x1,y1,x2,y2,v);//更新b矩阵
					    }

					    for(int i = 1; i <= n; i++){ //一定是从左往右,从上往下加总
					        for(int j = 1; j <= m; j++)
					            //更新a矩阵, 联系之前的二维前缀和, 这里的a相当于之前的S, 这里的b相当于之前的a
					            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + b[i][j]; //注意,bug: 最后应该是+ b[i][j] 而不是 + a[i][j]
					    }

					    for(int i = 1; i <= n; i++){
					        for(int j = 1; j <= m; j++)
					            printf("%d ", a[i][j]);
					        cout<<endl;
					    }

					    return 0;
					}
				3. 纯代码
					#include <iostream>
					using namespace std;

					const int N = 1010;
					int a[N][N];
					int b[N][N];

					void insert(int x1, int y1, int x2, int y2, int v){
					    b[x1][y1] += v;
					    b[x2+1][y1] -= v;
					    b[x1][y2+1] -= v;
					    b[x2+1][y2+1] += v;
					    return;
					}
					int main(){
					    int n, m, p;

					    cin >> n >> m >> p;
					    for(int i = 1; i <= n; i++){
					        for(int j = 1; j <= m; j++){
					            scanf("%d", &a[i][j]);
					        }
					    }

					    for(int i = 1; i <= n; i++){
					        for(int j = 1; j <= m ; j++){
					            insert(i,j,i,j,a[i][j]);
					        }
					    }

					    while(p --){
					        int x1, y1, x2, y2, v;
					        cin >> x1 >> y1 >> x2 >> y2 >> v;

					        insert(x1,y1,x2,y2,v);
					    }

					    for(int i = 1; i <= n; i++){
					        for(int j = 1; j <= m; j++)
					            a[i][j] = a[i-1][j] + a[i][j-1] - a[i-1][j-1] + b[i][j];
					    }

					    for(int i = 1; i <= n; i++){
					        for(int j = 1; j <= m; j++)
					            printf("%d ", a[i][j]);
					        cout<<endl;
					    }

					    return 0;
					}
				4. 复杂度
		5. 双指针算法
			1. AcWing 799. 最长连续不重复子序列
				1. 网址
				2. 代码{解析}
					#include <iostream>
					#include <string.h> //包括strlen()
					using namespace std;

					int two_pointer_example(){
					    char str[1000];
					    cin.getline(str, 100);

					    int n = strlen(str);

					    for(int i = 0; i < n; i++){

					        int j = i; //i的语意是: 指向一个单词的第一个字母
					        while( j < n && str[j] != ' ') j++;

					        //到此时: j指向的是单词之间的空格
					        for(int k = i; i < j; k++) cout<<str[k];
					        cout<<endl;

					        i = j; //注意,因为后面有i++, 所以这里直接i = j就好
					    }

					    return 0;
					}

					const int N = 100010;
					int a[N];
					int b[N];

					int main(){

					    int n;
					    scanf("%d", &n);

					    for(int i = 0; i < n ;i ++) scanf("%d", &a[i]);

					    int res = 0;
					    for(int i = 0, j = 0; i < n; i ++){
					        b[a[i]]++; //b[]的含义: 在[j,i]闭区间里面,元素xx的个数

					        while( j < i && b[a[i]] >= 2) b[a[j++]]--; //可以去掉 j < i, 因为j == i的时候, b[a[i]] == 1, 当满足b[a[i]] >= 2的时候,一定存在j < i. 后面b[a[j++]--的语意: 将j指向的元素移除出去,然后j++

					        res = max(res, i - j + 1);
					    }

					    cout<<res<<endl;
					    return 0;
					}
				3. 纯代码
					#include <iostream>
					#include <string.h> 
					using namespace std;

					int two_pointer_example(){
					    char str[1000];
					    cin.getline(str, 100);

					    int n = strlen(str);

					    for(int i = 0; i < n; i++){

					        int j = i;
					        while( j < n && str[j] != ' ') j++;

					        for(int k = i; i < j; k++) cout<<str[k];
					        cout<<endl;

					        i = j;
					    }

					    return 0;
					}

					const int N = 100010;
					int a[N];
					int b[N];

					int main(){

					    int n;
					    scanf("%d", &n);

					    for(int i = 0; i < n ;i ++) scanf("%d", &a[i]);

					    int res = 0;
					    for(int i = 0, j = 0; i < n; i ++){
					        b[a[i]]++; 

					        while( j < i && b[a[i]] >= 2) b[a[j++]]--;

					        res = max(res, i - j + 1);
					    }

					    cout<<res<<endl;
					    return 0;
					}
				4. 复杂度
			2. AcWing 800. 数组元素的目标和
				1. 网址
				2. 代码{解析}
					#include <iostream>
					using namespace std;

					const int N = 100010;
					int a[N];
					int b[N];

					int main(){
					    int n,m,v;
					    scanf("%d%d%d", &n, &m, &v);

					    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
					    for(int i = 0; i < m; i++) scanf("%d", &b[i]);

					    for(int i = 0, j = m-1; i < n; i++){ //作用: 初始化i,j. 并且是指导i向右走
					        while(j >= 0 && a[i] + b[j] > v) j--; //指导j向左走
					        //此时一定有a[i] + b[j] <= v;
					        //出来的时候, 可能 j == -1

					        if(j >= 0 && a[i] + b[j] == v) {  //题目保证: 有唯一解
					            printf("%d %d\n", i, j );
					            break;
					        }
					    }

					    return 0;
					}
				3. 纯代码
					#include <iostream>
					using namespace std;

					const int N = 100010;
					int a[N];
					int b[N];

					int main(){
					    int n,m,v;
					    scanf("%d%d%d", &n, &m, &v);

					    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
					    for(int i = 0; i < m; i++) scanf("%d", &b[i]);

					    for(int i = 0, j = m-1; i < n; i++){ 
					        while(j >= 0 && a[i] + b[j] > v) j--; 

					        if(j >= 0 && a[i] + b[j] == v) { 
					            printf("%d %d\n", i, j );
					            break;
					        }
					    }

					    return 0;
					}
				4. 复杂度
			3. AcWing 2816. 判断子序列
				1. 网址
				2. 代码{解析}
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 100010;

					int n, m;
					int a[N], b[N];

					int main()
					{
					    scanf("%d%d", &n, &m);
					    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
					    for (int i = 0; i < m; i ++ ) scanf("%d", &b[i]);

					    int i = 0, j = 0;
					    while (i < n && j < m)
					    {
					        if (a[i] == b[j]) i ++ ; 匹配成功, 好的, 看下一题{a[i]}
					        j ++ ; 匹配失败, 看下一次尝试{b[j]}
					    }

					    if (i == n) puts("Yes");
					    else puts("No");

					    return 0;
					}
				3. 纯代码
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 100010;

					int n, m;
					int a[N], b[N];

					int main()
					{
					    scanf("%d%d", &n, &m);
					    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
					    for (int i = 0; i < m; i ++ ) scanf("%d", &b[i]);

					    int i = 0, j = 0;
					    while (i < n && j < m)
					    {
					        if (a[i] == b[j]) i ++ ; 
					        j ++ ; 
					    }

					    if (i == n) puts("Yes");
					    else puts("No");

					    return 0;
					}
				4. 复杂度
		6. 位运算
			1. AcWing 801. 二进制中1的个数
				1. 网址
				2. 代码{解析}
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
				3. 纯代码
					#include <iostream>
					using namespace std;

					//打印补码
					void test(){
					    int x = 10;
					    unsigned int a = -x;

					    for(int i = 31; i >= 0; i--) cout << (a >> i & 1);

					    return;
					}

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
				4. 复杂度
		7. 离散化
			1. AcWing 802. 区间和
				1. 网址
				2. 代码{解析}
					//因为可能需要输入n次样本, 测试m个区间(左右2个)
					#include <iostream>
					#include <vector>
					#include <algorithm> //sort()
					using namespace std;

					typedef pair<int,int> PII;

					const int N = 3 * 100000 + 10;
					int a[N]; //相当于pdf
					int S[N]; //相当于cdf

					//因为find()会用到all当做全局变量
					vector<int> all; //包括了从add和query的所有索引

					int find(int x){
					    int l = 0, r = all.size()-1;


					    while(l < r){
					        int mid = (r-l)/2 + l;
					        if(all[mid] >= x) r = mid; 解析:
					        	这里是 if(true) r = mid; 相当于找 [l, mid]也就是往左找, 并且保留mid
					        	如果说中间的值 all[mid] 是大于我们的 target后, 就要往左找
					        	说明 target在左边, 且我们找的是 >= target的起始位置
					        else l = mid + 1;
					    }

					    return l + 1;//因为前缀和一般都是1开始处理
					}


					别背这个, 感觉有问题...
					// vector<int>::iterator unique(vector<int> &a)
					// {
					//     int j = 0;//指向非重数组的下一位
					//     for(int i = 0; i < (int)a.size();) 
					//     {
					//         if(i == 0) a[j++] = a[i]; //数组的第一位一定是满足条件的
					//         while(j <= i && a[j-1] != a[i]) a[j++] = a[i++];  //因为是递增的,所以一旦不等于,就说明不是重复
					//     }
					//     return a.begin() + j;
					// }

					背这个: 
					vector<int>::iterator unique_from_yxc(vector<int> &a)
					{
					    int j = 0;
					    for (int i = 0; i < a.size(); i ++ )
					        if (!i || a[i] != a[i - 1]) 因为是单增的, 所以只要不等于, 就说明不是重复元素
					            a[j ++ ] = a[i];
					    // a[0] ~ a[j - 1] 所有a中不重复的数

					    return a.begin() + j;
					}

					int main(){
					    int n, m;
					    cin >> n >> m;

					    vector<PII> add;
					    vector<PII> query;


					    for(int i = 0; i < n; i ++) 
					    {
					        int ind, v;
					        cin >> ind >> v;

					        all.push_back(ind);
					        add.push_back({ind, v});
					    }

					    for(int i = 0; i < m; i++){
					        int l, r;
					        cin >> l >> r;

					        all.push_back(l);
					        all.push_back(r);
					        query.push_back({l,r});
					    }

					    //将所有的索引,去重
					    sort(all.begin(), all.end()); //unique()需要一个递增的数组
					    all.erase(unique(all.begin(), all.end()), all.end()); -> 这个是调用 cpp自己的unique函数
					    //all.erase(unique(all), all.end()); 这个是调用我们自己写的unique函数. //unique()返回的是没有重复元素的数组的下一个元素的位置. 从这个位置开始,到末尾,都是重复元素被放置的地方. 这部分给erase()删除

					    //为所有要实现加法运算的索引,找到压缩后的索引,并加入a数组中
					    for(auto item : add){
					        int cind = find(item.first); //cind是从1开始的
					        a[cind] += item.second;
					    }

					    //将a数组累加
					    for(int i = 1; i <= all.size(); i++) S[i] = S[i-1] + a[i]; //bug, 注意是 <= all.size(), 而不是 <= n, 因为是求出全部的cdf,cdf的有的地方是一条水平直线

					    //为所有要找的l,r找到压缩后的index,并求出要找的区间和
					    for(auto item : query){
					        int cl = find(item.first), cr = find(item.second);
					        cout << S[cr] - S[cl - 1] << endl;
					    }

					    return 0;
					}
				3. 纯代码
					//因为可能需要输入n次样本, 测试m个区间(左右2个)
					#include <iostream>
					#include <vector>
					#include <algorithm> //sort()
					using namespace std;

					typedef pair<int,int> PII;

					const int N = 3 * 100000 + 10;
					int a[N]; //相当于pdf
					int S[N]; //相当于cdf

					
					vector<int> all; //包括了从add和query的所有索引

					int find(int x){
					    int l = 0, r = all.size()-1;


					    while(l < r){
					        int mid = (r-l)/2 + l;
					        if(all[mid] >= x) r = mid; 
					        else l = mid + 1;
					    }

					    return l + 1;
					}

					背这个: 
					vector<int>::iterator unique_from_yxc(vector<int> &a)
					{
					    int j = 0;
					    for (int i = 0; i < a.size(); i ++ )
					        if (!i || a[i] != a[i - 1])
					            a[j ++ ] = a[i];

					    return a.begin() + j;
					}

					int main(){
					    int n, m;
					    cin >> n >> m;

					    vector<PII> add;
					    vector<PII> query;


					    for(int i = 0; i < n; i ++) 
					    {
					        int ind, v;
					        cin >> ind >> v;

					        all.push_back(ind);
					        add.push_back({ind, v});
					    }

					    for(int i = 0; i < m; i++){
					        int l, r;
					        cin >> l >> r;

					        all.push_back(l);
					        all.push_back(r);
					        query.push_back({l,r});
					    }

					    //将所有的索引,去重
					    sort(all.begin(), all.end()); 
					    all.erase(unique(all.begin(), all.end()), all.end()); 

					    for(auto item : add){
					        int cind = find(item.first); 
					        a[cind] += item.second;
					    }

					    //将a数组累加
					    for(int i = 1; i <= all.size(); i++) S[i] = S[i-1] + a[i]; 

					    for(auto item : query){
					        int cl = find(item.first), cr = find(item.second);
					        cout << S[cr] - S[cl - 1] << endl;
					    }

					    return 0;
					}
				4. 复杂度
		8. 区间合并
			1. AcWing 803. 区间合并
				1. 网址
				2. 代码{解析}
					#include <iostream>
					#include <algorithm>

					using namespace std;

					typedef pair<int, int> PII;

					int main(){
					    int n;
					    scanf("%d",&n);

					    vector<PII> vec;
					    for(int i = 0; i < n; i ++){
					        int l, r;
					        cin >> l >> r;
					        vec.push_back({l,r});
					    }

					    sort(vec.begin(), vec.end()); //sort()默认是按照item的第一个元素来排序.所以是按照左侧端点l排序

					    int s = -2e9; //只要< -1e9就可以
					    int e = -2e9;

					    int res = 0;
					    for(auto item : vec){
					        if(item.first <= e) { //说明上一个[s,e]的end可以被延长
					            e = max(e, item.second); //小心,是item.second不是item.first
					        }
					        else //说明遇到一个新的[s,e]. 所以之前找到的[s,e]可以被加入答案数组中
					        {
					            if(s != -2e9) res ++; //之前找到的[s,e]可以被加入答案数组中. 但是主要要刨除s,t是初始值的情况
					            s = item.first;
					            e = item.second;
					        }
					    }

					    //将最后一组[r,l]加入答案. 不过要判断s,t是不是初始值
					    if(s != -2e9) res ++;
					    cout<<res<<endl;

					    return 0;
					}
				3. 纯代码
					#include <iostream>
					#include <algorithm>

					using namespace std;

					typedef pair<int, int> PII;

					int main(){
					    int n;
					    scanf("%d",&n);

					    vector<PII> vec;
					    for(int i = 0; i < n; i ++){
					        int l, r;
					        cin >> l >> r;
					        vec.push_back({l,r});
					    }

					    sort(vec.begin(), vec.end());

					    int s = -2e9;
					    int e = -2e9;

					    int res = 0;
					    for(auto item : vec){
					        if(item.first <= e) {
					            e = max(e, item.second); 
					        }
					        else
					        {
					            if(s != -2e9) res ++; //之前找到的[s,e]可以被加入答案数组中. 但是主要要刨除s,t是初始值的情况
					            s = item.first;
					            e = item.second;
					        }
					    }

					    //将最后一组[r,l]加入答案. 不过要判断s,t是不是初始值
					    if(s != -2e9) res ++;
					    cout<<res<<endl;

					    return 0;
					}
				4. 复杂度
	2. 数据结构
		1. 单链表
			1. AcWing 826. 单链表
				1. 网址
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					const int N = 100010;


					// head 表示头结点的下标
					// e[i] 表示节点i的值
					// ne[i] 表示节点i的next指针是多少
					// idx 存储当前已经用到了哪个点
					int head, e[N], ne[N], idx;

					// 初始化
					void init()
					{
					    head = -1;
					    idx = 0;
					}

					// 将x插到头结点
					void add_to_head(int x)
					{
					    e[idx] = x, ne[idx] = head, head = idx ++ ;
					}

					// 将x插到下标是k的点后面
					void add(int k, int x)
					{
					    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++ ;
					}

					// 将下标是k的点后面的点删掉
					void remove(int k)
					{
					    ne[k] = ne[ne[k]];
					}

					int main()
					{
					    int m;
					    cin >> m;

					    init();

					    while (m -- )
					    {
					        int k, x;
					        char op;

					        cin >> op;
					        if (op == 'H')
					        {
					            cin >> x;
					            add_to_head(x);
					        }
					        else if (op == 'D')
					        {
					            cin >> k;
					            if (!k) head = ne[head];
					            else remove(k - 1);
					        }
					        else
					        {
					            cin >> k >> x;
					            add(k - 1, x);
					        }
					    }

					    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
					    cout << endl;

					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int head, e[N], ne[N], idx;

					// 初始化
					void init()
					{
					    head = -1;
					    idx = 0;
					}

					// 将x插到头结点
					void add_to_head(int x)
					{
					    e[idx] = x, ne[idx] = head, head = idx ++ ;
					}

					// 将x插到下标是k的点后面
					void add(int k, int x)
					{
					    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++ ;
					}

					// 将下标是k的点后面的点删掉
					void remove(int k)
					{
					    ne[k] = ne[ne[k]];
					}

					int main()
					{
					    int m;
					    cin >> m;

					    init();

					    while (m -- )
					    {
					        int k, x;
					        char op;

					        cin >> op;
					        if (op == 'H')
					        {
					            cin >> x;
					            add_to_head(x);
					        }
					        else if (op == 'D')
					        {
					            cin >> k;
					            if (!k) head = ne[head];
					            else remove(k - 1);
					        }
					        else
					        {
					            cin >> k >> x;
					            add(k - 1, x);
					        }
					    }

					    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
					    cout << endl;

					    return 0;
					}
				4. 复杂度
		2. 双链表
			1. AcWing 827. 双链表
				1. 网址
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int m;
					int e[N], l[N], r[N], idx;

					// 在节点a的右边插入一个数x
					void insert(int a, int x)
					{
					    e[idx] = x; 先给值 
					    l[idx] = a, r[idx] = r[a]; 我idx的左边, 是a. 我idx的右边, 是a的右边 
					    l[r[a]] = idx, r[a] = idx ++ ; a的原先的右边的左边, 改为我idx. a的右边, 改为我idx. 最后idx ++.
					}

					// 删除节点a
					void remove(int a)
					{
					    l[r[a]] = l[a]; 让我a右边的左边, 直接等于我a的左边. 这样我a就可以脱离了
					    r[l[a]] = r[a]; 让我a左边的右边, 直接等于我a的右边. 这样我a就可以脱离了
					    	如果写成结构体, 就很冗长:
					    		nodes[nodes[k].l].r = nodes[k].r 
					    		r[l[k]] = r[k]
					}

					int main()
					{
					    cin >> m;

					    // 0是左端点{head}，1是右端点{tail}
					    r[0] = 1, l[1] = 0; 0号点的右边是1号点, 1号点的左边是0号点
					    idx = 2; 因为01已经被占用了 

					    while (m -- )
					    {
					        string op;
					        cin >> op;
					        int k, x;
					        if (op == "L") 在左端点 head 的右边插入一个数字 x
					        		从原来的 0 -> 1
					        		变为: 0 -> x -> 1
					        			我们认为x是head, 而0是head前面的一个士兵
					        {
					            cin >> x;
					            insert(0, x); 在左端点的右边插入一个数字 x
					        }
					        else if (op == "R") 在右端点 tail 插入一个数字 x
					        		从原来的 0 -> a ->  1
					        		变为: 0 -> a -> x -> 1
					        			我们认为x是tail, 而1是tail后面的一个士兵
					        {
					            cin >> x;
					            insert(l[1], x);	在右端点的左侧{l[1], 也就是a}, 的右边插入一个数字 x
					        }
					        else if (op == "D") 表示将第 k 个插入的数删除。
					        {
					            cin >> k;
					            remove(k + 1); 我的理解: 假设k==1, 也就是将第1个插入的数字删除, 因为我们分配 idx是从2开始的, 所以 k+1
					        }
					        else if (op == "IL") 表示在第 k 个插入的数左侧插入一个数。
					        {
					            cin >> k >> x;
					            insert(l[k + 1], x); 首先, k+1上面解释过了{因为index从2开始}, 其次, 这里说第 k 个插入的数左侧插入, 但是我们的insert只能往右侧插入, 所以也就是从 第 k 个插入的数左侧{l[k+1]}的右侧插入
					        }
					        else 表示在第 k 个插入的数右侧插入一个数。
					        {
					            cin >> k >> x;
					            insert(k + 1, x);
					        }
					    }

					    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
					    		注意, 0和1都是我们的哨兵, 是不能打印出来的
					    		第一个要打印的是 r[0], 最后一个是l[1]. 
					    cout << endl;

					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int m;
					int e[N], l[N], r[N], idx;

					// 在节点a的右边插入一个数x
					void insert(int a, int x)
					{
					    e[idx] = x; 
					    l[idx] = a, r[idx] = r[a];
					    l[r[a]] = idx, r[a] = idx ++ ;
					}

					// 删除节点a
					void remove(int a)
					{
					    l[r[a]] = l[a]; 
					    r[l[a]] = r[a]; 
					}

					int main()
					{
					    cin >> m;

					    r[0] = 1, l[1] = 0; 
					    idx = 2; 

					    while (m -- )
					    {
					        string op;
					        cin >> op;
					        int k, x;
					        if (op == "L") 
					        {
					            cin >> x;
					            insert(0, x);
					        }
					        else if (op == "R")
					        {
					            cin >> x;
					            insert(l[1], x);	
					        }
					        else if (op == "D") 
					        {
					            cin >> k;
					            remove(k + 1); 
					        }
					        else if (op == "IL") 
					        {
					            cin >> k >> x;
					            insert(l[k + 1], x);
					        }
					        else 表示在第 k 个插入的数右侧插入一个数。
					        {
					            cin >> k >> x;
					            insert(k + 1, x);
					        }
					    }

					    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
					    cout << endl;

					    return 0;
					}
				4. 复杂度
		3. 栈
			1. AcWing 828. 模拟栈
				1. 网址
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int m;
					int stk[N], tt;

					int main()
					{
					    cin >> m;
					    while (m -- )
					    {
					        string op;
					        int x;

					        cin >> op;
					        if (op == "push")
					        {
					            cin >> x;
					            stk[ ++ tt] = x;
					        }
					        else if (op == "pop") tt -- ;
					        else if (op == "empty") cout << (tt ? "NO" : "YES") << endl;
					        else cout << stk[tt] << endl;
					    }

					    return 0;
					}

					老师的做法:
						tt默认为0，且stk[0]是不用来存放元素的，stk[1] 用来存放压入栈的第一个元素
						因此用tt是否等于0来判断栈是否为空；
					另一种做法:
						tt 初始化为-1，然后stk[0]用来存放第一个压入栈的元素
						根据tt是否为-1来判断栈是否为空；
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int m;
					int stk[N], tt;

					int main()
					{
					    cin >> m;
					    while (m -- )
					    {
					        string op;
					        int x;

					        cin >> op;
					        if (op == "push")
					        {
					            cin >> x;
					            stk[ ++ tt] = x;
					        }
					        else if (op == "pop") tt -- ;
					        else if (op == "empty") cout << (tt ? "NO" : "YES") << endl;
					        else cout << stk[tt] << endl;
					    }

					    return 0;
					}
				4. 复杂度
			2. AcWing 3302. 表达式求值
				1. 网址
				2. 代码{解析}
					解释:
						https://www.acwing.com/solution/content/40978/

					#include <iostream>
					#include <cstring>
					#include <algorithm>
					#include <stack>
					#include <unordered_map> 哈希表, 存优先级 

					using namespace std;

					stack<int> num; 存数字
					stack<char> op; 存运算符

					void eval() 用栈顶的运算符, 计算栈顶的两个数字
					{
					    auto b = num.top(); num.pop();
					    auto a = num.top(); num.pop();
					    auto c = op.top(); op.pop();
					    int x;
					    if (c == '+') x = a + b;
					    else if (c == '-') x = a - b;
					    else if (c == '*') x = a * b;
					    else x = a / b;
					    num.push(x);
					}

					int main()
					{
					    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}}; 注明优先级, 数字越高, 优先级越大
					    string str;
					    cin >> str;
					    for (int i = 0; i < str.size(); i ++ ) 从前往后遍历每一个字符 
					    {
					        auto c = str[i];
					        if (isdigit(c))
					        {
					            int x = 0, j = i; 从i开始 
					            while (j < str.size() && isdigit(str[j])) 把数字抠出来
					                x = x * 10 + str[j ++ ] - '0';
					            i = j - 1; 因为for里面有 i++, 所以这里先回退一个
					            num.push(x);
					        }
					        else if (c == '(') op.push(c); 将运算符'('加入栈
					        else if (c == ')')
					        {
					            while (op.top() != '(') eval(); 将栈里面的运算符都处理一遍, 一直处理到遇到了 '('
					            op.pop();
					        }
					        else
					        {
					            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c]) eval(); 
					            	如果不为空, 并且最顶的优先级 >= 我们遇到的c, 就开始算
					            	如果 并且最顶是 '(', 就直接 push(c), 也就是说, 最顶不是 '(', 就可以判断 最顶的优先级 比大小 我们遇到的c
					            op.push(c); 算完之后, 插入c. 或者直接插入c
					        }
					    }
					    while (op.size()) eval(); 最后的再算完
					    cout << num.top() << endl;
					    return 0;
					}
				3. 纯代码

					#include <iostream>
					#include <cstring>
					#include <algorithm>
					#include <stack>
					#include <unordered_map> 哈希表, 存优先级 

					using namespace std;

					stack<int> num; 
					stack<char> op; 

					void eval() 
					{
					    auto b = num.top(); num.pop();
					    auto a = num.top(); num.pop();
					    auto c = op.top(); op.pop();
					    int x;
					    if (c == '+') x = a + b;
					    else if (c == '-') x = a - b;
					    else if (c == '*') x = a * b;
					    else x = a / b;
					    num.push(x);
					}

					int main()
					{
					    unordered_map<char, int> pr{{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
					    string str;
					    cin >> str;
					    for (int i = 0; i < str.size(); i ++ )
					    {
					        auto c = str[i];
					        if (isdigit(c))
					        {
					            int x = 0, j = i;
					            while (j < str.size() && isdigit(str[j])) 
					                x = x * 10 + str[j ++ ] - '0';
					            i = j - 1;
					            num.push(x);
					        }
					        else if (c == '(') op.push(c);
					        else if (c == ')')
					        {
					            while (op.top() != '(') eval();
					            op.pop();
					        }
					        else
					        {
					            while (op.size() && op.top() != '(' && pr[op.top()] >= pr[c]) eval(); 
					            op.push(c);
					        }
					    }
					    while (op.size()) eval(); 
					    cout << num.top() << endl;
					    return 0;
					}
				4. 复杂度
		4. 队列
			1. AcWing 829. 模拟队列
				1. 网址
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int m;
					int q[N], hh, tt = -1; 注意, 这里的hh是0, tt是-1

					int main()
					{
					    cin >> m;

					    while (m -- )
					    {
					        string op;
					        int x;

					        cin >> op;
					        if (op == "push")
					        {
					            cin >> x;
					            q[ ++ tt] = x; tt: 指向队尾的元素{是真的指着, 而不是指向它的下一个}
					        }
					        else if (op == "pop") hh ++ ; hh: 指向队首的元素. {所以如果 hh,tt 代表: [hh,tt]有元素. 初始化的时候是[hh=0,tt=-1]有元素, 也就是没有元素. 
					        		如果变为[hh=0,tt=0]有元素, 那就是0这个位置有元素,
					        		如果变为[hh=1,tt=0]有元素, 也就是没有元素}
					        else if (op == "empty") cout << (hh <= tt ? "NO" : "YES") << endl;
					        else cout << q[hh] << endl;
					    }

					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int m;
					int q[N], hh, tt = -1; 

					int main()
					{
					    cin >> m;

					    while (m -- )
					    {
					        string op;
					        int x;

					        cin >> op;
					        if (op == "push")
					        {
					            cin >> x;
					            q[ ++ tt] = x; tt: 
					        }
					        else if (op == "pop") hh ++ ;
					        else if (op == "empty") cout << (hh <= tt ? "NO" : "YES") << endl;
					        else cout << q[hh] << endl;
					    }

					    return 0;
					}
				4. 复杂度
		5. 单调栈
			1. AcWing 830. 单调栈
				1. 网址
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int stk[N], tt;

					int main()
					{
					    int n;
					    cin >> n;
					    while (n -- )
					    {
					        int x;
					        scanf("%d", &x);
					        while (tt 如果栈不为空 && stk[tt] >= x 且栈顶元素大于我们当前遍历到的x) tt -- ; 既然大于了, 就说明栈顶元素不会被用到了, 直接删除
					        if (!tt) printf("-1 "); 如果栈此时为空, 说明栈里面的都大于x, 就输出-1
					        else printf("%d ", stk[tt]); 如果此时栈里面还有元素, 说明他肯定比x小
					        stk[ ++ tt] = x; 此时把x加入栈顶. 
					        					之后如果遇到一个比x小的数b, 我们还会把x给删除掉, 一直到找到一个合适的. 
					        					如果遇到的比x大的c, 我们输出的就是x. 因为这个x是离c最近的比c小的数
					    }

					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int stk[N], tt;

					int main()
					{
					    int n;
					    cin >> n;
					    while (n -- )
					    {
					        int x;
					        scanf("%d", &x);
					        while (tt && stk[tt] >= x ) tt -- ; 
					        if (!tt) printf("-1 "); 
					        else printf("%d ", stk[tt]);
					        stk[ ++ tt] = x; 
					    }

					    return 0;
					}
				4. 复杂度
		6. 单调队列
			1. AcWing 154. 滑动窗口
				1. 网址
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					const int N = 1000010;

					int a[N], q[N]; a: 题目的输入, q: 我们的单调队列
						注意我们的q存的是下标. 

					int main()
					{
					    int n, k;
					    scanf("%d%d", &n, &k); 因为输入量有很多, 用scanf 
					    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

					    int hh = 0, tt = -1; 定义 [hh=0, tt=-1]
					    for (int i = 0; i < n; i ++ )
					    {
					        if (hh <= tt && q[hh] < i - k + 1) hh ++ ; 
					        	hh <= tt 如果队列不为空 
					        	且当前窗口的终点是i, 起点是{i - k + 1}. 
					        		解释: 很简单, 窗口的长度是 k, 终点是i, 那么起点是 i - k + 1. 所以窗口是: [i-k+1, i] : 长度刚好是: i-(i-k+1)+1 = k
					        		就像是, 我的终点是i, 长度是1的话, 其实起点是 i - 1 + 1. 也就是起点是i, 也就是[i,i], 也就是我一个值{长度为1嘛}
					         	q[hh] < i - k + 1:
					         		也就是q队列的队首, 存的index的值 < 窗口起点的index. 说明要把队首去掉: hh++
					         	不用while, 而是用if. 因为我们是for, 每次窗口只是移动一位

					        while (hh <= tt && a[q[tt]] >= a[i]) tt -- ;
					        	只要还有元素, 且左边的点a[q[tt]] 凡是大于等于我这个新点a[i]的, 就都是逆序对{左大右小}, 我们要把逆序对都删掉, 剩下的元素都是严格单增的
					        		因为题目求得是窗口最小, 所以最小值就是单增数组的第一个元素, q[hh]
					        	之所以是大于等于{有个等于} 是因为, 左侧的值如果等于我, 可是左边的值因为在左边, 所以先会被窗口剔除


					        	单调栈/队列的总结:
					        		1. 暴力做
					        		2. 然后看哪些是不需要的元素
					        			就像是我脑海里的图, 新来的元素a, 可以和x4,x5组成逆序对, 所以x4,x5都不用要了
					        			|			   x5
					        			|			x4
					        			|		 -------- a
					        			|        x3        
					        			|	  x2
					        			|  x1 
					        			|
					        			------------------
					        		3. 剩下的元素, 是具有单调性的{这里是单调上升}
					        			如果题目要求最大, 那就是a
					        			如果题目要求最小, 那就是x1
					        			我们还可以二分求其他的, 因为这是具有单调性的


					        q[ ++ tt] = i; 注意, 这一句要写在 if (i >= k - 1)之前, 因为i可能是最小值. 如果写在 if (i >= k - 1) 之后, 就是y总的bug了

					        if (i >= k - 1) printf("%d ", a[q[hh]]); 当窗口>=k的时候才开始打印. 也就是遍历到了 index == k-1
					    }

					    puts("");

					    hh = 0, tt = -1;
					    for (int i = 0; i < n; i ++ )
					    {
					        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;

					        while (hh <= tt && a[q[tt]] <= a[i]) tt -- ;
					        q[ ++ tt] = i;

					        if (i >= k - 1) printf("%d ", a[q[hh]]);
					    }

					    puts("");

					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 1000010;

					int a[N], q[N]; 

					int main()
					{
					    int n, k;
					    scanf("%d%d", &n, &k); 
					    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

					    int hh = 0, tt = -1; 
					    for (int i = 0; i < n; i ++ )
					    {
					        if (hh <= tt && q[hh] < i - k + 1) hh ++ ; 
					        	
					        while (hh <= tt && a[q[tt]] >= a[i]) tt -- ;

					        q[ ++ tt] = i; 

					        if (i >= k - 1) printf("%d ", a[q[hh]]); 
					    }

					    puts("");

					    hh = 0, tt = -1;
					    for (int i = 0; i < n; i ++ )
					    {
					        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;

					        while (hh <= tt && a[q[tt]] <= a[i]) tt -- ;
					        q[ ++ tt] = i;

					        if (i >= k - 1) printf("%d ", a[q[hh]]);
					    }

					    puts("");

					    return 0;
					}
				4. 复杂度
		7. KMP
			1. AcWing 831. KMP字符串 todo
				1. 网址
				2. 代码{解析}
					#include <iostream>
					using namespace std;

					const int N = 100010;
					const int M = 1000010;

					int n, m;
					char p[N];
					char s[M];
					int ne[N]; //注意不要用next,可能会重名


					int main(){
					    cin >> n >> (p + 1) >> m >> (s + 1); //意思是:abc存入p的index=1,2,3的位置, 记得加上括号

					    for(int i = 2, j = 0; i <= n ; i++){ //p的第二个字符和p的第一个字符比较
					        while(j && p[i] != p[j+1]) j = ne[j]; //不满足, 跳回到之前模式一样的地方
					        if(p[i] == p[j+1]) j++; //满足,继续
					        ne[i] = j;
					    }

					    for(int i = 1, j = 0; i <= m; i++){ //是s的第一个字符和p的第一个字符比较
					        while(j && s[i] != p[j+1]) j = ne[j];
					        if(s[i] == p[j+1]) j++;
					        if( j == n){
					            cout<< i - n + 1 - 1 <<" "; //注意是 i - n + 1 - 1. 因为index = i-n+1, 但是是从index==1开始的所以要-1
					            j = ne[j]; //跳回到之前模式一样的地方
					        }
					    }

					    return 0;

					}
				3. 纯代码
					#include <iostream>
					using namespace std;

					const int N = 100010;
					const int M = 1000010;

					int n, m;
					char p[N];
					char s[M];
					int ne[N]; 


					int main(){
					    cin >> n >> (p + 1) >> m >> (s + 1); 

					    for(int i = 2, j = 0; i <= n ; i++){ 
					        while(j && p[i] != p[j+1]) j = ne[j]; 
					        if(p[i] == p[j+1]) j++;
					        ne[i] = j;
					    }

					    for(int i = 1, j = 0; i <= m; i++){ 
					        while(j && s[i] != p[j+1]) j = ne[j];
					        if(s[i] == p[j+1]) j++;
					        if( j == n){
					            cout<< i - n + 1 - 1 <<" "; 
					            j = ne[j]; 
					        }
					    }

					    return 0;

					}
				4. 复杂度
		8. Trie
			1. AcWing 835. Trie字符串统计
				1. 网址
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int son[N][26] {存trie的每个点的所有儿子}, cnt[N]{以当前节点结尾的点有多少个}, idx{当前用到的token, 就是和单链表里面的一样}; 因为只包含小写字母, 所以开26个
					idx == 0, 既是根节点, 又是空节点. 如果一个点没有子节点, 也会让这个点指向0
					char str[N];

					存储{插入}一个字符串
					void insert(char *str)
					{
					    int p = 0; 从根节点开始
					    for (int i = 0; str[i] 因为字符串结尾是\0, 所以这里可以这么写成 str[i] ; i ++ ) 遍历字符串, 从头开始遍历
					    {
					        int u = str[i] - 'a';
					        if (!son[p][u]) son[p][u] = ++ idx; 如果节点p的儿子u不存在的话, 我们就创建这个儿子u, 用 ++idx; 
					        p = son[p][u]; 走向儿子的点 
					    }
					    cnt[p] ++ ; 以这个点p结尾的单词的个数增加了
					}

					int query(char *str)
					{
					    int p = 0;
					    for (int i = 0; str[i]; i ++ )
					    {
					        int u = str[i] - 'a';
					        if (!son[p][u]) return 0; 如果没有儿子, 说明就没有这个单词
					        p = son[p][u]; 说明有这个单词 
					    }
					    return cnt[p]; 单词个数
					}

					int main()
					{
					    int n;
					    scanf("%d", &n);
					    while (n -- )
					    {
					        char op[2];
					        scanf("%s%s", op, str); 操作类型 + 字符串
					        if (*op == 'I') insert(str);
					        else printf("%d\n", query(str));
					    }

					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int son[N][26], cnt[N], idx;
					char str[N];

					存储{插入}一个字符串
					void insert(char *str)
					{
					    int p = 0; 
					    for (int i = 0; str[i]; i ++ )
					    {
					        int u = str[i] - 'a';
					        if (!son[p][u]) son[p][u] = ++ idx; 
					        p = son[p][u]; 
					    }
					    cnt[p] ++ ; 
					}

					int query(char *str)
					{
					    int p = 0;
					    for (int i = 0; str[i]; i ++ )
					    {
					        int u = str[i] - 'a';
					        if (!son[p][u]) return 0;
					        p = son[p][u]; 
					    }
					    return cnt[p];
					}

					int main()
					{
					    int n;
					    scanf("%d", &n);
					    while (n -- )
					    {
					        char op[2];
					        scanf("%s%s", op, str); 
					        if (*op == 'I') insert(str);
					        else printf("%d\n", query(str));
					    }

					    return 0;
					}
				4. 复杂度
			2. AcWing 143. 最大异或对
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		9. 并查集
			1. AcWing 836. 合并集合
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 837. 连通块中点的数量
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 240. 食物链
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		10. 堆
			1. AcWing 838. 堆排序
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 839. 模拟堆
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		11. 哈希表
			1. AcWing 840. 模拟散列表
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 841. 字符串哈希
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
	3. 搜索和图论
		1. DFS
			1. AcWing 842. 排列数字
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 843. n-皇后问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. BFS
			1. AcWing 844. 走迷宫
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 845. 八数码
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 树与图的深度优先遍历	
			1. AcWing 846. 树的重心
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 树与图的广度优先遍历	
			1. AcWing 847. 图中点的层次
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 拓扑排序
			1. AcWing 848. 有向图的拓扑序列
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. Dijkstra
			1. AcWing 849. Dijkstra求最短路 I
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 850. Dijkstra求最短路 II
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		7. bellman-ford
			1. AcWing 853. 有边数限制的最短路
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		8. spfa
			1. AcWing 851. spfa求最短路
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 852. spfa判断负环
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		9. Floyd
			1. AcWing 854. Floyd求最短路
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		10. Prim
			1. AcWing 858. Prim算法求最小生成树
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		11. Kruskal
			1. AcWing 859. Kruskal算法求最小生成树
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		12. 染色法判定二分图
			1. AcWing 860. 染色法判定二分图
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		13. 匈牙利算法
			1. AcWing 861. 二分图的最大匹配
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
	4. 数学知识 
		1. 质数
			1. AcWing 866. 试除法判定质数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 867. 分解质因数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 868. 筛质数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 约数
			1. AcWing 869. 试除法求约数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 870. 约数个数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 871. 约数之和
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 872. 最大公约数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 欧拉函数
			1. AcWing 873. 欧拉函数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 874. 筛法求欧拉函数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 快速幂
			1. AcWing 875. 快速幂
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 876. 快速幂求逆元
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 扩展欧几里得算法
			1. AcWing 877. 扩展欧几里得算法
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 878. 线性同余方程
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. 中国剩余定理
			1. AcWing 204. 表达整数的奇怪方式
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		7. 高斯消元
			1. AcWing 883. 高斯消元解线性方程组
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 884. 高斯消元解异或线性方程组
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		8. 求组合数
			1. AcWing 885. 求组合数 I
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 886. 求组合数 II
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 887. 求组合数 III
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 888. 求组合数 IV
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			5. AcWing 889. 满足条件的01序列
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		9. 容斥原理
			1. AcWing 890. 能被整除的数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		10. 博弈论
			1. AcWing 891. Nim游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 892. 台阶-Nim游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 893. 集合-Nim游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 894. 拆分-Nim游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
	5. 动态规划 
		1. 背包问题
			1. AcWing 2. 01背包问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 3. 完全背包问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 4. 多重背包问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 5. 多重背包问题 II
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			5. AcWing 9. 分组背包问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 线性DP
			1. AcWing 898. 数字三角形
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 895. 最长上升子序列
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 896. 最长上升子序列 II
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 897. 最长公共子序列
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			5. AcWing 902. 最短编辑距离
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			6. AcWing 899. 编辑距离
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 区间DP
			1. AcWing 282. 石子合并
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 计数类DP
			1. AcWing 900. 整数划分
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 数位统计DP
			1. AcWing 338. 计数问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. 状态压缩DP
			1. AcWing 291. 蒙德里安的梦想
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			1. AcWing 91. 最短Hamilton路径
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		7. 树形DP
			1. AcWing 285. 没有上司的舞会
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		8. 记忆化搜索
			1. AcWing 901. 滑雪
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		1. 贪心 - 区间问题
			1. AcWing 905. 区间选点
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 908. 最大不相交区间数量
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 906. 区间分组
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 907. 区间覆盖
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 贪心 - Huffman树
			1. AcWing 148. 合并果子
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 贪心 - 排序不等式
			1. AcWing 913. 排队打水
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 贪心 - 绝对值不等式
			1. AcWing 104. 货仓选址
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 贪心 - 推公式
			1. AcWing 125. 耍杂技的牛
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
2. 提高
	1. 基础算法 
		1. 位运算
			1. AcWing 90. 64位整数乘法
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 递推与递归
			1. AcWing 95. 费解的开关
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 97. 约数之和
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 98. 分形之城
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 前缀和与差分
			1. AcWing 99. 激光炸弹
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 100. 增减序列
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 二分
			1. AcWing 102. 最佳牛围栏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 113. 特殊排序
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 排序
			1. AcWing 105. 七夕祭
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 106. 动态中位数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 107. 超快速排序
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. RMQ
			AcWing 1273. 天才的记忆
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
	2. 数据结构 
		1. 并查集
			1. AcWing 1250. 格子游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1252. 搭配购买
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 237. 程序自动分析
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 239. 奇偶游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			5. AcWing 238. 银河英雄传说
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 树状数组
			1. AcWing 241. 楼兰图腾
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 242. 一个简单的整数问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 243. 一个简单的整数问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 244. 谜一样的牛
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 线段树
			1. AcWing 1275. 最大数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 245. 你能回答这些问题吗
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 246. 区间最大公约数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 243. 一个简单的整数问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			5. AcWing 247. 亚特兰蒂斯
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			6. AcWing 1277. 维护序列
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 可持久化数据结构
			1. AcWing 256. 最大异或和
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 255. 第K小数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 平衡树
			1. AcWing 253. 普通平衡树
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 265. 营业额统计
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. AC自动机
			1. AcWing 1282. 搜索关键词
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1285. 单词
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
	3. 搜索和图论
		1. 搜索 - Flood Fill
			1. AcWing 1097. 池塘计数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1098. 城堡问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1106. 山峰和山谷
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 搜索 - 最短路模型
			1. AcWing 1076. 迷宫问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 188. 武士风度的牛
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1100. 抓住那头牛
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 搜索 - 多源BFS
			1. AcWing 173. 矩阵距离
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 搜索 - 最小步数模型
			1. AcWing 1107. 魔板
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 搜索 - 双端队列广搜
			1. AcWing 175. 电路维修
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. 搜索 - 双向广搜
			1. AcWing 190. 字串变换
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. 搜索 - A*
			1. AcWing 178. 第K短路
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 179. 八数码
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		7. 搜索 - DFS之连通性模型
			1. AcWing 1112. 迷宫
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1113. 红与黑
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		8. 搜索 - DFS之搜索顺序
			1. AcWing 1116. 马走日
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1117. 单词接龙
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1118. 分成互质组
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		9. 搜索 - DFS之剪枝与优化
			1. AcWing 165. 小猫爬山
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 166. 数独
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 167. 木棒
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 168. 生日蛋糕
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		10. 搜索 - 迭代加深
			1. AcWing 170. 加成序列
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		10. 搜索 - 双向DFS
			1. AcWing 171. 送礼物
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		11. 搜索 - IDA*
			1. AcWing 180. 排书
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 181. 回转游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		1. 图论 - 单源最短路的建图方式
			1. AcWing 1129. 热浪
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1128. 信使
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1127. 香甜的黄油
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 1126. 最小花费
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			5. AcWing 920. 最优乘车
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			6. AcWing 903. 昂贵的聘礼
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 图论 - 单源最短路的综合应用
			1. AcWing 1135. 新年好
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 340. 通信线路
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 342. 道路与航线
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 341. 最优贸易
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 图论 - 单源最短路的扩展应用
			1. AcWing 1137. 选择最佳线路
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1131. 拯救大兵瑞恩
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1134. 最短路计数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 383. 观光
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 图论 - Floyd算法
			1. AcWing 1125. 牛的旅行
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 343. 排序
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 344. 观光之旅
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 345. 牛站
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 图论 - 最小生成树
			1. AcWing 1140. 最短网络
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1141. 局域网
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1142. 繁忙的都市
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 1143. 联络员
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			5. AcWing 1144. 连接格点
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. 图论 - 最小生成树的扩展应用
			1. AcWing 1146. 新的开始
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1145. 北极通讯网络
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 346. 走廊泼水节
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 1148. 秘密的牛奶运输
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		7. 图论 - 负环
			1. AcWing 904. 虫洞
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 361. 观光奶牛
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1165. 单词环
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		8. 图论 - 差分约束
			1. AcWing 1169. 糖果
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 362. 区间
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1170. 排队布局
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 393. 雇佣收银员
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		9. 图论 - 最近公共祖先
			1. AcWing 1172. 祖孙询问
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1171. 距离
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 356. 次小生成树
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4 .AcWing 352. 闇の連鎖
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		10. 图论 - 有向图的强连通分量
			1. AcWing 1174. 受欢迎的牛
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 367. 学校网络
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1175. 最大半连通子图
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 368. 银河
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		11. 图论 - 无向图的双连通分量
			1. AcWing 395. 冗余路径
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1183. 电力
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 396. 矿场搭建
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		12. 图论 - 二分图
			1. AcWing 257. 关押罪犯
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 372. 棋盘覆盖
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 376. 机器任务
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 378. 骑士放置
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			5. AcWing 379. 捉迷藏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		13. 图论 - 欧拉回路和欧拉路径
			1. AcWing 1123. 铲雪车
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1184. 欧拉回路
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1124. 骑马修栅栏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 1185. 单词游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		14. 图论 - 拓扑排序
			1. AcWing 1191. 家谱树
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1192. 奖金
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 164. 可达性统计
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 456. 车站分级
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
	4. 数学知识
		1. 筛质数
			1. AcWing 1292. 哥德巴赫猜想
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1293. 夏洛克和他的女朋友
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 196. 质数距离
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 分解质因数
			1. AcWing 197. 阶乘分解
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 快速幂
			1. AcWing 1289. 序列的第k个数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1290. 越狱
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 约数个数
			1. AcWing 1291. 轻拍牛头
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1294. 樱花
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 198. 反素数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 200. Hankson的趣味题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 欧拉函数
			1. AcWing 201. 可见的点
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 220. 最大公约数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. 同余
			1. AcWing 203. 同余方程
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 222. 青蛙的约会
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 202. 最幸运的数字
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 1298. 曹冲养猪
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		7. 矩阵乘法
			1. AcWing 1303. 斐波那契前 n 项和
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1304. 佳佳的斐波那契
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1305. GT考试
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		8. 组合计数
			1. AcWing 1307. 牡牛和牝牛
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1308. 方程的解
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1309. 车的放置
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			4. AcWing 1310. 数三角形
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			5. AcWing 1312. 序列统计
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			6. AcWing 1315. 网格
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			7. AcWing 1316. 有趣的数列
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		9. 高斯消元
			1. AcWing 207. 球形空间产生器
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 208. 开关问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		10. 容斥原理
			1. AcWing 214. Devu和鲜花
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 215. 破译密码
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		11. 概率与数学期望
			1. AcWing 217. 绿豆蛙的归宿
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 218. 扑克牌	
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		12. 博弈论
			1. AcWing 1319. 移棋子游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			2. AcWing 1321. 取石子
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			3. AcWing 1322. 取石子游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
	5. 动态规划
		1. 数字三角形模型
			AcWing 1015. 摘花生
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1018. 最低通行费
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1027. 方格取数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 275. 传纸条
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 最长上升子序列模型
			AcWing 1017. 怪盗基德的滑翔翼
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1014. 登山
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 482. 合唱队形
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1012. 友好城市
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1016. 最大上升子序列和
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1010. 拦截导弹
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 187. 导弹防御系统
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 272. 最长公共上升子序列
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 背包模型
			AcWing 423. 采药
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1024. 装箱问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1022. 宠物小精灵之收服
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 278. 数字组合
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1023. 买书
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1021. 货币系统
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 532. 货币系统
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 6. 多重背包问题 III
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1019. 庆功会
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 7. 混合背包问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 8. 二维费用的背包问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1020. 潜水员
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1013. 机器分配
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 426. 开心的金明
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 10. 有依赖的背包问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 11. 背包问题求方案数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 12. 背包问题求具体方案
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 734. 能量石
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 487. 金明的预算方案
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 状态机模型
			AcWing 1049. 大盗阿福
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1057. 股票买卖 IV
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1058. 股票买卖 V
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1052. 设计密码
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1053. 修复DNA
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 状态压缩DP
			AcWing 1064. 小国王
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 327. 玉米田
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 292. 炮兵阵地
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 524. 愤怒的小鸟
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 529. 宝藏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. 区间DP
			AcWing 1068. 环形石子合并
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 320. 能量项链
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 479. 加分二叉树
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1069. 凸多边形的划分
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 321. 棋盘分割	
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		7. 树形DP
			AcWing 1072. 树的最长路径
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1073. 树的中心
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1075. 数字转换
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1074. 二叉苹果树
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 323. 战略游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1077. 皇宫看守
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		8. 数位DP
			AcWing 1081. 度的数量
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1082. 数字游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1083. Windy数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1084. 数字游戏 II
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1085. 不要62
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1086. 恨7不成妻
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		9. 单调队列优化DP
			AcWing 135. 最大子序和	
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1087. 修剪草坪
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1088. 旅行问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1089. 烽火传递
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1090. 绿色通道
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1091. 理想的正方形
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		10. 斜率优化DP
			AcWing 300. 任务安排1
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 301. 任务安排2
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 302. 任务安排3
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 303. 运输小猫
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
3. 进阶
	1. 基础算法
		1. 启发式合并
			AcWing 2154. 梦幻布丁
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 3189. Lomsat gelral
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. manacher算法
			AcWing 3188. manacher算法
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 最小表示法
			AcWing 158. 项链
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 构造
			AcWing 516. 神奇的幻方
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2268. 时态同步
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 打表
			AcWing 1412. 邮政货车
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
	2. 数据结构
		Splay
			AcWing 2437. Splay
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 950. 郁闷的出纳员
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1063. 永无乡
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 955. 维护数列
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		树套树
			AcWing 2488. 树套树-简单版
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2476. 树套树
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2306. K大数查询
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		分块之基本思想
			AcWing 243. 一个简单的整数问题2
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		分块之块状链表
			AcWing 947. 文本编辑器
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		莫队之基础莫队
			AcWing 2492. HH的项链
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		莫队之带修改的莫队
			AcWing 2521. 数颜色
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		莫队之回滚莫队
			AcWing 2523. 历史研究
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		莫队之树上莫队
			AcWing 2534. 树上计数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		莫队之二次离线莫队
			AcWing 2535. 二次离线莫队
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		树链剖分
			AcWing 2568. 树链剖分
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 918. 软件包管理器
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		动态树
			AcWing 2539. 动态树
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 999. 魔法森林
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		DLX之精确覆盖问题
			AcWing 1067. 精确覆盖问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 169. 数独
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 956. 智慧珠游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		DLX之重复覆盖问题
			AcWing 2713. 重复覆盖问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 182. 破坏正方形
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2724. 雷达
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		左偏树
			AcWing 2714. 左偏树
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2725. 数字序列
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2721. K-单调
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		后缀数组
			AcWing 2715. 后缀数组
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1004. 品酒大会
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2572. 生成魔咒
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		后缀自动机
			AcWing 2766. 后缀自动机
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1283. 玄武密码
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2811. 最长公共子串
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		点分治
			AcWing 252. 树
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 264. 权值
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		点分树
			AcWing 2226. 开店
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		CDQ分治
			AcWing 2815. 三维偏序
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2847. 老C的任务
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2819. 动态逆序对
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		仙人掌
			AcWing 2863. 最短路
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2752. 仙人掌图
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
	3. 搜索和图论
		1. 搜索 - 模拟退火
			AcWing 3167. 星星还是树
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2424. 保龄球
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2680. 均分数据
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 搜索 - 爬山法
			AcWing 207. 球形空间产生器
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		1. 图论 - 最大流之算法模板
			AcWing 2171. EK求最大流
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2172. Dinic/ISAP求最大流
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 图论 - 最大流之二分图匹配
			AcWing 2175. 飞行员配对方案问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2179. 圆桌问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 图论 - 最大流之上下界可行流
			AcWing 2188. 无源汇上下界可行流
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2189. 有源汇上下界最大流
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2190. 有源汇上下界最小流
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 图论 - 最大流之多源汇最大流
			AcWing 2234. 多源汇最大流
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 图论 - 最大流之关键边
			AcWing 2236. 伊基的故事 I - 道路重建
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. 图论 - 最大流之最大流判定
			AcWing 2277. 秘密挤奶机
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2187. 星际转移问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		7. 图论 - 最大流之拆点
			AcWing 2240. 餐饮
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2180. 最长递增子序列问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2278. 企鹅游行
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		8. 图论 - 最大流之建图实战
			AcWing 2237. 猪
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		9. 图论 - 最小割之算法模板
			AcWing 2173. Dinic/ISAP求最小割
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		10. 图论 - 最小割之直接应用
			AcWing 2279. 网络战争
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2280. 最优标号
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		11. 图论 - 最小割之平面图转最短路
			AcWing 3246. 引水入城
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		12. 图论 - 最小割之最大权闭合图
			AcWing 961. 最大获利
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		13. 图论 - 最小割之最大密度子图
			AcWing 2324. 生活的艰辛
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		14. 图论 - 最小割之最小点权覆盖集
			AcWing 2325. 有向图破坏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		15. 图论 - 最小割之最大点权独立集
			AcWing 2326. 王者之剑
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		16. 图论 - 最小割之建图实战
			AcWing 381. 有线电视网络
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2176. 太空飞行计划问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2199. 骑士共存问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		17. 图论 - 费用流之算法模板
			AcWing 2174. 费用流
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		18. 图论 - 费用流之直接应用
			AcWing 2192. 运输问题	
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2194. 负载平衡问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		19. 图论 - 费用流之二分图最优匹配
			AcWing 2193. 分配问题	
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		20. 图论 - 费用流之最大权不相交路径
			AcWing 2191. 数字梯形问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		21. 图论 - 费用流之网格图模型
			AcWing 382. K取方格数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2195. 深海机器人问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		22. 图论 - 费用流之拆点
			AcWing 2184. 餐巾计划问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		23. 图论 - 费用流之上下界可行流
			AcWing 969. 志愿者招募
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		24. 图论 - 2-SAT
			AcWing 2402. 2-SAT 问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 371. 牧师约翰最忙碌的一天
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1032. 游戏
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		25. 图论 - 朱刘算法
			AcWing 2417. 指挥网络
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		26. 图论 - Prufer编码
			AcWing 2419. prufer序列
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2418. 光之大陆
	4. 数学知识
		1. 莫比乌斯反演
			AcWing 2702. problem b
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1358. 约数个数和
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 积性函数
			AcWing 221. 龙哥的问题
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. BSGS
			AcWing 3124. BSGS
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 3125. 扩展BSGS
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2526. 随机数生成器
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. FFT
			AcWing 3122. 多项式乘法	
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 3123. 高精度乘法II
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 生成函数
			AcWing 3132. 食物
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. burnside引理与polya定理
			AcWing 3133. 串珠子	
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 3134. 魔法手链
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		7. 斯特林数
			AcWing 3165. 第一类斯特林数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 3166. 第二类斯特林数
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 3020. 建筑师
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		8. 线性基
			AcWing 3164. 线性基
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 210. 异或运算
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
	5. 动态规划
		1. 基环树DP
			AcWing 358. 岛屿
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 1080. 骑士
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 359. 创世纪
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 四边形不等式
			AcWing 304. 诗人小G
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2889. 再探石子合并
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 插头DP
			AcWing 2934. 插头DP
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2144. 神奇游乐园
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2644. 地板
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
	6. 计算几何
		1. 基础知识
			AcWing 2983. 玩具
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2984. 线段
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		2. 凸包
			AcWing 1401. 围住奶牛
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2935. 信用卡凸包
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		3. 半平面交
			AcWing 2803. 凸多边形
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2957. 赛车	
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		4. 最小圆覆盖
			AcWing 3028. 最小圆覆盖
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2785. 信号增幅仪
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		5. 三维计算几何基础与三维凸包
			AcWing 2119. 最佳包裹
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		6. 旋转卡壳
			AcWing 2938. 周游世界
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2142. 最小矩形覆盖
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		7. 三角剖分
			AcWing 3034. 望远镜	
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		8. 扫描线
			AcWing 3068. 扫描线
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 2801. 三角形面积并
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		9. 自适应辛普森积分
			AcWing 3074. 自适应辛普森积分	
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
			AcWing 3069. 圆的面积并
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
4. 面试辅导
	第二十讲
		AcWing 703. 数独检查
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 697. 蒙斯特
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 698. 读电话号码
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 696. 哈默队长
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1109. 等式
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 914. 樱桃网
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 78. 左旋转字符串
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十九讲
		AcWing 647. 懒惰拼字赛
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 627. 排灯节照明
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 631. Googol字符串
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 643. 动态网格
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 695. 劣马
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 592. 雨
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 72. 平衡二叉树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十八讲
		AcWing 687. 扫雷
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 562. 壁画
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 595. 夏洛克和括号
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 620. 安全区
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 628. 美丽的数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 76. 和为S的连续正数序列
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十七讲
		AcWing 591. 国家领导者
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 587. 吃蛋糕
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 561. 大按钮
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 571. 数学编码器
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 623. 投票
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 578. 去观光
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 80. 骰子的点数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十六讲
		AcWing 1768. H 指数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1769. H 指数 II
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1158. H指数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1108. 读书
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 558. 乘积三元组
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1060. 墙的重建
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 53. 最小的k个数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十五讲
		AcWing 1318. 取石子游戏
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1302. 矩阵 A × B
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1262. 鱼塘钓鱼
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1274. 奶牛排队
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1306. 迷路
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 89. a^b
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十四讲
		AcWing 1254. 找树根和孩子
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1255. 医院设置
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1256. 扩展二叉树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1764. 修塔游戏
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1120. 埃及分数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 79. 滑动窗口的最大值
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十三讲
		AcWing 1099. 仙岛求药
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1102. 移动骑士
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1103. 棋盘游戏	
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1111. 字母
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1114. 棋盘问题
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 75. 和为S的两个数字
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十二讲
		AcWing 1051. 最大的和
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1026. 乘积最大
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1698. 余数的最大值
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1025. 开餐馆
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1028. 复制书稿
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1090. 绿色通道
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十一讲
		AcWing 48. 复杂链表的复刻
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 680. 剪绳子
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1645. 不同的二叉搜索树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 415. 栈
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 50. 序列化二叉树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 60. 礼物的最大价值
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十讲
		AcWing 730. 机器人跳跃问题
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 845. 八数码
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 167. 木棒
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 731. 毕业旅行问题
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 45. 之字形打印二叉树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 46. 二叉搜索树的后序遍历序列
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第九讲
		AcWing 1611. 寻找峰值
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 843. n-皇后问题
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1613. 数独简单版
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1612. 最大正方形
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 52. 数组中出现次数超过一半的数字
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 901. 滑雪
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第八讲
		AcWing 131. 直方图中最大的矩形
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 152. 城市游戏
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1574. 接雨水
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1575. 盛水最多的容器
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 454. 表达式求值
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 43. 不分行从上往下打印二叉树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第七讲
		AcWing 1572. 递归实现指数型枚举 II
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 93. 递归实现组合型枚举
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1573. 递归实现组合型枚举 II
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 55. 连续子数组的最大和
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 62. 丑数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 29. 删除链表中重复的节点
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第六讲
		AcWing 92. 递归实现指数型枚举
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 94. 递归实现排列型枚举
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1537. 递归实现排列类型枚举 II
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 145. 超市
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1057. 股票买卖 IV
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 36. 合并两个排序的链表
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第五讲
		AcWing 104. 货仓选址
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1536. 均分纸牌
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 122. 糖果传递
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 106. 动态中位数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 146. 序列
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 33. 链表中倒数第k个节点
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 786. 第k个数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第四讲
		AcWing 1490. 最长上升子串
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1259. 二叉树遍历
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1491. 圆桌座位
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 30. 正则表达式匹配
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 18. 重建二叉树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 19. 二叉树的下一个节点
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第三讲
		AcWing 1056. 股票买卖 III
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1487. 取硬币
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1488. 最短距离
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1489. 田忌赛马
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 77. 翻转单词顺序
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 851. spfa求最短路
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第二讲
		AcWing 35. 反转链表
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1453. 移掉K位数字
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1454. 异或和是质数的子集数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1455. 招聘
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 797. 差分
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 173. 矩阵距离
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第一讲
		AcWing 756. 蛇形矩阵
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1451. 单链表快速排序
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1452. 寻找矩阵的极小值
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1048. 鸡蛋的硬度
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 41. 包含min函数的栈
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 34. 链表中环的入口结点
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
5. pat
	第十四章 基础算法与数据结构
		AcWing 1506. 中位数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1530. 最短距离
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1571. 完美序列
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1581. 急性中风
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1641. 狼人杀-简单版
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1535. 弹出序列
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1541. 世界首富
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1543. 栈
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1607. 爱丁顿数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1528. 火星购物
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1524. 最长回文子串
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十三章 链表
		AcWing 1516. 共享
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1560. 反转链表
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1587. 链表重复数据删除
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1626. 链表元素分类
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十二章 贪心
		AcWing 1521. 魔术卷
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1522. 排成最小的数字
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1553. 用 Swap(0, i) 操作进行排序
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1556. 月饼
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1603. 整数集合划分
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1618. 结绳
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1517. 是否加满油
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十一章 模拟
		AcWing 1480. 电梯
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1483. 世界杯投注
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1486. 排队等候
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1515. U 形 Hello World
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1525. 独一无二
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1526. 洗牌机
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1531. 课程学生列表
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1540. 主导颜色
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1542. 老鼠和大米
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1548. 才华与德行
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1551. A + B 和 C
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1555. 数字黑洞
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1566. 研究生入学
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1569. 成绩单
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1582. 买还是不买
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1585. 校园内的汽车
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1595. 螺旋矩阵
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1599. 合影
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1614. 单身狗
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1621. N 皇后问题
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1622. 推荐系统
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1625. 切整数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1633. 外观数列
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1640. 堆
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第十章 并查集
		AcWing 1485. 战争中的城市
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1604. 家产
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1608. 森林里的鸟
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1597. 社会集群
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 836. 合并集合
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第九章 哈希表
		AcWing 1532. 找硬币
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1549. 集合相似度
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1610. 朋友数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1637. 漏掉的数字
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1642. 危险品装箱
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1564. 哈希
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1630. 期终成绩
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1638. 哈希 - 平均查找时间
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第八章 动态规划
		AcWing 1479. 最大子序列和
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1529. 最佳彩色带
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1554. 找更多硬币
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1583. PAT 计数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1591. 快速排序
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第七章 数学
		AcWing 1533. 1 的个数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1545. 质因子
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1567. 有理数的和
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1578. 有理数运算
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1586. 连续因子
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1593. 整数分解
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1594. 数段之和
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1602. 卡住的键盘
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1606. C 语言竞赛
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1646. 谷歌的招聘
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第六章 图论
		AcWing 1475. 紧急情况
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1507. 旅行计划
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1518. 团伙头目
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1577. 条条大路通罗马
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1601. 在线地图
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1615. 哈密顿回路
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1619. 欧拉路径
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1624. 地铁地图
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1627. 顶点覆盖
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1632. 第一次接触
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1635. 最大集团
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1639. 拓扑顺序
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1643. 旅行商问题
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1648. 顶点着色
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1495. 公共自行车管理
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1558. 加油站
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1562. 微博转发
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 849. Dijkstra求最短路 I
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 850. Dijkstra求最短路 II
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第五章 树
		AcWing 1476. 数叶子结点
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1497. 树的遍历
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1498. 最深的根
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1527. 判断二叉搜索树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1550. 完全二叉搜索树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1576. 再次树遍历
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1589. 构建二叉搜索树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1592. 反转二叉树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1600. 完全二叉树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1605. 二叉搜索树最后两层结点数量
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1609. 前序和后序遍历
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1620. Z 字形遍历二叉树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1631. 后序遍历
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1552. AVL树的根
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1616. 判断完全 AVL 树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1628. 判断红黑树
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1539. 等重路径
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1584. 最大的一代
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1565. 供应链总销售额
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1580. 供应链最高价格
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1596. 供应链最低价格
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1649. 堆路径
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1623. 中缀表达式
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1636. 最低公共祖先
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1644. 二叉树中的最低公共祖先
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 826. 单链表
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 836. 合并集合
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第四章 排序
		AcWing 1484. 最佳排名
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1499. 数字图书馆
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1502. PAT 排名
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1505. 列表排序
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1523. 学生课程列表
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1538. 链表排序
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1561. PAT 评测
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1588. 插入还是堆排序
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1579. 插入还是归并
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 789. 数的范围
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 838. 堆排序
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第三章 进位制
		AcWing 1482. 进制
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1492. 可逆质数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1504. 火星颜色
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1590. 火星数字
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1496. 普通回文数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第二章 高精度
		AcWing 1474. 多项式 A + B
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1481. 多项式乘积
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1500. 趣味数字
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1501. 回文数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1544. 霍格沃茨的 A + B
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1629. 延迟的回文数
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
	第一章 字符串
		AcWing 1473. A + B 格式
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1477. 拼写正确
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1478. 签到与签出
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1519. 密码
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1520. 男孩 vs 女孩
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1534. 字符串减法
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1557. 说话方式
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1547. 约会
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1493. 电话账单
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1494. 银行排队
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1503. 乒乓球
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1546. 它们是否相等
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1559. 科学计数法
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1563. Kuchiguse
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1568. 中文读数字
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1570. 坏掉的键盘
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1598. 求平均值
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1617. 微博转发抽奖
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1634. PAT单位排行
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度
		AcWing 1647. 解码PAT准考证	
			1. 网址
			2. 代码{解析}
			3. 纯代码
			4. 复杂度


00
	1. 单链表
		1. 
	2. 双链表
		1. 
	3. 栈
		1. 
		2. 

			

	4. 队列

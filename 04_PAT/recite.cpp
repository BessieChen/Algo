目标:
	1. 面试: 每天背15题
		1. 基础 	106
		2. 提高 	219
		3. 面试/剑指offer	125+76=201
		4. pat 	162
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
			1. AcWing 785. 快速排序 $$
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

					    swap(q[l], q[rand() % (r-l+1) + l]);
					    int i = l - 1, j = r + 1, x = q[l];
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

					    swap(q[l], q[rand() % (r-l+1) + l]);
					    int i = l - 1, j = r + 1, x = q[l];
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
											所以就是 If(target <= xx[mid])
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
						2. 总结: 右改 mid(谐音, 又改mid)
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
					        	//如果temp是-2, 说明已经往上面借了一位, 所以-2 + 10 = 8
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
			1. AcWing 831. KMP字符串
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
					        while(j && p[i] != p[j+1]) j = ne[j]; //不满足, 跳回到之前模式一样的地方, ne[j]对应的是图中前缀的小后缀a1的右端点
					        	上一轮我们停留在了j点{注意, 这里是理解成索引为j的地方, 而不是长度为j}, 现在从j点继续. 
					        		如果j > 0, 说明还有回退的空间
					        		如果j == 0, 已经退到最后了, 就不需要while了 
					        	我们判断下一个pair{也就是 p[i], p[j+1]}. 
					        		pair的第一个部分, 也就是当前遍历到的 p[i]
					        			这个第一个部分, 其实关注的是后缀, 这个后缀的右端点, 是固定已知的, 那就是i索引所在的点
					        			至于这个后缀的左端点在哪里, 其实我们现在还不知道, 等知道了, 那就是后面 ne[i] = j; 这一步了, 也就是后缀的长度是 j , 对应的区间是 [i-j+1, i]
					        		pair的第二个部分, 是我们扩展一下上一轮停留到的前缀, 从上一轮的[1, j] 扩展到这一轮的[1, j+1]
					        	如果这两个部分, 匹配成功
					        		因为上一轮的时候, 我们知道了 后缀所在的区间[xx, i-1] == 前缀所在的区间 [1, j]
					        		而这一轮, 刚好 p[i] == p[j+1]
					        		那么上一轮的前缀区间和后缀区间, 都可以往后扩展一格, 变为 [xx, i]区间 == [1, j+1] 
					        	如果这两个部分, 不匹配, 我们就要回退, 回退是什么意思?
					        		|a1|c1*|b1|d-----|a2|c2*|b2|$|
					        		1        j                  i 
					        		首先, 后缀的右端点, 是固定已知的, 那就是i索引所在的点$, 且我们希望后缀的长度越长. 
					        		因为 上一轮的时候, 我们知道了上一轮求出的 最长后缀所在的区间[xx, i-1] == 最长前缀所在的区间 [1, j]
					        		我们其实还是可以利用上一轮的一些信息的.
					        			因为上一轮的 前缀|a1|c1*|b1| == 后缀|a2|c2*|b2|
					        			这一轮只是 $ != d 
					        			因为这一轮的后缀的右端点不变, 我们只需要尽可能的往前, 因为不可能前到 a2那么前了, 因为已经知道 $ != d了
					        			但是我们能否妥协一下, 所以我们尝试着站在前几轮的肩膀上求最长的后缀.
					        			我们可以利用以下两个信息:
					        				1. 因为我们知道根据上一轮的信息知道 b1 == b2
					        				2. 我们从上上上...某轮的信息知道 a1 == b1
					        					解释:
					        						于此同时, 那个前缀[1, j], 也就是图中 		这一段, 其实自己本身也可以分成前缀和后缀吧, 我况且称为 小前缀a和小后缀b
																	        		|a|c*|b|
																	        		1      j
													那么这个前缀的最长小前缀a小后缀b, 都是之前就已经计算好了, 因为我们计算的时候是从左往右计算的
													那这个前缀的最长小后缀b的长度是多少? 是ne[j], 因为前缀的后端点是j, 所以这个前缀的最长小前缀a也就是 [1, ne[j]]
													所以, 你知道了吧. 就像是如果打不过第3关, 我们就回退到第2关, 看看第二关有什么打的.
														我们之前想比较的是, 踩在上一轮的肩膀上
															因为上一轮的时候, 我们知道了 后缀所在的区间[xx, i-1] == 前缀所在的区间 [1, j]
									        				而这一轮, 我们比较的是 p[i] 和图中d位置上的点, 因为不匹配, 所以我们从第三关回退到第二管, 找前缀的小前缀a
									        				我们现在判断的是, p[i]和
					        			所以 a1 == b2
					        			所以我们不需要从头开始找前缀了, 我们可以从c1开始找前缀
					        			如果 c1 == $
					        			我们的最长前后缀就是 |a1|c1| == |b2|$|					        	
					        if(p[i] == p[j+1]) j++; //满足,继续
					        	如果这个pair相等, 说明什么?
					        		说明我们的后缀 [xx, i] 
					        ne[i] = j;
					        	解释: 以下两个区间的内容相同:
					        		1. 后缀:
					        			[i-j+1, i] 这个区间的内容
					        				这个区间的长度是j
					        				注意之所以是 i - j + 1. 因为右端点是i, 长度是j, 然后我们的左端点就是 i - j + 1.
					        		2. 前缀:
					        			[1, j] 区间的内容
					        				这个区间的长度是j
					    }
					    举例感受:
						    a a a a a a a a a 一共9个字母
						    	i: 0 ne[i]: 0
								i: 1 ne[i]: 0 
								i: 2 ne[i]: 1
								i: 3 ne[i]: 2
								i: 4 ne[i]: 3
								i: 5 ne[i]: 4
								i: 6 ne[i]: 5
								i: 7 ne[i]: 6
								i: 8 ne[i]: 7
								i: 9 ne[i]: 8  前8个a 和 后8个a 是最长前后缀. 说明最长前后缀是不能完全重叠的, 也就是不能是全部九个a
							a b c d e a b c d					   
							  	i: 0 ne[i]: 0	index == 0是无用的
								i: 1 ne[i]: 0	说明, [a] 最长公共前后缀是 j == 0 
								i: 2 ne[i]: 0	说明, [a, b] 最长公共前后缀是 j == 0
								i: 3 ne[i]: 0	说明, [a, b, c] 最长公共前后缀是 j == 0
								i: 4 ne[i]: 0	说明, [a, b, c, d] 最长公共前后缀是 j == 0
								i: 5 ne[i]: 0	说明, [a, b, c, d, e] 最长公共前后缀是 j == 0
								i: 6 ne[i]: 1	说明, [a, b, c, d, e, a] 最长公共前后缀是 j == 1
								i: 7 ne[i]: 2	说明, [a, b, c, d, e, a, b] 最长公共前后缀是 j == 2
								i: 8 ne[i]: 3
								i: 9 ne[i]: 4
							a b c d e a a b c d
								i: 0 ne[i]: 0
								i: 1 ne[i]: 0
								i: 2 ne[i]: 0
								i: 3 ne[i]: 0
								i: 4 ne[i]: 0
								i: 5 ne[i]: 0
								i: 6 ne[i]: 1	说明, [a, b, c, d, e, a] 最长公共前后缀是 j == 1
								i: 7 ne[i]: 1	说明, [a, b, c, d, e, a, a] 最长公共前后缀是 j == 1
								i: 8 ne[i]: 2
								i: 9 ne[i]: 3
								i: 10 ne[i]: 4
							a b a b a b a b a b a
								i: 0 ne[i]: 0
								i: 1 ne[i]: 0
								i: 2 ne[i]: 0
								i: 3 ne[i]: 1
								i: 4 ne[i]: 2
								i: 5 ne[i]: 3
								i: 6 ne[i]: 4
								i: 7 ne[i]: 5
								i: 8 ne[i]: 6
								i: 9 ne[i]: 7
								i: 10 ne[i]: 8
								i: 11 ne[i]: 9

					    for(int i = 1, j = 0; i <= m; i++){ //是s的第一个字符和p的第一个字符比较
					        while(j && s[i] != p[j+1]) j = ne[j];
					        if(s[i] == p[j+1]) j++;
					        if( j == n){ 说明把p给遍历完了 
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
			1. AcWing 835. Trie字符串统计 todo
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
			2. AcWing 143. 最大异或对 todo
				1. 网址
				2. 代码{解析}
				3. 纯代码
				4. 复杂度
		9. 并查集
			1. AcWing 836. 合并集合
				1. 网址
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int p[N];

					int find(int x)
					{
					    if (p[x] != x) p[x] = find(p[x]); 背就好了, 简单
					    return p[x];
					}

					int main()
					{
					    int n, m;
					    scanf("%d%d", &n, &m);
					    for (int i = 1; i <= n; i ++ ) p[i] = i;

					    while (m -- )
					    {
					        char op[2];
					        int a, b;
					        scanf("%s%d%d", op, &a, &b);
					        if (*op == 'M') p[find(a)] = find(b);
					        else
					        {
					            if (find(a) == find(b)) puts("Yes");
					            else puts("No");
					        }
					    }

					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int p[N];

					int find(int x)
					{
					    if (p[x] != x) p[x] = find(p[x]);
					    return p[x];
					}

					int main()
					{
					    int n, m;
					    scanf("%d%d", &n, &m);
					    for (int i = 1; i <= n; i ++ ) p[i] = i;

					    while (m -- )
					    {
					        char op[2];
					        int a, b;
					        scanf("%s%d%d", op, &a, &b);
					        if (*op == 'M') p[find(a)] = find(b);
					        else
					        {
					            if (find(a) == find(b)) puts("Yes");
					            else puts("No");
					        }
					    }

					    return 0;
					}
				4. 复杂度
			2. AcWing 837. 连通块中点的数量
				1. 网址
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int n, m;
					int p[N], cnt[N];

					int find(int x)
					{
					    if (p[x] != x) p[x] = find(p[x]); 背
					    return p[x];
					}

					int main()
					{
					    cin >> n >> m;

					    for (int i = 1; i <= n; i ++ )
					    {
					        p[i] = i;
					        cnt[i] = 1;
					    }

					    while (m -- )
					    {
					        string op;
					        int a, b;
					        cin >> op;

					        if (op == "C")
					        {
					            cin >> a >> b;
					            a = find(a), b = find(b);
					            if (a != b)
					            {
					                p[a] = b;
					                cnt[b] += cnt[a];
					            }
					        }
					        else if (op == "Q1")
					        {
					            cin >> a >> b;
					            if (find(a) == find(b)) puts("Yes");
					            else puts("No");
					        }
					        else
					        {
					            cin >> a;
					            cout << cnt[find(a)] << endl;
					        }
					    }

					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int n, m;
					int p[N], cnt[N];

					int find(int x)
					{
					    if (p[x] != x) p[x] = find(p[x]);
					    return p[x];
					}

					int main()
					{
					    cin >> n >> m;

					    for (int i = 1; i <= n; i ++ )
					    {
					        p[i] = i;
					        cnt[i] = 1;
					    }

					    while (m -- )
					    {
					        string op;
					        int a, b;
					        cin >> op;

					        if (op == "C")
					        {
					            cin >> a >> b;
					            a = find(a), b = find(b);
					            if (a != b)
					            {
					                p[a] = b;
					                cnt[b] += cnt[a];
					            }
					        }
					        else if (op == "Q1")
					        {
					            cin >> a >> b;
					            if (find(a) == find(b)) puts("Yes");
					            else puts("No");
					        }
					        else
					        {
					            cin >> a;
					            cout << cnt[find(a)] << endl;
					        }
					    }

					    return 0;
					}
				4. 复杂度
			3. AcWing 240. 食物链
				1. 网址
				2. 代码{解析}
					#include <iostream>

					using namespace std;

					const int N = 50010;

					int n, m;
					int p[N], d[N]; p是并查集的father, d是距离

					int find(int x)
					{
					    if (p[x] != x)
					    {
					        int t = find(p[x]); //这里会递归调用, t最后都是祖先的ind
					        d[x] += d[p[x]]; 执行完这一句, 就是d[x]存储的是x到根节点的距离. 这句话是通过递归调用实现的:  //这里也会递归调用,也就是d[父之父] += d[父之父之父], 之后d[父] += d[父之父], 最后 d[我] += d[父]. 所以d[我]最终就是我x到根节点的距离 
					        p[x] = t;
					    }
					    return p[x];
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    for (int i = 1; i <= n; i ++ ) p[i] = i;

					    int res = 0;
					    while (m -- )
					    {
					        int t, x, y;
					        scanf("%d%d%d", &t, &x, &y);

					        if (x > n || y > n) res ++ ; 编号超出, 是假话, res++ 
					        else
					        {
					            int px = find(x), py = find(y);
					            if (t == 1)
					            {
					                if (px == py && (d[x] - d[y]) % 3) res ++ ; 
					                //如果是同一个集合{生态圈}, 那就需要满足 d[x]%3 == d[y]%3, 也就是说他们属于同一个集合{生态圈}里面的同一类. 
					                //但是, 如果 d[x] % 3 != d[y] % 3, 就是说明不是同类, 则是假话 res++
					                else if (px != py) //不是同一个集合{生态圈}, 说明这是一句真话, 或者我们认为这是一句没有矛盾的话. 所以接下来就是合并他们
					                {
					                    p[px] = py; //px的父亲变成py
					                    d[px] = d[y] - d[x];  //修改距离: 所以你看之前说的xx层不是真的层,而是需要d[]来维护距离
					                    //因为是同类, 需要 (d[x] + ? ) % 3 == d[y] % 3, 所以 d[x] + ? == d[y], 所以 ? = d[y] - d[x], 所以d[px] 就是?的值
					                    //我的新理解:
					                    /*
					                    	   y
					                    	  /2
					                    	px 
					                    	|1
					                    	x

					                    	d[x]在没有更新之前, 指的是 x到px的距离, 也就是x到x的祖先px的距离 
					                    	现在更新了之后, 我们要满足的一个条件是 x和y是同一类, 所以要满足的关系是: (d[x] + ? ) % 3 == d[y] % 3
					                    		怎么解释? (d[x] + ? )中, d[x]也就是图中1的距离, ?也就是图中2的距离
					                    		而?也就是2, 其实恰好也就是 d[px], 意思也就是px到它的新祖先y的距离. 
					                    		而1是固定的, 2是我们可以更新的, 所以1不变, 将2更新为 d[y] - d[x] */
					                
					                    //https://www.acwing.com/video/19/ 的01:06:30
					                }
					            }
					            else //也就是 x吃y, 也就是x在y的下面层, d[x]%3 比 d[y]%3 要大, 大多少? 大一
					            {
					                
					                if (px == py && (d[x] - d[y] - 1) % 3) res ++ ; 
					                //注意d[x] - d[y] - 1) % 3 !=0, 不能换成d[a] - d[b]) % 3 != 1. 
					                // 注意(d[a] - d[b]) % 3可能是负数，需要转化成正数：((d[a] - d[b]) % 3 + 3) % 3 
					                //看是否是x吃y,也就是d[x]的余数比d[y]的余数大1, d[x] % 3 == d[y] % 3 + 1;
					                // d[x] % 3 == d[y] % 3 + 1 % 3;  d[x] % 3 == (d[y] + 1) % 3;
					                else if (px != py)
					                {
					                    p[px] = py;
					                    d[px] = d[y] + 1 - d[x];//修改距离: 所以你看之前说的xx层不是真的层,而是需要d[]来维护距离
					                    //因为是同类, 需要 (d[x] + ? ) % 3 == d[y] % 3 + 1, 所以? = d[y] - d[x] + 1
					                    //其实我觉得这里涉及到了一些余数的知识
					                }
					            }
					        }
					    }

					    printf("%d\n", res);

					    return 0;
					}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 50010;

					int n, m;
					int p[N], d[N]; 

					int find(int x)
					{
					    if (p[x] != x)
					    {
					        int t = find(p[x]); //这里会递归调用, t最后都是祖先的ind
					        d[x] += d[p[x]]; 
					        p[x] = t;
					    }
					    return p[x];
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    for (int i = 1; i <= n; i ++ ) p[i] = i;

					    int res = 0;
					    while (m -- )
					    {
					        int t, x, y;
					        scanf("%d%d%d", &t, &x, &y);

					        if (x > n || y > n) res ++ ; 编号超出, 是假话, res++ 
					        else
					        {
					            int px = find(x), py = find(y);
					            if (t == 1)
					            {
					                if (px == py && (d[x] - d[y]) % 3) res ++ ; 
					                else if (px != py) 
					                {
					                    p[px] = py; 
					                    d[px] = d[y] - d[x]; 
					                    
					                }
					            }
					            else 
					            {
					                
					                if (px == py && (d[x] - d[y] - 1) % 3) res ++ ; 
					                else if (px != py)
					                {
					                    p[px] = py;
					                    d[px] = d[y] + 1 - d[x];
					                }
					            }
					        }
					    }

					    printf("%d\n", res);

					    return 0;
					}
				4. 复杂度
		10. 堆
			1. AcWing 838. 堆排序{小根堆, 父亲 <= 左右儿子}
				1. 网址
				2. 代码{解析}
					老师的习惯
						从ind == 1开始
						所以size指向的是最后一个已经有的元素,而不是最后一个元素的下一位
							左儿子 = x * 2, 右儿子 = x * 2 + 1
							父节点 = x / 2
					老师说
						层数不高,所以 down()里面采用的是递归,而不是while实现.

					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010;

					int n, m;
					int h[N], cnt;

					void down(int u)
					{
					    int l = u * 2, r = u * 2 + 1; 
						int t = u;
						if(l <= cnt && h[l] > h[t]) t = l; 这里是小跟堆, 父亲 <= 左右儿子
						if(r <= cnt && h[r] > h[t]) t = r; 这里不能写成b[r] > b[l], 因为还是要和t比, 这里的t可能是l, 也可能是原来的u
						if(t != u){
							swap(h[u], h[t]);
							down(t, cnt);
						}
					}

					int main()
					{
					    scanf("%d%d", &n, &m);
					    for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]); 从1开始方便. 
					    cnt = n;

					    for (int i = n / 2; i; i -- ) down(i);

					    while (m -- )
					    {
					        printf("%d ", h[1]);
					        h[1] = h[cnt -- ];
					        down(1);
					    }

					    puts("");

					    return 0;
					}
				3. 纯代码
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010;

					int n, m;
					int h[N], cnt;

					void down(int u)
					{
					    int l = u * 2, r = u * 2 + 1; 
						int t = u;
						if(l <= cnt && h[l] > h[t]) t = l;
						if(r <= cnt && h[r] > h[t]) t = r;
						if(t != u){
							swap(h[u], h[t]);
							down(t, cnt);
						}
					}

					int main()
					{
					    scanf("%d%d", &n, &m);
					    for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);
					    cnt = n;

					    for (int i = n / 2; i; i -- ) down(i);

					    while (m -- )
					    {
					        printf("%d ", h[1]);
					        h[1] = h[cnt -- ];
					        down(1);
					    }

					    puts("");

					    return 0;
					}
				4. 复杂度:  O(n)
					复杂度
						如果是一个一个加入,然后 siftDown()
							复杂度是 O(n*logn):
								因为一个元素需要向下logn层,一共n个元素
						如果是heapify,也就是直接整个数组,从倒数第2层的最后一个元素开始 siftDown()
							复杂度是 O(n)
								因为倒数第二层有n/4个元素,每个元素只需往下siftdown 1层
								因为倒数第3层有n/8个元素,每个元素只需往下siftdown 2层
								...
								所以复杂度是 O(n/4 * 1) + (n/8 * 2) + ... 最后推到看https://www.acwing.com/video/17/的01:39:00 或者 https://www.acwing.com/video/263/ 的29:00
								总之就是 O(n * 1)
			2. AcWing 839. 模拟堆{用于优化Dijkstra, 求最短路}
				1. 网址
				2. 代码{解析}
					#include <iostream>
					#include <algorithm>
					#include <string.h>

					using namespace std;

					const int N = 100010;

					int h[N], ph[N], hp[N], cnt;

					void heap_swap(int a, int b)
					{
					    swap(ph[hp[a]],ph[hp[b]]); 注意: ph[hp[a]] = a; hp[ph[k]] = k
						    之前: ph 0 1 2 3 4 5 6 
						       	        a   b 		-> 也就是第2个插入的数字, 在heap中的下标是a
						    之后: ph 0 1 2 3 4 5 6
						       	        b   a  		-> 也就是第2个插入的数字, 在heap中的下标是b了, 而之后heap中的下标是b的数字也会从yy改为xx
					    swap(hp[a], hp[b]);
						    之前: hp 0 1 2 3 4 a b
						       	   		      2 4
						    之后: hp 0 1 2 3 4 a b
						       	   		      4 2   -> heap中的下标是b的数是xx
					    swap(h[a], h[b]);
					    	之前: h  0 1 a 3 b 5 6
						       	   		xx  yy
						    之后: h  0 1 a 3 b 5 6
						       	   		yy  xx      -> heap中的下标是b的数是xx
						这个故事就讲的通了:
							之前:
								ph 0 1 2 3 4 5 6 
						       	       a   b 		-> 也就是第2个插入的数字, 在heap中的下标是a
						       	hp 0 1 2 3 4 a b
						       	   		     2 4
						       	h  0 1 a 3 b 5 6
						       	   	   xx  yy

						       	故事:
						       		1. 问: 第2个插入的数字是多少? 
						       			答: 从ph[2]得知是a, h[a]得知是xx, 所以是xx
						       		2. 问: 我要交换heap中下标为a, b的两个数, 那么是交换第几个和第几个插入的数?
						       			答: 从hp[a]得知是2, 从hp[b]得知是4
						    假设我们真的交换了:
					    		ph 0 1 2 3 4 5 6
					       	           b   a  		
					       	    hp 0 1 2 3 4 a b
					       	   		         4 2 
					       	    h  0 1 a 3 b 5 6
					       	   		   yy  xx 
						       	
						       	故事:
						       		1. 问: 第2个插入的数字是多少? 
						       			答: 从ph[2]得知是b, h[b]得知是xx, 所以是xx. 你看, 信息存储没有变!! 第二个插入的一直是数字xx
					}

					void down(int u)
					{
					    int t = u;
					    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
					    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
					    if (u != t)
					    {
					        heap_swap(u, t);
					        down(t);
					    }
					}

					void up(int u)
					{
					    while (u / 2 && h[u] < h[u / 2]) 如果有父亲, 而且我比父亲的值小, 我上升{因为小根堆: 父亲 <= 儿子} 
					    	我比较喜欢这一句 u / 2
					    		因为如果是根u==1, 那么 u/2 ==0, 也就是根没有父亲了
					    {
					        heap_swap(u, u / 2);
					        u >>= 1;
					    }
					}

					int main()
					{
					    int n, m = 0; m是第m个插入的数字
					    scanf("%d", &n);
					    while (n -- )
					    {
					        char op[5];
					        int k, x;
					        scanf("%s", op);
					        if (!strcmp(op, "I")) !=0, 说明匹配 
					        {
					            scanf("%d", &x); 数字是多少 
					            cnt ++ ; cnt是heap中的下标 
					            m ++ ; 是第m个插入的数字
					            ph[m] = cnt, hp[cnt] = m;  第m个插入的数字在heap中的下标是cnt, 下标是cnt的数字是第m个插入的
					            h[cnt] = x; heap的第cnt个下标, 插入x这个数字
					            up(cnt); 从尾部一直往顶部sift
					        }
					        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
					        else if (!strcmp(op, "DM"))
					        {
					            heap_swap(1, cnt);
					            cnt -- ;
					            down(1);
					        }
					        else if (!strcmp(op, "D"))
					        {
					            scanf("%d", &k);
					            k = ph[k];   ph[k]: 第k个插入的数在heap中的下标是 ph[k]
					            heap_swap(k, cnt); 这里传入的都是 heap的下标
					            cnt -- ;
					            up(k); 	因为不确定是上升还是下降, 所以两个都走一遍
					            down(k);
					        }
					        else
					        {
					            scanf("%d%d", &k, &x);
					            k = ph[k];
					            h[k] = x; 更改第k个插入的元素, 改为x
					            up(k);
					            down(k);
					        }
					    }

					    return 0;
					}
				3. 纯代码
					#include <iostream>
					#include <algorithm>
					#include <string.h>

					using namespace std;

					const int N = 100010;

					int h[N], ph[N], hp[N], cnt;

					void heap_swap(int a, int b)
					{
					    swap(ph[hp[a]],ph[hp[b]]);
					    swap(hp[a], hp[b]);
					    swap(h[a], h[b]);
					}

					void down(int u)
					{
					    int t = u;
					    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
					    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
					    if (u != t)
					    {
					        heap_swap(u, t);
					        down(t);
					    }
					}

					void up(int u)
					{
					    while (u / 2 && h[u] < h[u / 2])
					    {
					        heap_swap(u, u / 2);
					        u >>= 1;
					    }
					}

					int main()
					{
					    int n, m = 0; 
					    scanf("%d", &n);
					    while (n -- )
					    {
					        char op[5];
					        int k, x;
					        scanf("%s", op);
					        if (!strcmp(op, "I"))
					        {
					            scanf("%d", &x); 
					            cnt ++ ; 
					            m ++ ; 
					            ph[m] = cnt, hp[cnt] = m;  
					            h[cnt] = x; 
					            up(cnt); 
					        }
					        else if (!strcmp(op, "PM")) printf("%d\n", h[1]);
					        else if (!strcmp(op, "DM"))
					        {
					            heap_swap(1, cnt);
					            cnt -- ;
					            down(1);
					        }
					        else if (!strcmp(op, "D"))
					        {
					            scanf("%d", &k);
					            k = ph[k];  
					            heap_swap(k, cnt);
					            cnt -- ;
					            up(k); 	
					            down(k);
					        }
					        else
					        {
					            scanf("%d%d", &k, &x);
					            k = ph[k];
					            h[k] = x;
					            up(k);
					            down(k);
					        }
					    }

					    return 0;
					}
				4. 复杂度
		11. 哈希表
			1. AcWing 840. 模拟散列表
				1. 网址
				2. 代码{解析}
					1. 开放寻址法
						#include <cstring>
						#include <iostream>

						using namespace std;

						const int N = 200003, null = 0x3f3f3f3f; 
							老师说, 坑位需要比数据范围大2到3倍
							老师如何找: 大于20w的最小质数
								for(int i = 200000; ; i ++){
									bool f = false;
									for(int j = 2; j * j <= i; j++){
										if(i % j == 0)
										{
											f = true;
											break; //说明不是质数
										}
									}

									if(!flag){
										cout << i <<endl;
										break; //i是质数
									}
								}

						int h[N];

						int find(int x) 返回值有两个含义
						{
						    int t = (x % N + N) % N; 一定是先%再+再%, 如果错写成: (x + N) % N , 那么: (-10e9 + 10e5) % 10e5 依旧是负数
						    while (h[t] != null 如果这个坑是有人的 && h[t] != x 并且这个坑位上人不是x)
						    {
						        t ++ ; 下一个坑位
						        if (t == N) t = 0;
						    }
						    return t; 返回的是二者之一: 一个没有人的坑, 所以可以存x || 这个坑位上的人已经是x
						}

						int main()
						{
						    memset(h, 0x3f, sizeof h);

						    int n;
						    scanf("%d", &n);

						    while (n -- )
						    {
						        char op[2];
						        int x;
						        scanf("%s%d", op, &x);
						        if (*op == 'I') h[find(x)] = x; 把这个没有人的坑, 填入x值 
						        else
						        {
						            if (h[find(x)] == null) puts("No"); find()返回两种: 一个没有人的坑 || 这个坑位上的人是x
						            else puts("Yes");
						        }
						    }

						    return 0;
						}

					2. 拉链法: 其实很简单, 就是用 质数N来判断坑在哪里, 其他的和单链表一样
						#include <cstring>
						#include <iostream>

						using namespace std;

						const int N = 100003; {N是第一个大于10w的质数}
							老师如何找: 大于100000的最小质数
								for(int i = 100000; ; i ++){
									bool f = false;
									for(int j = 2; j * j <= i; j++){
										if(i % j == 0)
										{
											f = true;
											break; //说明不是质数
										}
									}

									if(!flag){
										cout << i <<endl;
										break; //i是质数
									}
								}

						int h[N], e[N], ne[N], idx;

						void insert(int x)
						{
						    int k = (x % N + N) % N; 找到我们要的坑 
						    e[idx] = x;
						    ne[idx] = h[k]; 也就是往这个坑里面加入, 这个坑是一个链表.
						    h[k] = idx ++ ;
						}

						bool find(int x)
						{
						    int k = (x % N + N) % N;
						    for (int i = h[k]; i != -1; i = ne[i])
						        if (e[i] == x)
						            return true;

						    return false;
						}

						int main()
						{
						    int n;
						    scanf("%d", &n); 

						    memset(h, -1, sizeof h);

						    while (n -- )
						    {
						        char op[2];
						        int x;
						        scanf("%s%d", op, &x); 如果是读入一个字符串, 最好用 scanf(), 因为scanf会把制表符, 空格忽略掉. 

						        if (*op == 'I') insert(x);
						        else
						        {
						            if (find(x)) puts("Yes");
						            else puts("No");
						        }
						    }

						    return 0;
						}
				3. 纯代码
					1. 开放寻址法
						#include <cstring>
						#include <iostream>

						using namespace std;

						const int N = 200003, null = 0x3f3f3f3f; 
							
								for(int i = 200000; ; i ++){
									bool f = false;
									for(int j = 2; j * j <= i; j++){
										if(i % j == 0)
										{
											f = true;
											break; 
										}
									}

									if(!flag){
										cout << i <<endl;
										break; 
									}
								}

						int h[N];

						int find(int x) 返回值有两个含义
						{
						    int t = (x % N + N) % N; 
						    while (h[t] != null && h[t] != x)
						    {
						        t ++ ; 下一个坑位
						        if (t == N) t = 0;
						    }
						    return t; 
						}

						int main()
						{
						    memset(h, 0x3f, sizeof h);

						    int n;
						    scanf("%d", &n);

						    while (n -- )
						    {
						        char op[2];
						        int x;
						        scanf("%s%d", op, &x);
						        if (*op == 'I') h[find(x)] = x;
						        else
						        {
						            if (h[find(x)] == null) puts("No");
						            else puts("Yes");
						        }
						    }

						    return 0;
						}

					2. 拉链法: 其实很简单, 就是用 质数N来判断坑在哪里, 其他的和单链表一样
						#include <cstring>
						#include <iostream>

						using namespace std;

						const int N = 100003; 
								for(int i = 100000; ; i ++){
									bool f = false;
									for(int j = 2; j * j <= i; j++){
										if(i % j == 0)
										{
											f = true;
											break; //说明不是质数
										}
									}

									if(!flag){
										cout << i <<endl;
										break; //i是质数
									}
								}

						int h[N], e[N], ne[N], idx;

						void insert(int x)
						{
						    int k = (x % N + N) % N; 
						    e[idx] = x;
						    ne[idx] = h[k]; 
						    h[k] = idx ++ ;
						}

						bool find(int x)
						{
						    int k = (x % N + N) % N;
						    for (int i = h[k]; i != -1; i = ne[i])
						        if (e[i] == x)
						            return true;

						    return false;
						}

						int main()
						{
						    int n;
						    scanf("%d", &n); 

						    memset(h, -1, sizeof h);

						    while (n -- )
						    {
						        char op[2];
						        int x;
						        scanf("%s%d", op, &x);

						        if (*op == 'I') insert(x);
						        else
						        {
						            if (find(x)) puts("Yes");
						            else puts("No");
						        }
						    }

						    return 0;
						}
				4. 复杂度
			2. AcWing 841. 字符串哈希
				1. 网址
				2. 代码{解析}
					str = "ABCDEFSFOIJER"
					h[n]: "前n个"字符的hash值
						h[i]的意思是, 前i个字符的hash值. 
							有种累加和的感觉. 其中"左侧"第一个字符str[1], 它是前1个字符 h[1]. 
						例如
							h[0] = 0, 空值的哈希
							h[1] = "A"这个字符串的hash值
							h[2] = "AB"这个字符串的hash值
						问题:如何求一个字符串的hash值
						解决:
							1. 先将一个字符串看成一个P进制的数字
								例如"ABCE"可以看成像是(1235)p的数字
								计算方法:
									1*P^3 + 2*p^2 + 3*p + 5
								其中A是最高位,所以是p^3
								每个字母都映射着一个数字
									但是不能映射成0,不然的话AA和A计算的值都是0
							2. 计算好p进制对应的数字后,取模
							3. 经验值: 这样就不会发生conflict
								p进制的p = 131 或者 13331
								mod的数字是 2^64
							4.  用 unsigned long long 的溢出代替 mod
						我们为了求h[i]
							h[i] = h[i-1] * p + str[i]
								例如,h[1]是"A"的hash, 也就是1*p^0的hash
								然后h[2]是"AB"的hash,也就是1*p^1 + 2*p^0的hash
								其中str[2]就是"B"
						在知道全部i的h[i]后,我们可以求出第L位到第R位字符串的hash
							记这个hash叫xxx
								xxx = h[R] - h[L-1]*p^(R-L+1) 
									解释:
										1. 视频
											https://www.acwing.com/video/20/ 的 01:01:35
										1. 假设字符串是"ABCDE",R=5(从ind=1开始),L=3,也就是要求"CDE"的hash值
													  12345
										2. 因为h[R]的值是
											"ABCDE"的hash值
												注意A是高位,E是低位
												长度是R,也就是5
												所以A是第R-1位, E是第0位
											A*p^(R-1) + B*p^(R-2) + C*p^2 + D*p^1 + E*p^0
											A*p^4 + B*p^3 + C*p^2 + D*p^1 + E*p^0
										3. 因为h[L-1]的值是"AB"的hash值
												注意A是高位,E是低位
												长度是L-1,也就是2
												所以A是第L-2位, B是第0位
											所以 A*p^1 + B*p^0
										4. 所以xxx = h[R] - h[L-1]*p^(R-L+1) 后
											因为A从L-2的幂次,变成了R-1的幂次,需要乘上: R - (L - 1) == (R - L + 1) == 5-2==3次幂
											最后我们剩余的就是
												A*p^4 + B*p^3 + C*p^2 + D*p^1 + E*p^0 
											- (A*p^1 + B*p^0) * p^3 
											= C*p^2 + D*p^1 + E*p^0
											这个就是我们想要的"CDE"的hash值
					求一个字符串的hash值可以帮助我们判断两个字符串是否相等
					3. kmp能够做的,用字符串哈希也可以(但是循环节问题:只有kmp能做)

					#include <iostream>
					#include <algorithm>

					using namespace std;

					typedef unsigned long long ULL;

					const int N = 100010, P = 131; P是经验值 

					int n, m;
					char str[N];
					ULL h[N], p[N];

					ULL get(int l, int r) 获得[l,r]段的hash值
					{
					    return h[r] - h[l - 1] * p[r - l + 1]; 根据公式 
					}

					int main()
					{
					    scanf("%d%d", &n, &m);
					    scanf("%s", str + 1);

					    p[0] = 1;
					    for (int i = 1; i <= n; i ++ ) 计算h[i]: h[i]的意思是, 前i个字符的hash值. 有种累加和的感觉. 其中"左侧"第一个字符str[1], 它是前1个字符 h[1]. 
					    {
					        h[i] = h[i - 1] * P + str[i]; 因为有 +法, 所以h[i]就是非零了
					        p[i] = p[i - 1] * P; 这个就可以记录我们的 p^(R-L+1) 
					    }

					    while (m -- )
					    {
					        int l1, r1, l2, r2;
					        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

					        if (get(l1, r1) == get(l2, r2)) puts("Yes");
					        else puts("No");
					    }

					    return 0;
					}
				3. 纯代码
					#include <iostream>
					#include <algorithm>

					using namespace std;

					typedef unsigned long long ULL;

					const int N = 100010, P = 131; 

					int n, m;
					char str[N];
					ULL h[N], p[N];

					ULL get(int l, int r)
					{
					    return h[r] - h[l - 1] * p[r - l + 1]; 
					}

					int main()
					{
					    scanf("%d%d", &n, &m);
					    scanf("%s", str + 1);

					    p[0] = 1;
					    for (int i = 1; i <= n; i ++ )
					    {
					        h[i] = h[i - 1] * P + str[i]; 
					        p[i] = p[i - 1] * P; 
					    }

					    while (m -- )
					    {
					        int l1, r1, l2, r2;
					        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

					        if (get(l1, r1) == get(l2, r2)) puts("Yes");
					        else puts("No");
					    }

					    return 0;
					}
				4. 复杂度
					我觉得: O(n), 因为预处理 h[i]是 O(n), 然后get函数是 O(1)
	3. 搜索和图论
		1. DFS
			1. AcWing 842. 排列数字
				1. 网址
				2. 代码{解析}
					0. 介绍: BFS/DFS
						BFS
							稳重,步步为营
							用queue,也就是一层一层的往里面放
							空间复杂度: O(指数级 2^h), 因为第h层会有2^h个元素
							可以应用于
								1. 最短路问题
									0. 背景
										包含了动态规划问题
										两者互通
										DP是特殊的最短路问题,是没有环的最短路问题

										没有权重的最短路问题用BFS做
										DP问题一般不会用最短路算法做,因为最短路算法的复杂度更高,DP算法低一些

									1. 分类
										1. 单源最短路
											边的权都是正数
												1. 朴素dikkstra
													O(n^2)
														n是节点个数
														时间复杂度和e边的个数无关
													稠密图的时候,e =接近= n^2, 所以用朴素dijkstra更好
												2. heap优化的dijkstra
													O(e*logn)
													适合稀疏图
													没有负权边用dijkstra,别用spfa(虽然能用),老师说的
														因为虽然spfa会快一点,但是最坏的情况下会比dijkstra慢,题目可能就会卡你,让spfa变成最坏的
														例如网格的图,会卡你
											存在负权边: 一般用spfa,不用bellman-ford
												1. bellman-ford
													O(n*e)
													基于离散数学
													可以求负权环但是一般不用这个来做,用spfa做
												2. spfa
													一般是 O(e), 最坏 O(n*e)
													spfa是限制最小的算法
														可以解决没有负权环的问题(99.9%的题目都是没有负权环的)
													spfa是对bellman-ford的优化
										2. 多源汇最短路
											floyd
												O(n^3)
												基于动态规划

								2. 拓扑序
									有向图有拓扑序,无向图没有
									有向无环图一定存在拓扑序列
									举例
										你要先干a,才能干b
									操作
										不断删除入度==0的节点,直到全部删完,如果还剩,说明这个图有环,没有拓扑序

						DFS
							执着,不撞南墙不死心
							用stack,将一条路径的元素装入stack,去下一条路径前,会先把当前的stack清空
							空间复杂度:O(h),因为只存了当前的路径的元素
							包括:
								回溯
								剪枝
					1.
						#include <iostream>

						using namespace std;

						const int N = 10;

						int n;
						int path[N]; 方案, 用全局数组. 

						void dfs(int u, int state) 
						{
						    if (u == n) 递归结束, 也就是当完美地走到第n个位置. 
						    {
						        for (int i = 0; i < n; i ++ ) printf("%d ", path[i]); 输出path就好了
						        	注意, path[i]只是代表了一个数字
						        	因为之前: path[u] = i + 1; 把数字{i+1}填到path的索引为u的位置上 
						        puts("");

						        return;
						    }

						    for (int i = 0; i < n; i ++ ) 
						        if (!(state >> i & 1)) 找到一个没有被用过的数字. 假设n==7, 那么state如果是 0010010, 其中0表示没有被用过的数字
						        {
						            path[u] = i + 1; 把数字{i+1}填到path的第u个位置上{也就是索引为u的位置上}
						            dfs(u + 1, state + (1 << i)); 然后去看第u+1个位置, 并且把state标记为{第i位已经用过了}
						        }
						        按道理说, 这里应该是执行完了上一句 "dfs(u + 1, state + (1 << i))" 恢复现场. 
						        但是奇妙就奇妙在: 
						        	老师的上一句: dfs(u + 1, state + (1 << i))中, state 可并不是: state = state + (1 << i))
									所以 state的值并没有被修改, 所以每一层的 state的值是互不影响的!
						        用同学的话:
						        	进入递归的数是 state+（1<<i）,也就是在第i位的状态变了，所以就是尽管在递归完成后没有语句恢复现场
						        	但是因为state这个数一直没有变化，所以在递归完成后其实跟递归之前状态一样呐
						}

						int main()
						{
						    scanf("%d", &n);

						    dfs(0, 0); 从第0个位置开始看, 刚开始state是全0也就是没有一个数字被用过

						    return 0;
						}
				3. 纯代码
					#include <iostream>

					using namespace std;

					const int N = 10;

					int n;
					int path[N]; 

					void dfs(int u, int state) 
					{
					    if (u == n)
					    {
					        for (int i = 0; i < n; i ++ ) printf("%d ", path[i]);
					        puts("");

					        return;
					    }

					    for (int i = 0; i < n; i ++ ) 
					        if (!(state >> i & 1)) 
					        {
					            path[u] = i + 1;
					            dfs(u + 1, state + (1 << i));
					        }
					}

					int main()
					{
					    scanf("%d", &n);

					    dfs(0, 0); 

					    return 0;
					}
				4. 复杂度
			2. AcWing 843. n-皇后问题: 经典dfs问题 
				1. 网址
				2. 代码{解析}
					1. 第一种搜索顺序
						是按照格子依次遍历:
							也就是: 
								第0行第0列, 第0行第1列, ..., 第0行第n-1列
								第1行第0列, 第1行第1列, ..., 第1行第n-1列
								第n-1行第0列, 第n-1行第1列, ..., 第n-1行第n-1列
						每个格子, 有两种操作:
							放皇后
							不放皇后
						#include <iostream>

						using namespace std;

						const int N = 10;

						int n;
						bool row[N], col[N], dg[N * 2], udg[N * 2];
						char g[N][N];

						void dfs(int x, int y, int s)
						{
						    if (s > n) return; 当前皇后的个数, 如果已经超过n了, 就返回. 这是保险写法. 
						    if (y == n) y = 0, x ++ ;
						    	如果出界{也就是到了第n-1列的下一列, 出界了}. 
						    	然后我们就转移到下一行{x++}的第一列{y=0}

						    if (x == n) 这个是到了第n行, 但是到了第n行并不代表摆够了n个皇后
						    {
						        if (s == n) 如果到了第n行, 并且摆好了n个皇后
						        {
						            for (int i = 0; i < n; i ++ ) puts(g[i]); 输出 
						            puts("");
						        }
						        return;
						    }

						    g[x][y] = '.'; 因为是一个一个格子遍历, 这里是每个格子无条件放置'.', 如果需要放皇后, 之后会修改为'Q'

						    如果不放皇后: 我们下一个去的是 第x行, 第y+1列. 已经摆好的皇后还是s个
						    	dfs(x, y + 1, s);

						    如果放皇后, 还是需要判断这个位置是否合法 
						    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) 这里说的是第x行是全0, 第y列全0, 对角线\全0, 斜对角线/全0 
						    {
						        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true; 说明放了皇后
						        g[x][y] = 'Q';
						        dfs(x, y + 1, s + 1); 我们下一个去的是 第x行, 第y+1列. 已经摆好的皇后还是s个

						        走到这里的时候, 已经是递归到底, 然后往回走了, 然后再从这个位置出发去下一个位置, 我们去下一个位置之前, 需要恢复现场:
						        g[x][y] = '.';
						        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
						    }
						}

						int main()
						{
						    cin >> n;

						    dfs(0, 0, 0); 去第0行, 第0列, 当前摆好的皇后数量是 0

						    return 0;
						}
					
					2. 第二种搜索顺序
						是按照格子依次遍历:
							也就是: 其实没变...
								第0行第0列, 第0行第1列, ..., 第0行第n-1列
								第1行第0列, 第1行第1列, ..., 第1行第n-1列
								第n-1行第0列, 第n-1行第1列, ..., 第n-1行第n-1列
						每个格子, 先判断是否满足要求, 然后操作:
							如果满足要求, 就放皇后
							如果不满足要求, 就不放皇后

						解释:
							为什么第x行, 第y列对应的左斜线 / 是: x + y
							为什么第x行, 第y列对应的右斜线 \ 是: "- x + y + n" 或者 "x - y + n"
								老师说: 只要保证不同对角线一定映射到不同的下标中即可，其他细节都不本质，很随意
								的确, 老师的两种方法, 一种写的是 "- x + y + n", 一种写的是 "x - y + n", 都ac了

						详解:
							1. 左斜线{对角线}:
									 0  1  2  3
									-------------
									|a |b1|c1|  |
								    -------------
								  /	|b2|c2|  |  |
								0	-------------
								  /	|c3|  |  |  |
								1	-------------
								  / |  |  |  |  |
								2	-------------
								  /   /   /   / 
								3    4   5   6
								就给你一个小例子:
									a, bb, ccc所在的是左斜线 /:
									其中, 左上角是第0行, 右下角是第2*(n-1)行==第6行
										所以取值范围是[0, 2*(n-1)]
									验证:
										a是左斜线的第0行. 
											a所在的是第x=0行, 第y=0列.
												x + y == 0 + 0 = 0
										b是左斜线的第1行. 
											b1所在的是第x=0行, 第y=1列.
												x + y == 0 + 1 = 1
											b2所在的是第x=1行, 第y=0列.
												x + y == 1 + 0 = 1
									原因:
										左斜线 /, 对应着我们的方程: y = -x + b 
											|----------> y
											|  /
											| /
											↓    y = -x + b
											x
										b就是我们说的, "第x行, 第y列, 对应的对角线是第b行"
										因为 y = -x + b , 所以 b = x+y 
										于是 b =  "x + y"

							2. 右斜线{斜对角线}:
								1. 左上角是第0行, 右下角是第2*(n-1)行==第6行

										 0  1  2  3
										-------------
									0	|  | c|b1| a|
										------------- \
									1	|  |  | c|b2|  0
										------------- \
									2	|  |  |  | c|  1
										------------- \
									3	|  |  |  |  |  2
										-------------
										  \   \   \   \ 
										   6   5   4   3
									就给你一个小例子:
										a, bb, ccc所在的是右斜线 \:
										其中, 左上角是第0行, 右下角是第2*(n-1)行==第6行
											所以取值范围是[0, 2*(n-1)]
										验证:
											a是右斜线的第0行. 
												a所在的是第x=0行, 第y=3列.
													n + x - y == 3 + 0 - 3 = 0
											b是右斜线的第1行. 
												b1所在的是第x=0行, 第y=2列.
													n + x - y == 3 + 0 - 2 = 1
												b2所在的是第x=1行, 第y=3列.
													n + x - y == 3 + 1 - 3 = 1
								2. 左下角是第0行, 右上角是第2*(n-1)行==第6行
									当然只要保证不同对角线一定映射到不同的下标中即可，其他细节都不本质，很随意。
										也可以是: 	
												 0  1  2  3
												-------------
											0	|  | c|b1| a|
												------------- \
											1	|  |  | c|b2|  6
												------------- \
											2	|  |  |  | c|  5
												------------- \
											3	|  |  |  |  |  4
												-------------
												  \   \   \   \ 
												   0   1   2   3
											就给你一个小例子:
												a, bb, ccc所在的是右斜线 \:
												其中, 左下角是第0行, 右上角是第2*(n-1)行==第6行
													所以取值范围是[0, 2*(n-1)]
												验证:
													a是右斜线的第6行. 
														a所在的是第x=0行, 第y=3列
															"n - x + y" == 3 - 0 + 3 = 6
													b是右斜线的第5行. 
														b1所在的是第x=0行, 第y=2列.
															n - x + y == 3 - 0 + 2 = 5
														b2所在的是第x=1行, 第y=3列.
															n - x + y == 3 - 1 + 3 = 5
												原因:
													右斜线 \, 对应着我们的方程: y = x + b

														|----------> y
														|  \
														|   \
														↓    \ y = x + b
														x
													b就是我们说的, "第x行, 第y列, 对应的斜对角线是第b行"
													因为 y = x + b , 所以 b = -x+y 
														因为x的取值是[0,n-1], 因为y的取值是[0,n-1]
														所以-x+y的取值是 [-(n-1), n-1] 可能有负数
														所以最后加一个n
													于是 b =  "n - x + y"
							

						#include <iostream>

						using namespace std;

						const int N = 20; 这里已经是比题目的范围大1倍了. 因为假设有n行, 那么对角线有2n行

						int n;
						char g[N][N]; 存的是第n行第n列是否有皇后
						bool col[N], dg[N], udg[N]; 

						void dfs(int u) 遍历第u行
						{
						    if (u == n) 说明遍历到底, 我们现在输出这个方案
						    {
						        for (int i = 0; i < n; i ++ ) puts(g[i]);
						        puts("");
						        return;
						    }

						    for (int i = 0; i < n; i ++ ) 从第u行的第1"列"开始遍历
						        剪枝: 不合理的点, 就不再继续往下遍历了
						    	if (!col[i] 第i列是全0 && !dg[u + i] 对角线也是全0 && !udg[n - u + i] 斜对角线也是全0)
						        {
						            g[u][i] = 'Q';
						            col[i] = dg[u + i] = udg[n - u + i] = true; 说明放了皇后
						            dfs(u + 1);遍历第u+1行

						            恢复现场
						            col[i] = dg[u + i] = udg[n - u + i] = false;
						            g[u][i] = '.';
						        }
						}

						int main()
						{
						    cin >> n;
						    for (int i = 0; i < n; i ++ )
						        for (int j = 0; j < n; j ++ )
						            g[i][j] = '.';

						    dfs(0);

						    return 0;
						}	
				3. 纯代码
					1.
						#include <iostream>

						using namespace std;

						const int N = 10;

						int n;
						bool row[N], col[N], dg[N * 2], udg[N * 2];
						char g[N][N];

						void dfs(int x, int y, int s)
						{
						    if (s > n) return; 
						    if (y == n) y = 0, x ++ ;
						    if (x == n) 
						    {
						        if (s == n)
						        {
						            for (int i = 0; i < n; i ++ ) puts(g[i]); 输出 
						            puts("");
						        }
						        return;
						    }

						    g[x][y] = '.'; 
						    dfs(x, y + 1, s);

						    if (!row[x] && !col[y] && !dg[x + y] && !udg[x - y + n]) 
						    {
						        row[x] = col[y] = dg[x + y] = udg[x - y + n] = true; 
						        g[x][y] = 'Q';
						        dfs(x, y + 1, s + 1); 
						        g[x][y] = '.';
						        row[x] = col[y] = dg[x + y] = udg[x - y + n] = false;
						    }
						}

						int main()
						{
						    cin >> n;

						    dfs(0, 0, 0); 

						    return 0;
						}
						
						2. 
							#include <iostream>

							using namespace std;

							const int N = 20;

							int n;
							char g[N][N]; 
							bool col[N], dg[N], udg[N]; 

							void dfs(int u) 
							{
							    if (u == n) 
							    {
							        for (int i = 0; i < n; i ++ ) puts(g[i]);
							        puts("");
							        return;
							    }

							    for (int i = 0; i < n; i ++ ) 
							    	if (!col[i] && !dg[u + i] && !udg[n - u + i])
							        {
							            g[u][i] = 'Q';
							            col[i] = dg[u + i] = udg[n - u + i] = true; 
							            dfs(u + 1);
							            col[i] = dg[u + i] = udg[n - u + i] = false;
							            g[u][i] = '.';
							        }
							}

							int main()
							{
							    cin >> n;
							    for (int i = 0; i < n; i ++ )
							        for (int j = 0; j < n; j ++ )
							            g[i][j] = '.';

							    dfs(0);

							    return 0;
							}	
				4. 复杂度
		2. BFS
			1. AcWing 844. 走迷宫
				1. 网址
				2. 代码{解析}
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <queue>

					using namespace std;

					typedef pair<int, int> PII;

					const int N = 110;

					int n, m;
					int g[N][N], d[N][N]; g:存的是地图, d: 每个点到起点的距离

					int bfs()
					{
					    queue<PII> q;  一个队列

					    memset(d, -1, sizeof d); 起点都是 0xfffffff, 也就是max
					    d[0][0] = 0; 起点到起点的距离是 0 
					    q.push({0, 0});

					    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

					    while (q.size()) 如果队列不为空
					    {
					        auto t = q.front(); 把队头拿出来
					        q.pop();

					        for (int i = 0; i < 4; i ++ )4个方向
					        {
					            int x = t.first + dx[i], y = t.second + dy[i];

					            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) 
					            	保证xy的坐标是合法的, g[x][y] == 0说明xy点是空地, d[x][y] == -1说明以前没有走过xy点
					            //如果已经搜到过了, d[x][y] != -1, 就不需要遍历了,因为我们找的就是最短距离. 
					            	//老师说: bfs第一次搜到的点才是最短距离，不是第一次就不是最短距离
					            	// 我的疑问:会不会以前搜到过, 但是后来走不通. 但是这次虽然再次搜到,可是这次走的通?
					            	//我认为可能再次搜到,也一样走不通,因为BFS本身就是一层一层的搜的
					            	//而且 d[x][y]只能越来越大, 因为越外层, d[aa][bb]的值就越大, 距离就越大
					            {
					                d[x][y] = d[t.first][t.second] + 1;
					                q.push({x, y});
					            }
					        }
					    }

					    return d[n - 1][m - 1];
					}

					int main()
					{
					    cin >> n >> m;
					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < m; j ++ )
					            cin >> g[i][j]; 把整个地图读进来

					    cout << bfs() << endl;

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <queue>

					using namespace std;

					typedef pair<int, int> PII;

					const int N = 110;

					int n, m;
					int g[N][N], d[N][N]; 

					int bfs()
					{
					    queue<PII> q; 

					    memset(d, -1, sizeof d); 
					    d[0][0] = 0; 
					    q.push({0, 0});

					    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

					    while (q.size()) 
					    {
					        auto t = q.front();
					        q.pop();

					        for (int i = 0; i < 4; i ++ )
					        {
					            int x = t.first + dx[i], y = t.second + dy[i];

					            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) 
					            {
					                d[x][y] = d[t.first][t.second] + 1;
					                q.push({x, y});
					            }
					        }
					    }

					    return d[n - 1][m - 1];
					}

					int main()
					{
					    cin >> n >> m;
					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < m; j ++ )
					            cin >> g[i][j]; 

					    cout << bfs() << endl;

					    return 0;
					}
				4. 复杂度
			2. AcWing 845. 八数码
				1. 网址
				2. 代码{解析}
					主要是 3*3矩阵中的坐标, 还有string中的坐标的转换:
						1. string -> 3*3: 
							int k = t.find('x'); 求一下, 'x'这个字符, 在状态{字符串}中的下标 
					        int x = k / 3, y = k % 3;
					    2. 3*3 -> string:
					    	x * 3 + y
					    	
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>
					#include <queue>

					using namespace std;

					int bfs(string state)
					{
					    queue<string> q;		bfs需要定义个队列
					    unordered_map<string, int> d; 	定义个距离数组

					    q.push(state); 起点放到队列 
					    d[state] = 0; 起点到起点的距离 == 0

					    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

					    string end = "12345678x"; 终点状态
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

					    return -1; 如果遍历不到, 说明到不了终点
					}

					int main()
					{
					    char s[2];

					    string state;
					    for (int i = 0; i < 9; i ++ )
					    {
					        cin >> s;
					        state += *s; 将9个字符读入. 后面读的字符是插入到string的右边
					        	state存的是初始状态
					    }

					    cout << bfs(state) << endl;

					    return 0;
					}
				3. 纯代码
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>
					#include <queue>

					using namespace std;

					int bfs(string state)
					{
					    queue<string> q;		
					    unordered_map<string, int> d; 	

					    q.push(state); 
					    d[state] = 0; 

					    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

					    string end = "12345678x"; 
					    while (q.size())
					    {
					        auto t = q.front();
					        q.pop();

					        if (t == end) return d[t]; 

					        int distance = d[t]; 
					        int k = t.find('x'); 
					        int x = k / 3, y = k % 3;	

					        for (int i = 0; i < 4; i ++ )
					        {
					            int a = x + dx[i], b = y + dy[i]; 
					            if (a >= 0 && a < 3 && b >= 0 && b < 3) 
					            {
					                swap(t[a * 3 + b], t[k]);
					                if (!d.count(t)) 
					                {
					                    d[t] = distance + 1; 
					                    q.push(t); 
					                }
					                swap(t[a * 3 + b], t[k]);
					            }
					        }
					    }

					    return -1; 
					}

					int main()
					{
					    char s[2];

					    string state;
					    for (int i = 0; i < 9; i ++ )
					    {
					        cin >> s;
					        state += *s;
					    }

					    cout << bfs(state) << endl;

					    return 0;
					}
				4. 复杂度
		3. 树与图的深度优先遍历	
			1. AcWing 846. 树的重心
				1. 网址
				2. 代码{解析}
					不管是dfs还是bfs, 都是每个点只遍历一次
					树的重心, 老师举了一个例子: https://www.acwing.com/video/278/ 的08:00
					我们要对于每一个节点, 计算删除这个节点之后, 剩下的所有连通块中, 最大的连通块的节点个数
						对于某个节点, 如何计算删除这个节点之后, 剩下的所有连通块中, 最大的连通块的节点个数?
							首先, 我们计算以这个节点为根的所有的子树的大小. 
								因为每个子树都是一个连通块
							对于这个节点上方的连通块的大小怎么计算?
								很简单:
									整个树的大小 - 1{节点自己} - 所有子树的大小
								不明白的话, 见 https://www.acwing.com/video/278/ 的10:55

					#include <cstdio>
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010, M = N * 2;

					int n;
					int h[N], e[M], ne[M], idx;
					int ans = N; 存全局的最大连通块中的点的数量
					bool st[N]; 某个点是否被遍历过 

					void add(int a, int b) 记录a节点的儿子节点b
					{
					    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
					}

					int dfs(int u) 计算了如果删除u节点会怎么样, 返回的是 节点个数: u节点+以u节点为根的所有子树的节点个数 {通俗的说就是u和u下面的所有点有多少个}
					{ 
					    st[u] = true; 标记一下, u点遍历过了

					    int size = 0, sum = 0; 
					    	size: 以u节点为根的所有子树中, 连通块最大的那一个块的点的数量 
					    	sum: dfs()要返回的值, 也就是 节点个数: u节点+以u节点为根的所有子树的节点个数 {通俗的说就是u和u下面的所有点有多少个}
					    for (int i = h[u]; i != -1; i = ne[i]) 遍历所有的儿子
					    {
					        int j = e[i];
					        if (st[j]) continue; 如果儿子遍历过了, 就下一个. 因为这个树, 其实也是一个图 

					        int s = dfs(j); 以儿子j为根的节点个数s {这个个数 包括了儿子j和j下面的所有节点}
					        size = max(size, s); 看看哪个儿子的块头最大
					        sum += s; 更新总的节点个数
					    }

					    size = max(size, n - sum - 1); 计算一下u上方的节点个数. 因为 sum是不包括节点u的, 所以还要-1

					    ans = min(ans, size);  对于每个u都对应了一个最大连通块, 在所有的最大连通块中, 我们需要的最小的那M个

					    return sum + 1; sum是不包括节点u的, 所以还要+1
					}

					int main()
					{
					    scanf("%d", &n);

					    memset(h, -1, sizeof h); 初始化链表 

					    for (int i = 0; i < n - 1; i ++ )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);
					        add(a, b), add(b, a); 双向的 
					    }

					    dfs(1); 从节点1开始遍历

					    printf("%d\n", ans);

					    return 0;
					}
				3. 纯代码
					#include <cstdio>
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010, M = N * 2;

					int n;
					int h[N], e[M], ne[M], idx;
					int ans = N; 
					bool st[N]; 

					void add(int a, int b) 
					{
					    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
					}

					int dfs(int u) 
					{ 
					    st[u] = true; 

					    int size = 0, sum = 0; 
					    for (int i = h[u]; i != -1; i = ne[i]) 
					    {
					        int j = e[i];
					        if (st[j]) continue;

					        int s = dfs(j); 
					        size = max(size, s);
					        sum += s;
					    }

					    size = max(size, n - sum - 1); 
					    ans = min(ans, size);
					    return sum + 1; 
					}

					int main()
					{
					    scanf("%d", &n);

					    memset(h, -1, sizeof h); 

					    for (int i = 0; i < n - 1; i ++ )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);
					        add(a, b), add(b, a); 
					    }

					    dfs(1); 

					    printf("%d\n", ans);

					    return 0;
					}
				4. 复杂度
		4. 树与图的广度优先遍历	
			1. AcWing 847. 图中点的层次
				1. 网址
				2. 代码{解析}
					#include <cstdio>
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <queue>

					using namespace std;

					const int N = 100010;

					int n, m;
					int h[N], e[N], ne[N], idx;
					int d[N];

					void add(int a, int b)
					{
					    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
					}

					int bfs()
					{
					    memset(d, -1, sizeof d);

					    queue<int> q;
					    d[1] = 0; 只有index==1的点被遍历, 它距离1号点{自己}的距离是0
					    q.push(1);

					    while (q.size())
					    {
					        int t = q.front(); 队头 
					        q.pop();

					        for (int i = h[t]; i != -1; i = ne[i]) 遍历这个点的可以到的点 
					        {
					            int j = e[i];
					            if (d[j] == -1) 如果这个点j没有被遍历过 
					            {
					                d[j] = d[t] + 1; 距离
					                q.push(j);
					            }
					        }
					    }

					    return d[n]; 我们返回的是 n号点距离1号点的距离 
					}

					int main()
					{
					    scanf("%d%d", &n, &m);
					    memset(h, -1, sizeof h);

					    for (int i = 0; i < m; i ++ )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);
					        add(a, b);
					    }

					    cout << bfs() << endl;

					    return 0;
					}
				3. 纯代码
					#include <cstdio>
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <queue>

					using namespace std;

					const int N = 100010;

					int n, m;
					int h[N], e[N], ne[N], idx;
					int d[N];

					void add(int a, int b)
					{
					    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
					}

					int bfs()
					{
					    memset(d, -1, sizeof d);

					    queue<int> q;
					    d[1] = 0;
					    q.push(1);

					    while (q.size())
					    {
					        int t = q.front(); 
					        q.pop();

					        for (int i = h[t]; i != -1; i = ne[i]) 
					        {
					            int j = e[i];
					            if (d[j] == -1) 
					            {
					                d[j] = d[t] + 1; 
					                q.push(j);
					            }
					        }
					    }

					    return d[n]; 
					}

					int main()
					{
					    scanf("%d%d", &n, &m);
					    memset(h, -1, sizeof h);

					    for (int i = 0; i < m; i ++ )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);
					        add(a, b);
					    }

					    cout << bfs() << endl;

					    return 0;
					}
				4. 复杂度
		5. 拓扑排序
			1. AcWing 848. 有向图的拓扑序列
				1. 网址
				2. 代码{解析}
					#include <cstring>
						#include <iostream>
						#include <algorithm>

						using namespace std;

						const int N = 100010;

						int n, m;
						int h[N], e[N], ne[N], idx;
						int d[N];
						int q[N];

						void add(int a, int b)
						{
						    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
						}

						bool topsort()
						{
						    int hh = 0, tt = -1;  含义: [hh,tt]区间是有元素的.
						    	对比之前其他queue的代码:
						    		int hh = 0, tt = 0; 这里之所以 tt = 0, 是因为我们已经即将加入一个 q[0]. 
						    							也就是 [hh,tt]即[0,0]区间是有元素的.
								    q[0] = root;

								    while (hh <= tt)
								    {
								        int t = q[hh ++ ];
								        if (l.count(t)) q[ ++ tt] = l[t];
								        if (r.count(t)) q[ ++ tt] = r[t];
								    }
								对比完毕

						    for (int i = 1; i <= n; i ++ ) 遍历所有的点 
						        if (!d[i]) 如果这个点的入度 == 0:
						            q[ ++ tt] = i; 就插入我们的队列 

						    while (hh <= tt) 如果队列不空 
						    {
						        int t = q[hh ++ ]; 取队头, 也就是某一个入度 == 0的点t

						        for (int i = h[t]; i != -1; i = ne[i])  这个点t可以去的点j
						        {
						            int j = e[i];
						            if (-- d[j] == 0) 我们把点j的入度 先-1, 如果==0, 就放入我们的queue
						                q[ ++ tt] = j;
						        }
						    }

						    return tt == n - 1; 如果最后发现有n个元素进了queue,说明是有向无环图.否则说明有环
						    	我的解释: 
						    		加入说有一个环. 那么这个环里面的所有点, 每个点的入度就不可能是0
						    		a -> b -> c 
						    		↑---------|
						    		每个点的入度都是1, 而且永远是1. 
						    		加入queue的元素入度都是0, 所以存在有某些点没有进入queue,说明入度不是1,说明有环,没有拓扑序
						}

						int main()
						{
						    scanf("%d%d", &n, &m);

						    memset(h, -1, sizeof h);

						    for (int i = 0; i < m; i ++ )
						    {
						        int a, b;
						        scanf("%d%d", &a, &b);
						        add(a, b);

						        d[b] ++ ; //b的入度+1
						    }

						    if (!topsort()) puts("-1");
						    else
						    {
						        for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);
						        puts("");
						    }

						    return 0;
						}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010;

					int n, m;
					int h[N], e[N], ne[N], idx;
					int d[N];
					int q[N];

					void add(int a, int b)
					{
					    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
					}

					bool topsort()
					{
					    int hh = 0, tt = -1;

					    for (int i = 1; i <= n; i ++ )
					        if (!d[i])
					            q[ ++ tt] = i;

					    while (hh <= tt)
					    {
					        int t = q[hh ++ ];

					        for (int i = h[t]; i != -1; i = ne[i])
					        {
					            int j = e[i];
					            if (-- d[j] == 0)
					                q[ ++ tt] = j;
					        }
					    }

					    return tt == n - 1; //如果最后发现有n个元素进了queue,说明是有向无环图.否则说明有环
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    memset(h, -1, sizeof h);

					    for (int i = 0; i < m; i ++ )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);
					        add(a, b);

					        d[b] ++ ; //b的入度+1
					    }

					    if (!topsort()) puts("-1");
					    else
					    {
					        for (int i = 0; i < n; i ++ ) printf("%d ", q[i]);
					        puts("");
					    }

					    return 0;
					}
				4. 复杂度
		6. Dijkstra
			1. AcWing 849. Dijkstra求最短路 I
				1. 网址
				2. 代码{解析}
					图的表示:
						0. 
							无向图(相互指着的有向图), 有向图(一般化)
							树(没环的图), 图(一般化)
						1. 邻接矩阵
							不能存重复遍,自环边
							空间复杂度(n^2)
							少用,适合稠密图
						2. 邻接表: 常用
							单链表实现,使用了拉链法
							举例
								1: 4,5,6
								2: 6,4
								4: 1...
								...
					总结:
						1. 最短距离:
							d[N][N], dist[N]
						2. 最大点权:
							w[N], weight[j] = weight[t] + w[j];
						3. 最小花费 相当于最短距离
							c[N][N], cost[N]
						4. 经过节点的数量:
							cnt[N]
								cnt[j] = cnt[t] + 1;
						5. 最短距离的路径的个数:
							amt[N]
								amt[j] = amt[t]: 还沿着这条路走
								amt[j] += amt[t]: 多个路径合并
						6. 记录路径:
							pre[j] = t
					Dijkstra:
						0. 
							1. d[][], 两个点之间的距离, 题目给的
							2. dist[], 某个点到起点的最短距离
							3. st[], 某个点是否计算/放松过它所有的临边
						1. for() 有n个点, 所以放松n次
							{
								for(){} 遍历n个点, 找到没有计算过dist[], 并且距离起点最近的点, 这个点是t

								for(){} 遍历n个点, 放松点t的所有临边, 并且给这些更新dist[邻点]

								st[t] = true; 说明已经计算/放松点t的所有临边
							}
						5. dijkstra():
							1. 在所有的点中, 找一个合适的灵魂
							2. 用这个灵魂, 更新其他的点
						6. 初始需要的
							const int N = 1010;
							int n, m, S, T;			点边等
							int w[N], d[N][N];				input的值: 权重, 距离
							int dist[N], cnt[N], sum[N];	我们加工的: 最短距离, 最短路条数, 最大权值
							bool st[N];						dijkstra过程用到的

					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 510; 500个点, 10w条边, 所以是"稠密图", 用"邻接矩阵"来写

					int n, m;
					int g[N][N];
					int dist[N];
					bool st[N];

					int dijkstra()
					{
					    memset(dist, 0x3f, sizeof dist); 到起点的距离是正无穷
					    dist[1] = 0; 点1到起点{也是1}的距离是0 

					    for (int i = 0; i < n - 1; i ++ )
					    {
					        int t = -1; 没有灵魂的躯壳
					        for (int j = 1; j <= n; j ++ ) 对于所有的点 
					            if (!st[j] && (t == -1 || dist[t] > dist[j])) 如果这个点没有被遍历过. 如果躯壳没有灵魂 或者 有灵魂且但是灵魂不优
					                t = j;	我们选择更优秀的灵魂 
					        if(t == n) break; 因为题目要求的就是1到N的最短距离, 好的, 因为 dist[t]已经是存的到起点的最小值了, 所以就结束返回 
					        for (int j = 1; j <= n; j ++ ) 用这个点, 放松所有的其他点 j
					            dist[j] = min(dist[j], dist[t] + g[t][j]);

					        st[t] = true; 因为t是当前距离最小的,所以t节点的最短距离确定了
					        	将t点做标记, 说明已经遍历过了

					    }

					    if (dist[n] == 0x3f3f3f3f) return -1; 如果起点到达不了n号节点，则返回-1
					    return dist[n];
					}

					int main()
					{
					    scanf("%d%d", &n, &m); 

					    memset(g, 0x3f, sizeof g); 其他距离是正无穷 
					    while (m -- )
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);

					        g[a][b] = min(g[a][b], c); 是有向边, 对于同一条边, 存的是距离最短的那个
					    }

					    printf("%d\n", dijkstra());

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 510; 

					int n, m;
					int g[N][N];
					int dist[N];
					bool st[N];

					int dijkstra()
					{
					    memset(dist, 0x3f, sizeof dist); 
					    dist[1] = 0; 

					    for (int i = 0; i < n - 1; i ++ )
					    {
					        int t = -1; 
					        for (int j = 1; j <= n; j ++ ) 
					            if (!st[j] && (t == -1 || dist[t] > dist[j])) 
					                t = j;
					        if(t == n) break;
					        for (int j = 1; j <= n; j ++ )
					            dist[j] = min(dist[j], dist[t] + g[t][j]);

					        st[t] = true;
					    }

					    if (dist[n] == 0x3f3f3f3f) return -1;
					    return dist[n];
					}

					int main()
					{
					    scanf("%d%d", &n, &m); 

					    memset(g, 0x3f, sizeof g);
					    while (m -- )
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);

					        g[a][b] = min(g[a][b], c); 
					    }

					    printf("%d\n", dijkstra());

					    return 0;
					}
				4. 复杂度
					有向图的最短路问题的复杂度总结:
						1. 单源
							1. 边都是正数{更严谨的说, 是非负数, 边权>=0}
								1 "稠密图": 朴素版 Dijkstra + 邻接矩阵 
									时间复杂度 O(n^2)
									证明:
										for (int i = 0; i < n; i++) { -> 一个 for
										    int t = -1;
										    for (int j = 1; j <= n; j++) { -> 一个 for, O(n) * O(n) -> O(n^2)
										        if (!st[j] && (t == -1 || dist[j] < dist[t]))
										            t = j; 
										    }
										    st[t] = true; 					->  O(n) * O(1) -> O(n)
										    for (int j = 1; j <= n; j++) { -> 一个 for, O(n) * O(n) -> O(n^2)
										        dist[j] = min(dist[j], dist[t] + g[t][j]); -> 注意这里是遍历邻接表的第t行的所有元素 g[t][j]
										    }
										}
									适用于:
										"稠密图", 因为稠密图本身就要计算e条边, 而e就约等于n^2
										既然打日本{稠密图},就用消耗资源的原子弹{朴素版 Dijkstra}
									补充:
										稠密图: 用邻接矩阵
										稀疏图: 用邻接表
								2 "稀疏图": 堆优化版 Dijkstra + 邻接表 
									时间复杂度 O(e*loge) / O(e*logn)
									证明:
										这里没有for了, 是while, 我们需要按照逻辑来, 看heap最后会存多少, st最后会存多少
										while (heap.size()) { heap中到最后会存e条边
										    auto t = heap.top(); //O(e) * O(1) -> O(e) heap中到最后会存e条边, 每条边都pop一次, 所以是 O(e)
										    heap.pop();
										    int ver = t.second, distance = t.first;
										    if (st[ver])continue;
										    st[ver] = true;  //O(n) * O(1) -> O(n)  最后st是每个点都记录一次, 所以是O(n)
										    for (int i = h[ver]; i != -1; i = ne[i]) { 这个for, 其实要做的是, 对于每一个边{不是点}都遍历一次 
										        int j = e[i]; 这里会遍历以{i,j}为端点的边, 也就是所有的边, 一共e条
										        if (dist[j] > distance + w[i]) { 假设每个边都满足这个if条件, 
										        								堆的插入操作时间复杂度是 O(loge){因为 priority_queue是树, 树有e个节点, 所以有 loge层}, 
										        								因为for是对于每个边都遍历一次, 所以有
										        								{每个边 * 一个插入操作} = O(e) * O(loge) -> O(e*loge) -因为 loge 和 logn 是一个级别, 所以习惯写为-> O(e*logn)
										            dist[j] = distance + w[i];
										            heap.push({dist[j], j}); 
										        }
										    }
										}
									适用于:
										"稀疏图", 邻接表 
										打蚊子不需要用原子弹
							2. 有负权边 
								1. bellman-ford
									时间复杂度 O(n*e)
									证明:
										for (int i = 0; i < k; i ++ )
									    {
									        memcpy(last, dist, sizeof dist); 
									        for (int j = 0; j < m; j ++ )
									        {
									            auto e = edges[j];
									            dist[e.b] = min(dist[e.b], last[e.a] + e.c);
									        }
									    }
									    也就是:
											for (...) 迭代k次, 就意味着走的边数, 最多不超过k条边
										    {
										        memcpy(); 备份上一轮 
										        for (...) 上一个for是迭代k次, 对于每次, 都要放松所有e条边, 也就是遍历edge数组里面的所有边 
										    }
										复杂度: O(n*e)
											迭代k次, 每次都要放松所有e条边, 也就是遍历edge数组里面的所有边 
											我能理解 e, 可是为什么不是 O(k*e)? 你就背下来吧: 就是 O(点数n*边数e)

								2. spfa: 用 priority_queue 对 bellman-ford的瓶颈做了优化
									时间复杂度 一般是 O(e), 最坏 O(n*e)
									证明: 
										while (q.size())
									    {
									        int t = q.front(); 
									        q.pop();
									        st[t] = false; 

									        for (int i = h[t]; i != -1; i = ne[i]) 
									        	相当于采用了"BFS"，因此"遍历到的结点都是与源点连通的", 回忆树问题中bfs的每个边只走一次
									        	所以如果图也是没有环的话, 就像树一样, 所以也是遍历所有的边一次, 所以是 O(e)
									        {
									            int j = e[i];
									            if (dist[t] + w[i] < dist[j])
									            {
									                dist[j] = dist[t] + w[i]; 
									                if (!st[j]) 
									                {
									                    q.push(j);
									                    st[j] = true;
									                }
									            }
									        }
									    }
									适用于:
										老师说, 对于很多正权边的问题. 老师一般不用 dijkstra算法, 而是用spfa, 因为更快
										所以spfa不仅仅解决负权, 也可以解决正权边问题
						2. 多源 
							floyd
								时间复杂度 O(n^3)
								证明: 很简单
									void floyd()
									{
									    for (int k = 1; k <= n; k ++ )
									        for (int i = 1; i <= n; i ++ )
									            for (int j = 1; j <= n; j ++ )
									                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
									}
								适用于: 就是求多源的, 给你任意两个点ij, 问最近距离
			2. AcWing 850. Dijkstra求最短路 II
				1. 网址
				2. 代码{解析}
					0. 堆优化: 应用于稀疏图, 也就是点数 约等于 边数
					1. 朴素版本的瓶颈:
						1. 找最好的灵魂这一步, 复杂度是 O(n^2), 因为有两个嵌套的for loop
							优化: 因为只是找最小值, 所以用 priority_queue 找最短dist的t节点
								priority_queue "返回"最小值, 只需要 O(1)
								因为我们有个 while, priority_queue里面存了e条边, 
									这一步变成 O(e) * O(1)
						2. 但是往 priority_queue 里面"插入"元素, 一次插入操作的复杂度是 O(loge)
							我们自己实现堆, 因为我们会实现删除操作, 所以堆里只有n个点
								则插入操作是 O(logn), 解释: 因为 priority_queue是树, 树有n个节点, 树有 logn层
							但是我们不是自己实现堆, 而是用 priority_queue, 所以不能实现删除点, 所以最后堆里面是 e个邻边 
								所以 插入操作是 O(loge), 解释: 因为 priority_queue是树, 树有e个节点, e > n, 所以有 loge层
								但是! loge 和 logn 是一个级别,因为 e <= n^2, loge <= logn^2, loge <= 2logn, 也就是 loge比logn稍微大一点
						3. 最后, 需要多少次插入操作?
							因为 priority_queue 有e条边, 每个边都有一次插入操作 
							所以复杂度是: {每个边 * 一个插入操作} = O(e) * O(loge) -> O(e*loge) -因为 loge 和 logn 是一个级别, 所以习惯写为-> O(e*logn)

					3. 最后的复杂度:
						本应该是: O(e*loge)
						但是我们一般说成: O(e*logn)

					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <queue> //用到优先队列

					using namespace std;

					typedef pair<int, int> PII; 距离起点的最短距离int, 该节点的编号int

					const int N = 1e6 + 10;

					int n, m;
					int h[N], w[N], e[N], ne[N], idx; 因为是稀疏图,所以用邻接表, 代替之前的邻接矩阵g[N][N]
					int dist[N];
					bool st[N];

					void add(int a, int b, int c) //不怕平行边,因为我们每次都是取最短距离的节点
					{
					    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
					}

					int dijkstra()
					{
					    memset(dist, 0x3f, sizeof dist);
					    dist[1] = 0;
					    priority_queue<PII, vector<PII>, greater<PII>> heap; //最小堆
					    heap.push({0, 1}); 距离1节点的距离是0, 这个节点是1节点. 因为priority_queue是按照第一个关键字排的

					    while (heap.size()) 特别像宽搜, 因为最多遍历m条边, 所以heap最多只有m条边加入 
					    {
					        auto t = heap.top();//取出dist最小的节点
					        heap.pop();

					        int ver = t.second, distance = t.first;

					        if (st[ver]) continue; //加入这个ver节点已经求出了正确值,就看下一个
					        st[ver] = true;

					        for (int i = h[ver]; i != -1; i = ne[i]) //遍历ver节点的所有临边,这个临边的ind == i
					        {
					            int j = e[i];//j是ver的临边, 也就是以{ver, j}为端点的是一条边
					            if (dist[ver] + w[i] < dist[j])//w[i]的意思是, ver和j之间的距离. 如果我们能放松{也就是 从起点到ver再从ver到j的距离 小于 从起点到j的距离}
					            {
					                dist[j] = dist[ver] + w[i];
					                heap.push({dist[j], j});
					            }
					        }
					    }

					    if (dist[n] == 0x3f3f3f3f) return -1;
					    return dist[n];
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    memset(h, -1, sizeof h); //初始化链接表
					    while (m -- )
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);
					        add(a, b, c);
					    }

					    cout << dijkstra() << endl;

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <queue> //用到优先队列

					using namespace std;

					typedef pair<int, int> PII; 

					const int N = 1e6 + 10;

					int n, m;
					int h[N], w[N], e[N], ne[N], idx; 
					int dist[N];
					bool st[N];

					void add(int a, int b, int c)
					{
					    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
					}

					int dijkstra()
					{
					    memset(dist, 0x3f, sizeof dist);
					    dist[1] = 0;
					    priority_queue<PII, vector<PII>, greater<PII>> heap; 
					    heap.push({0, 1}); 

					    while (heap.size()) 
					    {
					        auto t = heap.top();
					        heap.pop();

					        int ver = t.second, distance = t.first;

					        if (st[ver]) continue; 
					        st[ver] = true;

					        for (int i = h[ver]; i != -1; i = ne[i]) 
					        {
					            int j = e[i];
					            if (dist[j] > dist[ver] + w[i])
					            {
					                dist[j] = dist[ver] + w[i];
					                heap.push({dist[j], j});
					            }
					        }
					    }

					    if (dist[n] == 0x3f3f3f3f) return -1;
					    return dist[n];
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    memset(h, -1, sizeof h);
					    while (m -- )
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);
					        add(a, b, c);
					    }

					    cout << dijkstra() << endl;

					    return 0;
					}
				4. 复杂度
		7. bellman-ford
			1. AcWing 853. 有边数限制的最短路
				1. 网址
				2. 代码{解析}
					这道题只能用bellman-ford,因为题目有边数限制, 所以即便有负权环,也不能无限次转
					逻辑:
						for (...) 迭代k次, 就意味着走的边数, 最多不超过k条边
					    {
					        memcpy(); 备份上一轮 
					        for (...) 上一个for是迭代k次, 对于每次, 都要放松所有e条边, 也就是遍历edge数组里面的所有边 
					    }
					复杂度: O(e*n) 
						迭代k次, 每次都要放松所有e条边, 也就是遍历edge数组里面的所有边 
						我能理解 e, 可是为什么不是 O(e*k)? 你就背下来吧: 就是 O(边数*点数)

					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 510, M = 10010;

					struct Edge
					{
					    int a, b, w; //a,b起点终点, c权重
					}edges[M]; 这是一个结构体数组 

					int n, m, k;
					int dist[N];
					int last[N]; 备份上一轮, 必须要加

					void bellman_ford()
					{
					    memset(dist, 0x3f, sizeof dist); 从1号点到n号点的最多经过k条边的最短距离存入 dist

					    dist[1] = 0; 从1号点到1号点距离是0

					    for (int i = 0; i < k; i ++ ) 迭代k次, 就意味着走的边数, 最多不超过k条边 //题目要求:不超过k条边
					    {
					        memcpy(last, dist, sizeof dist); 
					        	//不备份会导致串联, 例如老师给的样例, 正确答案是3. 因为只能走k==1条边. 
					        	//如果没有备份,会导致,先用最短距离的节点2去更新其他所有的点,导致节点3的最短距离变成了2,但是实际上是3
					        	//https://www.acwing.com/video/285/ 的16:50

					        //用上次迭代的距离,更新这次节点的dist.
					        /*理解了,样例是:点1到点2是1,点2到点3是1,点1到点3是3.只能走1条边, 问点1到点3的最短距离是多少.
					        	答案是3, 因为只能走一条边
					        没有备份:
					            1 2  3
					            0 3f 3f 
					            0 1  2 -->--> 因为用的是之这一轮的2节点的1, min(3f, 1+1) = 2, 但不应该是2
					        有备份
					            1 2  3
					            0 3f 3f --> 这个是上一轮的dist, 把这个信息存到 last中. 所以last里面是 [0, 3f, 3f]
					            0 1  3f --> 因为用的是上一轮的2节点的3f, min(3f, 3f+1) = 3f
					        */
					        for (int j = 0; j < m; j ++ ) //每次放松m个边
					        {
					            auto e = edges[j];
					            dist[e.b] = min(dist[e.b], last[e.a] + e.w);
					            	错误写法: 不用备份, 如下: 
					            		if(dist[e.a] + e.w < dist[e.b])
					            			dist[e.b] = dist[e.a] + e.w;
					            		这让我想起了dp中, 滚动数组优化中, 我们从右往左遍历是为了让左侧的值是上一轮的老值
					            		这里的上一轮的老值, 不见得都在左侧, 所以干脆把所有老值都备份到 last
					        }
					    }
					}

					int main()
					{
					    scanf("%d%d%d", &n, &m, &k);

					    for (int i = 0; i < m; i ++ ) 读m条边 
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);
					        edges[i] = {a, b, c}; 读入 
					    }

					    bellman_ford();

					    /*
					    为什么写成dist[n] > 0x3f3f3f3f / 2, 而不是dist[n] == 0x3f3f3f3f
					    	因为存在负权边
					    		回忆之前的都是正权边:
					    			dist[b] = min(0x3f3f3f3f, 0x3f3f3f3f + 5) 
					    			所以 dist[b]会一直保持 0x3f3f3f3f
					    			所以你判断 if(dist[n] == 0x3f3f3f3f) puts("impossible");这么写是ok的
								但是现在:
								    假设节点a到节点b的距离是-5, 但是dist[a] == disk[b] == 0x3f3f3f3f
								    假设节点a会更新节点b, 那么dist[b] = min(0x3f3f3f3f, 0x3f3f3f3f - 5) =  0x3f3f3f3f - 5
								    所以最后dist[b]会比正无穷小一点: 0x3f3f3f3f - 5
					   				但是不会小很多, 因为题目说了边的绝对值<1万, 有500次操作, 所以最多比正无穷小500万, 所以我们用/2判断
					    */
					    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
					    else printf("%d\n", dist[n]);

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 510, M = 10010;

					struct Edge
					{
					    int a, b, c; //a,b起点终点, c权重
					}edges[M];

					int n, m, k;
					int dist[N];
					int last[N];

					void bellman_ford()
					{
					    memset(dist, 0x3f, sizeof dist);

					    dist[1] = 0;
					    for (int i = 0; i < k; i ++ )
					    {
					        memcpy(last, dist, sizeof dist); 
					        for (int j = 0; j < m; j ++ )
					        {
					            auto e = edges[j];
					            dist[e.b] = min(dist[e.b], last[e.a] + e.c);
					        }
					    }
					}

					int main()
					{
					    scanf("%d%d%d", &n, &m, &k);

					    for (int i = 0; i < m; i ++ )
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);
					        edges[i] = {a, b, c};
					    }

					    bellman_ford();
					    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
					    else printf("%d\n", dist[n]);

					    return 0;
					}
				4. 复杂度
		8. spfa
			1. AcWing 851. spfa求最短路
				1. 网址
				2. 代码{解析}
					1. spfa是对bellman-ford的优化
					    bellman-ford中存在一句话:
					    dist[b] = min(dist[b], last[a] + w)
					    	1. 所以如果dist[b]减少, 一定是因为last[a]减少
					   		2. 所以我们可以发现:
					   			如果last[a]距离变小,它"可能"会使它的邻接点例如b的距离变小
					   			如果last[a]距离不变,它就"完全不可能"使得邻接点例如b的距离变小
					    所以我们存储dist"变小"的节点
					2. 用queue{其实用heap也可以}存所有dist"变小"的节点abc
					3. 并且更新这个节点abc的邻接点
					其他细节:
						对比Bellman_ford算法:
							1. Bellman_ford
								1. 会遍历所有的边，但是有很多的边遍历了其实没有什么意义
								2. 最后的判断条件写的是 if(dist[n] > 0x3f3f3f3f / 2)
								3. Bellman_ford算法可以存在负权回路，是因为其循环的次数是有限制的因此最终不会发生死循环；
							2. spfa:
								1.
									我们只用遍历那些到源点距离变小的点所连接的边即可
									只有当一个点的前驱结点更新了，该节点才会得到更新
									因此考虑到这一点，我们将创建一个队列每一次加入距离被更新的结点
								2. 最后的判断条件写的是 if(dist[n] == 0x3f3f3f3f)
									原因:
										其原因在于Bellman_ford算法会遍历所有的边，因此"不管是不是和源点连通"的边它都会得到更新；
										但是SPFA算法不一样，它相当于采用了"BFS"，因此"遍历到的结点都是与源点连通的"
											因此如果你要求的n和源点不连通，它不会得到更新，还是保持的0x3f3f3f3f
											回忆: 
												BFS中的st数组记录的是当前已经被遍历过的点
												spfa中的st数组判断当前的点是否已经加入到队列当中了, 也就是是否距离更短了
								3. SPFA算法不可以存在负权回路，由于用了队列来存储，只要发生了更新就会不断的入队
									因此假如有负权回路请你不要用SPFA否则会死循环。
									当然你如果用一个cnt来判断是否有负环也是可以的, 就不会死循环了
								4. 由于SPFA算法是由Bellman_ford算法优化而来，在最坏的情况下时间复杂度和它一样即时间复杂度为 O(nm) 
									假如题目时间允许可以直接用SPFA算法去解Dijkstra算法的题目。(好像SPFA有点小小万能的感觉...)
								5. 求负环一般使用SPFA算法，方法是用一个cnt数组记录每个点到源点的边数，一个点被更新一次就+1
									一旦有点的边数达到了n那就证明存在了负环
						对比Dijstra算法: 虽然有一些像但是其中的意义还是相差甚远的
							1. Dijkstra算法
								1. st
									st数组保存的是当前确定了到源点距离最小的点
									且一旦确定了最小那么就不可逆了: 不可标记为true后改变为false
								2. priority_queue
									Dijkstra算法里使用的是优先队列保存的是当前未确定最小距离的点
									目的是"快速的"取出当前到源点"距离最小"的点；
							2. SPFA算法
								1. st
									st数组判断当前的点是否已经加入到队列当中了；
									且spfa中的st数组可逆: 可以在标记为true之后又标记为false
									即便不使用st数组最终也没有什么关系，但是使用的好处在于可以提升效率。
								2. priority_queue
									目的只是记录一下当前"距离变小"的点
									SPFA算法中使用的是队列{你也可以使用别的数据结构}

					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <queue>

					using namespace std;

					const int N = 100010;

					int n, m;
					int h[N], w[N], e[N], ne[N], idx;
					int dist[N];
					bool st[N]; //感觉这个的语意是: 某个节点是否在queue里面

					void add(int a, int b, int c)
					{
					    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
					}

					int spfa()
					{
					    memset(dist, 0x3f, sizeof dist);
					    dist[1] = 0;

					    queue<int> q; 记录所有距离变小的节点 
					    q.push(1); 把起点1放入队列 
					    st[1] = true; 说明节点1在queue里面

					    while (q.size()) 只要队列不空, 队列里面是所有到起点的距离"变小"的节点, 所以队列不空说明还有距离变小的节点
					    {
					        int t = q.front(); 取出队头t
					        q.pop();

					        st[t] = false; 因为从queue取出点t, 说明现在queue里面没有节点t

					        for (int i = h[t]; i != -1; i = ne[i]) 遍历点t的邻接点
					        										因为t是变小的点, 那t节点的邻接点就"有可能"可以变小{到原点的距离变小}
					        										这个也验证了, 如果是一个到原点距离没变的点, 它的邻接点就"完全没可能"变小
					        {
					            int j = e[i];
					            if (dist[t] + w[i] < dist[j])
					            {
					                dist[j] = dist[t] + w[i]; 不管点j在不在queue里面{也就是不管st[j]是true还是false}, 我们都会更新j到起点的距离dist[j]
					                if (!st[j]) 如果不在queue里面,就放入. 如果这个点j本身就在queue,那以后会在queue中取出它的. 
					                {
					                    q.push(j);
					                    st[j] = true;
					                }
					            }
					        }
					    }

					    return dist[n]; 返回的就是节点n到节点1的最短距离 
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    memset(h, -1, sizeof h);

					    while (m -- )
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);
					        add(a, b, c);
					    }

					    int t = spfa();

					    if (t == 0x3f3f3f3f) puts("impossible");
					    	 为什么不是 if(dist[n] > 0x3f3f3f3f / 2)
								原因:
									其原因在于Bellman_ford算法会遍历所有的边，因此"不管是不是和源点连通"的边它都会得到更新；
									但是SPFA算法不一样，它相当于采用了"BFS"，因此"遍历到的结点都是与源点连通的"
										因此如果你要求的n和源点不连通，它不会得到更新，还是保持的0x3f3f3f3f
					    else printf("%d\n", t);

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <queue>

					using namespace std;

					const int N = 100010;

					int n, m;
					int h[N], w[N], e[N], ne[N], idx;
					int dist[N];
					bool st[N]; 

					void add(int a, int b, int c)
					{
					    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
					}

					int spfa()
					{
					    memset(dist, 0x3f, sizeof dist);
					    dist[1] = 0;

					    queue<int> q;
					    q.push(1); 
					    st[1] = true;

					    while (q.size()) 
					    {
					        int t = q.front();
					        q.pop();

					        st[t] = false; 

					        for (int i = h[t]; i != -1; i = ne[i]) 
					        {
					            int j = e[i];
					            if (dist[j] > dist[t] + w[i])
					            {
					                dist[j] = dist[t] + w[i];
					                if (!st[j]) 
					                {
					                    q.push(j);
					                    st[j] = true;
					                }
					            }
					        }
					    }

					    return dist[n];
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    memset(h, -1, sizeof h);

					    while (m -- )
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);
					        add(a, b, c);
					    }

					    int t = spfa();

					    if (t == 0x3f3f3f3f) puts("impossible");
					    else printf("%d\n", t);

					    return 0;
					}
				4. 复杂度
			2. AcWing 852. spfa判断负环
				1. 网址
				2. 代码{解析}
					重点: "如果cnt[x]  == n, 说明有负权环"
					    首先cnt[x]指的是从节点1到x点,在走最短路径的时候,经过的边数
					    cnt[x]的更新,一定是遇到了更短的路径,才会更新. 
					        if (dist[j] > dist[t] + w[i])
					            {
					                dist[j] = dist[t] + w[i];
					                cnt[j] = cnt[t] + 1;
					            ...
					    如果cnt[x] == n, 说明经过了n个边, 说明经过了n+1个点,但是我们只有n个节点
					    说明经过的n条边中,有两个点是同一个点
					    说明我们有环,因为是更短的路径,所以是负权环

					解释:
						算法分析
							使用spfa算法解决: 是否存在负环问题
							求负环的常用方法，基于SPFA，一般都用方法2, 本题也是用方法2:
								方法1：统计每个点入queue的次数，如果某个点入queue竟然有n次，则说明存在负环
								方法2：统计当前每个点到虚拟节点的"最短路中所包含的边数"，如果最短路所包含的边数>=n，则也说明存在环
									想象画面:
										树的bfs,从根一层一层向下扩散
										图的bfs{spfa很像bfs},对于某个点,一层一层向外扩散. 如果图中存在环, 并且这个点在环上, 一层层扩散后还会扩散回自己
											如果一个点, bfs, 走过的步数 == n, 那就说明一定有环了.
											注意, 步数 == n, 并不见得一定是刚好绕环一圈, 可能已经绕了超多圈了
												我们不设置一个阈值, 他能无限绕下去.
												所以, 步数 == n, 就一定有环了

						
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <queue>

					using namespace std;

					const int N = 2010, M = 10010;

					int n, m;
					int h[N], w[M], e[M], ne[M], idx;
					int dist[N], cnt[N]; 
						dist[N] 记录每个点到虚拟源点的最短距离
							dist[N]初始化不是 0x3f, 而是0 
								解释: 虚拟节点.
									在原图的基础上新建一个虚拟源点
									从该点向其他所有点连一条权值为0的边{我的理解应该是无向边吧}
										所以所有的点到这个虚拟节点的距离是0, 所以初始化是0
									"那么原图有负环等价于新图有负环", 对啊, 原图的某个负环, 这个环上的每个点, 都可以和虚拟节点相互连接, 然后变成新的负环
									然后在新图上用spfa可以找到负环，新图有负环等价于原图有负环。
						cnt[x] 记录当前x点到虚拟源点最短路的边数
							初始每个点到虚拟源点的距离为0
							如果cnt[x] >= n，则表示该图中一定存在负环，由于从虚拟源点到x至少经过n条边时，则说明图中至少有n + 1个点，表示一定有点是重复使用

					bool st[N];

					void add(int a, int b, int c)
					{
					    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
					}

					bool spfa()
					{
					    前面{spfa求最短路}的写法 只是把一个点, 点1放入queue中
					    	回忆{spfa求最短路}:
					    		queue<int> q; 记录所有距离变小的节点 
							    q.push(1); 把起点1放入队列 
							    st[1] = true; 说明节点1在queue里面
					    现在要把所有节点都放入queue中
							因为题目说的不是判断是否存在包含点1的负环, 而是判断是否存在任意负环 
							所以如果不把所有节点放入queue中, 而只是把点1放入queue中
								可能存在的情况:
									有负环, 但是节点1和这个负环是不连通的 
									之前说了, spfa很像bfs, 因此"遍历到的结点都是与源点1连通的", 如果只放入点1, 那么可能遍历不到负环所在的连通块
						queue<int> q;
					    for (int i = 1; i <= n; i ++ ) //因为担心节点1和负权环不连通, 所以需要把所有点都加到queue中
					    {
					        st[i] = true;
					        q.push(i);
					    }


					    while (q.size())
					    {
					        int t = q.front();
					        q.pop();

					        st[t] = false;

					        for (int i = h[t]; i != -1; i = ne[i]) //假设t节点是和节点1不连通的点, 我们依旧可以计算出和t相邻的点到t的举例, 因为全部dist[xx]的初始值都是0
					        {
					            int j = e[i];
					            if (dist[j] > dist[t] + w[i]) 
					            		因为dist[xx]初始值是0, 所以需要w[i] < 0的时候,才会更新dist[j]
					            		若dist[j] > dist[t] + w[i],则表示从t点走到j点能够让权值变少，因此进行对该点j进行更新，并且对应cnt[j] = cnt[t] + 1,往前走一步
					            {
					                dist[j] = dist[t] + w[i];
					                cnt[j] = cnt[t] + 1;

					                if (cnt[j] >= n) return true; 因为题目说的是: 是否有负环, 而不是是否包括点1的负环. 所以只要找到一个就返回
					                if (!st[j])
					                {
					                    q.push(j);
					                    st[j] = true;
					                }
					            }
					        }
					    }

					    return false;
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    memset(h, -1, sizeof h);

					    while (m -- )
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);
					        add(a, b, c);
					    }

					    if (spfa()) puts("Yes");
					    else puts("No");

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <queue>

					using namespace std;

					const int N = 2010, M = 10010;

					int n, m;
					int h[N], w[M], e[M], ne[M], idx;
					int dist[N], cnt[N];
					bool st[N];

					void add(int a, int b, int c)
					{
					    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
					}

					bool spfa()
					{
					    queue<int> q;

					    for (int i = 1; i <= n; i ++ ) 
					    {
					        st[i] = true;
					        q.push(i);
					    }

					    while (q.size())
					    {
					        int t = q.front();
					        q.pop();

					        st[t] = false;

					        for (int i = h[t]; i != -1; i = ne[i])
					        {
					            int j = e[i];
					            if (dist[j] > dist[t] + w[i])
					            {
					                dist[j] = dist[t] + w[i];
					                cnt[j] = cnt[t] + 1;

					                if (cnt[j] >= n) return true;
					                if (!st[j])
					                {
					                    q.push(j);
					                    st[j] = true;
					                }
					            }
					        }
					    }

					    return false;
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    memset(h, -1, sizeof h);

					    while (m -- )
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);
					        add(a, b, c);
					    }

					    if (spfa()) puts("Yes");
					    else puts("No");

					    return 0;
					}
				4. 复杂度
		9. Floyd
			1. AcWing 854. Floyd求最短路
				1. 网址
				2. 代码{解析}
					动态规划的思想
						集合表示: 
							f[k][i][j]
							节点序号是从1到n, k的取值范围是从1到n
							表示从i走到j的路径上{除i和j点外}, 只经过1到k的点的所有路径的最短距离。
						集合转移:
							f[k, i, j] = min(f[k - 1, i, j], f[k - 1, i, k] + f[k - 1, k, j]
								1. i到j的最短路径不经过k这个节点, 也就是f[k−1][i][j]
					    		2. i到j的最短路径经过k这个节点:
					    			f[k−1][i][k]: 我们从i节点到k节点, 并且经过的是节点1到节点k-1的最短距离{当然你爱经过不经过}
					    			f[k−1][k][j]: 我们从k节点到j节点, 并且经过的是节点1到节点k-1的最短距离{当然你爱经过不经过}
					    			因为这里指明了从i到k, 从k到j. 所以一定是经过了k, 并且起点是i, 终点是j

					我的脑海的画面:
						for (int k = 1; k <= n; k ++ )
					        for (int i = 1; i <= n; i ++ )
					            for (int j = 1; j <= n; j ++ )

						     -----------------> 第j列
						 	| >-1---------2--->
						 	| >-3---------4--->
						 	| >-5---------6--->
						 	|
						 	|
						 	↓
						 	 第i行

					    这里可以想成一个立方体
							先看一楼, 也就是k==1
								因为j在最里层, 所以k,i固定, j先变化
									也就是图中从1->2
								然后k固定, i+1, j继续变化
									也就是3->4
							最后弄完一楼, 我们往上一楼, 看k==2

					关键代码:
						for (int k = 1; k <= n; k ++ ) 
					        for (int i = 1; i <= n; i ++ )
					            for (int j = 1; j <= n; j ++ )
					                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					    我的理解:
					    	这里似乎不能通过我的{上方, 左上}来理解
					    	因为转移方程中, k不仅是第一个维度, 还存在第2,3维度...
					    		f[k, i, j] = min(f[k - 1, i, j], f[k - 1, i, k] + f[k - 1, k, j]
					    	三个for中, k是最外层, 所以先假设k是固定的
					    		例如k==1
						    		那么 d[i][j] = min(d[i][j], d[i][1] + d[1][j]);
						    		我们一直看的就是, 自己{d[i][j]}, 还有自己这一行的第1列, 自己这一列的第1行
						    			这个图像, 就是有点这种感觉了:{我自己, 我的最左方 d[i][1], 我的最上方 d[1][j]}
						    	例如k==2
						    		那么 d[i][j] = min(d[i][j], d[i][2] + d[2][j]);
						    		我们一直看的就是, 自己{d[i][j]}, 还有自己这一行的第2列, 自己这一列的第1行
						    			这个图像, 就是有点这种感觉了:{我自己, 我的左方 d[i][2], 我的上方 d[2][j]}
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 210, INF = 1e9;

					int n, m, Q;
					int d[N][N];

					void floyd()
					{
					    for (int k = 1; k <= n; k ++ ) 因此在计算"第k层"的f[i, j]的时候必须先将"第k-1层"的所有状态计算出来，所以需要把k放在最外层。
					        for (int i = 1; i <= n; i ++ )
					            for (int j = 1; j <= n; j ++ )
					                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}

					int main()
					{
					    scanf("%d%d%d", &n, &m, &Q);

					    for (int i = 1; i <= n; i ++ )
					        for (int j = 1; j <= n; j ++ )
					            if (i == j) d[i][j] = 0;
					            else d[i][j] = INF;

					    while (m -- )
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);
					        d[a][b] = min(d[a][b], c);
					    }

					    floyd();

					    while (Q -- )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);

					        int t = d[a][b];
					        if (t > INF / 2) puts("impossible");
					        	在下面代码中，判断从a到b是否是无穷大距离时
					        		需要进行 if(t > INF/2)判断
					        		而并非是 if(t == INF)判断
					        	原因是INF是一个确定的值，并非真正的无穷大，会随着其他数值而受到影响
					        		因为t可能由于更新, 会比INF稍微少一点. 
					        		t大于某个与INF相同数量级的数即可
					        else printf("%d\n", t);
					    }

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 210, INF = 1e9;

					int n, m, Q;
					int d[N][N];

					void floyd()
					{
					    for (int k = 1; k <= n; k ++ )
					        for (int i = 1; i <= n; i ++ )
					            for (int j = 1; j <= n; j ++ )
					                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
					}

					int main()
					{
					    scanf("%d%d%d", &n, &m, &Q);

					    for (int i = 1; i <= n; i ++ )
					        for (int j = 1; j <= n; j ++ )
					            if (i == j) d[i][j] = 0;
					            else d[i][j] = INF;

					    while (m -- )
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);
					        d[a][b] = min(d[a][b], c);
					    }

					    floyd();

					    while (Q -- )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);

					        int t = d[a][b];
					        if (t > INF / 2) puts("impossible");
					        else printf("%d\n", t);
					    }

					    return 0;
					}
				4. 复杂度
		10. Prim
			1. AcWing 858. Prim算法求最小生成树
				1. 网址
				2. 代码{解析}
					回忆:
						1. 有向图问题: 最短路
								1. 单源最短路
									都是正权边
										1. 朴素dikkstra
											O(v^2)
											稠密图的时候,e =接近= n^2, 所以用朴素dijkstra更好
										2. heap优化的dijkstra
											O(e*logv)
											适合稀疏图
									存在负权边: 一般用spfa,不用bellman-ford
										1. bellman-ford
											O(v*e)
										2. spfa
											一般是O(e), 最坏(v*e)
								2. 多源汇最短路
									floyd
										O(v^3)
										基于动态规划
						2. 无向图问题
							1. 最小生成树
								1. prim
									原理
										最短的横切边属于最小生成树
									朴素版prim
										复杂度: O(v^2)
										证明:
											for (int i = 0; i < n; i ++ ) -> n个节点
										    {
										        int t = -1;
										        for (int j = 1; j <= n; j ++ ) -> n个节点, 所以 O(n)*O(n) = O(n^2)
										            if (!st[j] && (t == -1 || dist[t] > dist[j]))
										                t = j;
										       	if (i && dist[t] == INF) return INF; 

										        if (i) res += dist[t]; 
										        st[t] = true;

										        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]); 
										    }
										适合:
											稠密图
									heap优化的prim
										复杂度: O(e*logv)
										证明: 和heap优化的dijkstra一样
											与Dijkstra类似，Prim算法也可以用堆优化，优先队列代替堆，优化的Prim算法时间复杂度 O(mlogn)。
											适用于稀疏图，但是稀疏图的时候求最小生成树，Kruskal算法更加实用。
										很少用
								2. kruskal
									原理:
										边长排序, 然后最短的组合为一类
										需要的数据结构: 并查集,判断两个点是否属于同一类
									复杂度: O(e*loge)
									证明:
										复杂度:
											排序操作: O(e*loge)
												快排的复杂度系数很小
													什么是系数很小. 例如都是 eloge级别的算法, 都要遍历loge层
														1. 其中一个算法, 每一层只需要计算1次
														2. 其中一个算法, 每一层需要计算100次
													所以虽然都是 eloge, 但是e具体是多少, 还是有影响的. 
												如果我们kruskal用快排, kruskal的性能会很大
											并查集操作: O(e)
												查询操作非常快, 复杂度: O(1)
												因为有e条边, 所以复杂度 O(e*1) = O(e)
									适合:
										稀疏图
							2. 二分图
								二分图
									一个图是二分图,当且仅当,图中不含有奇数环{环的边数是奇数,也就是环上的点的个数也是奇数}
									环上的点的个数是奇数,例如121,12121,最后一个1和第一个1就不能匹配了
								1. 判别一个图是否是二分图
									染色法
										O(v+e)
										其实是DFS
								2. 求二分图的最大匹配
									匈牙利算法
										最坏 O(v*e),但是实际运行效果非常好,远小于 O(ve) 
										思想
											如果我想要匹配的女生a,被其他男生b占据了,我就让这个b看看有没有其他女生c可以匹配,最后bc匹配,我和a匹配
										为什么是 O(v*e)
											v/2个男生,每个可能都需要让其他男生看看其他e条边能否匹配
											因为其实其他男生可能不需要找很多次,所以实际运行远小于O(v*e)
									最大流
										先不讲
					prim应用: 架设电缆, 全覆盖的情况下成本最低
					代码:
						#include <cstring>
						#include <iostream>
						#include <algorithm>

						using namespace std;

						const int N = 510, INF = 0x3f3f3f3f;

						int n, m;
						int g[N][N]; 稠密图, 用邻接矩阵存 
						int dist[N];
						bool st[N];


						int prim()
						{
						    memset(dist, 0x3f, sizeof dist); 把所有距离初始化为正无穷 

						    int res = 0; //存了最小生成树, 这个树的边的长度之和. 也就是我们要的答案
						    //下面的for loop
						    /*
						    1. 当i == 0也就是第一次遍历的时候
						        我们是初始化了所有和第一个节点相邻的边的dist[], 让这些dist不再是正无穷
						    2. 当i >= 1的时候,就是一次次找最短的dist,然后这个边就是最小生成树的一个边
						    */
						    for (int i = 0; i < n; i ++ ) 迭代 
						    {
						    	下面这一段, 最后的t是指: 在集合外的, 到集合距离最短的那个点.
						        int t = -1;
						        for (int j = 1; j <= n; j ++ )
						            if (!st[j] && (t == -1 || dist[t] > dist[j])) //!st[j]说明还没有划分成bobo老师中的蓝色的部分{蓝色部分是指最小生成树集合}, 这里是寻找最短边的节点
						                t = j;
						        反正走到这一步, t肯定是找到灵魂了, 但是这个灵魂的质量不一定好, 例如 dist[t] == INF.

						        if (i && dist[t] == INF) return INF; //假设不是第一次遍历,并且在集合外的最近的那个点t, 距离集合竟然是无穷, dist[t] == INF, 说明图不连通, 没有最小生成树

						        if (i) res += dist[t]; //这句话需要加在下面的for loop之前
						        st[t] = true;

						        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]); 
						        	//这个for loop放在if (i) res += dist[t];的后面,因为题目可能会给你一个负权环,例如4 4 -10, 是节点4到节点4的负权环. 也就是  g[4][4] == -10, 你会发现
						        	//dist[4] = min(dist[4], g[4][4]);会让dist[4]变得更小,从而res+=一个更小的数.这是不行的,所以在更新之前就res+=
						    }

						    return res;
						}


						int main()
						{
						    scanf("%d%d", &n, &m);

						    memset(g, 0x3f, sizeof g); 初始化是正无穷, 也就是不连通

						    while (m -- )
						    {
						        int a, b, c;
						        scanf("%d%d%d", &a, &b, &c);
						        g[a][b] = g[b][a] = min(g[a][b], c); 如果有重边, 存最小的. 注意是无向图两个方向都要存 
						    }

						    int t = prim();

						    if (t == INF) puts("impossible"); 如果所有点不是在一个连通块中, 就是impossible.
						    else printf("%d\n", t);

						    return 0;
						}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 510, INF = 0x3f3f3f3f;

					int n, m;
					int g[N][N];
					int dist[N];
					bool st[N];


					int prim()
					{
					    memset(dist, 0x3f, sizeof dist);

					    int res = 0; 
					    for (int i = 0; i < n; i ++ )
					    {
					        int t = -1;
					        for (int j = 1; j <= n; j ++ )
					            if (!st[j] && (t == -1 || dist[t] > dist[j]))
					                t = j;

					        if (i && dist[t] == INF) return INF;

					        if (i) res += dist[t];
					        st[t] = true;

					        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]); 
					        dist[4] = min(dist[4], g[4][4]);
					    }

					    return res;
					}


					int main()
					{
					    scanf("%d%d", &n, &m);

					    memset(g, 0x3f, sizeof g);

					    while (m -- )
					    {
					        int a, b, c;
					        scanf("%d%d%d", &a, &b, &c);
					        g[a][b] = g[b][a] = min(g[a][b], c);
					    }

					    int t = prim();

					    if (t == INF) puts("impossible");
					    else printf("%d\n", t);

					    return 0;
					}
				4. 复杂度
		11. Kruskal
			1. AcWing 859. Kruskal算法求最小生成树
				1. 网址
				2. 代码{解析}
					总结:
						稠密图求最小生成树: 用prim{因为麻烦, 需要}
						稀疏图求最小生成树: 用Kruskal
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

					int n, m;
					int p[N];

					struct Edge
					{
					    int a, b, w;

					    bool operator< (const Edge &E)const //重载操作符
					    {
					        return w < E.w;
					    }
					}edges[M]; //我很喜欢这一句,总之就是之前定义了全部的结构体内容struct xx{}XX;最后有[N]表示定义了一个结构体数组, 相当于定义了全局变量edges[N]

					int find(int x)
					{
					    if (p[x] != x) p[x] = find(p[x]);
					    return p[x];
					}

					int kruskal()
					{
					    sort(edges, edges + m); //按边长排序, 这里就用到了<操作符重载

					    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集

					    int res = 0, cnt = 0; //res是最小生成树的边长和, cnt是指最小生成树已经有几条边了
					    for (int i = 0; i < m; i ++ )
					    {
					        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

					        a = find(a), b = find(b);//找到a,b的祖先节点,赋值给a,b
					        if (a != b) //如果不是同一个祖先,说明可以合并,这个edge也是最小生成树的一部分
					        {
					            p[a] = b; //祖先a的父亲,现在是祖先b
					            res += w;
					            cnt ++ ;
					        }
					    }

					    if (cnt < n - 1) return INF; //最小生成树应该刚好是n-1条边, 如果不足,说明图不是联通的
					    return res;
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    for (int i = 0; i < m; i ++ ) 把所有的边读进来
					    {
					        int a, b, w;
					        scanf("%d%d%d", &a, &b, &w);
					        edges[i] = {a, b, w};
					    }

					    int t = kruskal();

					    if (t == INF) puts("impossible");
					    else printf("%d\n", t);

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010, M = 200010, INF = 0x3f3f3f3f;

					int n, m;
					int p[N];

					struct Edge
					{
					    int a, b, w;

					    bool operator< (const Edge &E)const 
					    {
					        return w < E.w;
					    }
					}edges[M]; 

					int find(int x)
					{
					    if (p[x] != x) p[x] = find(p[x]);
					    return p[x];
					}

					int kruskal()
					{
					    sort(edges, edges + m); 

					    for (int i = 1; i <= n; i ++ ) p[i] = i;   

					    int res = 0, cnt = 0; 
					    for (int i = 0; i < m; i ++ )
					    {
					        int a = edges[i].a, b = edges[i].b, w = edges[i].w;

					        a = find(a), b = find(b);
					        if (a != b) 
					        {
					            p[a] = b;
					            res += w;
					            cnt ++ ;
					        }
					    }

					    if (cnt < n - 1) return INF;
					    return res;
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    for (int i = 0; i < m; i ++ )
					    {
					        int a, b, w;
					        scanf("%d%d%d", &a, &b, &w);
					        edges[i] = {a, b, w};
					    }

					    int t = kruskal();

					    if (t == INF) puts("impossible");
					    else printf("%d\n", t);

					    return 0;
					}
				4. 复杂度
		12. 染色法判定二分图
			1. AcWing 860. 染色法判定二分图
				1. 网址
				2. 代码{解析}
					二分图: 
						1. 当且仅当图中不含有奇数环{环中的节点数是奇数, 或者说环中的边数是奇数}
						2. 
							任意一条边的两个端点都不可能在同一部分中.
							分成左右两侧, 左侧的所有点, 他们之间是一定是没有边连接的.
							右侧的所有点, 他们之间是一定是没有边连接的.
						3. 分成的左右两侧不一定是一样多. 例如左侧有10个, 右侧有2个也是ok的. 
					代码逻辑:
						我的颜色是1, 我的所有邻点都染成2. 然后dfs我的邻点. 最后会dfs所有的点. 
						如果我的颜色和我的邻点和我的颜色相同, 那就是有矛盾, 不存在二分图
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010, M = 200010; //因为是无向图, 所以题目给了一条边,我们其实要存两条,所以是20w

					int n, m;
					int h[N], e[M], ne[M], idx; //邻接表
					int color[N];

					void add(int a, int b)
					{
					    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
					}

					bool dfs(int u, int c)
					{
					    color[u] = c; //将u节点染成颜色c

					    for (int i = h[u]; i != -1; i = ne[i]) //u节点的邻接点
					    {
					        int j = e[i];
					        if (!color[j])
					        {
					            if (!dfs(j, 3 - c)) return false; //c=1的话,结果就是2, 如果是2的话,就是1
					        }
					        else if (color[j] == c) return false; 
					        //如果邻接点已经被染色, 判断这个点是不是和我颜色一样,一样就是false
					        //如果有自环的话,肯定return false, 因为color[j] == color[u]
					    }

					    return true;
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    memset(h, -1, sizeof h);

					    while (m -- )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);
					        add(a, b), add(b, a); 因为是无向边
					    }

					    bool flag = true;
					    for (int i = 1; i <= n; i ++ ) //开始染色
					        //每一个i,就是对一个连通图进行染色.

					        if (!color[i]) //如果没有染色
					        {
					            if (!dfs(i, 1)) //将第i个节点,染成1. 如果dfs()返回false,我们认为有矛盾发生,就不是二分图
					            //我之前担心:会不会存在一个图,将i节点染成1会出矛盾,如果换成2就不会.其实不会存在这样的图
					            //因为是深度遍历,所以dfs()之后,i节点所在的连通图的所有节点都会被染色, 之后再进入dfs()就是下一个连通图了
					            {
					                flag = false;
					                break;
					            }
					        }
					        //一个图的连通图染色完毕,然后看下一个连通图

					    if (flag) puts("Yes");
					    else puts("No");

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010, M = 200010;

					int n, m;
					int h[N], e[M], ne[M], idx;
					int color[N];

					void add(int a, int b)
					{
					    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
					}

					bool dfs(int u, int c)
					{
					    color[u] = c;

					    for (int i = h[u]; i != -1; i = ne[i])
					    {
					        int j = e[i];
					        if (!color[j])
					        {
					            if (!dfs(j, 3 - c)) return false; 
					        }
					        else if (color[j] == c) return false; 
					    }

					    return true;
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    memset(h, -1, sizeof h);

					    while (m -- )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);
					        add(a, b), add(b, a); 因为是无向边
					    }

					    bool flag = true;
					    for (int i = 1; i <= n; i ++ )
					    	if (!color[i])
					        {
					            if (!dfs(i, 1))
					            {
					                flag = false;
					                break;
					            }
					        }

					    if (flag) puts("Yes");
					    else puts("No");

					    return 0;
					}
				4. 复杂度
		13. 匈牙利算法
			1. AcWing 861. 二分图的最大匹配
				1. 网址
				2. 代码{解析}
					题目问的是: 不允许脚踏两条船的情况下, 最多有几对人牵手
					思路: 
						一个不受欢迎的男生a, 和某个女生b相互喜欢. 这个女生b还和一个非常受欢迎的男生c相互喜欢
						为了让尽可能多的对牵手, 我们让ab牵手. 
							因为c即便没有b, 可c很受欢迎, 还有很多其他的备胎. 
							如果bc牵手, a可就一直单着了
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 510, M = 100010;

					int n1, n2, m;
					int h[N], e[M], ne[M], idx; //老师之前写成了e[N], ne[N],, 造成了数组越界. 数组越界后,什么错误都会发生,不只是SF,还可能是TLE
					int match[N]; //右侧女生是匹配了谁, match[j] = i; 女生j匹配的是男生i
					bool st[N]; //是否已经判断过该女生

					void add(int a, int b)
					{
					    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ; 
					}

					bool find(int x)
					{
					    for (int i = h[x]; i != -1; i = ne[i])
					    {
					        int j = e[i];
					        if (!st[j])//如果这个女生已经被男生x看过了,以后就不会再看了
					        {
					            st[j] = true;
					            if (match[j] == 0 || find(match[j])) //如果这个女生单身: match[j] == 0, 或者虽然脱单但是她男朋友match[j] 可以找到其他女生. 
					            //之所以可以用find让这个男生match[j]找到这个男生相互喜欢的其他女生, 而不是女生j是因为,st[j]==true,但是男生只会接受女生一次.
					            //如果 find(match[j]) 返回的是false, 说明这个男生match[j]是个不受欢迎的, 所以我们男生x就别强人所难了
					            {
					                match[j] = x;
					                return true;
					            }
					        }
					    }

					    return false;
					}

					int main()
					{
					    scanf("%d%d%d", &n1, &n2, &m);

					    memset(h, -1, sizeof h);

					    while (m -- )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);
					        add(a, b); //注意, 虽然是无向图,但是我们一直是从男生角度出发来判断匹配.
					        //男找女,如果此女已经匹配,再看匹配她的男生是否还有其他相互喜欢的女生
					        //所以只用存男生节点的临边
					    }

					    int res = 0; //当前匹配的数量

					    for (int i = 1; i <= n1; i ++ ) 依次分析每个男生 
					    {
					        memset(st, false, sizeof st); //对于每个男生i, 都会将所有的女生都设置成false, 意思是女生都还没看. 因为要保证每个女生只被考虑一次
					        if (find(i)) res ++ ; 如果这个男生i匹配成功, res++
					    }

					    printf("%d\n", res);

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 510, M = 100010;

					int n1, n2, m;
					int h[N], e[M], ne[M], idx; 
					int match[N];
					bool st[N];

					void add(int a, int b)
					{
					    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ; 
					}

					bool find(int x)
					{
					    for (int i = h[x]; i != -1; i = ne[i])
					    {
					        int j = e[i];
					        if (!st[j])
					        {
					            st[j] = true;
					            if (match[j] == 0 || find(match[j])) 
					            {
					                match[j] = x;
					                return true;
					            }
					        }
					    }

					    return false;
					}

					int main()
					{
					    scanf("%d%d%d", &n1, &n2, &m);

					    memset(h, -1, sizeof h);

					    while (m -- )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);
					        add(a, b); 
					    }

					    int res = 0;

					    for (int i = 1; i <= n1; i ++ ) 
					    {
					        memset(st, false, sizeof st);
					        if (find(i)) res ++ ; 
					    }

					    printf("%d\n", res);

					    return 0;
					}
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

					    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

					    for (int i = 1; i <= n; i ++ )
					        for (int j = m; j >= v[i]; j -- )
					            f[j] = max(f[j], f[j - v[i]] + w[i]);

					    cout << f[m] << endl;

					    return 0;
					}
				3. 纯代码
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

					    for (int i = 1; i <= n; i ++ ) cin >> v[i] >> w[i];

					    for (int i = 1; i <= n; i ++ )
					        for (int j = m; j >= v[i]; j -- )
					            f[j] = max(f[j], f[j - v[i]] + w[i]);

					    cout << f[m] << endl;

					    return 0;
					}
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
					二进制思想 O(logn)
						如果直接计算a乘b这会超过 long long 的最大范围，所以采用类似于快速幂的思想
						把 b写成二进制形式，然后如果第i位上为1就加上它a*（2^i）次方（n与这位的位置有关）
						并且每次计算后取模就可以了
					例：计算 3*7 = 21
						7的二进制 111
						3*(2^0)=3
						3*(2^1)=6
						3*(2^2)=12
						观察3,6,12: 可发现每次的可由前一次*2推出(记得取模)

					#include <cstdio>

					typedef long long LL;

					LL qadd(LL a, LL b, LL p)
					{
					    LL res = 0;
					    while (b)
					    {
					        if (b & 1) res = (res + a) % p; 如果B的末位是1, 那么, 我们加上a, 记得取模
					        a = (a + a) % p; 之前说了, 每次是*2, 所以是 a+a
					        b >>= 1; 右移 
					    }
					    return res;
					}

					int main()
					{
					    LL a, b, p;
					    scanf("%lld%lld%lld", &a, &b, &p);
					    printf("%lld\n", qadd(a, b, p));

					    return 0;
					}
				3. 纯代码
					#include <cstdio>

					typedef long long LL;

					LL qadd(LL a, LL b, LL p)
					{
					    LL res = 0;
					    while (b)
					    {
					        if (b & 1) res = (res + a) % p;
					        a = (a + a) % p;
					        b >>= 1;
					    }
					    return res;
					}

					int main()
					{
					    LL a, b, p;
					    scanf("%lld%lld%lld", &a, &b, &p);
					    printf("%lld\n", qadd(a, b, p));

					    return 0;
					}
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
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					#define x first
					#define y second

					using namespace std;

					typedef pair<int, int> PII;

					const int N = 1010, M = N * N; 数据范围是 1k*1k

					int n, m; 用flood fill做二维地图的题目: 需要用队列存index, 存2维, 用pair存
					char g[N][N]; 	地图
					PII q[M]; 		队列: m=n*n 
					bool st[N][N];	判重数组, 一般bfs都是需要判重, 我们这里就是bfs

					void bfs(int sx, int sy) 
					{
					    int hh = 0, tt = 0; 队头队尾
					    q[0] = {sx, sy}; 	插入第一个元素, 大陆的起点{sx, sy}
					    st[sx][sy] = true;	标志已经遍历过
					    						设置st数组的目的: 
					    							防止重复遍历某个点
					    							如果不写st数组, 错倒是不会会错, 但是会导致我们的复杂度可能是指数级别, 因为一个点可能被遍历多次
					    while (hh <= tt) 当队列不空 
					    {
					        PII t = q[hh ++ ]; 取出队头 

					        遍历这个大陆, 因为题目是8联通, 老师习惯写两重循环, 也就是{左上,上,右上,左,右,左下,下,右下}
					        for (int i = t.x - 1; i <= t.x + 1; i ++ ) 
					            for (int j = t.y - 1; j <= t.y + 1; j ++ )
					            {
					                if (i == t.x && j == t.y) continue; 跳过中间的格子, 也就是跳过自己
					                if (i < 0 || i >= n || j < 0 || j >= m) continue; 如果下标不合法, 跳过 
					                if (g[i][j] == '.' || st[i][j]) continue; 下标合法但是没有水 || 遍历过了, 跳过

					                q[ ++ tt] = {i, j}; 这块地{i,j}下标合法, 并且是睡
					                st[i][j] = true; 标记遍历过了
					            }
					    }
					    走出来, 就是bfs了这块大陆
					    为什么不用dfs?
					    	我的理解: 因为这道题就很适合往外遍历一层啊, 因为就是一个圈嘛, 所以bfs很适合, 遍历一层就好了
					}

					int main()
					{
					    scanf("%d%d", &n, &m);
					    for (int i = 0; i < n; i ++ ) scanf("%s", g[i]); 数据范围大, 用scanf
	 
					    int cnt = 0; 统计连通块个数
					    for (int i = 0; i < n; i ++ ) 
					        for (int j = 0; j < m; j ++ ) 遍历j, 再遍历i: 左上->右上, 左下->右下
					            if (g[i][j] == 'W' && !st[i][j]) bfs的判断条件都很长, 所以要思考清楚.
					            	什么时候开始 ff? 条件是: 
						            	1. 字符是水
						            	2. 之前没有被遍历过 
					            {
					                bfs(i, j);	说明发现新大陆, 这个大陆的入口是{i,j}.
					                cnt ++ ;	走出 bfs(), 就是遍历完了这块大陆, 所以cnt++
					            }

					    printf("%d\n", cnt);

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					#define x first
					#define y second

					using namespace std;

					typedef pair<int, int> PII;

					const int N = 1010, M = N * N;

					int n, m;
					char g[N][N];
					PII q[M];
					bool st[N][N];

					void bfs(int sx, int sy)
					{
					    int hh = 0, tt = 0;
					    q[0] = {sx, sy};
					    st[sx][sy] = true;

					    while (hh <= tt)
					    {
					        PII t = q[hh ++ ];

					        for (int i = t.x - 1; i <= t.x + 1; i ++ )
					            for (int j = t.y - 1; j <= t.y + 1; j ++ )
					            {
					                if (i == t.x && j == t.y) continue;
					                if (i < 0 || i >= n || j < 0 || j >= m) continue;
					                if (g[i][j] == '.' || st[i][j]) continue;

					                q[ ++ tt] = {i, j};
					                st[i][j] = true;
					            }
					    }
					}

					int main()
					{
					    scanf("%d%d", &n, &m);
					    for (int i = 0; i < n; i ++ ) scanf("%s", g[i]);

					    int cnt = 0;
					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < m; j ++ )
					            if (g[i][j] == 'W' && !st[i][j])
					            {
					                bfs(i, j);
					                cnt ++ ;
					            }

					    printf("%d\n", cnt);

					    return 0;
					}
				4. 复杂度
					ff的复杂度是线性的
			2. AcWing 1098. 城堡问题
				1. 网址
				2. 代码{解析}
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					#define x first
					#define y second

					using namespace std;

					typedef pair<int, int> PII;

					const int N = 55, M = N * N; 数据是50*50

					int n, m;
					int g[N][N]; 	地图
					PII q[M];		bfs的队列, 里面装的是可以被计算为房间面积的格子
					bool st[N][N];	标记是否遍历过

					int bfs(int sx, int sy) 新大陆的起点
					{
					    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
					    	这里的方向偏移是有讲究的, 因为用1表示西墙，2表示北墙，4表示东墙，8表示南墙
						    	所以 i == 0是西, 也就是向左: {0, -1}
						    	所以 i == 1是北, 也就是向上: {-1, 0}
						    	所以 i == 2是东, 也就是向右: {0, 1}
						    	所以 i == 3是南, 也就是向下: {1, 0}

					    int hh = 0, tt = 0;
					    int area = 0;		面积是0 

					    q[0] = {sx, sy};	插入第一个元素
					    st[sx][sy] = true;	说明遍历过了 

					    while (hh <= tt)	队列不空
					    {
					        PII t = q[hh ++ ];	取出队头
					        area ++ ; 			area到最后, 计算的是queue里面从始至终装了多少格子, 也就是房间有多大

					        for (int i = 0; i < 4; i ++ )	顺次遍历{i,j}东南西北四个方向的格子 
					        {
					            int a = t.x + dx[i], b = t.y + dy[i]; 				{a,b}是该格子
					            if (a < 0 || a >= n || b < 0 || b >= m) continue;	如果下标不合法, 跳过 
					            if (st[a][b]) continue;								遍历过{或者说ab已经算为我们的房间面积了}, 就跳过
					            if (g[t.x][t.y] >> i & 1) continue;					如果下标合法, 但是我[i,j]到这个方向有墙, 跳过 

					            q[ ++ tt] = {a, b};		说明我ij可以走到这个ab格子, 所以queue加入ab
					            st[a][b] = true;		说明遍历过 
					            	经过if筛选才将st[a,b]设为true
					            	所以我个人觉得, 到最后并不是st数组的所有元素都是 true, 而是算为房间面积的才是true
					        }
					    }

					    return area;
					}

					int main()
					{
					    cin >> n >> m;
					    for (int i = 0; i < n; i ++ ) 		读入地图
					        for (int j = 0; j < m; j ++ )
					            cin >> g[i][j];

					    int cnt = 0, area = 0;		cnt: 连通块个数, area: 最大的连通块面积
					    for (int i = 0; i < n; i ++ )	遍历地图
					        for (int j = 0; j < m; j ++ )
					            if (!st[i][j]) 如果没有遍历过这个地方
					            {
					                area = max(area, bfs(i, j)); 就去遍历: bfs(i,j). 然后返回的面积和当前area比较 
					                cnt ++ ;	走出 bfs()就是一个连通块
					            }

					    cout << cnt << endl;
					    cout << area << endl;

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					#define x first
					#define y second

					using namespace std;

					typedef pair<int, int> PII;

					const int N = 55, M = N * N;

					int n, m;
					int g[N][N];
					PII q[M];
					bool st[N][N];

					int bfs(int sx, int sy)
					{
					    int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

					    int hh = 0, tt = 0;
					    int area = 0;

					    q[0] = {sx, sy};
					    st[sx][sy] = true;

					    while (hh <= tt)
					    {
					        PII t = q[hh ++ ];
					        area ++ ;

					        for (int i = 0; i < 4; i ++ )
					        {
					            int a = t.x + dx[i], b = t.y + dy[i];
					            if (a < 0 || a >= n || b < 0 || b >= m) continue;
					            if (st[a][b]) continue;
					            if (g[t.x][t.y] >> i & 1) continue;

					            q[ ++ tt] = {a, b};
					            st[a][b] = true;
					        }
					    }

					    return area;
					}

					int main()
					{
					    cin >> n >> m;
					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < m; j ++ )
					            cin >> g[i][j];

					    int cnt = 0, area = 0;
					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < m; j ++ )
					            if (!st[i][j])
					            {
					                area = max(area, bfs(i, j));
					                cnt ++ ;
					            }

					    cout << cnt << endl;
					    cout << area << endl;

					    return 0;
					}
				4. 复杂度
			3. AcWing 1106. 山峰和山谷
				1. 网址
				2. 代码{解析}
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					#define x first
					#define y second

					using namespace std;

					typedef pair<int, int> PII;

					const int N = 1010, M = N * N; 	区域大小是1k*1k

					int n;
					int h[N][N];	所有点的高度
					PII q[M];		队列, 装的是同一个高度的所有点
					bool st[N][N];	是否遍历过 

					void bfs(int sx, int sy, bool& has_higher, bool& has_lower)
					{
					    int hh = 0, tt = 0;
					    q[0] = {sx, sy};
					    st[sx][sy] = true;

					    while (hh <= tt)
					    {
					        PII t = q[hh ++ ];

					        for (int i = t.x - 1; i <= t.x + 1; i ++ )
					            for (int j = t.y - 1; j <= t.y + 1; j ++ )
					            {
					                if (i == t.x && j == t.y) continue;
					                if (i < 0 || i >= n || j < 0 || j >= n) continue;
					                if (h[i][j] != h[t.x][t.y]) 如果邻居格子和我高度不一样, 说明找到了不同的山// 山脉的边界
					                {
					                    if (h[i][j] > h[t.x][t.y]) has_higher  = true; 如果邻居所在的山, 比我高
					                    else has_lower = true;	如果邻居所在的山, 比我低 
					                }
					                else if (!st[i][j]) 走到这里, 一定是邻居格子和我高度一样, 我们属于同一座山. 
					                					那么我们要看看这个邻居是否被遍历过, 如果遍历过就不考虑了
					                					什么情况下会是邻居被遍历过了呢?
					                						我的理解:
					                							因为我们是同一座山, 所以这个邻居被遍历的时候, 也是在当前这个 bfs()函数中被遍历的
					                							因为 bfs()会遍历完一个连通块的所有格子, 而我和邻居就是一个连通块的
					                						举例:
					                							-------------
																| 1 | 2 | 3 |
																-------------
																| 4 | 5 | 6 |
																-------------
																| 7 | 8 |   |
																-------------
																例如图中12345678格子都是同一个高度, 属于同一座山
																那么我们遍历的顺序是:
																	遍历1的时候, 把245在st数组中标记为true
																	遍历2的时候, 会看13456格子, 但是因为145已经被标记为true了, 所以只会标记36格子
																		这就是邻居被遍历过的情况
					                {
					                    q[ ++ tt] = {i, j};
					                    st[i][j] = true;
					                }
					            }
					    }
					}

					int main()
					{
					    scanf("%d", &n);

					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < n; j ++ )
					            scanf("%d", &h[i][j]); 	因为有1k*1k个输入, 用scanf

					    int peak = 0, valley = 0;		peak: 山峰个数, valley: 山谷个数
					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < n; j ++ )
					            if (!st[i][j])	如果这个格子ij被没有遍历过
					            {
					                bool has_higher = false, has_lower = false;	
					                bfs(i, j, has_higher, has_lower);	用传引用的方式, 得知是否有比格子ij高的或者矮的
					                if (!has_higher) peak ++ ;			!has_higher: 只要没有比格子{i,j}高的格子, 说明{ij}是最高的, 所以{ij}是山峰
					                if (!has_lower) valley ++ ;			!has_lower: 只要没有比格子{i,j}矮的格子, 说明{ij}是最矮的, 所以{ij}是山谷
					                	如果又有比他高的, 又有比他矮的, 那么就什么都不是, 所以peak和valley都没变
					                	如果没有比他高的, 没有比他矮的, 那么整个地图就是一个平面, 所以peak和valley都++
					                	所以 
					                		不能加else, 加了else就是二选一.
					                		但是题目是可以peak和valley都++的
					            }

					    printf("%d %d\n", peak, valley);

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					#define x first
					#define y second

					using namespace std;

					typedef pair<int, int> PII;

					const int N = 1010, M = N * N;

					int n;
					int h[N][N];
					PII q[M];
					bool st[N][N];

					void bfs(int sx, int sy, bool& has_higher, bool& has_lower)
					{
					    int hh = 0, tt = 0;
					    q[0] = {sx, sy};
					    st[sx][sy] = true;

					    while (hh <= tt)
					    {
					        PII t = q[hh ++ ];

					        for (int i = t.x - 1; i <= t.x + 1; i ++ )
					            for (int j = t.y - 1; j <= t.y + 1; j ++ )
					            {
					                if (i == t.x && j == t.y) continue;
					                if (i < 0 || i >= n || j < 0 || j >= n) continue;
					                if (h[i][j] != h[t.x][t.y]) // 山脉的边界
					                {
					                    if (h[i][j] > h[t.x][t.y]) has_higher  = true;
					                    else has_lower = true;
					                }
					                else if (!st[i][j])
					                {
					                    q[ ++ tt] = {i, j};
					                    st[i][j] = true;
					                }
					            }
					    }
					}

					int main()
					{
					    scanf("%d", &n);

					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < n; j ++ )
					            scanf("%d", &h[i][j]);

					    int peak = 0, valley = 0;
					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < n; j ++ )
					            if (!st[i][j])
					            {
					                bool has_higher = false, has_lower = false;
					                bfs(i, j, has_higher, has_lower);
					                if (!has_higher) peak ++ ;
					                if (!has_lower) valley ++ ;
					            }

					    printf("%d %d\n", peak, valley);

					    return 0;
					}
				4. 复杂度
		2. 搜索 - 最短路模型
			1. AcWing 1076. 迷宫问题
				1. 网址
				2. 代码{解析}
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					#define x first
					#define y second

					using namespace std;

					typedef pair<int, int> PII; 其实记录的就是坐标{i,j}

					const int N = 1010, M = N * N;

					int n;
					int g[N][N];	存地图 
					PII q[M];		bfs的queue, 也就是层序遍历存的每一层的内容, 到最后queue是遍历完了一个联通块, 其实可能还没等到遍历完整个连通块, 我们就找到终点了{但是我们这里的实现没有提前break, 我觉得其实可以的}
					PII pre[N][N]; 	我们要记录路径, 所以就是上一个节点pre
										例如 PII aa = pre[i][j]
											x = aa.x 
											y = aa.y 
											说明 {x,y} --> {i,j}也就是 ij点 是从 xy点 来的
									其实这里的pre数组代替了st数组{也就是某个点是否被遍历过}
					void bfs(int sx, int sy)
					{
					    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 四个方向: 上, 右, 下, 左

					    int hh = 0, tt = 0; 
					    q[0] = {sx, sy};

					    memset(pre, -1, sizeof pre); 初始化pre, 说明每个点都没有遍历过
					    pre[sx][sy] = {0, 0};		 其实这里我要解释一下:
					    							这里的{0,0}并不是说起点{0,0}, 其实这里可以是任何非-1的值
					    							因为我们是 bfs(n-1, n-1), 所以其实是从{n-1,n-1}这个点往左上找
					    							所以我们这里就干脆把{n-1,n-1}当成虚拟起点, 这个虚拟起点的来源点是无
					    							但是为了让我们能够通过 "这个点已经被遍历过"的判断: if (pre[a][b].x != -1) , 我们就设置为非-1 
					    							因为可能bfs的时候, 在遍历其他点的时候, 其他点又遍历回了{n-1,n-1}这个点. 
					    while (hh <= tt)
					    {
					        PII t = q[hh ++ ];

					        for (int i = 0; i < 4; i ++ ) 四个方向, 因为是4个方向可以走 
					        {
					            int a = t.x + dx[i], b = t.y + dy[i];
					            if (a < 0 || a >= n || b < 0 || b >= n) continue;	如果不合法, 跳过 
					            if (g[a][b]) continue;								如果是障碍1, 跳过 
					            if (pre[a][b].x != -1) continue;					如果遍历过, 也跳过. 
					            	pre帮忙实现了st数组的功能{也就是某个点是否被遍历过, bfs只需要每个点遍历一次
					            			因为假如某个点被第二次遍历, 那么这第二次遍历赋予的距离一定 >= 第一次遍历赋予的距离
					            			{因为是层序遍历嘛, 越后面遍历到的距离越远}. 所以干脆就不考虑第二次}

					            q[ ++ tt] = {a, b};	插入到queue
					            pre[a][b] = t;		记录来源点 
					        }
					    }
					}

					int main()
					{
					    scanf("%d", &n);

					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < n; j ++ )
					            scanf("%d", &g[i][j]); 数据大, 用scanf

					    bfs(n - 1, n - 1); 从终点开始bfs
					    	因为如果是从起点{0,0}开始bfs, 那么pre里面存的都是 指向起点的内容, 因为是从起点过来的嘛!
					    		怎么说呢, 就是pre其实就像是一个链表, 指向的是来源点, 所以用pre我们只能追踪来源点
					    			例如
					    				{0,0} = pre[1,2]	{1,2}点的来源是起点{0,0}
					    				{1,2} = pre[4,5]
					    				{4,5} = pre[终点]
					    			因为我们打印pre的时候, 是"先知道pre[终点]", 从而知道{4,5}, 通过{4,5}去找pre[4,5]...
					    			所以打印是逆序的: 终点 -> {4,5} -> ... {0,0}
					    			所以我们还要把这个逆序压入到一个temp数组, 然后正序打印temp数组 
					    	因为如果是从终点{n-1,n-1}开始bfs, 那么pre里面存的都是 指向终点的内容, 因为是从终点过来的嘛!
				    			例如
				    				{n-1,n-1} = pre[4,5]	{4,5}点的来源是终点{n-1,n-1} 
				    				{4,5} = pre[1,2]
				    				{1,2} = pre[0,0]
				    			因为我们打印pre的时候, 是"先知道pre[0,0]", 从而知道{1,2}, 通过{1,2}去找pre[1,2]...
				    			所以打印是就是我们要的的: 起点 -> {1,2} -> ... {n-1,n-1}
					    PII end(0, 0);
					    	这就是我刚刚说的: "先知道pre[0,0]", 我们通过[0,0]去搜pre[0,0]

					    while (true)
					    {
					        printf("%d %d\n", end.x, end.y);
					        if (end.x == n - 1 && end.y == n - 1) break; 如果已经到终点{n-1,n-1}了, 就结束
					        end = pre[end.x][end.y];	去这个点的
					    }

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					#define x first
					#define y second

					using namespace std;

					typedef pair<int, int> PII;

					const int N = 1010, M = N * N;

					int n;
					int g[N][N];
					PII q[M];
					PII pre[N][N];

					void bfs(int sx, int sy)
					{
					    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

					    int hh = 0, tt = 0;
					    q[0] = {sx, sy};

					    memset(pre, -1, sizeof pre);
					    pre[sx][sy] = {0, 0};
					    while (hh <= tt)
					    {
					        PII t = q[hh ++ ];

					        for (int i = 0; i < 4; i ++ )
					        {
					            int a = t.x + dx[i], b = t.y + dy[i];
					            if (a < 0 || a >= n || b < 0 || b >= n) continue;
					            if (g[a][b]) continue;
					            if (pre[a][b].x != -1) continue;

					            q[ ++ tt] = {a, b};
					            pre[a][b] = t;
					        }
					    }
					}

					int main()
					{
					    scanf("%d", &n);

					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < n; j ++ )
					            scanf("%d", &g[i][j]);

					    bfs(n - 1, n - 1);

					    PII end(0, 0);

					    while (true)
					    {
					        printf("%d %d\n", end.x, end.y);
					        if (end.x == n - 1 && end.y == n - 1) break;
					        end = pre[end.x][end.y];
					    }

					    return 0;
					}
				4. 复杂度
					时间复杂度 O(n2)
			2. AcWing 188. 武士风度的牛
				1. 网址
				2. 代码{解析}
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					#define x first
					#define y second

					using namespace std;

					typedef pair<int, int> PII; 就是存下标{i,j}的

					const int N = 155, M = N * N;

					int n, m;
					char g[N][N];	地图 
					PII q[M];		存层序遍历bfs的路径
					int dist[N][N];	 所有点到起点的最短距离. 其实dist距离数组可以代替st数组{也就是某个点是否被遍历过}

					int bfs()
					{
					    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
					    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
					    		*1 	*2
					    	*3			*4
					    		  @
					    	*5			*6
					    		*7	*8
					    	简化:
					    		-2, -1, 1, 2
					    		对于每个数字, 搭配一个对应的数{例如2搭配1, 1搭配2}, 然后是取正负
					    			-2搭配: -1, 1
					    			2搭配: -1, 1
					    			-1搭配: -2, 2
					    			1搭配: -2, 2

					    int sx, sy;
					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < m; j ++ )
					            if (g[i][j] == 'K')
					                sx = i, sy = j; 说明起点在'K'点

					    int hh = 0, tt = 0;
					    q[0] = {sx, sy};	首先插入起点 

					    memset(dist, -1, sizeof dist);	所有点距离起点的距离是-1, 其实初始化只是-1, 代表没有遍历这个点, 而不是正无穷. 因为我们不需要用 min(xxx,yyy)
					    dist[sx][sy] = 0; 

					    while (hh <= tt)
					    {
					        auto t = q[hh ++ ];

					        for (int i = 0; i < 8; i ++ )
					        {
					            int a = t.x + dx[i], b = t.y + dy[i];
					            if (a < 0 || a >= n || b < 0 || b >= m) continue; 	下表不合法, 跳过 
					            if (g[a][b] == '*') continue;	表明是障碍物, 跳过 
					            if (dist[a][b] != -1) continue;  表明之前遍历过这个{i,j}点, 跳过 
					            	dist帮忙实现了st数组的功能{也就是某个点是否被遍历过, bfs只需要每个点遍历一次, 因为假如某个点被第二次遍历, 那么这第二次遍历赋予的距离一定 >= 第一次遍历赋予的距离{因为是层序遍历嘛, 越后面遍历到的距离越远}. 所以干脆就不考虑第二次}
					            if (g[a][b] == 'H') return dist[t.x][t.y] + 1;	如果很幸运, 刚好这个点就是终点'H', 直接返回
					            这里只是判断if, 而不再是之前的 dist[ab] = min(xxx, yyy);

					            dist[a][b] = dist[t.x][t.y] + 1;	更新dist, 
					            q[ ++ tt] = {a, b};					插入bfs的queue
					        }
					    }

					    return -1;
					}

					int main()
					{
					    cin >> m >> n;

					    for (int i = 0; i < n; i ++ ) cin >> g[i];

					    cout << bfs() << endl;

					    return 0;
					}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					#define x first
					#define y second

					using namespace std;

					typedef pair<int, int> PII;

					const int N = 155, M = N * N;

					int n, m;
					char g[N][N];
					PII q[M];
					int dist[N][N];

					int bfs()
					{
					    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
					    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

					    int sx, sy;
					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < m; j ++ )
					            if (g[i][j] == 'K')
					                sx = i, sy = j;

					    int hh = 0, tt = 0;
					    q[0] = {sx, sy};

					    memset(dist, -1, sizeof dist);
					    dist[sx][sy] = 0;

					    while (hh <= tt)
					    {
					        auto t = q[hh ++ ];

					        for (int i = 0; i < 8; i ++ )
					        {
					            int a = t.x + dx[i], b = t.y + dy[i];
					            if (a < 0 || a >= n || b < 0 || b >= m) continue;
					            if (g[a][b] == '*') continue;
					            if (dist[a][b] != -1) continue;
					            if (g[a][b] == 'H') return dist[t.x][t.y] + 1;

					            dist[a][b] = dist[t.x][t.y] + 1;
					            q[ ++ tt] = {a, b};
					        }
					    }

					    return -1;
					}

					int main()
					{
					    cin >> m >> n;

					    for (int i = 0; i < n; i ++ ) cin >> g[i];

					    cout << bfs() << endl;

					    return 0;
					}
				4. 复杂度
			3. AcWing 1100. 抓住那头牛
				1. 网址
				2. 代码{解析}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1e5 + 10;

					int n, k;
					int q[N];
					int dist[N];

					int bfs()
					{
					    memset(dist, -1, sizeof dist);
					    dist[n] = 0;
					    q[0] = n;

					    int hh = 0, tt = 0;

					    while (hh <= tt)
					    {
					        int t = q[hh ++ ];

					        if (t == k) return dist[k];

					        if (t + 1 < N && dist[t + 1] == -1)
					        {
					            dist[t + 1] = dist[t] + 1;
					            q[ ++ tt] = t + 1;
					        }
					        if (t - 1 >= 0 && dist[t - 1] == -1)
					        {
					            dist[t - 1] = dist[t] + 1;
					            q[ ++ tt] = t - 1;
					        }
					        if (t * 2 < N && dist[t * 2] == -1)
					        {
					            dist[t * 2] = dist[t] + 1;
					            q[ ++ tt] = t * 2;
					        }
					    }

					    return -1;
					}

					int main()
					{
					    cin >> n >> k;

					    cout << bfs() << endl;

					    return 0;
					}
				4. 复杂度
		3. 搜索 - 多源BFS
			1. AcWing 173. 矩阵距离
				1. 网址
				2. 代码{解析}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					#define x first
					#define y second

					using namespace std;

					typedef pair<int, int> PII;

					const int N = 1010, M = N * N;

					int n, m;
					char g[N][N];
					PII q[M];
					int dist[N][N];

					void bfs()
					{
					    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

					    memset(dist, -1, sizeof dist);

					    int hh = 0, tt = -1;
					    for (int i = 1; i <= n; i ++ )
					        for (int j = 1; j <= m; j ++ )
					            if (g[i][j] == '1')
					            {
					                dist[i][j] = 0;
					                q[ ++ tt] = {i, j};
					            }

					    while (hh <= tt)
					    {
					        auto t = q[hh ++ ];

					        for (int i = 0; i < 4; i ++ )
					        {
					            int a = t.x + dx[i], b = t.y + dy[i];
					            if (a < 1 || a > n || b < 1 || b > m) continue;
					            if (dist[a][b] != -1) continue;

					            dist[a][b] = dist[t.x][t.y] + 1;
					            q[ ++ tt] = {a, b};
					        }
					    }
					}

					int main()
					{
					    scanf("%d%d", &n, &m);
					    for (int i = 1; i <= n; i ++ ) scanf("%s", g[i] + 1);

					    bfs();

					    for (int i = 1; i <= n; i ++ )
					    {
					        for (int j = 1; j <= m; j ++ ) printf("%d ", dist[i][j]);
					        puts("");
					    }

					    return 0;
					}
				4. 复杂度
		4. 搜索 - 最小步数模型
			1. AcWing 1107. 魔板
				1. 网址
				2. 代码{解析}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>
					#include <queue>

					using namespace std;

					char g[2][4];
					unordered_map<string, pair<char, string>> pre;
					unordered_map<string, int> dist;

					void set(string state)
					{
					    for (int i = 0; i < 4; i ++ ) g[0][i] = state[i];
					    for (int i = 7, j = 0; j < 4; i --, j ++ ) g[1][j] = state[i];
					}

					string get()
					{
					    string res;
					    for (int i = 0; i < 4; i ++ ) res += g[0][i];
					    for (int i = 3; i >= 0; i -- ) res += g[1][i];
					    return res;
					}

					string move0(string state)
					{
					    set(state);
					    for (int i = 0; i < 4; i ++ ) swap(g[0][i], g[1][i]);
					    return get();
					}

					string move1(string state)
					{
					    set(state);
					    int v0 = g[0][3], v1 = g[1][3];
					    for (int i = 3; i >= 0; i -- )
					    {
					        g[0][i] = g[0][i - 1];
					        g[1][i] = g[1][i - 1];
					    }
					    g[0][0] = v0, g[1][0] = v1;
					    return get();
					}

					string move2(string state)
					{
					    set(state);
					    int v = g[0][1];
					    g[0][1] = g[1][1];
					    g[1][1] = g[1][2];
					    g[1][2] = g[0][2];
					    g[0][2] = v;
					    return get();
					}

					int bfs(string start, string end)
					{
					    if (start == end) return 0;

					    queue<string> q;
					    q.push(start);
					    dist[start] = 0;

					    while (!q.empty())
					    {
					        auto t = q.front();
					        q.pop();

					        string m[3];
					        m[0] = move0(t);
					        m[1] = move1(t);
					        m[2] = move2(t);

					        for (int i = 0; i < 3; i ++ )
					            if (!dist.count(m[i]))
					            {
					                dist[m[i]] = dist[t] + 1;
					                pre[m[i]] = {'A' + i, t};
					                q.push(m[i]);
					                if (m[i] == end) return dist[end];
					            }
					    }

					    return -1;
					}

					int main()
					{
					    int x;
					    string start, end;
					    for (int i = 0; i < 8; i ++ )
					    {
					        cin >> x;
					        end += char(x + '0');
					    }

					    for (int i = 1; i <= 8; i ++ ) start += char('0' + i);

					    int step = bfs(start, end);

					    cout << step << endl;

					    string res;
					    while (end != start)
					    {
					        res += pre[end].first;
					        end = pre[end].second;
					    }

					    reverse(res.begin(), res.end());

					    if (step > 0) cout << res << endl;

					    return 0;
					}
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
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>
					#include <queue>

					using namespace std;

					const int N = 6;

					int n;
					string a[N], b[N];

					int extend(queue<string>& q, unordered_map<string, int>& da, unordered_map<string, int>& db, string a[], string b[])
					{
					    for (int k = 0, sk = q.size(); k < sk; k ++ )
					    {
					        string t = q.front();
					        q.pop();

					        for (int i = 0; i < t.size(); i ++ )
					            for (int j = 0; j < n; j ++ )
					                if (t.substr(i, a[j].size()) == a[j])
					                {
					                    string state = t.substr(0, i) + b[j] + t.substr(i + a[j].size());
					                    if (da.count(state)) continue;
					                    if (db.count(state)) return da[t] + 1 + db[state];
					                    da[state] = da[t] + 1;
					                    q.push(state);
					                }
					    }

					    return 11;
					}

					int bfs(string A, string B)
					{
					    queue<string> qa, qb;
					    unordered_map<string, int> da, db;
					    qa.push(A), da[A] = 0;
					    qb.push(B), db[B] = 0;

					    while (qa.size() && qb.size())
					    {
					        int t;
					        if (qa.size() <= qb.size()) t = extend(qa, da, db, a, b);
					        else t= extend(qb, db, da, b, a);

					        if (t <= 10) return t;
					    }

					    return 11;
					}

					int main()
					{
					    string A, B;
					    cin >> A >> B;
					    while (cin >> a[n] >> b[n]) n ++ ;

					    int step = bfs(A, B);
					    if (step > 10) puts("NO ANSWER!");
					    else printf("%d\n", step);

					    return 0;
					}
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
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					int n;
					char g[N][N];
					int xa, ya, xb, yb;
					int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
					bool st[N][N];

					bool dfs(int x, int y)
					{
					    if (g[x][y] == '#') return false;
					    if (x == xb && y == yb) return true;

					    st[x][y] = true;

					    for (int i = 0; i < 4; i ++ )
					    {
					        int a = x + dx[i], b = y + dy[i];
					        if (a < 0 || a >= n || b < 0 || b >= n) continue;
					        if (st[a][b]) continue;
					        if (dfs(a, b)) return true;
					    }

					    return false;
					}

					int main()
					{
					    int T;
					    scanf("%d", &T);
					    while (T -- )
					    {
					        scanf("%d", &n);
					        for (int i = 0; i < n; i ++ ) scanf("%s", g[i]);
					        scanf("%d%d%d%d", &xa, &ya, &xb, &yb);

					        memset(st, 0, sizeof st);
					        if (dfs(xa, ya)) puts("YES");
					        else puts("NO");
					    }

					    return 0;
					}
				4. 复杂度
			2. AcWing 1113. 红与黑
				1. 网址
				2. 代码{解析}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 25;

					int n, m;
					char g[N][N];
					bool st[N][N];

					int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

					int dfs(int x, int y)
					{
					    int cnt = 1;

					    st[x][y] = true;
					    for (int i = 0; i < 4; i ++ )
					    {
					        int a = x + dx[i], b = y + dy[i];
					        if (a < 0 || a >= n || b < 0 || b >= m) continue;
					        if (g[a][b] != '.') continue;
					        if (st[a][b]) continue;

					        cnt += dfs(a, b);
					    }

					    return cnt;
					}

					int main()
					{
					    while (cin >> m >> n, n || m)
					    {
					        for (int i = 0; i < n; i ++ ) cin >> g[i];

					        int x, y;
					        for (int i = 0; i < n; i ++ )
					            for (int j = 0; j < m; j ++ )
					                if (g[i][j] == '@')
					                {
					                    x = i;
					                    y = j;
					                }

					        memset(st, 0, sizeof st);
					        cout << dfs(x, y) << endl;
					    }

					    return 0;
					}
				4. 复杂度
		8. 搜索 - DFS之搜索顺序
			1. AcWing 1116. 马走日
				1. 网址
				2. 代码{解析}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 10;

					int n, m;
					bool st[N][N];
					int ans;
					int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
					int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

					void dfs(int x, int y, int cnt)
					{
					    if (cnt == n * m)
					    {
					        ans ++ ;
					        return;
					    }
					    st[x][y] = true;

					    for (int i = 0; i < 8; i ++ )
					    {
					        int a = x + dx[i], b = y + dy[i];
					        if (a < 0 || a >= n || b < 0 || b >= m) continue;
					        if (st[a][b]) continue;
					        dfs(a, b, cnt + 1);
					    }

					    st[x][y] = false;
					}

					int main()
					{
					    int T;
					    scanf("%d", &T);
					    while (T -- )
					    {
					        int x, y;
					        scanf("%d%d%d%d", &n, &m, &x, &y);

					        memset(st, 0, sizeof st);
					        ans = 0;
					        dfs(x, y, 1);

					        printf("%d\n", ans);
					    }

					    return 0;
					}
				4. 复杂度
			2. AcWing 1117. 单词接龙
				1. 网址
				2. 代码{解析}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 21;

					int n;
					string word[N];
					int g[N][N];
					int used[N];
					int ans;

					void dfs(string dragon, int last)
					{
					    ans = max((int)dragon.size(), ans);

					    used[last] ++ ;

					    for (int i = 0; i < n; i ++ )
					        if (g[last][i] && used[i] < 2)
					            dfs(dragon + word[i].substr(g[last][i]), i);

					    used[last] -- ;
					}

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ ) cin >> word[i];
					    char start;
					    cin >> start;

					    for (int i = 0; i < n; i ++ )
					        for (int j = 0; j < n; j ++ )
					        {
					            string a = word[i], b = word[j];
					            for (int k = 1; k < min(a.size(), b.size()); k ++ )
					                if (a.substr(a.size() - k, k) == b.substr(0, k))
					                {
					                    g[i][j] = k;
					                    break;
					                }
					        }

					    for (int i = 0; i < n; i ++ )
					        if (word[i][0] == start)
					            dfs(word[i], i);

					    cout << ans << endl;

					    return 0;
					}
				4. 复杂度
			3. AcWing 1118. 分成互质组
				1. 网址
				2. 代码{解析}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 10;

					int n;
					int p[N];
					int group[N][N];
					bool st[N];
					int ans = N;

					int gcd(int a, int b)
					{
					    return b ? gcd(b, a % b) : a;
					}

					bool check(int group[], int gc, int i)
					{
					    for (int j = 0; j < gc; j ++ )
					        if (gcd(p[group[j]], p[i]) > 1)
					            return false;
					    return true;
					}

					void dfs(int g, int gc, int tc, int start)
					{
					    if (g >= ans) return;
					    if (tc == n) ans = g;

					    bool flag = true;
					    for (int i = start; i < n; i ++ )
					        if (!st[i] && check(group[g], gc, i))
					        {
					            st[i] = true;
					            group[g][gc] = i;
					            dfs(g, gc + 1, tc + 1, i + 1);
					            st[i] = false;

					            flag = false;
					        }

					    if (flag) dfs(g + 1, 0, tc, 0);
					}

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ ) cin >> p[i];

					    dfs(1, 0, 0, 0);

					    cout << ans << endl;

					    return 0;
					}
				4. 复杂度
		9. 搜索 - DFS之剪枝与优化
			1. AcWing 165. 小猫爬山
				1. 网址
				2. 代码{解析}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 20;

					int n, m;
					int w[N];
					int sum[N];
					int ans = N;

					void dfs(int u, int k)
					{
					    // 最优性剪枝
					    if (k >= ans) return;
					    if (u == n)
					    {
					        ans = k;
					        return;
					    }

					    for (int i = 0; i < k; i ++ )
					        if (sum[i] + w[u] <= m) // 可行性剪枝
					        {
					            sum[i] += w[u];
					            dfs(u + 1, k);
					            sum[i] -= w[u]; // 恢复现场
					        }

					    // 新开一辆车
					    sum[k] = w[u];
					    dfs(u + 1, k + 1);
					    sum[k] = 0; // 恢复现场
					}

					int main()
					{
					    cin >> n >> m;
					    for (int i = 0; i < n; i ++ ) cin >> w[i];

					    // 优化搜索顺序
					    sort(w, w + n);
					    reverse(w, w + n);

					    dfs(0, 0);

					    cout << ans << endl;

					    return 0;
					}
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
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					int n;
					int path[N];

					bool dfs(int u, int k)
					{
					    if (u == k) return path[u - 1] == n;

					    bool st[N] = {0};
					    for (int i = u - 1; i >= 0; i -- )
					        for (int j = i; j >= 0; j -- )
					        {
					            int s = path[i] + path[j];
					            if (s > n || s <= path[u - 1] || st[s]) continue;
					            st[s] = true;
					            path[u] = s;
					            if (dfs(u + 1, k)) return true;
					        }

					    return false;
					}

					int main()
					{
					    path[0] = 1;
					    while (cin >> n, n)
					    {
					        int k = 1;
					        while (!dfs(1, k)) k ++ ;

					        for (int i = 0; i < k; i ++ ) cout << path[i] << ' ';
					        cout << endl;
					    }

					    return 0;
					}
				4. 复杂度
		10. 搜索 - 双向DFS
			1. AcWing 171. 送礼物
				1. 网址
				2. 代码{解析}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					typedef long long LL;

					const int N = 46;

					int n, m, k;
					int w[N];
					int weights[1 << 25], cnt = 1;
					int ans;

					void dfs1(int u, int s)
					{
					    if (u == k)
					    {
					        weights[cnt ++ ] = s;
					        return;
					    }

					    dfs1(u + 1, s);
					    if ((LL)s + w[u] <= m) dfs1(u + 1, s + w[u]);
					}

					void dfs2(int u, int s)
					{
					    if (u >= n)
					    {
					        int l = 0, r = cnt - 1;
					        while (l < r)
					        {
					            int mid = l + r + 1 >> 1;
					            if ((LL)s + weights[mid] <= m) l = mid;
					            else r = mid - 1;
					        }
					        ans = max(ans, s + weights[l]);
					        return;
					    }

					    dfs2(u + 1, s);
					    if ((LL)s + w[u] <= m) dfs2(u + 1, s + w[u]);
					}

					int main()
					{
					    cin >> m >> n;
					    for (int i = 0; i < n; i ++ ) cin >> w[i];

					    sort(w, w + n);
					    reverse(w, w + n);

					    k = n / 2 + 2;
					    dfs1(0, 0);

					    sort(weights, weights + cnt);
					    cnt = unique(weights, weights + cnt) - weights;

					    dfs2(k, 0);

					    cout << ans << endl;

					    return 0;
					}
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
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 2510, M = 6200 * 2 + 10;

					int n, m, S, T;
					int h[N], e[M], w[M], ne[M], idx;
					int dist[N], q[N];
					bool st[N];

					void add(int a, int b, int c)
					{
					    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
					}

					void spfa()
					{
					    memset(dist, 0x3f, sizeof dist);
					    dist[S] = 0;

					    int hh = 0, tt = 1;
					    q[0] = S, st[S] = true;

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
					                    q[tt ++ ] = j;
					                    if (tt == N) tt = 0;
					                    st[j] = true;
					                }
					            }
					        }
					    }
					}

					int main()
					{
					    cin >> n >> m >> S >> T;

					    memset(h, -1, sizeof h);
					    for (int i = 0; i < m; i ++ )
					    {
					        int a, b, c;
					        cin >> a >> b >> c;
					        add(a, b, c), add(b, a, c);
					    }

					    spfa();

					    cout << dist[T] << endl;

					    return 0;
					}
				4. 复杂度
			2. AcWing 1128. 信使
				1. 网址
				2. 代码{解析}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 110, INF = 0x3f3f3f3f;

					int n, m;
					int d[N][N];

					int main()
					{
					    cin >> n >> m;

					    memset(d, 0x3f, sizeof d);
					    for (int i = 0; i < m; i ++ )
					    {
					        int a, b, c;
					        cin >> a >> b >> c;
					        d[a][b] = d[b][a] = min(d[a][b], c);
					    }

					    for (int k = 1; k <= n; k ++ )
					        for (int i = 1; i <= n; i ++ )
					            for (int j = 1; j <= n; j ++ )
					                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

					    int res = 0;
					    for (int i = 2; i <= n; i ++ )
					        if (d[1][i] == INF)
					        {
					            res = -1;
					            break;
					        }
					        else res = max(res, d[1][i]);

					    cout << res << endl;

					    return 0;
					}
				4. 复杂度
			3. AcWing 1127. 香甜的黄油
				1. 网址
				2. 代码{解析}
				3. 纯代码
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 810, M = 3000, INF = 0x3f3f3f3f;

					int n, p, m;
					int id[N];
					int h[N], e[M], w[M], ne[M], idx;
					int dist[N], q[N];
					bool st[N];

					void add(int a, int b, int c)
					{
					    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
					}

					int spfa(int start)
					{
					    memset(dist, 0x3f, sizeof dist);
					    dist[start] = 0;

					    int hh = 0, tt = 1;
					    q[0] = start, st[start] = true;
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
					                    q[tt ++ ] = j;
					                    if (tt == N) tt = 0;
					                    st[j] = true;
					                }
					            }
					        }
					    }

					    int res = 0;
					    for (int i = 0; i < n; i ++ )
					    {
					        int j = id[i];
					        if (dist[j] == INF) return INF;
					        res += dist[j];
					    }

					    return res;
					}

					int main()
					{
					    cin >> n >> p >> m;
					    for (int i = 0; i < n; i ++ ) cin >> id[i];

					    memset(h, -1, sizeof h);
					    for (int i = 0; i < m; i ++ )
					    {
					        int a, b, c;
					        cin >> a >> b >> c;
					        add(a, b, c), add(b, a, c);
					    }

					    int res = INF;
					    for (int i = 1; i <= p; i ++ ) res = min(res, spfa(i));

					    cout << res << endl;

					    return 0;
					}
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

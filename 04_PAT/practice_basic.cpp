0. C++ STL简介
	auto
		c++关键字,可以自动推测类型,省去书写麻烦
	vector, 变长数组，倍增的思想
		基础
		    size()  
		    	返回元素个数
		    empty()  
		    	返回是否为空
		    clear()  
		    	清空
		    front()/back() 
		    	返回第一个/最后一个
		    push_back()/pop_back()
		    begin()/end() 
		    	迭代器:第0个/最后一个的下一位
		    [] 
		    	随机寻址
		    支持比较运算，按字典序
		    	例如 a(4,3)要小于b(3,4)
		    	vector<int> a(4,3),b(3,4); a = [3,3,3,3], b = [4,4,4]
		    	if(a < b) printf("a < b"); //会输出
	    其他
	    	1. 初始化
		    	vector<int> v;
		    	vector<int> v(10);
		    	vector<int> v(10, -3); //10个元素,每个是-3
		    	vector<int> v[10]; //定义了10个vector, 是vector数组
	    	2. 返回元素个数
	    		v.size() 
	    			//O(1),.size()是其他stl数据结构都支持的
	    	3. 是否是空的
	    		v.empty()
	    			//O(1),.empty()是其他stl数据结构都支持的
	    	4. 清空
	    		v.clear()
	    			队列queue就没有clear()函数

	pair<int, int>
	    first
	    	第一个元素
	    second
	    	第二个元素
	    支持比较运算（字典序）
	    	以first为第一关键字
	    	以second为第二关键字
	    初始化
	    	pair<int, string> p;
	    	p = make_pair(10, "xx");
	    	p = {10, "xx"};
	    使用技巧
	    	将需要排序的属性放在first,不需要排序的放到second
	    	如果有三个属性
	    		pair<int, pair<int, int>> p;
	    	pair的好处
	    		相当于包括了2个成员的结构体struct
	    		并且帮我们实现了比较函数

	string，字符串
	    size()/length()  
	    	返回字符串长度
	    empty()
	    	是否为空
	    clear()
	    常用: substr(index，(子串长度))  
	    	index是从0开始
	    	子串长度
	    		如果填很大,默认到结尾
	    		不写这个参数,默认到结尾
	    	返回值
	    		子串的值,例如"xdfs"
	    c_str()  
	    	返回字符串所在字符数组的起始地址
	    	下面两个都能打印出string a的值
		    	cout << a << endl;
		    	printf("%s\n", a.c_str());
	    加法
	    	string a = "abc";
	    	a += "xxy";
	    	a += 'c';

	queue, 队列
	    size()
	    empty()
	    push()  
	    	向队尾插入一个元素
	    pop()  
	    	弹出队头元素
	    front()  
	    	返回队头元素
	    	回忆vector也是front()和back()
	    back()  
	    	返回队尾元素
	    注意: queue没有clear()函数
	    	如果想清空
	    		直接q = queue<int>();重新初始化就好了


	priority_queue
		优先队列
			其实就是heap
		默认是大根堆
			定义成小根堆的方式：
		    	1. 直接传入相反数
		    	2. priority_queue<int, vector<int>, greater<int>> q;
		    		使用的时候,记得#include <vector>和<queue>
	    size()
	    empty()
	    push()
	    	插入一个元素
	    top()
	    	返回堆顶元素
	    pop()
	    	弹出堆顶元素
	    注意: 
	    	priority_queue没有clear()函数
		    	如果想清空
		    		直接q = priority_queue<int>();重新初始化就好了
		    只能对队首进行删除/增加
		    不能对任意元素删除/增加/修改
	   

	stack
		栈
	    size()
	    empty()
	    push()
	    	向栈顶插入一个元素
	    top() 
	    	返回栈顶元素
	    pop() 
	    	弹出栈顶元素
	    注意: 
	    	priority_queue没有clear()函数
		    	如果想清空
		    		直接q = priority_queue<int>();重新初始化就好了
		    

	deque
		双端队列
		虽然接口很多,但是速度很慢,所以很少用
	    size()
	    empty()
	    clear()
	    front()/back()
	    	返回值
	    push_back()/pop_back()
	    	队尾插入删除
	    push_front()/pop_front()
	    	队首插入删除
	    begin()/end()
	    	迭代器
	    []
	    	随机索引

	set, map, multiset, multimap, 基于平衡二叉树（红黑树），动态维护有序序列
	    size()
	    empty()
	    clear()
	    begin()/end()
	    ++, -- 返回前驱和后继
	    	时间复杂度 O(logn)
	    	因为都是树存储

	    set/multiset
	    	#include <set>
	    		基于平衡树, 会记录顺序, O(logN)
	    	set一个元素只能有一个
	    	multiset一个元素可以存在多个
		        insert() 
		        	插入一个数
		        find() 
		        	查找一个数
		        	如果不存在, 返回的是end迭代器
		        count() 
		        	返回某一个数的个数
		        	因为multiset可以存在多个相同元素
		        erase()
		            1. 如果输入是一个数x，就删除所有x  
		            	O(k + logn)
		            	k是x的个数
		            2. 如果输入一个迭代器，删除这个迭代器
		        set/multiset最核心的操作:
		        	lower_bound()/upper_bound()
			            lower_bound(x)  
			            	返回大于等于x的最小的数的迭代器
			            upper_bound(x)  
			            	返回大于x的最小的数的迭代器
			            举例
			            	011345
			            	lower_bound(2)=3的ind
			            	upper_bound(2)=3的ind
			            	lower_bound(1)=第一个1的ind
			            	upper_bound(1)=3的ind
	    map/multimap
	    	#include <map>
	    		基于平衡树, 会记录顺序, O(logN)
	        insert() 
	        	插入的数是一个pair
	        erase() 
	        	输入的参数是pair或者迭代器
	        find()
	        强大的随机索引[]
	        	举例
	        		map<string, int> a;
	        		a["xyz"] = 1;
	        		cout << a["xyz"];  
	        	时间复杂度是 O(logn)
	        		相比数组的随机索引,数组是索引是O(1)
	        	注意multimap不支持此操作。 
	        	
	        lower_bound()/upper_bound()

	unordered_set, unordered_map, unordered_multiset, unordered_multimap, 哈希表
		#include <unordered_set> 和 <unordered_map>
	    		基于哈希表, 不会记录顺序, 复杂度是 O(1)
	    和上面类似，增删改查的时间复杂度是 O(1)
	    不支持 lower_bound()/upper_bound()， 迭代器的++，--

	bitset
		作用是圧位
			举例
				你要使用1024个bool
					1. 如果直接开1024个bool(一个bool是一字节,也就是8个bit)
						需要1024个字节
					2. 但是如果你放到bit里面存
						需要1024个bit = 128个字节
				需要使用1w * 1w的bool矩阵
					1. 用10^8个bool
						需要10^8个字节,100MB(1MB = 10^6B)
					2. 用10^8个bit
						只需要100MB/8=12.5MB
	    bitset<10000> s;
	    	<>里面传入的是你想要多少个bit
	    	而不是像其他数结那样,传入类型
	    ~, &, |, ^
	    	^: 
	    		遇到同志者相安无事是0, 遇到忤逆者就是报错1
	    		不进位加法: 
	    			0+0 = 0, 1+1=10->0
	    			1+0 = 1
	    			110110 ^ 001101 = 111011
	    				110110
	    				001101
	    				111x11, 其中x=0因为1+1=10->0	 
	    >>, <<
	    ==, !=
	    []

	    count()  返回有多少个1

	    any() 
	    	判断是否至少有一个1
	    none()  
	    	判断是否全为0,相当于empty()
	    	总之:
	    		全为0, none()==true, any() ==false
	    		有至少一个1, none()==false, any()==true

	    set() 
	    	把所有位置成1
	    set(k, v) 
	    	将第k位变成v
	    reset() 
	    	把所有位变成0
	    flip() 
	    	等价于~
	    flip(k)
	    	把第k位取反

1. 基础算法
	1. 快速排序
			介绍:
				1. 排序(快写模板,立即通过)
					1. 快排
						1. 基于分治
						2. 步骤
							1. 确定分界点
								q[l], q[(l+r)/2], q[r], 随机
							**2. 重新划分区间 
							3. 递归处理左右两段
						3. 实现2.2有很多种方法
							1. 开辟两个数组,a[],b[]
								s1.1-10:40
							2. 用两个指针
							3. 高精度计算
						4. quick_sort一般算法竞赛不会自己写,一般都是面试考官喜欢问

			1. 785. 快速排序
				0. bug
				1. 笔记
				2. 注释
					1. y
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
					2. b
						O(nlogn)
						```

						#include <iostream>
						using namespace std;

						const int N = 100010;
						int q[N];
						int n;

						void quick_sort(int q[], int l, int r){
						    if(l >= r) return;
						  //  swap(q[l], q[]);
						    int i = l - 1, j = r + 1, x = q[l + (rand() % (r - l + 1))]; -> 随机选一个x, 防止x是数组里面的min或者max
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


						```
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			
			2. 786. 第k个数
				0. bug
				1. 笔记
					1.
						复杂度是 O(n):
							因为是n + n/4 + n/8 +… = 2n


					分好后, 左边的数 <= x
					分好后, 右边的数 >= x
						也就是 ==x的数字, 在左右两边都有分布
				2. 注释
					1. y
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/39785/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
						#include <iostream>

						using namespace std;

						const int N = 100010;

						int q[N];

						int quick_sort(int q[], int l, int r, int k)
						{
						    if (l >= r) return q[l];

						    swap(q[l], q[rand() % (r-l+1) + l]);
						    
						    int x = q[l], i = l - 1, j = r + 1;
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
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	2. 归并排序
			3. 787. 归并排序
				0. bug
				1. 笔记
				2. 注释
					1. y
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/39790/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			4. 788. 逆序对的数量
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/455187/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	3. 二分
			5. 789. 数的范围
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						        int l = 0, r = n-1;
						        while(l < r){
						            int mid =  (r-l)/2 + l;
						            if(q[mid] >= x) r = mid; //good: 因为mid是true的时候,也就是右侧都是x或者>=x的时候. 
						            else l = mid+1;
						        }
						        //出来一定是 l == r, 并且l指向的是==x或者第一个>x的数字

						        if(q[l] != x) cout<<"-1 -1"<<endl;
						        else{ //能进入这里,保证了已经有一个是==x的值了
						            cout << l << ' '; //把之前的index打印出来

						            int l = 0, r = n-1;
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/455273/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			6. 790. 数的三次方根
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/455363/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	4. 高精度 
			介绍:
				2. 加减乘除. 我们会讨论的(cpp没有大整数的计算,但是java,python有)
					1.
						1. A: len(A) <= 10^6, 所以A是一个超大的数
						2. a: a <= 10^9, a是一个较小的数
					2. 我们会讨论: 其中AB都是大数,a是小一点的数
						1. A + B
						2. A - B
						3. A * a
						4. A / a
						不贵讨论
							A*B //太大了
							A/B //更复杂
					3. 加法
						1. 反过来存: 数字低位在index==0的地方
							我的画面:
								1. string a,b 也就是原始数组:
											|\
											|  \
											|    \
											|      \
											|--------
									ind 	0        size
											高位 	 低位
									三角形高  高 		 低
								2. vector<int> A, B, C. 也就是对应的数组, 还有结果数组C
													/|
												  /	 |
												/    |
											  /      |
											  --------
									ind 	0        size
											低位 	 高位
									三角形高  高 		 低
								3. 想象: string a,b -> vector<int> A,B,C: 就像是坎坷, 先下后上
									|\				  /|
									|  \			/  |
									|    \		  /    |
									|      \	/      |
									|--------	--------
							计算:
								加法: 从低位开始, 也就是 vector<int> A, B 的index == 0的地方
								减法: 从低位开始, 也就是 vector<int> A, B 的index == 0的地方
								乘法: 从低位开始, 也就是 vector<int> A, B 的index == 0的地方
								打印: 从高位开始, 也就是 vector<int> C 的index == size - 1的地方
								除法: 从高位开始, 也就是 vector<int> C 的index == size - 1的地方

								减法/乘法/除法: 都要去掉前导零.
						2. 注意进一
						3. auto c : list/vector/迭代器
							c11新特色
					4. 加减乘除
						1. 存储数字的方式都一样: 也就是数字低位在index==0的地方
							因为加减乘除可能需要混合进行

			7. 791. 高精度加法
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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
						    for(unsigned int i = 0; i < A.size() || i < B.size() || t; i++) 只要A和B还有一个没有完, 就继续下去, 或者 如果还有进位t 就继续下去//需要选择最长的那个 //注意不能用 int i, 编译出错
						    {
						        if(i < A.size()) t += A[i];
						        if(i < B.size()) t += B[i];
						        C.push_back(t % 10); //C的index==0位置是数字的最低位
						        t /= 10; 给下一次的进位
						    }
						    // if(t) C.push_back(t); 如果还有进位 这一句可省略
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/455366/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			8. 792. 高精度减法
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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


						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/455368/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			9. 793. 高精度乘法
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/456777/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			10. 794. 高精度除法
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/456870/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	5. 前缀和与差分
			介绍:
				3. 前缀和
					1. 前缀和最大的用处和唯一的用处
						求一段区间的复杂度,用前缀和, 可以让复杂度从 O(n)到 O(1)
							方法:
								a0,a1,a2..,an
									其中 a0 = 0, 方便计算
								Sn = a0 + a1 + a2 + .. + an
									S0 = 0
								S_(n+1) = S_(n) + a_(n+1)
						作用
							Sm - Sn 就是: (n, m]左开右闭的总和,也就是[n+1, m]的和
							[n+1,m]不用前缀和是 O(n) : a_(n+1) + a_(n+2) + ... + am
							用前缀和是 O(1): Sm - Sn
								Sn = a1 + a2 + .. + an
								Sm = a1 + a2 + .. + an + a_(n+1) + a_(n+2) + ... + am
						疑问
							为什么S0,a0都约定是0
							为了特殊例子的一般化
								例如
									普通例子: 求[2,9]区间
										也就是求a2 + a3 + ... a9
										也就是S9 - S1
									特殊例子: 求[1,9]区间
										也就是求a1 + a2 + .. + a9
										也就是S9 - S0 (你看,这里有S0, 所以我们希望S0是存在的)
									一般不存在求[0,9], 其实我觉得 [0,9]的总和 == [1,9]的总和, 因为a0 = 0
										因为[1,9]是题目中给的info,但是一般[0]这个是我们自己添加的
					2. 子矩阵的和: 相当于二维的前缀和
						公式:
							配合画图 #001 https://www.acwing.com/video/239/ 12:19

							初始化:
								S[i, j] 
									= S[i-1, j] + S[i, j-1] - S[i-1, j-1] + a[i,j]
									= 上侧 + 左侧 - 左上侧小矩形 + 本次a[i,j]
							问题:
								Sum((x1,y1), (x2, y2)) 
									= S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]
									= 大矩形 - 上侧 - 左侧 + 左上的小矩形
								注意,是4个下标:
									   0,0  y1          y2
										|---------------|
										|	|			| 
									  x1|---------------|			
										|	|			| 
										|	|			| 
									  x2|---------------|

								S[x2, y2]
									   0,0  y1          y2
										|---------------|
										| x |	x 		| 
									  x1|---------------|			
										|	|			| 
										| x |	x		| 
									  x2|---------------|

								S[x1 - 1, y2]
									   0,0  y1          y2
										|---------------|
										| x |	x 		| 
									  x1|---------------|			
										|	|			| 
										|   |			| 
									  x2|---------------|
								S[x1 - 1, y2]
									   0,0  y1          y2
										|---------------|
										| x |	 		| 
									  x1|---------------|			
										|	|			| 
										| x |			| 
									  x2|---------------|

								 S[x1 - 1, y1 - 1]
									     0,0  y1          y2
										|---------------|
										| x |	 		| 
									  x1|---------------|			
										|	|			| 
										|   |			| 
									  x2|---------------|
			
				4. 差分
					一维差分
						B是差分数组, A是原数组	
						B[1] = A[1] ,B[i] = A[i] - A[i-1] ( 2<=i<=n)
						   	容易发现，“前缀和” 和 “差分” 是一对互逆运算，差分序列B的前缀和序列就是原序列A，前缀和序列S的差分序列也是原序列A。
						   		把序列A的区间 [l,r] 加上 v（即把 A[l]，A[l+1], ……, A[r] 都加上 v）
								其差分序列 B 的变化为 b[l] 加 v，b[r+1] 减 v，其余位置不变。
						如果要在[l,r]区间的元素, 加上v这个值, 公式, b是差分数组: 
						    b[l] += v;
						    b[r+1] -= v;
						举例
							列如数列 1 3 6 3 9 10 20，让位置在[2,5]范围内加 10
								这里认为第一个数字的index是1, 所以[[2,5]]是指3,6,3,9
							先转化为他的差分序列：1 "2" 3 -3 6 "1" 10
								处理后：1 "12" 3 -3 6 "-9" 10
							他的原序列就是差分序列的前缀和：1 13 16 13 19 10 20
					二维差分
						我喜欢的一点
							整个矩阵代表着b,所以矩阵的面积的和{b的和}就是a
							总之就是
								假设给b[i,j] += n, 那就要给右侧和下测的元素 -= n, 但是要给右下角的元素 += n
								也就是
									+n -n
									-n +n
								为什么?
									假设我们求的是a[i,j]
										你会发现,我们在加总所有b[x,y]的时候,只用到了左上角的+n
											这也是我们需要的
									假设我们求的是a[i,j]右侧的元素
										你会发现,我们加总b的时候,会用到: 左上角的+n, 右上角的-n
										相当于抵消, 相当于没有影响到a[i,j]右侧元素的值
										也是我们想要的
									同理, 我们求a[i,j]下册的元素
										你会发现,我们加总b的时候,会用到: 左上角的+n, 左下角的-n
										相当于抵消, 相当于没有影响到a[i,j]下侧元素的值
										也是我们想要的
									最后, 我们求a[i,j]右下角的元素
										我们加总b的时候,会用到: 左上角的+n, 左下角的-n, 右上角的-n, 右下角的+n
										相当于抵消
						上述说的
							+n -n
							-n +n
							只是用于构建初始的b,是一个特例,更一般化的例子应该是
								还是只有四个元素被改变,但是这四个元素不是挨着的,而是围成了一个矩形
								+n--------------| -n
								|				| 
								|				| 
								|				| 
								----------------x
								-n  			  +n
							上述的图是b矩阵
								我们的目的就是在让a矩阵其中一块的所有元素都加上n
								所以就在你会发现, b矩阵的对应这块区域都+n
								但是其他区域, 要么: +n-n, +n-n, +n-n+n-n
			
			11. 795. 前缀和
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/456904/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			12. 796. 子矩阵的和
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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
						        	背诵: 
							        	原材料: x1y2, x2y1
							        	我们都是1-1, 也就是x1-1, y1-1
							        	所以最后就是 x1-1 y2, x2 y1-1
						        printf("%d\n",res);
						    }
						    return 0;
						}

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/457033/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			13. 797. 差分
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/457149/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			14. 798. 差分矩阵
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						    背诵: 
						    	原材料: x2,y1 	x1,y2
						    	向右下角扩散的, 我们都是遇到二就 +1: x2+1,y1 	x1,y2+1
						    	总之b是往右下角扩散的: 所以 x2+1, y2+1
						    对比: 前缀和:
						    	int res = S[x2][y2] - S[x1-1][y2] - S[x2][y1-1] + S[x1-1][y1-1];
					        	背诵: 
						        	原材料: x1y2, x2y1
						        	向左上角扩散的, 我们都是遇到一就-1, 也就是x1-1, y1-1
						        	所以最后就是 x1-1 y2, x2 y1-1
						        	这里是向左上角扩散的: 所以 x1-1,y1-1
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/457586/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	6. 双指针算法
			介绍:
				5. 双指针
					1. 应用
						1. 将O(n^2)的降为O(2*n)
						2. 使用的场合:
							存在单调性
							举例
								1. 连续的不重复元素
									连续的就是一种单调性:
										也就是连续数组的左侧index 一定是 小于 最右侧index
										所以可以一个index追另一个index
								2. 两个有序数组,求两个元素之和 == target
									一个从大到小找
									一个从小到大找
									都是沿着自己的既定方向走,说左移就只会左移,右移就只会右移
			
			15. 799. 最长连续不重复子序列
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						//https://www.acwing.com/video/245/ 39:29


						解释核心思路：

							遍历数组a中的每一个元素a[i], 对于每一个i，找到j使得双指针[j, i]维护的是以a[i]结尾的最长连续不重复子序列，长度为i - j + 1, 将这一长度与r的较大者更新给r。
							对于每一个i，如何确定j的位置：
								由于[j, i - 1]是前一步得到的最长连续不重复子序列
								所以如果[j, i]中有重复元素，一定是a[i]
								因此右移j直到a[i]不重复为止
									由于[j, i - 1]已经是前一步的最优解，
									此时j只可能右移以剔除重复元素a[i]，不可能左移增加元素，
									因此，"j具有“单调性”、本题可用双指针降低复杂度。"
							用数组s记录子序列a[j ~ i]中各元素出现次数，遍历过程中对于每一个i有四步操作：
								cin元素a[i] -> 
								将a[i]出现次数s[a[i]]加1 -> 
								若a[i]重复则右移j（s[a[j]]要减1） -> 
								确定j及更新当前长度i - j + 1给r。
							注意细节：
								当a[i]重复时，先把a[j]次数减1，再右移j。

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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/457640/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			16. 800. 数组元素的目标和
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/458257/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.
			
			17. 2816. 判断子序列 
				1. 代码:
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

					        我的理解:
					        	j就像是衣服, i就是一个人
					        	不过i喜不喜欢第j个衣服, 我们每次都要把第j个衣服换掉
					        	如果i喜欢第j个衣服, 那就看下一个人i+1
					        	如果i不喜欢第j个衣服, 就给i看下一件衣服j+1
					        	总之 j是无条件++
					    }

					    if (i == n) puts("Yes");
					    else puts("No");

					    return 0;
					}

				2. 解释:
					为什么双指针做法是正确的？
						整个过程中j指针不断扫描b数组并且向后移动
						相当于不断给i指针所指向的a数组创建匹配的机会
						只有匹配成功时, i指针才会向后移动一位
						当i==n时，说明全部匹配成功。

	7. 位运算
			介绍:
				6. 位运算
					1. 取第k位
						x >> k & 1
					2. 打印二进制
						for(int i = 31; i >= 0; i--) cout << (x >> i & 1);
						注意:
							x一定是unsigned int, 需要是无符号的
							我们需要先打印x的最高位,也就是x >> 31 & 1
					3. 求 
					lowbit(x)
						举例:
							x = 1010, lowbit(x) = 10;
							x = 101000, lowbit(x) = 1000
						计算:
							x & (-x)
						原因:
							-x = (~x+1)
							假设
										x = 1010 0101 1001 0000
										~x =0101 1010 0110 1111
									  ~x+1 =0101 1010 0111 0000
								  x & (-x)  ---- ---- ---1 ----

					4. 源码,反码,补码
						1. 源码是x
						2. 反码是~x
							也就是全部取反
						3. 补码是~x + 1
							取反+1
							x的负数就是x的补码
								例如y = -x, 那么y的二进制表达就是x的补码
							为何用补码表示负数?
								1. 我们想用加法表示减法
								2. x + (-x) = 0
									-x = 0 - x
									因为0的二进制是0000(32个0)
									但其实我们真的去减,应该是一个大数去减
									所以0其实是1 0000 (1后面32个0)
									你会发现, x + ~x + 1 就是1 0000
									例如
										因为 x + ~x是32个1
										再加1,就是1后跟32个0
								3. 总结: 假设x是4bit
									x + (-x) = 0000
									x + (-x) = 10000
									x + (-x) = x + ~x + 1
										-x 	 = x + ~x + 1 
			
			17. 801. 二进制中1的个数
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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
						    return x & (-x); 谐音: 与负, 渔夫
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/458280/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	8. 离散化
			介绍:
				7. 区间和
					1. 离散化处理
						背景
							对于一个一维数组,跨度非常大,但是里面的数据非常西数
							假设, index == 3的地方有一个值a, index == 9的地方有一个值b
							但是其他地方的值都是0
						我们将所有数据离散化处理
							其实说是离散化,我觉得是压缩了
							例如上例子中,一共只有两个值
							所以我们可以将值a从index = 3映射到index = 1(假设从1开始索引)
							所以我们可以将值b从index = 9映射到index = 2(假设从1开始索引)
							这样我们就以对这个压缩后形成的size == 2的数组来处理

			18. 802. 区间和 
				0. bug
				1. 笔记
					1.
						补充:
						1. 为什么要把query的index都加入all?
						    假设(ind, x)表示在ind加入元素x
						    (1,x),(4,y),(6,z)
						    假设没有将query加入all
						        经过压缩之后:
						            会变成(1,x),(2,y),(3,z)
						        经过前缀和处理之后
						            得到(1,x),(2,x+y),(3,x+y+z)
						            这种表示,可以让我们求出:(x+y)-(x+y)=0, (x+y)-x=y
						            但是我们不能求出x-x=0
						        假设我们要[2,3](这个index是未经压缩的),无论将2,3如何映射.都不能求出正确答案0
						2. 为什么要在all里面去重
						    不去重也可以
						        不去重的话,all也是递增序列,我们的 find()因为返回的是第一个>=x的位置,所以没有影响
						    去重的话
						        会只有唯一的x
						        所以 find()返回第一个>=x的数,也就一定是x本身而不是>x的数
				2. 注释
					1. y
					2. b
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

						我的图:

							要加的值	-a1--a2------a3--a4----------
							索引		 1   10		200 201

							要查找的索引 {0-20}, {100-300}

							要加的值插入了 all{1,10,200,201}
							要加的值插入了 add{{1, a1}, {10, a2}, {200, a3}, {201, a4}}

							要查找的索引插入了 all{"0",1,10,"20","100",200,201,"300"}
							要查找的索引插入了 query{{0, 20}, {100, 300}}

							压缩化: 把之前分散的index, 当成值, 然后根据值的大小, 排序得到的新的index就是压缩后的index
								之前分散的index: all{"0",1,10,"20","100",200,201,"300"}
								这些index本身对应的值: {-, a1, a2, -, -, a3, a4, -}
								当成值 {0,1,10,20,100,200,201,300}
								新的index就是压缩有的index: {0,1,2,3,4,5,6,7}
								所以相当于 
									{0, a1, a2, 0, 0, a3, a4, 0} --> 值
									{0, 1,  2,  3, 4,  5,  6, 7} --> 压缩后的index 对应了: int cind = find(item.first); 



							

				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	9. 区间合并
			19. 803. 区间合并
				0. bug
				1. 笔记
					1.
						区间合并,更多是使用"贪心算法",都是从左端点开始排序,或者右端点开始排序,或者左右双关键字排序
				2. 注释
					1. y
					2. b
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/458341/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

2. 数据结构
	1. 链表
			介绍:
				8. 链表
					1. 笔试的时候
						不采用
							struct Node{};
							new Node();
							因为算法的数据输入有很多万,时间不够
							除非你弄一个: struct Node[], 其实这个还是数组
						采用
							用数组模拟链表
					2. 单链表
						主要用于构造邻接表
							邻接表用于:树,图
						e[n]: 数组中第n个节点的值是e[n]
						ne[n]: 在数组中第n个节点的下一个节点的索引是ne[n],所以下一个节点的值:e[ne[n]]
						注意
							老师的实现方法
							只是存了某个ind的值和ind的左右节点
							其实就和用结构体是一样,也就是:
								不和数组一样,也就是没有说某个节点在整个链表到底是第几个
								而是单纯存了一个节点的值和他左右节点的ind
					3. 双链表
						用于优化

			20. 826. 单链表
				0. bug
				1. 笔记
					1.
						使用自己创建的数组来模拟链表等数据结构,比stl致命好的一个地方在于,
						自己创建的比stl快一些, 因为算法竞赛中不会使用stl的O2,O3(氧气优化,臭氧优化)优化.
						但是平时我们写代码会有这些优化,所以自己创建的好处就显示不出来.
				2. 注释
					1. y
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/42977/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			21. 827. 双链表 
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/42982/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	2. 栈和队列
			22. 828. 模拟栈
				0. bug
				1. 笔记
				2. 注释
					1. y
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/43103/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			23. 829. 模拟队列
				0. bug
				1. 笔记
				2. 注释
					1. y
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/43104/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			24. 830. 单调栈
				0. bug
				1. 笔记
				2. 注释
					1. y
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/43105/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			25. 154. 滑动窗口 单调队列
				0. bug
				1. 笔记
				2. 注释
					1. y
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/43107/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	3. KMP
			26. KMP字符串
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/458787/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

					从1开始的前缀 == 以i为终点的最长后缀, 这个后缀的长度是j
					next[i] = j

					也就是
						原数组:  xxxxxyyyxxx|xxyyyxxx
							   | 	 a1    |       i索引
							   			|    b 	   |
										|xxxxxyyyxxx
							  		    | 	 a2    |
							你看 a1 == a2, 也就是相当于平移
							而 a2 == b, 因为a2本来就是从b复制过来的, 本身就是一个东西
							所以 a1 == b, 也就是原数组的前缀 == 以i为终点的最长后缀

	4. Trie
			介绍:
				9. trie
					老师实现的非常短
			27. 835. Trie字符串统计  
				0. bug
				1. 笔记
				2. 注释
					1. y
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/45282/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			28. 143. 最大异或对 
				0. bug
				1. 笔记
					1.
						1. 暴力解法
						    每个数字,都要用O(n)寻找和它匹配的
						    所以一共是n个数字,O(n^2), 10^5 * 10^5  = 10^10
						2. trie
						    每个数字,需要O(32)寻找匹配,相当于O(logn)? 因为 n = 2^32
						    一共是n个数字,所以是O(nlogn), 需要10^5 \*32 = 3\*10^6, 老师说可以再1s每解出
						3. 老师是先查找,后插入(反过来也可以)
						    但是最好还是先查找,后插入.因为这样子,ai和后面的aj比,就不需要aj和前面ai再比了.也就是那种只往一侧比
						    查找:
						        如果某条路走的通,就继续走   
						            路的匹配,先从最高位开始匹配
						        走不通(没有想要的值),就只能按照他给的路走了(路是一定可以走到底的,因为每个int都是31位数值)
						        查找完,就计算这两个数的亦或值
						    插入:
						        把数值的最高位插入到根节点,因为先比较根节点,所以是先比较最高位
						4. 
						     if (!son[p][cc])    son[p][cc] = ++idx; //如果有坑的话，就填坑
						        p = son[p][cc];//记住每次都要更新p的值，而不是已经填坑了才更新
						知识: 
						1. cpp中1s可以计算10^7-10^8次计算10m,100m.也就是1千万到1亿次
						2. 所以算法竞赛,避免超时,需要复杂度在10^7~10^8
						
				2. 注释
					1. y
						#include <iostream>
						#include <algorithm>

						using namespace std;

						const int N = 100010, M = 3000000;

						int n;
						int a[N], son[M][2], idx;

						void insert(int x)
						{
						    int p = 0;
						    for (int i = 30; i >= 0; i -- )
						    {
						        int &s = son[p][x >> i & 1];
						        if (!s) s = ++ idx;
						        p = s;
						    }
						}

						int search(int x)
						{
						    int p = 0, res = 0;
						    for (int i = 30; i >= 0; i -- )
						    {
						        int s = x >> i & 1;
						        if (son[p][!s])
						        {
						            res += 1 << i;
						            p = son[p][!s];
						        }
						        else p = son[p][s];
						    }
						    return res;
						}

						int main()
						{
						    scanf("%d", &n);
						    for (int i = 0; i < n; i ++ )
						    {
						        scanf("%d", &a[i]);
						        insert(a[i]);
						    }

						    int res = 0;
						    for (int i = 0; i < n; i ++ ) res = max(res, search(a[i]));

						    printf("%d\n", res);

						    return 0;
						}

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/45284/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	5. 并查集
			介绍:
				10. 并查集
					代码段,思路巧妙
					路径压缩
			29.  836. 合并集合 
				0. bug
				1. 笔记
				2. 注释
					1. y
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/45287/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			30. 837. 连通块中点的数量
				0. bug
				1. 笔记
				2. 注释
					1. y
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/45295/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			31. 240. 食物链
				0. bug
				1. 笔记
					1.
						1. 逻辑
						    所有放在一个并查集里面的元素,我们都能知道他们的关系
						    例如x吃y,y吃z,我们就能知道x和z的关系
						    放在一个并查集里面
						        会有n层:
						            第0层: 根节点
						            第一层: 能吃根节点
						                所以%3 = 1, 所以距离根节点是1
						            第二层: 被根节点吃(这里就像是一个循环的圈了)
						                所以%3 = 2, 所以距离根节点是2
						            ---------------
						            第三层:是根节点的同类
						                所以%3 = 0, 所以距离根节点是0, 距离是0刚好也是同类
						            第四层: 能吃第三层, 所以也说明和第一层是同类
						                所以%3 = 1, 所以距离根节点是1
						            第五层: 能吃第四层, 所以也说明和第二层是同类
						                所以%3 = 2, 所以距离根节点是2
						        https://www.acwing.com/video/19/ 47:52

						2. 其他
						    全局变量初始化的时候本来就是0
				2. 注释
					1. y
					2. b
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
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	6. 堆
			介绍:
				11. heap堆
					操作
						stl的堆可以实现的:
							1. 加入一个ele
							2. 返回min
							3. 删除min
						stl的堆不可以实现的:
							1. 删除任意ele
								记得同时 down(x);up(x);
								因为替换过来的最后一个ele可能比被删除的ele要大或者要小都可能
							2. 修改任意ele的值
					回忆
						完全二叉树
						小根堆: 父亲 <= 左右儿子
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
					老师的习惯
						从ind == 1开始
						所以size指向的是最后一个已经有的元素,而不是最后一个元素的下一位
						然后左儿子 = x * 2, 右儿子 = x * 2 + 1
						父节点 = x / 2
					老师说
						层数不高,所以 down()里面采用的是递归,而不是while实现.

			32. 838. 堆排序 
				0. bug
				1. 笔记
				2. 注释
					1. y
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/45296/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			33. 839. 模拟堆 
				0. bug
				1. 笔记
					我们这道题, 需要存映射, 也就是 第k个插入的数. 所以不经常考
						ph[k]: 第k个插入的数, 在heap中的下标
						hp[k]: heap中下标是k的数, 是第hp[k]个插入的
				2. 注释
					1. y
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

					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	7. 哈希表/散列表
			介绍:
				12. 哈希表
					1. 存储结构
						1. 开放寻址法
							蹲坑,坑一定比人多
							不一定要刚好是mod的给你的位置,你只要往后找找到一个空位就行
							用0x3f3f3f3f, 并且 memset(xx, 0x3f,sizeof xx)
								用0x3f3f3f3f	,因为
									1. 比题目范围10^9大
									2. 是重复模式,可以用 memset()表示
						2. 拉链法
							就是如果有冲突,两个值都映射到了哈希表的同一个索引(链表),那就还是这个索引(链表),只不过往链表继续放元素
							1. 老师如何找: 大于100000的最小质数
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
					2. 举例
						输入一个取值范围是[10^(-9), 10^9]的数, 将这些数映射到取值范围是[0, 10^5]
					3. 和之前离散化的对比
						离散化是特殊的哈希函数,因为离散化是保序的,但是哈希函数不一定
					4. 操作
						1. 添加
						2. 查找
						3. 删除
							不会真的删除,而是在哈希表的映射元素(链表)中的该元素的bool设置成false
			
				13. 字符串哈希
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
			
			34. 840. 模拟散列表
				0. bug
				1. 笔记
				2. 注释
					1. y
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
					
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			35. 841. 字符串哈希 
				0. bug
				1. 笔记
				2. 注释
					1. y
						#include <iostream>
						#include <algorithm>

						using namespace std;

						typedef unsigned long long ULL;

						const int N = 100010, P = 131; P是经验值 

						int n, m;
						char str[N];
						ULL h[N], p[N];

						ULL get(int l, int r)
						{
						    return h[r] - h[l - 1] * p[r - l + 1]; 根据公式 
						}

						int main()
						{
						    scanf("%d%d", &n, &m);
						    scanf("%s", str + 1);

						    p[0] = 1;
						    for (int i = 1; i <= n; i ++ )
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
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

3. 搜索和图论
	1. dfs/bfs
			介绍:
				15. BFS/DFS
					BFS
						稳重,步步为营
						用queue,也就是一层一层的往里面放
						空间复杂度: O(指数级 2^h), 因为第h层会有2^h个元素
						可以应用于
							最短路问题
								1.
									包含了动态规划问题
									两者互通
									DP是特殊的最短路问题,是没有环的最短路问题

									没有权重的最短路问题用BFS做
									DP问题一般不会用最短路算法做,因为最短路算法的复杂度更高,DP算法低一些

								2. 分类
									单源最短路
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
										存在负权边(一般用spfa,不用bellman-ford)
											1. bellman-ford
												O(n*e)
												基于离散数学
												可以求负权环但是一般不用这个来做,用spfa做
											2. spfa
												一般是 O(e), 最坏 O(n*e)
												spfa是限制最小的算法
													可以解决没有负权环的问题(99.9%的题目都是没有负权环的)
												spfa是对bellman-ford的优化
									多源汇最短路
										floyd
											O(n^3)
											基于动态规划

							拓扑序
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

			36. 842. 排列数字 dfs
				0. bug
				1. 笔记
				2. 注释
					1. y
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
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			37. 843. n-皇后问题	经典dfs问题
				0. bug
				1. 笔记
					其实就是全排列的问题
					例如我们的全排列数组是:
						1 3 6 4 7 2 5
						意思是:
							第一个皇后, 在第1行,第"1"列
							第二个皇后, 在第2行,第"3"列
							第三个皇后, 在第3行,第"6"列
							....
				2. 注释
					1. y
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
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			38. 844. 走迷宫
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			39. 845. 八数码
				0. bug
				1. 笔记
					转换为图论问题:
						1. 所有的状态, 都是图里面的一个节点
							状态: "12345678x", "45678x123" 都是状态
						2. 我们给了起始节点, 问走到一个终点的最短距离
					过程:
						将原点状态"678x12345"想象为3*3的样子
						对于x, 枚举上下左右4个方向
						将上下左右4个方向的状态 + 他们到原点的距离记录
							如果上下左右有一个状态是终点状态"12345678x", 就可以提前结束了
				2. 注释
					1. y

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

					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	2. 深度优先/广度优先
			40. 846. 树的重心 (深度)
				0. bug
				1. 笔记
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
				2. 注释
					1. y
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
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			41. 847. 图中点的层次 (广度)
				0. bug
				1. 笔记
				2. 注释
					1. y
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
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

	3. 图:
			介绍:
				16. 图的表示
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

				17. 图的问题
					1. 有向图问题:
						1. 最短路
							单源最短路
									1. 朴素dikkstra
										O(v^2)
										稠密图的时候,e =接近= n^2, 所以用朴素dijkstra更好
									2. heap优化的dijkstra
										O(e*logv)
										适合稀疏图
								存在负权边(一般用spfa,不用bellman-ford)
									1. bellman-ford
										O(v*e)
									2. spfa
										一般是O(e), 最坏(v*e)
							多源汇最短路
								floyd
									O(v^3)
									基于动态规划
					2. 无向图问题
						1. 最小生成树
							1. prim
								原理
									最短的横切边属于最小生成树
								朴素版prim
									O(v^2)
									适合稠密图
								heap优化的prim
									O(elogv)
									很少用
							2. kruskal
								需要的数据结构
									并查集,判断两个点是否属于同一类
								O(eloge)
								适合稀疏图
						2. 二分图
							二分图
								一个图是二分图,当且仅当,图中不含有奇数环(环的边数是奇数,也就是环上的点的个数也是奇数)
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

			42. 拓扑- 848. 有向图的拓扑序列
				0. bug
				1. 笔记
					有向无环图一定存在拓扑序列
				2. 注释
					1. y
					2. b
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
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			43. dijkstra- 849. Dijkstra求最短路 I 
				0. bug
				1. 笔记
					1.	
						1. 我们可以用手写堆或者priority_queue来实现找最短dist的t节点
						2. 注意Loge 和 logn是一个级别,因为e <= n^2, loge <= logn^2, loge <= 2logn
				2. 注释
					1. y
					2. b
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
						            if (!st[j] && (t == -1 || dist[t] > dist[j]))  找到所有:没有确定最小距离(!st[j])的节点中, dist最小的, 这里先初始了t = 第一个没有确定的节点, 然后再和所有后面没有确定距离的节点作比较
						                t = j; 注意, t == -1, t = j之后, 还会继续走上面的for loop

						        if(t == n) break; 因为题目要求的就是1到N的最短距离, 如果求出来了dist最短的就是N节点,我们就知道答案了

						        st[t] = true; 因为t是当前距离最小的,所以t节点的最短距离确定了

						        for (int j = 1; j <= n; j ++ )
						            dist[j] = min(dist[j], dist[t] + g[t][j]);
						            两个作用,一个是将==3f..的dist[]更新为真正距离1节点的距离
						            第一次走的时候,t == 1,所以全程都是更新所有和1相邻的点,真正距离1节点的距离


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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/466609/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			44. dijkstra- 850. Dijkstra求最短路 II
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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
						    heap.push({0, 1}); //距离1节点的距离是1, 这个节点是1节点

						    while (heap.size()) 特别像宽搜, 因为最多遍历m条边, 所以heap最多只有m条边加入 
						    {
						        auto t = heap.top();//取出dist最小的节点
						        heap.pop();

						        int ver = t.second, distance = t.first;

						        if (st[ver]) continue; //加入这个ver节点已经求出了正确值,就看下一个
						        st[ver] = true;

						        for (int i = h[ver]; i != -1; i = ne[i]) //遍历ver节点的所有临边,这个临边的ind == i
						        {
						            int j = e[i];//j是ver的临边
						            if (dist[j] > dist[ver] + w[i])//w[i]的意思是, ver和j之间的距离
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/467204/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			45. bellman-ford- 853. 有边数限制的最短路 
				0. bug
				1. 笔记
					1. 这道题只能用bellman-ford,因为题目有边数限制, 所以即便有负权环,也不能无限次转
				2. 注释
					1. y
					2. b
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
						    for (int i = 0; i < k; i ++ ) 迭代k次, 就是意味着最多不经过k条边//题目要求:不超过k条边
						    {
						        memcpy(last, dist, sizeof dist); //不备份会导致串联, 例如老师给的样例, 正确答案是3因为只能走一条边. 如果没有备份,会导致,先用最短距离的节点2去更新其他所有的点,导致节点3的最短距离变成了2,但是实际上是3

						        //用上次迭代的距离,更新这次节点的dist.
						        /*理解了,样例是:1到2是1,2到3是1,1到3是3.
						        没有备份:
						            1 2  3
						            0 3f 3f
						            0 1  2 -->--> 因为用的是之这一轮的2节点的1, min(3f, 1+1) = 2, 但不应该是2
						        有备份
						            1 2  3
						            0 3f 3f
						            0 1  3f --> 因为用的是上一轮的2节点的3f, min(3f, 3f+1) = 3f
						        */
						        for (int j = 0; j < m; j ++ ) //每次放松m个边
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

						    /*
						    为什么写成dist[n] > 0x3f3f3f3f / 2, 而不是dist[n] == 0x3f3f3f3f
						    因为存在负权边
						    假设节点a到节点b的距离是-5, 但是dist[a] == disk[b] == 0x3f3f3f3f
						    假设节点a会更新节点b, 那么dist[b] = min(0x3f3f3f3f, 0x3f3f3f3f - 5) =  0x3f3f3f3f - 5
						    所以最后dist[b]会比正无穷小一点
						    因为题目说了边的绝对值<1万, 有500次操作, 所以最多比正无穷小500万, 所以我们用/2判断
						    */
						    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
						    else printf("%d\n", dist[n]);

						    return 0;
						}
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			46. spfa- 851. spfa求最短路
				0. bug
				1. 笔记
					1.
						1. spfa是对bellman-ford的优化
						    bellman-ford中存在一句话:
						    dist[b] = min(dist[b), dist[a] + w)
						    所以如果dist[b]减少, 一定是因为disk[a]减少
						    如果disk[a]不变,它也不能使得其他节点的距离减小
						    所以我们存储dist"变小"的节点
						2. 用queue(其实用heap也可以)存所有dist"变小"的节点abc
						3. 并且更新这个节点abc的邻接点
				2. 注释
					1. y
					2. b

						```
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

						    queue<int> q;
						    q.push(1); 把起点1放入队列 
						    st[1] = true; //说明放入queue里面

						    while (q.size()) 只要队列不空, 队列里面是所有到起点的距离"变小"的节点, 所以队列不空说明还有距离变小的节点
						    {
						        int t = q.front(); 取出队头t
						        q.pop();

						        st[t] = false; //说明从queue取出点t

						        for (int i = h[t]; i != -1; i = ne[i]) 因为t是变小的点, 那t节点的邻接点就"有可能"可以变小{到原点的距离变小}
						        										这个也验证了, 如果是一个到原点距离没变的点, 它的邻接点就"完全没可能"变小
						        {
						            int j = e[i];
						            if (dist[j] > dist[t] + w[i])
						            {
						                dist[j] = dist[t] + w[i];
						                if (!st[j]) //如果不在queue里面,就放入. 如果这个点j本身就在queue,那以后会在queue中取出它的
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

						```
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			47. spfa- 852. spfa判断负环
				0. bug
				1. 笔记
					1. 如果cnt[x]  == n, 说明有负权环
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
				2. 注释
					1. y
					2. b
						```
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

						    for (int i = 1; i <= n; i ++ ) //因为担心节点1和负权环不连通? 所以需要把所有点都加到queue中
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
						            if (dist[j] > dist[t] + w[i]) //因为dist[xx]初始值是0, 所以需要w[i] < 0的时候,才会更新dist[j]
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

						```
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			48. floyd- 854. Floyd求最短路
				0. bug
				1. 笔记
					1. d[k,i,j]的意思是,经过节点1到节点k,我们从i节点到j节点的最短距离
						    = d[k-1, i, k] + d[k-1, k, j]
						    等于
						    	我们从i节点到k节点, 并且经过的是节点1到节点k-1的最短距离{当然你爱经过不经过}
						    加上 
						    	我们从k节点到j节点, 并且经过的是节点1到节点k-1的最短距离{当然你爱经过不经过}
				2. 注释
					1. y
					2. b
						```
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
						```
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			49. prim- 858. Prim算法求最小生成树 
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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

						    int res = 0; //存了最小生成树的边的长度之和
						    //下面的for loop
						    /*
						    1. 当i == 0也就是第一次遍历的时候
						        我们是初始化了所有和第一个节点相邻的边的dist[], 让这些dist不再是正无穷
						    2. 当i >= 1的时候,就是一次次找最短的dist,然后这个边就是最小生成树的一个边
						    */
						    for (int i = 0; i < n; i ++ )
						    {
						        int t = -1;
						        for (int j = 1; j <= n; j ++ )
						            if (!st[j] && (t == -1 || dist[t] > dist[j])) //!st[j]说明还没有划分成bobo老师中的蓝色的部分, 这里是寻找最短边的节点
						                t = j;

						        if (i && dist[t] == INF) return INF; //假设不是第一次遍历,但是dist[t] == INF, 说明图不连通, 没有最小生成树

						        if (i) res += dist[t]; //这句话需要加在下面的for loop之前
						        st[t] = true;

						        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]); //这个for loop放在if (i) res += dist[t];的后面,因为题目可能会给你一个负权环,例如4 4 -10, 是节点4到节点4的负权环.你会发现
						        dist[4] = min(dist[4], g[4][4]);会让dist[4]变得更小,从而res+=一个更小的数.这是不行的,所以在更新之前就res+=
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/467487/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			50. kruskal- 859. Kruskal算法求最小生成树
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
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
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			51. 染色- 860. 染色法判定二分图
				0. bug
				1. 笔记
					二分图: 当且仅当图中不含有奇数环{环中的节点数是奇数, 或者说环中的边数是奇数}
					二分图:
						任意一条边的两个端点都不可能在同一部分中.
						分成左右两侧, 左侧的所有点, 他们之间是一定是没有边连接的.
						右侧的所有点, 他们之间是一定是没有边连接的.
					二分图:
						分成的左右两侧不一定是一样多. 例如左侧有10个, 右侧有2个也是ok的. 
					逻辑:
						我的颜色是1, 我的所有邻点都染成2. 然后dfs我的邻点. 最后会dfs所有的点. 
						如果我的颜色和我的邻点和我的颜色相同, 那就是有矛盾, 不存在二分图
				2. 注释
					1. y
					2. b
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
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			52. 匈牙利- 861. 二分图的最大匹配
				0. bug
				1. 笔记
				2. 注释
					1. y
						题目问的是: 不允许脚踏两条船的情况下, 最多有几对人牵手
						思路: 
							一个不受欢迎的男生a, 和某个女生b相互喜欢. 这个女生b还和一个非常受欢迎的男生c相互喜欢
							为了让尽可能多的对牵手, 我们让ab牵手. 
								因为c即便没有b, 可c很受欢迎, 还有很多其他的备胎. 
								如果bc牵手, a可就一直单着了.
					2. b
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
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

4. 数学知识
	质数
		AcWing 866. 试除法判定质数
			0. bug
			1. 笔记
				这道题是判定某个数是否是质数
				复杂度, 是很标准的 O(sqrt(N)) 
			2. 注释
				#include <iostream>
				#include <algorithm>

				using namespace std;

				bool is_prime(int x)
				{
				    if (x < 2) return false;
				    for (int i = 2; i <= x / i; i ++ )	从2到 sqrt(x), 看x是否能被这个数整除. 
				    						细节: 是 i <= x / i; 
				    						而不是 i * i <= x, 因为 i*i可能溢出变为负数, 负数<=x就一直出不来了
				        if (x % i == 0)
				            return false;
				    return true;
				}

				int main()
				{
				    int n;
				    cin >> n;

				    while (n -- )
				    {
				        int x;
				        cin >> x;
				        if (is_prime(x)) puts("Yes");
				        else puts("No");
				    }

				    return 0;
				}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 867. 分解质因数
			0. bug
			1. 笔记
				将某个数分解质因数，并按照质因数从小到大的顺序输出每个质因数的底数和指数
				复杂度是 
					最好: O(log_2^N), 最差: O(sqrt(N))
					解释: 为什么是 O(log_2^N), 因为最好的情况就是 i == 2的时候, 在while里面就把x都整除完了, 也就是x = 2^k, 所以只需要k次计算, k = log_2^x 
				疑问:
					我们要找的是x的质因子, 为什么 divide()中的 for()是遍历所有的从2到 sqrt(x)的数字, 这里面有合数呀, 可不应该有合数呀
					解释:
						如果 i是合数, 在走 if (x % i == 0) 这一句的时候, 就永远不会是true
						为什么? 因为如果i是一个合数, 说明这个i是某些比i小的质数的乘积
						但是因为我们的x, 在之前遍历到质因子i的时候, x /= i, 所以x此时已经不能被一个合数整除了
						例如 x = 2 * 2 * 2 * 2* 3
						我们遍历到 i == 2的时候, x/=i, 一直到x=3
						我们之后遍历到 i == 4{合数}的时候, 我们的x已经不可能被4整除了. 
						所以, for()是遍历所有的从2到 sqrt(x)的数字, 这里面有合数也不怕
			2. 注释
				#include <iostream>
				#include <algorithm>

				using namespace std;

				void divide(int x)
				{
				    for (int i = 2; i <= x / i; i ++ )	从2开始看 一直到 sqrt(x)
				        if (x % i == 0)	如果i能整除x, 说明i是一个质因子. 能满足这个条件的i一定是质数.
				        {
				            int s = 0;
				            while (x % i == 0) x /= i, s ++ ;	我们看有多少个这个质因子, 用s记录
				            cout << i << ' ' << s << endl;
				        }
				    if (x > 1) cout << x << ' ' << 1 << endl;	如果最后还剩余x, 就输出这个数字
				    cout << endl;
				}

				int main()
				{
				    int n;
				    cin >> n;
				    while (n -- )
				    {
				        int x;
				        cin >> x;
				        divide(x);
				    }
				    return 0;
				}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 868. 筛质数
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	约数
		AcWing 869. 试除法求约数
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 870. 约数个数
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 871. 约数之和
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 872. 最大公约数
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
		AcWing 873. 欧拉函数
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 874. 筛法求欧拉函数
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
		AcWing 875. 快速幂
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 876. 快速幂求逆元
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	扩展欧几里得算法
		AcWing 877. 扩展欧几里得算法
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 878. 线性同余方程
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	中国剩余定理
		AcWing 204. 表达整数的奇怪方式
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
		AcWing 883. 高斯消元解线性方程组
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 884. 高斯消元解异或线性方程组
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	求组合数
		AcWing 885. 求组合数 I
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 886. 求组合数 II
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 887. 求组合数 III
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 888. 求组合数 IV
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 889. 满足条件的01序列
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
		AcWing 890. 能被整除的数
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
		AcWing 891. Nim游戏
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 892. 台阶-Nim游戏
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 893. 集合-Nim游戏
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 894. 拆分-Nim游戏
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
18. 背包问题
	1. 01背包
		每种有1个
	2. 完全背包
		每种有无限个
	3. 多重背包
		每种有有限个
	4. 分组背包
		一个组只能选一种

	0. DP问题分析
		1. 状态表示
			
		2. 状态计算
			如何计算每一个状态

99. 其他经验
	1.
		1. 背模板
		2. 默写(以课后习题来默写)
		3. 增加熟练度: 删除后,写3-5遍
	2. 边界问题
		背模板
	3. 当输入数据多的时候
		c
			选择scanf(),而不是cin<<
		java
			选择bufferRead(),而不是scaner()
			scanner()慢10倍
	算法和工程
		1. 算法:
			自己看得懂
		2. 工程:
			让别人看懂
			为了以后容易维护
	参与人数：267  


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
							2. 用两个指针3. 高精度计算
						4, quick_sort一般算法竞赛不会自己写,一般都是面试考官喜欢问

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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/39784/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
						O(nlogn)
						```

						#include <iostream>

						using namespace std;

						const int N = 1e6 +10;

						int n;
						int q[N];

						void quick_sort(int q[], int l, int r){
						    if(l >= r) return;
						    swap(q[l], q[rand() % (r-l+1) + l]);
						    
						    int x = q[l], i = l - 1, j = r + 1;
						    while(i < j){
						        do i++; while(q[i] < x);
						        do j--; while(q[j] > x);
						        if(i < j) swap(q[i], q[j]);
						    }
						    quick_sort(q, l, j);
						    quick_sort(q, j+1, r);
						}

						int main(){
						    scanf("%d", &n);
						    for(int i = 0; i < n; i ++) scanf("%d", &q[i]);
						    
						    quick_sort(q, 0, n-1);
						    
						    for(int i = 0; i < n; i++) printf("%d ", q[i]);
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
						复杂度是O(n):
							因为是n + n/4 + n/8 +… = 2n
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
						2. 注意进一
						3. auto c : list/vector/迭代器
							c11新特色
					4. 加减乘除
						1. 格式都要一样: 也就是数字低位在index==0的地方
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

						vector<int> add2(vector<int> &A, vector<int> &B) //这里是传入地址.所以就不需要复制
						{
						    if(A.size() < B.size()) return add2(B,A);

						    int t = 0; //进位
						    vector<int> C;
						    for(unsigned int i = 0; i < A.size(); i++) //需要选择最长的那个
						    {
						        if(i < A.size()) t += A[i];
						        if(i < B.size()) t += B[i];
						        C.push_back(t % 10); //C的index==0位置是数字的最低位
						        t /= 10;
						    }
						    if(t) C.push_back(t);
						    return C;
						}

						vector<int> add(vector<int> &A, vector<int> &B) //这里是传入地址.所以就不需要复制
						{
						    int t = 0; //进位
						    vector<int> C;
						    for(unsigned int i = 0; i < A.size() || i < B.size(); i++) //需要选择最长的那个 //注意不能用 int i, 编译出错
						    {
						        if(i < A.size()) t += A[i];
						        if(i < B.size()) t += B[i];
						        C.push_back(t % 10); //C的index==0位置是数字的最低位
						        t /= 10;
						    }
						    if(t) C.push_back(t);
						    return C;
						}

						int main()
						{
						    string a,b;//传入的大数字
						    vector<int> A, B; //存到数组

						    cin >> a >> b;
						    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0');
						    for(int i = b.size()-1; i >= 0; i --) B.push_back(b[i] - '0'); //注意这里是char '0'

						    auto C = add2(A, B); //相当于vector<int> C = add(A,B);
						    for(int i = C.size()-1 ; i >= 0; i--) printf("%d",C[i]);
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
						        C.push_back( (temp + 10) % 10); //如果temp = -2, 那么就是8. 如果temp = 2, 那么就是2
						        if(temp >= 0) t = 0; 
						        else t = 1; //注意:一定要严格temp < 0才表明借了
						    }

						    //删除数字高位的0, 也就是C index末尾, 也就是C.back
						    while(C.size() > 1 && C.back() == 0) C.pop_back(); //语意: while里面是要pop掉的条件, 所以允许0,但是不允许003

						    return C;
						}
						int main(){
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

						vector<int> mul2(vector<int> &A, int b){
						    vector<int> C;
						    int t = 0;
						    for(unsigned int i = 0; i < A.size() || t ; i++) //合并了while
						    {
						        if(i < A.size()) t = A[i] * b + t; //还有上一次的
						        C.push_back(t % 10);
						        t /= 10;
						    }

						    while(C.size() > 1 && C.back() == 0) C.pop_back();


						    return C;
						}

						vector<int> mul(vector<int> &A, int b){
						    vector<int> C;
						    int t = 0;
						    for(unsigned int i = 0; i < A.size() ; i++)
						    {
						        t = A[i] * b + t; //还有上一次的
						        C.push_back(t % 10);
						        t /= 10;
						    }

						    while(t){
						        C.push_back(t % 10);
						        t /= 10;
						    }

						    //bug: 忘记删除前置0了, 例如C是300, 意味着是003, 但是答案应该是3
						    while(C.size() > 1 && C.back() == 0) C.pop_back();

						    return C;
						}
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
						        r = r * 10 + A[i]; //首先看上一轮遗留下来的余数, *10, 然后加上这意味的
						        C.push_back(r / b); //除以b,这里可能得到的是0.
						        r %= b; //剩下的余数,给下一轮. 
						    }

						    reverse(C.begin(), C.end());//假设C是0013,其实代表是数字31,所以先翻转,变成3100,最后去掉末尾的0
						    while(C.size() > 1 && C.back() == 0) C.pop_back();

						    return C;
						}




						int main(){
						    string a;
						    int b;

						    cin >> a >> b;

						    vector<int> A;
						    for(int i = a.size()-1; i >= 0; i--) A.push_back(a[i] - '0'); //其实可以从i = 0推入,因为出发是从最高位开始.但是+-*都是从数字最低位开始

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
					1. 最大和唯一的用处
						求一段区间的复杂度,从O(n)到O(1)
							假设有a0,a1,a2..,an
								其中a0 = 0, 方便计算
							其中Sn = a0 + a1 + a2 + .. + an
								S0 = 0
							Sn+1 = Sn + a_(n+1)
						作用
							Sm - Sn就是(n, m]左开右闭的总和,也就是[n+1, m]的和
							[n+1,m]不用前缀和是O(n) : a_(n+1) + a_(n+2) + ... + am
							用前缀和是O(1):
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
									一般不存在求[0,9]
										因为[1,9]是题目中给的info,但是一般[0]这个是我们自己添加的
					2. 子矩阵的和(相当于二维的前缀)
						公式:
							配合画图 #001 https://www.acwing.com/video/239/ 12:19
							Sum((x1,y1), (x2, y2)) 
								= S[x2, y2] - S[x1 - 1, y2] - S[x2, y1 - 1] + S[x1 - 1, y1 - 1]
								= 大矩形 - 上侧 - 左侧 + 左上的小矩形
								注意,是4个下标
							S[i, j] 
								= S[i-1, j] + S[i, j-1] - S[i-1, j-1] + a[i,j]
								= 上侧 + 左侧 - 左上侧小矩形 + 本次a[i,j]
			
				4. 差分
					一维差分
						B[1] = A[1] ,B[i] = A[i] - A[i-1] ( 2<=i<=n)
							  容易发现，“前缀和” 和 “差分” 是一对互逆运算，差分序列B的前缀和序列就是原序列A，前缀和序列S的差分序列也是原序列A。
							  把序列A的区间 [l,r] 加上 d（即把 Al，Al+1, ……, Ar 都加上 d），其差分序列 B 的变化为 Bl 加 d，Br+1 减 d，其余位置不变。
							 
						举例
							列如数列 1 3 6 3 9 10 20，让位置在[2,5]范围内加 10
								这里认为第一个数字的index是1, 所以[[2,5]]是指3,6,3,9
							先转化为他的差分序列：1 2 3 -3 6 1 10
								处理后：1 12 3 -3 6 -9 10
							他的原序列就是差分序列的前缀和：1 13 16 13 19 10 20
					二维差分
						我喜欢的一点
							整个矩阵代表着b,所以矩阵的面积的和(b的和)就是a
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
						           //S[i][j] += S[i-1][j] + S[i][j-1] - S[i-1][j-1]; //method 2;
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

						void insert(int l, int r, int v){
						    b[l] += v;
						    b[r+1] -= v;
						    return;
						}
						int main(){
						    int n,m;
						    cin >> n >> m;

						    for(int i = 1; i <= n ; i ++) scanf("%d",&a[i]); //填充a

						    for(int i = 1; i <= n; i ++) insert(i, i, a[i]); //构建b

						    while(m --){
						        int l, r, v;
						        scanf("%d%d%d", &l, &r, &v);

						        insert(l, r, v);
						    }

						    for(int i = 1; i <= n; i++) a[i] = a[i-1] + b[i]; //将b累加,变成新的a
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

						        if(a[i] + b[j] == v) {  //题目保证: 有唯一解
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
					3. 求lowbit(x)
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
						        不去重的话,all也是递增序列,我们的find()因为返回的是第一个>=x的位置,所以没有影响
						    去重的话
						        会只有唯一的x
						        所以find()返回第一个>=x的数,也就一定是x本身而不是>x的数
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
						        if(all[mid] >= x) r = mid;
						        else l = mid + 1;
						    }

						    return l + 1;//因为前缀和一般都是1开始处理
						}


						vector<int>::iterator unique(vector<int> &a)
						{
						    int j = 0;//指向非重数组的下一位
						    for(int i = 0; i < (int)a.size();) 
						    {
						        if(i == 0) a[j++] = a[i]; //数组的第一位一定是满足条件的
						        while(j <= i && a[j-1] != a[i]) a[j++] = a[i++];  //因为是递增的,所以一旦不等于,就说明不是重复
						    }
						    return a.begin() + j;
						}

						vector<int>::iterator unique_from_yxc(vector<int> &a)
						{
						    int j = 0;
						    for (int i = 0; i < a.size(); i ++ )
						        if (!i || a[i] != a[i - 1])
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
						    all.erase(unique(all.begin(), all.end()), all.end());
						    //all.erase(unique(all), all.end()); //unique()返回的是没有重复元素的数组的下一个元素的位置. 从这个位置开始,到末尾,都是重复元素被放置的地方. 这部分给erase()删除

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
						自己创建的比stl快一些, 因为算法竞赛中不会使用O2,O3(氧气优化,臭氧优化)优化.
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

						    // 0是左端点，1是右端点
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
						        else
						        {
						            cin >> k >> x;
						            insert(k + 1, x);
						        }
						    }

						    for (int i = r[0]; i != 1; i = r[i]) cout << e[i] << ' ';
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
						            q[ ++ tt] = x;
						        }
						        else if (op == "pop") hh ++ ;
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
						        while (tt && stk[tt] >= x) tt -- ;
						        if (!tt) printf("-1 ");
						        else printf("%d ", stk[tt]);
						        stk[ ++ tt] = x;
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

						int a[N], q[N];

						int main()
						{
						    int n, k;
						    scanf("%d%d", &n, &k);
						    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

						    int hh = 0, tt = -1;
						    for (int i = 0; i < n; i ++ )
						    {
						        if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;

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

						int son[N][26], cnt[N], idx;
						char str[N];

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
						    每个数字,需要O(32)寻找匹配,相当于O(logn)?
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
						int p[N], d[N];

						int find(int x)
						{
						    if (p[x] != x)
						    {
						        int t = find(p[x]); //这里会递归调用, t最后都是祖先的ind
						        d[x] += d[p[x]]; //这里也会递归调用,也就是d[父之父] += d[父之父之父], 之后d[父] += d[父之父], 最后 d[我] += d[父]
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

						        if (x > n || y > n) res ++ ;
						        else
						        {
						            int px = find(x), py = find(y);
						            if (t == 1)
						            {
						                if (px == py && (d[x] - d[y]) % 3) res ++ ; //如果是同一个结合, 如果 d[x] % 3 != d[y] % 3, 就是说明不是同类
						                else if (px != py) //不是同一个集合, 说明这是一句真话,或者我们认为这是一句没有矛盾的话
						                {
						                    p[px] = py; //px的父亲变成py
						                    d[px] = d[y] - d[x];  //修改距离: 所以你看之前说的xx层不是真的层,而是需要d[]来维护距离
						                    //因为是同类, 需要 (d[x] + ? ) % 3 == d[y] % 3, 所以? = d[y] - d[x], 所以d[px] 就是?的值
						                
						                    //https://www.acwing.com/video/19/ 的01:06:30
						                }
						            }
						            else
						            {
						                
						                if (px == py && (d[x] - d[y] - 1) % 3) res ++ ; //注意d[x] - d[y] - 1) % 3 !=0, 不能换成d[a] - d[b]) % 3 != 1. 注意(d[a] - d[b]) % 3可能是负数，需要转化成正数：((d[a] - d[b]) % 3 + 3) % 3 //看是否是x吃y,也就是d[x]的余数比d[y]的余数大1, d[x] % 3 == d[y] % 3 + 1;
						                // d[x] % 3 == d[y] % 3 + 1 % 3;  d[x] % 3 == (d[y] + 1) % 3;
						                else if (px != py)
						                {
						                    p[px] = py;
						                    d[px] = d[y] + 1 - d[x];//修改距离: 所以你看之前说的xx层不是真的层,而是需要d[]来维护距离
						                    //因为是同类, 需要 (d[x] + ? ) % 3 == d[y] % 3 + 1, 所以? = d[y] - d[x] -1
						                    //但是老师的?和我的?刚好是相反数
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
								记得同时down(x);up(x);
								因为替换过来的最后一个ele可能比被删除的ele要大或者要小都可能
							2. 修改任意ele的值
					回忆
						完全二叉树
						小根堆: 父亲 <= 左右儿子
					复杂度
						如果是一个一个加入,然后siftDown()复杂度是O(n*logn):因为一个元素需要向下logn层,一共n个元素
						如果是heapify,也就是直接整个数组,从倒数第2层的最后一个元素开始siftDown()复杂度是O(n)
							因为倒数第二层有n/4个元素,每个元素只需往下siftdown 1层
							因为倒数第3层有n/8个元素,每个元素只需往下siftdown 2层
							..
							所以复杂度是 (n/4 * 1) + (n/8 * 2) + ... 最后推到看https://www.acwing.com/video/17/的01:39:00
							总之就是O(n * 1)
					老师的习惯
						从ind == 1开始
						所以size指向的是最后一个已经有的元素,而不是最后一个元素的下一位
						然后左儿子 = x * 2, 右儿子 = x * 2 + 1
						父节点 = x / 2
					老师说
						层数不高,所以down()里面采用的是递归,而不是while实现.

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
						    int t = u;
						    if (u * 2 <= cnt && h[u * 2] < h[t]) t = u * 2;
						    if (u * 2 + 1 <= cnt && h[u * 2 + 1] < h[t]) t = u * 2 + 1;
						    if (u != t)
						    {
						        swap(h[u], h[t]);
						        down(t);
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/45305/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
							用0x3f3f3f3f, 并且memset(xx, 0x3f,sizeof xx)
								用0x3f3f3f3f	,因为
									1. 比题目范围10^9大
									2. 是重复模式,可以用memset()表示
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
						3, 删除
							不会真的删除,而是在哈希表的映射元素(链表)中的该元素的bool设置成false
			
				13. 字符串哈希
					str = "ABCDEFSFOIJER"
					h[n]: 前n个字符的hash值
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
								mod的数字是2^64
							4.  用unsigned long long的溢出代替mod

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
										2. 因为h[R]的值是
											"ABCDE"的hash值
											注意A是高位,E是低位
											长度是R,也就是5
											所以A是第R-1位, E是第0位
											A*p^(R-1) + B*p^(R-2) + .. E*p^0
											A*p^4 + B*p^3 + .. E*p^0
										3. 因为h[L-1]的值是"AB"的hash值
											注意A是高位,E是低位
											长度是L-1,也就是2
											所以A是第L-2位, B是第0位
											所以A*p^1 + B*p^0
										4. 所以xxx = h[R] - h[L-1]*p^(R-L+1) 后
											因为A从L-2的幂次,变成了R-1的幂次,需要乘上(R - L + 1)次幂
											最后我们剩余的就是
											C*p^2 + D*p^1 + E*p^0
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

							int h[N];

							int find(int x)
							{
							    int t = (x % N + N) % N;
							    while (h[t] != null && h[t] != x)
							    {
							        t ++ ;
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

						2. 拉链法
							#include <cstring>
							#include <iostream>

							using namespace std;

							const int N = 100003;

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

							作者：yxc
							链接：https://www.acwing.com/activity/content/code/content/45308/
							来源：AcWing
							著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/45313/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
												一般是O(e), 最坏(n*e)
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/47087/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					2. b
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			37. 843. n-皇后问题	dfs
				0. bug
				1. 笔记
				2. 注释
					1. y
						1. 第一种搜索顺序
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
							            for (int i = 0; i < n; i ++ ) puts(g[i]);
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
						
						2. 第二种搜索顺序
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

							作者：yxc
							链接：https://www.acwing.com/activity/content/code/content/47097/
							来源：AcWing
							著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
					
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

						            if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && d[x][y] == -1) //如果已经搜到过了, d[x][y] != -1, 就不需要遍历了,因为我们找的就是最短距离. 我的疑问:会不会以前搜到过,但是后来走不通. 但是这次虽然再次搜到,可是这次走的通?
						            //我认为可能再次搜到,也一样走不通,因为BFS本身就是一层一层的搜的
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/465891/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			39. 845. 八数码
				0. bug
				1. 笔记
				2. 注释
					1. y
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/48146/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/47105/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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

						作者：yxc
						链接：https://www.acwing.com/activity/content/code/content/47104/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
							4: 1..
							..

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
									最坏O(v*e),但是实际运行效果非常好,远小于(ve) 
									思想
										如果我想要匹配的女生a,被其他男生b占据了,我就让这个b看看有没有其他女生c可以匹配,最后bc匹配,我和a匹配
									为什么是O(v*e)
										v/2个男生,每个可能都需要让其他男生看看其他e条边能否匹配
										因为其实其他男生可能不需要找很多次,所以实际运行远小于O(v*e)
								最大流
									先不讲

			42. 拓扑- 848. 有向图的拓扑序列
				0. bug
				1. 笔记
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/466157/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
						    for (int i = 0; i < k; i ++ ) //题目要求:不超过k条边
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/467234/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
						    所以我们存储dist变小的节点
						2. 用queue(其实用heap也可以)存所有dist变小的节点abc
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
						    q.push(1);
						    st[1] = true; //说明放入queue里面

						    while (q.size())
						    {
						        int t = q.front();
						        q.pop();

						        st[t] = false; //说明从queue取出

						        for (int i = h[t]; i != -1; i = ne[i]) //遍历t节点的邻接点
						        {
						            int j = e[i];
						            if (dist[j] > dist[t] + w[i])
						            {
						                dist[j] = dist[t] + w[i];
						                if (!st[j]) //如果不在queue里面,就放入. 如果在,那以后会在queue中取出它的
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
						    等于经过节点1到节点k-1,我们从i节点到k节点的最短距离 加上 经过节点1到节点k-1,我们从k节点到j节点的最短距离
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/468062/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

			51. 染色- 860. 染色法判定二分图
				0. bug
				1. 笔记
				2. 注释
					1. y
					2. b
						#include <cstring>
						#include <iostream>
						#include <algorithm>

						using namespace std;

						const int N = 100010, M = 200010; //因为是无向图, 所以题目给了一条边,我们其实要存两条,所以是20w

						int n, m;
						int h[N], e[M], ne[M], idx; //临界表
						int color[N];

						void add(int a, int b)
						{
						    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
						}

						bool dfs(int u, int c)
						{
						    color[u] = c; //将u节点染成1

						    for (int i = h[u]; i != -1; i = ne[i]) //u节点的临街点
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
						        add(a, b), add(b, a);
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

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/468238/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
						        if (!st[j])//如果这个女生已经被男生i看过了,以后就不会再看了
						        {
						            st[j] = true;
						            if (match[j] == 0 || find(match[j])) //如果这个女生单身: match[j] == 0, 或者虽然脱单但是她男朋match[j]可以找到其他女生. 
						            //之所以可以用find让这个Match[j]找到其他女生而不是女生j是因为,st[j]==true,但是男生只会接受女生一次.
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
						        //男找女,如果此女已经匹配,再看匹配她的男生是否还有其他喜欢的女生
						        //所以只用存男生节点的临边
						    }

						    int res = 0; //当前匹配的数量

						    for (int i = 1; i <= n1; i ++ )
						    {
						        memset(st, false, sizeof st);//对于每个男生i, 都会将所有的女生都设置成false,意思是女生都还没看
						        if (find(i)) res ++ ;
						    }

						    printf("%d\n", res);

						    return 0;
						}

						作者：jackrrr
						链接：https://www.acwing.com/activity/content/code/content/468306/
						来源：AcWing
						著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				3. 5次
					r1.
					r2.
					r3.
					r4.
					r5.

4. 数学知识
	1. 质数
			53.


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


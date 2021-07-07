1.
	1. AcWing 13. 找出数组中重复的数字
		1. 其实这道题还是比较简单的
			0. 剑指offer的特点: 题目虽然说了范围是 0~(n-1), 但是真实还会给奇怪的数字
			1. 常规做法:
				时间 O(n)
				空间 O(n)	因为开辟了set
					class Solution {
					public:
					    int duplicateInArray(vector<int>& nums) {
					        unordered_set<int> s;
					        int n = nums.size();
					        for(auto x : nums) if (x < 0 || x >= n) return -1;
					        for(auto x : nums){
					            if(s.count(x)) return x;
					            s.insert(x);
					        }
					        return -1;
					    }
					};
			2. 优化做法:
				时间 O(n)
				空间 O(1)
				优化做法的确很有意思:
					想象画面, 就是每个人都有每个人的固定的位置, 第i号房间, 必须住的是值==i的人
		2. 解释:
			class Solution {
			public:
			    int duplicateInArray(vector<int>& nums) {
			        int n = nums.size();
			        for (auto x : nums)
			            if (x < 0 || x >= n)
			                return -1;
			        for (int i = 0; i < n; i ++ ) {
			            while (nums[i] != i && nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
			            	nums[i]: 住在第i个房间的人, 叫a
			            	nums[i] != i: 住在第i个房间的人并不是i本人
			            	nums[nums[i]]: 住在第a个房间的人
			            	nums[nums[i]] != nums[i]: 住在第a个房间的人, 也并不是a本人
			            	我们就交换, 让a本人住到它应该住的房间 nums[a]
			            	这里想象画面:
			            		如果刚好是n个人, n个房间, 相当于所有的人在调到第一个房间之后, 都会被推到自己应该所属的房间{就像让让a本人住到它应该住的房间 nums[a]}
			            		所以swap最多执行了n次
			            if (nums[i] != i && nums[nums[i]] == nums[i]) return nums[i];
			            	跳出while的条件:
			            		本来是我a住到我应该住的房间 nums[a], 但是竟然发现那个房间竟然有我a, 多余竟是我自己?!
			            		所以: nums[nums[i]] == nums[i]
			            		除了上面的这句, 还有一个现象就是, 我a没有被移动到我应该住的房间 nums[a], 说明我a在别人的房间{在i这个人的房间}
			            		所以: nums[i] != i
			        }
			        return -1;
			    }
			};
			优化:
				class Solution {
				public:
				    int duplicateInArray(vector<int>& nums) {
				        int n = nums.size();
				        for (auto x : nums)
				            if (x < 0 || x >= n)
				                return -1;
				        for (int i = 0; i < n; i ++ ) {
				            while (nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
				            	其实: 如果 nums[i] == i, 那么 nums[nums[i]] == nums[i] == i 这一串都是成立的
				            	所以当 nums[nums[i]] == nums[i], 说明 nums[i] == i 
				            	但是反过来
				            if (nums[i] != i) return nums[i];

				        }
				        return -1;
				    }
				};
		3. 小bug
			class Solution {
			public:
			    int duplicateInArray(vector<int>& nums) {
			        int n = nums.size();
			        for(auto i : nums) if(i < 0 || i >= n) return -1;	注意要先遍历一遍, 否则可能存在有一个非法值, 我们还没来得及判断就 return nums[i]了
			        for(int i = 0; i < n; i++){
			            while(nums[i] != i && nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
			            错: if(nums[nums[i]] == nums[i]) return nums[i];		不应该判断第a个房间是不是a
			            对: if(nums[i] != i) return nums[i];					应该判断第i个房间是不是i
			        }
			        return -1;
			    }
			};
			背保守写法:
				while(nums[i] != i && nums[nums[i]] != nums[i]) swap(nums[i], nums[nums[i]]);
					当第i个房间里面不是i, 而是a, 当第a个房间的人不是a. 让a本人住到它应该住的房间
				if (nums[i] != i && nums[nums[i]] == nums[i]) return nums[i];
					当第i个房间里面不是i, 而是a, 当第a个房间的人却是a. 多余竟是我自己
	2. AcWing 14. 不修改数组找出重复的数字
		1. 这道题, 还是扩展了我的思路
			class Solution {
			public:
			    int duplicateInArray(vector<int>& nums) {
			        int l = 1, r = nums.size() - 1;
			        while (l < r) {
			            int mid = l + r >> 1; // 划分的区间：[l, mid], [mid + 1, r]
			            int s = 0;
			            for (auto x : nums) s += x >= l && x <= mid;
			            if (s > mid - l + 1) r = mid;
			            else l = mid + 1;
			        }
			        return r;
			    }
			};
		2. 故事是这样的
			我们有一个题目给的nums数组, 一共n+1个元素, 值在[1,n], 所以一定有一个值是出现了2次
				抽屉原理：n+1 个苹果放在 n 个抽屉里，那么至少有一个抽屉中会放两个苹果
			我们二分, 二分的并不是nums数组, 而是值
				left: 值是[1, n/2]的元素, 我们看看nums数组中, 有多少个元素是的值在 [1, n/2] 中, 假设有x个元素是的值在 [1, n/2] 中
					如果 x > left区间长度, 也就是 x > n/2 - 1 + 1
						说明值在 [1, n/2] 之中的元素, 有两个是重复的
				right同理 
		3. 复杂度:
			时间复杂度：
				每次会将区间长度缩小一半，一共会缩小 O(logn) 次
				每次统计两个子区间中的数时需要遍历整个数组，时间复杂度是 O(n) {即我们看看nums数组中, 有多少个元素是的值在 [1, n/2] 中, 多少是在 [n/2, n]中}
				所以总时间复杂度是 O(nlogn)
			空间复杂度：代码中没有用到额外的数组，所以额外的空间复杂度是 O(1)
		4. 
			class Solution {
			public:
			    int duplicateInArray(vector<int>& nums) {
			        int l = 1, r = nums.size() - 1;
			        while (l < r) {
			            int mid = l + r >> 1; // 划分的区间：[l, mid], [mid + 1, r]
			            int s = 0;	计算个数
			            for (auto x : nums) s += (x >= l && x <= mid);	s += 0, 或者, s += 1;
			            if (s > mid - l + 1) r = mid;	左侧区间, 理应有区间长度个元素, 可是现在发现有多余的元素, 说明我们要往左找, 其中mid也是候选人
			            else l = mid + 1;
			        }
			        return r;
			    }
			};
		5. 超级顺利的 
			class Solution {
			public:
			    int duplicateInArray(vector<int>& nums) {
			        int l = 1, r = nums.size() - 1; // nums.size() == n + 1
			        while(l < r){
			            int mid = l + (r - l) / 2;
			            int cnt = 0;
			            for(auto i : nums) cnt += (l <= i && i <= mid);
			            if(cnt > mid - l + 1) r = mid;
			            else l = mid + 1;
			        }
			        return r;
			    }
			};
	3. AcWing 15. 二维数组中的查找
		1. 最坏是 O(n*m), 其实最快是 O(n+m)
		2. 这个解释很好: https://www.acwing.com/solution/content/702/
			因此我们可以从整个矩阵的右上角开始枚举，假设右上角的数是 xx：
				如果 xx 等于target，则说明我们找到了目标值，返回true；
				如果 xx 小于target，则 xx 左边的数一定都小于target，我们可以直接排除当前一整行的数； i++
				如果 xx 大于target，则 xx 下边的数一定都大于target，我们可以直接排序当前一整列的数； j--;
			每一步会排除一行或者一列，矩阵一共有n行m列，所以最多会进行 n+m 步
				所以时间复杂度是 O(n+m)
		3. 超级顺利 
			class Solution {
			public:
			    bool searchArray(vector<vector<int>> array, int target) {
			        if(!array.size() || !array[0].size()) return false;
			        int i = 0, j = array[0].size() - 1;		
			        while(i < array.size() && j >= 0){
			            int x = array[i][j];
			            if(x == target) return true;
			            else if(x > target) j--;    //往左找
			            else i++;                   //往下找
			        }
			        return false;
			    }
			};
	4. AcWing 16. 替换空格 
		1. 无脑模拟题
			class Solution {
			public:
			    string replaceSpaces(string &str) {
			        string res;
			        for(auto c : str){
			            if(c == ' ') res += "%20";
			            else res += c;
			        }
			        return res;
			    }
			};
		2. 你如果是想在参数上直接做修改
			class Solution {
			public:
			    string replaceSpaces(string &str) {
			        //先计算, 我们最后需要的空间有多大, 也就是如果遇到了' ', 我们需要多2个空间
			        int len = 0;
			        for(auto c : str){
			            if(c == ' ') len += 3;
			            else len ++;
			        }
			        对: int i = str.size() - 1, j = len - 1;    //i是指向str原有的内容的尾巴, j是指向新开辟空间的尾巴
			        str.resize(len); //将str的末尾再开辟一些空间
			        //为了不污染str前面的内容, 我们的复制从str的末尾开始
			        错: int i = str.size() - 1, j = len - 1;    不能这么写, 这里str.size()已经是扩大的了!!
			        while(i >= 0){
			            if(str[i] == ' '){
			                str[j--] = '0'; 
			                str[j--] = '2'; 
			                str[j--] = '%'; //倒着填上 %20
			            }else{
			                str[j--] = str[i];
			            }
			            i--;
			        }
			        return str;
			    }
			};
	5. AcWing 17. 从尾到头打印链表
		1. 递归写法, 小bug
			class Solution {
			public:
			    vector<int> printListReversingly(ListNode* head) {
			        auto tail = rev(head);
			        vector<int> res;
			        错: for(auto cur = tail; !cur; cur = cur->next){		for(合法状态), 我是脑袋抽了? 之前是 for(int i = h[a]; ~i; i = ne[i]) 我可能习惯上觉得i前面有个东西, 就想 ~i
			        对: for(auto cur = tail; cur; cur = cur->next){		
			            res.push_back(cur->val);
			        }
			        return res;
			    }
			    
			    ListNode* rev(ListNode* head){
			        错: if(!head || !head->next) return nullptr;		这个不管什么都是返回空, 这是不对的!
			        对: if(!head || !head->next) return head;		如果 head是空 就是 return 空{head}
			        												如果 head非空, 但是 head->next是空, return 非空{head}
			        auto tail = rev(head->next);
			        head->next->next = head;
			        head->next = nullptr;
			        return tail;
			    }
			};
		2. 无脑迭代写法: 其实我以前运筹课不理解的迭代, 就是简单的 for()/while()
			class Solution {
			public:
			    vector<int> printListReversingly(ListNode* head) {
			        vector<int> res;
			        while(head){
			            res.push_back(head->val);
			            head = head->next;
			        }
			        错: return vector<int>(res.end(), res.begin());		不能这么写, 报错
			        对: return vector<int>(res.rbegin(), res.rend());
			    }
			};
	6. AcWing 18. 重建二叉树
		1. 哇, 没有参考任何代码, 超级无敌顺利
			中序的作用: 知道左右子树的大小
			class Solution {
			public:
			    unordered_map<int, int> pos;
			    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
			        int n = inorder.size();
			        for(int i = 0; i < n; i++) pos[inorder[i]] = i;
			        return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
			    }
			    TreeNode* dfs(vector<int> &pre, vector<int> &in, int pl, int pr, int il, int ir){
			        if(pl > pr) return nullptr;
			        TreeNode* root = new TreeNode(pre[pl]);
			        int k = pos[root->val];							
			        int left = k - 1 - il + 1;//[il, k - 1]				知道左子树的大小{元素个数}
			        // int right = ir - k - 1 + 1; //[k + 1, ir];		知道右子树的大小{元素个数}
			        root->left = dfs(pre, in, pl + 1, pl + left, il, k - 1);
			        root->right = dfs(pre, in, pl + left + 1, pr, k + 1, ir);
			        return root;
			    }
			};
	7. AcWing 19. 二叉树的下一个节点 
		1. 哇, 也是没有参考任何代码, 超级顺利的
			class Solution {
			public:
			    TreeNode* inorderSuccessor(TreeNode* p) {
			        if(p->right){			有右儿子	
			            p = p->right;		去右儿子
			            while(p->left) p = p->left;		如果有左儿子, 去左儿子
			            return p;						如果没有左儿子, 左儿子竟是我自己
			        }
			        while(p->father && p == p->father->right) p = p->father;	如果有爸爸 && 我是爸爸的右儿子: 	向上
			        	退出while: 
			        		1. 没有爸爸{我没有下一个节点, 下一个节点是nullptr}
			        		2. 有爸爸, 我是爸爸的左儿子
			        	所以: while(不合法), 退出while就是合法的: 也就是我们想要的{我是爸爸的左儿子}
			        return p->father;	没有爸爸相当于爸爸是nullptr, 刚好下一个节点也是nullptr
			    }
			};

			1. 如果有右儿子, 答案就是右儿子的左儿子的左儿子的左儿子...
			2. 否则, 如果我是我父亲的左儿子, 答案就是我父亲
	8. AcWing 20. 用两个栈实现队列
		1. 这道题很简单, 有种倒开水的感觉
			开水从杯子a, 倒到杯子b
			在杯子a底部的水, 倒到杯子b后就变成b顶部的水
		2. 还是很顺利
			class MyQueue {
			public:
			    对: stack<int> stk, cache;
			    /** Initialize your data structure here. */
			    MyQueue() {
			        错: stack<int> stk, cache; 不应该写在这里
			    }
			    
			    /** Push element x to the back of queue. */
			    void push(int x) {
			        stk.push(x);
			    }
			    
			    void poll(stack<int> &a, stack<int> &b){	这是我自己加的函数: 将a的东西倒给b
			        while(a.size()){
			            b.push(a.top());
			            a.pop();
			        }
			    }
			    
			    /** Removes the element from in front of queue and returns that element. */
			    int pop() {
			        poll(stk, cache);
			        int res = cache.top(); cache.pop();
			        poll(cache, stk);
			        return res;
			    }
			    
			    /** Get the front element. */
			    int peek() {
			        poll(stk, cache);
			        int res = cache.top();
			        poll(cache, stk);
			        return res;
			    }
			    
			    /** Returns whether the queue is empty. */
			    bool empty() {
			        return stk.empty();
			    }
			};
	9. AcWing 21. 斐波那契数列
		1. 具体看要求的数据量吧, 这个总结的不错: https://www.acwing.com/blog/content/25/
		2. 这道题因为数据量小, 所以直接递归
			不过注意:
				n==0的时候, 有的题目是 Fibonacci(0)==0, 有的题目是 Fibonacci(0) == 1
			class Solution {
			public:
			    int Fibonacci(int n) {
			        if(n <= 1) return n;		因为 题目是 Fibonacci(0)==0
			        return Fibonacci(n-1) + Fibonacci(n-2);
			    }
			};
		3. 其他总结
			1. 能算到 n == 40 左右, 递归:
				时间复杂度是 O(2^n)，一秒内大约能算到第30-40项
				const int MOD = 1e9+7;
				int f(int n)
				{
				    if (n <= 1) return 1;		题目是 Fibonacci(0)==1
				    return (f(n - 1) + f(n - 2)) % MOD;
				}
			2. 能算到 n == 1e5 左右, 记忆化搜索
				时间复杂度是 O(n), 一秒内算 n=1e7 毫无压力，但由于是递归计算，递归层数太多会爆栈，大约只能算到 n=1e5 级别
				const int N = 1e5, MOD = 1e9+7;
				int a[N];
				int f2(int n)
				{
				    if (a[n]) return a[n];
				    if (n <= 1) return 1;
				    a[n] = f2(n - 1) + f2(n - 2);
				    a[n] %= MOD;
				    return a[n];
				}
			3. 能算到 n == 1e8 左右, 迭代{for}
				时间复杂度是 O(n), 但是空间大, 1e8 * 4 / (1024*1024) == 381MB
				const int N = 1e8, MOD = 1e9 + 7;
				int a[N];
				int f3(int n)
				{
				    a[0] = a[1] = 1;
				    for (int i = 2; i <= n; i ++ )
				    {
				        a[i] = a[i - 1] + a[i - 2];
				        a[i] %= MOD;
				    }
				    return a[n];
				}
			4. 不需要存历史值: 递归 + 滚动变量
				时间复杂度是 O(n), 空间复杂度是 O(1)
				const int MOD = 1e9 + 7;
				int f4(int n)
				{
				    int x, y, z;
				    x = y = 1;
				    for (int i = 2; i <= n; i ++ )
				    {
				        z = (x + y) % MOD;
				        x = y;
				        y = z;
				    }
				    return z;
				}
			5. 快速幂: 时间复杂度是 O(logn)
				#include <cstdio>
				#include <cstring>
				#include <iostream>
				#include <algorithm>
				#include <ctime>

				using namespace std;

				const int MOD = 1000000007;

				void mul(int a[][2], int b[][2], int c[][2])
				{
				    int temp[][2] = {{0, 0}, {0, 0}};
				    for (int i = 0; i < 2; i ++ )
				        for (int j = 0; j < 2; j ++ )
				            for (int k = 0; k < 2; k ++ )
				            {
				                long long x = temp[i][j] + (long long)a[i][k] * b[k][j];
				                temp[i][j] = x % MOD;
				            }
				    for (int i = 0; i < 2; i ++ )
				        for (int j = 0; j < 2; j ++ )
				            c[i][j] = temp[i][j];
				}


				int f_final(long long n)
				{
				    int x[2] = {1, 1};

				    int res[][2] = {{1, 0}, {0, 1}};
				    int t[][2] = {{1, 1}, {1, 0}};
				    long long k = n - 1;
				    while (k)
				    {
				        if (k&1) mul(res, t, res);
				        mul(t, t, t);
				        k >>= 1;
				    }

				    int c[2] = {0, 0};
				    for (int i = 0; i < 2; i ++ )
				        for (int j = 0; j < 2; j ++ )
				        {
				            long long r = c[i] + (long long)x[j] * res[j][i];
				            c[i] = r % MOD;
				        }

				    return c[0];
				}


				int main()
				{
				    long long n ;

				    cin >> n;
				    cout << f_final(n) << endl;

				    return 0;
				}

	最多两个升序
	如果没有重复项目, 就是 logn
	如果有重复项, 最坏是 O(n)
	"平移数组"的最小元素
	"平移": 形容词, 而不是动词

	说明删除完了 == nums[0]的东西后, 第二段没了
	或者本来就没有第二段


	     /
	    /
	   /
	  a
	 /
	/


	    /
	   /
	  /
	 a 		  
	 		  a
			 /
			/


			      /
			     /
	   a_______b/
	  /
	 /
	/


	     /
	    /
	__b/   a_____
		  /
		 /
		/


		class Solution {
		public:
		    int findMin(vector<int>& nums) {
		        // 忘写:
		        if(!nums.size()) return -1;
		        // int n = nums.size();
		        int n = nums.size() - 1;
		        // while(n >= 0 && nums[n] == nums[0]) n--; //不小心会n==-1, 之后 nums[-1] 很危险
		        while(n > 0 && nums[n] == nums[0]) n--; 
		        if(nums[n] >= nums[0]) return nums[0];
		        int l = 0, r = n;
		        while(l < r){
		            int mid = l + (r - l) / 2;
		            if(nums[mid] < nums[0]) r = mid; //mid在第二段, 往左找, 并且mid也是候选人
		            else l = mid + 1;
		        }
		        return nums[l];
		    }
		};


	1. 破坏现场: "*", 恢复现场
	2. 遍历到底, 返回true;
	2. for(3个方向) if(有一个 dfs()是true)返回true
		全部都false, 返回false


	还是很顺利的!
	class Solution {
	public:
	    bool hasPath(vector<vector<char>>& matrix, string &str) {
	        int n = matrix.size();
	        //忘写, 都是细节啊!
	        if(!n) return false;
	        int m = matrix[0].size();
	        for(int i = 0; i < n; i++){
	            for(int j = 0; j < m; j++){
	                if(dfs(matrix, n, m, str, 0, i, j)) return true;
	            }
	        }
	        return false;
	    }
	    
	    bool dfs(vector<vector<char>> &matrix, int n, int m, string &str, int u, int x, int y){
	        if(matrix[x][y] != str[u]) return false;
	        if(u == str.size() - 1) return true;
	        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	        char c = matrix[x][y];
	        matrix[x][y] = '*';
	        for(int i = 0; i < 4; i++){
	            int a = x + dx[i], b = y + dy[i];
	            if(a < 0 || a >= n || b < 0 || b >= m || matrix[a][b] == '*') continue;
	            if(dfs(matrix, n, m, str, u + 1, a, b)) return true;
	        }
	        matrix[x][y] = c;
	        return false;
	    }
	};

---



----
 a + b
 2*(a+b) == a + k*环 + b

 a + b2 == b + (a + b2) % 

2. 
	12. AcWing 24. 机器人的运动范围
	 	1. 不难, 注意小细节:
	 		row == col == 0的时候, 可以特判
	 	2. 代码 
	 		class Solution {
			public:
			    bool fail(int a, int b, int k){
			        int res = 0;
			        while(a){
			            res += a % 10;
			            a /= 10;
			        }
			        while(b){
			            res += b % 10;
			            b /= 10;
			        }
			        return res > k;
			    }
			    int movingCount(int threshold, int rows, int cols)
			    {
			        错: 忘写
			        对: if(!rows && !cols) return 0;
			        typedef pair<int, int> PII;
			        #define x first
			        #define y second
			        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
			        queue<PII> q;
			        bool st[rows][cols];
			        memset(st, false, sizeof st);
			        错: int res = 0;	[0,0]就是一个答案
			        对: int res = 1;
			        q.push({0, 0});
			        st[0][0] = true;
			        while(q.size()){
			            auto t = q.front(); q.pop();
			            for(int i = 0; i < 4; i++){
			                int a = t.x + dx[i], b = t.y + dy[i];
			                if(a < 0 || a >= rows || b < 0 || b >= cols || st[a][b] || fail(a, b, threshold)) continue;
			                q.push({a, b});
			                st[a][b] = true;
			                res ++;
			            }
			        }
			        return res;
			    }
			};
	13. AcWing 25. 剪绳子
		1. 这里面的证明很好, 其实最好的答案是, 每个段落的长度是自然常数e, 但是这里只能取整数, 而且3比2好, 所以取3
			https://www.acwing.com/solution/content/731/ 
				其中氰化物的解释非常好, 底下的评论也非常棒
		2. 这里相当于是:
			class Solution {
			public:
			    int maxProductAfterCutting(int l) {
			        错: if(l <= 3) return l;
			        对: if (l <= 3) return 1 * (l - 1);
			        int res = 1;
			        if(l % 3 == 1) res *= 4, l -= 4;		如果是分成3段3段, 最后多出了1, 干脆让这个1和一个3当成一个段落{长度==4}
			        else if(l % 3 == 2) res *= 2, l -= 2;	否则就是分成3段3段, 最后多出了2, 就单独拎出来这个2
			        while(l) res *= 3, l -= 3;				剩下的就肯定是能够3段3段恰好分完的, 就一直乘就好了
			        return res;
			    }
			};
	14. AcWing 26. 二进制中1的个数
		1. 解释:
			迭代进行如下两步，直到 n 变成0为止：
				如果 n 在二进制表示下末尾是1，则在答案中加1；
				将 n 右移一位，也就是将 n 在二进制表示下的最后一位删掉；
			这里有个难点是如何处理负数。
				在C++中如果我们右移一个"负整数，系统会自动在最高位补1"，这样会导致 n 永远不为0，就死循环了。
				解决办法是把 n 强制转化成"无符号整型"，这样 n 的二进制表示不会发生改变，但在右移时系统会自动在最高位补0。
		2. 小bug
			class Solution {
			public:
			    int NumberOf1(int n) {
			        unsigned int x = n;
			        int res = 0;
			        while(x){
			            if(x & 1) res ++;
			            错: x >> 1;
			            对: x >>= 1;
			        }
			        return res;
			    }
			};
	15. AcWing 27. 数值的整数次方
		1. 注意当指数是负数时，我们需要先取指数的绝对值，最后将乘积的倒数作为答案。
			时间复杂度是 O(logn)
		2. 	
			class Solution {
			public:
			    double Power(double base, int exponent) {
			        typedef long long LL;
			        错: LL k = (LL)abs(exponent);		例如 exponent == -2147483648, 奇怪的是 k 也依旧是 -2147483648
			        写法1:
				        LL k;
				        if(exponent < 0) k = (LL) -1 * exponent;
				        else k = (LL) exponent;
			        写法2:
			        	LL k = abs((LL)exponent);		例如 exponent == -2147483648, k 就是 2147483648
			        错: LL res = 1;			这样 res就不能表示小数了
			        对: double res = 1;
			        while(k){
			            if(k & 1) res *= base;	雪球base每次都要滚, 至于贴不贴到res上, 就是k&1的问题了
			            base *= base;
			            k >>= 1;
			        }
			        if(exponent < 0) return 1 / res;
			        return res;
			    }
			};
	16. AcWing 28. 在O(1)时间删除链表结点
		1. 其实就是把参数代表的那个节点给删除
			由于是单链表，我们不能找到前驱节点，所以我们不能按常规方法将该节点删除。
			我们可以换一种思路，将下一个节点的值复制到当前节点，然后将下一个节点删除即可。
		2. 有点像语法题
			class Solution {
			public:
			    void deleteNode(ListNode* node) {
			    	写法1: 暂存next, 把next复制到自己的地址, 删除next
				        auto p = node->next;
				        node->val = p->val;
				        node->next = p->next;
				        delete p;
			        写法2: 将 *(node->next) 赋值给 *node
						*node = *(node->next);		直接在node的地址上, 把node->next的内容放过来 

			        
			    }
			};
	17. AcWing 32. 调整数组顺序使奇数位于偶数前面
		1. 小bug
			class Solution {
			public:
			    void reOrderArray(vector<int> &array) {
			        错:	例如输入是 [], 我们竟然也能进while, 这就是不对的
			        对: if(!array.size()) return;
			        int l = -1, r = array.size();
			        while(l < r){
			            do{l++;} while((array[l] & 1) == 1);	记得有;
			            do{r--;} while((array[r] & 1) == 0);
			            if(l < r) swap(array[l], array[r]);
			        }
			    }
			};
	18. AcWing 33. 链表中倒数第k个节点
		1. 超级超级顺
			class Solution {
			public:
			    ListNode* findKthToTail(ListNode* pListHead, int k) {
			        int n = 0;
			        for(auto cur = pListHead; cur; cur = cur->next) n++;	计算个数, 其实有多少条边, 就是多少个节点, 因为最后一个节点是nullptr, 所以边数==节点数
			        if(k > n) return nullptr;
			        auto node = pListHead;
			        for(int i = 0; i < n - k; i++) node = node->next;		倒数第k个节点 == 正数第n-k个节点 == 遍历n-k条边
			        return node;
			    }
			};
	19. AcWing 34. 链表中环的入口结点
		1. 其实超级简单的逻辑: 参考图示: https://www.acwing.com/solution/content/741/
			可以用公式来说明：a,b,c,x,y的含义同上，我们用 z 表示从 c 点顺时针走到 b 的距离。
			则第一次相遇时 second 所走的距离是 x+(y+z)∗n+y, n 表示圈数，
			同时 second 走过的距离是 first 的两倍，
			也就是 2(x+y)，所以我们有 x+(y+z)∗n+y=2(x+y)，
			所以 x=(n−1)×(y+z)+z
			那么我们让 second 从 c 点开始走，走 x 步，会恰好走到 b 点；让 first 从 a 点开始走，走 x 步，也会走到 b 点
		2. 太出乎我意料了, 超级顺利
			class Solution {
			public:
			    ListNode *entryNodeOfLoop(ListNode *head) {
			        auto first = head;
			        auto second = head;
			        while(first && second){     //这个while()只是为了保证first, second都永远在走路
			            first = first->next;
			            second = second->next;
			            if(second) second = second->next;
			            else return nullptr;
			            if(first == second){    //只要能进这个if(), 就说明一定有环, 如果从来都没有进这个if(), 说明一直在外面的while()中first走一步, second走两步
			                first = head;
			                while(first && second){ //这个while()只是为了保证first, second都永远在走路
			                    first = first->next;
			                    second = second->next;
			                    if(first == second) return first;
			                }
			            }
			        }
			        return nullptr;	//我总觉得不会走到这里
			    }
			};
	20. AcWing 29. 删除链表中重复的节点
		1. 超级超级顺利, 能够熟练的想出每个故事细节
			只要确定好语意, 一切都很简单:
				p: p指向答案链表的最后一个节点, 此时p==dummy说明答案链表为空 
				p->next: 是下一个要检测的节点, 还不确定是否加入答案链表
			class Solution {
			public:
			    ListNode* deleteDuplication(ListNode* head) {
			        auto dummy = new ListNode(-1);				//创建虚拟节点
			        dummy->next = head;							//虚拟节点连接好head, 也就是把原材料{原始链表}准备好, 好给p来处理
			        auto p = dummy;
			        while(p->next){
			            auto test = p->next;
			            int val = test->val;					//我们就是看看下一个检测的节点, 是不是有多个, 所以它的记录值
			            while(test && test->val == val) test = test->next;
			            	之所以这么写上面的 while(), 我的解释, 因为我们目的是要找第一个 != val的节点, 这个没错吧
			            	既然找!=, 那么 while()就是反过来, 就是==val, 并且我们要保证test节点是合法的, 所以就是: while(test && test->val == val) test = test->next;
			            if(test == p->next->next) p = p->next;	
			            	这一句就是判断是不是只有一个==val的节点, 进入这个 if()说明的确只有一个, 说明p->next这个被检测的对象, 现在可以加入答案链表: p = p->next;	
			            p->next = test;
			            	接下来就是布置新的任务: 
			            	test是下一个要检测的对象, 之前说了 p->next是代表下一个要检测的节点, 还不确定是否加入答案链表, 所以 p->next = test; 也就是制定了新的检查任务
			        }
			        auto res = dummy->next;
			        delete dummy;
			        return res;
			    }
			};
	21. AcWing 30. 正则表达式匹配
	22. AcWing 31. 表示数值的字符串
3.
	23. AcWing 35. 反转链表
		1. 超级超级顺利
			class Solution {
			public:
			    ListNode* reverseList(ListNode* head) {
			        if(!head || !head->next) return head;
			        auto tail = reverseList(head->next);
			        head->next->next = head;
			        head->next = nullptr;
			        return tail;
			    }
			};
	24. AcWing 40. 顺时针打印矩阵
		0. 对比:
			本题: 上右下左: int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
			蛇型矩阵: 并不是上下左右四个方向轮流, 是一直往右, 直到不行了, 才往下
		1. 超级顺利
			class Solution {
			public:
			    vector<int> printMatrix(vector<vector<int> > matrix) {
			        vector<int> res;
			        if(matrix.empty()) return res;                      //最好用这一句, 而不是什么 if(!n); 因为这样 int m = matrix[0].size() 就要单独写
			        int n = matrix.size(), m = matrix[0].size();
			        vector<vector<bool>> st(n, vector<bool>(m, false)); //n行, n行什么, n行{vector<bool>, 这个又是m列, m列什么, m列false}
			        int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
			        for(int x = 0, y = 0, d = 0, k = 0; k <= n * m - 1; ){ //非常好, 细节没有出错: 是 k <= n * m - 1; 因为进入{}之后, 就是k++, 变成 k == n * m;
			            res.push_back(matrix[x][y]);
			            st[x][y] = true;
			            k++;
			            int a = x + dx[d], b = y + dy[d];
			            if(a < 0 || a >= n || b < 0 || b >= m || st[a][b]){
			                d = (d + 1) % 4;
			                a = x + dx[d], b = y + dy[d];
			            }
			            x = a, y = b;
			        }
			        return res;
			    }
			};
	25. AcWing 41. 包含min函数的栈
		0. 还是很简单的, 现在仅考虑 minstack的情况, stack的情况不考虑
			push:
				如果 minstack 为空, 可以直接push
				如果新的元素比 minstack 的最上面的元素 相等或者小于, 可以直接push
					因为他如果比我大, 则根本不会用到他
					如果他和我==或者比我小, 因为他距离顶部更近, 肯定会用到他
			pop:
				如果要删除的元素 == minstack, 就直接pop
			top:
				直接返回最上层元素就好
		1. 很顺利
			class MinStack {
			public:
			    /** initialize your data structure here. */
			    stack<int> stk;
			    stack<int> minstack;
			    MinStack() {
			        
			    }
			    
			    void push(int x) {
			        stk.push(x);
			        if(minstack.empty() || x <= minstack.top()) minstack.push(x);
			    }
			    
			    void pop() {
			        if(stk.top() == minstack.top()) minstack.pop();
			        stk.pop();
			    }
			    
			    int top() {
			        return stk.top();
			    }
			    
			    int getMin() {
			        return minstack.top();
			    }
			};
	26. 
4. 
	34. AcWing 48. 复杂链表的复刻
		-1. 注意:
			注意判断:
				1. head为空, matrix为空
				2. 数字是: 负数, 小数, 溢出
		0. 总结一下:
			方法1:
				1. 创建映射: pos[p] = new ListNode(p->val);
				2. 映射点的->next/random = p->next/random的映射点 
			方法2:
				1. 在原链表中间插入映射点
				2. 复制映射点的random: if(p->random)	p->next->random = p->random->next;
				3. 恢复
					1. 一根针穿插连接映射点: 	cur = cur->next = p->next;
					2. 原链表的结构恢复:		p->next = p->next->next;
		1. 非常顺利
			class Solution {
			public:
			    ListNode *copyRandomList2(ListNode *head) {
			        if(!head) return nullptr;
			        unordered_map<ListNode*, ListNode*> pos;
			        for(auto p = head; p; p = p->next){
			            pos[p] = new ListNode(p->val);
			        }
			        for(auto p = head; p; p = p->next){
			            pos[p]->next = pos[p->next];
			            if(p->random) pos[p]->random = pos[p->random];
			        }
			        return pos[head];
			    }
			    
			    ListNode *copyRandomList(ListNode *head) {
			        if(!head) return nullptr;
			        for(auto p = head; p; p = p->next->next){
			            auto ne = p->next;
			            auto node = new ListNode(p->val);
			            node->next = ne;
			            p->next = node;
			        }
			        for(auto p = head; p; p = p->next->next){
			            if(p->random){
			                p->next->random = p->random->next;
			            }
			        }
			        auto dummy = new ListNode(-1); 
			        auto cur = dummy;
			        for(auto p = head; p; p = p->next){
			            cur = cur->next = p->next;
			            p->next = p->next->next;
			        }
			        auto res = dummy->next;
			        delete dummy;
			        return res;
			    }
			};
	35. AcWing 50. 序列化二叉树
		1. 其实考察的知识点都是知道的, 难在很难想到居然用到这些知识点
		2. 

















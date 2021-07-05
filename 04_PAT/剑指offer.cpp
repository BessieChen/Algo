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



1. 基础算法
	1. 位运算
		1. AcWing 90. 64位整数乘法
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
2. 搜索
	1. flood fill 
		1. AcWing 1097. 池塘计数
			0. bug
			1. 笔记
				1. 两种联通: 4联通, 8联通
					4联通: 有一个公共边就是联通
						-------------
						|	| 1 |	|
						-------------
						| 2 | x | 3 |
						-------------
						|	| 4 |	|
						-------------
					8联通: 有一个公共点就是联通
						-------------
						| 1 | 2 | 3 |
						-------------
						| 4 | x | 5 |
						-------------
						| 6 | 7 | 8 |
						-------------
			2. 注释
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
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.		
		2. AcWing 1098. 城堡问题
			0. bug
			1. 笔记
				输入是二进制编码
					我们用1表示西墙，2表示北墙，4表示东墙，8表示南墙
					3表示该方块包含西墙和北墙, 因为 3 = 1 + 2
				看数字的x的{东西南北}是否有墙:
					for(int i = 0; i < 4; i++)
						if(g[t.x][t.y] >> i & 1)
				注意:
					1. 这道题其实是4联通问题
						因为我们是判断东西南北的格子, 至于左上,右上,左下,右下的格子, 根据题目都是不连通的
					2. 题目给的数字, 数字是格子的属性, 这个属性是格子的边的情况
						所以, 我们判断我{i,j}点上下左右是否连通, 就看我{i,j}点的上下左右有没有墙 -> 判断的是我的4条边
						对比上一题, 判断我{i,j}的周围是否连通, 是看周围格子是否是'W' -> 判断的是周围的8个格子
			2. 注释
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
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		3. AcWing 1106. 山峰和山谷
			0. bug
			1. 笔记
				7 8 9
				7 8 9
				7 8 9
					一个山谷: 777, 因为邻接的只有比他高的
					一个山峰: 999, 因为邻接的只有比他矮的
					888什么都不是, 因为周围有比他高的, 有比他矮的
			2. 注释
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
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	2. 最短路模型
		1. AcWing 1076. 迷宫问题
			0. bug
			1. 笔记
			2. 注释
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
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		2. AcWing 188. 武士风度的牛
			0. bug
			1. 笔记
				走的是'日'字, 所以一个点可以往8个'日'字方向走
					图示: https://www.acwing.com/video/449/ 的 01:45
				没有考虑什么别马脚
				如果日字的点存在障碍物"*", 就不能走到那个'日'字的点
			2. 注释
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
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		3. AcWing 1100. 抓住那头牛
			0. bug
			1. 笔记
				当一个图里面, 所有边的权重是1的时候, 我们就可以用bfs求最短路径
				bfs: 特殊的dijkstra算法
					解释:
						回忆堆优化版本的dijkstra, 我们从priority_queue取出来的是dist[t]最小的点t, 也就是"距离起点最短的点"
						当图里面所有边的权重是1, 那么从某点到起点有n条边的话, 距离就是n
						因为bfs是一层一层往外的, 所以bfs的queue里面的节点, 是逐渐距离起点越来越远的{距离是单增的}, 所以第一个从queue里面取出来的点, 也是"距离起点最短的点"
				想象
					题目中数轴的点, 对应我们假想的graph的点
					但是数轴中的距离 != graph中的距离
						因为数轴中10->20的距离是10, 但是graph中的10->20的最短距离是1 
							因为10可以选择一次"*2"操作, 当然也可以选择十次"+1"操作{这个距离是10}
			2. 注释
				#include <cstring>
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 1e5 + 10;

				int n, k;
				int q[N];
				int dist[N];	每个点距离起点n的最短距离

				int bfs()
				{
				    memset(dist, -1, sizeof dist);	初始化-1, 说明每个点都没有遍历过, 相当于取代了 st数组
				    dist[n] = 0; 	n距离n的最短距离是0
				    q[0] = n;		n加入到bfs队列 

				    int hh = 0, tt = 0;

				    while (hh <= tt)
				    {
				        int t = q[hh ++ ];

				        if (t == k) return dist[k]; 如果这个点是终点k, 我们返回最短距离dist[k]

				        接下来是看这个点t{农夫所在的点}, 能走到哪些点. 能走到的是 t+1, t-1, t*2
				        	注意, 题目中数轴的点, 对应我们假想的graph的点
								但是数轴中的距离 != graph中的距离
									因为数轴中10->20的距离是10, 但是graph中的10->20的最短距离是1 
										因为10可以选择一次"*2"操作, 当然也可以选择十次"+1"操作{这个距离是10}
				        	但是如果我们没有限制地这么走, 我们最终可能会扩展到无穷大, 其实是没必要的
				        	我们思考可以发现, 有些地方我们的农夫是不需要去的, 假设农夫要去的点是点a, a可以是t+1, t-1, t*2
				        		0 <= a <= N, N == 1e5 
				        		因为:
				        			1. 不需要 a < 0, 因为我们的牛就只在[0, N]之间, 所以如果你去了负数的地方:
				        				1. 你如果再-1, 更负数, 南辕北辙
				        				2. 你如果再*2, 更负数, 南辕北辙
				        				3. 只能+1, 那既然这么走到负数又走回正数, 干脆一开始就别去负数的地方
				        			2. 不需要 a > N, 因为我们的牛就只在[0, N]之间, 所以如果你去了>N的地方:
				        				1. 你如果再+1, 更远了, 南辕北辙
				        				2. 你如果再*2, 更远了, 南辕北辙
				        				3. 只能-1, 那既然这么走到N又走回N, 干脆一开始就别去>N的地方 
				        		所以 
				        			0 <= t+1 < N, 其实如果保证t是正数, 就不需要判断 0 < t+1
				        			0 <= t-1 < N, 其实如果保证t是<N, 就不需要判断 t+1 < N
				        			0 <= t*2 < N, 其实如果保证t是正数, 就不需要判断 t*2 > 0

				        以下就是点t的邻接点: t+1, t-1, t*2, 如果满足要求{也就是没有遍历过, 并且在[0,N]之间}, 我们就插入队列
				        if (t + 1 < N && dist[t + 1] == -1) 	
				        {
				            dist[t + 1] = dist[t] + 1;	记录距离
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
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	3. 多源bfs
		AcWing 173. 矩阵距离
			0. bug
			1. 笔记
				属于类a的所有点{例如本题的a类点是指值为0的点}, 到最近的b类点{例如本题的b类点是指值为1的点}的距离
					也就是, 对于某一个点a来说, 这个距离只有一个, 因为我们要找到最近的b类点
					对比: 本题和多源最短路不一样: 多源最短路是求任意两点之间的最短距离
						也就是, 对于某一个点a来说, 这个距离有一堆, 因为是任意两点之间

				举例子:
					-----------------
					| 0 | 0 | 0 | 1 |
					-----------------
					| 0 | 0 | 1 | 1 |
					-----------------
					| 0 | 1 | 1 | 0 |
					-----------------
					答案:
						-----------------
						| 3 | 2 | 1 | 0 |
						-----------------
						| 2 | 1 | 0 | 0 |
						-----------------
						| 1 | 0 | 0 | 1 |
						-----------------

				复杂度: O(n^2)? 
					最差: {(n^4)/4} = {(n^2)/2} * {(n^2)/2}
						{(n^2)/2}个值为0的点
						{(n^2)/2}个值为1的点
				突然明白了:
					我们的笨办法:
						属于类a的所有点{例如本题的a类点是指值为0的点}, 到最近的b类点{例如本题的b类点是指值为1的点}的距离
							b1 	a1
							b2 	a2
							b3	a3
							b4	a4
							b5	a5
								a6
								a7 
								a8
						笨办法步骤:
							1. 对于某一个点a1来说, 求它到所有点b的距离{距离a1b1, a1b2, ...} 然后取出最小的距离对应的点b
								实现: 起点是a1, 然后forloop终点b1, b2, ..., 对于每对起点终点, 用一次bfs
							2. 对于每个点a都重复一遍上述的做法
					聪明的办法: 添加一个虚拟源点c, 然后c点作为起点, 然后c和所有的b类点添加边, 边权是0
						c	b1 	a1
							b2 	a2
							b3	a3
							b4	a4
							b5	a5
								a6
								a7 
								a8
						具体步骤:
							1. 添加一个虚拟源点c, 然后c点作为起点, 然后c和所有的b类点添加边, 边权是0
							2. 然后按照普通的bfs算法, 起点是c, 终点是a1,a2,...
								其中 dist[a1]指的是点a1到c的最短距离, 也就是我们的答案
									也就是a1到最近的b类点{例如本题的b类点是指值为1的点}的距离
									至于这个路径, 是c->b多少->->再到a1
										我们是不知道的, 但也不需要知道, 因为题目只是问a1到b类点的最短距离, 而不是问对应的b类点是哪个
						实现:
							1. 其实不需要创造什么虚拟节点c, 直接把所有的b类点插入bfs的queue中
								为什么?
									因为假设你真的要装一个虚拟节点, 我们随意设置一个虚拟节点的坐标{xx,yy}
										dist[xx,yy] = 0
										q[ ++ tt] = {xx, yy}
									其实 while(hh <= tt)的时候, 你还是要特判:
										auto t = q[tt ++];
										if(t 就是 {xx,yy}): 我们往queue中插入b类点:
											"for (int i = 1; i <= n; i ++ )
										        for (int j = 1; j <= m; j ++ )
										            if (g[i][j] == '1')
										            {
										                dist[i][j] = 0;
										                q[ ++ tt] = {i, j};
										            }"
										最后把t给pop掉 
									其实, 你不觉得多次一举吗? 实现的时候, 直接一上来就把b类点插入就好了
										for (int i = 1; i <= n; i ++ )
									        for (int j = 1; j <= m; j ++ )
									            if (g[i][j] == '1')
									            {
									                dist[i][j] = 0;
									                q[ ++ tt] = {i, j};
									            }
									这样做的效果 和 创造了虚拟节点c的效果一样. 
								对比:
									之前的bfs: 一开始只是插入一个起点
									这里的bfs: 一开始就是插入多个起点{b1,b2,b3...}
							2. 正确性, 两种解释方式:
								1. 因为这么做的效果和创造虚拟节点c一样, 并且虚拟节点完全仿照 dijkstra, 所以这么做是对的
								2. 因为bfs的queue里面的值保证是单增的, 单增的话, 就是和 dijkstra完全一样, 所以这么做是对的
									为什么是单增? 第一层是b类点, 距离是0
										当我们遍历b1的邻接点们, 我们插入的距离是1
										当我们继续, 遍历b2的邻接点们, 我们插入的距离也是1
										总之我们的queue里面一直是 00000111122222333这么插入的
									你之前的担心:
										万一有一个点a1, 是b1的邻接点, 被b1的bfs给插入queue了
										但是万一a1距离后面需要遍历的点b2更近呢? 我的担心就是a1会不会被提前插入queue了
											不会, 因为当b2找到邻接点a1, 其实和b1找到邻接点a1的效果是一样的
									举例子吧. 
										000011112222233333
										------------------
										| b1 | "a1" | b2 |
										-------------------
										| b3 | b4   | b5 |
										-------------------
											当我们遍历b1的邻接点们
												对于a1来说, a1被插入queue, dist[a1] = 1
											当我们继续, 遍历b2的邻接点们
												对于a1来说, a1不会被插入queue因为已经被插入了而且只会被插入一次
												就算是继续插入a1被插入queue, dist[a1] 还是== 1, 所以不影响正确性

				最后解释一下, 我们的曼哈顿距离:
					因为是采用曼哈顿距离, 所以对于一个点来说, 它的邻点是{上下左右}四个方向
					也就是说, {左上, 左下, 右上, 右下} 不是他的邻点, 因为曼哈顿距离下, 距离是2
			2. 注释
				#include <cstring>
				#include <iostream>
				#include <algorithm>

				#define x first
				#define y second

				using namespace std;

				typedef pair<int, int> PII; 这个是坐标

				const int N = 1010, M = N * N;

				int n, m;
				char g[N][N];		记录原始地图的01标记, [N][N]是坐标
				PII q[M];			将坐标插入queue
				int dist[N][N];		所有点, 距离b类点的最短距离{或者距离虚拟源点的最短距离}

				void bfs()
				{
				    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}; 因为是采用曼哈顿距离, 所以只需要上下左右

				    memset(dist, -1, sizeof dist);
				    	dist不初始为 0x3f是因为bfs保证了dist只会被更新一次, 因为bfs层序遍历本来就是queue中出队的元素是当前的min{因为queue中每个元素的值是单增的}, 所以dist只会有-1和非-1的某种值的两种情况
						之前的最短路问题是因为需要不断更新dist, 所以我们要有0x3f 和 min()判断

				    int hh = 0, tt = -1;
				    for (int i = 1; i <= n; i ++ )
				        for (int j = 1; j <= m; j ++ )
				            if (g[i][j] == '1')
				            {
				                dist[i][j] = 0;
				                q[ ++ tt] = {i, j}; 插入一大堆起点{b类点}
				            }

				    while (hh <= tt)
				    {
				        auto t = q[hh ++ ];

				        for (int i = 0; i < 4; i ++ )
				        {
				            int a = t.x + dx[i], b = t.y + dy[i];
				            if (a < 1 || a > n || b < 1 || b > m) continue;
				            if (dist[a][b] != -1) continue;	如果遍历过, 跳过

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
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	4. 最小步数模型
		AcWing 1107. 魔板
			0. bug
			1. 笔记
				这道题的意思:
					0. 我们的起点状态, 固定是12345678
					1. 题目给我们一个string: 
						例如"2 6 8 4 5 7 3 1", 这是我们需要到的终点状态
					2. 但是这个string需要被转换为 g[2][4], 也就是像从中间拗断, 然后首尾黏上
						"2 6 8 4 5 7 3 1"
						变为
							"2 6 8 4 
							 1 3 7 5"
					3. 对数组{而不是string}, 我们有三种操作:
						A：交换上下两行
						B：将最右边的一列插入到最左边
						C：魔板中央对的4个数作顺时针旋转
					4. 总之就是给你一个终点状态, 你要从起点+3种操作到终点
				考察: 其实都是很简单的
					1. 将每个状态视为graph中的一个节点
					2. 每个节点都有3个邻接节点, 也就是对应3个操作
					3. 需要实现: 
						1. 如何将string变为数组, 数组回变为string
						2. 如何将数组进行3种操作 
			2. 注释
				#include <cstring>
				#include <iostream>
				#include <algorithm>
				#include <unordered_map> 我们需要存 {状态string, 最短距离int}, {本次状态string, {操作char, 上个状态string}}
				#include <queue>

				using namespace std;

				char g[2][4];
				unordered_map<string, pair<char, string>> pre;	
					每个状态{string}是从哪个状态{string}来的, 还要存是从哪个操作{char}来的. 所以是 pair<char, string>
				unordered_map<string, int> dist; 
					状态{string}距离起点的最短距离{int}. 之前都是dist[N]因为之前index就可以表示状态{图中的节点}, dist[index]的值就是最短距离

				void set(string state) 将字符串string加工为 g[2][4] 的矩阵
				{
				    for (int i = 0; i < 4; i ++ ) g[0][i] = state[i];
				    		第一行好说
				    for (int i = 7, j = 0; j < 4; i --, j ++ ) g[1][j] = state[i];
				    		我很喜欢这一句:
				    			因为string的最后一个元素, 其实是数组g的第二行的第一个元素
				    			所以string从i == 7开始, i--
				    			所以数组g[1]从j == 0开始, j++
				    			因为我们只需要加入4个, 所以 j < 4来限定长度
				}

				string get() 将g[2][4] 的矩阵变回我们的string
				{
				    string res;
				    for (int i = 0; i < 4; i ++ ) res += g[0][i];
				    for (int i = 3; i >= 0; i -- ) res += g[1][i];
				    		逆过来就好了 
				    return res;
				}

				A：交换上下两行
				string move0(string state)
				{
				    set(state);
				    for (int i = 0; i < 4; i ++ ) swap(g[0][i], g[1][i]);
				    return get();
				}

				B：将最右边的一列插入到最左边
				string move1(string state) 将最右侧一列, 插入到第一列的左边
				{
				    set(state);
				    int v0 = g[0][3], v1 = g[1][3];
				    for (int i = 3; i >= 0; i -- ) 因为是数组整体往右移, 所以是右侧的东西获得左侧的元素{g[i] = g[i-1]}, 然后这个动作是往左移动的{所以for从i=3开始, i--}
				    {
				        g[0][i] = g[0][i - 1];	左侧[i-1]的是没有被污染的数据, 更新的是右侧[i]
				        g[1][i] = g[1][i - 1];	
				    }
				    g[0][0] = v0, g[1][0] = v1;
				    return get();
				}

				C：魔板中央对的4个数作顺时针旋转
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

				int bfs(string start, string end) 这里是
				{
				    if (start == end) return 0; 如果本身就是, 返回0步

				    queue<string> q;

				    插入起始状态
				    q.push(start);
				    dist[start] = 0;

				    while (!q.empty())
				    {
				        auto t = q.front();
				        q.pop();

				        状态t能够到达的三个状态, 装入一个string[]
				        string m[3];
				        m[0] = move0(t);
				        m[1] = move1(t);
				        m[2] = move2(t);

				        for (int i = 0; i < 3; i ++ )
				            if (!dist.count(m[i]))	如果这个状态m[i]没有被遍历过
				            {
				                dist[m[i]] = dist[t] + 1; 	状态的距离, +1
				                pre[m[i]] = {'A' + i, t};	存当前状态m[i]的前一个状态t, 还有从t的{'A'+i}操作过来
				                q.push(m[i]);				插入队列 
				                if (m[i] == end) return dist[end];	如果这个状态就是我们要的, 返回 dist
				                									注意, 之所以这句话写在这里, 因为返回的时候, 我们需要知道这个状态的dist和pre. 
				                										所以dist和pre要先写
				            }
				    }

				    return -1;
				}

				int main()
				{
				    int x;
				    string start, end;
				    for (int i = 0; i < 8; i ++ ) 题目输入的终点状态string
				    {
				        cin >> x;
				        end += char(x + '0');
				    }

				    for (int i = 1; i <= 8; i ++ ) start += char('0' + i); 我们的起始状态

				    int step = bfs(start, end);

				    cout << step << endl;

				    string res;
				    while (end != start) 
				    {
				        res += pre[end].first; 从start->end经历的操作: first
				        end = pre[end].second; 我们是从哪个start状态来的: second
				    }

				    reverse(res.begin(), res.end()); 倒序

				    if (step > 0) cout << res << endl;

				    return 0;
				}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	5. 双端队列广搜
		AcWing 175. 电路维修 todo, 第二个偏移没搞懂
			0. bug
			1. 笔记
				图上的点, 有个性质: 有一半的点是走不到的
					假设: 坐标{i,j}, 下标从0开始
						i+j == 奇数的点, 我们走不到
						i+j == 偶数的点, 我们才能走到
				这道题是经典的边权只有0和1两种值的图
					所以用经典的"双端队列"bfs来求
					对比:
						传统bfs: 队头的点a, 和它的邻接点b, 我们都是无条件把b插入队尾
						"双端队列"bfs: 队头的点a, 和它的邻接点b
							如果ab之间的边权 == 0, 插入队头
							如果ab之间的边权 == 1, 插入队尾
					因为队列始终保持着 
						0000011111
						也就是单调递增的性质.
						所以就是和堆优化的dijkstra一样
						因为dijkstra是正确的, 所以我们这么做也是正确的

				但是, 不能因为queue里面的值是单增我们就和之前的题一样初始化dist为-1, 因为
					对比:
						之前的题: dist初始化为-1
							原因:
								边权都是1, 不存在说>1或者<1的边权
								所以每次距离都是 + 1, queue里面的值就是递增的
						这道题: dist不能初始化为-1, 初始化还是经典的 0x3f
							原因:
								边权有0的情况
								所以每次的距离, 除了+1, 还可能+0
									例如现在 a1,a2点都在queue中, 他们的dist[a1] == dist[a2]
									遍历a1的邻接点的时候, 发现了点c, d[a1][c] == 1, c入队
									遍历a2的邻接点的时候, 又发现了点c, 但是距离更近, 例如d[a2][c] == 0, dist[c]应该被更新, 且再次入队
				注意 
					不能说某个格子先'/'这么走, 然后走啊走又绕回来这个格子, 再\这么走. 每个格子的走法一定是固定好了的
			2. 注释
				#include <cstring>
				#include <iostream>
				#include <algorithm>
				#include <deque>		注意, 这里不是queue, 这里是双端队列

				#define x first
				#define y second

				using namespace std;

				typedef pair<int, int> PII;

				const int N = 510, M = N * N;  边长是500

				int n, m;
				char g[N][N];
				int dist[N][N];
				bool st[N][N];

				int bfs()
				{
				    memset(dist, 0x3f, sizeof dist);
				    memset(st, 0, sizeof st);
				    dist[0][0] = 0;
				    deque<PII> q;
				    q.push_back({0, 0});

				    char cs[] = "\\/\\/";
				    int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
				    int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};

				    while (q.size())
				    {
				        PII t = q.front();
				        q.pop_front();

				        if (st[t.x][t.y]) continue;
				        st[t.x][t.y] = true;

				        for (int i = 0; i < 4; i ++ )
				        {
				            int a = t.x + dx[i], b = t.y + dy[i];
				            if (a < 0 || a > n || b < 0 || b > m) continue;

				            int ca = t.x + ix[i], cb = t.y + iy[i];
				            int d = dist[t.x][t.y] + (g[ca][cb] != cs[i]);

				            if (d < dist[a][b])
				            {
				                dist[a][b] = d; 	更新dist

				                if (g[ca][cb] != cs[i]) q.push_back({a, b});	加到队列后面
				                else q.push_front({a, b});						加到队列前面
				            }
				        }
				    }

				    return dist[n][m];
				}

				int main()
				{
				    int T;
				    scanf("%d", &T);
				    while (T -- )
				    {
				        scanf("%d%d", &n, &m);
				        for (int i = 0; i < n; i ++ ) scanf("%s", g[i]);

				        int t = bfs();

				        if (t == 0x3f3f3f3f) puts("NO SOLUTION"); 之前老师是 if( n + m & 1) puts("Nosolution") 因为这个是{n+m}奇数
				        else printf("%d\n", t);
				    }

				    return 0;
				}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	6. 双向广搜
		AcWing 190. 字串变换 todo
			0. bug
			1. 笔记
				一个字符串, 看成图中的一个节点, 规则表示了一个字符串可以走到哪个字符串, 也就是从一个节点到另一个节点
				假设我们的起始点, 每一步都可以走到k种不同的节点, 假设我们走10步, 也就是k^10, 空间复杂度非常高
				用单向bfs, 可能会不过. 如果真的不过, 考虑双向bfs, 但是代码会稍微多一点
				用优化, 也就是"双向bfs", 思路:
					普通bfs: 起点一层一层往外扩, 去找终点
						k^10
					双向bfs: 起点终点同时都一层一层往外扩, 去找对方
						2*(k^5)
			2. 注释
				#include <cstring>
				#include <iostream>
				#include <algorithm>
				#include <unordered_map>
				#include <queue>

				using namespace std;

				const int N = 6; 规则最多是6个 

				int n;
				string a[N], b[N]; 规则: 从a[i] -> b[i]

				int extend(queue<string>& q, 
					unordered_map<string, int>& da, 
					unordered_map<string, int>& db, 
					string a[], 
					string b[])
				{
				    for (int k = 0, sk = q.size(); k < sk; k ++ )
				    {
				        string t = q.front();
				        q.pop();

				        for (int i = 0; i < t.size(); i ++ ) 枚举所有的sub子串
				            for (int j = 0; j < n; j ++ ) 因为这里是对每个子串遍历n个规则
				                if (t.substr(i, a[j].size()) == a[j]) 从下标i开始, 长度和规则a[j]一样, 看这一段是否和规则a[j]匹配
				                {
				                    string state = t.substr(0, i) + b[j] + t.substr(i + a[j].size()); 匹配的话, 先看看新的串儿长什么样子, 记为state
				                    if (da.count(state)) continue;	如果发现我们的
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
				    	双向bfs, 定义两个queue
				    unordered_map<string, int> da, db;
				    	定义距离也需要两个. 含义是状态string到起点的最短距离int
				    qa.push(A), da[A] = 0;
				    qb.push(B), db[B] = 0;

				    while (qa.size() && qb.size()) 
				    	如果两个queue, 只要有一个queue是空的{这个"只要某个是空"的语气, 用&&, 而不是||}, 就不用继续while了, 因为是无解的
				    	为什么? 
				    		因为假设空的queue是起点的, 说明遍历完了从起点出发的所有节点{整个连通块}, 都没有遇到终点, 那肯定就是遇不着了.
				    		因为都不是在一个连通块中
				    {
				        int t;
				        if (qa.size() <= qb.size()) t = extend(qa, da, db, a, b);
				        	如果第一个队列qa 比第二个队列qb 要短, 就扩展第一个队列
				        else t = extend(qb, db, da, b, a);
				        	否则扩展第二个队列

				        if (t <= 10) return t; 如果返回的是小于10, 说明找到重合点, 相遇了
				    }

				    return 11; 无解 
				}

				int main()
				{
				    string A, B; 起点终点 
				    cin >> A >> B;
				    while (cin >> a[n] >> b[n]) n ++ ; n是规则个数 

				    int step = bfs(A, B);
				    if (step > 10) puts("NO ANSWER!"); 
				    else printf("%d\n", step);

				    return 0;
				}

				#include<bits/stdc++.h>
				using namespace std;
				const int N = 6;
				int n;
				string a[N],b[N];
				// 扩展函数
				// 参数：扩展的队列，到起点的距离，到终点的距离，规则，规则
				//返回值：满足条件的最小步数
				int extend(queue<string>& q, unordered_map<string,int>& da, unordered_map<string, int>& db,
				        string a[], string b[]){
				    // 取出队头元素
				    string t = q.front();
				    q.pop();

				    for(int i = 0; i < t.size(); i ++)  // t从哪里开始扩展
				        for(int j = 0; j < n; j ++) // 枚举规则
				            //如果t这个字符串的一段= 规则，比如= xyz，才可以替换
				            if(t.substr(i, a[j].size()) == a[j]){
				                // 变换之后的结果state:前面不变的部分+ 变化的部分 + 后面不变的部分
				                // 比如abcd ，根据规则abc--> xu，变成 xud，这里的state就是xud
				                string state = t.substr(0,i) +b[j] + t.substr(i + a[j].size());
				                // state状态是否落到b里面去，两个方向会师，返回最小步数
				                if(db.count(state)) return da[t] + 1 + db[state];
				                // 如果该状态之前已扩展过，
				                if(da.count(state)) continue;
				                da[state] = da[t] + 1;
				                q.push(state);
				            }
				    return 11;

				}
				// 从起点和终点来做bfs
				int bfs(string A, string B){
				    queue<string> qa, qb; // 两个方向的队列
				    //每个状态到起点的距离da（哈希表），每个状态到终点的距离db哈希表
				    unordered_map<string, int> da, db; 
				    // qa从起点开始搜，qb从终点开始搜
				    qa.push(A), da[A] = 0; // 起点A到起点的距离为0
				    qb.push(B), db[B] = 0; // 终点B到终点B的距离为0

				    // qa和qb都有值，说明可以扩展过来，否则说明是不相交的
				    while(qa.size() && qb.size()){
				        int t; // 记录最小步数
				        // 哪个方向的队列的长度更小一些，空间更小一些，从该方向开始扩展，
				        // 时间复杂度比较平滑,否则有1个点会超时
				        if(qa.size() <= qb.size()) 
				            t = extend(qa, da, db, a, b);
				        else t = extend(qb, db, da, b, a);
				        // 如果最小步数在10步以内

				        if( t <= 10) return t;
				    }

				    return 11; // 如果不连通或者最小步数>10，则返回大于10的数

				}

				int main(){
				    string A, B;
				    cin >> A >> B;
				    // 读入扩展规则，分别存在a数组和b数组
				    while( cin >> a[n] >> b[n]) n ++;
				    int step = bfs(A,B);
				    if(step > 10) puts("NO ANSWER!");
				    else cout << step << endl;
				}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	7. A*
		AcWing 178. 第K短路 todo
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 179. 八数码 todo
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	todo:
	8. DFS之连通性模型
		AcWing 1112. 迷宫
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 1113. 红与黑
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	9. DFS之搜索顺序
		AcWing 1116. 马走日
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 1117. 单词接龙
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 1118. 分成互质组
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	10. DFS之剪枝与优化
		AcWing 165. 小猫爬山
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 166. 数独
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 167. 木棒
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 168. 生日蛋糕
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	11. 迭代加深
		AcWing 170. 加成序列
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	12. 双向DFS
		AcWing 171. 送礼物
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	13. IDA*
		AcWing 180. 排书
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 181. 回转游戏
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
3. 图论 
	1. 单源最短路的建图方式
		AcWing 1129. 热浪
			0. bug
			1. 笔记
				回忆复杂度:
					dijkstra: O(v^2)
					优化dijkstra: O(elogv)/O(eloge)
					spfa: 一般是 O(e), 最坏 O(v*e)
				这里的数据量不大, 三个算法都可以, 老师选择了他习惯的spfa
			2. 注释
				#include <cstring>
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 2510, M = 6200 * 2 + 10; 无向图, 所以给*2存两条边

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
				        if (hh == N) hh = 0; 因为是循环队列, 如果队头到了结尾, 就置为开头	
				        st[t] = false;		因为从queue取出点t, 说明现在queue里面没有节点t

				        for (int i = h[t]; ~i; i = ne[i]) 枚举点t的邻接点 
				        {
				            int j = e[i];	
				            if (dist[j] > dist[t] + w[i])	如果能更新/放松点j
				            {
				                dist[j] = dist[t] + w[i];
				                if (!st[j])	如果j不再队列中 
				                {
				                    q[tt ++ ] = j;	加入队列 
				                    if (tt == N) tt = 0;	如果到头了就到开头 
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

				    cout << dist[T] << endl; 因为保证有答案, 所以直接输出

				    return 0;
				}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 1128. 信使
			0. bug
			1. 笔记
				这道题不难, 问的东西是:
					从指挥部出发, 信息传遍完所有的点{通讯室}需要多久
					其实, 我们就需要两步:
						1. 从起点1{指挥部}到每个点的最短距离dist[i]
						2. 然后我们看最长的最短距离, 就是传遍完所有点的距离 
				这道题, 因为要求出所有的 dist[i]
					我们可以用dijkstra等
					但是老师用了floyed, 也就是当成是多源路径来求, 因为代码很短
					其实主要是因为这题的数据量小, floyed是 O(n^3), 100^3 = 10^6, 没有超过10^8也就是不到1s
			2. 注释
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
				        d[a][b] = d[b][a] = min(d[a][b], c); 无向边
				    }

				    Floyd算法: 
				    for (int k = 1; k <= n; k ++ )
				        for (int i = 1; i <= n; i ++ )
				            for (int j = 1; j <= n; j ++ )
				                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

				    int res = 0;
				    for (int i = 2; i <= n; i ++ )
				        if (d[1][i] == INF) -> 说明有个通讯室不连通 
				        {
				            res = -1;
				            break;
				        }
				        else res = max(res, d[1][i]); 

				    cout << res << endl; 

				    return 0;
				}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 1127. 香甜的黄油
			0. bug
			1. 笔记
				这道题, 求的是:
					找一个牧场a, 所有牛都会去这个牧场, 我们希望所有的牛到这个牧场需要走的距离最短
				其实抽象一下:
					遍历每个牧场, 对于每个牧场, 假设为大家会去的牧场, 然后计算所有牛去这个牧场的距离 
					其实是多源最短路问题, 但是题目的数据量比较大:
						1≤N≤500, 	牛的个数{点的个数} 
						2≤P≤800,	牧场个数{要假设的牧场a的个数}
						1≤C≤1450,	边的个数
				复杂度:
					floyed:
						O(v^3),800^3{为什么不是500^3, 因为我们要求的是遍历800个牧场{当成牧场a}, 每个牧场去500头牛{800个牧场中的其中500个牧场}的最短距离, 所以还是800^3}
					堆优化dijkstra:
						O(elogv) * v:
							之所以*v, 是因为 O(elogv)只是单源的, 我们有800个源
							经计算, 堆优化dijkstra是 O(1450*log800)*800是ok的
					spfa:
						一般 O(e)*v, 最坏 O(ev)*v 
						出题者一般都不会spfa, 所以很少出现最差情况, 所以本题用spfa也是可以的
			2. 注释
				#include <cstring>
				#include <iostream>
				#include <algorithm>

				using namespace std;

				const int N = 810, M = 1450 * 2 + 10, INF = 0x3f3f3f3f;

				int n, p, m;
				int id[N];	存牛所在的牧场 
				int h[N], e[M], w[M], ne[M], idx;	h: 某个点的邻接点的token, e: 邻接点, w: 边权.
				int dist[N], q[N];	最短距离, queue
				bool st[N];

				void add(int a, int b, int c)
				{
				    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
				}

				int spfa(int start)
				{
				    memset(dist, 0x3f, sizeof dist); 因为一个点可以多次入队, 所以用0x3f
				    dist[start] = 0;	起点到起点的距离为0

				    int hh = 0, tt = 1;
				    q[0] = start, st[start] = true;  入队 
				    while (hh != tt)	
				    {
				        int t = q[hh ++ ];
				        if (hh == N) hh = 0;	循环队列 
				        st[t] = false;			点t取出, 所以置为false 

				        for (int i = h[t]; ~i; i = ne[i])	遍历t的邻点
				        {
				            int j = e[i];
				            if (dist[j] > dist[t] + w[i]) 如果可以更新/放松邻接点j
				            {
				                dist[j] = dist[t] + w[i];
				                if (!st[j])				如果不在queue中就加入 
				                {
				                    q[tt ++ ] = j;
				                    if (tt == N) tt = 0;
				                    st[j] = true;
				                }
				                如果本来在queue中, 就只需要更新 dist[j] = dist[t] + w[i]; 因为之后肯定会从queue中取出, 到时候的dist[j]是新值 
				            }
				        }
				    }

				    int res = 0;
				    for (int i = 0; i < n; i ++ )	
				    {
				        int j = id[i];	第i头牛所在的牧场 
				        if (dist[j] == INF) return INF; 这里要判断, 只要有一头牛{第i头牛}不能走到我们的牧场start, 这个牧场start就肯定不能用了
				        res += dist[j];	计算距离和
				    }

				    return res;
				}

				int main()
				{
				    cin >> n >> p >> m;
				    for (int i = 0; i < n; i ++ ) cin >> id[i];  读入牛所在的牧场 

				    memset(h, -1, sizeof h);	初始化所有的token
				    for (int i = 0; i < m; i ++ )	读入所有的边
				    {
				        int a, b, c;
				        cin >> a >> b >> c;
				        add(a, b, c), add(b, a, c); 无向图 
				    }

				    int res = INF;	记录最短的距离和 
				    for (int i = 1; i <= p; i ++ ) res = min(res, spfa(i)); 这里就是遍历所有的牧场, 将每个牧场都假定为我们的a点 

				    cout << res << endl;

				    return 0;
				}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		xx AcWing 1126. 最小花费
			0. bug
			1. 笔记
				100 =  p * w
					要p最小, 那么w最大
				因为 0 < w < 1
				所以 logw < 0
				所以 -logw > 0
				所以可以用dijkstra, 因为dijkstra只能处理正权边

				如果只是 w > 0
				那么logw可正可负, -logw可正可负, 只能用spfa{处理负权边}


			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 920. 最优乘车 todo
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
		AcWing 903. 昂贵的聘礼 todo
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
	2. 单源最短路的综合应用
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
	3. 单源最短路的扩展应用
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
	4. Floyd算法
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
	5. 最小生成树
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
	6. 最小生成树的扩展应用
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
	7. 负环
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
	8. 差分约束
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
	9. 最近公共祖先
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
	10. 有向图的强连通分量
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
	11. 无向图的双连通分量
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
	12. 二分图
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
	13. 欧拉回路和欧拉路径
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
	14. 拓扑排序
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
		AcWing 90. 64位整数乘法588人打卡
	递推与递归
		AcWing 95. 费解的开关408人打卡
		AcWing 97. 约数之和294人打卡
		AcWing 98. 分形之城211人打卡
	前缀和与差分
		AcWing 99. 激光炸弹362人打卡
		AcWing 100. 增减序列325人打卡
	二分
		AcWing 102. 最佳牛围栏338人打卡
		AcWing 113. 特殊排序222人打卡
	排序
		AcWing 105. 七夕祭215人打卡
		AcWing 106. 动态中位数257人打卡
		AcWing 107. 超快速排序255人打卡
	RMQ
		AcWing 1273. 天才的记忆
4. 
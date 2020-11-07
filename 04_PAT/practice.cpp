1. string
	1. 2020年9月29日11:30:09
		1. 1473. A + B 格式	1001
			1. 笔记
				to_string()可以转换小数
				输入不大,用int来cin
			2. 注释
				#include <iostream>
				using namespace std;

				int main()
				{
				    int a, b;
				    cin >> a >> b;
				    int c = a + b;
				    string num = to_string(c);
				    string res;

				    for (int i = num.size() - 1, j = 0; i >= 0; i -- )
				    {
				        res = num[i] + res;
				        ++ j;
				        if (j % 3 == 0 && i && num[i - 1] != '-') res = ',' + res;
				    }

				    cout << res << endl;

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/259775/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					using namespace std;

					int main()
					{
						int a, b;
						cin >> a >> b;

						int c = a + b;
						string num = to_string(c);

						string res;
						for(int i = num.size()-1, j = 0; i >= 0 ; i --){
							res = num[i] + res;
							++j; //现在j就是我们res里面拥有的数字个数

							/*不能加的情况: 
							1. 还没有到3的倍数
							2. 当前的元素是第1个
								例如 ,999,999
							3. 当前的元素是第2个,但是前面有一个符号
								例如 -,999,999

							所以现在找反面
							*/
							if(j % 3 == 0 && i != 0 && (i >= 1 && num[i-1] != '-'))
								res = ',' + res;
						}

						cout << res << endl;

						return 0;
					}

				r2.
					#include <iostream>
					using namespace std;

					int main(){
						int a, b;
						cin >> a >> b;
						int c = a + b;
						string num = to_string(c);

						string res;
						for(int i = num.size()-1, j = 0; i >= 0 ; i--){
							res = num[i] + res;
							++j;
							if(j % 3 == 0 && i && ( i >= 1 && num[i-1] != '-'))
								res = ',' + res;
						}
						cout << res << endl;
						return 0;
					}
				r3.
					#include <iostream>
					using namespace std;

					int main(){
						int a, b;
						cin >> a >> b;
						int c = a + b;
						string num = to_string(c);

						string res;
						for(int i = num.size()-1, j = 0; i >= 0; i--){
							res = num[i] + res;
							++j;
							if(j % 3 == 0 && i && num[i-1] != '-')
								res = ',' + res;
						}
						cout << res << endl;
						return 0;
					}
				r4.
					#include <iostream>
					using namespace std;

					int main(){
						int a, b;
						cin >> a >> b;
						int c = a + b;
						string num = to_string(c);

						string res;
						for(int i = num.size()-1, j = 0; i >= 0 ; i--){
							res = num[i] + res;
							++j;
							if(j % 3 == 0 && i && num[i-1] != '-')
								res = ',' + res;
						}
						cout << res << endl;
						return 0;
					}
				r5.
					#include <iostream>
					using namespace std;

					int main(){
						int a, b;
						cin >> a >> b;
						int c = a + b;
						string num = to_string(c);

						string res;
						for(int i = num.size()-1, j = 0; i >= 0; i--){
							res = num[i] + res;
							++j;
							if(j % 3 == 0 && i && num[i-1] != '-')
								res = ',' + res;
						}
						cout << res << endl;
						return 0;
					}

		2. 1477. 拼写正确	1005
			1. 笔记
				1. 用index来代替switch
				2. 从int到string(to_string), 从string到int( - '0')
				3. 输出, 先输出第一个数字
				4. 注意, 之所以将int又转化成string是因为, 这样提取每个数字就很方便,而不需要%10,/10
			2. 注释
				#include <iostream>
				using namespace std;

				int main()
				{
				    string n;
				    cin >> n;

				    int s = 0;
				    for (auto c : n) s += c - '0';  // 计算每一位的总和

				    string str = to_string(s);

				    char word[10][10] = {
				        "zero", "one", "two", "three", "four",
				        "five", "six", "seven", "eight", "nine",
				    };

				    cout << word[str[0] - '0'];
				    for (int i = 1; i < str.size(); i ++ ) cout << ' ' << word[str[i] - '0'];

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/259807/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					using namespace std;
					int main(){
						string a;
						cin >> a;

						int sum = 0; //bug!
						for(auto c : a) sum += c - '0';

						string str = to_string(sum);
						char word[10][10] = {
							"zero", "one", "two", "three", "four",
				        "five", "six", "seven", "eight", "nine",
						};

						cout << word[str[0] - '0'];
						for(int i = 1; i < str.size(); i ++) cout << " " << word[str[i] - '0'];

						cout << endl;
						return 0; 
					}
				r2.
					#include <iostream>
					using namespace std;

					int main()
					{
						string a;
						cin >> a;

						int num = 0;
						for(auto i : a) num += i - '0';

						string sum = to_string(num);
						char word[10][10] = {
							"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
						};

						cout << word[sum[0] - '0'];
						for(int i = 1; i < sum.size(); i++) cout << " " << word[sum[i] - '0'];

						cout << endl;
						return 0;
					}
				r3.
					#include <iostream>
					using namespace std;
					int main(){
						string a;
						cin >> a;

						int num = 0;
						for(auto c : a) num += c - '0';

						string sum = to_string(num);
						char word[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",};

						cout << word[sum[0] - '0'];
						for(int i = 1; i < sum.size(); i++) cout << " " << word[sum[i] - '0'];

						cout << endl;
						return 0;
					}
				r4.
					#include <iostream>
					using namespace std;

					int main(){
						string a;
						cin >> a;

						int num = 0;
						for(auto c : a) num += c - '0';

						string sum = to_string(num);
						char word[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",};

						cout << word[sum[0] - '0'];
						for(int i = 1; i < sum.size(); i++) cout << " " << word[sum[i] - '0'];

						cout << endl;
						return 0;
					}
				r5.
					#include <iostream>
					using namespace std;

					int main(){
						string a;
						cin >> a;

						int num = 0;
						for(auto c : a) num += c - '0';

						string sum = to_string(num);
						char word[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",};
						cout << word[sum[0] - '0'];
						for(int i = 1; i < sum.size(); i++) cout << " " << word[sum[i] - '0'];

						cout << endl;
						return 0;
					}

		3. 1478. 签到与签出	1006
			0. bug
			1. 笔记
				1. 很简单的题
				2. 因为题目是xx:xx:xx的格式,所以很容易比较
					直接用string来cin, 然后直接用string的 > < 判断大小
						例如"08:00" < "12:00"
						但是"8" > "12"因为8>1
				3. 第一次赋值的特判,老师用了 i == 0, 我用了open_id == "", 注意不能用 == ''因为open_id是string, ''是char
			2. 注释
				#include <iostream>
				using namespace std;

				int main()
				{
				    string open_id, open_time;
				    string close_id, close_time;

				    int m;
				    cin >> m;

				    for (int i = 0; i < m; i ++ )
				    {
				        string id, in_time, out_time;
				        cin >> id >> in_time >> out_time;

				        // 更新开门的人
				        if (!i || in_time < open_time)
				        {
				            open_id = id;
				            open_time = in_time;
				        }

				        // 更新锁门的人
				        if (!i || out_time > close_time)
				        {
				            close_id = id;
				            close_time = out_time;
				        }
				    }

				    cout << open_id << ' ' << close_id << endl;

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/259824/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					using namespace std;

					int main(){
						string open_id, open_time; //因为id是很大的数字,所以用string而不是int
						string close_id, close_time;

						int m;
						cin >> m;
						while(m--){
							string id, in_time, out_time;
							cin >> id >> in_time >> out_time;

							if(open_id == "" || in_time < open_time){ //用到了string的字典序排序
								open_id = id;
								open_time = in_time;
							}

							if(close_id == "" || out_time > close_time){
								close_id = id;
								close_time = out_time;
							}
						}

						cout << open_id << " " << close_id << endl;
						return 0; 
					}
				r2.
					#include <iostream>
					using namespace std;

					int main(){

						string open_id, open_time;
						string close_id, close_time;

						int m;
						cin >> m;
						while(m--){
							string id, in_time, out_time;
							cin >> id >> in_time >> out_time;

							if(open_time == "" || in_time < open_time){
								open_id = id;
								open_time = in_time;
							}

							if(close_time == "" || out_time > close_time){
								close_id = id;
								close_time = out_time;
							}
						}
						cout << open_id << " " << close_id << endl;
						return 0;
					}
				r3.
					#include <iostream>
					using namespace std;

					int main(){

						string open_id, open_time;
						string close_id, close_time;

						int m;
						cin >> m;
						while(m--){
							string id, in_time, out_time;
							cin >> id >> in_time >> out_time;

							if(open_time == "" || in_time < open_time){
								open_id = id;
								open_time = in_time;
							}

							if(close_time == "" || out_time > close_time){
								close_id = id;
								close_time = out_time;
							}
						}
						cout << open_id << " " << close_id << endl;
						return 0;
					}
				r4.
					#include <iostream>
					using namespace std;

					int main(){
						string open_id, open_time;
						string close_id, close_time;
						
						int m;
						cin >> m;
						while(m--){
							string id, in_time, out_time;
							cin >> id >> in_time >> out_time;

							if(open_time == "" || in_time < open_time)
							{
								open_id = id;
								open_time = in_time;
							}

							if(close_time == "" || out_time > close_time){
								close_id = id;
								close_time = out_time;
							}
						}

						cout << open_id << " " << close_id << endl;
						return 0; 
					}
				r5.

		4. 1519. 密码	1035
			0. bug
			1. 笔记
				如果需要打印arr
					1. 这个arr设置成全局的
					2. 设置的时候,先定义const int N;
					3. 之后定义要放到哪个ind, 所以定义int m;
			2. 注释
				#include <iostream>
				using namespace std;

				const int N = 1010;

				string name[N], pwd[N];

				string change(string str)
				{
				    string res;

				    for (auto c : str)
				        if (c == '1') res += '@';
				        else if (c == '0') res += '%';
				        else if (c == 'l') res += 'L';
				        else if (c == 'O') res += 'o';
				        else res += c;

				    return res;
				}

				int main()
				{
				    int n;
				    cin >> n;

				    int m = 0;
				    for (int i = 0; i < n; i ++ )
				    {
				        string cur_name, cur_pwd;
				        cin >> cur_name >> cur_pwd;
				        string changed_pwd = change(cur_pwd);

				        if (changed_pwd != cur_pwd)
				        {
				            name[m] = cur_name;
				            pwd[m] = changed_pwd;
				            m ++ ;
				        }
				    }

				    if (!m)
				    {
				        if (n == 1) puts("There is 1 account and no account is modified");
				        else printf("There are %d accounts and no account is modified\n", n);
				    }
				    else
				    {
				        cout << m << endl;
				        for (int i = 0; i < m; i ++ ) cout << name[i] << ' ' << pwd[i] << endl;
				    }

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/259848/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					using namespace std;

					const int N = 1010;
					string name[N], pwd[N];

					string change(string cur){
						string res;
						for(auto c : cur){
							if (c == '1') res += '@';
					        else if (c == '0') res += '%';
					        else if (c == 'l') res += 'L';
					        else if (c == 'O') res += 'o';
					        else res += c;
						}
						return res;
					}

					int main(){
						int n;
						cin >> n;

						int m = 0;
						for(int i = 0; i < n; i++){
							string cur_name, cur_pwd;
							cin >> cur_name >> cur_pwd;

							string changed_pwd = change(cur_pwd);
							if(cur_pwd != changed_pwd){
								name[m] = cur_name;
								pwd[m] = changed_pwd;
								m++;
							}
						}

						if(!m){
							if(n == 1) puts("There is 1 account and no account is modified");
							else printf("There are %d accounts and no account is modified", n);
						}
						else{
							cout << m << endl;
							for(int i = 0; i < m ; i++) cout << name[i] << " " << pwd[i] << endl;
						}
						
						return 0;
					}
				r2.
					#include <iostream>
					using namespace std;

					const int N = 1010;
					string name_list[N], pwd_list[N];

					string change(string str){
						string res;
						for(auto c : str){
							if (c == '1') res += '@';
					        else if (c == '0') res += '%';
					        else if (c == 'l') res += 'L';
					        else if (c == 'O') res += 'o';
					        else res += c;
						}
						return res;
					}
					int main(){
						int n;
						cin >> n;

						int m = 0;
						for(int i = 0; i < n ; i++){
							string name, pwd;
							cin >> name >> pwd;

							string changed_pwd = change(pwd);
							if(pwd != changed_pwd){
								name_list[m] = name;
								pwd_list[m] = changed_pwd;
								m++;
							}
						}

						if(!m){
							if(n == 1) puts("There is 1 account and no account is modified");
							else printf("There are %d accounts and no account is modified", n);
						}
						else{
							cout << m << endl;
							for(int i = 0 ; i < m ; i++) cout << name_list[i] <<" " << pwd_list[i] << endl;
						}

						return 0;
					}
				r3.
					#include <iostream>
					using namespace std;

					const int N = 1010;
					string name[N], pwd[N];
					int m;

					string change(string str){
						string res;
						for(auto c : str){
							if (c == '1') res += '@';
					        else if (c == '0') res += '%';
					        else if (c == 'l') res += 'L';
					        else if (c == 'O') res += 'o';
					        else res += c;
						}
						return res;
					}

					int main(){
						int n;
						cin >> n;

						for(int i = 0; i < n; i++){
							string cur_name, cur_pwd;
							cin >> cur_name >> cur_pwd;

							string changed_pwd = change(cur_pwd);
							if(changed_pwd != cur_pwd){
								name[m] = cur_name;
								pwd[m] = changed_pwd;
								m++;
							}
						}

						if(!m){
							if(n == 1) puts("There is 1 account and no account is modified");
							else printf("There are %d accounts and no account is modified",n);
						}
						else{
							cout << m << endl;
							for(int i = 0; i < m ; i++) cout << name[i] << " " << pwd[i] << endl;
						}

						return 0;
					}
				r4.
					#include <iostream>
					using namespace std;

					const int N = 1010;
					string name[N], pwd[N];
					int m;

					string change(string str){
						string res;
						for(auto c : str){
							if (c == '1') res += '@';
						    else if (c == '0') res += '%';
						    else if (c == 'l') res += 'L';
						    else if (c == 'O') res += 'o';
						    else res += c;
						}
						return res;
					}

					int main(){
						int n;
						cin >> n;

						string cur_name, cur_pwd;
						for(int i = 0; i < n; i++){
							cin >> cur_name >> cur_pwd;

							string changed_pwd = change(cur_pwd);
							if(changed_pwd != cur_pwd){
								name[m] = cur_name;
								pwd[m] = changed_pwd;
								m++;
							}
						}

						if(!m){
							if(n == 1) puts("There is 1 account and no account is modified");
							else printf("There are %d accounts and no account is modified", n);
						}
						else{
							cout << m << endl;
							for(int i = 0; i < m ; i++) cout << name[i] << " " << pwd[i] << endl;
						}
						return 0;
					}
				r5.
					#include <iostream>
					using namespace std;

					const int N = 1010;
					string name[N], pwd[N];


					int m;

					string change(string str){
						string res;
						for(auto c : str){
							if (c == '1') res += '@';
					        else if (c == '0') res += '%';
					        else if (c == 'l') res += 'L';
					        else if (c == 'O') res += 'o';
					        else res += c;
						}
						return res;
					}
					int main(){
						int n;
						cin >> n;

						string cur_name, cur_pwd;
						for(int i = 0; i < n; i++){
							cin >> cur_name >> cur_pwd;

							string changed_pwd = change(cur_pwd);
							if(changed_pwd != cur_pwd){
								name[m] = cur_name;
								pwd[m] = changed_pwd;
								m++;
							}
						}

						if(!m){
							if(n == 1) puts("There is 1 account and no account is modified");
							else printf("There are %d accounts and no account is modified", n);
						}
						else{
							cout << m << endl;
							for(int i = 0 ; i < m ; i++) cout << name[i] << " " << pwd[i] << endl;
						}
						return 0;
					}

		5. 1520. 男孩 vs 女孩	1036
			0. bug
			1. 笔记
				1. 我的r1写法不够好,不够general
				2. 用str.emtpy()和str.size()来判断是否第一次赋值了
					而不是我的 if(str == "")
			2. 注释
				#include <iostream>

				using namespace std;

				int main()
				{
				    int n;

				    string girl_name, girl_id;  // 女生第一名的信息
				    int girl_score;
				    string boy_name, boy_id;  // 男生第一名的信息
				    int boy_score;

				    cin >> n;
				    for (int i = 0; i < n; i ++ )
				    {
				        string name, sex, id;
				        int score;
				        cin >> name >> sex >> id >> score;

				        if (sex == "F")  // 如果当前同学是女生
				        {
				            if (girl_name.empty() || girl_score < score)
				            {
				                girl_name = name;
				                girl_id = id;
				                girl_score = score;
				            }
				        }
				        else  // 男生
				        {
				            if (boy_name.empty() || boy_score > score)
				            {
				                boy_name = name;
				                boy_id = id;
				                boy_score = score;
				            }
				        }
				    }

				    if (girl_name.empty()) puts("Absent");
				    else cout << girl_name << ' ' << girl_id << endl;

				    if (boy_name.empty()) puts("Absent");
				    else cout << boy_name << ' ' << boy_id << endl;

				    if (girl_name.size() && boy_name.size()) cout << abs(girl_score - boy_score) << endl;
				    else cout << "NA" << endl;

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/259876/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					using namespace std;

					string g_name, g_id;
					int g = -1;
					string b_name, b_id;
					int b = 101; //这么写不够好

					int main(){
						int n;
						cin >> n;

						string name, gender, id;
						int score;
						for(int i = 0; i < n; i ++) {
							cin >> name >> gender >> id >> score;
							if(gender == "F" && score > g){
								g_name = name;
								g_id = id;
								g = score;
							}

							if(gender == "M" && score < b ){
								b_name = name;
								b_id = id;
								b = score;
							}
						}

						if(g == -1) puts("Absent");
						else cout << g_name << " " << g_id << endl;

						if(b == 101) puts("Absent");
						else cout << b_name << " " << b_id << endl;

						if(g != -1 && b != 101) cout << abs(b - g) << endl;
						else puts("NA");

						return 0;
					}
				r2.
					#include <iostream>
					using namespace std;

					string g_name, g_id;
					int g;
					string b_name, b_id;
					int b;

					int main(){
						int n;
						cin >> n;

						string name, gender, id;
						int score;
						for(int i = 0; i < n; i++){
							cin >> name >> gender >> id >> score;
							if(gender == "F"){
								if(g_name.empty() || score > g){
									g_name = name;
									g_id = id;
									g = score;
								}
							}
							else{
								if(b_name.empty() || score < b){
									b_name = name;
									b_id = id;
									b = score;
								}
							}
						}

						if(g_name.empty()) puts("Absent");
						else cout << g_name << " " << g_id << endl;

						if(b_name.empty()) puts("Absent");
						else cout << b_name << " " << b_id << endl;

						if(g_name.size() && b_name.size()) cout << abs(b - g) << endl;
						else puts("NA");

						return 0;

					}
				r3.
					#include <iostream>
					using namespace std;

					string g_name, g_id;
					int g;
					string b_name, b_id;
					int b;

					int main(){
						int n;
						cin >> n;

						string name, gender, id;
						int score;
						for(int i = 0; i < n; i++){
							cin >> name >> gender >> id >> score;
							if(gender == "F" && (g_name.empty() || score > g)){
								g_name = name;
								g_id = id;
								g = score;
							}

							if(gender == "M" && (b_name.empty() || score < b)){
								b_name = name;
								b_id = id;
								b = score;
							}
						}

						if(g_name.size()) cout << g_name << " " << g_id << endl;
						else puts("Absent");

						if(b_name.size()) cout << b_name << " " << b_id << endl;
						else puts("Absent");

						if(g_name.size() && b_name.size()) cout << abs(b - g) << endl;
						else puts("NA");

						return 0;
					}
				r4.
				r5.

		6. 1534. 字符串减法	1050
			0. bug
			1. 笔记
				1. 因为题目的输入中,一个字符串里面可能会有空格,所以我们不能用cin,而是用getline(cin, xx);
				2. 哈希表,用#include <unordered_set>
					复杂度是O(1)
					插入:
						xx.insert(c)
					个数:
						xx.count(a)
					如果xx中没有a
						if(xx.count(a) == 0)
						if(!xx.count(a))
				3. 因为题目哈希的是char, char是8bit, 一共256
					所以你可以开256个元素的数组
					int map[256] = {0,}; 
						全都初始化成0
					for(char c : s2) map[c] = 1; 
						不需要 - '0', 因为可能有特殊字符 )(*$#)
					
			2. 注释
			3. 5次
				r1.	会超时的做法,朴素的枚举, 复杂度是10^4 * 10^4, 0.1s是不够的的
					#include <iostream>
					using namespace std;

					bool hasC(char c, string& s2){
						for(auto s : s2){
							if(c == s) return true;
						}
						return false;
					}
					int main(){
						string s1, s2;

						getline(cin, s1);
						getline(cin, s2);

						string res;
						for(auto c : s1){
							if(!hasC(c, s2)) res += c;
						}

						cout << res << endl;
						return 0;
					}
				r2.
					#include <iostream>
					#include <unordered_set>

					using namespace std;

					int main(){
						string s1, s2;
						getline(cin, s1);
						getline(cin, s2);

						unordered_set<char> hash;
						for(char c : s2) hash.insert(c);

						string res;
						for(char c : s1){
							if(!hash.count(c)) res += c;
						}

						cout << res << endl;
						return 0;
					}
				r3.
					#include <iostream>
					#include <unordered_set>

					using namespace std;

					int main(){
						string s1, s2;
						getline(cin, s1);
						getline(cin, s2);

						unordered_set<char> hash;
						for(char c : s2)
							hash.insert(c);

						string res;
						for(char c : s1){
							if(!hash.count(c)) res += c;
						}

						cout << res << endl;
						return 0;
					}
				r4.
					#include <iostream>

					using namespace std;

					int main(){
						string s1, s2;
						getline(cin, s1);
						getline(cin, s2);

						int map[256] = {0,}; //全都初始化成0
						for(char c : s2){
							map[c] = 1; //不需要 - '0', 因为可能有特殊字符 )(*$#)
						}

						string res;
						for(char c : s1){
							if(map[c] == 0) res += c;
						}

						cout << res << endl;
						return 0;
					}
				r5.
					#include <iostream>
					using namespace std;

					int main(){
						string s1, s2;
						getline(cin, s1);
						getline(cin, s2);

						int map[256] = {0,};
						for(char c : s2) map[c] = 1;

						string res;
						for(char c : s1) {
							if(map[c] == 0) res += c;
						}

						cout << res << endl;
						return 0;
					}

		7. 1557. 说话方式	1071
			0. bug
				1. 不能这么写:我的本意是用while看下单词有多长,然后用substr来取出,但是因为tolower()只能处理char
					size_t j = i;
					while(j < s1.size() && isword(s1[j])) j++;
					string word = tolower(s1.substr(i, j-i)); 会报错, 因为tolower()只能处理char
				2. 忘记j++
			1. 笔记
				0. 用了双指针
					先检测到word的第一个字符,如果符合就用while()取出整个word
						int j = i; 首先让j指向i的位置
						while()需要先判断是否越界, 记得每次做完就j++
						取出之后,要放入map中
						最后i = j, 因为j所在的位置是不符合我们check()的char
							然后i++之后,我们就检测下一个char是不是符合check()
				1. 用unordered_map<string, int>存, 复杂度是O(1)
					同时我们可以通过string的>,<来比较两个string的字典序
				2. 用朴素的方法遍历了map里的所有元素,找出最小的.
				3. A是65, a是97, 所以 c+=32就可以大写变成小写
				4. 保险起见,用for(size_t i = 0; i < s.size(); i++), 因为s.size()是string::size_type

			2. 注释
				#include <iostream>
				#include <unordered_map>

				using namespace std;

				bool check(char c)
				{
				    if (c >= '0' && c <= '9') return true;
				    if (c >= 'A' && c <= 'Z') return true;
				    if (c >= 'a' && c <= 'z') return true;
				    return false;
				}

				char to_lower(char c)
				{
				    if (c >= 'A' && c <= 'Z') return c + 32;
				    return c;
				}

				int main()
				{
				    string str;
				    getline(cin, str);

				    unordered_map<string, int> hash;

				    for (int i = 0; i < str.size(); i ++ )
				        if (check(str[i]))
				        {
				            string word;
				            int j = i;
				            while (j < str.size() && check(str[j])) word += to_lower(str[j ++ ]);

				            hash[word] ++ ;
				            i = j;
				        }

				    string word;
				    int cnt = -1;
				    for (auto item : hash)
				        if (item.second > cnt || item.second == cnt && item.first < word)
				        {
				            word = item.first;
				            cnt = item.second;
				        }

				    cout << word << ' ' << cnt << endl;

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/259944/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					bool isword(char c){
						if(c >= '0' && c <= '9') return true;
						else if(c >= 'A' && c <= 'Z') return true;
						else if(c >= 'a' && c <= 'z') return true;
						else return false;
					}

					char mytolower(char c){
						if( c >= 'A' && c <= 'Z') return c + 32;
					}
					int main(){
						string s1;
						getline(cin, s1);

						unordered_map<string, int> map;
						for(size_t i = 0; i < s1.size(); i++){
							if(isword(s1[i])){
								size_t j = i;
								string word;
								while(j < s1.size() && isword(s1[j])) word += mytolower(s1[j++]);
								map[word]++;
								i = j; 
							}
						}
						
						
						string word;
						int cnt = 0;
						for(auto item : map){
							string w = item.first;
							int c = item.second;
							if(word.empty() || c > cnt || (c == cnt && w < word)){
								word = w;
								cnt = c;
							}
						}

						cout << word << " " << cnt << endl;
						return 0;
					}
				r2.
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					bool check(char c){
						if(c >= '0' && c <= '9') return true;
						else if( c >= 'A' && c <= 'Z') return true;
						else if(c >= 'a' && c <= 'z') return true;
						return false;
					}

					int main(){
						string s;
						getline(cin, s);

						unordered_map<string, int> map;
						for(size_t i = 0; i < s.size(); i++){
							if(check(s[i])){
								size_t j = i;

								string word;
								while(j < s.size() && check(s[j]))
								{
									word += tolower(s[j++]);
								}

								map[word]++;
								i = j;
							}
						}

						string res;
						int cnt = 0;
						for(auto item : map){
							string w = item.first;
							int c = item.second;
							if(res.empty() || c > cnt || (c == cnt && w < res)){
								res = w;
								cnt = c;
							}
						}

						cout << res << " " << cnt << endl;
						return 0;
					}
				r3.
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					bool check(char c){
						if(c >= '0' && c <= '9') return true;
						else if(c >= 'A' && c <= 'Z') return true;
						else if(c >= 'a' && c <= 'z') return true;
						else return false;
					}

					int main(){
						string s;
						getline(cin, s);

						unordered_map<string, int> map;
						for(int i = 0; i < s.size(); i++){
							if(check(s[i])){
								size_t j = i;

								string word;
								while(j < s.size() && check(s[j])){
									word += tolower(s[j++]);
								}

								map[word]++;
								i = j;
							}
						}

						string res;
						int cnt;
						for(auto item : map){
							string w = item.first;
							int c = item.second;

							if(res.empty() || c > cnt || (c == cnt && w < res)){
								res = w;
								cnt = c;
							}
						}

						cout << res << " " << cnt << endl;
						return 0;
					}


				r4.
				r5.

		8. 1547. 约会	1061
			0. bug
				1. 小心 && || 在一起写, 需要加足够多的括号
					例如(xx && (cc && dd) || (aa && bb)) 是错的
					(xx && ((cc && dd) || (aa && bb))) 是对的
				2. a[k] - 'A' + 10 容易漏写+10
			1. 笔记
				1. 如果格式需要是补零,例如0n或者nn, 那么就是 %02d, 而不是%d
				2. 看第二个字符的时候, 需要k++; //这是我之前的bug
				3. 假设for(int i = 0; i < n ; i++) {
					if(xxx) break;
				}	break完了之后,i不会++
				4. '0'到'9' 是在 'A'到'Z'前面, 'A'到'Z'是在'a'到'z'前面
				5. 我们的printf("%s", xx[0]), 其中xx是char xx[10][10] = {"xx", "yy", ...} 
					char[][]可以用%s
				6. 两段式的将一个char映射到int上, 这个char可以是'0'-'9'也可以是'a'-'z','A'-'Z'
					所以是两段式
						int res = a[k] <= '9' ? a[k] - '0' : a[k] - 'A' + 10;
						注意是 a[k]-'0'不是 a[k]-'9'
			2. 注释
				#include <cstdio>
				#include <iostream>

				using namespace std;

				int main()
				{
				    string a, b, c, d;
				    cin >> a >> b >> c >> d;

				    int k = 0;
				    while (true)
				    {
				        if (a[k] == b[k] && a[k] >= 'A' && a[k] <= 'G') break;
				        k ++ ;
				    }

				    char weekdays[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
				    printf("%s ", weekdays[a[k] - 'A']);

				    k ++ ;
				    while (true)
				    {
				        if (a[k] == b[k] && (a[k] >= '0' && a[k] <= '9' || a[k] >= 'A' && a[k] <= 'N')) break;
				        k ++ ;
				    }

				    printf("%02d:", a[k] <= '9' ? a[k] - '0' : a[k] - 'A' + 10);

				    for (int i = 0;; i ++ )
				        if (c[i] == d[i] && (c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z'))
				        {
				            printf("%02d\n", i);
				            break;
				        }

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/262678/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					using namespace std;

					int main(){
						string a,b,c,d;
						cin >> a >> b >> c >> d;

						char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
						size_t i;
						for(i = 0; i < a.size() && i < b.size(); i ++){
							if(a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G'){
								cout << day[a[i] - 'A'] << " ";
								break;
							}
						}

						i++;
						for(; i < a.size() && i < b.size() ; i++){
							if(a[i] == b[i] && (a[i] >= '0' && a[i] <= '9' || a[i] >= 'A' && a[i] <= 'Z')){
								printf("%02d:", a[i] <= '9' ? a[i] - '0' : a[i] - 'A' + 10);
								break;
							}
						}

						for(size_t j = 0; j < c.size() && j < d.size(); j++){
							if(c[j] == d[j] && (c[j] >= 'a' && c[j] <= 'z') || (c[j] >= 'A' && c[j] <= 'Z')){
								printf("%02d", j);
							}
						}
						cout << endl;
						return 0;

					}
				r2.
					#include <iostream>
					using namespace std;

					int main(){
						string a, b, c, d;
						cin >> a >> b >> c >> d;

						int i = 0;
						char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
						while(true) {
							if(a[i] == b[i] && a[i] >= 'A' && a[i] <= 'G'){
								printf("%s ", day[a[i] - 'A']);
								break;
							}
							i++;
						}
						
					    i++;
						while(true){
							if(a[i] == b[i] && (a[i] >= '0' && a[i] <= '9' || a[i] >= 'A' && a[i] <= 'N')){
								printf("%02d:", a[i] <= '9' ? a[i] - '0' : a[i] - 'A' + 10);
								break;
							}
							i++;
						}

						for(int j = 0; j < c.size() && j < d.size() ; j ++){
							if(c[j] == d[j] && (c[j] >= 'a' && c[j] <= 'z' || c[j] >= 'A' && c[j] <= 'Z'))
							{
								printf("%02d\n", j);
								break;
							}
						}

						return 0;
					}
				r3.
					#include <iostream>
					#include <cstdio>

					using namespace std;

					int main(){
						string a, b, c, d;
						cin >> a >> b >> c >> d;

						int k = 0;
						char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

						while(true){
							if(a[k] == b[k] && (a[k] >= 'A' && a[k] <= 'G')){
								printf("%s ", day[b[k] - 'A']);
								break;
							}
							k++;
						}

						k++;
						while(true){
							if(a[k] == b[k] && (a[k] >= '0' && a[k] <= '9' || a[k] >= 'A' && a[k] <= 'N')){
								int res = a[k] <= '9' ? a[k] - '0' : a[k] - 'A' + 10;
								printf("%02d:", res);
								break;
							}
							k++;
						}

						for(int i = 0; i < c.size() && i < d.size(); i++){
							if(c[i] == d[i] && (c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z'))
							{
								printf("%02d", i);
								break;
							}
						}

						return 0;

					}
				r4.
					#include <iostream>
					#include <cstdio>

					using namespace std;

					int main(){
						string a, b, c, d;
						cin >> a >> b >> c >> d;

						size_t k;
						char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
						for(k = 0; k < a.size() && k < b.size() ; k++){
							if(a[k] == b[k] && (a[k] >= 'A' && a[k] <= 'G')){
								printf("%s ", day[a[k] - 'A']);
								break;
							}
						}

						k++;
						for(; k < a.size() && k < b.size(); k++){
							if(a[k] == b[k] && (a[k] >= '0' && a[k] <= '9' || a[k] >= 'A' && a[k] <= 'N'))
							{
								int res = a[k] <= '9' ? a[k] - '0' : a[k] - 'A' + 10;
								printf("%02d:", res);
								break;
							}
						}

						for(int i = 0; i < c.size() && i < d.size() ; i++){
							if(c[i] == d[i] && (c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z')){
								printf("%02d", i);
								break;
							}
						}

						return 0;
					}

				r5.

		9. 1493. 电话账单	1016
			0. bug
				0. 注意用到除法的时候,使用double
				1. scanf()存到char[]中, printf()如果是string需要.c_str()
				2. 格式化打印:
					char formated_time[20];
					sprintf(formated_time, "%02d:%02d:%02d", day, hour, minutes);
				3. 保留2位小数: "%.2lf"
				4. 注意美元美分的转换, 注意cost是某小时的每分钟话费不是每小时话费
				5. 判断double a是否!=0
					错误: if(!a)
					正确: If(a > 0)
				6. cost[(i - 1) % 1440 / 60]
					也就是某个月的第i分钟,属于那一天的第几个小时
				7. 每次局部变量最好在声明的时候都初始化以下,否则会出现你想不到的bug!
					例如我在for loop里面定义了 double t, 每次都会用到它
					如果你初始化成某个值,到下一轮的时候,这个t还会用着上一轮的值,很恐怖!
				8. 如果是for(auto xx : yyy) 一个很大的东西的时候, 用引用
					for(auto &item : person)
			1. 笔记
				1. 见r1
					用到了struct
					用到了重载<, sort()
					用到了前缀和
			2. 注释
				#include <cstdio>
				#include <cstring>
				#include <iostream>
				#include <algorithm>
				#include <map>
				#include <vector>

				using namespace std;

				const int N = 1010, M = 31 * 1440 + 10;

				int n;
				int cost[24];  // 每个时间段的话费
				double sum[M];  // 从当月1号00:00开始到每个时刻所花费的钱数

				struct Record
				{
				    int minutes;
				    string state;
				    string format_time;

				    bool operator< (const Record& t) const
				    {
				        return minutes < t.minutes;
				    }
				};

				map<string, vector<Record>> persons;

				int main()
				{
				    for (int i = 0; i < 24; i ++ ) cin >> cost[i];
				    for (int i = 1; i < M; i ++ ) sum[i] = sum[i - 1] + cost[(i - 1) % 1440 / 60] / 100.0;

				    cin >> n;
				    char name[25], state[10], format_time[20];
				    int month, day, hour, minute;
				    for (int i = 0; i < n; i ++ )
				    {
				        scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minute, state);
				        sprintf(format_time, "%02d:%02d:%02d", day, hour, minute);

				        int minutes = (day - 1) * 1440 + hour * 60 + minute;
				        persons[name].push_back({minutes, state, format_time});
				    }

				    for (auto &person : persons)
				    {
				        auto name = person.first;
				        auto records = person.second;
				        sort(records.begin(), records.end());

				        double total = 0;
				        for (int i = 0; i + 1 < records.size(); i ++ )
				        {
				            auto a = records[i], b = records[i + 1];
				            if (a.state == "on-line" && b.state == "off-line")
				            {
				                if (!total) printf("%s %02d\n", name.c_str(), month);
				                cout << a.format_time << ' ' << b.format_time;

				                double c = sum[b.minutes] - sum[a.minutes];
				                printf(" %d $%.2lf\n", b.minutes - a.minutes, c);
				                total += c;
				            }
				        }

				        if (total) printf("Total amount: $%.2lf\n", total);
				    }

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/262740/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <map>
					#include <cstdio> //printf(), scanf()
					#include <algorithm>

					using namespace std;

					const int M = 31*24*60 + 10; // 31天, 每天24h, 每小时60m

					struct Record{
						string state;
						int minutes;  //相对于1号的0点0分的绝对分钟数
						string formated_time;

						bool operator< (const Record& t) const{ //sort()需要重载小于号
							return minutes < t.minutes; //我什么时候优先在左? 我minutes小的时候
						}
					};

					int main(){
						int cost[24];
						for(int i = 0; i < 24; i++) {
							cin >> cost[i];
						}

						double sum[M]; //从1号的0点0分开始算. 其中如果结束通话时间是06:00, 那么我们算钱的时候,只算到05:59的钱
						for(int i = 1; i < 31*1440; i++){
							int inday_minutes = (i - 1) % 1440;
							int which_hour = inday_minutes / 60; //如果是第60分钟, 那(60-1)/60 == 0 hour, 如果是1分钟, 也是(1-1)/60 == 0hour	
							sum[i] = sum[i-1] + cost[which_hour] / 100.0;
						}
						//如果题目是通话结束时06:00也依旧算成06:00的钱,那么:
						// for(int i = 1; i < 31*1440; i++){
						// 	sum[i] = sum[i-1] + cost[(i % 1440) / 60] / 100.0;
						// }

						int k;
						cin >> k;

						char name[100], state[10];
						int month, day, hour, minutes;

						map<string, vector<Record>> input; 
						/*我之前在想为什么map有一个string name然后Record里面也有一个string name
						我发现其实Record里面没有string name也没有关系,因为不存在什么相互映射的关系
						map的string name是为了让我们区分每个人,让每个人的信息都统一到一起
						*/
						/*
						为什么是用map,而不是用unordered_map
						因为用map的话,遍历map里面的所有成员,就是按照string name的字典序排序的了
						因为题目要求了:客户姓名的字母顺序（按ASCII码顺序，大写字母在前，小写字母在后）打印。
						*/
						/*
						我之前在想需不需要判断input里面有没有name这个成员,但是不需要,不管有没有都可以push_back
						*/
						int abs_minutes;
						char formated_time[20];
						for(int i = 0; i < k ; i ++){
							 scanf("%s %d:%d:%d:%d %s", name, &month, &day, &hour, &minutes, state);
							 abs_minutes = (day - 1) * 1440 + hour * 60 + minutes;
							 sprintf(formated_time, "%02d:%02d:%02d", day, hour, minutes);

							input[name].push_back({state, abs_minutes, formated_time});
						}

						for(auto &item : input){
							auto name = item.first;
							auto record = item.second; //这个就是某个人所有的通话记录,但是是无序的,需要排序

							sort(record.begin(), record.end());
							bool is_first = true;
							double total_fee = 0;
							for(int i = 0; i + 1 < record.size() ; i++){ //你看是i++,因为如果遇到了online, online, online, offline的情况, 我们会一个个挪到最后一个online和offline
								if(record[i].state == "on-line" && record[i+1].state == "off-line"){
									double fee = sum[record[i+1].minutes] - sum[record[i].minutes];
									total_fee += fee;
									int duration = record[i+1].minutes - record[i].minutes;
									if(is_first) {
										printf("%s %02d\n", name.c_str(), month);
										is_first = false;
									}
									printf("%s %s %d $%.2lf\n", record[i].formated_time.c_str(), record[i+1].formated_time.c_str(), duration, fee);
								}
							}
							if(total_fee != 0)printf("Total amount: $%.2lf\n", total_fee);
						}

						return 0;
					}
				r2.
					#include <iostream>
					#include <map>
					#include <algorithm>


					using namespace std;

					const int M = 31*24*60 + 10;

					struct Rec{
						int abs_minutes;
						string formated_time;
						string state;

						bool operator< (const Rec& t) const{
							return abs_minutes < t.abs_minutes;
						}
					};
					int main(){
						int cost[24];
						for(int i = 0; i < 24; i++) cin >> cost[i];
						double sum[M];
						for(int i = 1; i < M; i++){
							sum[i] = sum[i-1] + cost[(i - 1) % 1440 / 60] / 100.0;
						}

						int k;
						cin >> k;

						char name[40], state[10];
						int month, day, h, m;

						int minutes;
						char formated_time[20];
						map<string, vector<Rec>> input;
						while(k--){
							scanf("%s %d:%d:%d:%d %s", name, &month, &day, &h, &m, state);

							//加工:
							minutes = day * 1440 + h *60 + m;
							sprintf(formated_time, "%02d:%02d:%02d", day, h, m);

							input[name].push_back({minutes, formated_time, state});
						}

						for(auto &item : input){
							string name = item.first;
							auto vec = item.second;

							sort(vec.begin(), vec.end());

							double fee = 0.;
							int duration = -1;
							bool is_first = true;
							double total_fee = 0.;
							for(size_t i = 0; i + 1 < vec.size(); i++){
								if(vec[i].state == "on-line" && vec[i+1].state == "off-line"){
									fee = sum[vec[i+1].abs_minutes] - sum[vec[i].abs_minutes];
									total_fee += fee;
									duration = vec[i+1].abs_minutes - vec[i].abs_minutes;
									if(is_first) {
										printf("%s %02d\n", name.c_str(), month);
										is_first = false;
									}
									printf("%s %s %d $%.2lf\n", vec[i].formated_time.c_str(), vec[i+1].formated_time.c_str(), duration, fee);
								}
							}
							if(total_fee > 0) printf("Total amount: $%.2lf\n", total_fee);
						}
						return 0;
					}
				r3.
					#include <iostream>
					#include <map>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int M = 31*1440 + 10;

					struct Rec{
						int abs_minutes;
						string formated_time;
						string state;

						bool operator< (const Rec& t) const{
							return abs_minutes < t.abs_minutes;
						}
					};

					int main(){
						int cost[24];
						for(int i = 0; i < 24; i++) cin >> cost[i];
						double sum[M];
						for(int i = 1; i < M; i++) sum[i] = sum[i-1] + cost[(i-1) % 1440 / 60] / 100.0;

						int k;
						cin >> k;
						char name[20], state[10];
						int month, day, h, m;

						int abs_minutes;
						char formated_time[20];
						map<string, vector<Rec>> input;
						while(k--){
							scanf("%s %d:%d:%d:%d %s", name, &month, &day, &h, &m, state);

							abs_minutes = (day-1) * 1440 + h * 60 + m;
							sprintf(formated_time, "%02d:%02d:%02d", day, h, m);

							input[name].push_back({abs_minutes, formated_time, state});
						} 

						for(auto &item : input){
							string name = item.first;
							vector<Rec> vec = item.second;

							sort(vec.begin(), vec.end());

							int duration;
							double fee;
							bool is_first = true;
							double total_fee = 0;
							for(size_t i = 0; i + 1 < vec.size(); i++){
								if(vec[i].state == "on-line" && vec[i+1].state == "off-line"){
									duration = vec[i+1].abs_minutes - vec[i].abs_minutes;
									fee = sum[vec[i+1].abs_minutes] - sum[vec[i].abs_minutes];
									total_fee += fee;
									if(is_first){
										printf("%s %02d\n", name.c_str(), month);
										is_first = false;
									}
									printf("%s %s %d $%.2lf\n", vec[i].formated_time.c_str(), vec[i+1].formated_time.c_str(), duration, fee);
								}
							}
							if(total_fee > 0) printf("Total amount: $%.2lf\n", total_fee);
						}
						return 0;
					}
				r4.
					#include <iostream>
					#include <map>
					#include <vector>
					#include <cstdio>
					#include <algorithm>

					using namespace std;

					const int M = 31 * 1440 + 10;
					int cost[24];
					double sum[M];

					struct Rec{
						int abs_minutes;
						string formated_time;
						string state;

						bool operator< (const Rec& t) const{
							return abs_minutes < t.abs_minutes;
						}
					};

					int main(){
						
						for(int i = 0; i < 24; i++) cin >> cost[i];
						for(int i = 1; i < M; i++) sum[i] = sum[i-1] + cost[(i-1) % 1440 / 60] / 100.0;

						int k;
						cin >> k;
						char name[30], state[20];
						int month, day, h, m;

						int abs_minutes;
						char formated_time[30];

						map<string, vector<Rec>> input;
						while(k--){
							scanf("%s %d:%d:%d:%d %s", name, &month, &day, &h, &m, state);

							abs_minutes = (day-1)*1440 + h *60 + m;
							sprintf(formated_time, "%02d:%02d:%02d", day, h, m);

							input[name].push_back({abs_minutes, formated_time, state});
						}

						for(auto &person : input){
							string name = person.first;
							auto vec = person.second;

							sort(vec.begin(), vec.end());

							double fee = 0.0;
							int duration = 0;
							bool is_first = true;
							double total = 0.0;
							for(int i = 0 ; i + 1 < vec.size(); i++){
								if(vec[i].state == "on-line" && vec[i+1].state == "off-line"){
									fee = sum[vec[i+1].abs_minutes] - sum[vec[i].abs_minutes];
									total += fee;
									duration = vec[i+1].abs_minutes - vec[i].abs_minutes;
									if(is_first){
										printf("%s %02d\n", name.c_str(), month);
										is_first = false;
									}
									printf("%s %s %d $%.2lf\n", vec[i].formated_time.c_str(), vec[i+1].formated_time.c_str(), duration, fee);
								}
							}
							if(total > 0) printf("Total amount: $%.2lf\n", total);
						}

						return 0;
					}
				r5.

		10. 1494. 银行排队	1017
			0. bug
			1. 笔记
				1. 使用了struct数组, 而不是vector<struct>
					0. 我觉得两个都可以, 不过因为题目给了一共有多少人,所以用数组也可以知道size
					1. 感觉vector<Struct>更多是和map一起使用的,而map是需要key也就是string name,但是这道题并没有name
					2. 数组[]和vector都可以用sort(),只不过一个是sort(arr, arr + n), sort(vec.begin(), vec.end())
				2. 使用了小跟堆来表示 windows
					1. 因为题目只需要计算等待时间,不区分每个windows的编号
					2. 只需要知道最早释放的windows,和第一个到来的人
						最早释放的win: 用priority_queue的top()
						第一个到来的人: 用sort(arr, arr + n) for(int i = 0; i < n ; i++) auto p = person[i]
				3. 逻辑:
					1. 开始服务时间 = max(最早释放的win, 接下来第一个到来的人)
					2. 等待时间 = 开始服务时间 - 第一个到来的人;
								要么 == 0, 要么 == 最早释放的win - 第一个到来的人
					3. 更新win的时间 = 开始服务时间 + 这个人需要的时间
				3/ 
			2. 注释
				#include <cstdio>
				#include <cstring>
				#include <iostream>
				#include <algorithm>
				#include <queue>

				using namespace std;

				const int N = 10010, M = 110;

				int n, m;

				struct Person
				{
				    int arrive_time;
				    int service_time;

				    bool operator< (const Person& t) const  // 按到达时间排序
				    {
				        return arrive_time < t.arrive_time;
				    }
				}persons[N];

				int main()
				{
				    cin >> n >> m;

				    for (int i = 0; i < n; i ++ )
				    {
				        int hour, minute, second, service_time;
				        scanf("%d:%d:%d %d", &hour, &minute, &second, &service_time);
				        service_time = min(service_time, 60);

				        persons[i] = {hour * 3600 + minute * 60 + second, service_time * 60};
				    }

				    priority_queue<int, vector<int>, greater<int>> windows;

				    for (int i = 0; i < m; i ++ ) windows.push(8 * 3600);  // 先把m个窗口安排好

				    sort(persons, persons + n);

				    int sum = 0, cnt = 0;

				    for (int i = 0; i < n; i ++ )
				    {
				        auto person = persons[i];
				        int w = windows.top();
				        windows.pop();
				        if (person.arrive_time > 17 * 3600) break;  // 来晚了，则忽略

				        int start_time = max(person.arrive_time, w);
				        sum += start_time - person.arrive_time;
				        cnt ++ ;

				        windows.push(start_time + person.service_time);
				    }

				    printf("%.1lf\n", (double)sum / cnt / 60);

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/262814/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <queue>
					#include <algorithm>

					using namespace std;

					const int N = 10010;
					struct Person{
						int abs_s;
						int serve;

						bool operator< (const Person& t) const{
							return abs_s < t.abs_s;
						}
					}person[N];

					int main(){
						int n, d;
						cin >> n >> d;

						int h, m, s, serve;
						int abs_s;
						for(int i = 0; i < n ; i ++){
							scanf("%d:%d:%d %d", &h, &m, &s, &serve);
							abs_s = h * 3600 + m * 60 + s;
							
							serve = 60 * min(serve, 60);
							person[i] = {abs_s, serve};
						}

						priority_queue<int, vector<int>, greater<int>> server;
						for(int i = 0; i < d; i++) server.push(8 * 3600);

						sort(person, person + n);

						double total_wait = 0;
						int cnt = 0;
						for(int i = 0; i < n; i++){
							auto p = person[i];
							if(p.abs_s > 17 * 3600) break;

							int w = server.top();
							server.pop();

							int start_serve = max(w, p.abs_s);
							total_wait += start_serve - p.abs_s;
							cnt ++;

							server.push(start_serve + p.serve);
						}
						printf("%.1lf", total_wait / 60 / cnt);
						return 0;
					}
				r2.
					#include <iostream>
					#include <cstring>
					#include <cstdio>
					#include <algorithm>
					#include <queue>

					using namespace std;

					const int N = 10010;

					struct Person{
						int abs_seconds;
						int serve_time;

						bool operator< (const Person& t) const{
							return abs_seconds < t.abs_seconds;
						}
					}persons[N];

					int main(){
						int n, m;
						cin >> n >> m;

						int hour, minutes, seconds, serve_time;
						int abs_seconds;
						for(int i = 0; i < n; i++){
							scanf("%d:%d:%d %d", &hour, &minutes, &seconds, &serve_time);
							abs_seconds = hour * 3600 + minutes * 60 + seconds;
							serve_time = min(60, serve_time);
							persons[i] = {abs_seconds, serve_time * 60};
						}
						
						priority_queue<int, vector<int>, greater<int>> windows;
						for(int i = 0; i < m; i++) windows.push(8 * 3600);

						sort(persons, persons + n);
						
						int wait = 0;
						int cnt = 0;
						for(int i = 0; i < n; i++){
							auto p = persons[i];
							if(p.abs_seconds > 17 * 3600) break;

							int w = windows.top();
							windows.pop();

							int start = max(w, p.abs_seconds);
							wait += start - p.abs_seconds;
							cnt ++;
							
							windows.push(start + p.serve_time);
						}

						printf("%.1lf\n", (double) wait / 60 / cnt);

						return 0;
					}
				r3.
					#include <iostream>
					#include <cstring>
					#include <cstdio>
					#include <algorithm>
					#include <vector>
					#include <queue>

					using namespace std;

					const int N = 10010;

					struct Person{
						int abs_seconds;
						int duration;

						bool operator< (const Person& t) const{
							return abs_seconds < t.abs_seconds;
						}
					}persons[N];

					int main(){
						int a, b;
						cin >> a >> b;

						int hour, minutes, seconds, duration;
						int abs_seconds;
						for(int i = 0 ; i < a ; i++){
							scanf("%d:%d:%d %d", &hour, &minutes, &seconds, &duration);

							abs_seconds = hour * 3600 + minutes * 60 + seconds;
							duration = min(60, duration) * 60;

							persons[i] = {abs_seconds, duration};
						}

						priority_queue<int, vector<int>, greater<int>> windows;
						for(int i = 0 ; i < b; i++) windows.push(8*3600);

						sort(persons, persons + a);

						int wait = 0;
						int cnt = 0;
						for(int i = 0 ; i < a; i++){
							auto p = persons[i];
							if(p.abs_seconds > 17*3600) break;

							int w = windows.top();
							windows.pop();

							int start = max(p.abs_seconds, w);
							wait += start - p.abs_seconds;
							cnt ++;

							int end = start + p.duration;
							windows.push(end);
						}

						printf("%.1lf\n", (double) wait / 60 / cnt );
						return 0;
					}
				r4.
					#include <iostream>
					#include <cstdio>
					#include <queue>
					#include <algorithm>

					using namespace std;

					const int N = 10010;

					struct Person{
						int abs_seconds;
						int serve_time;

						bool operator< (const Person& t) const{
							return abs_seconds < t.abs_seconds;
						}
					}persons[N];

					int main(){
						int n, m;
						cin >> n >> m;

						int hour, minutes, seconds, serve_time;
						int abs_seconds;
						for(int i = 0; i < n; i++){
							scanf("%d:%d:%d %d", &hour, &minutes, &seconds, &serve_time);
							abs_seconds = hour * 3600 + minutes * 60 + seconds;
							serve_time = min(60, serve_time) * 60;

							persons[i] = {abs_seconds, serve_time};
						}

						priority_queue<int, vector<int>, greater<int>> windows;
						for(int i = 0; i < m ; i++) windows.push(8 * 3600);

						sort(persons, persons + n);

						int wait = 0;
						int cnt = 0;
						for(int i = 0; i < n ; i++){
							auto p = persons[i];
							if(p.abs_seconds > 17 * 3600) break;

							int w = windows.top();
							windows.pop();

							int start = max(w, p.abs_seconds);
							wait += start - p.abs_seconds;
							cnt ++;

							int end = start + p.serve_time;
							windows.push(end);
						}

						printf("%.1lf\n", (double) wait / 60 / cnt);
						return 0;
					}
				r5.

	2. 2020年9月30日11:30:20
		11. 1503. 乒乓球 $$	1026
			0. bug
				1. 四舍五入用round, 向上取整用ceil()
					#include <cmath>
					printf()不能用%d,而是用%.0lf(不要小数点), 血的教训!!
							int p.wait_time;
							printf("%.0lf\n",round(p.wait_time / 60.0));
				1. 血的教训!
					assign(xx &ps, xx &ts); 应该是引用啊!!否则ps和ts都不会被更改!
				2. 从秒,计算是第几小时:
					h = secs / 3600;
				3. 从秒,计算是第几分钟:
					m = secs % 3600 / 60;
				4. 从秒,计算第几秒
					s = secs % 60
				5. 从分钟, 到第几天
					d = m / 1440
				5. 从分钟, 到某天的第几个小时
					h = s % 1440 / 60
				6. 总结:
					N1 = t / a;
						例如 h = s / 3600
					N2 = t / b; 
						例如 m = s / 60;
					所以
						n1 = t / a;
							例如 h = s / 3600;
							例如 d = m / 1440;
						n2 = t % a / b;
							例如 m = s % 3600 / 60;
							例如 h = m % 1440 / 60;
			1. 笔记
				1. 用户必须用堆来存,因为有1w个,如果用数组存的话,for()每次遍历都会很慢, 我的疑问:我们不可以用sort()线与处理吗
				2. 球台比一定用堆存, 可以用数组,因为只有100个
				3. 在建立struct的时候, 先里面应该有什么参数的时候
					1. 想想input有什么
						在input的时候, 直接给的信息,  推入
					2. 想想output需要什么,加工的时候处理的
						在加工的时候,推入
				4. 很多时候,我预先想的数据结构可能是不对的,会在写的过程中改
					例如,我以为每个台有多少人用过是可以用cnt记录在Table结构体的
					但是后来发现输出的时候太麻烦,最后用了老师的int cnt[]数组,很方便
				5. 重载运算符
					1. 如果是用sort()处理, 就要重载<
						想的时候: 我如何能够排到左侧的语句
					2. 如果是用priority_queue的top(), 重载>
						如果是大根堆: 就是正常的想: 我如何能够脱颖而出,当最大
						如果是小根堆:
							首先记得<xx, vector<xx>, greater<xx>>
							其次, 想:如何失败(但是失败的人是最先跳出的)
						注意! 之后比较queue里面的元素的时候, 就都只能用>
							例如 
								auto nt = normal_tables.top();
				        		auto vt = vip_tables.top();
				        		if(vt > nt) 而不能用if(vt < nt)
				5. 	
					1. 因为开始打球的时间一定是 最晚(人, 桌子)
						如果桌子有空余, 所以一开始,就让桌子 == 人到来. 相当于快进到人到来的时间
						如果桌子没有空余, 就一定在排队
					2. 此时的桌子都是 等于或者晚于 人的到来
						如果是桌子 == 人
							说明有一个人来了(因为人不会同时来)
							并有一个或者多个桌子
						如果桌子 晚于 人
							说明现在由一个或者多个人在排队
						无论如何, 都至少有一个人, 不管是刚来还是多人排队
					3. 
						1. 取第一个桌子(不管是vt还是nt)
							现在肯定有一个人,或者排队
							1.
								如果第一个桌子是vt, 有一个人是vp
								就行使资本主义的assIgn(vt, vp)
							2. 不满足1的话,就是正常的想
								将第一个人,给第一台桌子(不管是什么类型的人,不管是什么桌子)
								用if(vp > np)判断第一个人是vp还是np
								用if(vt > nt)判断第一个桌子是vt还是nt(因为重载了操作符,所以时间相等,会返回编号最小的桌子)

				6. 我曾经想用vector<Table>来表示table,可是发现很麻烦
					1. 在sort(table)后, 我能得到最早的table
					2. 但是我pop()再push()进去后, 又需要sort()一次table,很麻烦
					3. 但是用priority_queue<>会自动帮我们sort
				7. 不太会出错的顺序:
					1. const xx
					2. struct 
					3. 全局变量: 可能会用到struct
					4. 函数: 可能会用到全局变量

			2. 注释
				#include <cstdio>
				#include <cstring>
				#include <iostream>
				#include <algorithm>
				#include <queue>
				#include <cmath>

				using namespace std;

				const int N = 10010, M = 110, INF = 1000000;

				int n, k, m;

				struct Person  // 球员
				{
				    int arrive_time, play_time;
				    int start_time, waiting_time;

				    bool operator< (const Person& t) const  // sort排序
				    {
				        if (start_time != t.start_time) return start_time < t.start_time;
				        return arrive_time < t.arrive_time;
				    }

				    bool operator> (const Person& t) const  // 优先队列中比较大小
				    {
				        return arrive_time > t.arrive_time;
				    }
				};

				struct Table  // 球桌
				{
				    int id;
				    int end_time;

				    bool operator> (const Table& t) const  // 优先队列中比较大小
				    {
				        if (end_time != t.end_time) return end_time > t.end_time;
				        return id > t.id;
				    }
				};

				bool is_vip_table[M];
				int table_cnt[M];

				vector<Person> persons;

				void assign(priority_queue<Person, vector<Person>, greater<Person>>& ps,
				            priority_queue<Table, vector<Table>, greater<Table>>& ts)
				{
				    auto p = ps.top(); ps.pop();
				    auto t = ts.top(); ts.pop();
				    p.waiting_time = round((t.end_time - p.arrive_time) / 60.0);
				    p.start_time = t.end_time;
				    table_cnt[t.id] ++ ;
				    persons.push_back(p);
				    ts.push({t.id, t.end_time + p.play_time});
				}

				string get_time(int secs)
				{
				    char str[20];
				    sprintf(str, "%02d:%02d:%02d", secs / 3600, secs % 3600 / 60, secs % 60);
				    return str;
				}

				int main()
				{
				    cin >> n;

				    priority_queue<Person, vector<Person>, greater<Person>> normal_persons;
				    priority_queue<Person, vector<Person>, greater<Person>> vip_persons;

				    normal_persons.push({INF});
				    vip_persons.push({INF});

				    for (int i = 0; i < n; i ++ )
				    {
				        int hour, minute, second;
				        int play_time, is_vip;
				        scanf("%d:%d:%d %d %d", &hour, &minute, &second, &play_time, &is_vip);

				        int secs = hour * 3600 + minute * 60 + second;
				        play_time = min(play_time, 120);
				        play_time *= 60;

				        if (is_vip) vip_persons.push({secs, play_time});
				        else normal_persons.push({secs, play_time});
				    }

				    priority_queue<Table, vector<Table>, greater<Table>> normal_tables;
				    priority_queue<Table, vector<Table>, greater<Table>> vip_tables;
				    normal_tables.push({-1, INF});
				    vip_tables.push({-1, INF});

				    cin >> k >> m;
				    for (int i = 0; i < m; i ++ )
				    {
				        int id;
				        cin >> id;
				        is_vip_table[id] = true;
				    }

				    for (int i = 1; i <= k; i ++ )
				        if (is_vip_table[i]) vip_tables.push({i, 8 * 3600});
				        else normal_tables.push({i, 8 * 3600});

				    while (normal_persons.size() > 1 || vip_persons.size() > 1)
				    {
				        auto np = normal_persons.top();
				        auto vp = vip_persons.top();
				        int arrive_time = min(np.arrive_time, vp.arrive_time);

				        while (normal_tables.top().end_time < arrive_time)  // O(klogk)
				        {
				            auto t = normal_tables.top();
				            normal_tables.pop();
				            t.end_time = arrive_time;
				            normal_tables.push(t);
				        }
				        while (vip_tables.top().end_time < arrive_time)
				        {
				            auto t = vip_tables.top();
				            vip_tables.pop();
				            t.end_time = arrive_time;
				            vip_tables.push(t);
				        }

				        auto nt = normal_tables.top();
				        auto vt = vip_tables.top();
				        int end_time = min(nt.end_time, vt.end_time);

				        if (end_time >= 21 * 3600) break;

				        if (vp.arrive_time <= end_time && vt.end_time == end_time) assign(vip_persons, vip_tables);
				        else if (np.arrive_time < vp.arrive_time)
				        {
				            if (nt > vt) assign(normal_persons, vip_tables); 因为table只重载了大于号, 所以只能用 > 
				            else assign(normal_persons, normal_tables);
				        }
				        else
				        {
				            if (nt > vt) assign(vip_persons, vip_tables);
				            else assign(vip_persons, normal_tables);
				        }
				    }

				    sort(persons.begin(), persons.end());

				    for (auto person : persons)
				    {
				        cout << get_time(person.arrive_time) << ' ' << get_time(person.start_time) << ' ';
				        cout << person.waiting_time << endl;
				    }

				    cout << table_cnt[1];
				    for (int i = 2; i <= k; i ++ ) cout << ' ' << table_cnt[i];
				    cout << endl;
				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/262962/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.

					#include <iostream>
					#include <queue>
					#include <algorithm>
					#include <cmath>
					#include <vector>
					#include <cstdio>

					using namespace std;

					const int N = 110, INF = 1000000;

					struct Player{
						int abs_seconds;
						int duration;
						int start_time;
						int wait_time;
						string formated_arrive_time;
						string formated_start_time;

						bool operator< (const Player& t) const{
							if(start_time != t.start_time) return start_time < t.start_time;
							return abs_seconds < t.abs_seconds;
						}

						bool operator> (const Player& t) const{
							return abs_seconds > t.abs_seconds;
						}
					};

					struct Table{
						int id;
						int serve_time;
						//int cnt;

						bool operator> (const Table& t) const{
							if(serve_time != t.serve_time) return serve_time > t.serve_time;
							return id > t.id;
						}
					};

					priority_queue<Player, vector<Player>, greater<Player>> normal_players;
					priority_queue<Player, vector<Player>, greater<Player>> vip_players;

					priority_queue<Table, vector<Table>, greater<Table>> normal_tables;
					priority_queue<Table, vector<Table>, greater<Table>> vip_tables;

					bool is_vip_table[N];
					int cnt[N];

					string formated(int time){
						char res[20];
						int hour = time / 3600;
						int minutes = time / 60 - hour * 60;
						int seconds = time % 60;
						sprintf(res, "%02d:%02d:%02d", hour, minutes, seconds);
						return res;
					}

					vector<Player> res;
					void assign(priority_queue<Player, vector<Player>, greater<Player>> &ps, priority_queue<Table, vector<Table>, greater<Table>> &ts){
						auto p = ps.top();
						ps.pop();
						auto t = ts.top();
						ts.pop();

						p.start_time = max(t.serve_time, p.abs_seconds);
						p.wait_time = p.start_time - p.abs_seconds;
					// 	cout <<"hi " << p.wait_time << endl; 
						p.formated_arrive_time = formated(p.abs_seconds);
						p.formated_start_time = formated(p.start_time);
						res.push_back(p);

						int end_time = p.start_time + p.duration;
						t.serve_time = end_time;
						cnt[t.id] ++;
						ts.push(t);
					}

					int main(){


						int n;
						cin >> n;

						int hour, minutes, seconds, duration, vip;
						int abs_seconds;
						for(int i = 0; i < n ; i++){
							scanf("%d:%d:%d %d %d", &hour, &minutes, &seconds, &duration, &vip);
							abs_seconds = hour * 3600 + minutes * 60 + seconds;
							duration = min(120, duration) * 60;
							if(vip) vip_players.push({abs_seconds, duration});
							else normal_players.push({abs_seconds, duration});
						}

						int k, v;
						cin >> k >> v;
						for(int i = 0 ; i < v; i++) {
							int id;
							cin >> id; //编号从1开始
							is_vip_table[id] = true;
						}

						for(int i = 1; i <= k; i++){ //从int i == 1开始
							if(is_vip_table[i]) vip_tables.push({i, 8 * 3600});
							else normal_tables.push({i, 8 * 3600});
						}

						// 类似于 start_time = max(earliest_windows, earliest_people);
						// 不过这里有两种people, 两种windows
						// 所以选出两种people里面的最早的人, 以及*所有的*早于这个人的windows

						normal_players.push({INF}); 
						vip_players.push({INF});
						normal_tables.push({-1, INF});
						vip_tables.push({-1, INF});
						
						int xx = 0;

						while(normal_players.size() > 1 || vip_players.size() > 1){

					        // cout << normal_players.size() << " " << vip_players.size() << endl;
							//因为无法确保是否vip_player和normal_player一定有top(), 所以添加哨兵.
							auto vp = vip_players.top();
							auto np = normal_players.top();
							int earliest_people_time = min(vp.abs_seconds, np.abs_seconds);

							//因为无法确保是否vip_table和normal_table一定有top(), 所以添加哨兵.
							//因为如果size == 0, 但是要输出top()的话会segmentation fault.
							while(normal_tables.top().serve_time < earliest_people_time){
								auto t = normal_tables.top();
								normal_tables.pop();
								t.serve_time = earliest_people_time;
								normal_tables.push(t);
							}

							while(vip_tables.top().serve_time < earliest_people_time){
								auto t = vip_tables.top();
								vip_tables.pop();
								t.serve_time = earliest_people_time;
								vip_tables.push(t);
							}
							
					// 		if()
					        
					        // if(++xx > 3)
					        //     exit(0);
							// 选出最早的桌子
							auto nt = normal_tables.top();
							auto vt = vip_tables.top();
							int earliest_serve_time = min(nt.serve_time, vt.serve_time);
							
					// 		cout << earliest_serve_time << " i" << endl;
							if(earliest_serve_time >= 21*3600) break;

							// 选出最早的人
					// 		auto np = normal_players.top();
					// 		auto vp = vip_players.top();

							// 先判断特例: VIP人和vip桌同时存在: vip是在队伍中(可能是第一个也可能是队伍中间),并且有vip桌
							if(vt.serve_time == earliest_serve_time && vp.abs_seconds <= earliest_serve_time){
								assign(vip_players, vip_tables);
							}
							else{
								if(vp > np){
									if(vt > nt){
										assign(normal_players, normal_tables);
									}
									else{
										assign(normal_players, vip_tables);
									}
								}
								else{
									if(vt > nt){
										assign(vip_players, normal_tables);
									}
									else{
										assign(vip_players, vip_tables);
									}
								}
							}
							
							
						}
						
					// 	exit(0);
					    sort(res.begin(), res.end());

						for(auto &p : res){
						   //cout << " --" << round(p.wait_time / 60.0) << endl;
							printf("%s %s %.0lf\n", p.formated_arrive_time.c_str(), p.formated_start_time.c_str(), round(p.wait_time / 60.0));
						}

						printf("%d", cnt[1]);
						for(int i = 2; i <= k; i ++){
							printf(" %d", cnt[i]);
						}

						cout << endl;
						return 0;

					}
				r2. 有bug, sf
					#include <iostream>
					#include <queue>
					#include <vector>
					#include <cmath>
					#include <algorithm>

					using namespace std;

					const int N = 110;
					const int INF = 1000000;

					struct Person{
						int arrive;
						int play;
						int start;
						double wait;
						string formated_arrive;
						string formated_start;

						bool operator> (const Person& t) const{
							return arrive > t.arrive;
						}

						bool operator< (const Person& t) const{
							if(start != t.start) return start < t.start;
							return arrive < t.arrive;
						}
					};

					struct Table{
						int id;
						int serve;
						int cnt;

						bool operator> (const Table& t) const{
							if(serve != t.serve) return serve > t.serve;
							return id > t.id;
						}
					};

					priority_queue<Person, vector<Person>, greater<Person>> normal_person;
					priority_queue<Person, vector<Person>, greater<Person>> vip_person;

					priority_queue<Table, vector<Table>, greater<Table>> normal_table;
					priority_queue<Table, vector<Table>, greater<Table>> vip_table;

					bool is_vip_table[N];
					int cnt_table[N];


					string formated(int time){
						char res[20];
						int hour = time / 3600;
						int minutes = time % 3600 / 60;
						int seconds = time % 60;
						sprintf(res, "%02d:%02d%02d", hour, minutes, seconds);
						return res;
					}
					vector<Person> res;
					void assign(priority_queue<Person, vector<Person>, greater<Person>> &ps, 
						priority_queue<Table, vector<Table>, greater<Table>> &ts){
						auto p = ps.top(); ps.pop();
						auto t = ts.top(); ts.pop();

						int start = max(p.arrive, t.serve);
						int wait = start - p.arrive;
						p.start = start;
						p.wait = (double)round(wait / 60);
						p.formated_start = formated(start);
						p.formated_arrive = formated(p.arrive);
						res.push_back(p);

						int new_serve = start + p.play;
						t.serve = new_serve;
						cnt_table[t.id]++;
						ts.push(t);
					}

					int main(){

						int n; 
						cin >> n;

						int hour, minutes, seconds, duration, vip;
						int arrive;
						for(int i = 0; i < n ; i ++){
							scanf("%d:%d:%d %d %d", &hour, &minutes, &seconds, &duration, &vip);

							arrive = hour * 3600 + minutes * 60 + seconds;
							duration = min(120, duration) * 60;

							if(vip) vip_person.push({arrive, duration});
							else normal_person.push({arrive, duration});
						}
					    
						int k, m;
						cin >> k >> m;
						int id;
						for(int i = 0; i < m; i++){
							cin >> id;
							is_vip_table[id] = true;
						}

						for(int i = 1; i <= k; i++){
							if(is_vip_table[i]) vip_table.push({i, 8 * 3600, 0});
							else normal_table.push({i, 8 * 3600, 0});
						}

						vip_person.push({INF}); normal_person.push({INF});
						vip_table.push({INF}); normal_table.push({INF});

					    int xx = 0;
						while(vip_person.size() >= 2 || normal_person.size() >= 2){
						    if(++xx > 3) exit(0); 
						   
							auto vp = vip_person.top();
							auto np = normal_person.top();
							int first_arrive_time = min(vp.arrive, np.arrive);
					        cout << vp.arrive << " hi " <<np.arrive << endl;
							while(vip_table.top().serve < first_arrive_time){
								auto vt = vip_table.top(); vip_table.pop();
								vt.serve = first_arrive_time, vip_table.push(vt);
							}

							while(normal_table.top().serve < first_arrive_time){
								auto nt = normal_table.top(); normal_table.pop();
								nt.serve = first_arrive_time, normal_table.push(nt);
							}
					        
							auto vt = vip_table.top(), nt = normal_table.top();
							int first_serve_time = min(vt.serve, nt.serve);
							if(first_serve_time >= 21 * 3600) break;

							if(vt.serve == first_serve_time && vp.arrive <= first_serve_time){
								assign(vip_person, vip_table);
							}
							else{
								if(np > vp){
									if(vt > nt) assign(vip_person, normal_table);
									else assign(vip_person, vip_table);
								}
								else{
									if(vt > nt) assign(normal_person, normal_table);
									else assign(normal_person, vip_table);
								}
							}
							//exit(0);
							 cout << vip_person.size() << " " <<  normal_person.size() << endl;
						}

						sort(res.begin(), res.end());
						for(int i = 0; i < n; i ++){
							auto p = res[i];
							printf("%s %s %.0lf\n", p.formated_arrive.c_str(), p.formated_start.c_str(), p.wait);
						}

						printf("%d", cnt_table[1]);
						for(int i = 2; i <= k; i++){
							printf("%d ", cnt_table[i]);
						}

						cout << endl;
						return 0;


					}
				r3. 依旧sf..
					#include <iostream>
					#include <queue>
					#include <vector>
					#include <cmath>
					#include <algorithm>

					using namespace std;

					const int N = 110;
					const int INF = 1000000;

					struct Person{
						int arrive;
						int play;
						int start;
						int wait;
						string f_arrive;
						string f_start;

						bool operator> (const Person& t) const{
							return arrive > t.arrive;
						}

						bool operator< (const Person& t) const{
							if(start != t.start) return start < t.start;
							return arrive < t.arrive;
						}
					};

					struct Table{
						int id;
						int serve;

						bool operator> (const Table& t) const{
							if(serve != t.serve) return serve > t.serve;
							return id > t.id;
						}
					};



					bool is_vip_table[N];
					int cnt[N];

					vector<Person> res;

					string f(int time){
						char res[20];
						int h = time / 3600;
						int m = time % 3600 / 60;
						int s = time % 60;
						sprintf(res, "%02d:%02d:%02d", h, m, s);
						return res;
					}

					void assign(priority_queue<Person, vector<Person>, greater<Person>> &ps, priority_queue<Table, vector<Table>, greater<Table>> &ts){
					    auto p = ps.top(); ps.pop();
					    auto t = ts.top(); ts.pop();
					    p.wait = round((t.serve - p.arrive) / 60.0);
					    p.start = t.serve;
					    cnt[t.id] ++ ;
					    res.push_back(p);
					    ts.push({t.id, t.serve + p.play});
					}


					int main(){
					    
					    priority_queue<Person, vector<Person>, greater<Person>> vip_person;
					    priority_queue<Person, vector<Person>, greater<Person>> normal_person;
					    
					    priority_queue<Table, vector<Table>, greater<Table>> vip_table;
					    priority_queue<Table, vector<Table>, greater<Table>> normal_table;
					    
					    vip_person.push({INF});
						normal_person.push({INF});
						vip_table.push({-1, INF});
						normal_table.push({-1, INF});
						int n;
						cin >> n;
						int hour, minutes, seconds, play, vip;
						int arrive;
						for(int i = 0; i < n; i ++){
							scanf("%d:%d:%d %d %d", &hour, &minutes, &seconds, &play, &vip);
							arrive = hour * 3600 + minutes * 60 + seconds;
							play = min(120, play) * 60;

							if(vip) vip_person.push({arrive, play});
							else normal_person.push({arrive, play});
						}

						int k, m;
						cin >> k >> m;
						for(int i = 0; i < m; i++){
							int id;
							cin >> id;
							is_vip_table[id] = true;
						}

						for(int i = 1; i <= k; i++){
							if(is_vip_table[i]) vip_table.push({i, 8 * 3600});
							else normal_table.push({i, 8 * 3600});
						}


					    int xx = 0;
						while(vip_person.size() > 1 || normal_person.size() > 1){
						    
						    if(++xx > 4) exit(0);
						    cout << vip_person.size() << " hi " << normal_person.size() << endl;
							auto vp = vip_person.top();
							auto np = normal_person.top();
							int first_arrive_time = min(vp.arrive, np.arrive);

							while(vip_table.top().serve < first_arrive_time){
								auto vt = vip_table.top();
								vip_table.pop();
								vt.serve = first_arrive_time;
								vip_table.push(vt);
							}

							while(normal_table.top().serve < first_arrive_time){
								auto nt = normal_table.top();
								normal_table.pop();
								nt.serve = first_arrive_time;
								normal_table.push(nt);
							}

							auto vt = vip_table.top();
							auto nt = normal_table.top();
							int first_serve_time = min(vt.serve, nt.serve);

							if(first_serve_time >= 21*3600) break;
							if(first_serve_time == vt.serve && vp.arrive <= first_serve_time){
								assign(vip_person, vip_table);
							}
							else{
								if(np > vp){
									if(vt > nt) assign(vip_person, normal_table);
									else assign(vip_person, vip_table);
								}
								else{
									if(vt > nt) assign(normal_person, normal_table);
									else assign(normal_person, vip_table);
								}
							}
						}

						sort(res.begin(), res.end());

						for(int i = 0; i < n; i++){
							auto p = res[i];
							printf("%s %s %d\n", p.f_arrive.c_str(), p.f_start.c_str(), p.wait);
						}

						cout << cnt[1];
						for(int i = 2; i < k; i++)
						{
							cout << " " << cnt[i];
						}

						cout << endl;
						return 0;
					}

				r4.
				r5.

	3. 2020年10月1日13:26:24
		12. 1546. 它们是否相等	1060
			0. bug
			1. 笔记
				0. 题目要求的:
					1. 关于幂次
						总结:
							找到'.'的前面,不包括'.',有a个数字
							找到删除'.'之后的string,有b个前置零
							k = a - b;
						形式是0.xxx * 10^ yyy
						可能的input有
							1. 1234
							2. 1234.
							3. 0.0001234
							4. 0000.001234
							5. 123.1234
						我们的目标:
							让小数点的后一位变成非零的数字,也就是结果是:
							1. 1234 -> 0.1234 * 10^4
								因为没有'.',所以我们会在最后加上'.'
								找到这个点的ind, k = 4在ind == 4的位置上
								看没有'.'的时候长什么样: '1234'
								去除前导0,每次除一个k--. 这里没有k--
								所以 k == 4
							2. 1234. -> 0.1234 * 10^4
								找到这个点的ind, k = 4在ind == 4的位置上
								看没有'.'的时候长什么样: '1234'
								去除前导0,每次除一个k--. 这里没有k--
								所以 k == 4
							3. 0.0001234 -> 0.1234 * 10^(-3)
								找到这个点的ind, k = 1在ind == 1的位置上
								看没有'.'的时候长什么样: '00001234'
								去除前导0,每次除一个k--. 祛除了4次,所以1-4=-3
								所以 k == -3
							4. 0000.001234 -> 0.1234 * 10^(-2)
								找到这个点的ind, k = 4在ind == 4的位置上
								看没有'.'的时候长什么样: '0000001234'
								去除前导0,每次除一个k--. 祛除了6次,所以4-6=-2
								所以 k == -2
							5. 123.1234 -> 0.1231234 * 10^3
								找到这个点的ind, k = 3在ind == 3的位置上
								看没有'.'的时候长什么样: '1231234'
								去除前导0,每次除一个k--.这里没有k--
								所以 k == 3
					2. 关于保留n位
						如果不足n位,就补足'0'
							a += string(n - a.size(), '0'); 
						如果超过n位, 就删除后面的
							 s = s.substr(0, n);


				1. string
					-1 总结:
						取k前面的: a.substr(0, k)
						取k+1和后面的: a.substr(k)
					0. 找:
						int k = a.find('.');
						说明在'.'之前,不包括'.',有k个元素
					1. 删
						1. 删除第一个char:
							a = a.substr(1);
						2. 删除后面的char, 直到a.size() == n;
							a = a.sustr(0, n);
						3. 删除第k个char
							a = a.substr(0, k) + a.substr(k+1);
								也就是0到k-1, 和k+1之后的
					2. 加
						1. 往后面加入一个char
							a += '0';
						2. 往后面补充0, 补充到整个string长度为n, 假设现在string.size() < n
							a += string(n - a.size(), '0'); 
								string(len, 'c');
					3. 可以直接return "0." + s + "*10^" + to_string(k);
						而不采用sprintf()
					
			2. 注释
				#include <iostream>
				#include <cstring>

				using namespace std;

				string change(string a, int n)
				{
				    int k = a.find(".");
				    if (k == -1) a += '.', k = a.find(".");

				    string s = a.substr(0, k) + a.substr(k + 1);
				    while (s.size() && s[0] == '0') s = s.substr(1), k -- ;

				    if (s.empty()) k = 0;
				    if (s.size() > n) s = s.substr(0, n);
				    else s += string(n - s.size(), '0');

				    return "0." + s + "*10^" + to_string(k);
				}

				int main()
				{
				    int n;
				    string a, b;
				    cin >> n >> a >> b;

				    a = change(a, n);
				    b = change(b, n);

				    if (a == b) cout << "YES " << a << endl;
				    else cout << "NO " << a << ' ' << b << endl;

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/317838/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					using namespace std;

					string change(int n, string a){

						char res[110];
						int k = a.find('.');
						if(k == -1) a += '.'; k = a.find('.');
						a = a.substr(0, k) + a.substr(k + 1);
						
						while(a.size() && a[0] == '0') a = a.substr(1), k--;
						if(a.empty()) k = 0;
						while(a.size() < n) a += '0';
						if(a.size() > n) a = a.substr(0, n);
						sprintf(res, "0.%s*10^%d", a.c_str(), k);
						
						return res;
					}

					int main(){
						int n;
						string a, b;
						cin >> n >> a >> b;

						string ac = change(n, a);
						string bc = change(n, b);

						if(ac == bc) cout << "YES " << ac << endl;
						else cout << "NO " << ac << " " << bc << endl;

						return 0;
					}
				r2.
					#include <iostream>

					using namespace std;

					string change(int n , string a){
						int k = a.find('.');
						if(k == -1) a += '.', k = a.find('.');

						string s = a.substr(0, k) + a.substr(k+1);
						while(s.size() && s[0] == '0') s = s.substr(1), k--;
						if(s.empty()) k = 0;

						if(s.size() > n) s = s.substr(0, n);
						else s += string(n - s.size(), '0');

						return "0." + s + "*10^" + to_string(k);
					}

					int main(){
						int n;
						string a, b;
						cin >> n >> a >> b;

						string x = change(n, a);
						string y = change(n, b);

						if(x == y) cout <<"YES " << x << endl;
						else cout << "NO " << x << " " << y << endl;
						return 0;
					}
				r3.
					#include <iostream>

					using namespace std;

					string change(int n, string a){
						int k = a.find('.');
						if(k == -1) a += '.', k = a.find('.');

						a = a.substr(0, k) + a.substr(k+1);
						while(a.size() && a[0] == '0') a = a.substr(1), k--;
						if(a.empty()) k = 0;

						if(a.size() > n) a = a.substr(0, n);
						else a += string(n - a.size(), '0');

						return "0." + a + "*10^" + to_string(k);

					}

					int main(){
						int n;
						string a, b;
						cin >> n >> a >> b;

						a = change(n, a);
						b = change(n, b);

						if(a == b) cout << "YES " << a << endl;
						else cout << "NO " << a << " " << b << endl;

						return 0;
					}
				r4.
					#include <iostream>

					using namespace std;

					string change(int n, string a){
						int k = a.find('.');
						if(k == -1) a += '.', k = a.find('.');

						a = a.substr(0, k) + a.substr(k + 1);
						while(a.size() && a[0] == '0') a = a.substr(1), k--;
						if(a.empty()) k = 0;

						if(a.size() > n) a = a.substr(0, n);
						else a += string(n - a.size(), '0');

						return "0." + a + "*10^" + to_string(k);
					}

					int main(){
						int n;
						string a, b;
						cin >> n >> a >> b;

						a = change(n, a);
						b = change(n, b);

						if(a == b) cout << "YES " << a << endl;
						else cout << "NO " << a << " " << b << endl;
						return 0;
					}
				r5.
					#include <iostream>

					using namespace std;

					string change(int n, string a){
						int k = a.find('.');
						if(k == -1) a += '.'; k = a.find('.');

						a = a.substr(0, k) + a.substr(k+1);
						while(a.size() && a[0] == '0') a = a.substr(1), k--;
						if(a.empty()) k = 0;

						if(a.size() > n) a = a.substr(0, n);
						else a += string(n - a.size(), '0');

						return "0." + a + "*10^" + to_string(k);
					}

					int main(){
						int n;
						string a, b;
						cin >> n >> a >> b;

						a = change(n, a);
						b = change(n, b);

						if(a == b) cout << "YES " << a << endl;
						else cout << "NO " << a << " " << b << endl;
						return 0;
					}

		13. 1559. 科学计数法	1073
			0. bug
			1. 笔记
				0. 回忆:
					 int to string: to_string()
					 string to int: stoi()
					 可以cout << 'c' + "string" << endl;	就是char和string加法
				1. 其实非常简单
					1. 举例: +1.23400E-03
						0. 过程:
							将1.23400*10^(-3)想象成0.123400 * 10^(-2)
							取中间部分,去除'.'
								123400
							同时幂次+1
								-3 + 1 = -2
						1. 我们需要提取'E'之前和之后的部分:
							1.23400
								需要将'.'去除
									 a = s[1] + s.substr(3, k - 3);
									 因为ind == 0: +/-
									 ind == 1: 一位数字
									 ind == 2: '.'
									 ind == 3: 剩余的始祖
							-03
								int b = stoi(s.substr(k + 1));
								用stoi()读取
								之后幂次++, b++;
						2. 如果
							1. 幂次b <= 0, 说明我们要在'0.' 和 '123400'之间添加b个'0' (string(-b, '0')), 如果b==0, string(0,'0')也就不会加'0';
							2. 幂次b > 0,
								1. 如果b >= a.size()
									说明我们要在'1234000' 后面加上 b-a.size()个'0'. (b-a.size()可以==0,也就是不加'0')
								2. 如果b < a.size()
									说明要加小数点,也就是先取[0,b-1]共b个的字符, 然后加上'.',之后加上[b-N]的字符
									 a = a.substr(0, b) + '.' + a.substr(b);
			2. 注释
				#include <iostream>

				using namespace std;

				int main()
				{
				    string s;
				    cin >> s;

				    if (s[0] == '-') cout << '-';

				    int k = s.find("E");
				    string a = s[1] + s.substr(3, k - 3);
				    int b = stoi(s.substr(k + 1));
				    b ++ ;

				    if (b <= 0) a = "0." + string(-b, '0') + a;
				    else if (b >= a.size()) a += string(b - a.size(), '0');
				    else a = a.substr(0, b) + '.' + a.substr(b);

				    cout << a << endl;

				    return 0;
				}


				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/317851/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					int main(){
						string num;
						cin >> num;

						if(num[0] == '-') cout << '-';
						int k = num.find('E');
						string a = num[1] + num.substr(3, k-3);
						int b = stoi(num.substr(k+1));
						b++;

						if(b <= 0)
							cout << "0." + string(-b, '0') + a << endl;
						else{
							if(b >= a.size()) cout << a + string(b - a.size(), '0');
							else cout << a.substr(0, b) + '.' + a.substr(b);
						}

						return 0;


					}
				r2.
					#include <iostream>

					using namespace std;

					int main(){
						string num;
						cin >> num;

						int k = num.find('E');
						string a = num[1] + num.substr(3, k-3);
						int b = stoi(num.substr(k+1)) + 1;

						if(num[0] == '-') cout << '-';
						if(b <= 0) cout << "0." + string(-b, '0') + a << endl;
						else {
							if(b < a.size()) cout << a.substr(0, b) + '.' + a.substr(b) << endl;
							else cout << a + string(b-a.size(), '0') << endl;
						}

						return 0;
					}
				r3.
					#include <iostream>

					using namespace std;

					int main(){
						string num;
						cin >> num;

						int k = num.find('E');
						string a = num[1] + num.substr(3, k - 3);
						int b = stoi(num.substr(k+1)) + 1;

						if(num[0] == '-') cout << '-';
						if(b <= 0) cout << "0." + string(-b, '0') + a << endl;
						else{
							if(b < a.size()) cout << a.substr(0, b) + '.' + a.substr(b) << endl;
							else{
								cout << a + string(b-a.size(), '0') << endl;
							}
						} 

						return 0;
					}
				r4.
					#include <iostream>

					using namespace std;

					int main(){
						string num;
						cin >> num;

						int k = num.find('E');
						string a = num[1] + num.substr(3, k-3);
						int b = stoi(num.substr(k+1)) + 1;

						if(num[0] == '-') cout << '-';
						if(b <= 0) cout << "0." + string(-b, '0') + a << endl;
						else{
							if(b < a.size()) cout << a.substr(0, b) + '.' + a.substr(b) << endl;
							else cout << a + string(b-a.size(), '0') << endl;
						}

						return 0;
					}
				r5.

		14. 1563. Kuchiguse	1077
			0. bug
				用getline(cin, s[i]);之前,记得getchar();
			1. 笔记
				1. 其实要找的是最长后缀,思路很简单
					就是直接看每个string的后k个字符是否一样
						比较的时候:
							1. 确认target的长度是 > k的,否则就不可能取target的后k个字符
							2. target的后k个字符 == 这k个字符
					后k个,k是从大到小排列的
				2. 因为题目的string长度最长是256, 一共只有100个string
					假设最坏情况,判断了256次的k,(k从256到1),每次判断100个string
					一共就256*100=2w
				3. string
					取最后a个char
					string str = xx.substr(xx.size() - a);
				4. 这道题的两个for loop里面的逻辑还是很有意思的
					1. 内loop:
						如果一旦发现不对劲, 设置is = false, break; 继续到外loop, 就是看下一个更短的k长度
						如果很顺利,也是直接到外loop
					2. 外loop: 
						先检查is
							如果是true, 就return(相当于break) 找到答案
							如果是false, 继续外loop, 就是看下一个更短的k长度
					3. 最后出来的肯定是全部都是false
			2. 注释
				#include <iostream>
				using namespace std;

				const int N = 110;

				int n;
				string s[N];

				int main()
				{
				    cin >> n;
				    getchar();
				    for (int i = 0; i < n; i ++ ) getline(cin, s[i]);

				    for (int k = s[0].size(); k; k -- )
				    {
				        string sf = s[0].substr(s[0].size() - k);
				        bool is_matched = true;

				        for (int i = 1; i < n; i ++ )
				            if (k > s[i].size() || s[i].substr(s[i].size() - k) != sf)
				            {
				                is_matched = false;
				                break;
				            }

				        if (is_matched)
				        {
				            cout << sf << endl;
				            return 0;
				        }
				    }

				    puts("nai");

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/317855/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					int main(){
						int n;
						cin >> n;
						string s[n];
						getchar();
						for(int i = 0; i < n; i++)
						{
							getline(cin, s[i]);
						}

						int k;
						bool is_k = true;
						for(k = s[0].size(); k; k--){
							string comp = s[0].substr(s[0].size() - k);
					// 		cout << comp << endl;
							is_k = true;
							for(int i = 1; i < n ; i++){
								if(s[i].size() - k < 0){
									is_k = false;
									break;
								}
								
								string target = s[i].substr(s[i].size() - k);
					// 			cout << target << endl;
								if(target != comp)
								{
									is_k = false;
									break;
								}
							}
							if(is_k){
							    cout << comp << endl;
							    break;
							}
						}

						if(!is_k) cout << "nai" << endl;
						
						return 0;
					}
				r2.
					#include <iostream>

					using namespace std;

					const int N = 110;
					int n;
					string s[N];

					int main(){
						cin >> n;
						getchar();
						for(int i = 0; i < n; i++){
							getline(cin, s[i]);
						}

						for(int i = s[0].size(); i > 0; i--){
							string cmp = s[0].substr(s[0].size() - i);
					// 		cout << cmp << endl;

							bool is_k = true;
							for(int j = 1; j < n ; j++){
								if(i > s[j].size() || s[j].substr(s[j].size() - i) != cmp) {
								 //   cout << cmp << " " <<  s[j].substr(s[j].size() - i) << endl;
									is_k = false;
									break;
								}
							}
							if(is_k) {
								cout << cmp << endl;
								return 0;
							}
						}
						puts("nai");
						return 0;
					}
				r3.
					#include <iostream>
					using namespace std;

					const int N = 110;
					int n;
					string str[N];

					int main(){
						cin >> n;
						getchar();
						for(int i = 0; i < n ; i++){
							getline(cin, str[i]);
						}

						for(int k = str[0].size(); k > 0 ; k--){
							string comp = str[0].substr(str[0].size() - k);

							bool is = true;
							for(int i = 1; i < n; i++){
								if( k > str[i].size() || str[i].substr(str[i].size() - k) != comp)
								{
									is = false;
									break;
								}
							}
							if(is){
								cout << comp << endl;
								return 0;
							}
						}

						puts("nai");
						return 0;
					}
				r4. 新方法, 记录minlen
					#include <iostream>

					using namespace std;

					const int N = 110;
					int n;
					string str[N];

					int main(){
						cin >> n;
						getchar();
						int minlen = 300;
						for(int i = 0; i < n; i++){
							getline(cin, str[i]);
							minlen = str[i].size() < minlen ? str[i].size() : minlen;
						}

						for(int i = minlen; i > 0; i--){
							string comp = str[0].substr(str[0].size() - i);

							bool is_k = true;
							for(int j = 1; j < n; j++){
								if(str[j].substr(str[j].size() - i) != comp){
									is_k = false;
									break;
								}
							}
							if(is_k){
								cout << comp << endl;
								return 0;
							}
						}

						puts("nai");
						return 0;


					}
				r5.
					#include <iostream>
					using namespace std;

					const int N = 110;

					int n;
					string str[N];

					int main(){
						cin >> n;
						getchar();
						int minlen = 300;
						for(int i = 0; i < n; i++){
							getline(cin, str[i]);
							minlen = min((int)str[i].size(), minlen);
						}

						for(int i = minlen; i > 0; i--){
							string comp = str[0].substr(str[0].size() - i);

							bool is_k = true;
							for(int j = 1; j < n; j++){
								if(str[j].substr(str[j].size() - i) != comp){
									is_k = false;
									break;
								}
							}
							if(is_k) {
								cout << comp << endl;
								return 0;
							}
						}

						puts("nai");
						return 0;
					}

		15. 1568. 中文读数字	1082 #todo
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		16. 1570. 坏掉的键盘	1084
			0. bug
			1. 笔记
				1. 因为字母和ascci码只有127个, 所以用len == 200的数组来当做set
				2. 两个指针(像这种,要保持两个指针都合法的,可以考虑加哨兵)
					第一个指针, 也就是我们想输入的string, 是不停的i++
					第二个指针, 也就是实际输出的string, 是遇到==才会j++
				3. 担心数组越界,所以会加一个哨兵
					为什么会越界, 因为实际输出的string b一定是 <= 想输入的string a的长度
					所以我们很有可能 b已经遍历到最后一位了,但是a还有
					所以:
						1. 可以给b加一个末尾: b += '#'
						2. 在j++的时候判断: if(x == y && j + 1 < b.size()) 但是这样的话, 我们的y就一直是b的最后一个char,可能会出问题
						所以最好是家哨兵.
			2. 注释
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					int main(){
						string a, b;
						cin >> a >> b;

						b += '#';
						int visited[200] = {0}; //因为字母和ascci码只有127个
						for(int i = 0, j = 0; i < a.size(); i++){
							char x = toupper(a[i]), y = toupper(b[j]);
							if(x == y ) j++;
							else{
								if(!visited[x]){
									cout << x;
									visited[x] = 1;
								}
							}
						}

						cout << endl;
						return 0;
					}
				r2.
					#include <iostream>

					using namespace std;

					int main(){
						string a,b;
						cin >> a >> b;

						b += '#';
						int visited[200] = {0};
						for(int i = 0, j = 0; i < a.size(); i++){
							char target = toupper(a[i]);
							char act = toupper(b[j]);
							if(target == act) j++;
							else{
								if(!visited[target]){
									cout << target;
									visited[target] = 1;
								}
							}
						}

						cout << endl;
						return 0;
					}
				r3.
					#include <iostream>

					using namespace std;

					int main(){
						string a,b;
						cin >> a >> b;

						b += '#';
						int v[200] = {0};
						for(int i = 0, j = 0; i < a.size(); i ++){
							char x = toupper(a[i]);
							char y = toupper(b[j]);
							if(x == y) j ++;
							else{
								if(!v[x]) {
									cout << x;
									v[x] = 1;
								}
							}
						}
						cout << endl;
						return 0;
					}
				r4.
				r5.

	4. 2020年10月2日09:08:47
		17. 1598. 求平均值	1108
			0. bug
				错误的认为: k + 1 >= 3 相当于 k >= 2 相当于 k > 3
					这根本就是错的好吗!! k >= 2是 k > 1
				同时,还有一个错的地方, 不是size - k + 1, 而是 s - k - 1
			1. 笔记
				1. 如何判断一个输入是否合法
					合法输入数字指 [−1000,1000] 范围内的精确到不超过 2 个小数位的实数。
					不合法的: aaa 9999 2.3.4 7.123
				1. stof(): 可以将string转化成float
					1. 如果是 aaa: 会报异常, 我们用try{}catch(...){} 其中catch(...)是捕捉任何异常
					2. 如果是 3.12aaa: 会只读取前面的部分, 所以我们要比较
						size_t idx;
			            double x = stof(num, &idx); idx是传出一共读取了多少个字符,相当于是浮点数x的size(包括了整数,小数和浮点)
			            if (idx < num.size()) success = false;
				2. 我们判断有几位小数:
					int k = num.find('.');
        			if (k != -1 && num.size() - k - 1 >= 3) success = false;
        			  k   s
        			  |   |
        			 2.123  所以中间的123的个数是 s - k - 1,因为是(k,s),而不是[k,s)
			2. 注释
				#include <iostream>

				using namespace std;

				int main()
				{
				    int n;

				    cin >> n;

				    int cnt = 0;
				    double sum = 0;

				    while (n -- )
				    {
				        string num;
				        cin >> num;
				        double x;

				        bool success = true;
				        try
				        {
				            size_t idx;
				            x = stof(num, &idx);

				            if (idx < num.size()) success = false;
				        }
				        catch(...)
				        {
				            success = false;
				        }

				        if (x < -1000 || x > 1000) success = false;
				        int k = num.find('.');
				        if (k != -1 && num.size() - k > 3) success = false;

				        if (success) cnt ++, sum += x;
				        else printf("ERROR: %s is not a legal number\n", num.c_str());
				    }

				    if (cnt > 1) printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
				    else if (cnt == 1) printf("The average of 1 number is %.2lf\n", sum);
				    else puts("The average of 0 numbers is Undefined");

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/323460/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					using namespace std;

					int main(){
						int n;
						cin >> n;

						int cnt = 0;
						double sum = 0.0;
						string a;
						for(int i = 0; i < n; i++){
							cin >> a;
							double x = 0.0;

							bool success = true;
							try{
								size_t ind;
								x = stof(a, &ind);
								if(ind < a.size()) success = false;
							}
							catch(...){
								success = false;
							}

							if(x < -1000 || x > 1000) success = false;
							int k = a.find('.');
							if(k != -1 && a.size() - k - 1 >= 3) success = false;
							if(!success){
								printf("ERROR: %s is not a legal number\n", a.c_str());
							}
							else{
								cnt ++;
								sum += x;
							}
						}

						if(cnt == 0) puts("The average of 0 numbers is Undefined");
						else if (cnt == 1) printf("The average of 1 number is %.2lf", sum);
						else printf("The average of %d numbers is %.2lf", cnt, sum / cnt);

						return 0;
					}


				r2.
					#include <iostream>

					using namespace std;

					int main(){
						int n;
						cin >> n;
						string a;
						double b;
						bool success;
						double sum;
						int cnt;
						for(int i = 0; i < n; i++){
							cin >> a;
							success = true;
							b = 0.0;
							try{
								size_t ind;
								b = stof(a, &ind);
								if(ind < a.size()) success = false;
							}
							catch(...){
								success = false;
							}

							if(b < -1000 || b > 1000) success = false;
							int k = a.find('.');
							if(k != -1 && a.size() - k - 1 >= 3) success = false;
							if(!success) printf("ERROR: %s is not a legal number\n", a.c_str());
							else{
								sum += b;
								cnt ++;
							}
						}

						if(cnt == 0) puts("The average of 0 numbers is Undefined");
						else if(cnt == 1) printf("The average of 1 number is %.2lf\n", sum);
						else printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);

						return 0;


					}
				r3.
					#include <iostream>

					using namespace std;

					bool check(string a, double &b){
						b = 9999.;
						try{
							size_t ind;
							b = stof(a, &ind);
							if(ind != a.size()) return false;
						}
						catch(...){
							return false;
						}
						if(b < -1000 || b > 1000) return false;
						int k = a.find('.');
						if(k != -1 && a.size() - k - 1 >= 3) return false;
						return true;
					}

					int main(){
						int n;
						cin >> n;
						string a;
						bool success;
						double sum = 0.0;
						int cnt = 0;
						for(int i = 0; i < n; i++){
							cin >> a;
							double b;
							success = check(a, b);
							if(!success) printf("ERROR: %s is not a legal number\n", a.c_str());
							else{
								cnt ++;
								sum += b;
							}
						}
						if(cnt == 0) puts("The average of 0 numbers is Undefined");
						else if(cnt == 1) printf("The average of 1 number is %.2lf\n", sum);
						else printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);

						return 0;
					}
				r4.
					#include <iostream>

					using namespace std;

					bool check(string a, double &b){
						try{
							size_t ind;
							b = stof(a, &ind);
							if(ind < a.size()) return false;
						}catch(...){
							return false;
						}

						if(b < -1000 || b > 1000) return false;
						int k = a.find('.');
						if(k != -1 && a.size()-k-1 >= 3) return false;

						return true; 
					}
					int main(){
						int n;
						cin >> n;

						string a;
						int cnt = 0;
						double sum = 0.0;
						for(int i = 0; i < n ; i++){
							cin >> a;
							double b;
							if(check(a, b)) {
								sum += b;
								cnt ++;
							}
							else{
								printf("ERROR: %s is not a legal number\n", a.c_str());
							}
						}

						if(cnt == 0) puts("The average of 0 numbers is Undefined");
						else if(cnt == 1) printf("The average of 1 number is %.2lf\n", sum);
						else printf("The average of %d numbers is %.2lf\n", cnt , sum / cnt );

						return 0;
					}
				r5.

		18. 1617. 微博转发抽奖	1124
			0. bug
			1. 笔记
				主要是unordered_set的使用:
					1. set.count(name[i])
					2. set.empty()
					3. set.insert(name[i]);
			2. 注释
				#include <iostream>
				#include <cstring>
				#include <unordered_set>

				using namespace std;

				const int N = 1010;

				int m, n, s;
				string name[N];

				int main()
				{
				    cin >> m >> n >> s;
				    for (int i = 1; i <= m; i ++ ) cin >> name[i];

				    unordered_set<string> hash;
				    int k = s;
				    while (k <= m)
				    {
				        if (hash.count(name[k])) k ++ ;
				        else
				        {
				            cout << name[k] << endl;
				            hash.insert(name[k]);
				            k += n;
				        }
				    }

				    if (hash.empty()) puts("Keep going...");

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/323472/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					const int N = 1100;
					string name[N];

					int main(){
						int m, n, s;
						for(int i = 1; i <= m; i++){
							cin >> name[i];
						}

						unordered_set<string> set;
						for(int i = s; i <= m ;){
							if(set.count(name[i]))
								i++;
							else{
								set.insert(name[i]);
								cout << name[i] << endl;
								i += n;
							}
						}

						if(set.empty()) cout << "Keep going..." << endl;
						return 0;
					}
				r2.
					#include <iostream>
					#include <unordered_set>

					using namespace std;

					const int N = 1010;
					string name[N];

					int main(){
						int m, n, s;
						cin >> m >> n >> s;
						for(int i = 1; i <= m; i++){
							cin >> name[i];
						}

						unordered_set<string> set;
						for(int i = s; i <= m;){
							if(set.count(name[i])) i++;
							else{
								set.insert(name[i]);
								cout << name[i] << endl;
								i += n;
							}
						}

						if(set.empty()) puts("Keep going...");
						return 0;

					}
				r3.
					#include <iostream>
					#include <unordered_set>

					using namespace std;

					const int N = 1010;
					string name[N];

					int main(){
						int m, n, s;
						cin >> m >> n >> s;
						for(int i = 1; i <= m; i++){
							cin >> name[i];
						}

						unordered_set<string> set;
						for(int i = s; i <= m ; )
						{
							if(set.count(name[i])) i++;
							else{
								set.insert(name[i]);
								cout << name[i] << endl;
								i += n;
							}
						}

						if(set.empty()) puts("Keep going...");

						return 0;
					}
				r4.
				r5.

		19. 1634. PAT单位排行	1141
			0. bug
				double真的是一个很恶心的东西!
					1. int不能 /除以一个数
					2. double和int不能直接相加
					3. double不能用来sort
					4. double不能用来if(doubleA == doubleB)或者if(doubleA != doubleB)
				1. 
					错误的:
						int g;
						cin >> g;
						hash[i].grade += g/1.5;
						错误原因: 因为是/1.5, 不能用int来存input
						其实非常容易出现bug, 因为在看input的形式的时候, 都是int, 所以我就会将g设置成int
						我就会忘记后面需要 /1.5
					正确:
						double g; cin >> g; hash[i].grade += g/1.5;
				2. %d一定是对应着int, 即便你把double cast成了int, 也不能当做int
					错误的例如:
						double a = (int)1.
						printf("%d", a); 会输出很奇怪的东西, 即便你把double cast成了int
					正确的:
						double a = (int)1.
						printf("%d", (int)a);
				3. 容易出bug的地方!!
					两个double之间的比较, 最好不要直接用 != ,而是记得将他们cast成int
					例如,错误的:
						grade是double
						if(i >= 1 && res[i].grade != res[i-1].grade) rank = i + 1;
					正确的:
						if(i >= 1 && (int)res[i].grade != (int)res[i-1].grade) rank = i + 1;
				4. 我之前觉得很奇怪的bug!但是我后来想明白了
					见r3里面, 如果 s.grade = (int)(s.grade + 1e-8); 答案就是正确的
					如果s.grade = (s.grade + 1e-8), 跑下面这个就是错误的
						50
						B35824 63 fi
						A52262 89 PF
						B70558 50 sl
						A44244 55 pf
						T42426 22 PF
						B40552 0 agnEyk
						B44608 1 FI
						A79448 7 OhxoCy
						A61658 43 pF
						T96625 98 fI
						B78998 42 sL
						T61664 3 pf
						A00053 90 sl
						B27970 13 sl
						B08683 38 JLSEC
						B19045 25 OHxoCY
						A28640 60 WUrX
						A30426 94 VnFjR
						T30492 14 VNfJr
						B88357 6 pf
						T32404 76 sL
						A15074 40 wuRx
						B14351 53 vNFjr
						A09728 68 OHXoCY
						B93722 46 FI
						A24455 95 jLsEc
						T49043 10 agNeyK
						T26264 14 AGnEYK
						B92183 36 oHXocy
						A02532 0 aGNeyK
						T86446 96 jlsEC
						T88939 20 VnFJR
						B33804 20 Sl
						T30375 4 AgNeYK
						T54489 20 JlSEc
						B71801 87 wuRX
						T50543 27 JlsEc
						T28712 29 FI
						T08625 33 JlSeC
						T91944 72 FI
						A14701 13 wUrx
						A78235 33 wURX
						B30779 8 OHXOcY
						B99829 58 JlSec
						B51449 57 OhxOCy
						B64516 45 fI
						B14527 37 Wurx
						T67656 92 ohxOcy
						T34618 62 SL
						A13719 46 ohxocy
					正确答案中
						5 pf 228 6
						5 wurx 228 6
					但是我的答案却是
						5 wurx 228 6
						5 pf 228 6
					是这样子的!!!!! 我们cast成int的目的是服务于后面的sort()
						虽然我输出的时候,看上去的确是两个人的排名一样, 分数一样, 人数一样,但是这是我输出时候cast成了int
						但是在sort(res.begin(), res.end())的时候,其实这两个是不一样的
						为什么, 因为我s.grade = (s.grade + 1e-8)中s.grade是double, double进行sort很恶心的!
			1. 笔记
				0. 使用了struct + unordered_map + vector
					struct:
						一个聚合的类型:school
						里面包含了很多内容:所以用struct存储这些内容
					unordered_map:
						因为每个聚合的类型, 我们需要用一个东西给存下来每一个聚合
						所以用map<string, Struct>, 其中string就是每一个聚合的名字
						我之前想过, 能不能直接将struct存入vector中,而不需要map用string来索引
						但是不行,因为vector<>需要我们一次性的push_back()
							但是我们的输入可能还会用到之前的的内容,例如grade, 我们的grade是一直是+=g的, 而不是一次性知道的
						另外,使用unordered_map的原因是
							我们的输出顺序是grade,而不是string
						什么时候可以用map:
							如果是string的话,我们可以用map给我们自动排好的顺序输出
					vector:
						因为我们需要排序, 但是map不能排序
						所以就把map里的所有东西放出来,然后放到vector里面, 用sort()
				1. 使用默认重构函数: School(): cnt(0), sum(0) {}
					使用的原因: 我们在输入的时候, 不是一次性的获取全部结果,而是一次获取一点
					所以我们直接用了hash[sch].sum += grade; 因为可以直接调用默认重构函数chool(): cnt(0), grade(0) {}, 然后在grade == 0的基础上 += grade;
				2. 使用了unordered_map<string, Struct>, 使用了vector<Struct>存结果
				3. 使用了重载<
					使用了sort()
				4. 读入如果出现除号,记得用double
					以后遇到除法, 记得输入的是否是double, 否则出现bug
				4. 精度问题
					1. 我们希望的输出是: 加权总分 定义为 x.yyy 的整数部分
						所以希望的是向下取整,也就是用(int)x.yyy, 就可以得到x
						例如 (int)1.999 = 1
					2. 但是, 有时候除法会导致的问题是, 我们的到的是1.99999999999, 这个时候我们不应该向下取整, 因为这个是精度问题导致的1.999999999,而实际上应该是2
						所以我们会 + 1e-8
						也就是(int)(1.999999999999 + 1e-8) = (int)2.0000000007 = 2
				5. 将一个string变成小写.
					因为tolower()只能处理char,所以我们要遍历string中的每一个char
					需要使用引用,来修改string的每一个char
						for (auto& c : sch) c = tolower(c);
						结束之后, sch中的每一个char都得到了修改
				6. 计算rank
					0. 一定初始化rank = 1
					1. rank不变的情况
						1. 是第0个, rank还是rank,不变, 也就是rank == 1
						2. 如果第i个(i >= 1) && g[i] == g[i-1]也就是==前面的, rank不变
					2. rank更新
						1. 如果第i个(i >= 1) && g[i] != g[i-1], 就一定要更新, 更新的值是就是我在队列里面的序号(假设从1开始)
					3. 我们一般都只会处理rank更新的情况: 所以也就只有一句
						int rank = 1;
						for (int i = 0; i < s.size(); i ++ )
					    {
					        if (i && s[i] != s[i - 1]) rank = i + 1;
					        cout << rank << endl;
					    }
			2. 注释
				#include <iostream>
				#include <cstring>
				#include <unordered_map>
				#include <vector>
				#include <algorithm>

				using namespace std;

				struct School
				{
				    string name;
				    int cnt;
				    double sum;

				    School(): cnt(0), sum(0) {}

				    bool operator< (const School &t) const
				    {
				        if (sum != t.sum) return sum > t.sum;
				        if (cnt != t.cnt) return cnt < t.cnt;
				        return name < t.name;
				    }
				};

				int main()
				{
				    int n;
				    cin >> n;

				    unordered_map<string, School> hash;
				    while (n -- )
				    {
				        string id, sch;
				        double grade;
				        cin >> id >> grade >> sch;

				        for (auto& c : sch) c = tolower(c);

				        if (id[0] == 'B') grade /= 1.5;
				        else if (id[0] == 'T') grade *= 1.5;

				        hash[sch].sum += grade;
				        hash[sch].cnt ++ ;
				        hash[sch].name = sch;
				    }

				    vector<School> schools;
				    for (auto item : hash)
				    {
				        item.second.sum = (int)(item.second.sum + 1e-8);
				        schools.push_back(item.second);
				    }

				    sort(schools.begin(), schools.end());
				    cout << schools.size() << endl;

				    int rank = 1;
				    for (int i = 0; i < schools.size(); i ++ )
				    {
				        auto s = schools[i];
				        if (i && s.sum != schools[i - 1].sum) rank = i + 1;
				        printf("%d %s %d %d\n", rank, s.name.c_str(), (int)s.sum, s.cnt);
				    }

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/323490/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <map>
					#include <algorithm>

					using namespace std;

					struct School{
						double grade;
						int cnt;
						int rank;
						string name;

						School() : grade(0), cnt(0), rank(-1){}

						bool operator< (const School& t) const{
							if(grade != t.grade) return grade > t.grade;
							if(cnt != t.cnt) return cnt < t.cnt;
							return name < t.name;
						}
					};

					map<string, School> sMap;
					int main(){
						int n;
						cin >> n;

						string id, sch;
						double g;
						for(int i = 0; i < n; i++){
							cin >> id >> g >> sch;
							if(id[0] == 'B') g /= 1.5;
							else if(id[0] == 'T') g *= 1.5;

					    	for(auto &c : sch) c = tolower(c);
							sMap[sch].grade += g;
							sMap[sch].cnt ++;
						}

						vector<School> res;
						for(auto item :sMap){
							auto name = item.first;
							auto school = item.second;
					        // school.grade = 123.99999999999;
					        // printf("%.5lf\n",school.grade);
							school.grade = (int)(school.grade + 1e-8);
					// 		printf("%.5lf\n",school.grade);
							school.name = name;
							res.push_back(school);
						}

						sort(res.begin(), res.end());
						int rank = 1;
						cout << res.size() << endl;
						for(int i = 0; i < res.size(); i++){
							//if(!i) rank = rank;
							//if(i >= 1 && res[i].grade == res[i-1].grade) rank = rank;

							if(i && res[i].grade != res[i-1].grade) rank = i+1;
							printf("%d %s %d %d\n", rank, res[i].name.c_str(), (int)res[i].grade, res[i].cnt);

						}
						return 0;

					}
				r2.
					#include <iostream>
					#include <map>

					using namespace std;



					struct School{
						string name;
						double grade;
						int cnt;

						School(): grade(0), cnt(0) {}

						bool operator< (const School& t) const{
							if(grade != t.grade) return grade > t.grade;
							if(cnt != t.cnt) return cnt < t.cnt;
							return name < t.name;
						}
					};

					map<string, School> schools;

					int main(){
						int n;

						string id, name;
						double g;
						for(int i = 0; i < n; i++){
							cin >> id >> g >> name;
							if(id[0] == 'B') g /= 1.5;
							else if(id[0] == 'T') g *= 1.5;

							for(auto &c : name) c = tolower(c);
							schools[name].grade += g;
							schools[name].cnt++;
							schools[name].name = name;
						}

						vector<School> res;
						for(auto item : schools){
							auto s = item.seconds;
							s.grade = (int)(s.grade + 1e-8);
							res.push_back(s);
						}

						sort(res.begin(), res.end());
						cout << res.size() << endl;

						int rank = 1;
						for(int i = 0; i < res.size(); i++){
							if(i != 0 && res[i].sum != res[i-1].sum) rank = i + 1;
							auto t = res[i];
							printf("%d %s %d %d\n",  rank,t.name.c_str(), t.sum, t.cnt);
						}

						return 0;
					}
				r3.
					#include <iostream>
					#include <unordered_map>
					#include <vector>
					#include <algorithm>

					using namespace std;

					struct School{
						string name;
						double grade;
						int cnt;

						School(): name(""), grade(0), cnt(0) {}

						bool operator< (const School& t) const{
							if(grade != t.grade) return grade > t.grade;
							if(cnt != t.cnt) return cnt < t.cnt;
							return name < t.name;
						}
					};

					unordered_map<string, School> schools;

					int main(){
						int n;
						cin >> n;

						string id;
						double g;
						string name;
						for(int i = 0; i < n ; i++){
							cin >> id >> g >> name;

							for(char &c : name) c = tolower(c);
							if(schools[name].name == "") schools[name].name = name;
							schools[name].cnt ++;

							if(id[0] == 'B') g /= 1.5;
							else if(id[0] == 'T') g *= 1.5;
							schools[name].grade += g;
						}


						vector<School> res;
						for(auto item : schools){
							auto s = item.second;
							s.grade = (int)(s.grade + 1e-8); //这是为了sort()才cast成int的
							res.push_back(s);
						}

						sort(res.begin(), res.end());
						cout << res.size() << endl;

						int rank = 1;
						for(int i = 0; i < res.size(); i++){
							if(i >= 1 && res[i].grade != res[i-1].grade) rank = i + 1;
							auto r = res[i];
							printf("%d %s %d %d\n", rank, r.name.c_str(), (int)r.grade, r.cnt);
						}

						return 0;


					}
				r4.
					#include <iostream>
					#include <unordered_map>
					#include <vector>
					#include <algorithm>

					using namespace std;

					struct School{
						string name;
						double grade;
						int cnt;

						School(): name(""), grade(0), cnt(0) {}

						bool operator< (const School& t) const{
							if(grade != t.grade) return grade > t.grade;
							if(cnt != t.cnt) return cnt < t.cnt;
							return name < t.name;
						}
					};

					unordered_map<string, School> school;

					int main(){
						int n;
						cin >> n;

						string id;
						double grade;
						string name;
						for(int i = 0; i < n; i++){
							cin >> id >> grade >> name;
							if(id[0] == 'B') grade /= 1.5;
							else if(id[0] == 'T') grade *= 1.5;

							for(char &c : name) c = tolower(c);

							school[name].grade += grade;
							school[name].cnt ++;
							if(school[name].name == "") school[name].name = name;
						}

						vector<School> res;
						for(auto item : school){
							auto s = item.second;
							s.grade = (int)(s.grade + 1e-8);
							res.push_back(s);
						}

						sort(res.begin(), res.end());
						cout << res.size() << endl;
						int rank = 1;
						for(int i = 0; i < res.size(); i++){
							auto s = res[i];
							if(i && res[i].grade != res[i-1].grade) rank = i+1;
							printf("%d %s %d %d\n", rank, s.name.c_str(), (int)s.grade, s.cnt);
						}

						return 0;
					}

				r5.

	5. 2020年10月3日08:21:03
		20. 1647. 解码PAT准考证	1153
			0. bug
				0. 注意, 有时候我可能会写成 if(char == string)但是我没发现,这会报错
					可以改成if(char == string[0])
				1. 因为type == 1的时候,我们是要grade降序, id升序输出, 所以我们要先sort(),再遍历我们所有的item

			1. 笔记
				1. 数据结构的使用
					0. 为什么不用vector<pair<string, int>> 存string id和int grade. 因为我们可以将两个信息放到struct里, 构建vector<struct>
					1. 为什么用了struct[]数组, 而不是vector<struct>?
						因为vector<>的好处我们这里不需要
							vector<>的好处在于我们在遍历的时候直接知道vector的size
							但是这道题已经告诉我们有多少个输入,所以已经知道了struct[]的size
					2. 为什么不用map<string, int>
						因为map<string,int>的好处在于我们可以递进的获取信息,不需要一次性知道
							例如: 
								map["abc"]++;
								注意,这里是可以直接++; 因为会直接初始化
								而不需要判断if(map.count("abc") == 0) map["abc"] = 1;
								else map["abc"]++;
						vector<>需要我们一次性的push_back, 而这里可以我们一次性
						struct[]也是需要我们一次性赋值
					3. 但是,我保险起见,我会用vector<struct>,而不是struct[]数组
				2. 数据结构的搭配
					和之前的unordered_map + vector相似
						因为我们不采用排序第一个关键字,所以不使用map(因为map是可以自动第一个关键字排序)
							因为我们用map是为了给每个stirng name输入相关的info,如果用map,那就是以string name为第一关键字的升序
							但是我们是以int grade为第一个关键字,所以不用map
						所以我们采用unordered_map,因为unordered_map不能排序,所以我们把结果push斤vector里面,然后我们sort(),重载<
				2. 关于排序
					1. vector<aa>需要使用aa的<符号排序
					2. vector<pair<aa,bb>> sort(vec.begin(), vec.end())的时候
						会自动按照第一关键字aa的升序, 然后第二关键字bb升序
						因为type == 3, 是按照int grade降序 + string name升序
						所以我们{-grade, name}
							第一关键字是-grade,即-grade的升序,grade的降序
							第二关键字name,即name的升序
					3. 会议其他
						1. priority_queue<>自动sort,然后按照>符号排序
							queue.top()就可以了
						2. map<aa,bb>, 自动按照aa的升序排序
							for(auto item : map)的时候就可以了


			2. 注释
				#include <iostream>
				#include <cstring>
				#include <unordered_map>
				#include <algorithm>
				#include <vector>

				using namespace std;

				const int N = 10010;

				int n, m;
				struct Person
				{
				    string id;
				    int grade;

				    bool operator< (const Person &t) const
				    {
				        if (grade != t.grade) return grade > t.grade;
				        return id < t.id;
				    }
				}p[N];

				int main()
				{
				    cin >> n >> m;
				    for (int i = 0; i < n; i ++ ) cin >> p[i].id >> p[i].grade;

				    for (int k = 1; k <= m; k ++ )
				    {
				        string t, c;
				        cin >> t >> c;

				        printf("Case %d: %s %s\n", k, t.c_str(), c.c_str());
				        if (t == "1")
				        {
				            vector<Person> persons;
				            for (int i = 0; i < n; i ++ )
				                if (p[i].id[0] == c[0])
				                    persons.push_back(p[i]);

				            sort(persons.begin(), persons.end());

				            if (persons.empty()) puts("NA");
				            else
				                for (auto person : persons) printf("%s %d\n", person.id.c_str(), person.grade);
				        }
				        else if (t == "2")
				        {
				            int cnt = 0, sum = 0;
				            for (int i = 0; i < n; i ++ )
				                if (p[i].id.substr(1, 3) == c)
				                {
				                    cnt ++ ;
				                    sum += p[i].grade;
				                }

				            if (!cnt) puts("NA");
				            else printf("%d %d\n", cnt, sum);
				        }
				        else
				        {
				            unordered_map<string, int> hash;
				            for (int i = 0; i < n; i ++ )
				                if (p[i].id.substr(4, 6) == c)
				                    hash[p[i].id.substr(1, 3)] ++ ;

				            vector<pair<int, string>> rooms;
				            for (auto item : hash) rooms.push_back({-item.second, item.first});

				            sort(rooms.begin(), rooms.end());
				            if (rooms.empty()) puts("NA");
				            else
				                for (auto room : rooms)
				                    printf("%s %d\n", room.second.c_str(), -room.first);
				        }
				    }

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/323501/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <vector>

					using namespace std;

					struct Person{
						string id;
						int grade;
					}

					vector<Person> persons;
					int main(){
						int n, m;

						string id;
						int grade;
						for(int i = 0 ; i < n ; i++){
							cin >> id >> grade;
							persons.push_back({id, grade});
						}

						int type;
						string cmd;
						for(int i = 0; i < m ;i ++){
							cin >> type >> cmd;
							printf("Case %d: %d %s\n", i+1, type, cmd.c_str());
							if(type == 1){
								int res = 0;
								for(auto p : persons){
									if(p.id[0] == cmd){
										printf("%s %d\n", p.id.c_str(), p.grade);
										if(!res) res = 1;
									}
								}
								if(!res) puts("NA");
							}
							else if(type == 2){
								int cnt = 0;
								int sum = 0;
								for(auto p :persons){
									if(p.id.substr(1,3) == cmd){
										cnt ++;
										sum += p.grade;
									}
								}
								if(!cnt) puts("NA");
								else printf("%d %d\n", cnt, sum);
							}
							else{
								unordered_map<string, int> map;
								for(auto p :persons){
									if(p.id.substr(4,6) == cmd){
										map[p.id.substr(1,3)] ++;
									}
								}
								vector<pair<int, string>> res;
								for(auto item : map){
									res.push_back({-item.second, item.first});
								}
								sort(res.begin(), res.end());
								for(auto item : res){
									printf("%s %d\n", item.second, -item.first);
								}
							}
						}
						return 0;
					}
				r2.
					#include <iostream>
					#include <algorithm>
					#include <vector>
					#include <unordered_map>

					using namespace std;

					const int N = 10010;

					struct Person{
						string id;
						int grade;

						bool operator< (const Person& t) const{
							if(grade != t.grade) return grade > t.grade;
							return id < t.id;
						}
					}persons[N];

					int main(){
						int n, m;
						cin >> n >> m;

						string id;
						int grade;
						for(int i = 0; i < n ; i++){
							cin >> id >> grade;
							persons[i] = {id, grade};
						}

						int type;
						string cmd;
						for(int i = 0; i < m; i++){
							cin >> type >> cmd;
							printf("Case %d: %d %s\n", i+1, type, cmd.c_str());

							vector<Person> res1;
							if(type == 1){
								for(int i = 0; i < n; i++){
									auto p = persons[i];
									if(p.id[0] == cmd[0]){
										res1.push_back(p);
									}
								}
								if(res1.empty()) puts("NA");
								else {
								    sort(res1.begin(), res1.end());
									for(auto p : res1)
										printf("%s %d\n", p.id.c_str(), p.grade);
								}
							}
							else if(type == 2){
								int cnt = 0;
								int sum = 0;
								for(int i = 0; i < n; i++){
									auto p = persons[i];
									if(p.id.substr(1,3) == cmd){
										cnt ++;
										sum += p.grade;
									}
								}
								if(cnt) printf("%d %d\n", cnt, sum);
								else puts("NA");
							}
							else{
							    unordered_map<string,int> map;
								for(int i = 0; i < n ; i++){
									auto p = persons[i];
									if(p.id.substr(4,6) == cmd){
										map[p.id.substr(1,3)]++;
									}
								}
								if(map.empty()) puts("NA");
									else{
										vector<pair<int, string>> res;
										for(auto item : map){
											res.push_back({-item.second, item.first});
										}
										sort(res.begin(), res.end());
										for(auto item: res){
											printf("%s %d\n", item.second.c_str(), -item.first);
										}
									}
							}
						}
						return 0;
					}
				r3.
					#include <iostream>
					#include <vector>
					#include <algorithm>
					#include <unordered_map>

					using namespace std;

					struct Person{
						string id;
						int grade;

						bool operator< (const Person& t) const{
							if(grade != t.grade) return grade > t.grade;
							return id < t.id;
						}
					};

					struct Record{
						string id;
						int cnt;

						bool operator< (const Record& t) const{
							if(cnt != t.cnt) return cnt > t.cnt;
							return id < t.id;
						}
					};

					int main(){
						int n, m;
						cin >> n >> m;

						string id;
						int grade;
						vector<Person> persons;
						for(int i = 0 ; i < n; i++){
							cin >> id >> grade;
							persons.push_back({id, grade});
						}

						int type;
						string cmd;
						for(int i = 0 ; i < m ; i++){
							cin >> type >> cmd;
							printf("Case %d: %d %s\n", i+1, type, cmd.c_str());
							
							if(type == 1){
								sort(persons.begin(), persons.end());
								bool b = false;
								for(auto p : persons){
									if(p.id[0] == cmd[0]){
										printf("%s %d\n", p.id.c_str(), p.grade);
										if(!b) b = true;
									}
								}
								if(!b) puts("NA");
							}
							else if(type == 2)
							{
								int cnt = 0;
								int sum = 0;
								for(auto p : persons){
									if(p.id.substr(1,3) == cmd){
										cnt ++;
										sum += p.grade;
									}
								}
								if(cnt) printf("%d %d\n", cnt, sum);
								else puts("NA");
							}
							else{
								unordered_map<string, int> map;
								vector<Record> res;
								for(auto p : persons){
									if(p.id.substr(4,6) == cmd){
										map[p.id.substr(1,3)]++;
									}
								}
								if(map.empty())puts("NA");
								else{
									for(auto item : map){
										res.push_back({item.first, item.second});
									}
									sort(res.begin(), res.end());
									for(auto item : res){
										printf("%s %d\n", item.id.c_str(), item.cnt);
									}
								}
							}
						}
						return 0;

					}
				r4.
				r5.

2. 高精度
	5. 2020年10月3日13:24:07
		21. 1474. 多项式 A + B 	1002
			0. bug
			1. 笔记
				1. 不难,但是细心
					就是读入的double
					然后输出的时候是从幂次大的,而不是幂次小的地方输出
					输出的时候保留一位小数
				2. 多项式的加法,不涉及进位,因为完全可以 2*x^3 + 123*x^2 + 23*x + 234
			2. 注释
				#include <iostream>

				using namespace std;

				const int N = 1010;

				double a[N], b[N], c[N];

				int main()
				{
				    int k;

				    cin >> k;
				    while (k -- )  // 读入第一个多项式
				    {
				        int n;
				        double v;
				        cin >> n >> v;
				        a[n] = v;
				    }

				    cin >> k;
				    while (k -- )  // 读入第二个多项式
				    {
				        int n;
				        double v;
				        cin >> n >> v;
				        b[n] = v;
				    }

				    // 求和
				    for (int i = 0; i < N; i ++ ) c[i] = a[i] + b[i];

				    k = 0;
				    for (int i = 0; i < N; i ++ )
				        if (c[i])
				            k ++ ;

				    cout << k;
				    for (int i = N - 1; i >= 0; i -- )
				        if (c[i])
				            printf(" %d %.1lf", i, c[i]);

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/269747/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					const int N = 1010;

					double a1[N];
					double a2[N];
					double res[N];

					int main(){
						int n1;
						cin >> n1;
						int n;
						double v;
						while(n1--){
							cin >> n >> v;
							a1[n] = v;
						}	
					    
						cin >> n1;
						while(n1--){
							cin >> n >> v;
							a2[n] = v;
						}
					    
						for(int i = 0; i < N; i ++) res[i] = a1[i] + a2[i];

						int cnt = 0;
						for(int i = 0; i < N; i++){
							if(res[i]) cnt++;
						}

						cout << cnt;
						for(int i = N-1; i >= 0; i--){
							if(res[i]) printf(" %d %.1lf", i, res[i]);
						}

						return 0;
					}
				r2.
					#include <iostream>

					using namespace std;

					const int N = 1010;
					double a[N];
					double b[N];
					double res[N];

					int main(){
						int n;
						cin >> n;

						int k;
						double v;
						for(int i = 0; i < n; i++){
							cin >> k >> v;
							a[k] = v;
						}

						cin >> n;
						for(int i = 0; i < n; i++){
							cin >> k >> v;
							b[k] = v;
						}

						int cnt = 0;
						for(int i = 0; i < N; i++){
							res[i] = a[i] + b[i];
						}
						for(auto i : res) if(i) cnt++;  

						cout << cnt;
						for(int i = N-1; i >= 0; i--){
							if(res[i]) printf(" %d %.1lf", i, res[i]);
						}

						return 0;
					}
				r3.
					#include <iostream>

					using namespace std;

					const int N = 1010;
					double a[N];
					double b[N];
					double res[N];

					int main(){
						int n;
						cin >> n;

						int k;
						double v;
						for(int i = 0; i <n ; i++){
							cin >> k >> v;
							a[k] = v;
						}

						cin >> n;
						for(int i = 0; i < n ;i ++){
							cin >> k >> v;
							b[k] = v;
						}

						for(int i = 0; i < N; i++){
							res[i] = a[i] + b[i];
						}

						int cnt = 0;
						for(auto i : res) if(i) cnt++;

						cout << cnt;
						for(int i = N-1; i >= 0; i--){
							if(res[i]) printf(" %d %.1lf", i, res[i]);
						}

						return 0;

					}
				r4.
				r5.

		22. 1481. 多项式乘积	1009
			0. bug
			1. 笔记
				0. 需要修改值的时候, 函数需要传入引用
					但是像是数组,本身就是指针,所以不需要用引用符号.而是
					double a[];
					void func(double a[]){xxx};
					func(a);
				1.这道题还是不难的
					主要就是考察一个乘积的结果在哪一位
					可以看老师的04:20的图: https://www.a c w ing.com/video/1009/
					总之就是res[i+j] += a[i] * b[j]
				2. 遍历的时候, 我们是全部都遍历,而不是输入了多少个就遍历多少个
					也就是,错误的是for(int i = 0; i < n; i++)
					而是 for(int i = 0; i < N; i++)
				3. 多项式的乘法,不涉及进位,因为完全可以 2*x^3 + 123*x^2 + 23*x + 234
			2. 注释
				#include <iostream>

				using namespace std;

				const int N = 1010;

				double a[N], b[N], c[N * 2];

				void input(double a[])
				{
				    int k;
				    cin >> k;
				    while (k -- )
				    {
				        int n;
				        double v;
				        cin >> n >> v;
				        a[n] = v;
				    }
				}

				int main()
				{
				    input(a);
				    input(b);

				    // 做乘法
				    for (int i = 0; i < N; i ++ )
				        for (int j = 0; j < N; j ++ )
				            c[i + j] += b[i] * a[j];

				    int k = 0;
				    for (int i = 0; i < N * 2; i ++ )
				        if (c[i])
				            k ++ ;

				    cout << k;
				    for (int i = N * 2 - 1; i >= 0; i -- )
				        if (c[i])
				            printf(" %d %.1lf", i, c[i]);

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/269766/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					const int N = 1010;
					double a[N];
					double b[N];
					double res[2*N];

					void input(double a[]){
						int n;
						cin >> n;
						int k;
						double v;
						while(n--){
							cin >> k >> v;
							a[k] = v;
						}
					}

					int main(){
						input(a);
						input(b);

						for(int i = 0; i < N; i++){
							for(int j = 0; j < N; j++){
								res[i+j] += a[i] * b[j];
							}
						}

						int cnt = 0;
						for(int i = 0; i < 2*N; i++) if(res[i]) cnt++;

						cout << cnt;
						for(int i = 2*N-1; i >= 0 ; i--){
							if(res[i]) printf(" %d %.1lf", i, res[i]);
						}

						return 0;
					}
				r2.
					#include <iostream>

					using namespace std;

					const int N = 1010;

					double a[N];
					double b[N];
					double res[N*2];

					void input(double a[]){
						int n;
						cin >> n;
						while(n--){
							int k;
							double v;
							cin >> k >> v;
							a[k] = v;
						}
					}
					int main(){
						input(a);
						input(b);

						for(int i = 0; i < N; i++){
							for(int j = 0; j < N ; j++)
								res[i+j] += a[i] * b[j];
						}

						int cnt = 0;
						for(int i = 0; i < 2*N; i++) if(res[i]) cnt++;
						cout << cnt;

						for(int i = 2*N-1 ; i >= 0; i--)
							if(res[i]) printf(" %d %.1lf", i, res[i]);

						return 0;
					}
				r3.
				r4.
				r5.

		23. 1500. 趣味数字	1023
			0. bug
				1. string 转到vector的时候,忘记 - '0'
				2. 从最后开始遍历的时候, 是int i = size-1, 而不是int i = size;
			1. 笔记
				1. 大数加法,两点比较重要:
					1. 拿到一个string, 我们需要从最后一位(数字最低位)开始往vector里面push
						这样我们就可以从vector的第0位(数字最低位)开始处理了
					2. 我们加法的时候, 两个数字相加,然后再加上t, 并且最后判断t是否还有剩余
					4. 每次计算好了一个数字之后,也是push到一个新的vector<> res
					4. 最后我们从从最后一位(数字最低位)开始读res
				2. 总结: 三明治: 尾+头+尾. 2个尾, 1个头
					1. string -> vector<> a, 从string的尾开始push到vector<> a
					2. vector<> a计算加法, 从a的头开始计算, 计算好后, 每次往res里面push
					3. vector<> res, 从res的尾开始, 依次读取
				3. 比较两个东西是否具有相同的元素
					1. 一般的,使用set,或者开一个数组来当set
					2. 如果两个东西是vector<int>, 我们可以用sort(), 然后看两者是否相同
			2. 注释
				#include <iostream>
				#include <algorithm>
				#include <vector>

				using namespace std;

				int main()
				{
				    string A;
				    vector<int> a;

				    cin >> A;
				    for (int i = A.size() - 1; i >= 0; i -- ) a.push_back(A[i] - '0');

				    vector<int> b;
				    int t = 0;
				    for (int i = 0; i < a.size(); i ++ )
				    {
				        int s = a[i] + a[i] + t;
				        b.push_back(s % 10);
				        t = s / 10;
				    }
				    if (t) b.push_back(t);
				    vector<int> c = b;
				    sort(a.begin(), a.end());
				    sort(c.begin(), c.end());

				    if (a == c) puts("Yes");
				    else puts("No");

				    for (int i = b.size() - 1; i >= 0; i -- ) cout << b[i];

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/269793/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <vector>
					#include <algorithm>

					using namespace std;

					int main(){
						string s;
						cin >> s;

						vector<int> a;
						for(char c : s) a.push_back(c - '0');

						int t = 0;
						vector<int> res;
						for(int i = a.size()-1; i >= 0 || t; i--){
							t = a[i] + a[i] + t;
							res.push_back( t % 10);
							t /= 10;
						}

						vector<int> c = res;
						sort(c.begin(), c.end());
						sort(a.begin(), a.end());

						if(c == a) puts("Yes");
						else puts("No");
						for(int i = res.size()-1; i >= 0; i--) cout << res[i];

						return 0;
					}
				r2.
					#include <iostream>
					#include <vector>
					#include <algorithm>

					using namespace std;

					int main(){
						string a;
						cin >> a;

						vector<int> b;
						for(int i = a.size()-1; i >= 0; i --) b.push_back(a[i] - '0');

						int t = 0;
						vector<int> res;
						for(int i = 0; i < b.size() || t; i++){
						   // cout << "b[i]" << b[i] << endl;
							if(i < b.size()) t = b[i] + b[i] + t;
					// 		cout << t << endl;
							res.push_back( t % 10);
							t = t / 10;
						}

						vector<int> copy = res;
						sort(res.begin(), res.end());
						sort(b.begin(), b.end());

						if(res == b) puts("Yes");
						else puts("No");

						for(int i = copy.size()-1; i >= 0; i--) cout << copy[i];

						return 0;
					}
				r3.
					#include <iostream>
					#include <vector>
					#include <algorithm>

					using namespace std;

					int main()
					{
						string str;
						cin >> str;

						vector<int> a;
						for(int i = str.size()-1; i >= 0; i--) a.push_back(str[i] - '0');

						int t = 0;
						vector<int> res;
						for(int i = 0; i < a.size() || t; i++){
							if(i < a.size()) t = a[i] + a[i] + t;
							res.push_back(t % 10);
							t /= 10;
						}

						string rres;
						for(int i = res.size()-1; i >= 0; i--) rres += res[i]+'0';

						sort(res.begin(), res.end());
						sort(a.begin(), a.end());

						if(res == a) puts("Yes");
						else puts("No");

						cout << rres << endl;
						return 0;
					}
				r4.
					#include <iostream>
					#include <vector>
					#include <algorithm>

					using namespace std;

					int main(){
						string str;
						cin >> str;

						vector<int> a;
						for(int i = str.size()-1; i >= 0; i--) a.push_back(str[i] - '0');

						int t = 0;
						vector<int> res;
						for(int i = 0; i < a.size() || t; i++){
							if(i < a.size()) t = a[i] + a[i] + t;
							res.push_back(t % 10);
							t /= 10;
						}

						string out;
						for(int i = res.size()-1; i >= 0; i--) out += res[i] + '0';

						sort(res.begin(), res.end());
						sort(a.begin(), a.end());

						if(res == a) puts("Yes");
						else puts("No");

						cout << out << endl;
						return 0;
					}
				r5.

		24. 1501. 回文数 1024
			0. bug
				1. 我的逻辑有点混乱, 不是if(isH(a)) cnt ++;
					而是不管是否isH(a), cnt都要++
				2. 因为得到的和res,我们还需要继续赋值给a的
					的确老师的思路更清晰
				3. for(int cnt = 0; cnt < k; cnt++){...; break}
						因为:
							break的时候, 走出for loop, cnt并没有++
					例如:
						int i = 0;
						for(; i < 10; i++){
						    cout << i << endl;
						    if(i == 3) break;
						}
						cout << i << endl; 输出的是0 1 2 3 3
						证明break之后, i没有++
			1. 笔记
				1. 这是更典型的大数相加, 参考23. 1500的三明治模型: 尾+头+尾
				2. 翻转vector<>, 用reverse begin和end
					vector<int> b(a.rbegin(), a.rend());
				3. 如果vector是参数的话,更习惯将vector<>当成引用传入函数
				4. 比较回文:注意我们的的截止条件可以是 i < j, 或者 i <= j. 但是i == j的时候, num[i]肯定==num[j], 所以没必要这么写
						bool check(vector<int>& num)
					{
					    for (int i = 0, j = num.size() - 1; i < j; i ++, j -- )
					        if (num[i] != num[j])
					            return false;
					    return true;
					}
				5. 那种给你k次机会,你慢慢试的题目,然后最后
					最好用
						int cnt = 0;
						while(cnt < k) { ....; cnt ++}
					最好别用
						int cnt = 0;
						for(int i = 0 ; i < k ; i++) {...; cnt++;}
						因为:
							1. int i几乎是累赘,不会用到
							2. 我们最后需要cout << cnt, 但是int i是局部变量
					不能用
						int cnt = 0;
						for(; cnt < k; cnt++){...; break}
						因为:
							break的时候, 走出for loop, cnt并没有++


			2. 注释
				#include <iostream>
				#include <vector>

				using namespace std;

				bool check(vector<int>& num)
				{
				    for (int i = 0, j = num.size() - 1; i < j; i ++, j -- )
				        if (num[i] != num[j])
				            return false;
				    return true;
				}

				vector<int> add(vector<int>& a, vector<int>& b)
				{
				    vector<int> c;
				    for (int i = 0, t = 0; i < a.size() || i < b.size() || t; i ++ )
				    {
				        int s = t;
				        if (i < a.size()) s += a[i];
				        if (i < b.size()) s += b[i];
				        c.push_back(s % 10);
				        t = s / 10;
				    }
				    return c;
				}

				int main()
				{
				    string n;
				    int k;
				    cin >> n >> k;

				    vector<int> a;
				    for (int i = n.size() - 1; i >= 0; i -- ) a.push_back(n[i] - '0');

				    int cnt = 0;
				    if (!check(a))
				    {
				        while (cnt < k)
				        {
				            vector<int> b(a.rbegin(), a.rend());
				            a = add(a, b);
				            cnt ++ ;
				            if (check(a)) break;
				        }
				    }

				    for (int i = a.size() - 1; i >= 0; i -- ) cout << a[i];

				    cout << endl << cnt << endl;

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/269816/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <vector>

					using namespace std;

					bool isH(vector<int> &a){
						for(int i = 0, j = a.size()-1; i < j; i++, j--){
							if(a[i] != a[j]) return false;
						}
						return true;
					}

					int main(){
						string num;
						int k;
						cin >> num >> k;

						vector<int> a;
						for(int i = num.size()-1; i >= 0; i --) a.push_back(num[i] - '0');

						if(isH(a)){
							cout << num << endl;
							cout << 0 << endl;
							return 0;
						}

						int cnt = 0;
						vector<int> res;
						while(cnt < k){
							int t = 0;
							vector<int> b(a.rbegin(), a.rend());
							res.clear();
							for(int i = 0; i < a.size() || i < b.size() || t; i++){
								if(i < a.size()) t += a[i];
								if(i < b.size()) t += b[i];
								res.push_back(t % 10);
								t /= 10;
							}
							cnt ++;
							a = res;
							if(isH(a)) break;
						}

						for(int i = a.size()-1 ; i >= 0; i--) cout << a[i];
						cout << endl << cnt << endl;
						
						

						return 0;

						


					}
				r2.
					#include <iostream>
					#include <vector>

					using namespace std;

					bool isH(vector<int> &a){
						for(int i = 0, j = a.size()-1; i < j; i++, j--) if(a[i] != a[j]) return false;
						return true;
					}


					int main(){
						string num;
						int k;
						cin >> num >> k;

						vector<int> a;
						for(int i = num.size()-1; i >= 0; i--) a.push_back(num[i] - '0');

						int cnt = 0;
						if(!isH(a)){
							for(int i = 0; i < k; i++){
								vector<int> b(a.rbegin(), a.rend());

								vector<int> res;
								int t = 0;
								for(int j = 0; j < a.size() || j < b.size() || t ; j++){
									if(j < a.size()) t += a[j];
									if(j < b.size()) t += b[j];
									res.push_back(t % 10);
									t /= 10;
								}

								a = res;

								cnt ++;
								if(isH(res)) break;
							}
						}

						for(int i = a.size()-1; i >= 0; i--) cout << a[i];

						cout << endl << cnt << endl;
						return 0;
					}
				r3.
					#include <iostream>
					#include <vector>

					using namespace std;

					bool isH(vector<int> &a){
						for(int i = 0, j = a.size()-1; i < j ; i++, j--){
							if(a[i] != a[j]) return false;
						}
						return true;
					}

					int main(){
						string num;
						int k;
						cin >> num >> k;

						vector<int> a;
						for(int i = num.size()-1; i >= 0 ; i--) a.push_back(num[i] - '0');

						if(isH(a)) 
						{
							cout << num << endl;
							cout << 0 << endl;
							return 0;
						}

						int cnt = 0;
					    while(cnt < k){
							vector<int> b(a.rbegin(), a.rend());
							vector<int> res;
							int t = 0;
							for(int i = 0; i < a.size() || i < b.size() || t; i++){
								if(i < a.size()) t += a[i];
								if(i < b.size()) t += b[i];
								res.push_back(t % 10);
								t /= 10;
							}
							a = res;
					        cnt ++;
							if(isH(res)) break;
						}
						
						

						for(int i = a.size()-1; i >= 0; i--) cout << a[i];
						cout << endl << cnt << endl;
						return 0;
					}


				r4.
					#include <iostream>
					#include <vector>

					using namespace std;

					bool isH(vector<int> &a){
						for(int i = 0, j = a.size()-1; i < j; i++, j--) if(a[i] != a[j]) return false;
						return true;
					}

					int main(){
						string str;
						int k;
						cin >> str >> k;

						vector<int> a;
						for(int i = str.size()-1; i >= 0; i--) a.push_back(str[i] - '0');

						if(isH(a)){
							cout << str << endl;
							cout << 0 << endl;
							return 0;
						}
					   
						int cnt = 0;
						while(cnt < k){
							vector<int> b(a.rbegin(), a.rend());
							vector<int> res;
							int t = 0;
							for(int i = 0; i < a.size() || i < b.size() || t ; i++){
								if(i < a.size()) t += a[i];
								if(i < b.size()) t += b[i];
								res.push_back(t % 10);
								t /= 10;
							}
							cnt ++;
							a = res;
							if(isH(res)) break;
						}

						for(int i = a.size()-1; i >= 0 ;i --) cout << a[i];
						cout << endl;
						cout << cnt << endl;
						return 0;
					}
				r5.

		25. 1544. 霍格沃茨的 A + B 	1058
			0. bug
				我容易错写成:
					a += b/17;
					a %= 17;
				应该是
					a += b/17;
					b %= 17;
			1. 笔记
				其实就是考察简单的进位问题:
					1. 记得每个位都依次相加
					2. 然后我们对最后一位向前进位, 也就是 / 进制, 得到的进位加到前一位
					3. 最后最后一个 % 进制
				只需要记住:
					b += c / 29, c %= 29;
					也就是先给b更新, 然后c更新
			2. 注释
				#include <iostream>

				using namespace std;

				int main()
				{
				    int a, b, c, d, e, f;
				    scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);
				    a += d, b += e, c += f;

				    b += c / 29, c %= 29;
				    a += b / 17, b %= 17;

				    printf("%d.%d.%d\n", a, b, c);

				    return 0;
				}
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					int main(){
						int a, b, c, d, e, f;
						scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);
						a += d, b += e, c += f;

						b += c / 29;
						c %= 29;
						a += b / 17;
						b %= 17;

						printf("%d.%d.%d", a, b, c);
						return 0;
					}
				r2.
					#include <iostream>

					using namespace std;

					int main(){
						int a,b,c,d,e,f;
						scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);

						a += d;
						b += e;
						c += f;

						 b += c / 29;
						 c = c % 29;
						 a += b / 17;
						 b = b % 17;

						 printf("%d.%d.%d", a,b,c);
						 return 0;
					}
				r3.
				r4.
				r5.

		26. 1629. 延迟的回文数	1136
			0. bug
				注意, cout的时候, 我用的是int a[i]
				正确的是:
					vector<int> a, cout << a[i];
				错误的是:
					vector<int> a, cout << (a[i] + '0'); 好像会输出很大的数字

			1. 笔记
				都是之前的综合,还是比较简单的
				可以试一下老师的用myprint()来cout
					老师用了四个逗号:
						print(a), cout << " + ", print(b), cout << " = ";
					void print(vector<int> &a){for(int i = a.size()-1; i >= 0; i--)cout << a[i];}
			2. 注释
				#include <iostream>
				#include <cstring>
				#include <vector>

				using namespace std;

				bool check(vector<int> A)
				{
				    for (int i = 0, j = A.size() - 1; i < j; i ++, j -- )
				        if (A[i] != A[j])
				            return false;
				    return true;
				}

				void print(vector<int> A)
				{
				    for (int i = A.size() - 1; i >= 0; i -- ) cout << A[i];
				}

				vector<int> add(vector<int> A, vector<int> B)
				{
				    vector<int> C;
				    for (int i = 0, t = 0; i < A.size() || i < B.size() || t; i ++ )
				    {
				        if (i < A.size()) t += A[i];
				        if (i < B.size()) t += B[i];
				        C.push_back(t % 10);
				        t /= 10;
				    }

				    return C;
				}

				int main()
				{
				    string a;
				    cin >> a;

				    vector<int> A;
				    for (int i = 0; i < a.size(); i ++ ) A.push_back(a[a.size() - 1 - i] - '0');

				    for (int i = 0; i < 10; i ++ )
				    {
				        if (check(A)) break;
				        vector<int> B(A.rbegin(), A.rend());

				        print(A), cout << " + ", print(B), cout << " = ";
				        A = add(A, B);

				        print(A), cout << endl;
				    }

				    if (check(A)) print(A), cout << " is a palindromic number." << endl;
				    else puts("Not found in 10 iterations.");

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/323515/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.	totally byb
					#include <iostream>
					#include <vector>
					using namespace std;

					bool isp(vector<int> &a){
						for(int i = 0, j = a.size()-1; i < j; i++, j--) if(a[i]!=a[j]) return false;
						return true;
					}

					string tostring(vector<int> &a){
					    string res;
					    for(int i = a.size()-1; i >= 0; i--) res += a[i] + '0';
					    return res;
					}

					int main(){
						string num;
						cin >> num;

						vector<int> a;
						for(int i = num.size()-1; i >= 0; i--) a.push_back(num[i] - '0');

						if(isp(a)){
							printf("%s is a palindromic number.", num.c_str());
							return 0;
						}

						int cnt = 0;
						while(cnt < 10){
							vector<int> b(a.rbegin(), a.rend());
							vector<int> res;
							int t = 0;
							for(size_t i = 0; i < a.size() || i < b.size() || t; i++){
								if(i < a.size()) t += a[i];
								if(i < b.size()) t += b[i];
								res.push_back(t % 10);
								t /= 10;
					  		}
					  		string c = tostring(a);
					  		string d = tostring(b);
					  		string e = tostring(res);
					  		printf("%s + %s = %s\n", c.c_str(), d.c_str(), e.c_str());
					  		if(isp(res)){
					  			printf("%s is a palindromic number.", e.c_str());
								return 0;
					  		}
					  		cnt ++;
					  		a = res;
						}

						puts("Not found in 10 iterations.");

						return 0;
					}
				r2.
					#include <iostream>
					#include <vector>

					using namespace std;

					bool isp(vector<int> &a){
						for(int i = 0, j = a.size()-1; i < j; i++, j--) if(a[i] != a[j]) return false;
						return true;
					}

					void print(vector<int> &a){
						for(int i = a.size()-1; i >= 0; i--){
							cout << a[i];
						}
					}

					vector<int> add(vector<int> &a, vector<int> &b){
						vector<int> res;
						for(int i = 0, t = 0; i < a.size() || i < b.size() || t; i++){
							if(i < a.size()) t += a[i];
							if(i < b.size()) t += b[i];
							res.push_back( t % 10);
							t /= 10;
					 	}
					 	return res;
					}

					int main(){
						string num;
						cin >> num;

						vector<int> a;
						for(int i = num.size()-1; i >= 0; i--) a.push_back(num[i] - '0');

						for(int i = 0; i < 10 ; i++){
							if(isp(a)) break;

							vector<int> b(a.rbegin(), a.rend());
							print(a), cout << " + ", print(b), cout << " = ";
							a = add(a, b);
							print(a);
							cout << endl;
						}

						if(isp(a)) print(a), cout << " is a palindromic number." << endl;
						else cout << "Not found in 10 iterations." << endl;
					}
				r3.
				r4.
				r5.

3. 进制
	6. 2020年10月5日12:51:34
		
		27. 1482. 进制	1010
			0. bug
				1. 我们的calc(string, LL), 那么传入的int一定要cast
			1. 笔记
				1. swap
					我们使用swap(a,b),记得#include <algorithm>
				3. l, r
					l : 最小的可能的进制
						是每一个数字中最大值+1
							例如 78, 起码也是9进制
					r: 最大可能的进制
						例如 78, 最大的进制是79进制, 当然也可以是80进制,81进制
						但是我们题目默认是求最小的那个进制
					注意:
						1. 题目输入的进制,最大是36
						2. 但是我们结果输出的进制, 可以最大是(3,656,158,440,062,976 - 1)进制
							3,656,158,440,062,976 - 1
							因为最大的数字是zzzzzzzzzz(10个z)
							如果zzzzzzzzzz+1 = 10000000000(10个0)
							所以10000000000 = 36^10+0^9+0^8...+0 = 3,656,158,440,062,976
							所以最大是16位数,我们可以用longlong存,因为longlong最大是19位
				2. calc
					题目是问a在r进制下和b在xx进制下相等
					我们是将他们统一成世界语言,就是10进制
						假设r进制的a在10进制下是res
						LL res = 0;
						for(char c : s){
							res = res * 10 + get(c);
						}
						我们的res的最大值是 10个z(因为进制最大是36)
					注意可能会溢出,溢出的情况:	
						1. bv62a5i36a是35进制, 问9876543210是多少进制,假设n是多少
							我们求出10进制的bv62a5i36a是937170408310020
							然后我们的n的取值范围是 10到937170408310020+1
								因为数字中最大是9,所以起码也是10进制
						2. 如果我们计算calc(9876543210, 937170408310020+1)
							很明显就会溢出LL了
							所以我们看一下,如果快要溢出了, 我们就希望 r = mid, 也就是向左边,更小的进制考虑
							所以采用了if ((double)res * r + get(c) > 1e16) return 1e18;
								其中return 1e18, 是不会溢出longlong的
								其中double是20位,相当于 unsigned long long
								注意, 一定要写double, 否则的话, res * r即便溢出了,也会丢掉前面的数字, 例如99990000000,溢出了,但是丢了前面的数字,只剩下000000,就不可能 > 1e16了 
							这个return 1e18中的1e18, 就是我们希望 == res的值
								r进制的a在10进制下是res
				3. 回忆二分法:
					求最小的那个进制, 例如我们的target是78, 然后问1
					while(l < r){	
						LL mid = l + (r-l)/2;	mid是靠左的
						if(res <= calc(b, mid)) r = mid;	mid靠左,所以r = mid
						else l = mid + 1;	所以l = mid + 1;
					}

					if(calc(b, r) != res) puts("Impossible"); 最后==res可以是r也可以是l,因为(r==l)就会跳出,而且一般一步一步挪的话,最后就是(r==l),而不是一下子就变成了(r = l-1)
				
				4. LL
					c/c++中int，long，long long的取值范围：
					10位: 
						2^32 = 4*10^10
							unsigned   int   0～4294967295 
							unsigned long 0～4294967295
						2^32/2 = 2*10^10
							int   -2147483648～2147483647 
							long   -2147483648～2147483647
					19位: 2^64/2 = 9*10^19
						long long 的最大值：9223372036854775807
						long long 的最小值：-9223372036854775808
					20位: 2^64 = 1.8*10^20
						unsigned long long 的最大值：18446744073709551615  //20位
						double 的最大值：18446744073709551615  //20位
					其他:
						__int64的最大值：9223372036854775807
						__int64的最小值：-9223372036854775808
						unsigned __int64的最大值：18446744073709551615
			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>

					using namespace std;

					typedef long long LL;


					int get(char c)
					{
					    if (c <= '9') return c - '0';
					    return c - 'a' + 10;
					}


					LL calc(string n, LL r)
					{
					    LL res = 0;
					    for (auto c : n)
					    {
					        if ((double)res * r + get(c) > 1e16) return 1e18;
					        res = res * r + get(c);
					    }
					    return res;
					}


					int main()
					{
					    string n1, n2;
					    cin >> n1 >> n2;
					    int tag, radix;
					    cin >> tag >> radix;

					    if (tag == 2) swap(n1, n2);
					    LL target = calc(n1, radix);

					    LL l = 0, r = max(target, 36ll);
					    for (auto c : n2) l = max(l, (LL)get(c) + 1);

					    while (l < r)
					    {
					        LL mid = l + r >> 1;
					        if (calc(n2, mid) >= target) r = mid;
					        else l = mid + 1;
					    }

					    if (calc(n2, r) != target) puts("Impossible");
					    else cout << r << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/269858/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b

					#include <iostream>
					#include <algorithm> //包括了swap()

					using namespace std;

					typedef long long LL;

					int get(char c){
						if(c <= '9') return c - '0'; //bug, 记得减去0
						else return c - 'a' + 10;
					}

					LL calc(string a, LL radit){ //bug!, radit必须是LL, 不嫩是int, 因为是为了计算calc(b, radit), 这里的radit可以很大, 而不仅仅是36
						LL res = 0;
						for(auto c : a){
						    if((double)res * radit + get(c) > 1e17) return 1e18;  //按道理说,如果输入的a是zzzzzzzzzz,进制是36, 也才2*10^15, 所以如果return 1e18说明是输入的问题, 应该最后是impossible
							res = res * radit + get(c);
						}
						return res;
					}

					int main(){
						string a, b;
						int tag, radit;
						cin >> a >> b; 
						cin >> tag >> radit;

						if(tag == 2) swap(a, b);

						LL target;
						target = calc(a, radit);
						
						LL l = 0, r = max(target + 1, 36ll);
						for(auto c : b)  //bug! 这里是从我们的b中遍历, 而不是我们的a !!
							l = max(l, (LL)get(c) + 1);
							
						while( l < r){
							LL mid = l + (r-l) / 2;
							if(calc(b, mid) >= target) r = mid;
							else l = mid + 1; 
						}

						if(calc(b, l) == target) cout << r << endl;
						else puts("Impossible");

						return 0;

					}
			3. 5次
				r1.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					typedef long long LL;

					int get(char c){
						if(c <= '9') return c - '0';
						return c - 'a' + 10;
					}

					LL calc(string a, LL r){
						LL res = 0;
						for(char c : a){
						    if ((double)res * r + get(c) > 1e16) return 1e18;
							res = res * r + get(c);
						}
						return res;
					}

					int main(){
						string a, b;
						int type;
						int radit;

						cin >> a >> b >> type >> radit;
						if(type == 2) swap(a, b);

						LL res = calc(a, (LL)radit);
						
						LL l = 0, r = res + 1;
						for(char c : b) l = max(l, (LL)get(c) + 1);

						while(l < r){
							LL mid = l + (r-l)/2;
							if(res <= calc(b, mid)) r = mid;
							else l = mid + 1;
						}

						if(calc(b, r) != res) puts("Impossible");
						else cout << r << endl;

						return 0; 
					}
				r2.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					typedef long long LL;

					int get(char c){
						if(c <= '9') return c - '0';
						return c - 'a' + 10;
					}

					LL calc(string a, LL radit){
						LL res = 0;
						for(char c : a){
							if((double) res * radit > 1e16) return 1e18;
					 		res = res * radit + get(c);
						}
						return res;
					}

					int main(){
						string a, b;
						int type, radit;

						cin >> a >> b >> type >> radit;
						if(type == 2) swap(a,b);

						LL target = calc(a, (LL)radit);

						LL l = 0, r = target + 1;
						for(char c : b) l = max(l, (LL)get(c) + 1);

						while(l < r){
							LL mid = l + (r-l) / 2;
							if(target <= calc(b, mid)) r = mid;
							else l = mid + 1;
						}

						if(calc(b, r) != target) puts("Impossible");
						else cout << r << endl;

						return 0;
					}
				r3.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					typedef long long LL;

					int get(char c) {
						if(c <= '9') return c - '0';
						return c - 'a' + 10;
					}

					LL calc(string a, LL radit){
						LL res = 0;
						for(char c : a){
							if((double) res * radit > 1e16) return 1e18;
							res = res * radit + get(c);
						}
						return res;
					}

					int main(){
						string a, b;
						int type, radit;

						cin >> a >> b >> type >> radit;

						if(type == 2) swap(a,b);

						LL target = calc(a, (LL)radit);

						LL l = 0, r = target + 1;
						for(char c : b) l = max(l, (LL)(get(c) + 1));

						while(l < r) {
							LL mid = l + (r-l)/2;
							if(target <= calc(b, mid)) r = mid;
							else l = mid + 1;
						}

						if(target == calc(b, r)) cout << r << endl;
						else puts("Impossible");

						return 0;
					}
				r4.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					typedef long long LL;

					int get(char c){
						if(c <= '9') return c - '0';
						return c - 'a' + 10;
					}

					LL calc(string a, LL radit){
						LL res = 0;
						for(char c : a){
							if((double)res * radit > 1e16) return 1e18;
							res = res * radit + get(c);
						}
						return res;
					}


					int main(){
						string a,b;
						int type, radit;

						cin >> a >> b >> type >> radit;

						if(type == 2) swap(a,b);
						LL target = calc(a, (LL)radit);

						LL l = 0, r = target + 1;
						for(char c : b) l = max(l, (LL)get(c) + 1);

						while(l < r){
							LL mid = l + (r-l)/2;
							if(target <= calc(b, mid)) r = mid;
							else l = mid + 1;
						}

						if(target != calc(b, r)) puts("Impossible");
						else cout << r <<endl;
						return 0;
					}

				r5.

		28. 1492. 可逆质数	1015
			0. bug
				一个n进制下的数字x, 变成10进制
					res = res * n + (x的第一位数字)
					但是很容易错写成: res = res * 10 + (x的第一位数字)
						因为可能会想着,我要转化成10进制,所以*10,其实是*n
			1. 笔记
				1. 这道题的input类型不同, 是直接输入n,d然后最后以负数结尾, 所以我们用
					int n, d; while(cin >> n >> d, n >= 1)
				2. 底下的while,完成了了很多步骤
					1. n % d: n转化成d进制的时候,假设结果是x, x最末尾的那个数字就是 n % d
					2. 题目是将x翻转,所以 n % d就是x的第一位数字
					3. 我们将x从d进制转化成10进制的时候, 采用的是 res * d + (x的第一位数字) == res * d + n % d
					4. 所以一气呵成,  res * d + n % d
				3. bug, 是n % i在计算质数的时候
				4. 模板:
					1. 质数:
						bool isprime(int n){
							if(n == 1) return false;
							for(int i = 2; i <= n / i; i++) if(n % i == 0) return false;
							return true;
						}
					2. 进制: d进制表示的a, 转化成10进制
						string a, int d;
						int res = 0;
						for(char c : a) 
							res = res * d + (c - '0');
					3. 进制: 10进制表示的a, 转化成d进制
						vector<int> res;
						int a, int d;
						while(a){
							res.push_back(a % d);
							a /= d;
						}
						最后res的第0位是数字的最低位
			2. 注释
				#include <iostream>

				using namespace std;

				typedef long long LL;

				bool is_prime(int n)
				{
				    if (n == 1) return false;

				    for (int i = 2; i * i <= n; i ++ )
				        if (n % i == 0)
				            return false;
				    return true;
				}

				bool check(int n, int d)
				{
				    if (!is_prime(n)) return false;

				    LL r = 0;
				    while (n)
				    {
				        r = r * d + n % d;
				        n /= d;
				    }

				    return is_prime(r);
				}

				int main()
				{
				    int n, d;
				    while (cin >> n >> d, n >= 1)
				    {
				        if (check(n, d)) puts("Yes");
				        else puts("No");
				    }

				    return 0;
				}

				作者：yxc
				链接：https://www.acwing.com/activity/content/code/content/269922/
				来源：AcWing
				著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1. 很顺利
					#include <iostream>

					using namespace std;

					bool isprime(int n){
						if(n == 1) return false;
						for(int i = 2; i <= n / i; i++){
							if(n % i == 0) return false;
						}
						return true;
					}

					int convert(int n, int d){
						int res = 0;
						while(n){
							res = res * d + n % d;
							n /= d;
						}
						return res;
					}
					int main(){
						int n, d;
						while(cin >> n >> d, n >= 1){
							if(!isprime(n) || !isprime(convert(n, d))){
								puts("No");
								continue;
							}
							puts("Yes");
						}
						return 0;
					}
				r2.
					#include <iostream>

					using namespace std;

					bool isprime(int n){
						if(n == 1) return false;
						for(int i = 2; i <= n / i; i++) if(n % i == 0) return false;
						return true;
					}

					int convert(int n, int d){
						int res = 0;
						while(n){
							res = res * d + n % d;
							n /= d;
						}
						return res;
					}

					int main(){
						int n, d;
						while(cin >> n >> d, n >= 1){
							if(!isprime(n) || !isprime(convert(n, d))) {puts("No"); continue;}
							puts("Yes");
						}
						return 0;
					}
				r3.
				r4.
				r5.

		29. 1504. 火星颜色	1027
			0. bug
				如果不足2位,前面补足0, 例如4应该输出成04
			1. 笔记
				0. 人类的数字的最大值: 168 (对应着火星的CC = 12 * 13 + 12 = 168)
				1. 这道题方便的地方在于, 取值范围是0-168, 所以转换成13进制,肯定只有两位数, 所以我们可以/ 13, % 13
				2. 小心bug! 是 <= 9, 不是 <= '9'!
			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					char get(int x)
					{
					    if (x <= 9) return '0' + x;
					    return 'A' + x - 10;
					}

					int main()
					{
					    int a[3];
					    for (int i = 0; i < 3; i ++ ) scanf("%d", &a[i]);

					    cout << '#';

					    for (int i = 0; i < 3; i ++ ) cout << get(a[i] / 13) << get(a[i] % 13);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/269939/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>

					using namespace std;

					char get(int a){
						if(a <= 9) return a + '0'; //bug, 是 <= 9, 不是 <= '9'!
						else return a - 10 + 'A'; //记得 - 10. 映射从10~12到0~2
					}
					int main(){
						int a[3];
						for(int i = 0; i < 3; i ++) scanf("%d", &a[i]);

						cout << "#";
						for(int i = 0; i < 3; i ++) cout << get(a[i] / 13) << get(a[i] % 13);

						return 0;
					}
			3. 5次
				r1. 挺顺的
					#include <iostream>

					using namespace std;

					char print(int i){
						if(i <= 9) return i + '0';
						return i - 10 + 'A';
					}

					int main(){
						int a[3];
						cout << '#';
						for(int i = 0; i < 3; i++) {
							cin >> a[i];

							cout << print(a[i] / 13) << print(a[i] % 13);
						}

						return 0;
					}
				r2.
					#include <iostream>

					using namespace std;

					char print(int i){
						if(i <= 9) return i + '0';
						return i - 10 + 'A';
					}

					int main(){
						int a[3];

						cout << '#';
						for(int i = 0; i < 3; i++){
							cin >> a[i];
							cout << print(a[i] / 13) << print(a[i] % 13);
						}
					}
				r3.
				r4.
				r5.

		30. 1590. 火星数字 ****	1100
			0. bug
				1. r1,r2代码依旧很丑,逻辑很混乱. 对于if(line[0] <= '9'){的地球数字的情况
					我不应该先判断是否是 >= 13, 应该先判断是否 <= 12(这种才优雅)
				2. 计算从mars到earth
					int sum = 0;
					for(int i = 0; i < 25; i++){
						if(word == names[i]){
							if(i <= 12) sum += i;
							else sum += (i-12) * 13; 这里容易错, 例如mars的13, 相当于earth的十, (13-12)*13=13
						}
					}
			1. 笔记
				1. 这道题主要是输入的地方需要注意,因为格式比较复杂
					1. getchar(); getline();
						刚开始的时候,一定要把/n干掉: getchar().
						记得要读一整行,然后判断这一行是什么, 用getline(cin, xx)
						模板:
							getchar();
							string input;
							getline(cin, input);
					2. stringstream();
						用了ssin, 也就是将line可以当做我们cin的东西一个一个输出
						模板:
							stringstream ssin(input);
							string word;
							while(ssin >> word){}

						另一个:
							stringstream ssin(input);
							int num;
							ssin >> num; 
								这个就相当于把string变成int
								类似于:
									stringstream ssin(input);
									string str;
									ssin >> str;
									int num = stoi(str);

				4. 这个火星文还是很神奇的,就是前13个数字("tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"),一定是出现在火星文的个位, 后12个("tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"), 地应出现在十位
				5. get()里面小心bug, 一定记得(- 13 + 1), 因为我们是从name[13]开始,但是这个数字还要+1, 不然 0 * 13没东西..
				6. 我可以用#include <sstream>的stringstream()来自己调试!!
					#include <iostream>
					#include <sstream>

					using namespace std;

					int main(){
					    string input = 
					    "5\n29\n5\n13\nelo nov\ntam\n"; 注意,一定要写到一行
					    
					    stringstream ssin(input);
					    
					    string word;
					    while(ssin >> word) cout << word << endl;
					    
					    return 0;
					}
					输出结果就是我想要的
				7. 这道题其实并不难,只要把
					char names[][5] = {
					    "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
					    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
					};
					想象成:
						{0,1,2,..,9
							10, 20, 30, ..., 90};
				8. 其实下标还是很好判断的.
			2. 注释
				1. y
					#include <iostream>
					#include <sstream>

					using namespace std;

					char names[][5] = {
					    "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
					    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
					};

					int get(string word)
					{
					    for (int i = 0; i < 25; i ++ )
					        if (names[i] == word)
					        {
					            if (i < 13) return i;
					            return (i - 12) * 13;
					        }
					    return -1;  // 一定不会执行
					}

					int main()
					{
					    int n;
					    cin >> n;
					    getchar();

					    while (n -- )
					    {
					        string line;
					        getline(cin, line);

					        stringstream ssin(line);
					        if (line[0] <= '9')
					        {
					            int v;
					            ssin >> v;
					            if (v < 13) cout << names[v] << endl;
					            else
					            {
					                cout << names[12 + v / 13];
					                if (v % 13 == 0) cout << endl;
					                else cout << ' ' << names[v % 13] << endl;
					            }
					        }
					        else
					        {
					            int res = 0;
					            string word;
					            while (ssin >> word) res += get(word);
					            cout << res << endl;
					        }
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/269965/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>
					#include <sstream>

					using namespace std;

					char name[][5] = { //bug, 记得是char[][], 不是int[][]
						"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
					    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
					};

					int get(string word){
						for(int i = 0; i < 25; i++){
							if(word == name[i]){
								if(i <= 12) return i;
								else return (i - 13 + 1) * 13; //bug, 一定记得-13 + 1, 因为我们是从name[13]开始,但是这个数字还要+1, 不然 0 * 13没东西..
							}
						}
						return -1; //执行不到
					}

					int main(){
						int n;
						cin >> n;
						getchar(); //一定要把/n干掉

						while( n --){
						    string input;
					    	getline(cin, input); //bug, 记得要输入cin //读一整行
					    
					    	stringstream s(input);
					    
					    	if(input[0] <= '9'){ //说明是地球的文字
					    		int num = 0;
					    		s >> num; //很神奇,也就是将input,假设是string "91"变成了int 91
					    		if(num <= 12) cout << name[num] << endl;
					    		else{
					    			cout << name[12 + num / 13] << " "; //bug, 记得要+ 12, 例如13, 应该输出tam(对应的是name[13]), num / 13 == 1 
					    			if(num % 13 == 0) cout << endl; //bug!是%13, 不是/13. 例如是13, 我们就直接输出tam, 因为没有余数
					    			else cout << name[num % 13] << endl; 
					    		}
					    	}
					    	else{ //火星文
					    		
					    		//因为不确定到底会输入多少火星文,所以我们使用while
					    		int num = 0; //bug!, 我发现,如果你只是写成int num; 之后在进入这个循环的时候, num并没有置为零!!
					    		string word;
					    		while(s >> word) {
					    		    num += get(word); //一个字母, 老师通过判断是前12位还是后12位来判断是否*13
					    		}
					    		cout << num << endl;
					    
					    	}
						}

						return 0;
					}
			3. 5次
				r1. 通过了,但是代码很不优雅.
					#include <iostream>
					#include <sstream>

					using namespace std;

					char name1[][4] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
					char name2[][4] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

					int main(){
						int n;
						cin >> n;
						getchar();

						string line;
						while(n--){
							getline(cin, line);
							stringstream ssin(line);

							if(line[0] <= '9'){
								int num = stoi(line);
								if(!num){
								     cout << "tret" << endl;
								     continue;
								}
								if(num % 13 == 0) cout << name2[num / 13 - 1] << endl;
								else if (num < 13) cout << name1[num % 13-1] <<endl;
								else cout << name2[num/13-1] << " " << name1[num % 13-1] <<endl;
							}
							else{
								string word;
								int cnt = 0;
								int sum = 0;
								while(ssin >> word){
									if(word == "tret"){
										break;
									}
									for(int i = 0; i < 12 && !cnt; i++){
										if(word == name2[i]){
											sum += (i+1) * 13;
											break;
										}	
									}
									cnt = 1;
									for(int i = 0; i < 12 && cnt; i++){
										if(word == name1[i]){
											sum += (i+1);
										}
									}
								}

								cout << sum << endl;
							}
						}

						return 0;
					}
				r2. 代码依旧很丑,逻辑很混乱. 对于if(line[0] <= '9'){的地球数字的情况
						我不应该先判断是否是 >= 13, 应该先判断是否 <= 12(这种才优雅)
					#include <iostream>
					#include <sstream>

					using namespace std;

					char names[][5] = {
					    "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
					    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
					};

					int main(){
						int n;
						cin >> n;
						getchar();
						
						while(n--){
							string line; getline(cin, line);
							if(line[0] <= '9'){
								int num = stoi(line);
								bool visited = false;
								if(num == 0) {cout << names[0] << endl; continue;}
								if(num >= 13) {cout << names[num/13 - 1 + 13]; num %= 13; visited = true;}
								if(num % 13 == 0) {cout << endl; continue;}
								if(visited && num <= 12) cout << " " << names[num] << endl;
								else cout << names[num] << endl;
							}
							else{
								stringstream ssin(line);
								string word;
								int sum = 0;
								while(ssin >> word){
									for(int i = 0; i < 25; i++){
										if(word == names[i]){
											if(i <= 12){
												sum += i;
												break;
											}
											else{
												sum += (i-12)*13;
											}
										}
									}
								}
								cout << sum << endl;
							}
						}
						return 0;
					}
				r3. 很顺利,一次过,优雅简洁.
					#include <iostream>
					#include <sstream>

					using namespace std;

					char names[][5] = {
					    "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
					    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
					};

					int main(){
						int n;
						cin >> n;
						getchar();
						while(n--){
							string line;
							getline(cin, line);
							stringstream ssin(line);

							if(line[0] <= '9'){
								int num;
								ssin >> num;
								if(num <= 12) cout << names[num] << endl;
								else{
									cout << names[num / 13 - 1 + 13];
									if(num % 13 == 0) //说明没有个位数
										cout << endl;
									else	
										cout << " " << names[num % 13] << endl;
								}
							}
							else{
								string word;
								int sum = 0;
								while(ssin >> word){
									for(int i = 0; i < 25; i++){
										if(word == names[i]){
											if(i <= 12) sum += i;
											else sum += (i-12) * 13;
										}
									}
								}
								cout << sum << endl;
							}
						}
						return 0;
					}
				r4. 一次过, 优雅简洁
					#include <iostream>
					#include <sstream>

					char names[][5] = {
					    "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
					    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
					};


					using namespace std;

					int main(){
						int n;
						cin >> n;
						getchar();

						while(n--){
							string input;
							getline(cin, input);
							stringstream ssin(input);

							if(input[0] <= '9'){
								int num;
								ssin >> num;
								if(num <= 12) {cout << names[num] << endl;}
								else{
									cout << names[num/13 - 1 + 13];
									if(num % 13 == 0) cout << endl;
									else cout << " " << names[num % 13] << endl;
								}
							}
							else{
								string word;
								int sum = 0;
								while(ssin >> word){
									for(int i = 0; i < 25; i++){
										if(word == names[i]){
											if(i <= 12) sum += i;
											else sum += (i-12)*13;
										}
									}
								}
								cout << sum << endl;
							}
						}
						return 0;
					}
				r5.

		31. 1496. 普通回文数	1019
			0. bug
				1. 一般过不去,小心个例,例如 n == 0.
			1. 笔记
				这道题就是进制转换
					一般可以是int n -> vector<int> res
						while(n){
							res.push_back(n % d);
							n /= d;
						}
				其实就是求n在b进制下的数字是多少
				其实也就一行while(n) vec.push_back(n % b), n /= b, 但是如果是n==0需要特判
			2. 注释
				1. y
					#include <iostream>
					#include <vector>

					using namespace std;

					vector<int> nums;

					bool check()
					{
					    for (int i = 0, j = nums.size() - 1; i < j; i ++, j -- )
					        if (nums[i] != nums[j])
					            return false;

					    return true;
					}

					int main()
					{
					    int n, b;
					    cin >> n >> b;

					    if (!n) nums.push_back(0);
					    while (n) nums.push_back(n % b), n /= b;

					    if (check()) puts("Yes");
					    else puts("No");

					    cout << nums.back();
					    for (int i = nums.size() - 2; i >= 0; i -- ) cout << ' ' << nums[i];

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/309977/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>
					#include <vector>

					using namespace std;

					vector<int> nums;

					bool check()
					{
					    for (int i = 0, j = nums.size() - 1; i < j; i ++, j -- ) 两个指针
					        if (nums[i] != nums[j])
					            return false;

					    return true;
					}

					int main()
					{
					    int n, b;
					    cin >> n >> b;

					    if (!n) nums.push_back(0); 如果不写这一句, N == 0的时候, 下一句while(0)不走, nums会是空的, 所以会是segmentfault
					    while (n) nums.push_back(n % b), n /= b;

					    if (check()) puts("Yes");
					    else puts("No");

					    cout << nums.back();
					    for (int i = nums.size() - 2; i >= 0; i -- ) cout << ' ' << nums[i];

					    return 0;
					}

			3. 5次
				r1.
					#include <iostream>
					#include <vector>

					using namespace std;

					bool isp(vector<int> res){
						for(int i = 0, j = res.size()-1 ; i < j; i++, j--) if(res[i] != res[j]) return false;
						return true;
					}

					int main(){
						int n, d;
						cin >> n >> d;

					    vector<int> res;
					    if(!n) res.push_back(n);
						while(n){
							res.push_back(n % d);
							n /= d;
						}
						if(isp(res)) puts("Yes");
						else puts("No");

						cout << res[res.size()-1];
						for(int i = res.size()-2 ; i >= 0; i--) cout << " " << res[i];

						return 0;

					}
				r2.
					#include <iostream>
					#include <vector>

					using namespace std;

					bool isp(vector<int> res){
						for(int i = 0, j = res.size()-1; i < j; i++, j--) if(res[i] != res[j]) return false;
						return true;
					}
					int main()
					{
						int n, d;
						cin >> n >> d;

						vector<int> res;
						if(!n) res.push_back(n);
						else{
							while(n){
								res.push_back(n % d);
								n /= d;
							}
						}

						if(isp(res)) puts("Yes");
						else puts("No");

						cout << res[res.size()-1];
						for(int i = res.size()-2; i >= 0; i--) cout << " " << res[i];

						cout << endl;
						return 0;
					}
				r3.
				r4.
				r5.

4. 排序(这个专题的题目都还挺简单的)
	7. 2020年10月6日12:26:17
		32. 1484. 最佳排名	1012
			0. bug(很多bug)
				-1. 有时候真的是自己的逻辑出了问题!!
					例如, 我要求出最小的rank, 初始的时候应该是rank = 人数 + 1
					但是我错写成了Rank = 5. 因为我觉得只有4门课..
				0. round()在cmath
				1. 注意排名的问题
					如果用sort()的方法, sort的结果是成绩大的在右侧, 也就是第一名在右侧
					int get_rank(vector<int>& a, int x)
						{
						    int l = 0, r = a.size() - 1;
						    while (l < r)
						    {
						        int mid = l + r + 1 >> 1;
						        if (a[mid] <= x) l = mid;
						        else r = mid - 1;
						    }
						    return a.size() - r; 为什么是这个? 因为
						    	假设r = a.size() - 1. 说明是最后一个, 也就是第一名
						    	所以 - 1 就是第一名
						}
				2. 因为题目说的是, 如果几个排名相同, 那么就按照 a > c > m > e来输出
					所以我们村的时候, 最好是grade[0]存average. 这样更新rank的时候就可以保持average的优先级
					for (int i = 0; i < 4; i ++ )
		            {
		                int rank = get_rank(q[i], grades[id][i]);
		                if (rank < res)
		                {
		                    res = rank;
		                    c = names[i];
		                }
		            }
		        3. 老是犯的错误:
		        	就是For(int j = ...) { g[i] ...} 应该是g[j]
		        4. 思路上容易犯的错误:
		        	1. 我可能会比较一个学生的最高分, 然后找到这个最高分是该科目的第几名
		        		这是错误的
		        	2. 为什么错?
		        		假设一个学生的成绩是 40, 90, 91, 93
		        		但是可能的是, 91的那个科目, 这个学生是第10名
		        		但是40的那个科目, 学生是第1名
		        	3. 所以正确的做法:
		        		遍历所有的成绩, 看这个成绩在那个科目的排名
		        		例如,得到的结果是1, 5, 10, 4
		        		那么就输出1 
			1. 笔记
				数据结构
					unordered_map<string, vector<int>> students; 每个学生 + 该学生的4个成绩
					vector<int> grades[4]; vector数组, 4个vector<int>, 分别存4个成绩
				求rank
					1. 用二分
						记得sort(), 然后看是二分的哪个模板
						用二分的情况适用于, 只给了我一个数字, 让我求出在数组中的rank
					2. 用if(xx[i] != xx[i-1])
						适用于批量求每个元素在数组中的rank
				思路
					1. 需要将id,3门成绩,平均分存到一个用户结构体
					2. 然后将c成绩放到一个数组, 其他类似,所以一共有4个数组
					3. 将四个数组排序
					4. 看某个用户,它的四个成绩,在四个数组里面的排名,min求出最小排名

			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>
					#include <vector>
					#include <cmath>

					using namespace std;

					unordered_map<string, vector<int>> grades;
					vector<int> q[4];  // A: q[0], C: q[1], M: q[2], E: q[3]

					int get_rank(vector<int>& a, int x)
					{
					    int l = 0, r = a.size() - 1;
					    while (l < r)
					    {
					        int mid = l + r + 1 >> 1;
					        if (a[mid] <= x) l = mid;
					        else r = mid - 1;
					    }
					    return a.size() - r;
					}

					int main()
					{
					    int n, m;
					    cin >> n >> m;

					    for (int i = 0; i < n; i ++ )
					    {
					        string id;
					        int t[4] = {0};
					        cin >> id;
					        for (int j = 1; j < 4; j ++ )
					        {
					            cin >> t[j];
					            t[0] += t[j];
					        }
					        t[0] = round(t[0] / 3.0);
					        for (int j = 0; j < 4; j ++ )
					        {
					            q[j].push_back(t[j]);
					            grades[id].push_back(t[j]);
					        }
					    }

					    for (int i = 0; i < 4; i ++ ) sort(q[i].begin(), q[i].end());

					    char names[] = "ACME";
					    while (m -- )
					    {
					        string id;
					        cin >> id;
					        if (grades.count(id) == 0) puts("N/A");
					        else
					        {
					            int res = n + 1;
					            char c;
					            for (int i = 0; i < 4; i ++ )
					            {
					                int rank = get_rank(q[i], grades[id][i]);
					                if (rank < res)
					                {
					                    res = rank;
					                    c = names[i];
					                }
					            }
					            cout << res << ' ' << c << endl;
					        }
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/272589/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>
					#include <algorithm> //sort()
					#include <vector>
					#include <cmath> //round()
					#include <unordered_map>

					using namespace std;

					unordered_map<string, vector<int>> students;
					vector<int> grade[4]; //相当于是二维数组

					int get_rank(int g, vector<int> &grades){ //这里用了引用&,所以会快
					    int l = 0, r = grades.size()-1;

					    while(l < r){
					        int mid = 1 + l + (r-l) / 2;
					        if(grades[mid] <= g) l = mid; //靶子是g,我们希望我们的探测点是在所有 <= g的部分
					        else r = mid - 1;
					    }

					    return grades.size() - r; //r左侧一共有r个元素,数组一共有size()个元素,所以r包括自己是grades.size() - r. //假设是第一名, r会 == grades.size()- 1, 所以刚号 return 1;

					}
					int main()
					{
					    int n, m;
					    cin >> n >> m;

					    for(int i = 0; i < n ;i ++){//不用while(n --),因为后面还会用到n
					        string id;
					        cin >> id;

					        int g[4] = {0}; //记得初始化, 用这个数组就不用写 cin >> a >> c >> m >> e这么麻烦了

					        //填写要插入到unordered_map<string, vector<int>> 中的vector<int>的内容
					        //vector<int>中 A:[0], C:[1], M:[2], E:[3]
					        //这里是将id同学的所有3个成绩输入到g[i]中,然后计算平均值
					        for(int i = 1; i < 4; i++){
					            cin >> g[i]; //例如i==1的时候,输入的是c
					            g[0] += g[i];
					        }

					        g[0] = round(g[0] / 3.0); //四舍五入,向上取整是ceil()

					        //将4个成绩,分别插入student,和grade
					        //注意: 我之前以为是一次性插入student[id].push_back({g[0],g[1],...})//其实也可以一个一个插入
					        //这里grade[i] = g[i], 用i作为连接
					        for(int i = 0; i < 4; i++){
					            grade[i].push_back(g[i]);
					            students[id].push_back(g[i]);
					        }
					    }

					    //目前为止grade[0]是所有同学的a成绩, grade[1]是所有同学的c成绩
					    //students[id]是id同学的acme成绩

					    //四门成绩,都要sort一遍,最大成绩在最右侧
					    for(int i = 0; i < 4 ; i ++) sort(grade[i].begin(), grade[i].end());

					    //看要哪个id
					    char names[] = "ACME"; //注意这里是char[]
					    while(m --){
					        string request;
					        cin >> request;

					        if(students.count(request) == 0) {
					            cout << "N/A" << endl;
					            continue;
					        }

					        string best_course;
					        int best_rank = n + 1; //因为有n个学生
					        for(int i = 0; i < 4; i++){
					            int rank = get_rank(students[request][i], grade[i]); //找request学生的i成绩在i成绩单里面的排名
					            if(rank < best_rank) 
					            {
					                best_rank = rank;
					                best_course = names[i];
					            }
					        }

					        cout << best_rank << " " << best_course << endl;
					    }

					    return 0;


					}

					作者：jackrrr
					链接：https://www.acwing.com/activity/content/code/content/485178/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <vector>
					#include <cmath>
					#include <algorithm>

					using namespace std;

					unordered_map<string, vector<int>> students;
					vector<int> grades[4];

					int main(){
						int n, q;
						cin >> n >> q;
						for(int i = 0; i < n ;i ++){
							string id;
							cin >> id;
							int g[4];
							int sum = 0;
							for(int j = 1; j <= 3; j ++) 
							{
								cin >> g[j];
								sum += g[j];
							}
							g[0] = round(sum / 3.0);

							for(int j = 0; j < 4; j++){
								grades[j].push_back(g[j]);
								students[id].push_back(g[j]);
							}
						}

						for(int i = 0; i < 4; i++) 
							sort(grades[i].begin(), grades[i].end());

						char name[5] = "ACME";
						for(int i = 0; i < q; i ++){
							string id;
							cin >> id;
					// 		cout << "hi " << i << " " << id << endl;
							
							if(students.count(id) == 0){
								puts("N/A");
								continue;
							}
							int rank = n + 1;
							char res = name[0];
							auto s = students[id];
							for(int j = 0; j < 4; j++){
								int g = s[j];
								int l = 0, r = n - 1;
								while(l < r){
									int mid = l + (r-l)/2 + 1;
									if(grades[j][mid] <= g) l = mid;
									else r = mid - 1;
								}
								int temp = n - l;
								if(rank > temp){
								    rank = temp;
								    res = name[j];
								}
							}
							cout << rank << " " << res << endl; 
							
						}
						return 0;
					}
				r2.
					#include <iostream>
					#include <vector>
					#include <cmath>
					#include <algorithm>

					using namespace std;

					unordered_map<string, vector<int>> students;
					vector<int> grades[4];

					int get(int g, vector<int> &grade){
						int l = 0, r = grade.size() - 1;
						while(l < r){
							int mid = l + (r-l) / 2 + 1;
							if(grade[mid] <= g) l = mid;
							else r = mid - 1;
						}
						return grade.size() - l;
					}

					int main(){

						int n, m;
						cin >> n >> m;

						for(int i = 0; i < n ; i++){
							string id;
							cin >> id;
							int g[4];
							int sum = 0;
							for(int j = 1; j < 4; j++){
								cin >> g[j];
								sum += g[j];
							}
							g[0] = round(sum / 3.0);

							for(int j = 0; j < 4; j++){
								grades[j].push_back(g[j]);
								students[id].push_back(g[j]);
							}
						}

						for(int i = 0; i < 4 ; i++) sort(grades[i].begin(), grades[i].end());

						for(int i = 0; i < m ; i++){
							string id;
							cin >> id;
							if(students.count(id) == 0){
								puts("N/A");
								continue;
							}

							auto s = students[id];
							char name[5] = "ACME";
							int rank = n + 1;
							char res = name[0];
							for(int j = 0; j < 4; j ++){
								int g = s[j];
								int temp = get(g, grades[j]);
								if(temp < rank){
									rank = temp;
									res = name[j];
								}
							}
							cout << rank << " " << res << endl;
						}
						return 0;
					}
				r3.
					#include <iostream>
					#include <vector>
					#include <cmath>
					#include <algorithm>

					using namespace std;

					unordered_map<string, vector<int>> students;
					vector<int> grades[4];

					int get(int g, vector<int>& grades){
						int l = 0, r = grades.size()-1;
						while(l < r){
							int mid = l +(r-l) / 2 + 1;
							if(grades[mid] <= g) l = mid;
							else r = mid - 1;
						}
						return grades.size() - r;
					}

					int main(){
						int n, m;
						cin >> n >> m;

						for(int i = 0; i < n; i++){
							string id;
							cin >> id;
							int g[4];
							int sum = 0;
							for(int j = 1; j < 4; j++){
								cin >> g[j];
								sum += g[j];
							}
							g[0] = round(sum / 3.0);

							for(int j = 0; j < 4; j ++){
								grades[j].push_back(g[j]);
								students[id].push_back(g[j]);
							}
						}

						for(int i = 0; i < 4; i ++) sort(grades[i].begin(), grades[i].end());

						for(int i = 0; i < m ; i++){
							string id;
							cin >> id;
							if(students.count(id) == 0){
								puts("N/A");
								continue;
							}

							auto s = students[id];

							char names[5] = "ACME";
							int rank = n + 1;
							char res = names[0];

							for(int j = 0; j < 4; j++){
								int g = s[j];
								int temp = get(g, grades[j]);
								if(temp < rank){
									rank = temp;
									res = names[j];
								}
							}

							cout << rank << " " << res << endl;


						}
					}
				r4.
					#include <iostream>
					#include <cmath>
					#include <vector>
					#include <algorithm>

					using namespace std;

					unordered_map<string, vector<int>> students;
					vector<int> grades[4];

					int main(){
						int n, m;
						cin >> n >> m;

						for(int i = 0; i < n; i++){
							string id;
							cin >> id;

							int g[4];
							int sum = 0;
							for(int j = 1; j < 4; j ++){
								cin >> g[j];
								sum += g[j];
							}
							g[0] = round(sum / 3.0);

							for(int j = 0 ; j < 4; j++){
								grades[j].push_back(g[j]);
								students[id].push_back(g[j]);
							}
						}
						
						for(int i = 0; i < 4; i++) sort(grades[i].begin(), grades[i].end());
						
						while(m --){
							string id;
							cin >> id;
							if(students.count(id) == 0){
								puts("N/A");
								continue;
							}

							auto s = students[id];
							int rank = 2010;
							char names[5] = "ACME";
							char res = names[0];

							for(int i = 0; i < 4; i++){
								int g = s[i];
								auto grade = grades[i];

								int l = 0, r = grade.size()-1;
								while(l < r){
									int mid = l + (r-l)/2 + 1;
									if(grade[mid] <= g) l = mid;
									else r = mid - 1;
								}
								int temp = grade.size() - r;
								if(temp < rank){
									rank = temp;
									res = names[i];
								}
							}

							cout << rank << " " << res << endl;
						}
						return 0;
					}
				r5.
					#include <iostream>
					#include <cmath>
					#include <algorithm>
					#include <vector>

					using namespace std;

					unordered_map<string, vector<int>> students;
					vector<int> grades[4];

					int main(){
						int n, m;
						cin >> n >> m;

						for(int i = 0; i < n; i ++){
							string id;
							cin >> id;

							int g[4];
							int sum = 0;
							for(int j = 1; j < 4; j ++){
								cin >> g[j];
								sum += g[j];
							}
							g[0] = round(sum / 3.0);

							for(int j = 0; j < 4; j++){
								grades[j].push_back(g[j]);
								students[id].push_back(g[j]);
							}
						}
						
						for(int i = 0; i < 4; i++) sort(grades[i].begin(), grades[i].end());

						while(m--){
							string id;
							cin >> id;

							if(students.count(id) == 0){
								puts("N/A");
								continue;
							}

							auto s = students[id];
							int rank = 2020;
							char names[5] = "ACME";
							char res = names[0];
							for(int i = 0; i < 4; i ++){
								int g = s[i];
								auto grade = grades[i];

								int l = 0, r = grade.size() - 1;
								while(l < r){
									int mid = l + (r-l) /2 + 1;
									if(grade[mid] <= g) l = mid;
									else r = mid - 1;
								}
								int temp = grade.size() - r;
								if(temp < rank){
									rank = temp;
									res = names[i];
								}
							}

							cout << rank << " " << res << endl;
						}
						return 0;
					}

	8. 2020年10月7日13:26:46
		33. 1499. 数字图书馆	1022
			0. bug
				1. 题目输出的时候,要求按升序顺序排列。
					所以一定要sort
				2. 如果要在 while 里面使用 getline() 一定注意, 把 getchar() 放在 while 外面
				3. 如果TLE
					1. 检查: cout 变成 printf()
					2. 检查: for(auto x : xxx) 变成 for(auto &x : xxx)
			1. 笔记
				思路:
					1. 这道题主要是输入和输出
					2. 老师用的是遍历的方法,就是如果题目要求符合xx条件的,老师写的代码会遍历所有用户看他是否有xx条件
						1. 这个的复杂度M*N, M个请求, N个用户, 总之不超时

					1. 是用vector<Book>, 而不是struct Book{}books[N]; 是因为不确定N
					2. 没有设置成unordered_map<string(也就是id), Book>, 好像也没必要,因为题目不会问我们某某id的情况,而是让我们返回id


					1. 小心bug, while()里面不能出现getchar().

			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>
					#include <set>
					#include <vector>
					#include <sstream>

					using namespace std;

					struct Book
					{
					    string id, name, author;
					    set<string> keywords;
					    string publisher, year;
					};

					int main()
					{
					    int n, m;
					    cin >> n;

					    vector<Book> books;
					    while (n -- )
					    {
					        string id, name, author;
					        cin >> id;
					        getchar();
					        getline(cin, name), getline(cin, author);
					        string line;
					        getline(cin, line);
					        stringstream ssin(line);
					        string keyword;
					        set<string> keywords;
					        while (ssin >> keyword) keywords.insert(keyword);
					        string publisher, year;
					        getline(cin, publisher);
					        cin >> year;
					        books.push_back({id, name, author, keywords, publisher, year});
					    }

					    cin >> m;
					    getchar();
					    string line;
					    while (m -- )
					    {
					        getline(cin, line);
					        cout << line << endl;
					        string info = line.substr(3);
					        char t = line[0];
					        vector<string> res;
					        if (t == '1')
					        {
					            for (auto& book : books)
					                if (book.name == info)
					                    res.push_back(book.id);
					        }
					        else if (t == '2')
					        {
					            for (auto& book : books)
					                if (book.author == info)
					                    res.push_back(book.id);
					        }
					        else if (t == '3')
					        {
					            for (auto& book : books)
					                if (book.keywords.count(info))
					                    res.push_back(book.id);
					        }
					        else if (t == '4')
					        {
					            for (auto& book : books)
					                if (book.publisher == info)
					                    res.push_back(book.id);
					        }
					        else
					        {
					            for (auto& book : books)
					                if (book.year == info)
					                    res.push_back(book.id);
					        }

					        if (res.empty()) puts("Not Found");
					        else
					        {
					            sort(res.begin(), res.end());
					            for (auto id : res) cout << id << endl;
					        }
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/272621/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>
					#include <sstream>
					#include <vector>
					#include <algorithm> //sort()
					#include <set> //set<string> keywords

					using namespace std;

					struct Book{
					    string id;
					    string title;
					    string author;
					    set<string> keywords;
					    string publisher;
					    string year;
					};
					int main(){
					    int n;
					    cin >> n;

					    vector<Book> books;
					    for(int i = 0; i < n; i ++){
					        string id;
					        cin >> id;

					        //以下是存在空格的,所以统一用getline()
					        string title, author, keyword, publisher;
					        getchar(); //读上一次的\n回车
					        getline(cin, title);
					        getline(cin, author);
					        getline(cin , keyword);
					        getline(cin, publisher);

					        string year;
					        cin >> year;

					        set<string> keywords;
					        stringstream kwcin(keyword);
					        string kw;
					        while( kwcin >> kw) keywords.insert(kw);

					        books.push_back({id, title, author, keywords, publisher, year});
					    }

					    int m;
					    cin >> m;
					    getchar(); //getchar()应该出现一次,而不是出现在while里面,因为
					    while(m --){

					        string input; //因为input的格式有空格(2: Yue Chen),所以需要getline()
					        //getchar(); //把\n读了, bug!! 不能每次都getchar()!!, 如果while里面出现getchar(),会发生第一个字符没了, 也就是本应是:"1: xxx", 但现在只剩": xxx""
					        getline(cin, input); //会把\n也读了,所以后面不需要getchar();
					        cout << input << endl;

					        string content = input.substr(3); //我们需要的是从ind==3开始的字符: Yue Chen
					        char request = input[0]; //如果是1, 说明要查title //bug, 注意是char, 不是string

					        vector<string> res; //把所有结果的id都存在vector里面
					        if(request == '1'){
					            for(auto& b : books){ //注意我们用的是auto&, 而不是auto, 因为books式结构体,复制的话太慢,引用快
					                if(b.title == content)
					                    res.push_back(b.id); //存的是b书的id
					            }
					        }
					        else if(request == '2'){
					            for(auto& b : books){
					                if(b.author == content)
					                    res.push_back(b.id); //存的是b书的id
					            }
					        }
					        else if(request == '3'){
					            for(auto& b : books){
					                if(b.keywords.count(content)) //这里是看b书的keyword包不包含content
					                    res.push_back(b.id); //存的是b书的id
					            }
					        }
					        else if(request == '4'){
					            for(auto& b : books){
					                if(b.publisher == content)
					                    res.push_back(b.id); //存的是b书的id
					            }
					        }
					        else{
					            for(auto& b : books){
					                if(b.year == content)
					                    res.push_back(b.id); //存的是b书的id
					            }
					        }

					        if(res.empty()) cout << "Not Found" << endl;
					        else {
					            sort(res.begin(), res.end());//对id排序
					            for(auto id : res) cout << id << endl;
					        }
					    }

					    return 0;
					}

					作者：jackrrr
					链接：https://www.acwing.com/activity/content/code/content/485312/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <sstream>
					#include <set>
					#include <algorithm>

					using namespace std;

					struct Book{
						string id, name, author;
						set<string> keywords;
						string publisher;
						string year;
					};

					vector<Book> books;

					int main(){
						int n;
						cin >> n;

						while(n--){
							string id;
							cin >> id;

							string name;
							getchar();
							getline(cin, name);

							string author;
							getline(cin, author);

							set<string> temp;
							string read; 
							getline(cin, read);
							stringstream ssin(read);
							string word;
							while(ssin >> word){
								temp.insert(word);
							}

							string publisher;
							getline(cin, publisher);

							string year;
							cin >> year;

							books.push_back({id, name, author, temp, publisher, year});
						}

						cin >> n;
						getchar();

						while(n--){
							string line;
							getline(cin, line);
							cout << line << endl;

							char a = line[0];
							string cmd = line.substr(3);
							vector<string> res;
							if(a == '1'){
								for(auto &b : books){
									if(b.name == cmd){
										res.push_back(b.id);
									}
								}
							}
							else if(a == '2'){
								for(auto &b : books){
									if(b.author == cmd){
										res.push_back(b.id);
									}
								}
							}
							else if(a == '3'){
								for(auto &b : books){
									if(b.keywords.count(cmd)){
										res.push_back(b.id);
									}
								}
							}
							else if(a == '4'){
								for(auto &b : books){
									if(b.publisher == cmd){
										res.push_back(b.id);
									}
								}
							}
							else{
								for(auto &b : books){
									if(b.year == cmd){
										res.push_back(b.id);
									}
								}
							}

							if(res.empty()) puts("Not Found");
							else{
							    sort(res.begin(), res.end());
								for(auto i : res){
									cout << i << endl;
								}
							}
						}

						return 0;


					}
				r2.
					#include <iostream>
					#include <vector>
					#include <sstream>
					#include <set>
					#include <algorithm>

					using namespace std;

					struct Book{
						string id, title, author;
						set<string> keywords;
						string publisher, year;
					};

					vector<Book> books;

					int main(){
						int n, m;
						cin >> n;
						while(n--){
							string id;
							cin >> id;
							string title, author;
							getchar();
							getline(cin, title), getline(cin, author);
							string line;
							getline(cin, line);
							stringstream ssin(line);
							string keyword;
							set<string> keywords;
							while(ssin >> keyword) keywords.insert(keyword);
							string publisher;
							getline(cin, publisher);
							string year;
							cin >> year;

							books.push_back({id, title, author, keywords, publisher, year});
						}

						cin >> m;
						getchar();
						
						while(m--){
							string line;
							getline(cin, line);
							cout << line << endl;

							char type = line[0];
							string cmd = line.substr(3);
							vector<string> res;
							if(type == '1'){
								for(auto &b : books){
									if(b.title == cmd) res.push_back(b.id);
								}
							}
							else if(type == '2'){
								for(auto &b : books){
									if(b.author == cmd) res.push_back(b.id);
								}
							}
							else if(type == '3'){
								for(auto &b : books){
									if(b.keywords.count(cmd)) res.push_back(b.id);
								}
							}
							else if(type == '4'){
								for(auto &b : books){
									if(b.publisher == cmd) res.push_back(b.id);
								}
							}
							else{
								for(auto &b : books){
									if(b.year == cmd) res.push_back(b.id);
								}
							}

							if(res.empty()) puts("Not Found");
							else{
								sort(res.begin(), res.end());
								for(auto i : res) cout << i << endl;
							}
						}

						return 0;
					}
				r3. 挑战 https://www.acwing.com/problem/content/submission/code_detail/2577028/
					#include <iostream>
					#include <vector>
					#include <set>
					#include <sstream>
					#include <algorithm>

					using namespace std;

					struct Book{
					    string id, title, author;
					    set<string> keywords;
					    string publisher, year;
					};

					vector<Book> books;

					int main(){
					    
					    int n, m;
					    cin >> n;
					    while(n --){
					        string id;
					        cin >> id;
					        string title;
					        getchar();
					        getline(cin, title);
					        string author;
					        getline(cin, author);
					        string line;
					        getline(cin, line);
					        stringstream ssin(line);
					        string word;
					        set<string> keywords;
					        while(ssin >> word) keywords.insert(word);
					        string publisher;
					        getline(cin, publisher);
					        string year;
					        cin >> year;
					        books.push_back({id, title, author, keywords, publisher, year});
					    }
					    
					    cin >> m;
					    getchar();
					    while(m--){
					        string line;
					        getline(cin, line);
					        cout << line << endl;
					        
					        char t = line[0];
					        string cmd = line.substr(3);
					        vector<string> res;
					        if(t == '1'){
					            for(auto &b : books){
					                if(b.title == cmd) res.push_back(b.id);
					            }
					        }
					        else if(t == '2'){
					            for(auto &b : books){
					                if(b.author == cmd) res.push_back(b.id);
					            }
					        }
					        else if(t == '3'){
					            for(auto &b : books){
					                if(b.keywords.count(cmd)) res.push_back(b.id);
					            }
					        }
					        else if(t == '4'){
					            for(auto &b : books){
					                if(b.publisher == cmd) res.push_back(b.id);
					            }
					        }
					        else{
					            for(auto &b : books){
					                if(b.year == cmd) res.push_back(b.id);
					            }
					        }
					        
					        if(res.empty()) puts("Not Found");
					        else{
					            sort(res.begin(), res.end());
					            for(auto i : res) cout << i << endl;
					        }
					    }
					    
					    return 0;
					    
					}
				r4.
				r5.

		34. 1502. PAT 排名	1025
			0. bug
			1. 笔记
				思路1, by y
					其实更简单,不像我那样,分成了两个部分.而是直接在grade里面处理
						他依赖的一个性质: 最终要求要按照final_rank排名,这等价于按照grade排名
					1. 读取student的内容(创建student struct,因为复杂的内容用struct处理会简单一些)
					2. 创建n个分地区的vector,vector<stduent> local[N]
					3. 创建1个总地区vecotr, vector<student> all;
					4. 每次读取就分别向分和总插入(主义是分地区加工后,再加入总地区),分插入的时候按照ind来索引是哪个local[N]
					5. 对分总排序.
					6. 老师最后的计算排名的方法:
						1. 假设是	0	1	2	3	4	5
						2. 			100 99 	99	99	98	98
						3. 排名		1	2	2	2	3	3
						方法: 从0开始,假设不等于左侧:排名就是自己的ind+1, 如果等于左侧:就是左侧的排名

					7. 关于重载标志服
					    1. 只需要思考, 返回我优先: 因为我的grade大我优先, 所以return grade > t.grade
					    2. 只需要思考, 返回我优先: 因为我的id小我优先, 所以return id < t.id
					8. 其实没有我设想的vector<student> studnets; 创建了一个学生的vecotor,而都是地区的vector
					9. 所以其实是一个学生的信息其实是复制了两次,一次给了local地区一个是global地区
					10. 易错,我们是local进行加工之后,然后将id, grade, location, local_rank加入总
					11. 最后是从总来打印
					12. 
				思路2, byb
					1. 我用了4个数组:
						vector<Student> students[N]; N个考场中的student
						vector<Student> allS;	所有students
						vector<int> local_grade[N];	N个考场的grade
						vector<int> final_grade;	所有grade
					2. 然后用了二分法, 就是先sort()grade, 然后遍历所有的student, 将每个s的成绩 看是sort之后的grade里面的第几名
			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>
					#include <vector>

					using namespace std;

					const int N = 110;

					struct Student
					{
					    string id;
					    int grade;
					    int location_number, local_rank, final_rank;

					    bool operator< (const Student& t) const
					    {
					        if (grade != t.grade) return grade > t.grade;
					        return id < t.id;
					    }
					};

					vector<Student> grades[N];
					vector<Student> all;

					int main()
					{
					    int n;
					    cin >> n;
					    for (int i = 1; i <= n; i ++ )
					    {
					        int k;
					        cin >> k;
					        for (int j = 0; j < k; j ++ )
					        {
					            string id;
					            int grade;
					            cin >> id >> grade;
					            grades[i].push_back({id, grade, i});
					        }

					        auto& g = grades[i];
					        sort(g.begin(), g.end());
					        for (int i = 0; i < g.size(); i ++ )
					        {
					            if (!i || g[i].grade != g[i - 1].grade)
					                g[i].local_rank = i + 1;
					            else
					                g[i].local_rank = g[i - 1].local_rank;
					            all.push_back(g[i]);
					        }
					    }

					    sort(all.begin(), all.end());
					    for (int i = 0; i < all.size(); i ++ )
					        if (!i || all[i].grade != all[i - 1].grade)
					            all[i].final_rank = i + 1;
					        else
					            all[i].final_rank = all[i - 1].final_rank;

					    cout << all.size() << endl;
					    for (auto& s : all)
					        cout << s.id << ' ' << s.final_rank << ' ' << s.location_number << ' ' << s.local_rank << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/272643/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>
					#include <algorithm> //sort
					#include <vector>

					using namespace std;

					const int N = 110; //最多100个地区
					const int M = 310; //每个地区最多300人

					//构建student
					struct Student{
					    string id;
					    int grade;
					    int location;
					    int local_rank;
					    int global_rank;

					    bool operator< (const Student& t) const{ //用于sort()的时候比较Student
					        if(grade != t.grade) return grade > t.grade; //返回的是我优先,如果我的grade大的话,就是我优先
					        else return id < t.id; //返回的是我优先
					    }
					};

					vector<Student> local[N]; //不能写成vector<int> local[N], 因为我们在sort()的时候不单单要
					vector<Student> global;

					int main(){
					    int n;
					    cin >> n;

					    for(int i = 0; i < n; i ++){ //这里的i可以当做地区名
					        int m;
					        cin >> m;
					        while(m--){
					            string id;
					            int g;
					            cin >> id >> g;
					            local[i].push_back({id, g, i + 1}); //后面的会自动补齐,也就是0, 注意: 地区编号按输入顺序依次为 1∼N
					        }

					        //加下来对i地区的人进行排名,然后local_rank记录进去
					        auto& l = local[i]; //l是vector<Student>
					        sort(l.begin(), l.end()); //这里会用到标志服重载,所以grade大的,id小的在前面
					        for(int j = 0; j < l.size(); j++){
					            if(!j || l[j].grade != l[j-1].grade)
					                l[j].local_rank = j+1;
					            else
					                l[j].local_rank = l[j-1].local_rank;

					            global.push_back(l[j]);//因为最后需要全部内容打印, 所以我们将global存了全部内容
					            //注意,这里不是push_back({id, grade, local_rank}), 而是直接将l[j], 也就是一个studnet插入了里面
					        }
					    }

					    sort(global.begin(), global.end());
					    for(int j = 0; j < global.size(); j++){
					            if(!j || global[j].grade != global[j-1].grade)
					                global[j].global_rank = j+1;
					            else
					                global[j].global_rank = global[j-1].global_rank;
					    }

					    //目前为止,global里面的每个学生,拥有了global_rank,然后global本身的排序也是题目要的
					    cout << global.size() << endl;
					    for(auto& s : global){
					        cout << s.id << " " << s.global_rank <<" " << s.location << " " << s.local_rank << endl;
					    }

					    return 0;
					}

					作者：jackrrr
					链接：https://www.acwing.com/activity/content/code/content/485385/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

			3. 5次
				r1. 很顺利
					#include <iostream>
					#include <algorithm>
					#include <vector>

					using namespace std;

					const int N = 110;

					struct Student{
						string id;
						int grade;
						int loc;
						int local_rank;
						int final_rank;

						bool operator< (const Student& t) const{
							if(final_rank != t.final_rank) return final_rank < t.final_rank;
							return id < t.id;
						}
					};

					vector<Student> students[N];
					vector<Student> allS;
					vector<int> local_grade[N];
					vector<int> final_grade;

					int get(int g, vector<int> &grades){
						int l = 0, r = grades.size()-1;
						while(l < r){
							int mid = l + (r-l)/2 + 1;
							if(grades[mid] <= g) l = mid;
							else r = mid - 1;
						}
						return grades.size() - r;
					}

					int main(){
						int n;
						cin >> n;
						for(int i = 1; i <= n; i++){
							int num;
							cin >> num;
							while(num --){
								string id;
								int grade;
								cin >> id >> grade;

								students[i].push_back({id, grade, i});
								local_grade[i].push_back(grade);
								final_grade.push_back(grade);
							}

							sort(local_grade[i].begin(), local_grade[i].end());
							for(auto &s : students[i]){
								s.local_rank = get(s.grade, local_grade[i]);
								allS.push_back(s);
							}
						}

						sort(final_grade.begin(), final_grade.end());
						for(auto &s : allS){
							s.final_rank = get(s.grade, final_grade);
						}

						sort(allS.begin(), allS.end());
						cout << allS.size() << endl;
						for(auto &s : allS){
							cout << s.id << " " << s.final_rank << " " << s.loc << " " << s.local_rank << endl;
						}

						return 0;
					}
				r2.
					#include <iostream>
					#include <vector>
					#include <algorithm>


					using namespace std;

					const int N = 210;


					struct Student{
					    string id;
					    int grade;
					    int location;
					    int local_rank;
					    int final_rank;
					    
					    bool operator< (const Student& t) const{
					        if(final_rank != t.final_rank) return final_rank < t.final_rank;
					        return id < t.id;
					    }
					};

					vector<Student> students[N];
					vector<Student> allS;
					vector<int> grades[N];
					vector<int> allG;

					int get(int g, vector<int> &grades){
					    int l = 0, r = grades.size()-1;
					    while(l < r){
					        int mid = l + (r-l)/2 + 1;
					        if(grades[mid] <= g) l = mid;
					        else r = mid - 1;
					    }
					    return grades.size() - r;
					}

					int main(){
					    int n;
					    cin >> n;
					    for(int i = 1; i <= n; i++){
					        int m;
					        cin >> m;
					        while(m--){
					            string id;
					            int g;
					            cin >> id >> g;
					            students[i].push_back({id, g, i});
					            grades[i].push_back(g);
					            allG.push_back(g);
					        }
					        
					        sort(grades[i].begin(), grades[i].end());
					        for(auto &s : students[i]){
					            s.local_rank = get(s.grade, grades[i]);
					            allS.push_back(s);
					        }
					    }
					    
					    sort(allG.begin(), allG.end());
					    for(auto &s : allS ){
					        s.final_rank = get(s.grade, allG);
					    }
					    
					    sort(allS.begin(), allS.end());
					    cout << allS.size() << endl;
					    for(auto &s : allS) cout << s.id << " " << s.final_rank << " " << s.location << " " <<s.local_rank << endl;

					    
					    return 0;
					}
				r3.
					#include <iostream>
					#include <vector>
					#include <algorithm>

					const int N = 210;

					using namespace std;

					struct Student{
					    string id;
					    int grade, location, local_rank, final_rank;
					    
					    bool operator< (const Student& t) const{
					        if(grade != t.grade) return grade > t.grade;
					        return id < t.id;
					    }
					};

					vector<Student> students[N];
					vector<Student> allS;

					int main(){
					    int n;
					    cin >> n;
					    for(int i = 1; i <= n; i++){
					        int m;
					        cin >> m;
					        while(m--){
					            string id;
					            int grade;
					            cin >> id >> grade;
					            students[i].push_back({id, grade, i});
					        }
					        
					        sort(students[i].begin(), students[i].end());
					        for(size_t j = 0, rank = 1; j < students[i].size(); j++){
					            if(j && students[i][j].grade != students[i][j-1].grade) rank = j + 1;
					            students[i][j].local_rank = rank;
					            allS.push_back(students[i][j]);
					        }
					    }
					    
					    sort(allS.begin(), allS.end());
					    int rank = 1;
					    for(size_t i = 0; i < allS.size(); i++){
					        if(i && allS[i].grade != allS[i-1].grade) rank = i + 1;
					        allS[i].final_rank = rank;
					    }
					    
					    cout << allS.size() << endl;
					    for(auto &s : allS) cout << s.id << " " << s.final_rank << " " <<  s.location << " " << s.local_rank << endl;
					    
					    return 0;
					}
				r4.
					#include <iostream>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 210;

					struct Student{
					    string id;
					    int grade, location, local_rank, final_rank;
					    
					    bool operator< (const Student& t) const{
					        if(grade != t.grade) return grade > t.grade;
					        return id < t.id;
					    }
					};

					vector<Student> localS[N];
					vector<Student> allS;

					int main(){
					    int n;
					    cin >> n;
					    for(int i = 1; i <= n; i++){
					        auto &ls = localS[i];
					        int m;
					        cin >> m;
					        for(int j = 0; j < m; j++)
					        {
					            string id;
					            int grade;
					            cin >> id >> grade;
					            ls.push_back({id, grade, i});
					        }
					        
					        sort(ls.begin(), ls.end());
					        for(int j = 0, rank = 1; j < m; j++)
					        {
					            if(j && ls[j].grade != ls[j-1].grade) rank = j + 1;
					            ls[j].local_rank = rank;
					            allS.push_back(ls[j]);
					        }
					    }
					    
					    sort(allS.begin(), allS.end());
					    for(int i = 0, rank = 1; i < allS.size(); i++){
					        if( i && allS[i].grade != allS[i-1].grade) rank = i + 1;
					        allS[i].final_rank = rank;
					    }
					    
					    cout << allS.size() << endl;
					    for(auto &i : allS) cout << i.id << " " << i.final_rank << " " << i.location << " " << i.local_rank << endl;
					    
					    return 0;
					}
				r5.
					#include <iostream>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 210;

					struct Student{
					    string id;
					    int grade, location, local_rank, final_rank;
					    
					    bool operator< (const Student& t) const{
					        if(grade != t.grade) return grade > t.grade;
					        return id < t.id;
					    }
					};

					vector<Student> localS[N];
					vector<Student> allS;

					int main(){
					    int n;
					    cin >> n;
					    
					    for(int i = 1; i <= n; i++){
					        int m;
					        cin >> m;
					        
					        auto& ls = localS[i];
					        while(m --){
					            string id;
					            int grade;
					            cin >> id >> grade;
					            
					            ls.push_back({id, grade, i});
					        }
					        
					        sort(ls.begin(), ls.end());
					        for(int j = 0, rank = 1; j < (int)ls.size() ; j++)
					        {
					            if(j && ls[j].grade != ls[j-1].grade) rank = j + 1;
					            ls[j].local_rank = rank;
					            allS.push_back(ls[j]);
					        }
					    }
					    
					    sort(allS.begin(), allS.end());
					    for(int i = 0, rank = 1; i < (int)allS.size() ; i++){
					        if(i && allS[i].grade != allS[i-1].grade) rank = i + 1;
					        allS[i].final_rank = rank;
					    }
					    
					    cout << allS.size() << endl;
					    for(auto &i : allS) cout << i.id << " " << i.final_rank << " " << i.location << " " << i.local_rank << endl;
					    
					    return 0;
					}

		35. 1505. 列表排序	1028
			0. bug
			1. 笔记
				思路:
					1. 遇到复杂的结构,用结构体
					2. 这道题需要用多种排序,但是重载标识符只能用一次,所以我们是自定了3个比较函数
					3. sort()如果没有第三个参数,就是看容器(vector)里面的数据的小于操作符,如果有第三个参数,第三个参数就是比较函数
					4. 什么时候用cin,cout/scanf(),printf()
						1. 在数据量很小的时候用cin, cout
						2. 在数据量很大(10^5)时候,用scanf(),printf().否则会超时.
							注意,这里说的用scanf()和printf()是排他的用
							也就是一个cin,cout都不能有!一个都不行
							否则会因为什么同步?的问题,削弱scanf()
						3. 在数据输入比较复杂的时候,用scanf(),printf()
					5. cin,cout / scanf(), printf()
						1. cin,cout可以输出输入string
						2. 但是scanf()不能输入string,需要我们先输入成char xx[10], 然后再 = {xx} 来当做string push进去
							记得scanf()输入%d的时候,需要 &, 例如scanf("%d", &yy);
						3. printf()也不能输出string,需要我们printf("%s", xx.c_str()), 否则输出乱码
					6. 定义结构体
						1. 可以通过数组的方式: struct _xx{}XX[N];
							1. 插入是: XX[i] = {a,b,c};
							2. 适用于题目告诉我们size
							3. 如果是用数组的话,我们记得就不要用while(n--), 而使用for(int i = 0; i < n ; i++) 因为一个我们需要XX[i] = xx, 另一个因为之后需要用n来知道XX的size
					 	2. 可以通过vector的方式: struct _xx{}; vector<_xx> XX;
					 		1. 插入是: XX.push_back({a,b,c});
					 		2. 适用于题目没有告诉我们size,我们需要用.size(), 否则自己开新变量存size很麻烦
					 		2. 使用于需要比较运算
					 7. 比较函数: 你可以用引用, 但是老师没有用.应该都可以
					 	bool comp1(Rec &a, Rec &b){
						    return a.id < b.id;
						}

						bool comp2(Rec &a, Rec &b){
						    if(a.name != b.name) return a.name < b.name;
						    return a.id < b.id;
						}

						bool comp3(Rec &a, Rec &b){
						    if(a.grade != b.grade) return a.grade < b.grade;
						    return a.id < b.id;
						}

						if(m == 1) sort(res.begin(), res.end(), comp1);
					    else if(m == 2) sort(res.begin(), res.end(), comp2);
					    else sort(res.begin(), res.end(), comp3);
			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010;

					int n;

					struct Row
					{
					    string id, name;
					    int grade;
					}rows[N];

					bool cmp1(Row a, Row b)
					{
					    return a.id < b.id;
					}

					bool cmp2(Row a, Row b)
					{
					    if (a.name != b.name) return a.name < b.name;
					    return a.id < b.id;
					}

					bool cmp3(Row a, Row b)
					{
					    if (a.grade != b.grade) return a.grade < b.grade;
					    return a.id < b.id;
					}

					int main()
					{
					    int c;
					    scanf("%d%d", &n, &c);
					    char id[10], name[10];
					    for (int i = 0; i < n; i ++ )
					    {
					        int grade;
					        scanf("%s%s%d", id, name, &grade);
					        rows[i] = {id, name, grade};
					    }

					    if (c == 1) sort(rows, rows + n, cmp1);
					    else if (c == 2) sort(rows, rows + n, cmp2);
					    else sort(rows, rows + n, cmp3);

					    for (int i = 0; i < n; i ++ )
					        printf("%s %s %d\n", rows[i].id.c_str(), rows[i].name.c_str(), rows[i].grade);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/272659/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010;

					struct Row{
					    string id;
					    string name;
					    int grade;
					}row[N];

					bool cmp1(Row a, Row b){
					    return a.id < b.id; 
					}

					bool cmp2(Row a, Row b){
					    if(a.name != b.name) return a.name < b.name;
					    return a.id < b.id;
					}

					bool cmp3(Row a, Row b){
					    if(a.grade != b.grade) return a.grade < b.grade;
					    return a.id < b.id;
					}

					int main(){
					    int n, m;
					    scanf("%d%d", &n, &m);

					    char id[10], name[10]; //只能用char[]来用scanf()读
					    int grade;
					    for(int i = 0; i < n; i++)
					    {
					        scanf("%s %s %d", id, name, &grade);
					        row[i] = {id, name, grade};
					    }

					    if(m == 1){
					        sort(row, row + n, cmp1);
					    }
					    else if(m == 2){
					        sort(row, row + n, cmp2);
					    }
					    else{
					        sort(row, row + n, cmp3);
					    }

					    for(int i = 0; i < n; i++){
					        printf("%s %s %d\n", row[i].id.c_str(), row[i].name.c_str(), row[i].grade);
					    }

					    return 0;
					}

					作者：jackrrr
					链接：https://www.acwing.com/activity/content/code/content/486517/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					struct Record{
						string id;
						string name;
						int grade;
					};

					vector<Record> rec;

					bool cmp1(Record &r1, Record &r2){
						return r1.id < r2.id;
					}

					bool cmp2(Record &r1, Record &r2){
						if(r1.name != r2.name) return r1.name <= r2.name;
						return r1.id < r2.id;
					}

					bool cmp3(Record &r1, Record &r2){
						if(r1.grade != r2.grade) return r1.grade <= r2.grade;
						return r1.id < r2.id;
					}


					int main(){
						int n, m;
						cin >> n >> m;
						while(n--){
							string id, name;
							int grade;
							cin >> id >> name >> grade;

							rec.push_back({id, name, grade});
						}
						if(m == 1)
							sort(rec.begin(), rec.end(), cmp1);
						else if(m == 2)
							sort(rec.begin(), rec.end(), cmp2);
						else sort(rec.begin(), rec.end(), cmp3);

						for(auto &i : rec){
							printf("%s %s %d\n", i.id.c_str(), i.name.c_str(), i.grade);
						}

						return 0;
					}
				r2.
					#include <iostream>
					#include <algorithm>
					#include <vector>

					using namespace std;

					struct Rec{
					    string id;
					    string name;
					    int grade;
					};

					vector<Rec> res;

					bool comp1(Rec &a, Rec &b){
					    return a.id < b.id;
					}

					bool comp2(Rec &a, Rec &b){
					    if(a.name != b.name) return a.name < b.name;
					    return a.id < b.id;
					}

					bool comp3(Rec &a, Rec &b){
					    if(a.grade != b.grade) return a.grade < b.grade;
					    return a.id < b.id;
					}

					int main(){
					    int n, m ;
					    cin >> n >> m;
					    while(n--){
					        char id[10], name[10];
					        int grade;
					        scanf("%s %s %d", id, name, &grade);
					        res.push_back({id, name, grade});
					    }
					    
					    if(m == 1) sort(res.begin(), res.end(), comp1);
					    else if(m == 2) sort(res.begin(), res.end(), comp2);
					    else sort(res.begin(), res.end(), comp3);
					    
					    for(auto &s : res){
					        printf("%s %s %d\n", s.id.c_str(), s.name.c_str(), s.grade);
					    }
					    
					    return 0;
					}
				r3.
					#include <iostream>
					#include <vector>
					#include <algorithm>

					using namespace std;

					struct Rec{
					    string id, name;
					    int grade;
					};

					vector<Rec> res;

					bool comp1(Rec &a, Rec &b){
					    return a.id < b.id;
					}

					bool comp2(Rec &a, Rec &b){
					    if(a.name != b.name) return a.name < b.name;
					    return a.id < b.id;
					}

					bool comp3(Rec &a, Rec &b){
					    if(a.grade != b.grade) return a.grade < b.grade;
					    return a.id < b.id;
					}

					int main(){
					    int n, m;
					    cin >> n >> m;
					    
					    while(n--){
					        char id[10], name[10];
					        int grade;
					        scanf("%s %s %d", id, name, &grade);
					        
					        res.push_back({id, name, grade});
					    }
					    
					    if(m == 1) sort(res.begin(), res.end(), comp1);
					    else if(m == 2) sort(res.begin(), res.end(), comp2);
					    else sort(res.begin(), res.end(), comp3);
					    
					    for(auto &s : res) printf("%s %s %d\n", s.id.c_str(), s.name.c_str(), s.grade);
					    
					    return 0;
					}
				r4.
				r5.

		36. 1523. 学生课程列表	1039
			0. bug
				cin:
					对于这样的情况, 输入是: aaa bbb ccc ddd
					我们不一定要用getline(), stringstream() 来一个一个读
					而是可以用cin 
						就是string temp; while( cin >> temp) 这样也可以一个一个读
				cout << vec.size() << endl;
					如果是空的话, 会输出0, 所以不需要判断是否vec.empty();
			1. 笔记
				1. 其实这道题很简单,关键看你怎么存
				2. 它的input是一个ind,后面包含了若干个string
				3. 他需要的output是给一个string,你输出若干个int
				4. 所以你存的时候,可以是一个string + 若干个int, 所以就是用map, 因为这里不涉及到排序,所以是unordered_map
				5. 因为输出的int是升序的,所以记得用sort
				6. 用auto的时候,想清楚这个到底是什么类型
				7. 我们用cin, 因为输入是40000, 还不到10^5

				本题时间限制比较紧，可以加上读入优化：ios::sync_with_stdio(false); cin.tie(0);。
			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>
					#include <vector>

					using namespace std;

					unordered_map<string, vector<int>> students;

					int main()
					{
					    ios::sync_with_stdio(false);
					    cin.tie(0);

					    int n, k;
					    cin >> n >> k;

					    while (k -- )
					    {
					        int id, m;
					        cin >> id >> m;
					        while (m -- )
					        {
					            string name;
					            cin >> name;
					            students[name].push_back(id);
					        }
					    }

					    while (n -- )
					    {
					        string name;
					        cin >> name;

					        auto& ls = students[name];
					        cout << name << ' ' << ls.size();
					        sort(ls.begin(), ls.end());

					        for (auto l : ls) cout << ' ' << l;
					        cout << endl;
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/272679/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <unordered_map>
					#include <iostream>
					#include <algorithm>
					#include <vector>

					using namespace std;

					unordered_map<string, vector<int>> students;

					int main(){
					    int n, m;
					    cin >> n >> m;

					    while(m--){
					        int id, p;
					        cin >> id >> p;
					        while(p--){
					            string name;
					            cin >> name;
					            students[name].push_back(id); //注意不是student[name] = p;
					        }
					    }

					    //method 1
					    /*
					    for(auto& s : students){ //s是<string, vector<int>>, 所以记得是s.second
					        sort(s.second.begin(), s.second.end());
					    }

					    while(n--){
					        string name;
					        cin >> name;
					        cout << name << " " << students[name].size();
					        for(auto& id : students[name]) //如果student[name]都没有就是不会走这个for loop
					                cout << " " << id;
					        cout << endl;
					    }
					    */

					    //method 2
					    while(n--){
					        string name;
					        cin >> name;

					        cout << name << " " << students[name].size();
					        sort(students[name].begin(), students[name].end());
					        for(auto id : students[name]){
					            cout << " " << id;
					        }
					        cout << endl;
					    }

					    //method 1,2 end
					    return 0;
					}

					作者：jackrrr
					链接：https://www.acwing.com/activity/content/code/content/486519/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <unordered_map>
					#include <vector>
					#include <sstream>
					#include <algorithm>

					using namespace std;

					unordered_map<string, vector<int>> students;

					int main(){
						int n, m;
						cin >> n >> m;
						while(m--){
							int id, a;
							cin >> id >> a;
							while(a--){
								string name;
								cin >> name;
								students[name].push_back(id);
							}
						}
						
						while(n--){
							string line;
							getline(cin, line);
							stringstream ssin(line);

							string query;
							while(ssin >> query){
								cout << query;
								auto &s = students[query];
								printf(" %d", s.size());
								sort(s.begin(), s.end());
								for(auto &item : s){
									printf(" %d", item);
								}
								cout << endl;
							}
						}

						return 0;
					}
				r2.
					#include <iostream>
					#include <algorithm>
					#include <vector>


					using namespace std;

					unordered_map<string, vector<int>> students;

					int main(){
					    int n, m;
					    cin >> n >> m;
					    while(m--){
					        int id, k;
					        cin >> id >> k;
					        while(k--){
					            string name;
					            cin >> name;
					            students[name].push_back(id);
					        }
					    }
					    
					    while(n--){
					        string name;
					        cin >> name;
					        auto &s = students[name];
					        sort(s.begin(), s.end());
					        
					        cout << name << " " << s.size();
					        for(int i : s){
					            cout << " " << i;
					        }
					        
					        
					        cout << endl;
					    }
					    
					    return 0;
					}
				r3.
					#include <iostream>
					#include <algorithm>
					#include <vector>


					using namespace std;

					unordered_map<string, vector<int>> students;

					int main(){
					    int n, m;
					    cin >> n >> m;
					    while(m--){
					        int id, k;
					        cin >> id >> k;
					        while(k--){
					            string name;
					            cin >> name;
					            students[name].push_back(id);
					        }
					    }
					    
					    while(n--){
					        string name;
					        cin >> name;
					        auto &s = students[name];
					        sort(s.begin(), s.end());
					        
					        cout << name << " " << s.size();
					        for(int i : s){
					            cout << " " << i;
					        }
					        
					        
					        cout << endl;
					    }
					    
					    return 0;
					}
				r4.
					#include <iostream>
					#include <algorithm>
					#include <vector>
					#include <unordered_map>

					using namespace std;

					unordered_map<string, vector<int>> students;

					int main(){
					    int n, m;
					    cin >> n >> m;
					    while(m--){
					        int id;
					        int num;
					        cin >> id >> num;
					        while(num--){
					            string name;
					            cin >> name;
					            students[name].push_back(id);
					        }
					    }
					    
					    while(n--){
					        string name;
					        cin >> name;
					        
					        auto &s = students[name];
					        sort(s.begin(), s.end());
					        
					        cout << name << " " << s.size();
					        for(int i : s){
					            cout << " " << i;
					        }
					        
					        cout << endl;
					    }
					    
					    return 0;
					    
					}
				r5.

		37. 1538. 链表排序	1052
			0. bug
				1. 忘记加c_str()
				2. printf("%s %d %s\n", vec[i].addr.c_str(), vec[i].val, vec[i+1].addr.c_str()); 
					小心bug! 最后是s %d %s,不是s %d %d, 另一个bug, 最后输出的是vec[i+1].addr而不是vec[i].next;
				3. 最后打印的时候:
					应该是: 每个节点都要打印一次, 也就是打印size次, 其中最后一个节点的下一个是"-1"
					我的错误写法: 只打印了size-1次, 因为我以为最后一个节点的下一个是"-1"所以我们应该少打一个,其实不应该
			1. 笔记
				-1. 这道题目的意思:
					1. 给你很多节点的信息, 这些节点, 有些是连在一起的, 例如可能有10个节点, 最后可以有两个链表
					2. 给了你一个head, 让你求出这个head引导下的链表.
					3. 将这个链表的节点打散, 重新组合, 组合的条件就是按照key的顺序
				2. printf()是不会给你自动换行的, 所以你可以用两个 printf()打印一行的内容
					另外, 你可以用 printf()和 puts()搭配, 打印一行的内容, 因为 puts()可以换行
				0. 将链表排序变成了数组排序, 有点投机取巧,但是方便
				1. 这个代码厉害的地方在于, 我们用哈希表来找一个链表了
					unordered_map<string, Node> student;
					for(string i = head; i != "-1"; i = student[i].next) 
				2. 找到链表之后,推入vector,对vector进行排序(需要重载Node的符号),最后输出
				3. **** 这道题, N = 10^5, 所以不能用cin,cout
				2. 老师说,我们之所以喜欢在算法比赛中,开一个结构体数组,是因为:
					1. 时间短,只有1s,如果你一个结构体一个结构体的new, 时间不够
						因为new本质上是malloc,new一次很快,但是很多次的话,就会超时
					2. 如果我们开了一个结构体数组
						相当于就只new了一次,但是new的空间很大
						new的次数多对时间的影响大,但是new的空间大对时间影响不大
					3. 在工程中,喜欢不停new,是因为没有时间限制
						1. 假设来一个用户,new一次
						2. 不可能1s中内,来10^5个客户(除了11.11)

			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>
					#include <vector>

					using namespace std;

					struct Node
					{
					    string address;
					    int key;
					    string next;

					    bool operator< (const Node& t) const
					    {
					        return key < t.key;
					    }
					};

					int main()
					{
					    int n;
					    char head[10];
					    scanf("%d%s", &n, head);

					    unordered_map<string, Node> map;
					    char address[10], next[10];
					    while (n -- )
					    {
					        int key;
					        scanf("%s%d%s", address, &key, next);
					        map[address] = {address, key, next};
					    }

					    vector<Node> nodes;
					    for (string i = head; i != "-1"; i = map[i].next) nodes.push_back(map[i]);

					    printf("%d ", nodes.size());
					    if (nodes.empty()) puts("-1");
					    else
					    {
					        sort(nodes.begin(), nodes.end());
					        printf("%s\n", nodes[0].address.c_str());
					        for (int i = 0; i < nodes.size(); i ++ )
					        {
					            if (i + 1 == nodes.size())
					                printf("%s %d -1\n", nodes[i].address.c_str(), nodes[i].key);
					            else
					                printf("%s %d %s\n", nodes[i].address.c_str(), nodes[i].key, nodes[i + 1].address.c_str());
					        }
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/272708/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

				2. b
					#include <iostream>
					#include <algorithm>
					#include <vector>
					#include <unordered_map>

					using namespace std;

					struct Node{
					    string addr;
					    int val;
					    string next;

					    bool operator< (const Node& t) const{
					        return val < t.val; //我优先(排在左边)的条件, 我的值更小
					    }
					};

					int main(){
					    int n;
					    char head[6];
					    scanf("%d %s", &n, head);

					    char addr[10], next[10];
					    int val;
					    unordered_map<string, Node> map;
					    while(n --){
					        scanf("%s %d %s", addr, &val, next);
					        map[addr] = {addr, val, next};
					    }   

					    //制作链表,把每个节点都推入vector
					    vector<Node> vec;
					    for(string i = head; i != "-1"; i = map[i].next ) vec.push_back(map[i]);

					    printf("%d ", (int)vec.size());
					    //对vec排序, 会用到Node的小于号
					    if(vec.size())
					    {
					        sort(vec.begin(), vec.end());
					        printf("%s\n", vec[0].addr.c_str()); //打印头结点地址, 注意要c_str()

					        for(int i = 0; i < (int)vec.size(); i++){ //注意如何判断是否是最后一个节点
					            if(i == (int)vec.size()-1)
					                printf("%s %d %d\n", vec[i].addr.c_str(), vec[i].val, -1);  //尾结点的next是-1
					            else
					                printf("%s %d %s\n", vec[i].addr.c_str(), vec[i].val, vec[i+1].addr.c_str()); //小心bug! 最后是%s,不是%d, 另一个bug, 最后输出的是vec[i+1].addr而不是vec[i].next;
					        }
					    }
					    else{
					        puts("-1");
					    }
					    return 0;
					}


					作者：jackrrr
					链接：https://www.acwing.com/activity/content/code/content/486534/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>
					#include <vector>

					using namespace std;

					struct Node{
						string addr;
						int key;
						string next;

						bool operator< (const Node& t) const { return key < t.key; }
					};

					unordered_map<string, Node> map;

					int main(){
						int n;
						char head[10];
						scanf("%d %s", &n, head);
						while(n--){
							char addr[10], next[10];
							int key;

							scanf("%s %d %s", addr, &key, next);
							map[addr] = {addr, key, next};
						}

						vector<Node> res;
						for(string i = head; i != "-1"; i = map[i].next){
							res.push_back(map[i]);
						}

						sort(res.begin(), res.end());
						if(res.empty()) printf("0 -1");
						else{
							printf("%d %s\n", res.size(), res[0].addr.c_str());
							for(int i = 0; i < res.size() ; i++){
								auto s = res[i];
								if(i != res.size() - 1) {auto sn = res[i+1]; printf("%s %d %s\n", s.addr.c_str(), s.key, sn.addr.c_str());}
								else printf("%s %d -1\n", s.addr.c_str(), s.key);
							}
						}

						return 0;
					}
				r2.
					#include <iostream>
					#include <unordered_map>
					#include <vector>
					#include <algorithm>

					using namespace std;

					struct Node{
					    string addr;
					    int key;
					    string next;
					    
					    bool operator< (const Node& t) const{
					        return key < t.key;
					    }
					};

					unordered_map<string, Node> map;

					int main(){
					    int n;
					    char head[10];
					    scanf("%d %s", &n, head);
					    
					    while(n--){
					        char addr[10];
					        int key;
					        char next[10];
					        scanf("%s %d %s", addr, &key, next);
					        
					        map[addr] = {addr, key, next};
					    }
					    
					    vector<Node> res;
					    for(string i = head; i != "-1"; i = map[i].next){
					        res.push_back(map[i]);
					    }
					    
					    sort(res.begin(), res.end());
					    printf("%d ", res.size());
					    if(res.empty()) puts("-1");
					    else{
					        printf("%s\n", res[0].addr.c_str());
					        
					        for(int i = 0; i < res.size(); i++){
					            if(i + 1 != res.size()) printf("%s %d %s\n", res[i].addr.c_str(), res[i].key, res[i+1].addr.c_str());
					            else printf("%s %d -1\n", res[i].addr.c_str(), res[i].key);
					        }
					    }
					    
					    return 0;
					}
				r3.
					#include <iostream>
					#include <unordered_map>
					#include <vector>
					#include <algorithm>

					using namespace std;

					struct Node{
					    string addr;
					    int key;
					    string next;
					    
					    bool operator< (const Node &t) const{
					        return key < t.key;
					    }
					};

					unordered_map<string, Node> map;

					int main(){
					    int n;
					    char head[10];
					    scanf("%d %s", &n, head);
					    
					    while(n--){
					        char addr[10];
					        int key;
					        char next[10];
					        scanf("%s %d %s", addr, &key, next);
					        
					        map[addr] = {addr, key, next};
					    }
					    
					    vector<Node> res;
					    for(string i = head; i != "-1"; i = map[i].next){
					        res.push_back(map[i]);
					    }
					    
					    sort(res.begin(), res.end());
					    printf("%d ",res.size());
					    if(res.empty()) puts("-1");
					    else{
					        printf("%s\n", res[0].addr.c_str());
					        
					        for(int i = 0; i < res.size(); i++){
					            if(i != res.size() - 1) printf("%s %d %s\n", res[i].addr.c_str(), res[i].key, res[i+1].addr.c_str());
					            else printf("%s %d -1\n", res[i].addr.c_str(), res[i].key);
					        }
					    }
					    
					    return 0;
					}
				r4.
					#include <iostream>
					#include <vector>
					#include <algorithm>
					#include <unordered_map>

					using namespace std;

					struct Node{
					    string addr;
					    int key;
					    string next;
					    
					    bool operator< (const Node& t) const{
					        return key < t.key;
					    }
					};

					unordered_map<string, Node> map;

					int main(){
					    int n;
					    char head[10];
					    scanf("%d %s", &n, head);
					    
					    while(n--){
					        char addr[10];
					        int key;
					        char next[10];
					        scanf("%s %d %s", addr, &key, next);
					        
					        map[addr] = {addr, key, next};
					    }
					    
					    vector<Node> res;
					    for(string i = head; i != "-1"; i = map[i].next){
					        res.push_back(map[i]);
					    }
					    
					    sort(res.begin(), res.end());
					    printf("%d ", res.size());
					    if(res.empty()) puts("-1");
					    else{
					        printf("%s\n", res[0].addr.c_str());
					        int i = 0;
					        for(; i < res.size() - 1; i++){
					            printf("%s %d %s\n", res[i].addr.c_str(), res[i].key, res[i+1].addr.c_str());
					        }
					        printf("%s %d -1\n", res[i].addr.c_str(), res[i].key);
					    }
					    
					    return 0;
					}
				r5.

		38. 1561. PAT 评测	1075
			0. bug
			1. 笔记
				0. 经典的 unordered_map + vector
				1. 数据规模只有10000, 10^4所以不用scanf()
				2. 构造了一个struct, 其中有total总分, 也有cnt满分题目个数
				3. 使用的技巧: 重载操作符, 构建函数
				4. 因为需要排序, 所以要用到了vector<>
				5. 在input的时候, 完成了记录一个人每道题的最大成绩
				6. 之后,在遍历的时候,计算了一个人是否编译通过并提交过, 如果提交过, 就计算这个人的total,cnt, 最后将这个人push到vector
				7. 用sort(),所以重载了操作符.  
				8. 厉害的地方, 用grade = -2,-1,0,x分别代表了没有提交,编译错误,答案错,部分正确. 其中用Max(0,grade)来输出总分(因为没有提交和编译错误不算成负分), 用 if(grade >= 0)来判断是否提交过(因为-2和-1都是没有提交和编译错误)
				9. 因为题目中grade只会是-1,0,x不会是-2,所以你设置成-2就有必要.我也想试试(不行,因为-2和-1在output严格区分了)
				10. 超级容易错!
				11. Student(string _id) : id(_id)，C++构造函数的列表初始化
				其他:
					1. 构造函数
						Student(){}
						Student(string _id) : id(_id){
							for(int i = 0; i < N; i++) grade[i] = -2;
							total = 0;
							cnt = 0;
							submit = false; 注意!!!!! 如果没有初始化, 会认为是true
							rank = M + 1;
						}

						为什么需要构造函数, 因为一步一步的更新信息
						if(map.count(id) == 0) map[id] = Student(id);
						map[id].grade[p] = max(map[id].grade[p], g);
						if(!map[id].submit && g >= 0) map[id].submit = true;

					2. unordered_map的使用:
						1. 直接获取元素:
							auto &s = map[id];

						2. 用for()的话, 注意item.second才是元素
							vector<Student> res;
							for(auto &item : map){
								auto &s = item.second;
								s.calc();
								if(s.submit) res.push_back(s); 
							}

					 3. printf()可以没有字母, 纯字符
					 	printf(" -");
					 4. puts()可以当做换行
					 	puts("");
					 5. 对于一行的情况, 输入给一个数组
						for(int i = 1; i <= pnum; i++){
							scanf("%d ", &full[i]);
						}
			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>
					#include <vector>

					using namespace std;

					const int K = 6;

					int n, k, m;
					int p_score[K];

					struct Student
					{
					    string id;
					    int grade[K];
					    int total, cnt;

					    Student(){}
					    Student(string _id) : id(_id)
					    {
					        for (int i = 1; i <= k; i ++ ) grade[i] = -2;
					        total = cnt = 0;
					    }

					    void calc()
					    {
					        for (int i = 1; i <= k; i ++ )
					        {
					            total += max(0, grade[i]);
					            if (grade[i] == p_score[i]) cnt ++ ;
					        }
					    }

					    bool has_submit()
					    {
					        for (int i = 1; i <= k; i ++ )
					            if (grade[i] >= 0)
					                return true;
					        return false;
					    }

					    bool operator< (const Student& t) const
					    {
					        if (total != t.total) return total > t.total;
					        if (cnt != t.cnt) return cnt > t.cnt;
					        return id < t.id;
					    }
					};

					int main()
					{
					    unordered_map<string, Student> students;

					    scanf("%d%d%d", &n, &k, &m);
					    for (int i = 1; i <= k; i ++ ) scanf("%d", &p_score[i]);

					    while (m -- )
					    {
					        string u_id;
					        char u_id_s[6];
					        int p_id, grade;
					        scanf("%s%d%d", u_id_s, &p_id, &grade);
					        u_id = u_id_s;

					        if (students.count(u_id) == 0) students[u_id] = Student(u_id);
					        students[u_id].grade[p_id] = max(students[u_id].grade[p_id], grade);
					    }

					    vector<Student> res;
					    for (auto& item: students)
					    {
					        auto& s = item.second;
					        if (s.has_submit())
					        {
					            s.calc();
					            res.push_back(s);
					        }
					    }

					    sort(res.begin(), res.end());

					    for (int i = 0, rank = 1; i < res.size(); i ++ )
					    {
					        if (i && res[i].total != res[i - 1].total) rank = i + 1;
					        printf("%d %s %d", rank, res[i].id.c_str(), res[i].total);
					        for (int j = 1; j <= k; j ++ )
					            if (res[i].grade[j] == -2) printf(" -");
					            else printf(" %d", max(0, res[i].grade[j]));
					        puts("");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/272747/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>
					#include <vector>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int K = 10; //最多5道题

					int full_grade[K];
					int n, k, m; //k要是全局变量,因为struct Student用到了

					struct Student{
					    string id;
					    int grade[K]; //bug, 这里应该是K, 而不能是k, 因为k现在还不确定. 如果写k会报错:array bound is not an integer constant before ']' token
					    int total; //总分
					    int cnt; //满分个数
					    int rank; //排名

					    Student() {} //default初始
					    Student(string _id) : id(_id){ //这里: id(_id)相当于直接初始了id
					        total = 0;
					        cnt = 0;
					        rank = -1;
					        for(int i = 0; i < k; i ++) grade[i] = -2; //必须是-2, 而不是-1. -2表示从未提交,-1表示编译错误, 题目中output是严格区分两者了
					    }

					    bool has_submit(){
					        for(int i = 0; i < k; i++)
					        {
					            if(grade[i] >= 0){ //因为0和正整数都表示成功提交了
					                return true;
					            }
					        }
					        return false;
					    }

					    void calc(){
					        for(int i = 0 ; i < k; i++){ 
					            if(grade[i] >= 0) total += grade[i]; //bug, 小心-1是算作0加入总分的 
					            if(grade[i] == full_grade[i]) cnt ++;
					        }
					    }

					    bool operator< (const Student& t) const{
					        if(total != t.total) return total > t.total;
					        if(cnt != t.cnt) return cnt > t.cnt;
					        return id < t.id;
					    }
					};

					int main(){

					    scanf("%d%d%d", &n, &k ,&m); //bug! 我之前写成&n, &m ,&k, 一直导致了segmentation fault

					    //读满分
					    for(int i = 0; i < k; i++){ 
					        scanf("%d", &full_grade[i]);
					    }

					    //读提交
					    unordered_map<string, Student> map;

					    for(int i = 0; i < m; i ++){
					        char u_id_s[10];
					        int p_id, g;
					        scanf("%s %d %d", u_id_s, &p_id, &g);
					        string u_id = u_id_s;

					        if(map.count(u_id) == 0) //如果学生没有遇见过,就初始化
					        {
					            map[u_id] = Student(u_id); //这里调用了初始化函数.
					        }

					        p_id--; //bug!, 因为题目K的编号是从1开始的!
					        //之后我们判断题目p_id的成绩g是不是这个学生最好的成绩
					        map[u_id].grade[p_id] = max(map[u_id].grade[p_id], g);
					    }

					    //到此为止, 所以学生都初始完了,并且都保留了最好成绩
					    //接下来看哪些学生虽然初始化了,但是没有提交
					    //提交的,计算total和cnt,并且push到vec里面
					    vector<Student> vec; //将提交的学生放到vec中, 之后去排序
					    for(auto& item : map){ //注意, 这里的item不是Studnet,而是<string, Student>
					        auto& s = item.second;
					        if(s.has_submit()){
					            s.calc(); //计算total和cnt;
					            vec.push_back(s);
					        }
					    }

					    sort(vec.begin(), vec.end()); //用了操作符重载

					    //计算排名
					    for(int i = 0; i < (int)vec.size(); i++){
					        if(!i || vec[i].total < vec[i-1].total)
					            vec[i].rank = i + 1;
					        else
					            vec[i].rank = vec[i-1].rank;
					    }

					    //打印
					    for(auto& s : vec){
					        printf("%d %s %d", s.rank, s.id.c_str(), s.total);
					        for(int i = 0 ; i < k ; i++) { 
					            if(s.grade[i] == -2) cout << " -"; //bug, 题目说了(如果未提交就是-, 如果编译出错或者没有写对还是0)
					            else cout << " " << max(0,s.grade[i]); //bug, 因为可能s.grade[i]依旧是初始值-2
					        }
					        cout << endl;
					    }

					    return 0;
					}

					作者：jackrrr
					链接：https://www.acwing.com/activity/content/code/content/486781/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1. 
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>
					#include <vector>

					using namespace std;

					const int N = 10;

					const int M = 10010;

					int n;
					int m;


					int full[N];

					struct Student{
						string id;
						int grade[N];
						bool sub;
						int total;
						int cnt;
						int rank;

						Student(){}
						Student(string _id) : id(_id){
							for(int i = 1; i <= m; i++) grade[i] = -2;
							sub = false;
							total = 0;
							cnt = 0;
							rank = M + 1;
						}

						void calc()
						{
							for(int i = 1; i <= m; i++)
							{
								total += max(grade[i], 0);
								if(grade[i] == full[i]) cnt ++;
							} 
						}

						bool operator< (const Student& t) const{
							if(total != t.total) return total > t.total;
							if(cnt != t.cnt) return cnt > t.cnt;
							return id < t.id;
						}
					};


					unordered_map<string, Student> input;
					vector<Student> res;

					int main(){
						int k;
						scanf("%d %d %d", &n, &m, &k);
						for(int i = 1; i <= m; i++) cin >> full[i];

						while(k--){
							char id[10];
							int q, g;
							scanf("%s %d %d", id, &q, &g);

							if(input.count(id) == 0) input[id] = Student(id);
							input[id].grade[q] = max(input[id].grade[q], g);
							if(g >= 0) input[id].sub = true;
						}

					    
						for(auto &item : input){
						    auto &s = item.second;
							s.calc();
							if(s.sub == true) res.push_back(s);
						}

						sort(res.begin(), res.end());
						for(int i = 0, rank = 1; i < (int)res.size(); i++){
							if(i && res[i].total != res[i-1].total) rank = i+1;
							res[i].rank = rank;
						}

						for(int i = 1; i <= (int)res.size(); i++){
							printf("%d %s %d", res[i-1].rank, res[i-1].id.c_str(), res[i-1].total);
							for(int j = 1; j <= m; j++){
								if(res[i-1].grade[j] >= -1) 
									printf(" %d",max(0, res[i-1].grade[j]));
								else{
									printf(" -");
								}
							}
							puts("");
						}
						
						return 0;
					}
				r2.
					#include <iostream>
					#include <unordered_map>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 6;
					const int M = 10010;

					int full[N];

					int snum, pnum, k;

					struct Student{
						string id;
						int grade[N];
						int total;
						int cnt;
						bool submit;
						int rank;

						Student(){}
						Student(string _id) : id(_id){
							for(int i = 0; i < N; i++) grade[i] = -2;
							total = 0;
							cnt = 0;
							submit = false;
							rank = M + 1;
						}

						void calc(){
							for(int i = 1; i <= pnum; i++){
								total += max(0, grade[i]);
								if(grade[i] == full[i]) cnt ++;
							}
						}

						bool operator< (const Student& t) const{
							if(total != t.total) return total > t.total;
							if(cnt != t.cnt) return cnt > t.cnt;
							return id < t.id;
						}
					};

					unordered_map<string, Student> map;

					int main(){
						
						scanf("%d %d %d", &snum, &pnum, &k);

						for(int i = 1; i <= pnum; i++){
							scanf("%d ", &full[i]);
						}

						while(k--){
							char id[10];
							int p, g;
							scanf("%s %d %d", id, &p, &g);

							if(map.count(id) == 0) map[id] = Student(id);
							map[id].grade[p] = max(map[id].grade[p], g);
							if(!map[id].submit && g >= 0) map[id].submit = true;
						}

						vector<Student> res;
						for(auto &item : map){
							auto &s = item.second;
							s.calc();
							if(s.submit) res.push_back(s); 
						}

						sort(res.begin(), res.end());

						for(int i = 0, rank = 1; i < (int)res.size(); i++){
							if(i && res[i].total != res[i-1].total) rank = i + 1;
							res[i].rank = rank;

							printf("%d %s %d", rank, res[i].id.c_str(), res[i].total);
							for(int j = 1; j <= pnum; j++){
								if(res[i].grade[j] >= -1) printf(" %d", max(0, res[i].grade[j]));
								else printf(" -");
							}

							puts("");

						}

						return 0;


					}

				r3.
					#include <iostream>
					#include <unordered_map>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 10;
					const int M = 10010;

					int snum, pnum, k;

					int full[N];

					struct Student{
					    string id;
					    int grade[N];
					    int total;
					    int cnt;
					    bool submit;
					    int rank;
					    
					    Student(){}
					    Student(string _id) : id(_id){
					        for(int i = 0; i < N; i++) grade[i] = -2;
					        total = 0;
					        cnt = 0;
					        submit = false;
					        rank = M + 1;
					    }
					    
					    void calc(){
					        for(int i = 1; i <= pnum; i++){
					            total += max(0, grade[i]);
					            if(grade[i] == full[i]) cnt++;
					        }
					    }
					    
					    bool operator< (const Student& t) const{
					        if(total != t.total) return total > t.total;
					        if(cnt != t.cnt) return cnt > t.cnt;
					        return id < t.id;
					    }
					};


					unordered_map<string, Student> map;

					int main(){
					    scanf("%d %d %d", &snum, &pnum, &k);
					    for(int i = 1; i <= pnum; i++)
					        scanf("%d ", &full[i]);
					    while(k--){
					        char id[10];
					        int p, g;
					        scanf("%s %d %d", id, &p, &g);
					        
					        if(map.count(id) == 0) map[id] = Student(id);
					        auto &s = map[id];
					        s.grade[p] = max(g, s.grade[p]);
					        if(!s.submit && g >= 0) s.submit = true;
					    }
					    
					    vector<Student> res;
					    for(auto &item : map){
					        auto &s = item.second;
					        s.calc();
					        if(s.submit) res.push_back(s);
					    }
					    
					    sort(res.begin(), res.end());
					    for(int i = 0, rank = 1; i < (int)res.size(); i++){
					        if(i && res[i].total != res[i-1].total) rank = i + 1;
					        res[i].rank = rank;
					        
					        printf("%d %s %d", rank, res[i].id.c_str(), res[i].total);
					        for(int j = 1; j <= pnum; j++){
					            if(res[i].grade[j] >= -1) printf(" %d", max(0, res[i].grade[j]));
					            else printf(" -");
					        }
					        puts("");
					    }
					    
					    return 0;
					}
				r4.
					#include <iostream>
					#include <unordered_map>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 6;
					const int M = 10010;

					int snum, pnum, k;
					int full[N];

					struct Student{
					    string id;
					    int grade[N];
					    int total;
					    int cnt;
					    bool submit;
					    int rank;
					    
					    Student(){}
					    Student(string _id) : id(_id){
					        for(int i = 0; i < N; i++) grade[i] = -2;
					        total = 0;
					        cnt = 0;
					        rank = M + 1;
					        submit = false;
					    }
					    
					    void calc(){
					        for(int i = 1; i <= pnum; i++){
					            total += max(0, grade[i]);
					            if(grade[i] == full[i]) cnt ++;
					        }
					    }
					    
					    bool operator< (const Student& t) const{
					        if(total != t.total) return total > t.total;
					        if(cnt != t.cnt) return cnt > t.cnt;
					        return id < t.id;
					    } 
					};

					unordered_map<string, Student> map;

					int main(){
					    scanf("%d %d %d", &snum, &pnum, &k);
					    for(int i = 1; i <= pnum; i++) 
					        scanf("%d ", &full[i]);
					        
					    while(k--){
					        char id[10];
					        int p, g;
					        scanf("%s %d %d",id, &p, &g);
					        if(map.count(id) == 0) map[id] = Student(id);
					        auto &s = map[id];
					        s.grade[p] = max(g, s.grade[p]);
					        if(!s.submit && g >= 0) s.submit = true;
					    }
					    
					    // cout << res.size()
					    vector<Student> res;
					    for(auto &item : map){
					        auto &s = item.second;
					        s.calc();
					        if(s.submit) res.push_back(s);
					    }
					    
					    sort(res.begin(), res.end());
					    for(int i = 0, rank = 1; i < (int)res.size(); i++){
					        if(i && res[i].total != res[i-1].total) rank = i + 1;
					        res[i].rank = rank;
					    
					        printf("%d %s %d", rank, res[i].id.c_str(), res[i].total);
					        for(int j = 1; j <= pnum; j++){
					            if(res[i].grade[j] >= -1) printf(" %d", max(0, res[i].grade[j]));
					            else printf(" -");
					        }
					        puts("");
					    }
					    
					    return 0;
					    
					}
				r5.

		39. 1588. 插入还是堆排序	1098
			0. bug
				1. 插入排序: 注意是b[l-1] > temp
					int temp = b[l];
					while(l >= 2 && b[l-1] > temp) 注意是b[l-1] > temp, 不是b[l-1] > b[l], 假设是从b[1]开始有值
					{
						b[l] = b[l-1];
						l--; //不能简写成 b[l] = b[--l];
					}
					b[l] = temp;
				2. 比较的时候:
					记得如果是全局变量的话, 最好要判断范围, 例如正确的:
						while(k <= n && b[k-1] <= b[k]) k++;
					    while(k <= n && b[k] == a[k]) k++;
					错误的:
						while(b[k-1] <= b[k]) k++;
					    while(b[k] == a[k]) k++;
					    因为全局变量中, k如果超出了n, 那么a[k], b[k]一定相等, == 0
				3. 因为是判断是否用heap
					所以从i == 1开始读取input, 而不是从 i == 0开始
				4. 写 down() 的时候, 翻了错误:

					void down(int u, int size)
					{
					    int l = u * 2, r = u * 2 + 1;
						int t = u;
						if(l <= size && b[l] > b[u]) t = l;
						if(r <= size && b[r] > b[t]) t = r; 这里不能写成b[r] > b[l], 因为还是要和t比, 这里的t可能是l, 也可能是原来的u
						if(t != u){
							swap(b[u], b[t]);
					        down(t, size); 我错写成了 down(1, size);
					    }
					}



			1. 笔记
				思路:
					1. 老师说插入排序的特点: 左侧的元素都是拍好的(递增的),右侧的元素都是和原来的元素一样
					2. 老师说堆排序的特点: 左侧是堆的顺序, 右侧是最大的前k个数. 总之,堆顶的元素i是 <= 右侧的所有元素的
					3. 因为题目是保证唯一解, 所以肯定是分了左右侧,没有分左右侧说明排序完了,排序结束两种方法的结果都一样,所以即可以说是堆排序也可以说是插入排序,答案不唯一.
					4. 回忆插入排序: 右侧的元素一直跟左侧的元素打擂台,一直到打不过
					5. 回忆堆排序: 左侧的堆顶(最大值),插入到数组末尾,siftdown()之后,左侧的堆顶又是一个最大值,插入到数组末尾
					6. 因为插入排序好判断(左侧有序,右侧原封不变),堆排序不好判断(需要看左侧是否满足堆还是比较麻烦的)
					7. 所以,先判断是否是插入,是,就继续插入排序.不是,说明是堆排序,找到数组的左右两侧(by 堆顶的元素i是 <= 右侧的所有元素的),最后继续堆排序
					8. 很多bug,很容易写错

				一个技巧:
					int k = 2;
					while(k <= n && b[k-1] <= b[k]) k++;
					这样break的时候, k就是我们需要的了
					而不是 
						int k = 1;
						while(k <= n && b[k] <= b[k+1]) k++;
						break的时候, k+1才是我们需要的.

			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					const int N = 110;

					int n;
					int a[N], b[N];

					void down(int u, int size)
					{
					    int t = u;
					    if (u * 2 <= size && b[t] < b[u * 2]) t = u * 2;
					    if (u * 2 + 1 <= size && b[t] < b[u * 2 + 1]) t = u * 2 + 1;
					    if (t != u)
					    {
					        swap(b[t], b[u]);
					        down(t, size);
					    }
					}

					int main()
					{
					    cin >> n; 
					    for (int i = 1; i <= n; i ++ ) cin >> a[i];
					    for (int i = 1; i <= n; i ++ ) cin >> b[i];

					    int p = 2;
					    while (p <= n && b[p] >= b[p - 1]) p ++ ;
					    int k = p;
					    while (p <= n && a[p] == b[p]) p ++ ;
					    if (p == n + 1)  // 说明是插入排序
					    {
					        puts("Insertion Sort");
					        while (k > 1 && b[k] < b[k - 1]) swap(b[k], b[k - 1]), k -- ;
					    }
					    else  // 否则说明一定是堆排序
					    {
					        puts("Heap Sort");
					        p = n;
					        while (b[1] <= b[p]) p -- ;
					        swap(b[1], b[p]);
					        down(1, p - 1);
					    }

					    cout << b[1];
					    for (int i = 2; i <= n; i ++ ) cout << ' ' << b[i];
					    cout << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/272766/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>

					using namespace std;

					const int N = 110;

					int a[N];
					int b[N];

					void siftdown(int pos, int size){
					    int t = pos;
					    if(2*pos+1 < size && b[t] < b[2*pos+1]) t = 2*pos+1; //bug,主义是t = 2*pos+1, 而不是pos = 2*pos+1 //这句话:如果存在做儿子 && left儿子比自己大
					    if(2*pos+2 < size && b[t] < b[2*pos+2]) t = 2*pos+2; //bug, 这里是b[t] < b[2*pos+1]而不是b[pos] < b[2*pos+1], 因为这里一共有两个if,所以上面的t = 2*pos+1 可以影响我们这个t, 所以假设上一句 left比自己大, 但是现在发现right 比 left大, 那么我们就要把父亲和right交换.
					    if(t != pos ){//是否被修改过
					        swap(b[t], b[pos]); //交换
					        siftdown(t, size); //注意这里是size,因为堆的大小没变
					    }
					}
					int main(){
					    int n;
					    cin >> n;



					    for(int i = 0 ; i < n ; i ++) cin >> a[i];
					    for(int i = 0 ; i < n ; i ++) cin >> b[i];

					    //插入排序比较容易检查,所以检查插入
					    int p = 1; 
					    while(p < n && b[p-1] <= b[p]) p++; //bug, 注意是 b[p-1] <= b[p], 也就是可以相等或者单调递增

					    //此时的p是指向右侧的第一个元素
					    int k = p;
					    while(p < n && a[p] == b[p]) p++;

					    if(p == n){ //说明是插入排序, bug, 容易错, p如果指向数组的最后一个ind,应该是n-1, 所以n-1+1 = n, 而不是if(p == n+1)
					        puts("Insertion Sort");

					        //进行插入排序之后的事情,从k开始向左打雷
					        while( k >= 1 && b[k-1] > b[k]) { //只有k左边有人才能打,所以k至少是ind == 1
					            swap(b[k-1], b[k]);
					            k--;
					        }

					    }
					    else{ //因为一定有解,所以是堆排序
					        //接下来确定右侧在哪里
					        int top = b[0];
					        int p = n-1;
					        while(p >= 1 && b[p] >= top) p--;

					        //此时p是左侧堆的最末尾的节点
					        swap(b[0],b[p]); //bug! 注意是先将堆顶给移到后面,然后我们在对前面0到q-1索引的元素排序
					        siftdown(0, p); //因为是0到p-1,所以size == p
					        puts("Heap Sort");
					    }

					    cout << b[0];
					    for(int i = 1; i < n; i ++) cout << " " << b[i];
					    cout << endl;

					    return 0;
					}

					作者：jackrrr
					链接：https://www.acwing.com/activity/content/code/content/486871/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1. 通过, 但是很不优雅
					#include <iostream>

					using namespace std;

					const int N = 110;

					int origin[N];
					int after[N];

					int n;

					void down(int i, int size){
						int t = i, l = t * 2 + 1, r = l + 1;
						if(l < size && after[l] > after[t]) t = l;
						if(r < size && after[r] > after[t]) t = r;
						if(t != i){
							swap(after[i], after[t]);
							down(t, size);
						}
					}

					int main(){

						cin >> n;
						

						for(int i = 0; i < n; i++){
							cin >> origin[i];
						}
						for(int i = 0; i < n; i++){
							cin >> after[i];
						}

						int i = 0;
						for(; i + 1 < n; i++){
							if(after[i] > after[i+1]) break;
						}

						bool isInsert = true;
						int next = i + 1;
						while(next < n){
							if(after[next] != origin[next]){
								isInsert = false;
								break;
							}
							next++;
						}
					    i++;
						if(isInsert){
							puts("Insertion Sort");
							int t = after[i];
							while(i >= 1 && after[i-1] > t){
								after[i] = after[i-1];
								i--;
							}
							after[i] = t;
						}
						else{
							puts("Heap Sort");
							int a = n - 1;
							while(after[0] <= after[a]) a--;
							swap(after[0], after[a]);
							down(0, a);
						}

						cout << after[0];
						for(int k = 1; k < n; k++) cout << " " << after[k];
						cout << endl;
						return 0;	
					}
				r2.
					#include <iostream>

					using namespace std;

					const int N = 110;
					int n;
					int a[N];
					int b[N];

					void down(int u, int size){
						int l = u * 2, r = u * 2 + 1;
						int t = u;
						if(l <= size && b[l] > b[u]) t = l;
						if(r <= size && b[r] > b[l]) t = r;
						if(t != u){
							swap(b[u], b[t]);
							down(t, size);
						}
					}

					int main(){
						cin >> n;
						for(int i = 1; i <= n; i++) cin >> a[i];
						for(int i = 1; i <= n; i++) cin >> b[i];

						int k = 2;
						while(k <= n && b[k-1] <= b[k]) k++;
					// 	cout << k;
						int l = k;
						while(k <= n && a[k] == b[k]) k++;
						if(k == n + 1){ 
							puts("Insertion Sort");
							int temp = b[l];
							while(l >= 2 && b[l-1] > temp){
								b[l] = b[l-1];
								l--;
							}
							b[l] = temp;
						}
						else{
							puts("Heap Sort");
							int j = n;
							while(b[1] <= b[j]) j--;
							swap(b[1], b[j]);
							down(1, j-1);
						}

						cout << b[1];
						for(int i = 2; i <= n; i++) cout << " " << b[i];
						cout << endl;

						return 0;
					}
				r3.
					#include <iostream>
					using namespace std;

					const int N = 110;
					int n;
					int a[N];
					int b[N];

					void down(int u, int size){
					    int t = u, l = u * 2, r = l + 1;
					    if(l <= size && b[l] > b[u]) t = l;
					    if(r <= size && b[r] > b[l]) t = r;
					    if(t != u){
					        swap(b[u], b[t]);
					        down(t, size);
					    }
					}

					int main(){
					    cin >> n;
					    for(int i = 1; i <= n; i++) cin >> a[i];
					    for(int i = 1; i <= n; i++) cin >> b[i];
					    
					    int k = 2;
					    while(k <= n && b[k-1] <= b[k]) k++;
					    int t = k;
					    while(k <= n && b[k] == a[k]) k++;
					    if(k == n+1){
					        puts("Insertion Sort");
					        int temp = b[t];
					        while(b[t-1] > temp){
					            b[t] = b[t-1];
					            t--;
					        }
					        b[t] = temp;
					    }
					    else{
					        puts("Heap Sort");
					        int l = n;
					        while(b[1] <= b[l]) l--;
					        swap(b[1], b[l]);
					        down(1, l-1);
					    }
					    
					    cout << b[1];
					    for(int i = 2; i <= n ; i++) cout << " " << b[i];
					    cout << endl;
					    return 0;
					}
				r4.
					#include <iostream>

					using namespace std;

					const int N = 110;
					int n;
					int a[N];
					int b[N];

					void down(int u, int size){
					    int t = u, l = u * 2, r = l + 1;
					    if(l <= size && b[l] > b[u]) t = l;
					    if(r <= size && b[r] > b[l]) t = r;
					    if(u != t){
					        swap(b[u], b[t]);
					        down(t, size);
					    }
					}

					int main(){
					    cin >> n;
					    for(int i = 1; i <= n; i ++) cin >> a[i];
					    for(int i = 1; i <= n; i ++) cin >> b[i];
					        
					    int k = 2;
					    while(k <= n && b[k-1] <= b[k]) k++;
					    int t = k;
					    while(k <= n && b[k] == a[k]) k++;
					    
					    if(k == n+1){
					        puts("Insertion Sort");
					        int temp = b[t];
					        while(t >= 2 && b[t-1] > temp){
					            b[t] = b[t-1];
					            t--;
					        }
					        b[t] = temp;
					    }
					    else{
					        puts("Heap Sort");
					        int l = n;
					        while(b[1] <= b[l]) l--;
					        swap(b[1], b[l]);
					        down(1, l-1);
					    }
					    
					    cout << b[1];
					    for(int i = 2; i <= n; i++) cout << " " << b[i];
					    cout << endl;
					    
					    return 0;
					    
					    
					}
				r5.
					#include <iostream>

					using namespace std;

					const int N = 110;
					int n;
					int a[N], b[N];

					void down(int u, int size){
					    int t = u, l = u * 2, r = l + 1;
					    if(l <= size && b[l] > b[u]) t = l;
					    if(r <= size && b[r] > b[l]) t = r;
					    if(u != t){
					        swap(b[u], b[t]);
					        down(t, size);
					    }
					}
					int main(){
					    cin >> n;
					    for(int i = 1; i <= n; i++) cin >> a[i];
					    for(int i = 1; i <= n; i++) cin >> b[i];
					    
					    int k = 2;
					    while(k <= n && b[k-1] <= b[k]) k ++;
					    int t = k;
					    while(k <= n && b[k] == a[k]) k++;
					    if(k == n + 1){
					        puts("Insertion Sort");
					        int temp = b[t];
					        while(t >= 2 && b[t-1] > temp){
					            b[t] = b[t-1];
					            t--;
					        }
					        b[t] = temp;
					    }
					    else{
					        puts("Heap Sort");
					        int l = n;
					        while(b[1] <= b[l]) l--;
					        swap(b[1], b[l]);
					        down(1, l-1);
					    }
					    
					    cout << b[1];
					    for(int i = 2; i <= n; i++) cout << " " << b[i];
					    cout << endl;
					    return 0;
					    
					    
					}

	9. 2020年10月13日08:28:53

		40. 1579. 插入还是归并	1089
			0. bug
			1. 笔记
				1. sort(), 用于数组[]
					两个参数都是指针
					例如我要处理[i,j]这个区间
						sort(arr + i, arr + j + 1); 一定记得j+1
					如果我要处理从i开始, 长度为len的区间, 也就是[i, i + len - 1]
						sort(arr + i, arr + (i + len));
				2. 模板, 每隔len的长度处理一次:
					for(int i = 0; i < n; i += len){
						sort(arr + i, arr + min(i + len, n)); 因为我们要保证指针不越界, 所以是min(i + len, n)
					}
				3. 我喜欢老师的这个逻辑:
					int l = 1;
					while(true)
			        {
			            bool match = check();
			            
			            int len = 1 << l;
			            for(int i = 0; i < n; i += len){
			                sort(a + i , a + min(n, i + len));
			            }
			            
			            if(match){
			                print(a);
			                break;
			            }
			            l++;
			        }
			        1.
				        也就是先用没有加工过的arr来判断是否是match
				        然后不管有没有match,都进行往下迭代一次
				        如果是match, 说明刚刚迭代的就是我们要的东西
				        如果没有match, 然后再看下刚刚迭代的东西, 是不是match
				    2. 从 l == 1开始的原因:
				    	假设极端的, b数组 == a数组, 说明一次都没有迭代, 所以我们 l == 1, 就可以是迭代第一次


			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					int n;
					int a[N], b[N];

					bool check()
					{
					    for (int i = 0; i < n; i ++ )
					        if (a[i] != b[i])
					            return false;
					    return true;
					}

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ ) cin >> a[i];
					    for (int i = 0; i < n; i ++ ) cin >> b[i];

					    int k = 0;
					    while (b[k + 1] >= b[k]) k ++ ;

					    bool match = true;
					    for (int i = k + 1; i < n; i ++ )
					        if (a[i] != b[i])
					        {
					            match = false;
					            break;
					        }

					    if (match)
					    {
					        puts("Insertion Sort");
					        sort(b, b + k + 2);
					        cout << b[0];
					        for (int i = 1; i < n; i ++ ) cout << ' ' << b[i];
					        cout << endl;
					    }
					    else
					    {
					        puts("Merge Sort");

					        int k = 1;
					        while (true)
					        {
					            bool match = check();

					            int len = 1 << k;
					            for (int i = 0; i < n; i += len)
					                sort(a + i, a + min(n, i + len));

					            if (match) break;
					            k ++ ;
					        }

					        cout << a[0];
					        for (int i = 1; i < n; i ++ ) cout << ' '<< a[i];
					        cout << endl;
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/323536/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 110;
					int n;
					int a[N], b[N];

					bool check(){
						for(int i = 0; i < n; i++){
							if(a[i] != b[i]) return false;
						}
						return true;
					}

					void print(int* c){
					    cout << c[0];
						for(int i = 1; i < n; i++) cout << " " << c[i];
						cout << endl;
					}

					int main(){
						cin >> n;
						for(int i = 0; i < n; i++) cin >> a[i];
						for(int i = 0; i < n; i++) cin >> b[i];

						int k = 1;
						while(k < n && b[k-1] <= b[k]) k++;
						int t = k;
						while(k < n && b[k] == a[k]) k++;
						if(k == n){
							puts("Insertion Sort");
							int temp = b[t];
							while(t >= 1 && b[t-1] > temp){
								b[t] = b[t-1];
								t--;
							}
							b[t] = temp;
							print(b);
						}
						else{
							puts("Merge Sort");
							int l = 1;
							while(true){
								bool match = check();
								int len = 1 << l;

								for(int i = 0; i < n; i += len){
									sort(a + i, a + min(i + len, n));
								}

								if(match) break;
								l++;
							}
							print(a);
						}

						return 0;
					}
				r2.
					#include <iostream>
					#include <algorithm>

					using namespace std;
					const int N = 110;
					int n;
					int a[N], b[N];

					bool check(){
					    for(int i = 0; i <n ; i++) if(a[i] != b[i]) return false;
					    return true;
					}

					void print(int* c){
					    cout << c[0];
					    for(int i = 1; i < n ; i++) cout << " " <<c[i];
					    cout << endl;
					}
					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> a[i];
					    for(int i = 0; i < n ;i ++) cin >> b[i];
					    
					    int k = 1;
					    while(k < n && b[k-1] <= b[k]) k++;
					    int t = k;
					    while(k < n && a[k] == b[k]) k++;
					    
					    if(k == n){
					        puts("Insertion Sort");
					        int temp = b[t];
					        while(t-1 >= 0 && b[t-1] > temp){
					            b[t] = b[t-1];
					            t--;
					        }
					        b[t] = temp;
					        print(b);
					    }
					    else{
					        puts("Merge Sort");
					        int l = 1;
					        while(true){
					            bool match = check();
					            
					            int len = 1 << l;
					            for(int i = 0; i < n; i += len){
					                sort(a + i, a + min(i + len, n));
					            }
					            
					            if(match){
					                print(a);
					                break;
					            }
					            l ++;
					        }
					    }
					    
					    return 0;
					}
				r3.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 110;
					int n;
					int a[N], b[N];

					void print(int* c){
					    cout << c[0];
					    for(int i = 1; i < n; i++) cout << " " << c[i];
					    cout << endl;
					}

					bool check(){
					    for(int i = 0; i < n; i++) if(a[i] != b[i]) return false;
					    return true;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> a[i];
					    for(int i = 0; i < n; i++) cin >> b[i];
					    
					    int k = 1;
					    while(k < n && b[k-1] <= b[k]) k++;
					    int t = k;
					    while(k < n && a[k] == b[k]) k++;
					    
					    if(k == n){
					        puts("Insertion Sort");
					        sort(b, b + t + 1);
					        print(b);
					    }
					    else{
					        puts("Merge Sort");
					        
					        int l = 1;
					        while(true)
					        {
					            bool match = check();
					            
					            int len = 1 << l;
					            for(int i = 0; i < n; i += len){
					                sort(a + i , a + min(n, i + len));
					            }
					            
					            if(match){
					                print(a);
					                break;
					            }
					            l++;
					        }
					    }
					    
					    return 0;
					}
				r4.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 110;
					int n;
					int a[N], b[N];

					void print(int* c){
					    cout << c[0];
					    for(int i = 1; i < n; i++) cout << " " <<c[i];
					    cout << endl;
					}

					bool check(){
					    for(int i = 0; i < n; i++) if(a[i] != b[i]) return false;
					    return true;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> a[i];
					    for(int i = 0; i < n; i++) cin >> b[i];
					    
					    int k = 1;
					    while(k < n && b[k-1] <= b[k]) k++;
					    int t = k;
					    while(k < n && a[k] == b[k]) k++;
					    
					    if(k == n){
					        puts("Insertion Sort");
					        sort(b, b + t + 1);
					        print(b);
					    }
					    else{
					        puts("Merge Sort");
					        
					        int l = 1;
					        while(true){
					            bool match = check();
					            int len = 1 << l;
					            for(int i = 0; i < n; i += len){
					                sort(a + i, a + min(i + len, n));
					            }
					            
					            if(match){
					                print(a);
					                break;
					            }
					            l++;
					        }
					    }
					    
					    return 0;
					}
				r5.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 110;
					int n;
					int a[N], b[N];

					void print(int *c){
					    cout << c[0];
					    for(int i = 1; i < n; i++) cout << " " << c[i];
					    cout << endl;
					}

					bool check(){
					    for(int i = 0; i <n; i++) if(a[i] != b[i]) return false;
					    return true;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> a[i];
					    for(int i = 0; i < n; i++) cin >> b[i];
					    
					    int k = 1;
					    while(k < n && b[k-1] <= b[k]) k++;
					    int t = k;
					    while(k < n && a[k] == b[k]) k++;
					    
					    if(k == n){
					        puts("Insertion Sort");
					        sort(b, b + t + 1);
					        print(b);
					    }
					    else{
					        puts("Merge Sort");
					        
					        int l = 1;
					        while(true){
					            
					            bool match = check();
					            
					            int len = 1 << l;
					            for(int i = 0; i <n; i += len){
					                sort(a + i, a + min(i + len, n));
					            }
					            
					            if(match){
					                print(a);
					                break;
					            }
					            
					            l++;
					        }
					    }
					    
					    return 0;
					}

		41. 789. 数的范围 模板题
			0. bug
			1. 笔记
				0. 其他更加灵活的cmin和cmax (不再是从小到大,而是从大到小排), 见1527.
				1. 细节
					1. 先直接上 int mid = l + (r-l) / 2;
					2. 然后思考一个true的情况:
						1. 画面中, xx[mid]是固定在xx数组中间的
						2. 但是, 你的目标值是移动的,
							想象如何变成true
								1. 如果是求==target的起始位置
									就想着: 这个位置的点有什么特点?
										特点是, 这个位置右侧的点都 >= target
										所以我们干脆就让xx[mid] >= target; 这样就满足了右侧的点的条件.
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
							此时, 不用想, false 的情况就是l = mid + 1;
								l 比 r 优越, 所以是 + 1

						2. 如果我们的想要的区间在右侧[mid, r]. 例如求==target的终止位置, 就是希望继续往右边找
							也就是从[l, r]变成[mid, r], 所以r不变, l = mid;
							一旦l = mid; 二话不说, 将之前的mid加一: int mid = l + (r-l)/2 + 1;
							此时, 不用想, false 的情况就是r = mid - 1;
								r 比 l 低贱, 所以是 - 1
				2. 总结: 右改mid(谐音, 又改mid)
					1. 思考一个xx[mid]满足要求的情况, 也就是true的情况,
						通过固定xx[mid], 移动target
					2. 如果true, 你是想继续往左还是往右? 就是想象画面,[l,mid]是左边和[mid,r]是右边,你要哪个
						1. 往左. r = mid, l = mid + 1;
						2. 往右, 小心啦!!, l = mid, r = mid - 1; mid = l + (r-l)/2 + 1;
					
			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int  N = 100010;

					int n, m;
					int q[N];


					int main()
					{
					    scanf("%d%d", &n, &m);
					    for (int i = 0; i < n; i ++ )
					    {
					        scanf("%d", &q[i]);
					        if (q[i] > 10000) puts("!");
					    }

					    while (m -- )
					    {
					        int x;
					        scanf("%d", &x);

					        int l = 0, r = n - 1;
					        while (l < r)
					        {
					            int mid = l + r >> 1;
					            if (q[mid] >= x) r = mid;
					            else l = mid + 1;
					        }

					        if (q[r] != x) puts("-1 -1");
					        else
					        {
					            int left = l;
					            l = 0, r = n - 1;
					            while (l < r)
					            {
					                int mid = l + r + 1 >> 1;
					                if (q[mid] <= x) l = mid;
					                else r = mid - 1;
					            }

					            int right = r;

					            printf("%d %d\n", left, right);
					        }
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/273115/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int  N = 100010;

					int n, m;
					int q[N];


					int main()
					{
					    scanf("%d%d", &n, &m);
					    for (int i = 0; i < n; i ++ )
					    {
					        scanf("%d", &q[i]);
					        if (q[i] > 10000) puts("!");
					    }

					    while (m -- )
					    {
					        int x;
					        scanf("%d", &x);

					        int l = 0, r = n - 1;
					        while (l < r)
					        {
					            int mid = l + r >> 1;
					            if (q[mid] >= x) r = mid;
					            else l = mid + 1;
					        }

					        if (q[r] != x) puts("-1 -1");
					        else
					        {
					            int left = l;
					            l = 0, r = n - 1;
					            while (l < r)
					            {
					                int mid = l + r + 1 >> 1;
					                if (q[mid] <= x) l = mid;
					                else r = mid - 1;
					            }

					            int right = r;

					            printf("%d %d\n", left, right);
					        }
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/273115/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1. 写的很顺利, 1c1a
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int n, m;
					int a[N];
					int q;

					int checkmin()
					{
						int l = 0, r = n-1;
						while(l < r){
							int mid = l + (r-l)/2;
							if(q <= a[mid]) r = mid;
							else l = mid + 1;
						}
						if(a[r] == q) return r;
						return -1;
					}

					int checkmax(){
						int l = 0, r = n - 1;
						while(l < r){
							int mid = l + (r-l)/2 + 1;
							if(a[mid] <= q) l = mid;
							else r = mid - 1;
						}
						if(a[r] == q) return r;
						return -1;
					}
					int main(){
						cin >> n >> m;
						for(int i = 0; i < n; i++) cin >> a[i];


						while(m--){
							cin >> q;

							int l = checkmin();
							int r = checkmax();
							cout << l << " " << r << endl;
						}

						return 0;
					}
				r2.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int n, m;
					int a[N];
					int q;

					int cmin(){
					    int l = 0, r = n-1;
					    while(l < r){
					        int mid = l + (r-l)/2;
					        if(q <= a[mid]) r = mid;
					        else l = mid + 1;
					    }
					    if(a[r] == q) return r;
					    return -1;
					}

					int cmax(){
					    int l = 0, r = n - 1;
					    while(l < r){
					        int mid = l + (r-l)/2 + 1;
					        if(a[mid] <= q) l = mid;
					        else r = mid - 1;
					    }
					    if(a[r] == q) return r;
					    return -1;
					}

					int main(){
					    cin >> n >> m;
					    for(int i = 0; i < n ; i++) cin >> a[i];
					    
					    while(m--){
					        cin >> q;
					        int l = cmin();
					        int r = cmax();
					        cout << l << " " << r << endl;
					    }
					    return 0;
					}
				r3.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int n, m, q;
					int a[N];

					int cmin(){
					    int l = 0, r = n-1;
					    while(l <r){
					        int mid = l + (r-l)/2;
					        if(q <= a[mid]) r = mid;
					        else l = mid + 1;
					    }
					    if(q == a[r]) return r;
					    return -1;
					}

					int cmax(){
					    int l = 0, r = n - 1;
					    while(l < r){
					        int mid = l + (r-l)/2 + 1;
					        if(a[mid] <= q) l = mid;
					        else r = mid - 1;
					    }
					    if(q == a[r]) return r;
					    return -1;
					}
					int main(){
					    cin >> n >> m;
					    for(int i = 0; i < n; i++) cin >> a[i];
					    
					    while(m--){
					        cin >> q;
					        int l = cmin();
					        int r = cmax();
					        cout << l << " " << r << endl;
					    }
					    
					    return 0;
					}
				r4.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int n, m, q;
					int a[N];

					int cmin(){
					    int l = 0, r = n-1;
					    while(l < r){
					        int mid = l + (r-l)/2;
					        if(q <= a[mid]) r = mid;
					        else  l = mid + 1;
					    }
					    if(q == a[r]) return r;
					    return -1;
					}

					int cmax(){
					    int l = 0, r = n - 1;
					    while(l < r){
					        int mid = l + (r-l)/2 + 1;
					        if(a[mid] <= q) l = mid;
					        else r = mid - 1;
					    }
					    if(q == a[r]) return r;
					    return -1;
					}

					int main(){
					    
					    cin >> n >> m;
					    for(int i = 0; i <n ; i++) cin >>a[i];
					    
					    while(m--){
					        cin >> q;
					        int l = cmin();
					        int r = cmax();
					        cout << l << " " << r << endl;
					     }
					     
					     return 0;
					    
					}
				r5.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int n, m, q;
					int a[N];

					int cmin(){
					    int l = 0, r = n-1;
					    while(l < r){
					        int mid = l + (r-l)/2;
					        if(q <= a[mid]) r = mid;
					        else l = mid + 1;
					    }
					    if(q == a[r]) return r;
					    return -1;
					}

					int cmax(){
					    int l = 0, r = n-1;
					    while(l < r){
					        int mid = l + (r-l)/2 + 1;
					        if(a[mid] <= q) l = mid;
					        else r = mid - 1;
					    }
					    if(a[r] == q) return r;
					    return -1;
					}

					int main(){
					    cin >> n >> m;
					    for(int i = 0; i < n; i++) cin >> a[i];
					    
					    while(m--){
					        cin >> q;
					        int l = cmin();
					        int r = cmax();
					        cout << l << " " << r << endl;
					    }
					    
					    return 0;
					}

		42. 838. 堆排序 	模板题
			0. bug
				总是容易写错的地方:
					1. 
						void down(int u, int size){
							int t = u, l = u * 2, r = l + 1;
							if(l <= size && a[l] < a[t]) t = l; 容易错写成  a[l] < a[u]
							if(r <= size && a[r] < a[t]) t = r; 容易错写成  a[r] < a[l]
							if(t != u){
								swap(a[t], a[u]);
								down(t, size); 容易错写成 down(1, size);
							}
						}
					2. heapify
						for(int i = n/2; i; i--) down(i, size); 容易写错的地方: 是 down(i, size), 而不是 down(1, size)

			1. 笔记
				1. 堆排序:
					1. 首先读取的时候一定是从index == 1开始读取
					2. 其次, 先heapify, 也就是从最后一个非叶子节点读取, 
						它的ind是 n / 2
							举例, 节点是1, (2,3), (4). 那么的确 4/2 == 2是 最后一个非叶子节点
							当节点是 1, (2,3), (4,5), (6, 7). 那么的确 7/2==3是 最后一个非叶子节点
						for(int i = n/2; i; i--) down(i, size); 容易写错的地方: 是 down(i, size), 而不是 down(1, size)
							其中i的意思是 i >= 1
					3. 其中down()的时候, 是小的元素放到heap的顶部
					4. heap排序, 我们只能保证top是最小的,所以要一个一个取出top,然后把
						swap(a[1], a[size]);
						size--;
						之后down的时候, size的范围要缩小
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
					链接：https://www.acwing.com/activity/content/code/content/273116/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int n, m;
					int a[N];

					void down(int u, int size){
						int t = u, l = u * 2, r = l + 1;
						if(l <= size && a[l] < a[u]) t = l;
						if(r <= size && a[r] < a[t]) t = r;
						if(t != u){
							swap(a[u], a[t]);
							down(t, size);
						}
					}

					int main(){
						scanf("%d %d", &n, &m);
						int size = n;
						for(int i = 1; i <= n; i++) scanf("%d ", &a[i]);
						
						

						for(int i = n/2; i >= 1; i--) down(i, size);

						for(int i = 0; i < m; i ++){
							printf("%d ", a[1]);
							a[1] = a[size--];
					// 		size--;
							down(1, size);
						}

					    puts("");
						return 0;

					}
				r2.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int n, m;
					int a[N];

					void down(int u, int size){
					    int t = u, l = u *2, r = l + 1;
					    if(l <= size && a[l] < a[t]) t = l;
					    if(r <= size && a[r] < a[t]) t = r;
					    if(t != u){
					        swap(a[t], a[u]);
					        down(t, size);
					    }
					}

					int main(){
					    scanf("%d %d", &n, &m);
					    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
					    int size = n;
					    
					    for(int i = n/2; i; i--) down(i, size);
					    
					    while(m--){
					        printf("%d ", a[1]);
					        swap(a[1], a[size--]);
					        down(1, size);
					    }
					    puts("");
					    return 0;
					}
				r3.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int n, m;
					int a[N];

					void down(int u, int size){
					    int t = u, l = u *2 , r = l + 1;
					    if(l <= size && a[l] < a[t]) t = l;
					    if(r <= size && a[r] < a[t]) t = r;
					    if(t != u){
					        swap(a[t], a[u]);
					        down(t, size);
					    }
					}
					int main(){
					    scanf("%d %d", &n, &m);
					    int size = n;
					    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
					    
					    for(int i = n/2; i ; i--) down(i, size);
					    
					    for(int i = 0; i <m; i++){
					        printf("%d ", a[1]);
					        a[1] = a[size--];
					        down(1, size);
					    }
					    
					    puts("");
					    return 0;
					}
				r4.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int n, m;
					int a[N];

					void down(int u, int size){
					    int t = u, l = u *2, r = l +1;
					    if(l <= size && a[l] < a[t]) t = l;
					    if(r <= size && a[r] < a[t]) t = r;
					    if(t != u){
					        swap(a[u], a[t]);
					        down(t, size);
					    }
					}

					int main(){
					    scanf("%d%d", &n, &m);
					    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
					    int size = n;
					    for(int i = n/2; i ; i--) down(i, size);
					    while(m--){
					        printf("%d ", a[1]);
					        a[1] = a[size];
					        size--;
					        down(1, size);
					    }
					    puts("");
					    return 0;
					}
				r5.	
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int n, m;
					int a[N];

					void down(int u, int size){
					    int t = u, l = u *2 ,r = l + 1;
					    if(l <= size && a[l] < a[t]) t = l;
					    if(r <= size && a[r] < a[t]) t = r;
					    if(t != u){
					        swap(a[t], a[u]);
					        down(t, size);
					    }
					}

					int main(){
					    
					    scanf("%d%d", &n, &m);
					    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
					    int size = n;
					    for(int i = n/2; i ; i--) down(i, size);
					    while(m--){
					        printf("%d ", a[1]);
					        a[1] = a[size];
					        size--;
					        down(1, size);
					    }
					    puts("");
					    return 0;
					}

5. 树
		43. 826. 单链表	模板题
			0. bug
				1. 这道题中, 如果是remove的k==0,说明删除头结点. 但是我总觉得怪怪的, 为什么不是1
				2. 不要忘了init(){head = -1;} 我就忘了, 有时候是写了init(),但是忘记加入main()中了
				3. 题目是说第k个后面add或者remove, 这个k是从1开始的, 记得是k-1. add(k-1, x), remove(k-1)
			1. 笔记
				1.
					1. i != -1
						for(xx; ~i; xx)
					2. i >= 1 或者说 i > 0
						for(xx; i ; xx);
					3. i == 0
						if(!i)
				2. 要记的模板:
					int head, e[N], ne[N];
					int ind;

					void init(){
						head = -1;
						ind = 0;
					}

					void add_head(int a){
						e[ind] = a, ne[ind] = head, head = ind++;
					}

					//假设之前是 (头结点) a --> b --> c --> d --> -1, 其中b是a的next,现在要变成a --> b --> e --> c --> d --> -1
					//其中b是第3个加入的节点, 在b的后面加上一个数, 这里的后面是next
					void add_k(int a, int k){ 在k的前面加上一个新的数字, 所以这个新的数字的next是k
						e[ind] = a, ne[ind] = ne[k], ne[k] = ind++; //也就是我ind要指向你k的下一位,你k指向我
					}


					void remove(int k){ 
						ne[k] = ne[ne[k]]; //我k不指向我的下一个了,我指向我next的next
					}

					void remove_head(){
						head = ne[head];
					}

					add规律:
						e[ind] = xx, ne[ind] = yy, yy = ind++;

						想象: 我先创建一个新的节点, 这个节点的e, 和ne要设置好, 最后我要给这个节点一个名分, 也就是让yy链接它
							
						xx是元素
						yy是head, 或者是ne[k]
							e[ind] = xx, ne[ind] = head, head = ind++;
								我ind的元素是xx, 我ind的下一个是旧头head, 新头head是我ind, 最后ind++
							e[ind] = xx, ne[ind] = ne[k], ne[k] = ind++;
								我ind的元素是xx, 我ind的下一个是它k的下一个ne[k], 它k的下一个现在是我ind, 最后ind++

					remove规律:
						yy = ne[yy]
							ne[k] = ne[ne[k]]; 
								k的下一个 是 k的下一个 的下一个
							head = ne[head];
								头 是 头的下一个

					最后是遍历
						for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';

			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010;

					int head, e[N], ne[N], idx;

					void init()
					{
					    head = -1;
					}

					void add_head(int x)
					{
					    e[idx] = x, ne[idx] = head, head = idx ++ ;
					}

					void add_k(int k, int x)
					{
					    e[idx] = x, ne[idx] = ne[k], ne[k] = idx ++ ;
					}

					void remove(int k)
					{
					    ne[k] = ne[ne[k]];
					}

					int main()
					{
					    init();

					    int m;
					    cin >> m;
					    while (m -- )
					    {
					        char op;
					        int k, x;
					        cin >> op;
					        if (op == 'H')
					        {
					            cin >> x;
					            add_head(x);
					        }
					        else if (op == 'I')
					        {
					            cin >> k >> x;
					            add_k(k - 1, x);
					        }
					        else
					        {
					            cin >> k;
					            if (!k) head = ne[head];
					            else remove(k - 1);
					        }
					    }

					    for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
					    cout << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/280325/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int head, e[N], ne[N];
					int ind;

					void init(){
						head = -1;
						ind = 0;
					}

					void add_head(int a){
						e[ind] = a, ne[ind] = head, head = ind++;
					}

					假设之前是 (头结点) a --> b --> c --> d --> -1, 其中b是a的next,现在要变成a --> b --> e --> c --> d --> -1
					其中b是第3个加入的节点, 在b的后面加上一个数, 这里的后面是next
					void add_k(int a, int k){
						e[ind] = a, ne[ind] = ne[k], ne[k] = ind++; 也就是我ind要指向你k的下一位,你k指向我
					}


					void remove(int k){
						ne[k] = ne[ne[k]]; 我k不指向我的下一个了,我指向我next的next
					}
					int main(){

						init();

						int m;
						cin >> m;
						while(m--){
							char op; 老师用的是char
							int k, x;
							cin >> op;
							if(op == 'H'){
								cin >> x;
								add_head(x);
							}
							else if(op == 'I'){
								cin >> k >> x;
								add_k(x, k-1); 因为说的是第1个加入的元素,其实是ind==0的位置,所以k-1
							}
							else{
								cin >> k;
								if(!k) head = ne[head]; head的next是ne[head], 所以head变成head的next
								remove(k-1); 因为说的是第1个加入的元素,其实是ind==0的位置,所以k-1
							}
						}

						for(int i = head; ~i; i = ne[i]){
							cout << e[i] << " ";
						}
						cout << endl;

						return 0;

					}
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int m;

					int head, e[N], ne[N], ind;

					void add_head(int x){
						e[ind] = x, ne[ind] = head, head = ind++;
					}

					void add(int x, int k){
						e[ind] = x, ne[ind] = ne[k], ne[k] = ind++;
					}

					void remove(int k){
						ne[k] = ne[ne[k]];
					}

					void init(){
					    head = -1;
					}

					int main(){
					    
					    init();
						cin >> m;
						char t;
						int x, k;
						while(m--){
							cin >> t;
							if(t == 'H'){
								cin >> x;
								add_head(x);
							}
							else if(t == 'I'){
								cin >> k >> x;
								add(x, k-1);
							}
							else{
								cin >> k;
								if(k == 0) head = ne[head];
								else remove(k-1);
							}
						}

						for(int i = head; ~i; i = ne[i]){
							cout << e[i] << " ";
						}
						cout << endl;
						return 0;
					}
				r2.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int head, e[N], ne[N], ind;

					void init(){
					    head = -1;
					}

					void add_head(int x){
					    e[ind] = x, ne[ind] = head, head = ind++;
					}

					void add(int k, int x){
					    e[ind] = x, ne[ind] = ne[k], ne[k] = ind++;
					}

					void remove_head(){
					    head = ne[head];
					}

					void remove(int k){
					    ne[k] = ne[ne[k]];
					}

					void print()
					{   
					    for(int i = head; ~i; i = ne[i]) cout << e[i] << " ";
					    cout << endl;
					}

					int main(){
					    init();
					    int m;
					    cin >> m;
					    char c;
					    int k, x;
					    while(m--){
					        cin >>c;
					        if(c == 'H'){
					            cin >> x;
					            add_head(x);
					        }
					        else if(c == 'I'){
					            cin >> k >> x;
					            add(k-1, x);
					        }
					        else{
					            cin >> k;
					            if(!k) remove_head();
					            else remove(k-1);
					        }
					    }
					    
					    print();
					    return 0;
					}
				r3.
						#include <iostream>

						using namespace std;

						const int N = 100010;
						int head, e[N], ne[N], ind;

						void init(){
						    head = -1;
						}

						void add_head(int x)
						{
						    e[ind] = x, ne[ind] = head, head = ind++;
						}

						void add(int k, int x){
						    e[ind] = x, ne[ind] = ne[k], ne[k] = ind++;
						}

						void remove(int k){
						    ne[k] = ne[ne[k]];
						}

						void remove_head()
						{
						    head = ne[head];
						}
						    
						int main(){
						    
						    init();
						    int m;
						    cin >> m;
						    char c;
						    int k, x;
						    while(m--){
						        cin >> c;
						        if(c == 'H'){
						            cin >> x;
						            add_head(x);
						        }else if(c == 'I'){
						            cin >> k >> x;
						            add(k-1, x);
						        }else{
						            cin >> k;
						            if(!k) remove_head();
						            else remove(k-1);
						        }
						    }
						    
						    for(int i = head; ~i; i = ne[i]) cout << e[i] << " ";
						    cout << endl;
						    return 0;
						    
						}
				r4.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int head, e[N], ne[N], ind;

					void init(){
					    head = -1;
					}

					void add_head(int x){
					    e[ind] = x, ne[ind] = head, head = ind++;
					}

					void add(int k, int x){
					    e[ind] = x, ne[ind] = ne[k], ne[k] = ind++;
					}

					void remove_head(){
					    head = ne[head];
					}

					void remove(int k){
					    ne[k] = ne[ne[k]];
					}

					int main(){
					    
					    init();
					    int m;
					    cin >> m;
					    char c;
					    int k, x;
					    while(m--){
					        cin >> c;
					        if(c == 'H'){
					            cin >> x;
					            add_head(x);
					        }else if(c == 'I'){
					            cin >> k >> x;
					            add(k-1, x);
					        }else{
					            cin >> k;
					            if(!k) remove_head();
					            else remove(k-1);
					        }
					    }
					    
					    for(int i = head;  ~i; i = ne[i]) cout << e[i] << " ";
					    cout << endl;
					    return 0;
					}
				r5.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int head, e[N], ne[N], ind;

					void init(){
					    head = -1;
					}

					void add_head(int x)
					{
					    e[ind] = x, ne[ind] = head, head = ind++;
					}

					void add(int k, int x){
					    e[ind] = x, ne[ind] = ne[k], ne[k] = ind++;
					}

					void remove_head(){
					    head = ne[head];
					}

					void remove(int k){
					    ne[k] = ne[ne[k]];
					}

					int main(){
					    init();
					    int m;
					    cin >> m;
					    
					    char c;
					    int k, x;
					    while(m--){
					        cin >> c;
					        if(c == 'H'){
					            cin >> x;
					            add_head(x);
					        }else if( c == 'I'){
					            cin >> k >> x;
					            add(k-1, x);
					        }else{
					            cin >> k;
					            if(!k) remove_head();
					            else remove(k-1);
					        }
					    }
					    for(int i = head; ~i; i = ne[i]) cout << e[i] << " ";
					    cout << endl;
					    return 0;
					    
					}

		44. 836. 合并集合	模板题
			0. bug
				题目说节点编号是1-N
				所以一定是 for (int i = 1; i <= n; i ++ ) p[i] = i;
					而不是 for (int i = 0; i < n; i ++ ) p[i] = i;
				否则之后merge的两个东西就是错的了. 不过其实这道题的merge 和find如果我写成for (int i = 0; i < n; i ++ ) p[i] = i; 也不会错, 但是小心以后吧
			1. 笔记
				0. 并查集是非常容易考到的数据结构
				1. 模板:
					1. 初始化
						const int N = 100010;
						int p[N];
						for (int i = 1; i <= n; i ++ ) p[i] = i;

					2. find
						int find(int x) // 返回x的祖宗节点 + 路径压缩
						{
						    if (p[x] != x) p[x] = find(p[x]); 我x的父亲,是父亲的祖先
						    return p[x]; 返回x的祖先
						}

					3. Merge
						 p[find(a)] = find(b); a的祖宗的父亲 是 b的祖宗	
			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int n, m;
					int p[N];

					int find(int x) // 返回x的祖宗节点 + 路径压缩
					{
					    if (p[x] != x) p[x] = find(p[x]);
					    return p[x];
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    for (int i = 1; i <= n; i ++ ) p[i] = i;

					    while (m -- )
					    {
					        char op[2];
					        int a, b;
					        scanf("%s%d%d", op, &a, &b);

					        if (op[0] == 'M') p[find(a)] = find(b);
					        else
					        {
					            if (find(a) == find(b)) puts("Yes");
					            else puts("No");
					        }
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/280326/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int p[N];
					int n, m;

					void init(){
						for(int i = 0; i < n; i++) p[i] = i;
					}

					int find(int i){
						if(i != p[i]){
							p[i] = find(p[i]);
						}
						return p[i];
					}

					void merge(int i, int j){
						p[find(i)] = find(j);
					}

					int main(){
						cin >> n >> m;
						init();

						char c;
						int a, b;
						while(m--){
							cin >> c >> a >> b;
							if(c == 'M') merge(a,b);
							else {
								if(find(a) == find(b)) puts("Yes");
								else puts("No");
							}
						}
						return 0;
					}
				r2.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int p[N];

					int n, m;

					int find(int a){
					    if(a != p[a]) p[a] = find(p[a]);
					    return p[a];
					}

					int main(){
					    cin >> n >> m;
					    for(int i = 0; i < n; i++) p[i] = i;
					    
					    char c;
					    int a, b;
					    while(m--){
					        cin >> c >> a >> b;
					        if(c == 'M') p[find(a)] = find(b);
					        else{
					            if(find(a) == find(b)) puts("Yes");
					            else puts("No");
					        }
					    }
					    return 0;
					}
				r3.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int p[N];
					int n, m;

					int find(int a){
					    if(a != p[a]) p[a] = find(p[a]);
					    return p[a];
					}

					int main(){
					    cin >> n >> m;
					    for(int i = 0; i < n; i++) p[i] = i;
					    
					    char c;
					    int a, b;
					    while(m--){
					        cin >> c >> a >> b;
					        if(c == 'M') p[find(a)] = find(b);
					        else{
					            if(find(a) == find(b)) puts("Yes");
					            else puts("No");
					        }
					    }
					    return 0;
					}
				r4.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int p[N];
					int n, m;

					int find(int a){
					    if(a != p[a]) p[a] = find(p[a]);
					    return p[a];
					}

					int main(){
					    cin >> n >> m;
					    for(int i = 1; i <= n; i++) p[i] = i;
					    
					    char c;
					    int a, b;
					    while(m--){
					        cin >> c >> a >> b;
					        if(c == 'M') p[find(a)] = find(b);
					        else{
					            if(find(a) == find(b)) puts("Yes");
					            else puts("No");
					        }
					    }
					    return 0;
					}
				r5.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int p[N];
					int n, m;

					int find(int a){
					    if(a != p[a]) p[a] = find(p[a]);
					    return p[a];
					}

					int main(){
					    cin >> n >> m;
					    for(int i = 1; i <= n; i++) p[i] = i;
					    char c;
					    int a, b;
					    while(m--){
					        cin >> c >> a >> b;
					        if(c == 'M') p[find(a)] = find(b);
					        else{
					            if(find(a) == find(b)) puts("Yes");
					            else puts("No");
					        }
					    }
					    return 0;
					}
		
	10. 2020年10月14日01:31:21

		45. 1476. 数叶子结点	1004
			0. bug
				0. 竟然忘了memset()!!!忘记初始化了,一旦忘记就会mem limit exceeded
				1.  memset(h, -1, sizeof h); 不要写错, 并且要加上 #include <cstring>
				2. 打印的时候:
					 cout << cnt[0];
					    for(int i = 1; i <= max_depth; i++) cout <<" " << cnt[i];
					 注意是 i <= max_depth, 不是 i < max_depth;
			1. 笔记
				1. 
					1. 如何判断是否是叶节点
						if(h[a] == -1)说民是叶节点
				0.
					0. 因为这里的一个节点会有多个子节点, 所以我们不能只存左右子树, 而是用邻接表
					1. dfs和bfs都可以写这道题,但是老师更倾向于dfs,因为bfs需要维护队列
					2. 思路:
						1. 存树的形状
						3. 一般用dfs能做的bfs也能做,但是dfs代码短,不像bfs需要维护queue

						1. 主要考察树: 
						h[a]其实是a这个节点的叶子节点的token,这个token其实是ind,可以帮我们索引到一个链表,也就是说这个链表的所有元素,都是a这个节点的叶子节点
						假设h[a] == ind, 那么e[ind] == b说明节点a的一个子节点是b
						ne[ind] == ind2说明这个子节点b也有一个链表, 这个链表的token是ind2
							因为之前设置的时候ne[ind] = h[b]?

						故事是这样的,假设我们要给a节点的链表中插入一个b节点, 现在空余的token是ind
						h[a]表示的是, a节点的链表的头结点的token, 我们要注意, 加的方式是新来的元素是插入头结点, 想象:
						刚开始是h[a] = -1是什么都没有加过,之后分别加入cdf之后,链表是-1 -- c -- d -- f(头结点), 所以最后一个进入的f是在头结点
						谁是谁的next!!! c是d的next, 所以这是我之前纠结的地方,next是在左边, 其实你如果想象成f -- d -- c -- -1就是next在右边了! 
						所以假设d当时拿到的token是ind, ne[ind] == c的token!! 也就是b的next是c

						 现在空余的token是ind,既然ind还没用过, 我们就用吧
						e[ind] = b, 将e[ind]这个没有用过的地方, 放入b的值
						ne[ind] = h[a], 也就是我们将b的next,设置为之前的老的头结点(h[a])
						h[a] = ind++, 现在a节点的新的头节点是ind了!

						我给一个例子吧, 刚开始ind == 0, h[]所有初始化是-1
						void add(int a(8), int b(9))
						{
						    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
						    相当于是:
						    e[0] = 9, ne[0] = -1, h[8] = 0, ind = 1;
						}
						void add(int a(8), int c(7))
						{
						    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
						    相当于是:
						    e[1] = 7, ne[1] = 0, h[8] = 1, ind = 2;
						}

						遍历的时候:
						for (int i = h[u]; ~i; i = ne[i]) //注意-1的0x是1111 1111,所以~(-1) == 0
						        dfs(e[i]);
						i = h[8] == 1
						e[i] == e[1] 也就是c的值7
						i = ne[i] == ne[1] == 0, 也就是去到token是0的地方
						e[i] == e[0] 也就是b的值8
						i = ne[i] == ne[0] == -1
						结束
			2. 注释
				1. y
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					int n, m;
					int h[N], e[N], ne[N], idx;
					int cnt[N], max_depth;

					void add(int a, int b)
					{
					    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
					}

					void dfs(int u, int depth)
					{
					    if (h[u] == -1)  // 说明u是叶子节点
					    {
					        cnt[depth] ++ ;
					        max_depth = max(max_depth, depth);
					        return;
					    }

					    for (int i = h[u]; ~i; i = ne[i])
					        dfs(e[i], depth + 1);
					}

					int main()
					{
					    cin >> n >> m;

					    memset(h, -1, sizeof h);
					    for (int i = 0; i < m; i ++ )
					    {
					        int id, k;
					        cin >> id >> k;
					        while (k -- )
					        {
					            int son;
					            cin >> son;
					            add(id, son);
					        }
					    }

					    dfs(1, 0);

					    cout << cnt[0];
					    for (int i = 1; i <= max_depth; i ++ ) cout << ' ' << cnt[i];
					    cout << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/279623/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>
					#include <cstring> // memset()

					using namespace std;

					const int N = 110;
					int h[N], e[N], ne[N];
					int ind; //全局变量初始是0
					int cnt[N];
					int maxdepth;// 需要记录maxdepth, 因为我们打印的时候, 需要打印cnt[N]的前maxdepth个元素

					void add(int a, int b){
					    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
					}

					void dfs(int a, int depth){
					    if(h[a] == -1) //叶子,所以要插入到我们的cnt中
					    {
					        cnt[depth]++;
					        maxdepth = max(maxdepth, depth);
					        return;
					    }

					    for(int i = h[a]; i != -1; i = ne[i]){
					        dfs(e[i], depth+1);
					    }
					}

					int main(){
					    int n, m;
					    cin >> n >> m;

					    memset(h, -1, sizeof h);

					    while(m--){
					        int id, k;
					        cin >> id >> k;
					        while(k--){
					            int son;
					            cin >> son;
					            add(id, son);//将b链接到a上
					        }
					    }

					    dfs(1,0); //为什么是(1,0),因为题目说了根节点的值是01, 所以a==01==1, 然后第一层高度是0

					    cout << cnt[0]; //一定能保证有一个叶子,因为如果只有一个根节点, 根节点就是叶子
					    for(int i = 1; i <= maxdepth; i++) cout << " " << cnt[i];

					    cout << endl;

					    return 0;
					}

					作者：jackrrr
					链接：https://www.acwing.com/activity/content/code/content/487666/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 110;
					int h[N], e[N], ne[N], ind;
					int n, m;

					int cnt[N];
					int max_depth;

					void add(int a, int b){
						e[ind] = b, ne[ind] = h[a], h[a] = ind++;
					}

					void dfs(int a, int depth){
						if(h[a] == -1){
							cnt[depth]++;
							max_depth = max(max_depth, depth);
							return;
						}

						for(int i = h[a]; ~i; i = ne[i]){
							dfs(e[i], depth + 1);
						}
					}

					int main(){
						cin >> n >> m;
						memset(h, -1, sizeof h);

						int f, k, s;
						for(int i = 0; i < m; i++){
							cin >> f >> k;
							while(k--){
								cin >> s;
								add(f, s);
							}
						}

						dfs(1, 0);

						cout << cnt[0];
						for(int i = 1; i <= max_depth; i++) cout << " " << cnt[i];
						cout << endl;
						return 0;

					}
				r2.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 100;
					int h[N], e[N], ne[N], ind;
					int cnt[N], max_depth;

					void add(int a, int b){
					    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
					}

					void dfs(int a, int depth){
					    if(h[a] == -1){
					        cnt[depth]++;
					        max_depth = max(max_depth, depth);
					        return;
					    }    
					    
					    for(int i = h[a]; ~i; i = ne[i]){
					        dfs(e[i], depth + 1);
					    }
					}

					int main(){
					    int n, m;
					    cin >> n >> m;
					    memset(h, -1, sizeof h);
					    for(int i = 0; i < m ; i++){
					        int f, k, s;
					        cin >> f >> k;
					        while(k--){
					            cin >> s;
					            add(f, s);
					        }
					    }
					    
					    dfs(1, 0);
					    
					    cout << cnt[0];
					    for(int i = 1; i <= max_depth; i++) cout <<" " << cnt[i];
					    
					    cout << endl;
					    return 0;
					}
				r3.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 110;
					int h[N], e[N], ne[N], ind;
					int cnt[N], max_depth;

					void add(int a, int b){
					    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
					}

					void dfs(int a, int depth){
					    
					    if(h[a] == -1){
					        cnt[depth] ++;
					        max_depth = max(depth, max_depth);
					        return;
					    }
					    
					    for(int i = h[a]; ~i; i = ne[i]){
					        dfs(e[i], depth + 1);
					    }
					}


					int main(){
					    int n, m;
					    cin >> n >> m;
					    memset(h, -1, sizeof h);
					    while(m--){
					        int f, k, s;
					        cin >> f >> k;
					        while(k--){
					            cin >> s;
					            add(f, s);
					        }
					    }

					    dfs(1, 0);
					    

					    cout << cnt[0];
					    for(int i = 1; i <= max_depth; i++) cout << " " << cnt[i];
					    cout << endl;
					    return 0;
					    
					}
				r4.
						#include <iostream>
						#include <cstring>

						using namespace std;

						const int N = 110;
						int h[N], e[N], ne[N], ind;
						int cnt[N], max_depth;

						void add(int a, int b){
						    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
						}

						void dfs(int a, int depth){
						    
						    if(h[a] == -1){
						        cnt[depth] ++;
						        max_depth = max(depth, max_depth);
						        return;
						    }
						    
						    for(int i = h[a]; ~i; i = ne[i]){
						        dfs(e[i], depth + 1);
						    }
						}


						int main(){
						    memset(h, -1, sizeof h);
						    
						    int n, m;
						    cin >> n >> m;
						    while(m--){
						        int f, k, s;
						        cin >> f >> k;
						        while(k--){
						            cin >> s;
						            add(f, s);
						        }
						    }
						    
						    dfs(1, 0);
						    
						    cout << cnt[0];
						    for(int i = 1; i <= max_depth; i++) cout << " " << cnt[i];
						    cout << endl;
						    return 0;
						}
				r5.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 110;
					int h[N], e[N], ne[N], ind;
					int cnt[N], max_depth;

					void add(int a, int b){
					    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
					}

					void dfs(int a, int depth){
					    if(h[a] == -1){
					        cnt[depth] ++;
					        max_depth = max(depth, max_depth);
					        return;
					    }
					    
					    for(int i = h[a]; ~i; i = ne[i]){
					        dfs(e[i], depth + 1);
					    }
					}

					int main(){
					    
					    memset(h, -1, sizeof h);
					    
					    int n, m;
					    cin >> n >> m;
					    
					    while(m--){
					        int f, k, s;
					        cin >> f >> k;
					        while(k--){
					            cin >> s;
					            add(f, s);
					        }
					    }
					    
					    dfs(1, 0);
					    cout << cnt[0];
					    for(int i = 1; i <= max_depth; i ++) cout << " " << cnt[i];
					    cout << endl;
					    return 0;
					}

		46. 1497. 树的遍历	1020
			0. bug
			1. 笔记
				0. 考点:
					1. build(), 其实几句话就好了, 很简dan
														
						int build(int il, int ir, int pl, int pr){
							//找root的值
							int root_val = postorder[pr];//根节点的值
							int k = pos[root_val];//知道根节点在中序中的位置

							//判断有无左右子树, 通过看k在中序中的位置
							if(il < k) //有left, 如果il == k说明没有left树
							{
								l[root_val] = build(il, k-1, pl, pl + (k-1-il));//见解释
							}
							if(k < ir)
							{
								r[root_val] = build(k+1, ir, (pr-1) + (k+1-ir), pr-1);//bug!容易错的地方,pr是root(回忆int root_val = postorder[pr]]),所以是pr-1!
							}
							return root_val; //返回根的值
						}

					2. 层序遍历. 背下模板, 很简单
						int q[N];//用于bfs
						void bfs(int root){
							q[0] = root;
							
							int h, t;//queue的队首和队尾
							h = t = 0;//或者直接://int h = 0, t = 0; 
							
							while(h <= t) //说明还有元素
							{
								int top = q[h ++]; //如果有元素, 取出, h指向下一个
								if(l.count(top)) q[++t] = l[top]; //有左孩子, t移到空位, 放入孩子
								if(r.count(top)) q[++t] = r[top];
							}
							//走到这里,q里面留下来了所有的顺序,注意这里不是真的pop掉了,所以q里面是有数据的.

							cout << q[0];
							for(int i = 1; i < h; i++) cout << ' ' << q[i]; 这里是 < h, 而不是写成 < n. 因为q里面的元素并没有pop掉. 
							cout << endl;
						}
				1.
					0. 因为只有左右子树, 所以只存储左右子树就好了
					1. 这道题经常考
					2. 知识点: 如果知道前序+中序, 或者后续+中序, 是可以求出二叉树的. 但是知道前序 + 后序就不行.\
					3. 求的过程
						1. 后序的最后一个节点是root(前序是第一个节点是root)
						2. 在中序中找到这个root, 左侧就是root的左子树(求出左侧长度n),右侧柚子树(求出右侧长度m)
						3. 后续中,因为是左子树+右子树+root,所以可以知道左子树是哪一段(截取长度为n),右子树是哪一段
						4. 后序中,左子树的最后一个节点是root
						5. 重复到2.
						老师用了递归
					------------------
					4. 重新构建二叉树方法:
						1. 在在中序中找到这个root,就是已知值, 找index, 所以我们用哈希表存, 快, 知道某个值的下标是多少
						2. 重建二叉树,是一个递归的过程. 返回当前子树的根节点.
						3. 老师在构建二叉树的时候,没有使用链接表,而是使用了两个哈希表.其实非常好
							1. 二叉树的重要内容就是, 某个节点(值)的左右儿子的ind是多少
							2. 一个哈希表存某个节点(用值表示)的左子树,一个存右边的
					------------------
					5. 
						1. build()两种思路: 
							已知左子树在中序的ind是[il, k-1]
							求左子树在后序的ind是[pl, ?]
							1. 长度
								因为在中序中, 左子树的长度是(k-il), 因为是[il, k), k是指向左子树最后一个节点的下一位
								所以在后续中, 右子树的最后一个节点的下一位是 pl + (k-il)
								但是我们要求的是右子树的最后一个节点的位置, 所以是 pl + (k-il) - 1;
							2. 差相等
								老师说 ? - pl == k - 1 - il
								? == pl + (k - 1 - il)
						2. 解释l[root] = build(il, k - 1, pl, pl + (k - 1 - il));
							build(il, k - 1, pl, pl + (k - 1 - il))返回root的左子树的根
							root的左子树的根,也就是root的左儿子
					------------------
					3. bfs()中,tt是指向了元素的,而不是元素的下一个

					-----------------
					4. 思考:
					中序: 需要建立值和位置之间的map
					后序: 不需要建立上面的map, 因为每次只要取最后一位.

					5. 思考:
					中序: 左子树+根+右子树
					后序: 左子树+右子树+根

					6. 思考:
					build的参数传入的是相同的一个树,但是build()里面又有两个build()分别服务于左子树和右子树

					7. 易错
					右子树的后序的右侧节点是Pr-1,不是pr,因为pr是根节点
					build(k+1, ir, (pr-1) + (k+1-ir), pr-1);//bug!容易错的地方,pr是root(回忆int root_val = postorder[pr]]),所以是pr-1!

					8. 思考
					重构二叉树,除了记录每个节点left,right,还需要知道root,最后通过root找左右,通过左右继续找左右.

					9. 其他错误:
					似乎不能用left,会和系统重名

					10. 语法
					1. 定义的时候
						应该是 int h = 0, t = 0;
						而不是int h = t = 0;
					2. 如果已经定义了
						int h,t;
						h = t = 0;是没问题的
			2. 注释
				1. y
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>

					using namespace std;

					const int N = 40;

					int n;
					int postorder[N], inorder[N];
					unordered_map<int, int> l, r, pos;
					int q[N];

					int build(int il, int ir, int pl, int pr)
					{
					    int root = postorder[pr];
					    int k = pos[root];
					    if (il < k) l[root] = build(il, k - 1, pl, pl + (k - 1 - il));
					    if (k < ir) r[root] = build(k + 1, ir, pl + (k - 1 - il) + 1, pr - 1);
					    return root;
					}

					void bfs(int root)
					{
					    int hh = 0, tt = 0;
					    q[0] = root;

					    while (hh <= tt)
					    {
					        int t = q[hh ++ ];
					        if (l.count(t)) q[ ++ tt] = l[t];
					        if (r.count(t)) q[ ++ tt] = r[t];
					    }

					    cout << q[0];
					    for (int i = 1; i < n; i ++ ) cout << ' ' << q[i];
					    cout << endl;
					}

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ ) cin >> postorder[i];
					    for (int i = 0; i < n; i ++ )
					    {
					        cin >> inorder[i];
					        pos[inorder[i]] = i;
					    }

					    int root = build(0, n - 1, 0, n - 1);

					    bfs(root);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/279654/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>
					#include <unordered_map> //用户哈希表存LR

					using namespace std;

					const int N = 40;
					int postorder[N];
					int inorder[N];
					unordered_map<int, int> pos; //给一个节点的值(节点的值都不相同),返回这个节点在inorder中的位置.
					unordered_map<int, int> l, r; //因为我们要重构二叉树.但这里不用单链表,老师说是二叉,所以设置每个节点的左右孩子就好了.
														//存的是左右孩子的值,而不是ind
					int q[N];//用于bfs
														
					int build(int il, int ir, int pl, int pr){
						//找root的值
						int root_val = postorder[pr];//根节点的值
						int k = pos[root_val];//知道根节点在中序中的位置

						//判断有无左右子树, 通过看k在中序中的位置
						if(il < k) //有left, 如果il == k说明没有left树
						{
							l[root_val] = build(il, k-1, pl, pl + (k-1-il));//见解释
						}
						if(k < ir)
						{
							r[root_val] = build(k+1, ir, (pr-1) + (k+1-ir), pr-1);//bug!容易错的地方,pr是root(回忆int root_val = postorder[pr]]),所以是pr-1!
						}
						return root_val; //返回根的值
					}

					void bfs(int root){
						q[0] = root;
						
						int h, t;//queue的队首和队尾
						h = t = 0;//或者直接://int h = 0, t = 0; 
						
						while(h <= t) //说明还有元素
						{
							int top = q[h ++]; //如果有元素, 取出, h指向下一个
							if(l.count(top)) q[++t] = l[top]; //有左孩子, t移到空位, 放入孩子
							if(r.count(top)) q[++t] = r[top];
						}
						//走到这里,q里面留下来了所有的顺序,注意这里不是真的pop掉了,所以q里面是有数据的.

						cout << q[0];
						for(int i = 1; i < h; i++) cout << ' ' << q[i]; //之所以写在这里,因为h是局部变量
						cout << endl;
					}

					int main(){

						int n;
						cin >> n;
						for(int i = 0; i < n; i++) cin >> postorder[i];
						for(int i = 0; i < n; i++)
						{
							cin >> inorder[i];
							pos[inorder[i]] = i; //给一个节点的值(节点的值都不相同),返回这个节点在inorder中的位置.
						}

						int root_val = build(0, n-1, 0, n-1);

						bfs(root_val);

						return 0;
					}
			3. 5次
				r1.
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					const int N = 40;
					int postorder[N], inorder[N];
					unordered_map<int, int> l, r, pos;
					int root;
					int q[N];

					int build(int il, int ir, int pl, int pr){
						int root = postorder[pr];
						int k = pos[root];

						if(il < k){
							l[root] = build(il, k-1, pl, pl + (k - 1 - il));
						}
						if(k < ir){
							r[root] = build(k+1, ir, pl + (k - 1 - il) + 1, pr-1);
						}

						return root;
					}

					void bfs(){
						q[0] = root;
						int h, t;
						h = t = 0;

						while(h <= t){
							int top = q[h++];
							if(l.count(top)) q[++t] = l[top];
							if(r.count(top)) q[++t] = r[top];
						}

						cout << q[0];
						for(int i = 1; i < h; i++) cout << " " << q[i];
						cout << endl;
					}

					int main(){
						int n;
						cin >> n;
						for(int i = 0; i < n; i++) cin >> postorder[i];
						for(int i = 0; i < n; i++)
						{
							int a;
							cin >> a;
							inorder[i] = a;;
							pos[a] = i;
						}

						root = build(0, n-1, 0, n-1);

						bfs();

						return 0;
					}
				r2.
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					const int N = 40;
					int post[N], in[N];
					unordered_map<int, int> l, r, pos;
					int root;
					int q[N];

					int build(int il, int ir, int pl, int pr){
					    int root = post[pr];
					    int k = pos[root];
					    
					    if(il < k){
					        l[root] = build(il, k-1, pl, pl + (k-1-il));
					    }
					    if(k < ir){
					        r[root] = build(k+1, ir, pl + (k-il), pr - 1);
					    }
					    
					    return root;
					}

					void bfs()
					{
					    q[0] = root;
					    int h, t;
					    h = t = 0;
					    
					    while(h <= t){
					        int top = q[h++];
					        if(l.count(top)) q[++t] = l[top];
					        if(r.count(top)) q[++t] = r[top];
					    }
					    
					    cout << q[0];
					    for(int i = 1; i < h; i++) cout << " " << q[i];
					    cout << endl;
					    
					}
					int main(){
					    int n;
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> post[i];
					    for(int i = 0; i < n; i++){
					        int a;
					        cin >> a;
					        in[i] = a;
					        pos[a] = i;
					    }
					    
					    root = build(0, n-1, 0, n-1);
					    
					    bfs();
					    
					    return 0;
					    
					}
				r3.
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					const int N = 40;
					int post[N], in[N];
					unordered_map<int, int> l, r, pos;
					int root;
					int q[N];

					int build(int il, int ir, int pl, int pr){
					    int root = post[pr];
					    int k = pos[root];
					    if(il < k) l[root] = build(il, k-1, pl, pl+(k-1-il));
					    if(k < ir) r[root] = build(k+1, ir, pl+(k-il), pr-1);
					    return root;
					}

					void bfs()
					{
					    q[0] = root;
					    int h, t;
					    h = t = 0;
					    
					    while(h <= t){
					        int top = q[h++];
					        if(l.count(top)) q[++t] = l[top];
					        if(r.count(top)) q[++t] = r[top];
					    }
					    
					    cout << q[0];
					    for(int i = 1; i < h; i++) cout << " " << q[i];
					    cout << endl;
					}

					int main(){
					    int n;
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> post[i];
					    for(int i = 0; i < n; i++){
					        cin >> in[i];
					        pos[in[i]] = i;
					    }
					    
					    root = build(0, n-1, 0, n-1);
					    
					    bfs();
					    
					    return 0;
					}
				r4.
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					const int N = 40;
					int post[N], in[N];
					unordered_map<int, int> l, r, pos;
					int root;
					int q[N];

					int build(int il, int ir, int pl, int pr){
					    int root = post[pr];
					    int k = pos[root];
					    if(il < k) l[root] = build(il, k-1, pl, pl+(k-1-il));
					    if(k < ir) r[root] = build(k+1, ir, pl+(k-il), pr-1);
					    return root;
					}

					void bfs()
					{
					    q[0] = root;
					    int h, t;
					    h = t = 0;
					    
					    while(h <= t){
					        int top = q[h++];
					        if(l.count(top)) q[++t] = l[top];
					        if(r.count(top)) q[++t] = r[top];
					    }
					    
					    cout << q[0];
					    for(int i =1 ; i < h; i++) cout << " " << q[i];
					    cout << endl;
					}
					int main(){
					    int n;
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> post[i];
					    for(int i = 0; i < n; i++){
					        cin >> in[i];
					        pos[in[i]] = i;
					    }
					    
					    root = build(0, n-1, 0, n-1);
					    
					    bfs();
					    
					    return 0;
					}
				r5.
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					const int N = 40;
					int post[N], in[N];
					unordered_map<int, int> l, r, pos;
					int root;
					int q[N];

					int build(int il, int ir, int pl, int pr){
					    int root = post[pr];
					    int k = pos[root];
					    if(il < k) l[root] = build(il, k-1, pl, pl+(k-1-il));
					    if(k < ir) r[root] = build(k+1, ir, pl+(k-il), pr-1);
					    return root;
					}

					void bfs(){
					    q[0] = root;
					    int h, t;
					    h = t = 0;
					    while(h <= t){
					        int top = q[h++];
					        if(l.count(top)) q[++t] = l[top];
					        if(r.count(top)) q[++t] = r[top];
					    }
					    cout << q[0];
					    for(int i = 1; i < h; i++) cout << " " << q[i];
					    cout << endl;
					}

					int main(){
					    int n;
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> post[i];
					    for(int i = 0; i <n; i++){
					        cin >> in[i];
					        pos[in[i]] = i;
					    }
					    
					    root = build(0, n-1, 0, n-1);
					    
					    bfs();
					    
					    return 0;
					}

		47. 1498. 最深的根	1021
			0. bug
				1. 老师之前是暴力枚举, 所以每一次我们add(), 两条边都要add(): add(a,b),add(b,a)
				2. dfs() 里面需要判断是不是从father来的, 因为之前是双向边
				3. 注意往下递归的时候, father是dfs(int a, int father)中的a, 而不是 i ( i = h[a])
			1. 笔记

				0. 考察了:
					1. 连通块个数: 并查集-int k, p[N];
					2. 如何找最深高度: dfs-int h[N], e[N], ne[N], ind;
						之前45.是, 我告诉你, 你现在的depth, 所以传入了depth数据给dfs(), 即dfs(int a, int depth)
							也就是把根当成了depth = 0,然后到叶子节点后, depth是>0, 然后修改cnt[depth]
						现在是, 我不知道你的depth, 你最好自己生成, 然后告诉我, 所以是在dfs()里面有个 int depth = 0; depth = max(depth, dfs(e[i], a) + 1);
							也就是把叶节点当成了depth = 0, 看最后返回到root的depth有多少
							dfs(int a, int source)的语意是: 包括a点在内的高度. 不过这里的高度是从0开始的, 也就是说即便是一个节点,我们认为他的高度是0,而不是1. 所以max_depth是从-1开始的.
								所以你可以:
									int maxdepth = 0; 设置成0
									int dfs(int a, int s){
									    int depth = 1; 设置成1
									    for(int i = h[a]; ~i; i = ne[i]){
									        if(e[i] == s) continue;
									        depth = max(depth, dfs(e[i], a) + 1);
									    }
									    return depth;
									}

				思路:
					1. 老师这里是暴力枚举了所有点是否是正确答案,因为一共有10^4个点,但是有2s,足够用了
					2. 考察了:
						1. 连通分量
							逻辑:如果a,b两个点不属于同一个,并且这次input中a,b是链接的,就会少一个连通分量
							使用:并查集find()
						2. 如果是树,若有N个点,一定是N-1条边,(不多不少),多了就有环,少了就不连通(存在多个连通分量)
						3. 但是如果N个点,N-1条边,不一定是树. 例如:6个点,其中4个点是环,另2个点链接.虽然也是5条边,但是一个是环,一个是连通分量.

					3. 老师说:
						1. 可以用bfs来看某个节点的每个叶子节点到该节点的距离
						2. 可以用dfs来遍历所有的叶子,然后返回值+1(因为高度+1)
					4. 因为是无向图,所以在遍历的过程中,我们可能会遍历到过来的点.
						例如,假设我们是认为a点是根节点,往下遍历
						其中b点是a的子节点,我们会遍历b,但是遍历b的临点的时候也会遍历到a(因为无向图存储)
						所以我们要判断b的子节点是否等于b的父亲a,如果等于,就continue
					5. dfs()在本题中的语意是:参数是int u,也就是u的叶子节点中到u节点的最大高度.
					6. dfs()中,叶子节点的高度是0, 如果是叶子结点,会返回depth == 0
					7. 注意: h[a]中的a是节点的编号:从1-N,所以很多for(int i = 1; ...) 而不是for(int i = 0; ...)
			2. 注释
				1. y
					#include <cstring>
					#include <iostream>
					#include <algorithm>
					#include <vector>

					using namespace std;

					const int N = 10010, M = N * 2;

					int n;
					int h[N], e[M], ne[M], idx;
					int p[N];

					int find(int x)
					{
					    if (p[x] != x) p[x] = find(p[x]);
					    return p[x];
					}

					void add(int a, int b)
					{
					    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
					}

					int dfs(int u, int father) 迭代
					{
					    int depth = 0;
					    for (int i = h[u]; ~i; i = ne[i])
					    {
					        int j = e[i];
					        if (j == father) continue;
					        depth = max(depth, dfs(j, u) + 1);
					    }
					    return depth;
					}

					int main()
					{
					    cin >> n;

					    memset(h, -1, sizeof h);
					    for (int i = 1; i <= n; i ++ ) p[i] = i;

					    int k = n;
					    for (int i = 0; i < n - 1; i ++ )
					    {
					        int a, b;
					        cin >> a >> b;
					        if (find(a) != find(b))
					        {
					            k -- ;
					            p[find(a)] = find(b);
					        }
					        add(a, b), add(b, a);
					    }

					    if (k > 1) printf("Error: %d components", k);
					    else
					    {
					        vector<int> nodes;
					        int max_depth = -1;

					        for (int i = 1; i <= n; i ++ )
					        {
					            int depth = dfs(i, -1);
					            if (depth > max_depth)
					            {
					                max_depth = depth;
					                nodes.clear();
					                nodes.push_back(i);
					            }
					            else if (depth == max_depth)
					                nodes.push_back(i);
					        }

					        for (auto v : nodes) cout << v << endl;
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/279675/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>
					#include <vector> //因为要用到vector.clear(), 所以不用普通数组
					#include <cstring> //memset()

					using namespace std;

					const int N = 10010, M = 2 * N; //因为边数是点数的2倍
					int h[N], e[M], ne[M], ind; //因为h[N]是存储每个节点的token, e[M]是存储很多条边
					int p[N]; //并查集

					void add(int a, int b){
					    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
					}

					int find(int a){
					    if(p[a] != a) p[a] = find(p[a]); //如果我的爸爸不是我的爷爷,就让我的爸爸成为我的爷爷,一直到我的爸爸是我的祖宗
					    return p[a]; //这里返回的条件是 p[a] == a, 也就是a其实就是祖先.
					}

					int dfs(int cur, int source){
					    int depth = 0;
					    for(int i = h[cur]; ~i; i = ne[i]){
					        int son = e[i];
					        if(son == source) continue;
					        depth = max(depth, dfs(son, cur) + 1);
					    }
					    return depth;
					}
					int main(){
					    int n;
					    cin >> n;

					    //初始化单链表
					    memset(h, -1, sizeof h);
					    //初始化并查集
					    for(int i = 1; i <= n; i++) p[i] = i;

					    //读入n-1条边
					    int k = n; //用于计算连通分量
					    int a, b;
					    for(int i = 0; i < n-1; i ++) {
					        cin >> a >> b;
					        add(a,b), add(b,a);
					        if(find(a) != find(b)) //假如他们之前不是一个集合,但是现在input他们之间有边了
					        {
					            k--;
					            p[find(a)] = find(b);
					        }
					    }   

					    vector<int> res; //存output需要的节点
					    int max_depth = -1;
					    if(k >= 2){
					        printf("Error: %d components", k);
					    }
					    else{
					        for(int id = 1; id <= n; id ++){
					            int depth = dfs(id, -1);
					            if(max_depth < depth)
					            {
					                max_depth = depth;
					                res.clear();
					                res.push_back(id);
					            }
					            else if(max_depth == depth){
					                res.push_back(id);
					            }
					        }
					    }

					    for(auto i : res) cout << i << endl;
					    return 0;
					}

					作者：jackrrr
					链接：https://www.acwing.com/activity/content/code/content/488211/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
			3. 5次
				r1.
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 10010, M = N * 2;
					int h[N], e[M], ne[M], ind;
					int max_depth;
					int p[N];

					void add(int a, int b){
						e[ind] = b, ne[ind] = h[a], h[a] = ind++;
					}

					// 之前是, 我告诉你, 你现在的depth, 所以传入了depth数据给dfs(), 即dfs(int a, int depth)
					// 现在是, 我不知道你的depth, 你最好自己生成, 然后告诉我, 所以是在dfs()里面有个 int depth = 0;


					int find(int a){
						if(a != p[a]) p[a] = find(p[a]);
						return p[a];
					}

					int dfs(int a, int father){
						int depth = 0;
						if(h[a] == -1) return depth;

						for(int i = h[a]; ~i; i = ne[i]){
						    if(e[i] == father) continue;
							depth = max(depth, dfs(e[i], a) + 1);
						}
						return depth;
					}


					int main(){
						memset(h, -1, sizeof h);
						max_depth = -1;

						int n;
						cin >> n;

						for(int i = 1; i <= n; i++) p[i] = i;
						int k = n;

						int a, b;
						for(int i = 0; i < n-1; i++){
							scanf("%d%d", &a, &b);
							if(find(a) != find(b)){
							    k--;
							    p[find(b)] = find(a);
							}
							add(a, b);
							add(b, a);
						}
						


						if(k != 1){
							printf("Error: %d components\n", k);
							return 0;
						}

						int depth;
						vector<int> res;
						for(int i = 1; i <= n; i++){
						    
							depth = dfs(i, -1);
								
							if(depth > max_depth){
								max_depth = depth;
								res.clear();
								res.push_back(i);
							}
							else if(depth == max_depth){
								res.push_back(i);
							}
						}

						for(int i = 0; i < res.size(); i++) cout << res[i] << endl;

						return 0;



					}
				r2.
					#include <iostream>
					#include <vector>
					#include <cstring>

					using namespace std;

					const int N = 10010;
					int h[N], e[N], ne[N], ind;
					vector<int> res;
					int p[N];

					int find(int a){
					    if(a != p[a]) p[a] = find(p[a]);
					    return p[a];
					}

					void add(int a, int b){
					    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
					}

					int dfs(int a, int source){
					    int depth = 0;
					    if(h[a] == -1) return depth;
					    for(int i = h[a]; ~i ; i = ne[i]){
					        if(e[i] == source) continue;
					        depth = max(depth, dfs(e[i], a) + 1);
					    }
					    return depth;
					}


					int main(){
					    int n;
					    cin >> n;
					    
					    memset(h, -1, sizeof h);
					    for(int i = 1; i <= n; i ++) p[i] = i;
					    
					    int k = n;
					    for(int i = 1; i <= n; i++){
					        int a, b;
					        cin >> a >> b;
					        if(find(a) != find(b)){
					            k--;
					            p[find(a)] = find(b);
					        }
					        add(a, b), add(b, a);
					    }
					    
					    if(k != 1){
					        printf("Error: %d components\n", k);
					        return 0;
					    }
					    int depth;
					    int max_depth = -1;
					    for(int i = 1; i <= n; i++){
					        depth = dfs(i, -1);
					        if(depth > max_depth){
					            max_depth = depth;
					            res.clear();
					            res.push_back(i);
					        }else if(depth == max_depth){
					            res.push_back(i);
					        }
					    }
					    
					    for(int i : res) cout << i << endl;
					    return 0;
					    
					}
				r3.
					#include <iostream>
					#include <vector>
					#include <cstring>

					using namespace std;

					const int N = 10010;
					int h[N], e[N], ne[N], ind;
					int k, p[N];
					vector<int> res;

					int n;

					int find(int a){
					    if(a != p[a]) p[a] = find(p[a]);
					    return p[a];
					}

					void add(int a, int b){
					    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
					}

					int dfs(int a, int source){
					    int depth = 0;
					    if(h[a] == -1) return depth;
					    for(int i = h[a]; ~i; i = ne[i]){
					        if(e[i] == source) continue;
					        depth = max(depth, dfs(e[i], a) + 1);
					    }
					    return depth;
					}

					int main(){
					    cin >> n;
					    k = n;
					    for(int i = 1; i <= n; i++) p[i] = i;
					    memset(h, -1, sizeof h);
					    
					    for(int i = 0; i < n; i ++){
					        int a, b;
					        cin >> a >> b;
					        if(find(a) != find(b)){
					            k--;
					            p[find(a)] = find(b);
					        }
					        
					        add(a, b), add(b, a);
					    }
					    
					    if(k != 1){
					        printf("Error: %d components\n", k);
					        return 0;
					    }
					    
					    int max_depth = -1;
					    for(int i = 1; i <= n; i++){
					        int depth = dfs(i, -1);
					        if(depth > max_depth){
					            max_depth = depth;
					            res.clear();
					            res.push_back(i);
					        }
					        else if(depth == max_depth){
					            res.push_back(i);
					        }
					    }
					    
					    for(int i : res) cout << i << endl;
					    return 0;
					}
				r4.
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 10010;
					int h[N], e[N], ne[N], ind;
					int k, p[N];
					vector<int> res;

					int find(int a){
					    if(a != p[a]) p[a] = find(p[a]);
					    return p[a];
					}

					void add(int a, int b){
					    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
					}

					int dfs(int a, int source){
					    int depth = 0;
					    for(int i = h[a]; ~i; i = ne[i]){
					        if(e[i] == source) continue;
					        depth = max(depth, dfs(e[i], a) + 1);
					    }
					    return depth;
					}

					int main(){
					    int n;
					    cin >> n;
					    
					    k = n;
					    for(int i = 1; i <= n; i++) p[i] = i;
					    
					    memset(h, -1, sizeof h);
					    
					    for(int i = 1; i <= n-1; i++){
					        int a, b;
					        cin >> a >> b;
					        if(find(a) != find(b)){
					            k--;
					            p[find(a)] = find(b);
					        }
					        add(a, b), add(b, a);
					    }
					    
					    if(k != 1){
					        printf("Error: %d components\n", k);
					        return 0;
					    }
					    
					    int max_depth = -1;
					    for(int i = 1; i <= n; i++){
					        int depth = dfs(i, -1);
					        if(depth > max_depth){
					            max_depth = depth;
					            res.clear();
					            res.push_back(i);
					        }
					        else if(depth == max_depth) res.push_back(i);
					    }
					    
					    for(int i : res) cout << i << endl;
					    return 0;
					}
				r5.
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 10010;
					int h[N], e[N], ne[N], ind;
					int k, p[N];
					vector<int> res;

					int find(int a){
					    if(a != p[a]) p[a] = find(p[a]);
					    return p[a];
					}

					void add(int a, int b){
					    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
					}

					int dfs(int a, int s){
					    int depth = 0;
					    if(h[a] == -1) return depth;
					    for(int i = h[a]; ~i; i = ne[i]){
					        if(e[i] == s) continue;
					        depth = max(depth, dfs(e[i], a) + 1);
					    }
					    return depth;
					}


					int main(){
					    
					    int n;
					    cin >> n;
					    
					    for(int i = 1; i <= n; i++) p[i] = i;
					    k = n;
					    memset(h, -1, sizeof h);
					    
					    for(int i = 0; i < n-1; i ++){
					        int a, b;
					        cin >> a >> b;
					        add(a, b), add(b, a);
					        
					        if(find(a) != find(b)){
					            k--;
					            p[find(a)] = find(b);
					        }
					    }
					    
					    if(k != 1){
					        printf("Error: %d components\n", k);
					        return 0;
					    }
					    
					    int max_depth = -1;
					    for(int i = 1; i <= n; i++){
					        int depth = dfs(i, -1);
					        if(max_depth < depth){
					            max_depth = depth;
					            res.clear();
					            res.push_back(i);
					        }else if(max_depth == depth) res.push_back(i);
					    }
					    
					    for(int i : res) cout << i << endl;
					    return 0;
					    
					}
				r6.
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 10010;
					int h[N], e[N], ne[N], ind;
					int k, p[N];
					vector<int> res;

					int find(int a){
					    if(a != p[a]) p[a] = find(p[a]);
					    return p[a];
					}

					void add(int a, int b){
					    e[ind] = b, ne[ind] = h[a], h[a] = ind++;
					}

					int dfs(int a, int s){
					    int depth = 0;
					    for(int i = h[a]; ~i; i = ne[i]){
					        if(e[i] == s) continue;
					        depth = max(depth, dfs(e[i], a) + 1);
					    }
					    return depth;
					}


					int main(){
					    
					    int n;
					    cin >> n;
					    
					    memset(h, -1, sizeof h);
					    for(int i = 1; i <= n; i++) p[i] = i;
					    k = n;
					    
					    for(int i = 0; i < n-1; i++){
					        int a, b;
					        cin >> a >> b;
					        if(find(a) != find(b))
					        {
					            k--;
					            p[find(a)] = find(b);
					        }
					        add(a, b), add(b, a);
					    }
					    
					    if(k != 1){
					        printf("Error: %d components\n", k);
					        return 0;
					    }
					    
					    int maxdepth = -1;
					    for(int i = 1; i <= n; i++){
					        int depth = dfs(i, -1);
					        if(depth > maxdepth){
					            maxdepth = depth;
					            res.clear();
					            res.push_back(i);
					        }else if(depth == maxdepth) res.push_back(i);
					    }
					    
					    for(int i : res) cout << i << endl;
					    return 0;
					    
					}
		
	11. 2020年10月15日18:22:59
		
		48. 1527. 判断二叉搜索树	1043 很棒的题! *****
			0. bug
				1. 大bug
					最后画出图来的时候, 才知道那里错了
					题目的样例: ()是错误根源
						8 6 5 7 (10 8 11)
						5 6 7 8 (8 10 11) 
					我在找第几个的时候错了. 例如, 我现在要找的是右子树
						10 8 11
						8 10 11 我要找的是8在第二行是第几个, 我的错代码告诉我输第3个(从0开始), 但实际上是第4个
						因为我应该找的范围应该是[4,6], 而不是整个数组[0,6]
					错误的根源:
						int cmin(int a){
							int l = 0, r = n-1;
							while(l < r)
							{
								int mid = l + (r-l)/2;
								if(a <= in[mid]) r = mid;
								else l = mid + 1;
							}
							if(in[r] != a) return -1;
							cout << "a: " << a << " min: " << r << endl;
							return r; //肯定能够找到, 所以不是-1
						}

						int cmax(int a){
							int l = 0, r = n-1;
							while(l < r){
								int mid = l + (r-l)/2 + 1;
								if(in[mid] >= a) l = mid;
								else r = mid - 1;
							}
							cout << "a: " << a << " max: " << r << endl;
							if(in[r] != a) return -1;
							return r;
						}
					应该是:
						int cmin(int a, int il, int ir){
							int l = il, r = ir-1;
							while(l < r)
							{
								int mid = l + (r-l)/2;
								if(a <= in[mid]) r = mid;
								else l = mid + 1;
							}
							if(in[r] != a) return -1;
							cout << "a: " << a << " min: " << r << endl;
							return r; //肯定能够找到, 所以不是-1
						}

						int cmax(int a, int il, int ir){
							int l = il, r = ir-1;
							while(l < r){
								int mid = l + (r-l)/2 + 1;
								if(in[mid] >= a) l = mid;
								else r = mid - 1;
							}
							cout << "a: " << a << " max: " << r << endl;
							if(in[r] != a) return -1;
							return r;
						}
				2. 注意, 可能存在cmin和cmax最后的r, 并不能满足 in[r] == target
					我之前错误的认为 ,肯定能够在in[]找到target, 所以我没有设置return -1
				3. 大bug
					我都想mr了,耽误我好几个小时 debug!
					bug是: 可能用type == 0的时候能填充一部分post order
					但是记住, 到了type == 1之后, 要把之前的清空!!!! 所以要加上 cnt == 0!!!!
				4. 小bug
					因为是pre, 所以范围记得是 pl + 1开始. 不要和post混为一谈
			1. 笔记
				0. 不要把什么翻转过后的二叉树想象很复杂,其实就是两种树:
					1. 题目定义的: 二叉树, 左子 < 自己 <= 右子
						例如:
							题目给的例1: 8 6 5 7 10 8 11
							中序后: 5 6 7 8 8 10 11
					2. 翻转后的无非是: 左子 >= 自己 > 右子.
						例如: 
							题目给的例2: 8 10 11 8 6 7 5
							中序后: 11 10 8 8 7 6 5 
					3. 求树的方法
						都是一模一样.
				0. 
					1. build()
						只要一边的子树不行,那res就是false
						build()不能放在前面,否则就是无限循环了,应该是 
							1. 终止条件 (tree最底部)
							2. 自己的结果 (自己的事情)
							3. 自己子女返回的结果 (自己的孩子)
							4. 自己返回给父亲 (给父亲)

					2. 知道了
						1. 因为要后序所以是build(左), build(右), postorder[cnt++] = xx
						2. 如果是中序, 应该就是build(左), postorder[cnt++] = xx, build(右)
						3. 前序就是post, build(), build();
				1. 
					找a在in[]中在第k个位置
					1. 没有翻转:
						需要找到最左侧的a, 因为本身是从小到大排, 所以就是正常的cmin
					2. 翻找后:
						需要找到最右侧的a, 但是因为翻转后是从大到小排, 所以需要灵活应对: true的条件是 in[mid] >= target, true 之后还是向右找
				2.**** 如何在build()里面后序遍历填充:
						三句:
							if(!build(il, k-1, pl+1, pl+1 + (k-1-il), type)) res = false;
							if(!build(k+1, ir, pl+1+(k-il), pr, type)) res = false;
							post[cnt++] = root;
						解释:
							第一次执行: post[cnt++] = root; 的时候, 就已经是遍历到tree的最左下角了
							因为一直build(),build()一直都是早左侧的元素
							第二次执行: post[cnt++] = root; 的时候, 就已经是遍历到tree的最左下角右侧的子树了
							因为执行检测右子树的 if(!build(k+1, ir, pl+1+(k-il), pr, type)) res = false;
				3. 如何判断是否存在:
					1. 如果是 if(il > ir) return true;
						就是已经是修得正果了, 因为每次都找到了对的k, 才能走到这一句
					2. if( k == -1) return false; 不能找到对的k, 就要false
					3. 以上是我自己的, 我在看我的子树怎么样, 只要有一颗false, 我也就是false了
						bool res = true;
						if(!build(il, k-1, pl+1, pl+1 + (k-1-il), type)) res = false;
						if(!build(k+1, ir, pl+1+(k-il), pr, type)) res = false;
					4. 最后把我的结果给我的父亲.

				4. 对比1497的build: 因为保证唯一解, 所以可以正常找到左右子树
					int build(int il, int ir, int pl, int pr){
					    int root = post[pr];
					    int k = pos[root];
					    if(il < k) l[root] = build(il, k-1, pl, pl+(k-1-il));
					    if(k < ir) r[root] = build(k+1, ir, pl+(k-il), pr-1);
					    return root;
					}

					我们这里的build: 需要判断是否存在, 我们假设存在, 就直接在 build()里面后序遍历填充.
						bool build(int il, int ir, int pl, int pr, int type){
							if(il > ir) return true;

							int root = pre[pl];
							int k;
							if(!type) k = cmin(root, il, ir + 1);
							else k = cmax(root, il , ir +);
							if( k == -1 || k < il || k > ir) return false;

							bool res = true;
							if(!build(il, k-1, pl+1, pl+1 + (k-1-il), type)) res = false;
							if(!build(k+1, ir, pl+1+(k-il), pr, type)) res = false;
							post[cnt++] = root;

							return res;
						}
			2. 注释
				1. y
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;

					int n;
					int preorder[N], inorder[N];
					int postorder[N], cnt;

					bool build(int il, int ir, int pl, int pr, int type)
					{
					    if (il > ir) return true;

					    int root = preorder[pl];
					    int k;
					    if (type == 0)
					    {
					        for (k = il; k <= ir; k ++ )
					            if (inorder[k] == root)
					                break;
					        if (k > ir) return false;
					    }
					    else
					    {
					        for (k = ir; k >= il; k -- )
					            if (inorder[k] == root)
					                break;
					        if (k < il) return false;
					    }

					    bool res = true;
					    if (!build(il, k - 1, pl + 1, pl + 1 + (k - 1 - il), type)) res = false;
					    if (!build(k + 1, ir, pl + 1 + (k - 1 - il) + 1, pr, type)) res = false;

					    postorder[cnt ++ ] = root;
					    return res;
					}

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ )
					    {
					        cin >> preorder[i];
					        inorder[i] = preorder[i];
					    }

					    sort(inorder, inorder + n);

					    if (build(0, n - 1, 0, n - 1, 0))
					    {
					        puts("YES");
					        cout << postorder[0];
					        for (int i = 1; i < n; i ++ ) cout << ' ' << postorder[i];
					        cout << endl;
					    }
					    else
					    {
					        reverse(inorder, inorder + n);
					        cnt = 0;
					        if (build(0, n - 1, 0, n - 1, 1))
					        {
					            puts("YES");
					            cout << postorder[0];
					            for (int i = 1; i < n; i ++ ) cout << ' ' << postorder[i];
					            cout << endl;
					        }
					        else puts("NO");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/279699/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/279699/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r0. 错误代码, 包含debug. 最后画出图来的时候, 才知道那里错了
					题目的样例: ()是错误根源
						8 6 5 7 (10 8 11)
						5 6 7 8 (8 10 11) 
					我在找第几个的时候错了. 例如, 我现在要找的是右子树
						10 8 11
						8 10 11 我要找的是8在第二行是第几个, 我的错代码告诉我输第3个(从0开始), 但实际上是第4个
						因为我应该找的范围应该是[4,6], 而不是整个数组[0,6]
					错误的根源:
						int cmin(int a){
							int l = 0, r = n-1;
							while(l < r)
							{
								int mid = l + (r-l)/2;
								if(a <= in[mid]) r = mid;
								else l = mid + 1;
							}
							if(in[r] != a) return -1;
							cout << "a: " << a << " min: " << r << endl;
							return r; //肯定能够找到, 所以不是-1
						}

						int cmax(int a){
							int l = 0, r = n-1;
							while(l < r){
								int mid = l + (r-l)/2 + 1;
								if(in[mid] >= a) l = mid;
								else r = mid - 1;
							}
							cout << "a: " << a << " max: " << r << endl;
							if(in[r] != a) return -1;
							return r;
						}
					应该是:
						int cmin(int a, int il, int ir){
							int l = il, r = ir-1;
							while(l < r)
							{
								int mid = l + (r-l)/2;
								if(a <= in[mid]) r = mid;
								else l = mid + 1;
							}
							if(in[r] != a) return -1;
							cout << "a: " << a << " min: " << r << endl;
							return r; //肯定能够找到, 所以不是-1
						}

						int cmax(int a, int il, int ir){
							int l = il, r = ir-1;
							while(l < r){
								int mid = l + (r-l)/2 + 1;
								if(in[mid] >= a) l = mid;
								else r = mid - 1;
							}
							cout << "a: " << a << " max: " << r << endl;
							if(in[r] != a) return -1;
							return r;
						}



					1. 
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					int post[N], pre[N], in[N], cnt;
					int n;

					int cmin(int a, int il, int ir){
						int l = il, r = ir-1;
						while(l < r)
						{
							int mid = l + (r-l)/2;
							if(a <= in[mid]) r = mid;
							else l = mid + 1;
						}
						if(in[r] != a) return -1;
						cout << "a: " << a << " min: " << r << endl;
						return r; //肯定能够找到, 所以不是-1
					}

					int cmax(int a, int il, int ir){
						int l = il, r = ir-1;
						while(l < r){
							int mid = l + (r-l)/2 + 1;
							if(in[mid] >= a) l = mid;
							else r = mid - 1;
						}
						cout << "a: " << a << " max: " << r << endl;
						if(in[r] != a) return -1;
						return r;
					}

					bool build(int il, int ir, int pl, int pr, int type){
						if(il > ir) return true;

					    // printf("%d %d %d %d\n", il ,ir, pl, pr);
						int root = pre[pl];
						int k;
						if(!type) k = cmin(root, il, ir + 1);
						else k = cmax(root, il , ir + 1);
						if( k == -1 || k < il || k > ir){
						    printf("Why false, %d %d %d\n", k, il, ir);
						    return false;
						} 
					    // printf("%d %d %d %d %d\n", il ,ir, pl, pr, k);
						bool res = true;
						printf("a %d %d %d %d\n", il, k-1, pl+1, pl+1 + (k-1-il));
						printf("b %d %d %d %d\n", k+1, ir, pl+1+(k-il), pr);
						if(!build(il, k-1, pl+1, pl+1 + (k-1-il), type)) res = false;
						if(!build(k+1, ir, pl+1+(k-il), pr, type)) res = false;
						post[cnt++] = root;
						return res;
					}

					void print(){
						puts("Yes");
						cout << post[0];
						for(int i = 1; i < n; i++) cout << " " << post[i];
						cout << endl;
					}

					int main()
					{
						cin >> n;
						for(int i = 0; i < n; i++){
							cin >> pre[i];
							in[i] = pre[i];
						}

					    sort(in, in + n);
					    for(int i = 0; i < n; i++) cout << in[i] << " ";
					    cout << endl;
						if(build(0, n-1, 0, n-1, 0)){
							print();
							return 0;
						}

					    
						reverse(in, in + n);
						for(int i = 0; i < n; i++) cout << in[i] << " ";
					    cout << endl;
						if(build(0, n-1, 0, n-1, 1)){
							print();
							return 0;
						}

						puts("No");
						return 0;

					}
				r0-2. 错误代码, 包含debug. 又一个bug, 忘记加cnt = 0清空
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					int post[N], pre[N], in[N], cnt;
					int n;

					int cmin(int a, int il, int ir){
						int l = il, r = ir;
						while(l < r)
						{
							int mid = l + (r-l)/2;
							if(a <= in[mid]) r = mid;
							else l = mid + 1;
						}
						if(in[r] != a) return -1;
					// 	cout << "a: " << a << " min: " << r << endl;
						return r; //肯定能够找到, 所以不是-1
					}

					int cmax(int a, int il, int ir){
					    cout << "heyyyyyyyyyyyyyyyy" << endl;
						int l = il, r = ir;
						while(l < r){
							int mid = l + (r-l)/2 + 1;
							if(in[mid] >= a) l = mid;
							else r = mid - 1;
						}
						cout << "a: " << a << " max: " << r << endl;
						if(in[r] != a) return -1;
						return r;
					}

					bool build(int il, int ir, int pl, int pr, int type){
						if(il > ir) return true;

					    printf("%d %d %d %d %d\n", il ,ir, pl, pr, type);
					    
						int root = pre[pl];
						cout << "root: " << root << " pl: " << pl <<endl;
						int k;
						if(!type) k = cmin(root, il, ir);
						else k = cmax(root, il , ir);
						if( k == -1 || k < il || k > ir){
						    printf("Why false, %d %d %d\n", k, il, ir);
						    return false;
						} 
					    // printf("%d %d %d %d %d\n", il ,ir, pl, pr, k);
						bool res = true;
						printf("a %d %d %d %d\n", il, k-1, pl+1, pl+1 + (k-1-il));
						printf("b %d %d %d %d\n", k+1, ir, pl+1+(k-il), pr);
					    // if(!type)
					    // {
					    //     if(!build(il, k-1, pl+1, pl+1 + (k-1-il), type)) res = false;
					    // 	if(!build(k+1, ir, pl+1+(k-il), pr, type)) res = false;}
					    // 	else{
					    	    
					    // 	    if(!build(il, k-1, pl+1+(k-il), pr, type)) res = false;
					    // 	    if(!build(k+1, ir, pl+1, pl+1 + (k-1-il), type)) res = false;
					    // 	}
					    
					    if(!build(il, k-1, pl+1, pl+1 + (k-1-il), type)) res = false;
					    	if(!build(k+1, ir, pl+1+(k-il), pr, type)) res = false;
						cout << " hi " << cnt << " root " << root << endl;
						post[cnt++] = root;
						
						return res;
					}

					void print(){
						puts("YES");
						cout << post[0];
						for(int i = 1; i < n; i++) cout << " " << post[i];
						cout << endl;
					}

					int main()
					{
						cin >> n;
						for(int i = 0; i < n; i++){
							cin >> pre[i];
							in[i] = pre[i];
						}

					    sort(in, in + n);
					//     for(int i = 0; i < n; i++) cout << in[i] << " ";
					//     cout << endl;
						if(build(0, n-1, 0, n-1, 0)){
							print();
							return 0;
						}

					    
						reverse(in, in + n);
						for(int i = 0; i < n; i++) cout << in[i] << " ";
						cnt = 0;
					    cout << endl;
						if(build(0, n-1, 0, n-1, 1)){
							print();
							return 0;
						}

						puts("NO");
						return 0;

					}
				r1. 这次写很顺
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					int pre[N], in[N], post[N];
					int cnt;
					int n;

					void print(){
						puts("YES");
						cout << post[0];
						for(int i = 1; i < n; i++) cout << " " << post[i];
						cout << endl;
						return;
					}

					int fl(int a, int il, int ir){
					    int l = il, r = ir;
					    while(l < r){
					        int mid = l + (r-l)/2;
					        if(a <= in[mid]) r = mid;
					        else l = mid + 1;
					    }
					    if(in[r] == a) return r;
					    return -1;
					}

					int fr(int a, int il, int ir){
					    int l = il, r = ir;
					    while(l < r){
					        int mid = l + (r-l)/2 + 1;
					        if(in[mid] >= a) l = mid;
					        else r = mid - 1;
					    }
					    if(in[r] == a) return r;
					    return -1;
					}

					bool build(int il, int ir, int pl, int pr, int type){
						if(il > ir) return true;
						int root = pre[pl];
						int k;
						if(!type) k = fl(root, il, ir);
						else k = fr(root, il, ir);
						if(k == -1) return false;

						bool res = true;
						if(!build(il, k-1, pl+1, pl+1+(k-1-il), type)) res = false;
						if(!build(k+1, ir, pl+1+(k-il), pr, type)) res = false;
						post[cnt++] = root;

						return res;
					}

					int main(){
						cin >> n;
						for(int i = 0; i < n; i++){
							cin >> pre[i];
							in[i] = pre[i];
						}

						sort(in, in + n);
						if(build(0, n-1, 0, n-1, 0)){
							print();
							return 0;
						}

						cnt = 0;
						reverse(in, in + n);
						if(build(0, n-1,0, n-1, 1)){
							print();
							return 0;
						}

						puts("NO");
						return 0;
					} 
				r2.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					int pre[N], in[N], post[N], cnt;
					int n;

					int findl(int a, int il, int ir){
					    int l = il, r = ir;
					    while(l < r){
					        int mid = l + (r-l)/2;
					        if(a <= in[mid]) r = mid;
					        else l = mid + 1;
					    }
					    if(in[r] == a) return r;
					    return -1;
					}

					int findr(int a, int il, int ir){
					    int l = il, r = ir;
					    while(l < r){
					        int mid = l + (r-l)/2 + 1;
					        if(in[mid] >= a) l = mid;
					        else r = mid - 1;
					    }
					    if(in[r] == a) return r;
					    return -1;
					}

					void print(){
					    puts("YES");
					    cout << post[0];
					    for(int i = 1; i < n; i++) cout << " " << post[i];
					    cout << endl;
					    return ;
					}

					bool build(int il, int ir, int pl, int pr, int type){
					    if(il > ir) return true;
					    
					    int root = pre[pl];
					    int k;
					    if(type == 0) k = findl(root, il, ir);
					    else k = findr(root, il, ir);
					    if(k == -1) return false;
					    
					    bool res = true;
					    if(!build(il, k-1, pl+1, pl+1+(k-1-il), type)) res = false;
					    if(!build(k+1, ir, pl+1+(k-il), pr, type)) res = false;
					    post[cnt++] = root;
					    return res;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        cin >> pre[i];
					        in[i] = pre[i];
					    }
					    
					    sort(in, in + n);
					    if(build(0, n-1, 0, n-1, 0)){
					        print();
					        return 0;
					    }
					    
					    reverse(in, in + n);
					    cnt = 0;
					    if(build(0, n-1, 0, n-1, 1)){
					        print();
					        return 0;
					    }
					    
					    puts("NO");
					    return 0;
					}
				r3.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					int pre[N], in[N], post[N], cnt;
					int n;

					int findl(int a, int il, int ir){
					    int l = il, r = ir;
					    while(l < r){
					        int mid = l + (r-l)/2;
					        if(a <= in[mid]) r = mid;
					        else l = mid +1;
					    }
					    if(in[r] == a) return r;
					    return -1;
					}

					int findr(int a, int il, int ir){
					    int l = il, r = ir;
					    while(l < r){
					        int mid = l + (r-l) / 2 + 1;
					        if(in[mid] >= a) l = mid;
					        else r = mid - 1;
					    }
					    if(in[r] == a) return r;
					    return -1;
					}

					void print(){
					    puts("YES");
					    cout << post[0];
					    for(int i = 1; i < n; i++) cout << ' ' << post[i];
					    cout << endl;
					    return;
					}

					bool build(int il, int ir, int pl, int pr, int type){
					    if(il > ir) return true;
					    int root = pre[pl];
					    int k;
					    if(!type) k = findl(root, il, ir);
					    else k = findr(root, il, ir);
					    if(k == -1) return false;
					    
					    bool res = true;
					    if(!build(il, k - 1, pl + 1, pl + 1 + ( k - 1 - il), type)) res = false;
					    if(!build(k + 1, ir, pl + 1 + ( k - il), pr, type)) res = false;
					    post[cnt++] = root;
					    
					    return res;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        cin >> pre[i];
					        in[i] = pre[i];
					    }
					    
					    sort(in, in + n);
					    if(build(0, n - 1, 0, n - 1, 0)){
					        print();
					        return 0;
					    }
					    
					    reverse(in, in + n);
					    cnt = 0;
					    if(build(0, n - 1, 0 , n - 1, 1)){
					        print();
					        return 0;
					    }
					    
					    puts("NO");
					    return 0;
					}
				r4.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					int pre[N], in[N], post[N], cnt;
					int n;

					int findl(int a, int il, int ir){
					    int l = il, r = ir;
					    while(l < r){
					        int mid = l + (r-l)/2;
					        if(a <= in[mid]) r = mid;
					        else l = mid + 1;
					    }
					    if(in[r] == a) return r;
					    return -1;
					}

					int findr(int a, int il, int ir){
					    int l = il, r = ir;
					    while(l < r){
					        int mid = l +(r-l)/ 2 + 1;
					        if(in[mid] >= a) l = mid;
					        else r = mid - 1;
					    }
					    if(in[r] == a) return r;
					    return -1;
					}

					void print(){
					    puts("YES");
					    cout << post[0];
					    for(int i = 1; i < n; i++) cout << " " << post[i];
					    cout << endl;
					    return;
					}

					bool build(int il, int ir, int pl, int pr, int type){
					    if(il > ir) return true;
					    
					    int root = pre[pl];
					    int k;
					    if(!type) k = findl(root, il, ir);
					    else k = findr(root, il, ir);
					    if(k == -1) return false;
					    
					    bool res = true;
					    if(!build(il, k-1, pl + 1, pl + 1 + (k - 1 - il), type)) res = false;
					    if(!build( k + 1, ir, pl + 1 + (k - il), pr, type)) res = false;
					    post[cnt++] = root;
					    
					    return res;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        cin >> pre[i];
					        in[i] = pre[i];
					    }
					    
					    sort(in, in + n);
					    if(build(0, n - 1, 0, n - 1, 0)){
					        print();
					        return 0;
					    }
					    
					    reverse(in, in + n);
					    cnt = 0;
					    if(build(0, n - 1, 0, n - 1, 1)){
					        print();
					        return 0;
					    }
					    
					    puts("NO");
					    return 0;
					}
				r5.
					#include <iostream>
					#include <algorithm>

					using namespace std;


					const int N = 1010;
					int pre[N], in[N], post[N], cnt;
					int n;

					int findl(int a, int il, int ir){
					    int l = il, r = ir;
					    while(l < r){
					        int mid = l + ( r- l) /2;
					        if(a <= in[mid]) r = mid;
					        else l = mid + 1;
					    }
					    if(in[r] == a) return r;
					    return -1;
					}

					int findr(int a, int il, int ir){
					    int l = il, r = ir;
					    while(l < r){
					        int mid = l + (r- l) /2 + 1;
					        if(in[mid] >= a) l = mid;
					        else r = mid - 1;
					    }
					    if(in[r] == a) return r;
					    return -1;
					}

					void print(){
					    puts("YES");
					    cout << post[0];
					    for(int i = 1; i < n; i++) cout << " " << post[i];
					    cout << endl;
					    return;
					}

					bool build(int il, int ir, int pl, int pr, int type){
					    if(il > ir) return true;
					    
					    int root = pre[pl];
					    int k;
					    if(!type) k = findl(root, il, ir);
					    else k =  findr(root, il, ir);
					    if(k == -1) return false;
					    
					    bool res = true;
					    if(!build(il, k - 1, pl + 1, pl + 1 + (k - 1 - il), type)) res = false;
					    if(!build(k + 1, ir, pl + 1 + ( k - il), pr, type)) res = false;
					    post[cnt++] = root;
					    
					    return res;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        cin >> pre[i];
					        in[i] = pre[i];
					    }
					    
					    sort(in, in + n);
					    if(build(0, n - 1, 0, n - 1, 0)){
					        print();
					        return 0;
					    }
					    
					    reverse(in, in + n);
					    cnt = 0;
					    if(build(0, n - 1, 0, n - 1, 1)){
					        print();
					        return 0;
					    }
					    
					    puts("NO");
					    return 0;
					}

		49. 1550. 完全二叉搜索树	1064
			0. bug
				1.我们填充的时候, 是tree[u] = in[k++]. 我错写成了tree[k++] = in[u]. 我写的时候a[]代表in[], b[]代表tree[]
					u指的是 递归时候的当前根节点的编号,  k指的是,该用中序遍历的第k个数字了
				2. 完全二叉树,可以从ind == 1开始, 但是中序遍历的值, 可以从in的 ind == 0开始, 所以k也是从0开始, 输出也是从cin >> in[0]开始
			1. 笔记
				0. 
					1.dfs()遍历左右子树:
						之前的做法是:
							dfs(自己){
								if(有左子) dfs(左子)
								func(自己): 可以是打印自己, 或者像这道题一样, 把一个数字放入自己
								if(有右子) dfs(右子)
							}
						以前表示左右使用l[xx], r[xx]. 这里用的是 完全二叉树的 u*2, u*2+1
					2. 完全二叉树的一个性质:
						从0开始打印, 相当于是层序遍历
				1.
					思考:
						1. 瓶颈是sort() nlogn
						2. 所有的dfs()递归调用的时候用的是一个k, 所以写成k的引用
						3. 思路:
							1. 因为题目要的是排好序的完全二叉树
							2. 既然排好序,它的中序排列就是递增的
							3. 我们知道所有val,就可以求出这个完全二叉树的中序遍历
							4. 我们用中序遍历这个二叉树,将所有拍好序的值填进去就好了
							5. 最神奇的地方,用数组从头遍历到尾,其实就是二叉树的层序遍历
						4. 回忆:
							0. 跟是1
							1. 左子: n*2
							2. 右子: n*2+1
							3. 父亲: n/2(向下取整: 3/2 == 1)
							4. 最后一个非叶子节点: n / 2
				2. 
					1. 排好序 -> 二叉搜索树的中序遍历
					2. 按顺序填进去 -> 完全二叉树, 也就是left = x * 2, right = x * 2 + 1;
					3. 瓶颈在排序上, sort(), 复杂度nlogn
			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;

					int n;
					int w[N], tr[N];

					void dfs(int u, int& k) 
					{
					    if (u * 2 <= n) dfs(u * 2, k);
					    tr[u] = w[k ++ ];  中序遍历
					    if (u * 2 + 1 <= n) dfs(u * 2 + 1, k);
					}

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ ) cin >> w[i];

					    sort(w, w + n);

					    int k = 0; 大家共用一个k, 来知道怎么填
					    dfs(1, k);

					    cout << tr[1];
					    for (int i = 2; i <= n; i ++ ) cout << ' ' << tr[i];
					    cout << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/279716/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					int a[N], b[N];
					int n;
					int k;

					void dfs(int u){
						int l = u * 2, r = l + 1;
						if(l <= n) dfs(l);
						b[u] = a[k++]; //b[k++] = a[u];
						if(r <= n) dfs(r);
					}

					int main(){
						cin >> n;
						for(int i = 0; i < n; i++) cin >> a[i];
						sort(a, a + n);

						dfs(1);

						cout << b[1];
						for(int i = 2; i <= n; i++) cout << " " << b[i];
						cout << endl;
						return 0;
					}
				r2.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					int a[N], b[N];
					int n;
					int k;

					void dfs(int u){
					    int l = u * 2, r = l + 1;
					    if(l <= n) dfs(l);
					    b[u] = a[k++];
					    if(r <= n) dfs(r);
					}
					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> a[i];
					    
					    sort(a, a + n);
					    dfs(1);
					    
					    cout << b[1];
					    for(int i = 2; i <= n; i ++) cout << " " << b[i];
					    cout << endl;
					    return 0;
					}
				r3.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					int a[N], b[N];
					int n, k;

					void dfs(int u){
					    int l = u * 2, r = l + 1;
					    if(l <= n) dfs(l);
					    b[u] = a[k++];
					    if(r <= n) dfs(r);
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> a[i];
					    
					    sort(a, a + n);
					    dfs(1);
					    
					    cout << b[1];
					    for(int i = 2; i<= n; i++) cout << " " << b[i];
					    cout << endl;
					    return 0;
					}
				r4.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					int a[N], b[N];
					int n, k;

					void dfs(int u){
					    int l = u * 2, r = l + 1;
					    if(l <= n) dfs(l);
					    b[u] = a[k++];
					    if(r <= n) dfs(r);
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> a[i];
					    sort(a, a + n);
					    dfs(1);
					    cout << b[1];
					    for(int i = 2; i <= n; i++) cout << " " << b[i];
					    cout << endl;
					    return 0;
					}
				r5.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					int a[N], b[N];
					int n, k;

					void dfs(int u){
					    int l = u * 2, r = l + 1;
					    if(l <= n) dfs(l);
					    b[u] = a[k++];
					    if(r <= n) dfs(r);
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> a[i];
					    sort(a, a + n);
					    dfs(1);
					    cout << b[1];
					    for(int i = 2; i <= n; i++) cout << ' ' << b[i];
					    cout << endl;
					    return 0;
					}
			
		50. 1576. 再次树遍历	1086
			0. bug
				1.输入的时候出错了, 因为pop是没有接数字的
					我错在了直接写: cin >> type >> node;
					应该先判断type是不是push, 然后再cin >> node
			1. 笔记
				0. 我的方法和老师的完全不同:
					方法一: 在build()里面填充l, r. 之后dfs()
						我是先将pre[]和in[]填充好, 然后build(), build()的过程中每个节点的l,r都会记录下来
						之后用dfs()进行后序遍历,将结果存入res,最后输出res,也就是后序遍历
					方法二: 直接在build()里面后序遍历填充
						注意一定要有终止条件 if(il > ir) return;
				1.
					0. 思路:
						1. 方法一
							1. 第一个进入的一定是根节点
							2. 遇到一个a是push, 
								如果上一个b也是push,则a是b的左孩子
								如果上一个b是pop,则a是b的右孩子
						2. 方法二
							1. 如果是push进去的,就是先序遍历
							2. 如果是pop出来的,就是中序遍历

						1. type == 0是push
						2. 如果不是根节点,就加空格
						3. 老师也是使用了stack,来知道最后一个元素是什么. 但是如何判断last是push还是pop呢?
					1. 规律:
						当前是push[a]
							如果上一个是push[b], 那么b的左子就是a :l[b] = a;
							如果上一个是pop(), pop掉的元素的b, 那么b的右子就是a : r[b] = a
						当前是pop, pop掉的是a
							那么记录下, 这次是pop, pop的是a, 供下一次push使用
					2. 规律:
						push()是前序遍历
						pop()是中序遍历
						举例: push(1); push(2); push(3); pop(); pop(); push(4); pop(); pop(); push(5); push(6); pop(); pop()。
							前序: 1,2,3,4,5,6
							中序: 3,2,4,1,6,5
							是真的也!
			2. 注释
				1. y
					#include <iostream>
					#include <stack>

					using namespace std;

					const int N = 40;

					int n;
					int l[N], r[N];

					void dfs(int u, int root)
					{
					    if (!u) return;
					    dfs(l[u], root);
					    dfs(r[u], root);
					    cout << u;
					    if (u != root) cout << ' ';
					}

					int main()
					{
					    cin >> n;
					    int root;
					    int last = 0, type;
					    stack<int> stk;
					    for (int i = 0; i < n * 2; i ++ )
					    {
					        string op;
					        cin >> op;
					        if (op == "Push")
					        {
					            int x;
					            cin >> x;
					            if (!last) root = x;
					            else
					            {
					                if (type == 0) l[last] = x;
					                else r[last] = x;
					            }
					            stk.push(x);
					            last = x;
					            type = 0;  // 表示push
					        }
					        else
					        {
					            last = stk.top();
					            stk.pop();
					            type = 1;  // 表示pop
					        }
					    }

					    dfs(root, root);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/279748/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1. 方法一: 在build()里面填充l, r. 之后dfs()
					#include <iostream>
					#include <stack>
					#include <unordered_map>
					#include <vector>

					using namespace std;

					const int N = 100;

					int pre[N], in[N];
					unordered_map<int, int> l, r, pos;
					stack<int>  stk;
					vector<int> res;
					int n;

					int build(int il, int ir, int pl, int pr){
						int root = pre[pl];
						int k = pos[root];
						if(il < k) l[root] = build(il, k-1, pl+1, pl+1+(k-1-il));
						if(k < ir) r[root] = build(k+1, ir, pl+1+(k-il), pr);
						return root;
					}

					void dfs(int a){
						if(l.count(a)) dfs(l[a]);
						if(r.count(a)) dfs(r[a]);
						res.push_back(a);
					}

					void print(){
						cout << res[0];
						for(int i = 1; i < n; i++) cout << " " << res[i];
						cout << endl;
						return;
					}

					int main(){
						cin >> n;

						int pi = 0;
						int ii = 0;
						for(int i = 0; i < 2*n; i++){
							char type[10];
							int node;
							cin >> type;
							if(type[1] == 'u'){
							    cin >> node;
								stk.push(node);
								pre[pi++] = node;
							}
							else{
								int top = stk.top();
								stk.pop();
								in[ii] = top;
								pos[top] = ii++;
							}
							
						}

						int root = build(0, n-1, 0, n-1);
						dfs(root);
						print();
						return 0;
					}
				r2. 方法二: 直接在build()里面后序遍历填充
					#include <iostream>
					#include <stack>
					#include <unordered_map>
					#include <vector>

					using namespace std;

					const int N = 100;

					int pre[N], in[N];
					unordered_map<int, int> l, r, pos;
					stack<int>  stk;
					vector<int> post;
					int n;

					void build(int il, int ir, int pl, int pr){
					    if(il > ir) return;
						int root = pre[pl];
						int k = pos[root];
						build(il, k-1, pl+1, pl+1+(k-1-il));
						build(k+1, ir, pl+1+(k-il), pr);
						post.push_back(root);
					}

					void print(){
						cout << post[0];
						for(int i = 1; i < n; i++) cout << " " << post[i];
						cout << endl;
						return;
					}

					int main(){
						cin >> n;

						int pi = 0;
						int ii = 0;
						for(int i = 0; i < 2*n; i++){
							char type[10];
							int node;
							cin >> type;
							if(type[1] == 'u'){
							    cin >> node;
								stk.push(node);
								pre[pi++] = node;
							}
							else{
								int top = stk.top();
								stk.pop();
								in[ii] = top;
								pos[top] = ii++;
							}
							
						}

						build(0, n-1, 0, n-1);
						print();
						return 0;
					}
				r3. 一:
					#include <iostream>
					#include <vector>
					#include <unordered_map>
					#include <stack>

					using namespace std;

					const int N = 40;

					int cnt;
					vector<int> pre, in, post;
					unordered_map<int, int> pos;
					stack<int> stk;
					int n;

					void build(int il, int ir, int pl, int pr){
					    if(il > ir) return;
					    int root = pre[pl];
					    int k = pos[root];
					    if(il < k) build(il, k-1, pl+1, pl+1+(k-1-il));
					    if(k < ir) build(k+1, ir, pl+1+(k-il), pr);
					    post.push_back(root);
					}


					int main(){
					    cin >> n;
					    int ii = 0;
					    for(int i = 0; i < 2 * n ; i++){
					        char type[10];
					        int node;
					        cin >> type;
					        
					        if(type[1] == 'u'){
					            cin >> node;
					            stk.push(node);
					            pre.push_back(node);
					        }else{
					            int top = stk.top();
					            stk.pop();
					            in.push_back(top);
					            pos[top] = ii++;
					        }
					    }
					    
					    build(0, n-1, 0, n-1);
					    
					    cout << post[0];
					    for(int i = 1; i < n; i++) cout << " " << post[i];
					    cout << endl;
					    
					    return 0;
					}
				r4. 一:
					#include <iostream>
					#include <vector>
					#include <unordered_map>
					#include <stack>

					using namespace std;

					vector<int> pre, in, post;
					stack<int> stk;
					unordered_map<int, int> pos;
					int n;

					void build(int il, int ir, int pl, int pr){
					    if(il > ir) return;
					    int root = pre[pl];
					    int k = pos[root];
					    if(il < k) build(il, k-1, pl+1, pl+1+(k-1-il));
					    if(k < ir) build(k+1, ir, pl+1+(k-il), pr);
					    post.push_back(root);
					}

					int main(){
					    cin >> n;
					    
					    int ii = 0;
					    for(int i = 0; i < 2 * n; i++){
					        char type[10];
					        cin >> type;
					        if(type[1] == 'u'){
					            int node;
					            cin >> node;
					            pre.push_back(node);
					            stk.push(node);
					        }else{
					            int top = stk.top();
					            stk.pop();
					            in.push_back(top);
					            pos[top] = ii++;
					        }
					    }
					    
					    build(0, n-1, 0, n-1);
					    
					    cout <<post[0];
					    for(int i = 1; i < n; i++) cout << " " << post[i];
					    cout << endl;
					    return 0;
					}
				r5. 二:
					#include <iostream>
					#include <vector>
					#include <unordered_map>
					#include <stack>

					using namespace std;

					vector<int> pre, in, post;
					unordered_map<int, int> l, r, pos;
					stack<int> stk;
					int n;

					int build(int il, int ir, int pl, int pr){
					    int root = pre[pl];
					    int k = pos[root];
					    if(il < k) l[root] = build(il, k-1, pl+1, pl+1+(k-1-pl));
					    if(k < ir) r[root] = build(k+1, ir, pl+1+(k-il), pr);
					    return root;
					}

					void dfs(int a){
					    if(l.count(a)) dfs(l[a]);
					    if(r.count(a)) dfs(r[a]);
					    post.push_back(a);
					}

					int main(){
					    cin >> n;
					    int ii = 0;
					    for(int i = 0; i < 2 * n; i++){
					        char type[10];
					        cin >> type;
					        if(type[1] == 'u'){
					            int node;
					            cin >> node;
					            pre.push_back(node);
					            stk.push(node);
					        }else{
					            int top = stk.top();
					            stk.pop();
					            in.push_back(top);
					            pos[top] = ii++;
					        }
					    }
					    
					    int root = build(0, n-1, 0, n-1);
					    dfs(root);
					    cout << post[0];
					    for(int i = 1; i < n; i++) cout << " " << post[i];
					    cout << endl;
					    return 0;
					}
				r6: 二:
					#include <iostream>
					#include <vector>
					#include <unordered_map>
					#include <stack>

					using namespace std;

					vector<int> pre, in, post;
					unordered_map<int, int> l, r, pos;
					stack<int> stk;
					int n;

					int build(int il, int ir, int pl, int pr){
					    int root = pre[pl];
					    int k = pos[root];
					    if(il <k) l[root] = build(il, k-1, pl+1, pl+1+(k-1-il));
					    if(k < ir) r[root] = build(k+1, ir, pl+1+(k-il), pr);
					    return root;
					}

					void dfs(int a){
					    if(l.count(a)) dfs(l[a]);
					    if(r.count(a)) dfs(r[a]);
					    post.push_back(a);
					}

					int main(){
					    cin >> n;
					    
					    int ii = 0;
					    for(int i = 0; i < 2 * n; i++){
					        char t[10];
					        cin >> t;
					        if(t[1] == 'u'){
					            int node;
					            cin >> node;
					            pre.push_back(node);
					            stk.push(node);
					        }else{
					            int top = stk.top();
					            stk.pop();
					            in.push_back(top);
					            pos[top] = ii++;
					        }
					    }
					    
					    int root = build(0, n-1, 0, n-1);
					    dfs(root);
					    cout << post[0];
					    for(int i = 1; i < n; i++) cout << " " << post[i];
					    cout << endl;
					    return 0;
					}
		
		51. 1589. 构建二叉搜索树	1099
			0. bug
				1. 
					不能写成:
						for(int i = 0; i < n; i++){
							cin >> a >> b;
							l[i] = a;
							r[i] = b;
						}
					而应该是:
						for(int i = 0; i < n; i++){
							cin >> a >> b;
							
							if(a != -1) l[i] = a;
							if(b != -1) r[i] = b;
						}

					或者用老师的方法也是可以的, 老师直接用了 int l[N], int r[N], 而不是我的unordered_map<int,int> 
				2. 虽然输出是层序遍历, 但是填入的时候是中序遍历, 所以用到了dfs和bfs
			1. 笔记
				思路:
					1. 同样也是,排序好了之后,填进去
					2. 用到了dfs和bfs
			2. 注释
				1. y
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					int n;
					int l[N], r[N];
					int a[N], w[N];
					int q[N];

					void dfs(int u, int& k)
					{
					    if (u == -1) return;

					    dfs(l[u], k);
					    w[u] = a[k ++ ];
					    dfs(r[u], k);
					}

					void bfs()
					{
					    int hh = 0, tt = 0;
					    q[0] = 0;

					    while (hh <= tt)
					    {
					        int t = q[hh ++ ];
					        if (l[t] != -1) q[ ++ tt] = l[t];
					        if (r[t] != -1) q[ ++ tt] = r[t];
					    }

					    cout << w[q[0]];
					    for (int i = 1; i < n; i ++ ) cout << ' ' << w[q[i]];
					}

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ ) cin >> l[i] >> r[i];
					    for (int i = 0; i < n; i ++ ) cin >> a[i];
					    sort(a, a + n);

					    int k = 0;
					    dfs(0, k);
					    bfs();

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/279760/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1. 方法一: 用<unordered_map> 存l, r
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					unordered_map<int, int> l, r;
					int temp[N];
					int n;
					int q[N], res[N];
					int cnt;

					void dfs(int root){
					    if(l.count(root)) dfs(l[root]);
					    res[root] = temp[cnt++];
					    if(r.count(root)) dfs(r[root]);
					}

					void bfs(int root){
						q[0] = root;
						int h, t;
						h = t = 0;
						while(h <= t){
							int top = q[h++];
							if(l.count(top)) q[++t] = l[top];
							if(r.count(top)) q[++t] = r[top];
						}
						cout << res[q[0]];
						for(int i = 1; i < h; i++) cout << " " << res[q[i]];
						cout << endl;
					}

					int main(){
						cin >> n;
						int a, b;
						for(int i = 0; i < n; i++){
							cin >> a >> b;
							if(a != -1) l[i] = a;
							if(b != -1) r[i] = b;
						}
						for(int i = 0 ; i < n; i++) cin >> temp[i];
						sort(temp, temp + n);

					    dfs(0);
						bfs(0);

						return 0;


					}
				r2. 一:
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					unordered_map<int, int> l, r;
					int nums[N];
					int res[N];
					int q[N];
					int n;
					int cnt;

					void dfs(int a){
					    if(l.count(a)) dfs(l[a]);
					    res[a] = nums[cnt++];
					    if(r.count(a)) dfs(r[a]);
					}

					void bfs(int a){
					    q[0] = a;
					    int hh, tt;
					    hh = tt = 0;
					    while( hh <= tt){
					        int top = q[hh++];
					        if(l.count(top)) q[++tt] = l[top];
					        if(r.count(top)) q[++tt] = r[top];
					    }
					    cout << res[q[0]];
					    for(int i = 1; i < hh; i++) cout << " " << res[q[i]];
					    cout << endl;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        int a, b;
					        cin >> a >> b;
					        if(a != -1) l[i] = a;
					        if(b != -1) r[i] = b;
					    }
					    
					    for(int i = 0; i <n; i++) cin >> nums[i];
					    sort(nums, nums + n);
					    
					    dfs(0);
					    bfs(0);
					    
					    return 0;
					}
				r3. 一:
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					unordered_map<int, int> l, r;
					int nums[N], cnt;
					int res[N];
					int q[N];
					int n;

					void dfs(int a){
					    if(l.count(a)) dfs(l[a]);
					    res[a] = nums[cnt++];
					    if(r.count(a)) dfs(r[a]);
					}

					void bfs(int a){
					    q[0] = a;
					    int hh, tt;
					    hh = tt = 0;
					    while(hh <= tt){
					        int top = q[hh++];
					        if(l.count(top)) q[++tt] = l[top];
					        if(r.count(top)) q[++tt] = r[top];
					    }
					    cout << res[q[0]];
					    for(int i = 1; i < hh; i ++) cout << " " << res[q[i]];
					    cout << endl;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        int a, b;
					        cin >> a >> b;
					        if(a != -1) l[i] = a;
					        if(b != -1) r[i] = b;
					    }
					    for(int i = 0; i < n; i++) cin >> nums[i];
					    sort(nums, nums + n);
					    
					    dfs(0);
					    bfs(0);
					    
					    return 0;
					}
				r4. 一:
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					unordered_map<int, int> l, r;
					int nums[N], cnt;
					int res[N];
					int q[N];
					int n;

					void dfs(int a){
					    if(l.count(a)) dfs(l[a]);
					    res[a] = nums[cnt++];
					    if(r.count(a)) dfs(r[a]);
					}

					void bfs(int a){
					    q[0] = a;
					    int hh, tt;
					    hh = tt = 0;
					    while(hh <= tt){
					        int top = q[hh++];
					        if(l.count(top)) q[++tt] = l[top];
					        if(r.count(top)) q[++tt] = r[top];
					    }
					    cout << res[q[0]];
					    for(int i = 1; i < hh; i++) cout << " " << res[q[i]];
					    cout << endl;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i< n; i++){
					        int a, b;
					        cin >> a >> b;
					        if(a != -1) l[i] = a;
					        if(b != -1) r[i] = b;
					    }
					    for(int i = 0; i<n; i++) cin >> nums[i];
					    sort(nums, nums +n);
					    
					    dfs(0);
					    bfs(0);
					    return 0;
					}
				r5. 二:
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					int l[N], r[N];
					int nums[N], cnt;
					int res[N];
					int q[N];
					int n;

					void dfs(int a){
					    if(l[a] != -1) dfs(l[a]);
					    res[a] = nums[cnt++];
					    if(r[a] != -1) dfs(r[a]);
					}

					void bfs(int a){
					    q[0] = a;
					    int hh, tt;
					    hh = tt = 0;
					    while(hh <= tt){
					        int top = q[hh++];
					        if(l[top] != -1) q[++tt] = l[top];
					        if(r[top] != -1) q[++tt] = r[top];
					    }
					    cout << res[q[0]];
					    for(int i = 1; i < hh; i++) cout << " " << res[q[i]];
					    cout << endl;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        int a, b;
					        cin >> a >> b;
					        l[i] = a, r[i] = b;
					    }
					    for(int i = 0; i < n; i++) cin >> nums[i];
					    sort(nums, nums + n);
					    
					    dfs(0);
					    bfs(0);
					    return 0;
					    
					}
				r6: 一:
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					int l[N], r[N];
					int nums[N], cnt;
					int res[N];
					int q[N];
					int n;

					void dfs(int a){
					    if(l[a] != -1) dfs(l[a]);
					    res[a] = nums[cnt++];
					    if(r[a] != -1) dfs(r[a]);
					}

					void bfs(int a){
					    q[0] = a;
					    int hh, tt;
					    hh = tt = 0;
					    while(hh <= tt){
					        int top = q[hh++];
					        if(l[top] != -1) q[++tt] = l[top];
					        if(r[top] != -1) q[++tt] = r[top];
					    }
					    cout << res[q[0]];
					    for(int i = 1; i < hh; i++) cout << " " <<res[q[i]];
					    cout << endl;
					}
					int main(){
					    cin >> n;
					    for(int i = 0; i <n; i++){
					        int a, b;
					        cin >> a >> b;
					        l[i] = a, r[i] = b;
					    }
					    for(int i = 0; i < n; i++) cin >>nums[i];
					    sort(nums, nums + n);
					    
					    dfs(0);
					    bfs(0);
					    
					    return 0;
					}

	12. 2020年10月18日14:19:51
	
		52. 1592. 反转二叉树	1102
			0. bug
				1.题目没有说谁是根节点, 你不能默认0是root
					计算谁是root: 
						首先hf[] = true
							if (a != '-') l[i] = a - '0', has_father[l[i]] = true;
						其次找没有father的节点
							int root = 0;
							while (has_father[root]) root ++ ;
				2. 传引用的时候, 一定是传变量, 而不是常数:
					例如void xx(int &a);
					要写成:
						int i = 0;
						xx(i);
					而不能写成:
						xx(0)
				3. dfs()
					两种方式终止:
						1.
							void dfs_r(int u){
								if(l[u] != -1) dfs_r(l[u]);
								if(r[u] != -1) dfs_r(r[u]);
								swap(l[u], r[u]);
							}
						2. 
							void dfs_reverse(int u)
							{
							    if (u == -1) return;
							    dfs_reverse(l[u]);
							    dfs_reverse(r[u]);
							    swap(l[u], r[u]);
							}

			1. 笔记
				思路:
					1. 从最底部开始, 所有节点的左右儿子反过来. 因为是最底部开始, 所以是后序遍历翻转. 就像是删除一个树, 是后序遍历先把左右子树删除, 最后删除自己
					2. 用char输入是因为有'-'符号,不能读成int
					3. 判断哪个点是根节点,看是否有父亲,没有就是根节点
					4. 老师是用后序遍历来翻转,用其他可否? 最好还是后序遍历, 先处理好左右子树, 最后是自己
					5. 中序遍历, 因为不能输出最后一个空格, 老师用了一个输出多少个来判断是否是最后一个数.
						传引用 int& k, 因为大家都要用到这个数
						void dfs(int u, int& k)
						{
						    if (u == -1) return;
						    dfs(l[u], k);

						    cout << u;
						    if ( ++ k != n) cout << ' ';

						    dfs(r[u], k);
						}
					6. 层序遍历就没有, 因为层序遍历不是用递归, 而是用queue

			2. 注释
				1. y
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 15;

					int n;
					int l[N], r[N];
					int q[N];
					bool has_father[N];

					void dfs_reverse(int u)
					{
					    if (u == -1) return;

					    dfs_reverse(l[u]);
					    dfs_reverse(r[u]);
					    swap(l[u], r[u]);
					}

					void bfs(int root)
					{
					    int hh = 0, tt = 0;
					    q[0] = root;
					    while (hh <= tt)
					    {
					        int t = q[hh ++ ];
					        if (l[t] != -1) q[ ++ tt] = l[t];
					        if (r[t] != -1) q[ ++ tt] = r[t];
					    }

					    cout << q[0];
					    for (int i = 1; i < n; i ++ ) cout << ' ' << q[i];
					    cout << endl;
					}

					void dfs(int u, int& k)
					{
					    if (u == -1) return;
					    dfs(l[u], k);

					    cout << u;
					    if ( ++ k != n) cout << ' ';

					    dfs(r[u], k);
					}

					int main()
					{
					    cin >> n;

					    memset(l, -1, sizeof l);
					    memset(r, -1, sizeof r);
					    for (int i = 0; i < n; i ++ )
					    {
					        char lc, rc;
					        cin >> lc >> rc;
					        if (lc != '-') l[i] = lc - '0', has_father[l[i]] = true;
					        if (rc != '-') r[i] = rc - '0', has_father[r[i]] = true;
					    }

					    int root = 0;
					    while (has_father[root]) root ++ ;

					    dfs_reverse(root);
					    bfs(root);

					    int k = 0;
					    dfs(root, k);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/279781/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 20;
					int l[N], r[N];
					bool hf[N];
					int n;
					int q[N];

					void dfs_r(int u){
						if(l[u] != -1) dfs_r(l[u]);
						if(r[u] != -1) dfs_r(r[u]);
						swap(l[u], r[u]);
					}

					void dfs(int u, int& i){
						if(u == -1) return;
						dfs(l[u], i);
						if(++i != n) cout << u << " ";
						else cout << u << endl;
						dfs(r[u], i);
					}

					void bfs(int u){
						q[0] = u;
						int hh, tt;
						hh = tt = 0;
						while(hh <= tt){
							int top = q[hh++];
							if(l[top] != -1) q[++tt] = l[top];
							if(r[top] != -1) q[++tt] = r[top];
						}
						cout << q[0];
						for(int i = 1; i < hh; i++) cout << " " << q[i];
						cout << endl;
					}

					int main(){
						cin >> n;

						memset(l, -1, sizeof l);
						memset(r, -1, sizeof r);
						for(int i = 0; i < n; i++){
							char a, b;
							cin >> a >> b;
							if(a != '-') l[i] = a - '0', hf[l[i]] = true;
							if(b != '-') r[i] = b - '0', hf[r[i]] = true;
						}

					    int root = 0;
					    while(hf[root]) root++;
					    
						dfs_r(root);
						
						bfs(root);
						
						int i = 0;
						dfs(root, i);
						
						

					}
				r2.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 20;
					int l[N], r[N];
					bool hf[N];
					int q[N];
					int n;

					void dfsr(int u){
					    if(u == -1) return;
					    dfsr(l[u]);
					    dfsr(r[u]);
					    swap(l[u], r[u]);
					}

					void bfs(int u){
					    q[0] = u;
					    int hh, tt;
					    hh = tt = 0;
					    while(hh <= tt){
					        int top = q[hh++];
					        if(l[top] != -1) q[++tt] = l[top];
					        if(r[top] != -1) q[++tt] = r[top];
					    }
					    cout << q[0];
					    for(int i = 1; i < hh; i++) cout << " " << q[i];
					    cout << endl;
					}

					void dfs(int u, int& i){
					    if(u == -1) return;
					    dfs(l[u], i);
					    
					    cout << u;
					    if(++i != n) cout << " ";
					    else cout << endl;
					    
					    dfs(r[u], i);
					    
					}

					int main(){
					    cin >> n;
					    
					    memset(l, -1, sizeof l);
					    memset(r, -1, sizeof r);
					    
					    for(int i = 0; i < n; i++){
					        char a, b;
					        cin >> a >> b;
					        if(a != '-') l[i] = a - '0', hf[l[i]] = true;
					        if(b != '-') r[i] = b - '0', hf[r[i]] = true;
					    }
					    
					    int root = 0;
					    while(hf[root]) root++;
					    
					    dfsr(root);
					    
					    bfs(root);
					    
					    int i = 0;
					    dfs(root, i);
					    
					    return 0;
					}
				r3.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 40;
					int l[N], r[N];
					bool hf[N];
					int q[N];
					int n;


					void dfsr(int u){
					    if(u == -1) return;
					    dfsr(l[u]);
					    dfsr(r[u]);
					    swap(l[u], r[u]);
					}

					void bfs(int u){
					    q[0] = u;
					    int hh, tt;
					    hh = tt = 0;
					    while(hh <= tt){
					        int t = q[hh++];
					        if(l[t] != -1) q[++tt] = l[t];
					        if(r[t] != -1) q[++tt] = r[t];
					    }
					    cout << q[0];
					    for(int i = 1; i < hh; i++) cout << " " << q[i];
					    cout << endl;
					}

					void dfs(int u, int& i){
					    if(u == -1) return;
					    dfs(l[u], i);
					    cout << u;
					    if(++i != n) cout << " ";
					    else cout << endl;
					    dfs(r[u], i);
					}
					int main(){
					    cin >> n;
					    
					    memset(l ,-1, sizeof l);
					    memset(r, -1, sizeof r);
					    
					    for(int i = 0; i < n; i++){
					        char a, b;
					        cin >> a >> b;
					        if(a != '-') l[i] = a - '0', hf[l[i]] = true;
					        if(b != '-') r[i] = b - '0', hf[r[i]] = true;
					    }
					    
					    int root = 0;
					    while(hf[root]) root++;
					    
					    dfsr(root);
					    
					    bfs(root);
					    
					    int i = 0;
					    dfs(root, i);
					}
				r4.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 20;
					int l[N], r[N], q[N];
					bool hf[N];
					int n;

					void dfsr(int u){
					    if(u == -1) return;
					    dfsr(l[u]);
					    dfsr(r[u]);
					    swap(l[u], r[u]);
					}

					void bfs(int u){
					    q[0] = u;
					    int hh, tt;
					    hh = tt = 0;
					    while(hh <= tt){
					        int t = q[hh++];
					        if(l[t] != -1) q[++tt] = l[t];
					        if(r[t] != -1) q[++tt] = r[t];
					    }
					    cout << q[0];
					    for(int i = 1; i < hh; i++) cout << " "<< q[i];
					    cout << endl;
					}

					void dfs(int u, int& i){
					    if(u == -1) return;
					    dfs(l[u], i);
					    cout << u;
					    if(++i != n) cout << " ";
					    else cout << endl;
					    dfs(r[u], i);
					}

					int main(){
					    cin >> n;
					    
					    memset(l, -1, sizeof l);
					    memset(r, -1, sizeof r);
					    
					    for(int i = 0; i < n; i++){
					        char a, b;
					        cin >> a >> b;
					        if(a != '-') l[i] = a - '0', hf[l[i]] = true;
					        if(b != '-') r[i] = b - '0', hf[r[i]] = true;
					    }
					    
					    int root = 0;
					    while(hf[root]) root++;
					    
					    dfsr(root);
					    
					    bfs(root);
					    
					    int i = 0;
					    dfs(root, i);
					}
				r5.

		53. 1600. 完全二叉搜索树 1110
			0. bug
				1. 大bug!
					1. 首先这道题和上面的翻转二叉树不同. 翻转二叉树的输入是一个个位数, 所以可以用char读, 但是这道题可以是两位数, 所以你不能用 a - '0'的方法读!!
						错误:
								char a, b; 因为a可以是"10"
								cin >> a >> b;
								if(a != '-') l[i] = a - '0', hf[l[i]] = true;
						正确:
							string a, b;
					        cin >> a >> b;
					        if (a != "-") l[i] = stoi(a), has_father[l[i]] = true;
			1. 笔记
				思路:
					1. 记录每个节点的左右子
					2. 题目没有给根节点,需要通过是否有father来判断是否是根节点
					3. 在dfs()遍历的过程中, 给每个节点赋予 完全二叉树的编号 k, 例如左子是 u*2, 右子是 u*2+1
						最后记录maxk.
						因为题目要求输出maxk对应的编号, 所以你还要记录一个maxid
			2. 注释
				1. y
					#include <cstring>
					#include <iostream>

					using namespace std;

					const int N = 25;

					int n;
					int l[N], r[N];
					bool has_father[N];
					int maxk, maxid;

					void dfs(int u, int k)
					{
					    if (u == -1) return;

					    if (k > maxk)
					    {
					        maxk = k;
					        maxid = u;
					    }

					    dfs(l[u], k * 2);
					    dfs(r[u], k * 2 + 1);
					}

					int main()
					{
					    memset(l, -1, sizeof l);
					    memset(r, -1, sizeof r);

					    cin >> n;
					    for (int i = 0; i < n; i ++ )
					    {
					        string a, b;
					        cin >> a >> b;
					        if (a != "-") l[i] = stoi(a), has_father[l[i]] = true;
					        if (b != "-") r[i] = stoi(b), has_father[r[i]] = true;
					    }

					    int root = 0;
					    while (has_father[root]) root ++ ;

					    dfs(root, 1);

					    if (maxk == n) printf("YES %d\n", maxid);
					    else printf("NO %d\n", root);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/283547/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 30;
					int l[N], r[N], kk[N], maxk, maxid;
					bool hf[N];
					int n;

					void dfs(int u, int k){
						if(u == -1) return;

						kk[u] = k;
						if(k > maxk){
						    maxk = k;
						    maxid = u;
						}

						dfs(l[u], k * 2);
						dfs(r[u], k * 2 + 1);
					}

					int main(){
						cin >> n;
						memset(l, -1, sizeof l);
						memset(r, -1, sizeof r);

						for(int i = 0; i < n; i++){
							string a, b;
							cin >> a >> b;
							if(a != "-") l[i] = stoi(a), hf[l[i]] = true;
							if(b != "-") r[i] = stoi(b), hf[r[i]] = true;
						}

						int r = 0;
						while(hf[r]) r++;
						
						dfs(r, 1);

						if(maxk > n) printf("NO %d\n", r);
						else printf("YES %d\n", maxid);

						return 0;
					}
				r2.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 30;
					int l[N], r[N], maxk, maxid;
					bool hf[N];
					int n;

					void dfs(int u, int k){
					    if(u == -1) return;
					    if(k > maxk){
					        maxk = k;
					        maxid = u;
					    }
					    dfs(l[u], k * 2);
					    dfs(r[u], k * 2 + 1);
					}

					int main(){
					    cin >> n;
					    
					    memset(l, -1, sizeof l);
					    memset(r, -1, sizeof r);
					    
					    for(int i = 0; i < n; i++){
					        string a, b;
					        cin >> a >> b;
					        if(a != "-") l[i] = stoi(a), hf[l[i]] = true;
					        if(b != "-") r[i] = stoi(b), hf[r[i]] = true;
					    }
					    
					    int root = 0;
					    while(hf[root]) root++;
					    
					    dfs(root, 1);
					    
					    if(maxk != n) printf("NO %d\n", root);
					    else printf("YES %d\n", maxid);
					    
					    return 0;
					}
				r3.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 30;
					int l[N], r[N], maxk, maxid;
					int n;
					bool hf[N];

					void dfs(int u, int k){
					    if(u == -1) return;
					    if(k > maxk) maxk = k, maxid = u;
					    dfs(l[u], k * 2);
					    dfs(r[u], k * 2 + 1);
					}

					int main(){
					    cin >> n;
					    
					    memset(l, -1, sizeof l);
					    memset(r, -1, sizeof r);
					    
					    for(int i = 0; i < n; i++){
					        string a, b;
					        cin >> a >> b;
					        if(a != "-") l[i] = stoi(a), hf[l[i]] = true;
					        if(b != "-") r[i] = stoi(b), hf[r[i]] = true;
					    }
					    
					    int root  = 0;
					    while(hf[root]) root++;
					    
					    dfs(root, 1);
					    
					    if(maxk == n) printf("YES %d\n", maxid);
					    else printf("NO %d\n", root);
					    
					    return 0;
					}
				r4.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 30;
					int l[N], r[N], maxk, maxid, n;
					bool hf[N];

					void dfs(int u, int k){
					    if(u == -1) return;
					    if(k > maxk) maxk = k, maxid = u;
					    dfs(l[u], k * 2);
					    dfs(r[u], k * 2 + 1);
					}

					int main(){
					    cin >> n;
					    memset(l, -1, sizeof l);
					    memset(r, -1, sizeof r);
					    
					    for(int i = 0; i < n; i++){
					        string a, b;
					        cin >> a >> b;
					        if(a != "-") l[i] = stoi(a), hf[l[i]] = true;
					        if(b != "-") r[i] = stoi(b), hf[r[i]] = true;
					    }
					    
					    int root = 0;
					    while(hf[root]) root ++;
					    
					    dfs(root, 1);
					    
					    if(maxk == n) printf("YES %d\n", maxid);
					    else printf("NO %d\n", root);
					    
					    return 0;
					}
				r5.

		54. 1605. 二叉搜索树最后两层结点数量	1115
			0. bug
				1. 终止条件记得return
				2. memset()只能填入一个字节, 所以填入0x3f, 并设置INF = 0x3f3f3f3f.
					不过老师用u == 0来判断也是可以的,因为虽然输入可能是0,但是这个0,是数值的w[u] = 0
					而不是u == 0, u代表的是ind, 它从1开始
			1. 笔记
				0.
					很神奇的insert():
						1. 我给你举个例子: 
							1. 26, 24, 21
								root = 1
								  	0	1	2	3	4
								w 		26	24  21				 1. u = ++ idx;v[u] = w; 	=>	 root = ++ idx = 1; w[1] = 26;
								l 		2	3					 2. insert(l[u], w); =>  u = ++ idx;v[u] = w; 	=>   l[root] = l[1] = ++ ind = 2; w[2] = 24	
								 								 3. insert(l[u], w); =>  u = ++ idx;v[u] = w; 	=>   l[u] = l[2] = ++ ind = 3; w[3] = 21	
								r 								 r没有更新
							2. 26, 24, 29, 21	
								root = 1
								  	0	1	2	3	4
								w 		26	24  29	21			  1. u = ++ idx;v[u] = w; 	=>	 root = ++ idx = 1; w[1] = 26;
								l 		2(a)4(d)(e)				  2. insert(l[u], w); => u = ++ idx;v[u] = w; 	=>   l[root] = l[1] = ++ ind = 2; w[2] = 24	
								 								  4. insert(l[u], w); => u = ++ idx;v[u] = w; 	=>   l[u] = l[2] = ++ ind = 4; w[4] = 24		
								r 		3(b)(c)	(f)  			  3. insert(r[u], w); => u = ++ idx;v[u] = w; 	=>   r[root] = r[1] = ++ ind = 3; w[3] = 29
								规律:
									a点(编号为2)的点的left和right是: d点和c点, 也就是left的编号为4, 对应的数字是w[4], right是空
									b点(编号为3)的点left和right是: e点和f点, 说明都是空(因为值==0, 值==0表示空)
					insert()模板:
						int l[N], r[N], w[N], ind;

						void insert(int& u, int v){ 记得一定是传引用. 
							if(!u){ 说明这个位置没有使用, 即root == 0, 或者l[u] == 0, r[u] == 0;
								u = ++ind; 所以标号/token从1开始. 因为是传引用, 所以可以把l[u], r[u]改变
								w[u] = v;
								return;
							}

							if(v <= w[u]) insert(l[u], v);
							else insert(r[u], v);
						}

						int root = 0; 意思是空节点, 相当于l[N]全局变量都是0, 也就是都是空节点
						for(int i = 0; i < n; i++){
							int v;
							cin >> v;
							insert(root, v);
						}

				1.
					0.
						1. 编号从1开始, 因为0有特殊含义: 空节点
					1. 题目没有给编号,所以我们用ind来设置编号
					2. 如果某个节点是0,意味着空的,我们传入&u是因为想改变它的值.
						void insert(int& u, int w) 好厉害!
						{
						    if (!u) //如果是空的
						    {
						        u = ++ idx; //创建节点
						        v[u] = w; //赋值
						        return;
						    }
						    if (w <= v[u]) insert(l[u], w);  因为insert(int &i ,int w), 所以可以改变l[u]的值
						    else insert(r[u], w);
						}
					3. dfs()是前序遍历来计算max_depth
					4. 二叉树老师喜欢用l[N],r[N], 而不是struct Node{int val; Node l, r;};

			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					const int N = 1010;

					int n;
					int l[N], r[N], v[N], idx;
					int cnt[N], max_depth;

					void insert(int& u, int w)
					{
					    if (!u)
					    {
					        u = ++ idx;
					        v[u] = w;
					    }
					    else if (w <= v[u]) insert(l[u], w);
					    else insert(r[u], w);
					}

					void dfs(int u, int depth)
					{
					    if (!u) return;
					    cnt[depth] ++ ;
					    max_depth = max(max_depth, depth);
					    dfs(l[u], depth + 1);
					    dfs(r[u], depth + 1);
					}

					int main()
					{
					    cin >> n;

					    int root = 0;
					    for (int i = 0; i < n; i ++ )
					    {
					        int w;
					        cin >> w;
					        insert(root, w);
					    }

					    dfs(root, 0);

					    int n1 = cnt[max_depth], n2 = cnt[max_depth - 1];
					    printf("%d + %d = %d\n", n1, n2, n1 + n2);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/283562/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>
					#include <cstring>
					#include <unordered_map>

					using namespace std;

					const int N = 1010, INF = 0x3f3f3f3f;
					int l[N], r[N], ind, w[N];
					int cnt[N], maxd;
					int n;

					void insert(int& u, int v, int depth){
						if(u == INF){
							u = ++ ind;
							w[u] = v;
							cnt[depth]++;
							if(depth > maxd) maxd = depth;
						}
						else if(v <= w[u]) insert(l[u], v, depth + 1);
						else insert(r[u], v, depth + 1);
					}

					int main(){
						cin >> n;
 
						
						memset(l, 0x3f, sizeof l);
						memset(r, 0x3f, sizeof r);

						int root = INF;
						for(int i = 0; i < n; i++){
							int v;
							cin >> v;
							insert(root, v, 0);
						}

						printf("%d + %d = %d", cnt[maxd], cnt[maxd - 1], cnt[maxd] + cnt[maxd - 1]);
						return 0;

					}
				r2.
					#include <iostream>

					using namespace std;

					const int N = 1010;
					int l[N], r[N], w[N], ind;
					int cnt[N], maxd;
					int n;

					void insert(int& u, int v, int depth){
						if(!u){
							u = ++ind;
							w[u] = v;
							cnt[depth]++;
							maxd = max(maxd, depth);
							return;
						}

						if(v <= w[u]) insert(l[u], v, depth + 1);
						else insert(r[u], v, depth + 1);
					}

					int main(){
						cin >> n;
						int root = 0;
						for(int i = 0; i < n; i++){
							int v;
							cin >> v;
							insert(root, v, 0);
						}

						int a = cnt[maxd], b = cnt[maxd-1];
						printf("%d + %d = %d\n", a, b, a + b);
						return 0;
					}
				r3.
					#include <iostream>

					using namespace std;

					const int N = 1010;
					int l[N], r[N], w[N], ind;
					int cnt[N], maxd;
					int n;

					void insert(int& u, int v, int depth){
					    if(!u){
					        u = ++ind;
					        w[u] = v;
					        cnt[depth]++;
					        maxd = max(maxd, depth);
					        return;
					    }
					    if(v <= w[u]) insert(l[u], v, depth + 1);
					    else insert(r[u], v, depth + 1);
					    
					}

					int main(){
					    cin >> n;
					    
					    int root = 0;
					    for(int i = 0; i < n; i++){
					        int v;
					        cin >> v;
					        insert(root, v, 0);
					    }
					    
					    int a = cnt[maxd], b = cnt[maxd-1];
					    printf("%d + %d = %d\n", a, b, a + b);
					    return 0;
					}
				r4.
					#include <iostream>

					using namespace std;

					const int N = 1010;
					int l[N], r[N], w[N], ind;
					int cnt[N], maxd;
					int n;

					void insert(int& u, int v, int d){
					    if(!u){
					        u = ++ind;
					        w[u] = v;
					        cnt[d]++;
					        maxd = max(maxd, d);
					        return;
					    }
					    if(v <= w[u]) insert(l[u], v, d+1);
					    else insert(r[u], v, d + 1);
					}
					int main(){
					    cin >> n;
					    
					    int root = 0;
					    for(int i = 0; i < n; i++){
					        int v;
					        cin >> v;
					        insert(root, v, 0);
					    }
					    
					    int a = cnt[maxd], b = cnt[maxd-1];
					    printf("%d + %d = %d\n", a, b, a+b);
					    return 0;
					}
				r5.

		55. 1609. 前序和后序遍历	1119
			0. bug
				1.
					1. 错误的:
						string ls, rs;
						for(int i = l1+1; i <= r1; i++){
							lc = build(l1 + 1, i-1, l2, l2 + (i-1-l1-1), ls);
							rc = build(i+1, r1, l2+(i-l1-1), r2-1, rs);
						我错误的想法:
							1. i是k, 就是inordered的分割点, 但是这里没有inordered, 只有pre和post
					2.  正确的:
							1. i是左子树的最右侧, 而不是什么inordered的分割符
								for(int i = preL; i <= preR; i++){
									leftcnt = build(preL + 1, )
								}
						解释:
							1. 首先i一定是从preL到preR, 一个都不能漏掉
							2.
								int lcnt = dfs(preL + 1, i, preR, postR + i - preL - 1, lin);
								int rcnt = dfs(i + 1, preR, postR + i - preL, postR - 1, rin);
							3. 解释: 其实就是正常的分割, 记住pre[]是要抛弃第一个, post[]是要抛弃最后一个
								    pre[]
										左子树:
											preL + 1, i
												所以当i == preL的时候, preL + 1 > preL, 就可以break
										右子树:
											i+1, preR
									post[]
										左子树:
											postL, postL + (i - preL - 1)
										右子树:
											postL + (i - preL), postR - 1
							4. 对比 ***:
								在以前有inordered: 以下的xx和yy是pre或者post的左右端
									build(il, k - 1, xx, yy)
									build(k + 1, ir, xx, yy)
									你看, 其中k-1和k+1其实是相隔了一个数字k, 因为这是inordered, 使用k做分割
								现在: 根本就没有inordered, 所以不存在所谓的相隔数字k
									int lcnt = build(preL + 1, i, xx, yy);
									int rcnt = build(i + 1, xx, yy);
									你看其中i和i+1中间没有相隔什么数字, 本身就是挨着的, 因为这是preordered
				2. 记得最后string res要去掉末尾的空格:
					res.pop_back();
			1. 笔记
				0.
					1. 这道题吧, 很多需要背诵的细节, 一个细节错了, 答案就错了:
						0. 终止条件:
							if(prel > prer) return 1
								注意一定是严格的大于, 不能是prel >= prer,  因为即便是prel == prer也不能直接return 1, 也要判断是不是pre[prel] == post[postr]
						1. 检查自身:
							if(pre[prel] != post[postr]) return 0
						2. 检查左右儿子: 左右儿子是爆搜确定的, 其中我们的分割点是从prel到prer, 一个都不能少
							1. 左右儿子的返回的数字, 只要一个不满足, 就继续下一个
							2. 如果左右儿子都满足, 就可以生成string
								我之前的疑问: string会不会超出应该的长度
								答案是: 不会的, 因为for loop中, string可能会被覆盖掉, 总之就是string只能被更新成其他string, 但是不会额外增加长度
							3. string的加法:
								如果是到了终止条件, 那么返回的lstr和rstr都是""空的
								所以就可以 in = lstr + to_string(pre[preL]) + ' ' + rstr; 
								这样string in就是第一个string
							4. 注释:
								int cnt = 0;
							    for (int i = preL; i <= preR; i ++ )  // 枚举左子树包含的节点数量
							    {
							        string lstr, rstr;
							        int lcnt = dfs(preL + 1, i, preR, postR + i - preL - 1, lstr);
							        int rcnt = dfs(i + 1, r1, postR + i - preL - 1 + 1, postR - 1, rstr);

							        if(lcnt == 0 || rcnt == 0) continue; 

							        说明左右子树都是合法的, 那么我也是合法的
						            in = lstr + to_string(pre[preL]) + ' ' + rstr; 
						            cnt += lcnt * rcnt; 因为我们是暴力枚举 for (int i = l1; i <= r1; i ++ ) , 所以cnt可能会变成2,3..
						            if (cnt > 1) break;
							    }
						3. 把自己传给父亲
							return cnt

				1.
					1. 
						1. 暴力枚举左侧,右侧
						2. 时间复杂度是阶乘
							1. 假设第一层有11个,最左根节点,爆搜的是右边10个节点,但是有9中分割方式:例如左侧1个,右侧9个;左侧2个,右侧8个...
							2. 搜第二层的时候, 例如左侧1个,右侧9个的: 右侧9个还分成了左侧1个,右侧8个;左侧2个,右侧7个...
							3. 但是我们有很多限制,例如preorder的最左侧应该是postorder的最右侧.

						3. in.pop_back();去掉string的最后一个空格
						4. 我很喜欢那个传入string rin, lin, string& in. 这样就可以把之前的in都传给rin了
						5. in = lin + to_string(pre[l1]) + ' ' + rin; //是因为中序遍历, 左子树 + 根节点 + 右子树
						6. cnt += lcnt * rcnt;还不是很懂, 到时候画个图.
						7. 注意build的里面: 
							左子树中, preorder是不包括第一个点(因为是根节点).
							右子树中, postorder是不包括最后一个点(因为是根节点).

					2.
						1. 这道题并没有用bool
							用int, 即可以当成是bool: lcnt && rcnt, 又可以计算出合法子树的数量
			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					const int N = 40;

					int n;
					int pre[N], post[N];

					int dfs(int l1, int r1, int l2, int r2, string& in)
					{
					    if (l1 > r1) return 1; 空树一定是1个合法方案
					    if (pre[l1] != post[r2]) return 0; 说明这个已经不合法了

					    int cnt = 0;
					    for (int i = l1; i <= r1; i ++ )  // 枚举左子树包含的节点数量
					    {
					        string lin, rin;
					        int lcnt = dfs(l1 + 1, i, l2, l2 + i - l1 - 1, lin);
					        int rcnt = dfs(i + 1, r1, l2 + i - l1 - 1 + 1, r2 - 1, rin);

					        if (lcnt && rcnt) 说明左右子树都是合法的, 那么我也是合法的
					        {
					            in = lin + to_string(pre[l1]) + ' ' + rin; 
					            cnt += lcnt * rcnt; 因为我们是暴力枚举 for (int i = l1; i <= r1; i ++ ) , 所以cnt可能会变成2,3..
					            if (cnt > 1) break;
					        }
					    }
					    return cnt;
					}

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ ) cin >> pre[i];
					    for (int i = 0; i < n; i ++ ) cin >> post[i];

					    string in;    
					    int cnt = dfs(0, n - 1, 0, n - 1, in); 当前节点有多少个合法的二叉树

					    if (cnt > 1) puts("No"); 说明答案不唯一
					    else puts("Yes");

					    in.pop_back();
					    cout << in << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/283585/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					const int N = 40;
					int pre[N], post[N]; 
					int n;

					int build(int l1, int r1, int l2, int r2, string& s){
						if(l1 > r1) return 1;

						if(pre[l1] != post[r2]) return 0;

						int cnt =0;
						for(int i = l1; i <= r1; i++){
						    	string ls, rs;
							int lc = build(l1 + 1, i, l2, l2 + (i-l1-1), ls);
							int rc = build(i+1, r1, l2+(i-l1), r2-1, rs);

					        // cout << lc << " " << rc << endl;
							if(lc == 0 || rc == 0) continue;

							s = ls + to_string(pre[l1]) + " " + rs;
					// 		cout << "hi" <<endl;
							cnt += lc * rc;
							if(cnt > 1) break;
						}
						return cnt;
					}

					int main(){
						cin >> n;
						for(int i = 0; i < n; i++) cin >> pre[i];
						for(int i = 0; i < n; i++) cin >> post[i];

						string res;
						int cnt = build(0, n-1, 0, n-1, res);

						if(cnt > 1) puts("No");
						else puts("Yes");
						res.pop_back();
						cout << res << endl;
						return 0;

					}
				r2. 很顺:
					#include <iostream>

					using namespace std;

					const int N = 40;
					int pre[N], post[N];
					int n;

					int build(int preL, int preR, int postL, int postR, string& res){
						int cnt = 0;
						if(preL > preR) return 1;

						if(pre[preL] != post[postR]) return 0;

						for(int i = preL; i <= preR; i++){
							string lstr, rstr;
							int lcnt = build(preL + 1, i, postL, postL + ( i - preL - 1), lstr);
							int rcnt = build(i + 1, preR, postL + (i - preL), postR - 1, rstr);

							if(!lcnt || !rcnt) continue;
							res = lstr + to_string(pre[preL]) + " " + rstr;
							cnt += lcnt * rcnt;
							if(cnt > 1) break;
						}
						return cnt;
					}

					int main(){
						cin >> n;
						for(int i = 0; i < n; i++) cin >> pre[i];
						for(int i = 0; i < n; i++) cin >> post[i];

						string res;
						int cnt = build(0, n - 1, 0, n - 1, res);

						if(cnt > 1) puts("No");
						else puts("Yes");

						res.pop_back();
						cout << res << endl;
						return 0;
					}
				r3. 顺利
					#include <iostream>

					using namespace std;

					const int N = 40;
					int pre[N], post[N], n;

					int build(int preL, int preR, int postL, int postR, string& res){
					    int cnt = 0;
					    if(preL > preR) return 1;
					    
					    if(pre[preL] != post[postR]) return 0;
					    
					    for(int i = preL; i <= preR; i++){
					        string lstr, rstr;
					        int lcnt, rcnt;
					        lcnt = build(preL + 1, i, postL, postL + (i - preL - 1), lstr);
					        rcnt = build(i + 1, preR, postL + (i- preL), postR - 1 , rstr);
					        
					        if(!lcnt || !rcnt) continue;
					        res = lstr + to_string(pre[preL]) + " " + rstr;
					        cnt += lcnt * rcnt;
					        if(cnt > 1) break;
					    }
					    
					    return cnt;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> pre[i];
					    for(int i = 0; i < n; i++) cin >> post[i];
					    
					    string res;
					    int cnt;
					    cnt = build(0, n - 1, 0, n - 1, res);
					    
					    if(cnt == 1) puts("Yes");
					    else puts("No");
					    
					    res.pop_back();
					    cout << res << endl;
					    return 0;
					}
				r4.
					#include <iostream>

					using namespace std;

					const int N = 40;
					int pre[N], post[N], n;

					int build(int preL, int preR, int postL, int postR, string& res){
					    int cnt = 0;
					    if(preL > preR) return 1;
					    if(pre[preL] != post[postR]) return 0;
					    
					    for(int i = preL; i <= preR ; i++){
					        string lstr, rstr;
					        int lcnt, rcnt;
					        lcnt = build(preL + 1, i, postL, postL + (i-preL -1), lstr);
					        rcnt = build(i + 1, preR, postL + (i-preL), postR - 1, rstr);
					        
					        if(!lcnt || !rcnt) continue;
					        res = lstr + to_string(pre[preL]) + " " + rstr;
					        cnt += lcnt * rcnt;
					        if(cnt > 1) break;
					    }
					    return cnt;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++) cin >> pre[i];
					    for(int i = 0; i < n; i++) cin >> post[i];
					    
					    string res;
					    int cnt;
					    cnt = build(0, n - 1, 0, n - 1, res);
					    
					    if(cnt == 1) puts("Yes");
					    else puts("No");
					    
					    res.pop_back();
					    cout << res << endl;
					    return 0;
					}
				r5.			

		56. 1620. Z 字形遍历二叉树	1127
			0. bug
			1. 笔记
				1. 
					1. 重构二叉树, 中序中找root是直接从左到右遍历, 复杂度ON, 因为这道题的输入小, 只有30所以没有必要优化
					2. z字形,就是将depth==奇数的(根节点的depth==0)层翻转
					3. 回忆: build(il, k - 1, pl, ?); 
						1. 因为? - pl = (k-1)-il
						2. 所以?就是pl 加上k-1和il的差值: pl + ( k - 1 - il )

					4. 喜欢这一段:
						void bfs(int root)
						{
						    int hh = 0, tt = 0;
						    q[0] = root;

						    int step = 0; 
						    while (hh <= tt)
						    {
						        int head = hh, tail = tt; head和tail的含义是,树的某一整个层在q[]中的位置
						        举例: 第一层是根节点, 所以head == tail == 0;
						        第二层假设是2个节点,所以head == 1, tail == 2;
						        第三层是4个节点, head == 3, tail = 6.
						        while (hh <= tail) //tail是固定的,tt和hh是动态的.所以hh只能遍历到当前层结束
						        {
						            int t = q[hh ++ ];
						            if (l.count(t)) q[ ++ tt] = l[t];
						            if (r.count(t)) q[ ++ tt] = r[t];
						        }

						        if ( ++ step % 2) reverse(q + head, q + tail + 1);
						        如果是奇数,就翻转这一层.
						        例如根节点这一层, ++step是1, 所以if(1) reverse(根节点);
						        例如第二层, ++step是2, 所以不翻转
						        第三层, ++step是3, if(1) reverse(3, 6+1); //翻转第三层的所有元素.
						    }
						}
			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>

					using namespace std;

					using namespace std;

					const int N = 40;

					int n;
					unordered_map<int, int> l, r, pos;
					int in[N], post[N];
					int q[N];

					int build(int il, int ir, int pl, int pr)
					{
					    int root = post[pr];
					    int k = pos[root];

					    if (il < k) l[root] = build(il, k - 1, pl, pl + k - 1 - il);
					    if (k < ir) r[root] = build(k + 1, ir, pl + k - 1 - il + 1, pr - 1);

					    return root;
					}

					void bfs(int root)
					{
					    int hh = 0, tt = 0;
					    q[0] = root;

					    int step = 0;
					    while (hh <= tt)
					    {
					        int head = hh, tail = tt;
					        while (hh <= tail)
					        {
					            int t = q[hh ++ ];
					            if (l.count(t)) q[ ++ tt] = l[t];
					            if (r.count(t)) q[ ++ tt] = r[t];
					        }

					        if ( ++ step % 2) reverse(q + head, q + tail + 1);
					    }
					}

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ )
					    {
					        cin >> in[i];
					        pos[in[i]] = i;
					    }
					    for (int i = 0; i < n; i ++ ) cin >> post[i];

					    int root = build(0, n - 1, 0, n - 1);

					    bfs(root);

					    cout << q[0];
					    for (int i = 1; i < n; i ++ ) cout << ' ' << q[i];
					    cout << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/283592/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>
					#include <cstring>

					using namespace std;

					const int N = 40;
					int in[N], post[N];
					unordered_map<int, int> l, r, pos;
					int q[N];
					int n;

					int build(int il, int ir, int pl, int pr){
						int root = post[pr];
						int k = pos[root];
						if(il < k) l[root] = build(il, k-1, pl, pl + (k-1-il));
						if(k < ir) r[root] = build(k+1, ir, pl + (k-il), pr-1);
						return root;
					}


					void bfs(int u){
						q[0] = u;
						int hh, tt;
						hh = tt = 0;
						int layer = 0;

						while(hh <= tt){
							int head = hh;
							int tail = tt;
							while(hh <= tail){
								int t = q[hh++];
								if(l.count(t)) q[++tt] = l[t];
								if(r.count(t)) q[++tt] = r[t];
							}
							if(++layer % 2) reverse(q + head, q + tail + 1);
						}

						cout << q[0];
						for(int i = 1; i < n; i++) cout << " " << q[i];
						cout << endl;
					}

					int main(){
						cin >> n;

						for(int i = 0; i < n; i++){
							cin >> in[i];
							pos[in[i]] = i;
						}
						for(int i = 0; i < n; i++) cin >> post[i];

						int root = build(0, n-1, 0, n-1);

						bfs(root);
						return 0;
					}
				r2.
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 40;
					int in[N], post[N], q[N];
					unordered_map<int, int> l, r, pos;
					int n;

					int build(int il, int ir, int pl, int pr){
					    int root = post[pr];
					    int k = pos[root];
					    if(il < k) l[root] = build(il, k-1, pl, pl + (k-1-il));
					    if(k < ir) r[root] = build(k+1, ir, pl+(k-il), pr-1);
					    return root;
					}

					void bfs(int u){
					    q[0] = u;
					    int hh, tt;
					    hh = tt = 0;
					    
					    int layer = 0;
					    while(hh <= tt){
					        int head = hh, tail = tt;
					        while(hh <= tail){
					            int t = q[hh++];
					            if(l.count(t)) q[++tt] = l[t];
					            if(r.count(t)) q[++tt] = r[t];
					        }
					        if(++layer % 2) reverse(q + head, q + tail + 1);
					    }
					    
					    cout << q[0];
					    for(int i = 1; i < hh; i++) cout << " " << q[i];
					    cout << endl;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        cin >> in[i];
					        pos[in[i]] = i;
					    }
					    for(int i = 0; i < n; i++) cin >> post[i];
					    
					    int root = build(0, n-1, 0, n-1);
					    bfs(root);
					    return 0;
					}
				r3.
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 40;
					int in[N], post[N], q[N];
					unordered_map<int, int> l, r, pos;
					int n;

					int build(int il, int ir, int pl, int pr){
					    int root = post[pr];
					    int k = pos[root];
					    if(il < k) l[root] = build(il, k-1, pl, pl+(k-1-il));
					    if(k < ir) r[root] = build(k+1, ir, pl + (k-il), pr-1);
					    return root;
					}

					void bfs(int u){
					    q[0] = u;
					    int hh, tt;
					    hh = tt = 0;
					    int layer = 0;
					    while(hh <= tt){
					        int head = hh, tail = tt;
					        while(hh <= tail){
					            int t = q[hh++];
					            if(l.count(t)) q[++tt] = l[t];
					            if(r.count(t)) q[++tt] = r[t];
					        }
					        if(++layer % 2) reverse(q + head, q + tail + 1);
					    }
					    cout << q[0];
					    for(int i = 1; i < hh; i++) cout << " " << q[i];
					    cout << endl;
					}
					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        cin >> in[i];
					        pos[in[i]] = i;
					    }
					    for(int i = 0; i < n; i++){
					        cin >> post[i];
					    }
					    
					    int root = build(0, n-1, 0, n-1);
					    bfs(root);
					    return 0;
					}
				r4.
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 40;
					int in[N], post[N], q[N];
					unordered_map<int, int> l, r, pos;
					int n;

					int build(int il, int ir, int pl, int pr){
					    int root = post[pr];
					    int k = pos[root];
					    if(il < k) l[root] = build(il, k-1, pl, pl+(k-1-il));
					    if(k < ir) r[root] = build(k+1, ir, pl+(k-il), pr-1);
					    return root;
					}

					void bfs(int u){
					    q[0] = u;
					    int hh, tt;
					    hh = tt = 0;
					    
					    int layer = 0;
					    while(hh <= tt){
					        int head = hh, tail = tt;
					        while(hh <= tail){
					            int t = q[hh++];
					            if(l.count(t)) q[++tt] = l[t];
					            if(r.count(t)) q[++tt] = r[t];
					        }
					        if(++layer % 2) reverse(q + head, q + tail + 1);
					    }
					    cout << q[0];
					    for(int i = 1;i < hh; i++) cout << " " << q[i];
					    cout << endl;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        cin >> in[i];
					        pos[in[i]] = i;
					    }
					    for(int i = 0; i < n; i++) cin >> post[i];
					    
					    int root = build(0, n-1, 0, n-1);
					    bfs(root);
					    return 0;
					}
				r5.

	13. 2020年10月21日07:26:54

		57. 1631. 后序遍历	1138
			0. bug
			1. 笔记
				1. 
					1. 题目之前都写过, 但是这里的输入是5万, 所以我们需要用哈希表Unordered_map来存储值和ind
					2. 我喜欢的地方:
						void build(int il, int ir, int pl, int pr)
						{
						    int root = pre[pl];
						    int k = pos[root];

						    if (il < k) build(il, k - 1, pl + 1, pl + 1 + k - 1 - il);
						    if (k < ir) build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr);

						    if (!post) post = root; 我喜欢这一句
							    这一句只会执行一次, 也就是说, 第一次执行这一句的时候,就已经是tree最左下角的了
							    	这时的root就是最左下角的, 也就应该是il == k的点
								    题目要求的是后序遍历的第一个节点
								    老师说了,写完了上面两个build()说明是遍历完所有的左子树和右子树了
								    现在是看根节点了.其实这个根节点就是后序遍历的第一个节点,也就是树中最左边的节点
							    不过要注意:
							    	进入if(!post)执行post = root; 的时候,我发现,这个build()中的那两个build()是不执行的
							    	也就是,这个build()里面 il == k, k == ir, 所以if(il < k)和if(k < ir)都是false, 那两个build()不执行
							    	此时也就是树中最左边的点
						}
					3. 如果不优化,就会tle
						例如, 把int k = pos[root]改成下面的:
						int k;
						for(int i = il; i <= ir; i++){
							if(in[i] == root)
							{
								k = i;
								break;
							}
						}
			2. 注释
				1. y
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					const int N = 50010;

					int n;
					int pre[N], in[N];
					unordered_map<int, int> pos;
					int post;

					void build(int il, int ir, int pl, int pr)
					{
					    int root = pre[pl];
					    int k = pos[root];

					    if (il < k) build(il, k - 1, pl + 1, pl + 1 + k - 1 - il);
					    if (k < ir) build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr);

					    if (!post) post = root;
					}

					int main()
					{
					    cin >> n;

					    for (int i = 0; i < n; i ++ ) cin >> pre[i];
					    for (int i = 0; i < n; i ++ )
					    {
					        cin >> in[i];
					        pos[in[i]] = i;
					    }

					    build(0, n - 1, 0, n - 1);

					    cout << post << endl;
					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/283601/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					const int N = 50010;
					int in[N], pre[N];
					int post;
					int n;
					unordered_map<int, int> pos;

					void build(int il, int ir, int pl, int pr){
						int root = pre[pl];
						int k = pos[root];
						if(il < k) build(il, k-1, pl+1, pl+1+(k-1-il));
						if(k < ir) build(k+1, ir, pl+1+(k-il), pr);
						if(!post) post = root;
					}

					int main(){
						cin >> n;
						for(int i = 0; i < n; i++) cin >> pre[i];
						for(int i = 0; i < n; i++){
							cin >> in[i];
							pos[in[i]] = i;
						}

						build(0, n-1, 0, n-1);
						cout << post << endl;
						return 0;
					}
				r2.
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					const int N = 50010;
					int in[N], pre[N];
					unordered_map<int, int> pos;
					int post, n;

					void build(int il, int ir, int pl, int pr){
					    int root = pre[pl];
					    int k = pos[root];
					    if(il < k) build(il, k-1, pl+1, pl+1+(k-1-il));
					    if(k < ir) build(k+1, ir, pl+1+(k-il), pr);
					    if(!post) post = root;
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++)cin >> pre[i];
					    for(int i = 0; i < n; i++){
					        cin >> in[i];
					        pos[in[i]] = i;
					    }
					    
					    build(0, n-1, 0, n-1);
					    cout << post << endl;
					    return 0;
					}
				r3.
				r4.
				r5.

		58. 1552. AVL树的根	1160
			0. bug, 尤其警惕第4个bug, 总是会错在这里
				1. 
					正确的:
						if(v < w[u]){
							insert(l[u], v);
							if(gb(u) >= 2){
								if(gb(l[u]) == 1) R(u);
								else L(l[u]), R(u);
							}
						}
						else{
							insert(r[u], v);
							if(gb(u) <= -2){
								if(gb(r[u]) == -1) L(u); 
								else R(r[u]), L(u);
							}
						}
					错误的: comment部分
						if(v < w[u]){
							insert(l[u], v);
							if(gb(u) >= 2){
								if(gb(l[u]) == 1) R(u);
								else L(l[u]), R(u);
							}
							// else if(gb(u) <= -2){
							// 	if(gb(r[u]) == -1) L(u); 
							// 	else R(r[u]), L(u);
							// }
						}
						else{
							insert(r[u], v);
							if(gb(u) <= -2){
								if(gb(r[u]) == -1) L(u); 
								else R(r[u]), L(u);
							}
							// else if(gb(u) >= 2){
							// 	if(gb(l[u]) == 1) R(u);
							// 	else L(l[u]), R(u);
							// }
						}
				2.
					insert(int& u, int v), L(int& u), R(int& u)
						这三个都要传引用, 因为是结构体内部的变化
				3. update()的时机:
					1. 在L(), R()里面, 都要update()
					2. 在insert()里面, 3种情况都要update()
						1. 不简写: 学要写3次update();
							1. if(!u){...; update()}
							2. if(v < w[u]){...; update()}
							3. else {...; update()}
						2. 简写: 只需要写一次update()
							if(!u){}
							else if(v < w[u]){}
							else{}
							update();
				4. 需要重视的bug, 我已经犯了好多次了. 一个奇奇怪怪的bug: 竟然没有报错, 还我找半天
					错误的: if(get_balance(r[u] == -1))
					应该是: if(get_balance(r[u]) == -1)
				5. 我nd是怎么了? 锈了?
					约定好了: get_balance()是左侧-右侧,所以,如果是insert(l[u],v)那么就是判断是否是 >= 2
					我的错误: insert(l[u],v)判断成了是否是 <= -2
			1. 笔记
				0. AVL的插入很简单: 总之, 最后的目标都是变成 屋顶 /\
					1. 向l[u]插入, 不正常的两种情况:
						1. / 一路左撇
							解决: 直接R(u), 变成屋顶/\
						2. < 先左撇儿子, 后右撇
							解决: 先L(l[u]), 变成/, 后R(u), 变成屋顶/\
					2. 向r[u]插入, 不正常的两种情况:
						1. \ 一路右撇
							解决: 直接L(u), 变成屋顶/\
						2. > 先右撇儿子, 后左撇
							解决: 先R(r[u]), 变成\, 后L(u), 变成屋顶/\
					3. 关键背下来: 
						void R(int& u) 
						{
						    int p = l[u]; 
						    l[u] = r[p], r[p] = u; 
						    update(u), update(p); 先更新底部t, 后更新顶部p
						    u = p;
						}

						void L(int& u) 
						{
						    int p = r[u]; 
						    r[u] = l[p], l[p] = u; 
						    update(u), update(p);
						    u = p;
						}

				1. 
					1. avl 和 红黑树
						avl需要学会判别,插入(get_balance, udpate, R, L, insert).
						红黑树学会判别,(插入需要100多行,所以不会考)

					2. 
					void update(int u) //这个是默认在u的左右节点更新完的基础上调用的
					{
					    h[u] = max(h[l[u]], h[r[u]]) + 1;
					}


						x 					  y
					   / \					/  \
					  y   a			       c    x
					 /\      			       / \ 
					c  b      变成             b  a

					void R(int& u) 右旋u, 注意要传引用
					{
					    int p = l[u]; 找到u的左子p
					    l[u] = r[p], r[p] = u; 最后变成: p的右子 -成为->  u的左子, p没有右子了, u -成为-> p的右子 
					    update(u), update(p); 注意现在u在下面,所以先更新u的高度,才能更新p的高度
					    u = p; 最后u的位置由p代替
					}

						x 					 y
					   / \					/ \
					  a   y 			   x    c
					     / \			  / \  
					    b    c  变成      a  b

					void L(int& u) 
					{
					    int p = r[u]; 找到u的右子p
					    r[u] = l[p], l[p] = u; 最后变成: p的左子 -成为->  u的右子, p没有左子了, u -成为-> p的左子 
					    update(u), update(p);
					    u = p;
					}

					int get_balance(int u) 注意这里没有abs(),而是判断左边比右边高多少
					{
					    return h[l[u]] - h[r[u]];
					}

					void insert(int& u, int w)
					{
					    if (!u) u = ++ idx, v[u] = w;
					    else if (w < v[u])
					    {
					        insert(l[u], w);
					        if (get_balance(u) == 2) 左边长, 说明有两种情况: /   或者   /
					        {											  /           \
					            if (get_balance(l[u]) == 1) R(u); 左边长, 说明是第1种情况
					            else L(l[u]), R(u); 右边长, 说明是第2种情况, 就是把下面的 \ 向左侧旋转, 变成? , 然后就是第一种情况了 
					        }
					    }
					    else
					    {
					        insert(r[u], w);
					        if (get_balance(u) == -2)左边长, 说明有两种情况: \   或者   \
					        {											  	\         /
					            if (get_balance(r[u]) == -1) L(u); 右边长, 说明是第1种情况
					            else R(r[u]), L(u); 左边长, 说明是第2种情况, 就是把下面的/ 向右侧旋转, 变成\, 然后就是第一种情况了 
					        }
					    }

					    update(u);
					}

			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 30;

					int l[N], r[N], v[N], h[N], idx;

					void update(int u)
					{
					    h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					void R(int& u)
					{
					    int p = l[u];
					    l[u] = r[p], r[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void L(int& u)
					{
					    int p = r[u];
					    r[u] = l[p], l[p] = u;
					    update(u), update(p);
					    u = p;
					}

					int get_balance(int u)
					{
					    return h[l[u]] - h[r[u]];
					}

					void insert(int& u, int w)
					{
					    if (!u) u = ++ idx, v[u] = w;
					    else if (w < v[u])
					    {
					        insert(l[u], w);
					        if (get_balance(u) == 2)
					        {
					            if (get_balance(l[u]) == 1) R(u);
					            else L(l[u]), R(u);
					        }
					    }
					    else
					    {
					        insert(r[u], w);
					        if (get_balance(u) == -2)
					        {
					            if (get_balance(r[u]) == -1) L(u);
					            else R(r[u]), L(u);
					        }
					    }

					    update(u);
					}

					int main()
					{
					    int n, root = 0;
					    cin >> n;

					    while (n -- )
					    {
					        int w;
					        cin >> w;
					        insert(root, w);
					    }

					    cout << v[root] << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/283632/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					const int N = 30;
					int l[N], r[N], h[N], w[N], ind;
					int n;

					void update(int u){
						h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					int gb(int u){
						return h[l[u]] - h[r[u]];
					}

					void R(int& u){
						int p = l[u];
						l[u] = r[p], r[p] = u; 
						update(u), update(p);
						u = p;
					}

					void L(int& u){
						int p = r[u];
						r[u] = l[p], l[p] = u;
						update(u), update(p);
						u = p; 
					}

					void insert(int& u, int v){
					    
						if(!u){
							u = ++ind;
							w[u] = v;
							update(u);
							return;
						}

						if(v < w[u]){
							insert(l[u], v);
							if(gb(u) >= 2){
								if(gb(l[u]) == 1) R(u);
								else L(l[u]), R(u);
							}
							update(u);
						}
						else{
							insert(r[u], v);
							if(gb(u) <= -2){
								if(gb(r[u]) == -1) L(u); 
								else R(r[u]), L(u);
							}
							update(u);
						}
						
					}

					int main(){
						cin >> n;

						int root = 0;
						for(int i = 0; i < n; i++)
						{
							int v;
							cin >> v;
							insert(root, v);
						}
						cout << w[root] << endl;
					}
				r2.
					#include <iostream>

					using namespace std;

					const int N = 30;
					int l[N], r[N], w[N], h[N], ind;
					int n;

					int get_balance(int u){
						return h[l[u]] - h[r[u]];
					}

					void update(int u){
						h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					void R(int& u){
						int p = l[u];
						l[u] = r[p], r[p] = u;
						update(u), update(p);
						u = p;
					}

					void L(int& u){
						int p = r[u];
						r[u] = l[p], l[p] = u;
						update(u), update(p);
						u = p;
					}

					void insert(int& u, int v){
						if(!u){
							u = ++ind;
							w[u] = v;
						}else if(v < w[u]){
							insert(l[u], v);
							if(get_balance(u) >= 2){
								if(get_balance(l[u]) >= 1) R(u);
								else L(l[u]), R(u);
							}
						}else{
							insert(r[u], v);
							if(get_balance(u) <= -2){
								if(get_balance(r[u]) <= -1) L(u);
								else R(r[u]), L(u);
							}
						}
						update(u);
					}

					int main(){
						cin >> n;
						int v;
						int root = 0;
						for(int i = 0; i < n; i++){
							cin >> v;
							insert(root, v);
						}
						cout << w[root] << endl;
					}
				r3.
					#include <iostream>
					using namespace std;

					const int N = 40;
					int l[N], r[N], w[N], ind;
					int h[N];
					int n;

					int gb(int u){
					    return h[l[u]] - h[r[u]];
					}

					void update(int u){
					    h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					void R(int& u){
					    int p = l[u];
					    l[u] = r[p], r[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void L(int& u){
					    int p = r[u];
					    r[u] =l[p], l[p] = u;
					    update(u), update(p);
					    u = p;
					}


					void insert(int& u, int v){
					    if(!u) u = ++ind, w[u] = v;
					    else if(v < w[u]){
					        insert(l[u], v);
					        if(gb(u) >= 2){
					            if(gb(l[u]) == 1) R(u);
					            else L(l[u]), R(u);
					        }
					    }else{
					        insert(r[u], v);
					        if(gb(u) <= -2){
					            if(gb(r[u]) == -1) L(u);
					            else R(r[u]), L(u);
					        }
					    }
					    update(u);
					}

					int main(){
					    cin >> n;
					    int v;
					    int root = 0;
					    for(int i = 0; i< n; i++){
					        cin >> v;
					        insert(root, v);
					    }
					    cout << w[root] << endl;
					    
					}
				r4.
					#include <iostream>

					using namespace std;

					const int N = 40;
					int l[N], r[N], w[N], ind;
					int h[N], n;

					void update(int u){
					    h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					int gb(int u){
					    return h[l[u]] - h[r[u]];
					}

					void R(int& u){
					    int p = l[u];
					    l[u] = r[p], r[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void L(int& u){
					    int p = r[u];
					    r[u] = l[p], l[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void insert(int& u, int v){
					    if(!u){
					        u = ++ind;
					        w[u] = v;
					    }else if(v < w[u]){
					        insert(l[u], v);
					        if(gb(u) >= 2){
					            if(gb(l[u]) == 1) R(u);
					            else L(l[u]), R(u);
					        }
					    }else{
					        insert(r[u], v);
					        if(gb(u) <= -2){
					            if(gb(r[u]) == -1) L(u);
					            else R(r[u]), L(u);
					        }
					    }
					    update(u);
					}

					int main(){
					    cin >> n;
					    int root = 0;
					    int v;
					    for(int i = 0; i < n;i ++){
					        cin >> v;
					        insert(root, v);
					    }
					    cout << w[root] << endl;
					    return 0;
					}
				r5.
					#include <iostream>
					#include <algorithm>
					using namespace std;

					const int N = 40;
					int l[N], r[N], w[N], ind;
					int h[N], n;

					void update(int u){
					    h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					int gb(int u){
					    return h[l[u]] - h[r[u]];
					}

					void R(int& u){
					    int p = l[u];
					    l[u] = r[p], r[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void L(int& u){
					    int p = r[u];
					    r[u] = l[p], l[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void insert(int& u, int v){
					    if(!u){
					        u = ++ind;
					        w[u] = v;
					    }else if(v < w[u]){
					        insert(l[u], v);
					        if(gb(u) >= 2){
					            if(gb(l[u]) == 1) R(u);// cout << "r" << endl;
					            else L(l[u]), R(u);// cout << "lr" << endl;
					        }
					    }else{
					        insert(r[u], v);
					        // cout << v << " " << gb(u) << endl;
					        if(gb(u) <= -2){
					            if(gb(r[u]) == -1) L(u);// cout << "l" << endl;
					            else R(r[u]), L(u); //cout << "rl" << endl;
					        }
					    }
					    update(u);
					}
					int main(){
					    cin >> n;
					    int v;
					    int root = 0;
					    for(int i = 0; i < n; i++){
					        cin >> v;
					        insert(root, v);
					    }
					    cout << w[root] << endl;
					   
					    return 0;
					}
				r6.
					#include <iostream>
					using namespace std;

					const int N = 30;
					int l[N], r[N], w[N], ind;
					int n, h[N];

					void update(int u){
					    h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					int gb(int u){
					    return h[l[u]] - h[r[u]];
					}

					void R(int& u){
					    int p = l[u];
					    l[u] = r[p], r[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void L(int& u){
					    int p = r[u];
					    r[u] = l[p], l[p] = u;
					    update(u), update(p);
					    u = p;
					}


					void insert(int& u, int v){
					    if(!u){
					        u = ++ind;
					        w[u] = v;
					    }
					    else if(v < w[u]){
					        insert(l[u], v);
					        if(gb(u) >= 2){
					            if(gb(l[u]) == 1) R(u);
					            else L(l[u]), R(u);
					        }
					    }else{
					        insert(r[u], v);
					        if(gb(u) == -2){
					            if(gb(r[u]) == -1) L(u);
					            else R(r[u]), L(u);
					        }
					    }
					    update(u);
					}

					int main(){
					    cin >> n;
					    int v, root = 0;
					    for(int i = 0; i < n; i++){
					        cin >> v;
					        insert(root, v);
					    }
					    cout << w[root] << endl;
					    return 0;
					}

	14. 2020年11月2日14:08:20

		59. 1616. 判断完全 AVL树 	1123
			0. bug
				1. 果然很就不写代码就会出问题:
					正确:
						if(!u) u = ++ ind, w[u] = v;
					错误:	
						if(!u) u = ind ++, w[u] = v;
				2. pos也就是记录个数的.
					正确
						pos[root] = 1; 根节点对应的ind是1
					错误:
						pos[0] = 1; 根节点对应的ind是1

			1. 笔记
				1. 
					1. 构建avl
					2. 假设这个avl是完全二叉树, 记录每个节点在完全二叉树中的位置
						例1, a节点有bc两个子节点, 我们就分别放入了ind = 1,2,3的位置, b只有右节点d, 放入了ind == 2*2+1 == 5 的位置
						c有两个子节点ef, 分别放入了ind == 3*2 和 3*2+1 即 == 6,7的位置

						例2, a节点有bc两个子节点, 我们就分别放入了ind = 1,2,3的位置, b有左右节点de, 放入了ind == 4,5 的位置
						c只有右节点f, 分别放入了ind ==7的位置

						例2, a节点有bc两个子节点, 我们就分别放入了ind = 1,2,3的位置, b有左右节点de, 放入了ind == 4,5 的位置
						c只有左节点f, 分别放入了ind ==6的位置

					3. 记录ind最大值, 判断这个ind和n的关系
						例1,2: ind的最大值是7, 但是我们只有abcdef共6个节点,所以说明前面有空位,所以不是完全二叉树
						例3: ind的最大值是6 == abcdef共6个节点,是完全二叉树

					4.
						int q[N]; q是bfs用到的队列
						int pos[N];	pos是记录每个节点(值)的对应的ind
						例如某个节点的值是99,它的ind是2,即pos[99]=2. 如果这个节点的左子的值是88, 它的ind就是2*2, 即pos[88] = 4
						因为题目中说了所有的值都不同,所以可以用pos数组存.
						bool bfs(int root)
						{
						    int hh = 0, tt = 0;
						    q[0] = root;
						    pos[root] = 1; 根节点对应的ind是1

						    bool res = true;
						    while (hh <= tt)
						    {
						        int t = q[hh ++ ];
						        if (pos[t] > n) res = false; 这就是我们上面说的,只要一个超出了n,就说明前面有空位,说明不是完全二叉树

						        if (l[t]) q[ ++ tt] = l[t], pos[l[t]] = pos[t] * 2; 插入左子, t的左子的ind是t的ind*2
						        if (r[t]) q[ ++ tt] = r[t], pos[r[t]] = pos[t] * 2 + 1; 插入右子, t的右子的ind是t的ind*2+1
						    }

						    return res;
						}


			2. 注释
				1. y
					#include <iostream>
					using namespace std;

					const int N = 30;

					int n;
					int l[N], r[N], v[N], h[N], idx;
					int q[N], pos[N];

					void update(int u)
					{
					    h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					void R(int& u)
					{
					    int p = l[u];
					    l[u] = r[p], r[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void L(int& u)
					{
					    int p = r[u];
					    r[u] = l[p], l[p] = u;
					    update(u), update(p);
					    u = p;
					}

					int get_balance(int u)
					{
					    return h[l[u]] - h[r[u]];
					}

					void insert(int& u, int w)
					{
					    if (!u) u = ++ idx, v[u] = w;
					    else if (w < v[u])
					    {
					        insert(l[u], w);
					        if (get_balance(u) == 2)
					        {
					            if (get_balance(l[u]) == 1) R(u);
					            else L(l[u]), R(u);
					        }
					    }
					    else
					    {
					        insert(r[u], w);
					        if (get_balance(u) == -2)
					        {
					            if (get_balance(r[u]) == -1) L(u);
					            else R(r[u]), L(u);
					        }
					    }

					    update(u);
					}

					bool bfs(int root)
					{
					    int hh = 0, tt = 0;
					    q[0] = root;
					    pos[root] = 1;

					    bool res = true;
					    while (hh <= tt)
					    {
					        int t = q[hh ++ ];
					        if (pos[t] > n) res = false;

					        if (l[t]) q[ ++ tt] = l[t], pos[l[t]] = pos[t] * 2;
					        if (r[t]) q[ ++ tt] = r[t], pos[r[t]] = pos[t] * 2 + 1;
					    }

					    return res;
					}

					int main()
					{
					    int root = 0;
					    cin >> n;
					    for (int i = 0; i < n; i ++ )
					    {
					        int w;
					        cin >> w;
					        insert(root, w);
					    }

					    bool res = bfs(root);

					    cout << v[q[0]];
					    for (int i = 1; i < n; i ++ ) cout << ' ' << v[q[i]];
					    cout << endl;

					    if (res) puts("YES");
					    else puts("NO");

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/283649/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					const int N = 30;
					int l[N], r[N], h[N], w[N], ind;
					int q[N], pos[N];
					int n;

					void update(int u){
						h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					int gb(int u){
						return h[l[u]] - h[r[u]];
					}

					void R(int& u){
						int p = l[u];
						l[u] = r[p], r[p] = u;
						update(u), update(p);
						u = p; 
					}

					void L(int& u){
						int p = r[u];
						r[u] = l[p], l[p] = u;
						update(u), update(p);
						u = p;
					}

					void insert(int& u, int v){
						if(!u){
							u = ++ ind;
							w[u] = v;
							update(u);
						}
						else if(v < w[u]){
							insert(l[u], v);
							if(gb(u) >= 2){
								if(gb(l[u]) >= 1) R(u);
								else L(l[u]), R(u);
							}
							update(u);
						}else{
							insert(r[u], v);
							if(gb(u) <= -2){
								if(gb(r[u]) <= -1) L(u);
								else R(r[u]), L(u);
							}
							update(u);
						}
					}

					bool bfs(int root){
						int hh, tt;
						hh = tt = 0;
						q[0] = root;
					// 	cout << "root " << root << endl;
						pos[root] = 1;
						bool res = true;
						while(hh <= tt){
							int t = q[hh++];
					// 		cout << pos[t] << " hi" << endl;
							if(pos[t] > n) res = false;
							if(l[t]) q[++tt] = l[t], pos[l[t]] = pos[t] * 2; 
							if(r[t]) q[++tt] = r[t], pos[r[t]] = pos[t] * 2 + 1;
						}

						cout << w[q[0]];
						for(int i = 1; i < hh; i++){
							cout << " " << w[q[i]];
						}
						cout << endl;
						return res;
					}

					int main(){
						
						cin >> n;

						int root = 0;
						for(int i = 0; i < n; i++){
							int v;
							cin >> v;
							insert(root, v);
						}	

						bool res = bfs(root);
						if(res) cout << "YES" << endl;
						else cout << "NO" << endl;
						return 0;

					}
				r2.
					#include <iostream>

					using namespace std;

					const int N = 30;
					int l[N], r[N], h[N], w[N], ind;
					int q[N], pos[N];
					int n;
					int root;

					void update(int u){
						h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					int gb(int u){
						return h[l[u]] - h[r[u]];
					}

					void R(int& u){
						int p = l[u];
						l[u] = r[p], r[p] = u;
						update(u), update(p);
						u = p;
					}

					void L(int& u){
						int p = r[u];
						r[u] = l[p], l[p] = u;
						update(u), update(p);
						u = p;
					}

					void insert(int& u, int v){
						if(!u){
							u = ++ind;
							w[u] = v;
						}else if(v < w[u]){
							insert(l[u], v);
							if(gb(u) == 2){
								if(gb(l[u]) == 1) R(u);
								else L(l[u]), R(u);
							}
						}else{
							insert(r[u], v);
							if(gb(u) == -2){
								if(gb(r[u]) == -1) L(u);
								else R(r[u]), L(u);
							}
						}
						update(u);
					}

					bool bfs(int root){
						int hh, tt;
						hh = tt = 0;
						q[0] = root;
						bool res = true;
						pos[root] = 1;
						while(hh <= tt){
							int t = q[hh++];
							if(pos[t] > n) res = false;
							if(l[t]) q[++tt] = l[t], pos[l[t]] = pos[t] * 2;
							if(r[t]) q[++tt] = r[t], pos[r[t]] = pos[t] * 2 + 1;
						}
						cout << w[q[0]];
						for(int i = 1; i < hh; i++){
							cout << " " << w[q[i]];
						}
						cout << endl;
						return res;
					}

					int main(){
						cin >> n;
						for(int i = 0; i < n; i++){
							int v;
							cin >> v;
							insert(root, v);
						}

						bool res = bfs(root);
						if(res) cout << "YES" << endl;
						else cout << "NO" << endl;

					}
				r3. todo 有bug, 且没找到bug
					#include <iostream>

					using namespace std;

					const int N = 30;
					int l[N], r[N], h[N], w[N], ind;
					int q[N], pos[N];
					int n, root;

					void update(int u){
					    h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					int gb(int u){
					    return h[l[u]] - h[r[u]];
					}

					void R(int& u){
					    int p = l[u];
					    l[u] = r[p], r[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void L(int& u){
					    int p = r[u];
					    r[u] = l[p], l[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void insert(int& u, int v){
					    if(!u) u = ++ ind, w[u] = v;
					    else if(v < w[u]){
					        insert(l[u], v);
					        if(gb(u) == 2){
					            if(gb(l[u]) == 1) R(u);
					            else L(l[u]), R(u);
					        }
					    }else{
					        insert(r[u], v);
					        if(gb(u) == -2){
					            if(gb(r[u] == -1)) L(u);
					            else R(r[u]), L(u);
					        }
					    }
					    update(u);
					}

					bool bfs(int root){
					    int hh, tt;
					    hh = tt = 0;
					    
					    q[0] = root;
					    bool res = true;
					    pos[root] = 1;
					    while(hh <= tt){
					        int t = q[hh++];
					        
					        if(l[t]) q[++tt] = l[t], pos[l[t]] = pos[t] * 2;
					        if(r[t]) q[++tt] = r[t], pos[r[t]] = pos[t] * 2 + 1;
					        
					        if(pos[t] > n) res = false;
					    }
					    
					    cout << w[q[0]];
					    for(int i = 1; i < hh; i++) cout << " " << w[q[i]];
					    cout << endl;
					    return res;
					}


					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        int v;
					        cin >> v;
					        insert(root, v);
					    }
					    
					    bool res = bfs(root);
					    if(res) cout << "YES" << endl;
					    else cout << "NO" << endl;
					    return 0;
					}
				r4. 好奇怪,再写一次,一次通过..上面的bug到底是什么?
					#include <iostream>

					using namespace std;

					const int N = 30;
					int l[N], r[N], h[N], w[N], ind;
					int q[N], pos[N];
					int n, root;

					void update(int u){
					    h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					int gb(int u){
					    return h[l[u]] - h[r[u]];
					}

					void R(int& u){
					    int p = l[u];
					    l[u] = r[p], r[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void L(int& u){
					    int p = r[u];
					    r[u] = l[p], l[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void insert(int& u, int v){
					    if(!u) u = ++ ind, w[u] = v;
					    else if(v < w[u]){
					        insert(l[u], v);
					        if(gb(u) == 2){
					            if(gb(l[u]) == 1) R(u);
					            else L(l[u]), R(u);
					        }
					    }else{
					        insert(r[u], v);
					        if(gb(u) == -2){
					            if(gb(r[u] == -1)) L(u);
					            else R(r[u]), L(u);
					        }
					    }
					    update(u);
					}

					bool bfs(int root){
					    int hh, tt;
					    hh = tt = 0;
					    
					    q[0] = root;
					    bool res = true;
					    pos[root] = 1;
					    while(hh <= tt){
					        int t = q[hh++];
					        
					        if(l[t]) q[++tt] = l[t], pos[l[t]] = pos[t] * 2;
					        if(r[t]) q[++tt] = r[t], pos[r[t]] = pos[t] * 2 + 1;
					        
					        if(pos[t] > n) res = false;
					    }
					    
					    cout << w[q[0]];
					    for(int i = 1; i < hh; i++) cout << " " << w[q[i]];
					    cout << endl;
					    return res;
					}


					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        int v;
					        cin >> v;
					        insert(root, v);
					    }
					    
					    bool res = bfs(root);
					    if(res) cout << "YES" << endl;
					    else cout << "NO" << endl;
					    return 0;
					}
				r5.
					#include <iostream>

					using namespace std;

					const int N = 30;
					int l[N], r[N], h[N], w[N], ind;
					int q[N], pos[N];
					int n, root;

					void update(int u){
					    h[u] = max(h[l[u]], h[r[u]]) + 1;
					}

					int gb(int u){
					    return h[l[u]] - h[r[u]];
					}

					void R(int& u){
					    int p = l[u];
					    l[u] = r[p], r[p] = u;
					    update(u), update(p);
					    u = p;
					}


					void L(int& u){
					    int p = r[u];
					    r[u] = l[p], l[p] = u;
					    update(u), update(p);
					    u = p;
					}

					void insert(int& u, int v){
					    if(!u){
					        u = ++ ind;
					        w[u] = v;
					    }else if(v < w[u]){
					        insert(l[u], v);
					        if(gb(u) == 2){
					            if(gb(l[u]) == 1) R(u);
					            else L(l[u]), R(u);
					        }
					    }
					    else{
					        insert(r[u], v);
					        if(gb(u) == -2){
					            if(gb(r[u]) == -1) L(u);
					            else R(r[u]), L(u);
					        }
					    }
					    
					    update(u);
					}

					void bfs(int root){
					    int hh, tt;
					    hh = tt = 0;
					    
					    bool res = true;
					    pos[root] = 1;
					    
					    q[0] = root;
					    while(hh <= tt){
					        int t = q[hh++];
					        if(l[t]) q[++tt] = l[t], pos[l[t]] = pos[t] * 2;
					        if(r[t]) q[++tt] = r[t], pos[r[t]] = pos[t] * 2 + 1;
					        if(pos[t] > n) res = false;
					    }
					    
					    cout << w[q[0]];
					    for(int i = 1; i < hh; i++) cout << " " << w[q[i]];
					    cout << endl;
					    if(res) cout << "YES" << endl;
					    else cout << "NO" << endl;
					    return;
					    
					    
					}

					int main(){
					    cin >> n;
					    for(int i = 0; i < n; i++){
					        int v;
					        cin >> v;
					        insert(root, v);
					    }
					    
					   bfs(root);
					   
					   return 0;
					}

	15. 2020年11月3日08:24:56

		60. 1628. 判断红黑树	1135  ***** 
			0. bug
				1.  left和right不赋初值0就会错呢
					考虑到有k个测试案例，如果left与right不附初值0
					那么当左子树或右子树为空不向下递归时则left与right没有更新，是之前测试案例的值
				2. 每次记得pos.clear()
				3. 记得要把in[i] = abs(pre[i]);
					但是build()里面是 root = pre[pl], k = pos[abs(root)];
			1. 笔记
				0. 之所以用build()加工
					1. return root
					2. 计算ls 和 rs
					因为:
						1. root可以用递归的方式求得: 用来判断这个条件 if(root < 0) {if(left < 0 || right < 0) res = false;}
						2. ls和rs也可以递归求得
						3. 需要判断的东西: 都可以递归求得, 所以放在了一个 build()里面
							1. 根节点是黑色(最后判断)
							2. 红色节点的儿子都是黑色(递归的时候判断)
							3. 每个节点到每个叶子节点,经过的黑色点的个数都是一样的(递归的时候判断)
				0. 
					1. build() 包含了两种信息: 两个儿子的颜色, 两个儿子(两个路径)的黑色节点数量
						1. 两个儿子的颜色: 也就是用left 和 right传回来的, 如果父亲是红色, 此时如果l,r有一个是红色, 那么就是false, 不是红黑树 
							if(root < 0 ) if (left < 0 || right < 0) ans = false;
						2. 两个儿子(两个路径)的黑色节点:
							if (ls != rs) ans = false; 只要tree的最下面递归回来的时候有两个路径的黑色节点数目不一样, 就是false
						    sum = ls;
						    更新黑色节点的高度: if(root > 0) sum++;
					2. build()和以前一样, 是满足几个条件的:
						1. 递归到底:
							因为最底层的情况是 null, 也就是相当于跳过了两个build(), 直接走到最后一句 return root. 并且已经有一个sum++;
						2. 判断自己:
							if (k < il || k > ir) res = false;
						3. 看两个儿子:
							1. 两个儿子的颜色
								if(root < 0 ) if (left < 0 || right < 0) ans = false;
							2. 两个儿子(两个路径)的黑色节点:
								if (ls != rs) ans = false; 只要tree的最下面递归回来的时候有两个路径的黑色节点数目不一样, 就是false

						4. 将自己的信息传给父亲:
							sum = ls;
							if(root > 0) sum++; 自己是黑色, 黑色数量 + 1
							return root;

				1. 
					1. 需要判断的东西:
					1. 根节点是黑色(最后判断)
					2. 红色节点的儿子都是黑色(递归的时候判断)
					3. 每个节点到每个叶子节点,经过的黑色点的个数都是一样的(递归的时候判断)
			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>

					using namespace std;

					const int N = 40;

					int pre[N], in[N];
					unordered_map<int, int> pos;
					bool ans;

					int build(int il, int ir, int pl, int pr, int& sum)
					{
					    int root = pre[pl];
					    int k = pos[abs(root)];

					    if (k < il || k > ir)
					    {
					        ans = false;
					        return 0;
					    }

					    int left = 0, right = 0, ls = 0, rs = 0;
					    if (il < k) left = build(il, k - 1, pl + 1, pl + 1 + k - 1 - il, ls);
					    if (k < ir) right = build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr, rs);

					    if (ls != rs) ans = false;
					    sum = ls;
					    if (root < 0)
					    {
					        if (left < 0 || right < 0) ans = false;
					    }
					    else sum ++ ;

					    return root;
					}

					int main()
					{
					    int T;
					    cin >> T;
					    while (T -- )
					    {
					        int n;
					        cin >> n;
					        for (int i = 0; i < n; i ++ )
					        {
					            cin >> pre[i];
					            in[i] = abs(pre[i]);
					        }

					        sort(in, in + n);

					        pos.clear();
					        for (int i = 0; i < n; i ++ ) pos[in[i]] = i;

					        ans = true;
					        int sum;
					        int root = build(0, n - 1, 0, n - 1, sum);

					        if (root < 0) ans = false;
					        if (ans) puts("Yes");
					        else puts("No");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/283682/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b

					#include <iostream>
					#include <algorithm>
					#include <unordered_map>

					using namespace std;

					const int N = 40;

					int pre[N], in[N];
					unordered_map<int, int> pos;
					bool ans;

					int build(int il, int ir, int pl, int pr, int& sum)  
					sum的语意是,当前的这个根节点(不是全树的根节点)到每个叶子结点的经过的黑色节点的数量
					我之前的疑问是: 既然是到每一个叶子结点,为什么只有一个sum(因为已经说过了经过的黑色节点数目相等,所以用一个变量就可以存了)
					因为
						1. 我们是递归的过程,经过了无数个build()之后,最后是先来到了叶子节点,叶子节点有两个null
						2. 我们使用了两个build(),每个build都会返回一个ls和rs的值,这两个变量和sum的作用一样,都是记录经过黑色节点的数目. 
						3. 如果ls,rs不相等,我们就不需要记录sum了,因为不是红黑树
						3. 如果相等,ls赋值给sum,其实就只有一个sum就够了,因为ls == rs
					{
					    int root = pre[pl];
					    int k = pos[abs(root)]; 因为在存pos的时候, 是用绝对值存的.

					    if (k < il || k > ir)  不合法的情况
					    	题目给的前序遍历不一定合法, 所以: k <= il-1 或者 k >= ir + 1就是不合法
					    	但是如果 k == il 是合法的, 只不过没有左子树, 或者 k == ir也是合法的, 只不过没有右子树
					    {
					        ans = false; 全局变量变成false,说明不能构建红黑树
					        return 0; 老师说, 随便return一个值就可以. 因为反正都是false了, 也没有必要在 返回一个宏结点或者嘿节点去 继续判断什么了. 
					    }

					    int left = 0, right = 0; 左右子,设置成0, 0代表着黑色. 红黑树默认是黑色,如果需要染色,染成红色[叶子结点的底下是null节点,也是黑色节点]
					    int ls = 0, rs = 0; 去叶子节点经过的黑色节点数目.
					    if (il < k) left = build(il, k - 1, pl + 1, pl + 1 + k - 1 - il, ls); 如果有左子, 它构建他.
					    if (k < ir) right = build(k + 1, ir, pl + 1 + k - 1 - il + 1, pr, rs);

					    上面因为有两个build(),所以是递归部分
					    走到此时,说明是到了树的最底下左边的叶子节点, 叶子节点是不走上面两个build()的因为il == k == ir.
					    此时ls == rs == 0. 

					    if (ls != rs) ans = false;
					    sum = ls; 相等就说明,叶子节点经过的黑色数目是sum.

					    if (root < 0) (如果是第一次走到这里,说明root就是叶子节点) root节点 < 0说明是红色
					    {
					        if (left < 0 || right < 0) ans = false; 如果两个儿子有一个是红色,就不是红黑树
					    }
					    else sum ++ ; 因为当前的root节点就是黑色的,所以递归回去的时候,需要告诉root的父亲, 现在又多了一个黑色节点(也就是root自己)

					    return root;
					}

					int main()
					{
					    int T;
					    cin >> T;
					    while (T -- )
					    {
					        int n;
					        cin >> n;
					        for (int i = 0; i < n; i ++ )
					        {
					            cin >> pre[i]; 不用sort,因为我们不需要知道节点的具体的值,只需要知道节点在哪里就好了
					            in[i] = abs(pre[i]); 因为我们要sort()所以我们要加入的是绝对值.
					        }

					        sort(in, in + n);

					        pos.clear();
					        for (int i = 0; i < n; i ++ ) pos[in[i]] = i;

					        ans = true; 我们默认是true,而不是默认是false. 因为逻辑不是证明xx是红黑树,而是,如果xx只要不满足了某个性质就不是红黑树. 所以后面一直是推翻的逻辑.
					        int sum; 这个是根节点到所有叶子节点经过的黑色节点的数目(因为说了经过的路线中,所有黑色节点个数都是相等,那就可以用一个值纪录个数,也就是一个sum就够了)
					        int root = build(0, n - 1, 0, n - 1, sum); 重建二叉树, 求根节点.

					        if (root < 0) ans = false;  最后判断根节点是不是黑色
					        if (ans) puts("Yes"); 
					        else puts("No");
					    }

					    return 0;
					}
			3. 5次
				r1. 挺顺利的,不难
					#include<iostream>
					#include<unordered_map>
					#include<algorithm>

					using namespace std;

					const int N = 40;
					int pre[N], in[N];
					unordered_map<int, int> pos;
					int n;
					bool ans;

					int build(int il, int ir, int pl, int pr, int& sum){
					    int root = pre[pl];
					    int k = pos[abs(root)];

					    if(k < il || k > ir){
					        ans = false;
					        return -1;
					    }

					    int left = 0, right = 0; 
					    int ls = 0, rs = 0;
					    if(il < k) left = build(il, k-1, pl+1, pl+1+(k-1-il), ls);
					    if(k < ir) right = build(k+1, ir, pl+1+(k-il), pr, rs);

					    if(ls != rs){
					        ans = false;
					        return -1;
					    }

					    sum = ls;
					    if(root < 0){
					        if(left < 0 || right < 0){
					            ans = false;
					            return -1;
					        }
					    }else{
					        sum ++;
					    }

					    return root;
					}


					int main(){
					    int T;
					    cin >> T;
					    while(T--){
					        ans = true;

					        cin >> n;
					        for(int i = 0; i < n ; i++){
					            cin >> pre[i];
					            in[i] = abs(pre[i]);
					        }

					        sort(in, in + n);
					        pos.clear();
					        for(int i = 0; i < n; i++){
					            pos[in[i]] = i;
					        }

					        int sum;
					        int root = build(0, n-1, 0, n-1, sum);
					        if(root < 0) ans = false;
					        if(ans) cout << "Yes" << endl;
					        else cout << "No" << endl;
					    }

					    return 0;
					}
				r2.
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 40;
					int pre[N], in[N];
					unordered_map<int, int> pos;
					int n;
					bool res;

					int build(int il, int ir, int pl, int pr, int& sum){
					    int root = pre[pl];
					    int k = pos[abs(root)];
					    
					    if(k < il || k > ir){
					        res = false;
					        return -1;
					    }
					    
					    int left = 0, right = 0;
					    int ls = 0, rs = 0;
					    if(il < k) left = build(il, k - 1, pl + 1, pl + 1 + (k-1-il), ls);
					    if(k < ir) right = build(k+1, ir, pl+1+(k-il), pr, rs);
					    
					    if(ls != rs){
					        res = false;
					        return -1;
					    }
					    
					    sum = ls;
					    if(root > 0){
					        sum ++;
					    }else{
					        if(left < 0 || right < 0){
					            res = false;
					            return -1;
					        }
					    }
					    
					    return root;
					    
					}

					int main(){
					    int T;
					    cin >> T;
					    while(T--){
					        res = true;
					        cin >> n;
					        for(int i = 0; i < n; i++)
					        {
					            cin >> pre[i];
					            in[i] = abs(pre[i]);
					        }
					        
					        sort(in, in + n);
					        pos.clear();
					        for(int i = 0 ; i <n; i++){
					            pos[in[i]] = i;
					        }
					        
					        int sum;
					        int root = build(0, n-1, 0, n-1, sum);
					        if(root < 0) res = false;
					        if(res) cout << "Yes" << endl;
					        else cout << "No" << endl;
					    }
					    return 0;
					}
				r3.
					#include <iostream>
					#include <algorithm>
					#include <unordered_map>

					using namespace std;

					const int N = 40;
					int pre[N], in[N];
					unordered_map<int, int> pos;
					int n;
					bool res;

					int build(int il, int ir, int pl, int pr, int& sum){
					    int root = pre[pl];
					    int k = pos[abs(root)];
					    
					    if(k < il || k > ir){
					        res = false;
					        return -1;
					    }
					    
					    int left = 0, right = 0;
					    int ls = 0, rs = 0;
					    if(il < k) left = build(il, k - 1, pl + 1, pl + 1 + (k - 1 - il), ls);
					    if(k < ir) right = build(k + 1, ir, pl + 1 + (k - il), pr, rs);
					    
					    if(ls != rs){
					        res = false;
					        return -1;
					    }
					    sum = ls;
					    
					    if(root < 0){
					        if(left < 0 || right < 0){
					            res = false;
					            return -1;
					        }
					    }
					    if(root > 0) sum ++ ;
					    return root;
					}

					int main(){
					    int T;
					    cin >> T;
					    while(T--){
					        res = true;
					        cin >> n;
					        for(int i = 0; i < n; i++){
					            cin >> pre[i];
					            in[i] = abs(pre[i]);
					        }
					        
					        sort(in, in + n);
					        pos.clear();
					        for(int i = 0; i < n; i++){
					            pos[in[i]] = i;
					        }
					        
					        int sum;
					        int root = build(0, n-1, 0, n-1, sum);
					        if(root < 0) res = false;
					        if(res) cout << "Yes" << endl;
					        else cout << "No" << endl;
					    }
					    return 0;
					}
				r4.
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 40;
					int pre[N], in[N];
					unordered_map<int, int> pos;
					int n;
					bool res;

					int build(int il, int ir, int pl, int pr, int& sum){
					    int ls = 0, rs = 0;
					    int root = pre[pl];
					    int k = pos[abs(root)];
					    
					    if(k < il || k > ir){
					        res = false;
					        return -1;
					    }
					    
					    int left = 0, right = 0;
					    if(il < k) left = build(il, k - 1, pl + 1, pl + 1 + (k - 1- il), ls);
					    if(k < ir) right = build(k + 1, ir, pl + 1 + ( k - il), pr, rs);
					    
					    if(ls != rs){
					        res = false;
					        return -1;
					    }
					    sum = ls;
					    if(root < 0){
					        if(left < 0 || right < 0){
					            res = false;
					            return -1;
					        }
					    }
					    
					    if(root > 0){
					       sum ++; 
					    }
					    return root;
					    
					}

					int main(){
					    int T;
					    cin >> T;
					    while(T--){
					        res = true;
					        cin >> n;
					        for(int i = 0; i < n; i++){
					            cin >> pre[i];
					            in[i] = abs(pre[i]);
					        }
					        
					        sort(in, in + n);
					        pos.clear();
					        for(int i = 0 ; i < n ; i++){
					            pos[in[i]] = i;
					        }
					        
					        int sum;
					        int root = build(0, n-1, 0, n-1, sum);
					        if(root < 0) res = false;
					        if(res) cout << "Yes" << endl;
					        else cout << "No" << endl;
					    }
					    
					    return 0;
					}
				r5.

		61. 1539. 等重路径	1053
			0. bug
			1. 笔记
				0. 思路还是很简单的.
					注意的地方:
						1. dfs()里面传入的东西,是当前自己节点的所有信息
							也就是dfs(int u, int s, xx path)中s和path是已经包含了自己这个节点u的信息, 而不是进入dfs()之后再处理这些信息
							原因: 因为我们有恢复现场这个步骤. 而恢复现场是要给儿子节点已经准备好信息, 所以dfs()的参数就是要包括已经准备好的信息
								path.push_back(w[i]); 
				                dfs(i, s + w[i], path); 这个权重s + w[i]也算是恢复现场. 因为每个儿子的信息都不同
				                path.pop_back();
				1. 我们有ans的排序: 从大到小
					sort(ans.begin(), ans.end(), greater<vector<int>>());
				2. 检查是否是leaf:
					bool is_leaf(int u){
					    for(int i = 0; i < n; i++){
					        if(g[u][i]) return false;
					    }
					    return true;
					}
				0. 
					1. 考察了 dfs() 来搜索每一个从根到叶子的路径
						其中是先从 最开始的时候, 传入根节点的信息: 权值, 和path
					2. dfs() 一个很重要的性质: 恢复现场
						终止条件是:
							if (is_leaf)
						    {
						        if (s == S) ans.push_back(path);
						    }
						因为for (int i = 0; i < n; i ++ )
				            if (g[u][i])
				            {
				                path.push_back(w[i]); 
				                dfs(i, s + w[i], path);
				                path.pop_back();
				            }
				        你看这个for()循环, 当你自己的节点要去儿子节点的时候, 首先把这个儿子节点的信息给他备好: 儿子的权重: s + w[i], 儿子的path: path.push_back(w[i]); 
				        	如果这个儿子, 是叶子节点, 遇到终止条件就会return会自己节点
				        然后你在去你下一个儿子的节点,也就是for()的下一个,所以你要把你当前儿子的信息给pop掉, 给新儿子准备信息
				1. 
					1. 用邻接矩阵存,而不是邻接表
					2. pat很要求stl的使用,例如这道题需要使用vector<>的比较,你不需要自己实现小于号,很方便
					3. 因为N很小,所以老师用邻接矩阵存,老师说pat的很多题都可以邻接矩阵存.
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					int n, m, S;
					int w[N];
					bool g[N][N];
					vector<vector<int>> ans;

					void dfs(int u, int s, vector<int> &path)
					{
					    bool is_leaf = true;
					    for (int i = 0; i < n; i ++ )
					        if (g[u][i])
					        {
					            is_leaf = false;
					            break;
					        }

					    if (is_leaf)
					    {
					        if (s == S) ans.push_back(path);
					    }
					    else
					    {
					        for (int i = 0; i < n; i ++ )
					            if (g[u][i])
					            {
					                path.push_back(w[i]);
					                dfs(i, s + w[i], path);
					                path.pop_back();
					            }
					    }
					}

					int main()
					{
					    cin >> n >> m >> S;
					    for (int i = 0; i < n; i ++ ) cin >> w[i];

					    while (m -- )
					    {
					        int id, k;
					        cin >> id >> k;
					        while (k -- )
					        {
					            int son;
					            cin >> son;
					            g[id][son] = true;
					        }
					    }

					    vector<int> path({w[0]});
					    dfs(0, w[0], path);

					    sort(ans.begin(), ans.end(), greater<vector<int>>());

					    for (auto p : ans)
					    {
					        cout << p[0];
					        for (int i = 1; i < p.size(); i ++ ) cout << ' ' << p[i];
					        cout << endl;
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/294234/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>
					#include <cstring>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					int n, m, S;
					int w[N]; 每个点的权值
					bool g[N][N]; 初始是false
					vector<vector<int>> ans; 爆搜,村结果

					void dfs(int u, int s, vector<int> &path) s的意思是到目前为止的权重之和(这个权重之和是包括了u点的). 因为需要修改path的值,所以我们要用引用
					{
					    bool is_leaf = true; 判断是否是叶子
					    for (int i = 0; i < n; i ++ ) 爆搜矩阵,因为一共有n个点,所以是 i < n
					        if (g[u][i])
					        {
					            is_leaf = false;
					            break;
					        }

					    if (is_leaf)
					    {
					        if (s == S) ans.push_back(path); 
					        说明是叶子结点, 之所以是(s == S)而不是(s + w[u] == S)是因为dfs()的参数s就是(这个权重之和是包括了u点,也就是这个叶子结点的的)
					    	最后你看,path是vector<int>, 而ans是全局变量, 是vector<vector<int>> 之所以用vector,是因为题目要求升序输出.
					    }
					    else 不是叶子,就继续往下遍历
					    {
					        for (int i = 0; i < n; i ++ ) 
					            if (g[u][i]) 如果存在这条路径
					            {
					                path.push_back(w[i]); 
					                dfs(i, s + w[i], path); 这里把叶子结点的权值也加上了 s + w[i]
					                path.pop_back(); 恢复现场,给下一个叶子使用
					            }
					    }
					}

					int main()
					{
					    cin >> n >> m >> S; 点数,边数,目标值
					    for (int i = 0; i < n; i ++ ) cin >> w[i];

					    while (m -- )
					    {
					        int id, k;
					        cin >> id >> k;
					        while (k -- )
					        {
					            int son;
					            cin >> son;
					            g[id][son] = true; 临界矩阵
					        }
					    }

					    vector<int> path({w[0]}); 存一个路径, 这个路径的第一个元素是根的权重
					    dfs(0, w[0], path); 从根节点开始搜, 最开始的总和是w[0](根的权重), 

					    sort(ans.begin(), ans.end(), greater<vector<int>>()); 升序输出

					    for (auto p : ans)
					    {
					        cout << p[0];
					        for (int i = 1; i < p.size(); i ++ ) cout << ' ' << p[i];
					        cout << endl;
					    }

					    return 0;
					}

			3. 5次
				r1.
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 110;
					int n, m, S;
					int w[N];
					bool g[N][N];
					vector<vector<int>> ans;
					vector<int> path;

					void dfs(int u, int s, vector<int> path){
					    bool is_leaf = true;
					    for(int i = 0; i < n; i++){
					        if(g[u][i]){
					            is_leaf = false;
					            break;
					        }
					    }

					    if(is_leaf){
					        if(s == S) ans.push_back(path);
					        return;
					    }else{
					        for(int i = 0; i < n; i++){
					            if(g[u][i]){
					                path.push_back(w[i]);
					                dfs(i, s + w[i], path);
					                path.pop_back();
					            }
					        }
					    }
					}

					int main(){
					    cin >> n >> m >> S;
					    for(int i = 0; i < n ; i++) cin >> w[i];

					    for(int i = 0; i < m ; i++){
					        int id, k, son;
					        cin >> id >> k;
					        while(k--){
					            cin >> son;
					            g[id][son] = true;
					        }
					    }

					    path.push_back(w[0]);
					    dfs(0, w[0], path);

					    sort(ans.begin(), ans.end(), greater<vector<int>>());
					    for(auto& item : ans){
					        cout << item[0];
					        for(int i = 1; i < item.size(); i++) cout << " " << item[i];
					        cout << endl;
					    }

					    return 0;
					}
				r2.
					#include <iostream>
					#include <algorithm>
					#include <vector>


					using namespace std;

					const int N = 110;
					int n, m, S, w[N];
					bool g[N][N];
					vector<vector<int>> ans;

					bool is_leaf(int u){
					    for(int i = 0; i < n; i++){
					        if(g[u][i]) return false;
					    }
					    return true;
					}

					void dfs(int u, int s, vector<int>& path){
					    if(is_leaf(u)){
					        if(s == S) ans.push_back(path);
					    }else{
					        for(int i = 0; i < n; i++){
					            if(g[u][i]){
					                path.push_back(w[i]);
					                dfs(i, s + w[i], path);
					                path.pop_back();
					            }
					        }
					    }
					}

					int main(){
					    cin >> n >> m >> S;
					    for(int i = 0; i < n; i++) cin >> w[i];
					    for(int i = 0; i < m; i++){
					        int id, k, son;
					        cin >> id >> k;
					        while(k--){
					            cin >> son;
					            g[id][son] = true;
					        }
					    }

					    vector<int> path({w[0]});
					    dfs(0, w[0], path);
					    
					    sort(ans.begin(), ans.end(), greater<vector<int>>());

					    for(auto& item : ans){
					        cout << item[0];
					        for(int i = 1; i < item.size(); i++) cout << " " << item[i];
					        cout << endl;
					    }
					    return 0;
					}
				r3.
					#include <iostream>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 110;
					int n, m, S, w[N];
					bool g[N][N];
					vector<vector<int>> ans;

					bool is_leaf(int u){
					    for(int i = 0; i < n ; i++){
					        if(g[u][i]) return false;
					    }
					    return true;
					}
					void dfs(int u, int s, vector<int>& path){
					    if(is_leaf(u)){
					        if(s == S) ans.push_back(path);
					    }else{
					        for(int i = 0; i < n; i++){
					            if(g[u][i]){
					                path.push_back(w[i]);
					                dfs(i, s + w[i], path);
					                path.pop_back();
					            }
					        }
					    }
					}

					int main(){
					    cin >> n >> m >> S;
					    for(int i = 0; i < n; i++) cin >> w[i];
					    for(int i = 0; i < m; i++){
					        int id, k, son;
					        cin >> id >> k;
					        while(k--){
					            cin >> son;
					            g[id][son] = true;
					        }
					    }
					    
					    vector<int> path({w[0]});
					    dfs(0, w[0], path);
					    sort(ans.begin(), ans.end(), greater<vector<int>>());
					    
					    for(auto& item : ans){
					        cout << item[0];
					        for(int i = 1; i < item.size(); i++) cout << " " << item[i];
					        cout << endl;
					    }
					    return 0;
					}
				r4.
					#include <iostream>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 110;
					int n, m, S, w[N];
					bool g[N][N];
					vector<vector<int>> ans;

					bool is_leaf(int u){
					    for(int i = 0; i < n; i++) if(g[u][i]) return false;
					    return true;
					}
					void dfs(int u, int s, vector<int>& path){
					    if(is_leaf(u)){
					        if(s == S) ans.push_back(path);
					    }
					    else{
					        for(int i = 0; i < n; i++){
					            if(g[u][i]){
					                path.push_back(w[i]);
					                dfs(i, s + w[i], path);
					                path.pop_back();
					            }
					        }
					    }
					}

					int main(){
					    cin >> n >> m >> S;
					    for(int i = 0; i < n; i++) cin >> w[i];
					    for(int i = 0; i < m ; i++){
					        int id, k, son;
					        cin >> id >> k;
					        while(k--){
					            cin >> son;
					            g[id][son] = true;
					        }
					    }
					    
					    vector<int> path({w[0]});
					    dfs(0, w[0], path);
					    sort(ans.begin(), ans.end(), greater<vector<int>>());
					    for(auto& item : ans){
					        cout << item[0];
					        for(int i = 1; i < item.size(); i++) cout << " " << item[i];
					        cout << endl;
					    }
					    return 0;
					    
					}
				r5.

		62. 1584. 最大的一代	1094
			0. bug
				1. 题目的编号是从01开始的, 而不是从00开始的:
					while(level[l].size()){
				        for(int id : level[l]){
				            错误: for(int i = 0; i < n; i++){
				            正确: for(int i = 1; i <= n; i++){
				                if(g[id][i]) level[l+1].push_back(i);
				            }
				        }
				        l++;
				    }
				    另外, 题目认为最顶层是01层而不是00层
				    所以我们是level[1].push_back(1); 而不是level[0].push_back(1);
				2. 我们用的是 vector<int> level[N]; 而不是 vector<vector<int>> level;
			1. 笔记
				1. 
					1. 就是宽搜,老师没有用queue[]实现,而是vector<int> level[N];
					2. 总之和queue[]很像, 就是用前面一层来populate后面一层
						不过还是容易写错, 多写几次
							level[1].push_back(1);
						    int l = 1;
						    while (level[l].size())
						    {
						        for (auto ver : level[l]) 看这个level上的所有人
						            for (int j = 1; j <= n; j ++ ) 这些人,每个人的儿子
						                if (g[ver][j])
						                    level[l + 1].push_back(j); 插入下一个
						        l ++ ;
						    }
					3. 
						如果bool g[N][N],如果N==100,占用的内存是0.01MB, int g[N][N] 会是4倍.
						如果bool g[N][N],如果N==10010,占用的内存是95MB
						如果bool g[N][N],如果N==7010,占用的内存是46MB
						cout << (sizeof g) / 1024.0 / 1024.0 << endl;
						但是如果只是g[N][N]但是没有用memset(g, 0, sizeof(g))的话,是不会说超空间的
						因为只是定义g[N][N],系统会优化,不会真的用这么多内存
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 110;

					int n, m;
					bool g[N][N];
					vector<int> level[N];

					int main()
					{
					    cin >> n >> m;

					    while (m -- )
					    {
					        int id, k;
					        cin >> id >> k;
					        while (k -- )
					        {
					            int son;
					            cin >> son;
					            g[id][son] = true;
					        }
					    }

					    level[1].push_back(1);
					    int l = 1;

					    while (level[l].size())
					    {
					        for (auto ver : level[l])
					            for (int j = 1; j <= n; j ++ )
					                if (g[ver][j])
					                    level[l + 1].push_back(j);
					        l ++ ;
					    }

					    int k = 1;
					    for(int i = 1; i < l; i ++ )
					        if (level[i].size() > level[k].size())
					            k = i;

					    cout << level[k].size() << ' ' << k << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/294240/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>
					#include <vector>

					using namespace std;

					const int N = 110;

					int n, m;
					bool g[N][N];
					vector<int> level[N];


					int main(){

					    cin >> n >> m;
					    for(int i = 0; i < m; i++){
					        int id, k, son;
					        cin >> id >> k;
					        while(k--){
					            cin >> son;
					            g[id][son] = true;
					        }
					    }
					    
					    //exit(0);

					    level[1].push_back(1);
					    int l = 1;
					    while(level[l].size()){
					        for(int id : level[l]){
					            for(int i = 1; i <= n; i++){
					                if(g[id][i]) level[l+1].push_back(i);
					            }
					        }
					        l++;
					    }
					    

					    int k = 1;
					    for(int i = 1; i < l ; i++){
					        if((int)level[i].size() > (int)level[k].size()) k = i;
					    }

					    
					    cout << level[k].size() <<  " " << k << endl;
					    return 0;

					}
				r2.
					#include <iostream>
					#include <vector>

					using namespace std;

					const int N = 110;
					int n, m;
					bool g[N][N];
					vector<int> level[N];

					int main(){
					    cin >> n >> m;
					    while(m--){
					        int id, k, son;
					        cin >> id >> k;
					        while(k--){
					            cin >> son;
					            g[id][son] = true;
					        }
					    }
					    
					    level[1].push_back(1);
					    int l = 1;
					    int maxn = 0;
					    int maxk = 0;
					    while(level[l].size()){
					        for(auto item : level[l]){
					            for(int i = 1 ; i <= n; i++){
					                if(g[item][i]) level[l+1].push_back(i);
					            }
					        }
					        if(level[l].size() > maxn){
					            maxn = level[l].size();
					            maxk = l;
					        }
					        l++;
					    }
					    
					    cout << maxn << " " << maxk << endl;
					    return 0;
					    
					    
					}
				r3.
					#include <iostream>
					#include <vector>

					using namespace std;

					const int N = 110;
					int n, m;
					bool g[N][N];
					vector<int> level[N];

					int main(){
					    cin >> n >> m;
					    while(m--){
					        int id, k, son;
					        cin >> id >> k;
					        while(k--){
					            cin >> son;
					            g[id][son] = true;
					        }
					    }
					    
					    level[1].push_back(1);
					    int l = 1;
					    while(level[l].size()){
					        for(int i : level[l]){
					            for(int j = 1; j <= n; j ++){
					                if(g[i][j]) level[l+1].push_back(j);
					            }
					        }
					        l++;
					    }
					    
					    int k = 1;
					    for(int i = 2; i < l; i++){
					        if(level[i].size() > level[k].size()) k = i;
					    }
					    cout << level[k].size() << " " << k <<endl;
					    return 0;
					}
				r4.
				r5.

	16. 2020年11月4日11:18:35

		63. 1565. 供应链总销售额	1079
			0. bug
				1. 注意 pow(1 + R / 100, dfs(i)); 记得除以100, 因为是百分比
				2. 记录价格, 利率是: double P, R; 不是int
				3. 不要忘了 memset(xx, -1, sizeof xx)
			1. 笔记
				1. dfs() 记忆化搜索, 搜完了这个就存下来, 避免下一次重复计算
				2. 老师没有用 邻接矩阵, 只记录了每个节点的父节点是谁
					因为我们需要求的是 某个节点到root的距离, 这个距离 == 该节点的father到root的距离 + 1
					所以只存父节点是谁就够了
				3. f[v]指的是v到根的距离
				4. 这个 dfs()递归我喜欢:
					1. 这里的是求某个点到root的距离, 不过递归的时候, 采用的是从f[root] = 0开始的, 然后儿子们是+1
						不同于以前的, 叶子节点的距离是0, 然后最后看root的最深高度是什么,那样的题目
					2. 既然是从f[root] = 0开始,那么我们就是要知道 父亲, 然后得出儿子. 所以递归的时候, 需要父亲的信息. 
						所以我们使用了存储父亲的信息的方法: + 一个函数判断是否是root
							p[son] = i; son的父亲是i,
							if(p[u] == -1)  u是根节点, 因为root没有父亲
						对比之前的存储儿子的方法 + 一个函数判断是否是leaf
							g[id][son] = true;
							bool is_leaf(int u){
							    for(int i = 0; i < n; i++){
							        if(g[u][i]) return false;
							    }
							    return true;
							}
					3. 城会玩: 老师一边将f[u]的值设置好了, 一边return
						int dfs(int u){
						    if(f[u] != -1) return f[u];
						    if(p[u] == -1) return f[u] = 0;
						    return f[u] = dfs(p[u]) + 1;
						}
				5. 当时题目说叶子结点的销售量是xx的时候,我没有想到用cnt[N]就可以, 我想的太复杂了, 我以为需要什么map
					判断是否是叶子: 看cnt[i]是否 == 0
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>
					#include <cmath>

					using namespace std;

					const int N = 100010;

					int n;
					double P, R;
					int p[N], f[N], c[N]; p[N]每个点的父节点, f[N]每个点到根节点的距离, c[N]某个叶节点卖给了多少消费者

					int dfs(int u) 这个叫做记忆化搜索, 也是dp的一种
					{
					    if (f[u] != -1) return f[u]; 已经搜索过了
					    if (p[u] == -1) return f[u] = 0; 如果这个点没有父节点, 就是根节点
					    return f[u] = dfs(p[u]) + 1; 我这个节点到根节点的距离 == 父节点到根节点的距离 + 1
					}

					int main()
					{
					    cin >> n >> P >> R;

					    memset(p, -1, sizeof p); 所有点都没有父节点
					    for (int i = 0; i < n; i ++ )
					    {
					        int k;
					        cin >> k;
					        for (int j = 0; j < k; j ++ )
					        {
					            int son;
					            cin >> son;
					            p[son] = i;
					        }

					        if (!k) cin >> c[i];
					    }

					    memset(f, -1, sizeof f);

					    double res = 0;
					    for (int i = 0; i < n; i ++ )
					        if (c[i])
					            res += c[i] * P * pow(1 + R / 100, dfs(i)); 这里用到了dfs(i), 也就是i到根节点的距离.

					    printf("%.1lf\n", res);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/317063/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>
					#include <cmath>
					#include <cstring>

					using namespace std;

					const int N = 100010;

					int n, p[N], f[N], cnt[N];
					double P, R;

					int dfs(int u){
					    if(f[u] != -1) return f[u];
					    if(p[u] == -1) return f[u] = 0;
					    return f[u] = dfs(p[u]) + 1;
					}

					int main(){
					    cin >> n >> P >> R;

					    memset(p, -1, sizeof p);
					    memset(f, -1, sizeof f);
					    int k, son;
					    for(int i = 0; i < n; i++){
					        cin >> k;
					        if(k){
					            while(k--){
					                cin >> son;
					                p[son] = i;
					            }
					        }else{
					            cin >> cnt[i];
					        }
					    }

					    double res = 0;
					    for(int i = 0; i < n; i++){
					        if(cnt[i])
					            res += cnt[i] * P * pow(1 + R / 100, dfs(i));
					    }

					    printf("%.1lf", res);
					    return 0;
					}
				r2.
					#include <iostream>
					#include <cstring>
					#include <cmath>

					using namespace std;

					const int N = 100010;
					int n, p[N], f[N], cnt[N];
					double P, R;

					int dfs(int u){
					    if(f[u] != -1) return f[u];
					    if(p[u] == -1) return f[u] = 0;
					    return f[u] = dfs(p[u]) + 1;
					}
					int main(){
					    cin >> n >> P >> R;
					    int k, son;
					    
					    memset(p, -1, sizeof p);
					    memset(f, -1, sizeof f);
					    for(int i = 0; i < n; i++){
					        cin >> k;
					        if(!k) cin >> cnt[i];
					        while(k--){
					            cin >> son;
					            p[son] = i;
					        }
					    }
					    
					    double res = 0;
					    for(int i = 0; i < n; i++){
					        if(cnt[i]){
					            res += cnt[i] * P * pow(1 + R / 100, dfs(i));
					        }
					    }
					    
					    printf("%.1lf", res);
					    return 0;
					    
					}
				r3.
					#include <iostream>
					#include <cstring>
					#include <cmath>

					using namespace std;

					const int N = 100010;
					int n, p[N], f[N], cnt[N];
					double P, R;

					int dfs(int u){
					    if(f[u] != -1) return f[u];
					    if(p[u] == -1) return f[u] = 0;
					    return f[u] = dfs(p[u]) + 1;
					}

					int main(){
					    cin >> n >> P >> R;
					    int k, son;
					    
					    memset(p, -1, sizeof p);
					    for(int i = 0; i < n; i++){
					        cin >> k;
					        if(!k) cin >> cnt[i];
					        while(k--){
					            cin >> son;
					            p[son] = i;
					        }
					    }
					    
					    memset(f, -1, sizeof f);
					    double res = 0;
					    for(int i = 0; i <n; i++){
					        if(cnt[i]){
					            res += cnt[i] * P * pow(1 + R / 100, dfs(i));
					        }
					    }
					    
					    printf("%.1lf", res);
					    return 0;
					}
				r4.
					#include <iostream>
					#include <cstring>
					#include <cmath>

					using namespace std;

					const int N = 100010;
					int n, p[N], f[N], cnt[N];
					double P, R;

					int dfs(int u){
					    if(f[u] != -1) return f[u];
					    if(p[u] == -1) return f[u] = 0;
					    return f[u] = dfs(p[u]) + 1;
					}

					int main(){
					    cin >> n >> P >> R;
					    int k, son;
					    
					    memset(p, -1, sizeof p);
					    for(int i = 0; i < n; i++){
					        cin >> k;
					        if(!k) cin >> cnt[i];
					        while(k--){
					            cin >> son;
					            p[son] = i;
					        }
					    }
					    
					    double res = 0;
					    memset(f, -1, sizeof f);
					    for(int i = 0; i < n; i++){
					        if(cnt[i]) res += cnt[i] * P * pow(1 + R / 100, dfs(i));
					    }
					    
					    printf("%.1lf", res);
					    return 0;
					}
				r5.

		64. 1580. 供应链最高价格	1090
			0. bug
			1. 笔记
				1. 求节点到root距离
				2. 双关键字排序: 最大深度, 最大深度的个数
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <cmath>

					using namespace std;

					const int N = 100010;

					int n;
					double P, R;
					int p[N], f[N];

					int dfs(int u)
					{
					    if (f[u] != -1) return f[u];
					    if (p[u] == -1) return f[u] = 0;
					    return f[u] = dfs(p[u]) + 1;
					}

					int main()
					{
					    cin >> n >> P >> R;
					    for (int i = 0; i < n; i ++ ) cin >> p[i];

					    memset(f, -1, sizeof f);

					    int  max_depth = 0, cnt = 0;
					    for (int i = 0; i < n; i ++ )
					        if (dfs(i) > max_depth) 枚举每个点 到根节点的距离, 说明这是最大致
					        {
					            max_depth = dfs(i); 
					            cnt = 1;
					        }
					        else if (dfs(i) == max_depth) cnt ++ ;

					    printf("%.2lf %d\n", P * pow(1 + R / 100, max_depth), cnt);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/317068/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1. byb 不难
					#include <iostream>
					#include <cstring>
					#include <cmath>

					using namespace std;

					const int N = 100010;
					int n, p[N], f[N];
					double P, R;

					int dfs(int u){
					    if(f[u] != -1) return f[u];
					    if(p[u] == -1) return f[u] = 0;
					    return f[u] = dfs(p[u]) + 1;
					}

					int main(){
					    cin >> n >> P >> R;
					    memset(p, -1, sizeof p);
					    for(int i = 0; i < n; i++){
					        cin >> p[i];
					    }

					    int m = -1, cnt = 0; m是节点到root的最深深度
					    memset(f, -1, sizeof f);
					    for(int i = 0; i < n; i++){
					        int temp = dfs(i);
					        if(m < temp){
					            m = temp;
					            cnt = 1;
					        }
					        else if(m == temp) cnt ++;
					    }

					    printf("%.2lf %d", P * pow(1 + R / 100, m), cnt);
					    return 0;
					}
				r2.
					#include <iostream>
					#include <cstring>
					#include <cmath>

					using namespace std;

					const int N = 100010;
					int n, p[N], f[N];
					double P, R;

					int dfs(int u){
					    if(f[u] != -1) return f[u];
					    if(p[u] == -1) return f[u] = 0;
					    return f[u] = dfs(p[u]) + 1;
					}

					int main(){
					    cin >> n >> P >> R;
					    memset(p, -1, sizeof p);
					    for(int i = 0; i < n; i++) cin >> p[i];
					    
					    int md = -1, cnt = 0;
					    memset(f, -1, sizeof f);
					    for(int i = 0; i < n; i++){
					        int temp = dfs(i);
					        if(md < temp) md = temp, cnt = 1;
					        else if(md == temp) cnt ++;
					    }
					    
					    printf("%.2lf %d", P * pow(1 + R / 100, md), cnt);
					    return 0;
					}
				r3.
					#include <iostream>
					#include <cstring>
					#include <cmath>

					using namespace std;

					const int N = 100010;
					int n, p[N], f[N];
					double P, R;

					int dfs(int u)
					{
					    if(f[u] != -1) return f[u];
					    if(p[u] == -1) return f[u] = 0;
					    return f[u] = dfs(p[u]) + 1;
					}

					int main(){
					    cin >> n >> P >> R;
					    memset(p, -1 ,sizeof p);
					    for(int i = 0; i < n; i++) cin >> p[i];
					    
					    int md = -1, cnt = 0;
					    memset(f, -1, sizeof f);
					    for(int i = 0; i < n; i++){
					        int temp = dfs(i);
					        if(md < temp) md = temp, cnt = 1;
					        else if(md == temp) cnt ++;
					    }
					    
					    printf("%.2lf %d", P * pow(1 + R / 100, md), cnt);
					    return 0;
					}
				r4.
				r5.

		65. 1596. 供应链最低价格	1106
			0. bug
				注意逻辑不要错. 因为是最小的距离, 但是这里一定是leaf到root的最短距离, 而不是任何一个点到root的最短距离, 因为如果是任何一个点, 那root到root就是0距离
				所以需要一个记录is_leaf的数组
			1. 笔记
				1. 这里不是问: 哪个节点到root的距离最小, 而是哪个叶节点到root的距离最小
					也就是求最短路径
				2. 思路还是: 遍历每个叶节点, 然后用 dfs()来往上递归(因为dfs()了父亲), 求到root的距离
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <cmath>

					using namespace std;

					const int N = 100010;

					int n;
					double P, R;
					int p[N], f[N];
					bool is_leaf[N];

					int dfs(int u)
					{
					    if (f[u] != -1) return f[u];
					    if (p[u] == -1) return f[u] = 0;
					    return f[u] = dfs(p[u]) + 1;
					}

					int main()
					{
					    cin >> n >> P >> R;

					    memset(p, -1, sizeof p);
					    for (int i = 0; i < n; i ++ )
					    {
					        int k;
					        cin >> k;
					        for (int j = 0; j < k; j ++ )
					        {
					            int son;
					            cin >> son;
					            p[son] = i;
					        }

					        if (!k) is_leaf[i] = true;
					    }

					    memset(f, -1, sizeof f);

					    int res = N, cnt = 0;
					    for (int i = 0; i < n; i ++ )
					        if (is_leaf[i])
					        {
					            if (res > dfs(i)) res = dfs(i), cnt = 1;
					            else if (res == dfs(i)) cnt ++ ;
					        }

					    printf("%.4lf %d\n", P * pow(1 + R / 100, res), cnt);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/317077/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>
					#include <cstring>
					#include <cmath>

					using namespace std;

					const int N = 100010;
					int n, p[N], f[N], is_leaf[N];
					double P, R;

					int dfs(int u){
					    if(f[u] != -1) return f[u];
					    if(p[u] == -1) return f[u] = 0;
					    return f[u] = dfs(p[u]) + 1;
					}

					int main(){
					    cin >> n >> P >> R;
					    memset(p, -1, sizeof p);
					    int k, son;
					    for(int i = 0; i < n; i++){
					        cin >> k;
					        if(!k) is_leaf[i] = 1;
					        while(k--){
					            cin >> son;
					            p[son] = i;
					        }
					    }

					    int md = N, cnt = 0;
					    memset(f, -1, sizeof f);
					    for(int i = 0; i < n; i++){
					        if(!is_leaf[i]) continue;
					        int temp = dfs(i);
					        if(temp < md) md = temp, cnt = 1;
					        else if(temp == md) cnt ++;
					    }

					    printf("%.4lf %d\n", P * pow(1 + R / 100, md), cnt);
					    return 0;
					}
				r2.
					#include <iostream>
					#include <cstring>
					#include <cmath>

					using namespace std;

					const int N = 100010;
					int n, p[N], f[N];
					double P, R;
					bool l[N];

					int dfs(int u){
					    if(f[u] != -1) return f[u];
					    if(p[u] == -1) return f[u] = 0;
					    return f[u] = dfs(p[u]) + 1;
					}

					int main(){
					    cin >> n >> P >> R;
					    memset(p, -1, sizeof p);
					    int k, son;
					    for(int i = 0; i < n; i++){
					        cin >> k;
					        if(!k) l[i] = true;
					        while(k--){
					            cin >> son;
					            p[son] = i;
					        }
					    }
					    
					    int m = N, cnt = 0;
					    memset(f, -1, sizeof f);
					    for(int i = 0; i < n; i++){
					        if(!l[i]) continue;
					        int t = dfs(i);
					        if(t < m) m = t, cnt = 1;
					        else if(t == m) cnt ++;
					    }
					    
					    printf("%.4lf %d", P * pow( 1 + R / 100, m), cnt);
					    
					    return 0;
					}
				r3.
					#include <iostream>
					#include <cstring>
					#include <cmath>

					using namespace std;

					const int N = 100010;
					int n, p[N], f[N];
					bool l[N];
					double P, R;

					int dfs(int u){
					    if(f[u] != -1) return f[u];
					    if(p[u] == -1) return f[u] = 0;
					    return f[u] = dfs(p[u]) + 1;
					}

					int main(){
					    cin >> n >> P >> R;
					    int k, son;
					    memset(p, -1, sizeof p);
					    for(int i = 0; i < n; i++){
					        cin >> k;
					        if(!k) l[i] = true;
					        while(k--){
					            cin >> son;
					            p[son] = i;
					        }
					    }
					    
					    int m = N, cnt = 0;
					    memset(f, -1, sizeof f);
					    for(int i = 0; i < n; i++){
					        if(!l[i]) continue;
					        int t = dfs(i);
					        if(t < m) m = t, cnt = 1;
					        else if(t == m) cnt ++;
					    }
					    
					    printf("%.4lf %d", P * pow(1 + R / 100, m), cnt);
					    
					    return 0;
					    
					}
				r4.
				r5.

		66. 1649. 堆路径	1155
			0. bug
				1. 因为是层序遍历,又是完全二叉树,所以最好从1开始
				2. 你写的时候注意typo, 例如我要写的是 u * 2, 但是竟然写成 n * 2, bug找了很久
				3. 正确:  if(path[i] > path[i-1]) lt = true; 输出小跟堆 Min Heap (也就是root最小)
			1. 笔记
				1.  完全二叉树, 层序遍历中暗含的条件: 
					if (u * 2 + 1 <= n)  dfs(u * 2 + 1); 存在右子树, 也就是右子树合法: u * 2 + 1. 如果u是叶子, 那么u没有左右子树, 因为 u * 2 > n
					if (u * 2 <= n) dfs(u * 2);
					if (u * 2 > n)  叶节点

				0.
					1. 那种一条一条路径下去的模板:
						1. 将自己push进path [可以实现一些逻辑, 例如自己是叶子, 就是打印]
						2. 将dfs(左), dfs(右) [这道题是先dfs(右)后dfs(左)]
						3. 最后恢复现场 
					2. 打印的时候:
						也就是遍历到了叶子, 现在path里面就是从root都其中一个叶子的路径
						打印完成之后, 没有return, 而是把叶子从path里pop掉, 然后去下一个叶子
					3. 这里的 dfs()是进入之后,往path插入本节点的信息, 而不是在dfs()参数中插入本节点的信息
				1. 如何判断大根堆小跟堆:
					就是设立两个gt和lt, 如果
					if (gt && lt) puts("Not Heap");
				    else if (gt) puts("Min Heap");
				    else puts("Max Heap");
			2. 注释
				1. y
					#include <iostream>
					#include <vector>

					using namespace std;

					const int N = 1010;

					int n;
					int h[N];
					bool gt, lt;
					vector<int> path;

					void dfs(int u)
					{
					    path.push_back(h[u]);
					    if (u * 2 > n)  叶节点
					    {
					        cout << path[0];
					        for (int i = 1; i < path.size(); i ++ )
					        {
					            cout << ' ' << path[i];
					            if (path[i] > path[i - 1]) gt = true;
					            else if (path[i] < path[i - 1]) lt = true;
					        }
					        cout << endl;  不加return是为了执行函数最后一行的恢复现场操作。
					    }

					    if (u * 2 + 1 <= n) dfs(u * 2 + 1);
					    if (u * 2 <= n) dfs(u * 2);

					    path.pop_back();
					}

					int main()
					{
					    cin >> n;
					    for (int i = 1; i <= n; i ++ ) cin >> h[i];

					    dfs(1);

					    if (gt && lt) puts("Not Heap");
					    else if (gt) puts("Min Heap");
					    else puts("Max Heap");

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/317791/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>
					#include <vector>

					using namespace std;

					const int N = 1010;
					int n, q[N];
					vector<int> path;
					bool gt, lt;


					void dfs(int u){
					    path.push_back(q[u]);
					    if(u * 2 > n) {
					        cout << path[0];
					        for(int i = 1; i < path.size(); i++){
					            cout << " " << path[i];
					            if(path[i] > path[i-1]) gt = true;
					            else if(path[i] < path[i-1]) lt = true;
					        }
					        cout << endl;
					    }
					    if(u * 2 + 1 <= n) dfs(u * 2 + 1);
					    if(u * 2 <= n) dfs(u * 2);
					    
					    path.pop_back();

					}
					int main(){
					    cin >> n;
					    for(int i = 1 ; i <= n ; i++) cin >> q[i];

					    dfs(1);
					    if(gt && lt) cout << "Not Heap" << endl;
					    else if(gt) cout << "Min Heap" << endl;
					    else cout << "Max Heap" << endl;
					    
					    return 0;


					}
				r2.
					#include <iostream>
					#include <vector>

					using namespace std;

					const int N = 1010;
					int n, q[N];
					vector<int> path;
					bool gt, lt;

					void print(){
					    cout << path[0];
					    for(int i = 1; i < path.size(); i++){
					        cout << " " << path[i];
					        if(path[i] > path[i-1]) lt = true;
					        else if(path[i] < path[i-1]) gt = true;
					    }
					    cout << endl;
					}

					void dfs(int u){
					    path.push_back(q[u]);
					    if(u * 2 > n) print();
					    if(u * 2 + 1 <= n) dfs(u * 2 + 1);
					    if(u * 2 <= n) dfs(u * 2);
					    path.pop_back();
					}

					int main(){
					    cin >> n;
					    for(int i = 1 ; i <= n; i++) cin >> q[i];
					    dfs(1);
					    if(gt && lt) cout << "Not Heap" << endl;
					    else if(gt) cout << "Max Heap" << endl;
					    else cout << "Min Heap" << endl;
					    
					}
				r3.
					#include <iostream>
					#include <vector>

					using namespace std;

					const int N = 1010;
					int n, q[N];
					vector<int> p;
					bool gt, lt;

					void print(){
					    cout << p[0];
					    for(int i = 1; i < p.size(); i++){
					        cout << " " << p[i];
					        if(p[i] > p[i-1]) gt = true;
					        else if(p[i] < p[i-1]) lt = true;
					    }
					    cout << endl;
					}

					void dfs(int u){
					    p.push_back(q[u]);
					    if(u * 2 > n) print();
					    if(u * 2 + 1 <= n) dfs(u * 2 + 1);
					    if(u * 2 <= n) dfs(u * 2);
					    p.pop_back();
					}

					int main(){
					    cin >> n;
					    for(int i = 1; i <= n; i ++) cin >> q[i];
					    dfs(1);
					    if(gt && lt) cout << "Not Heap" << endl;
					    else if(gt) cout << "Min Heap" << endl;
					    else cout << "Max Heap" << endl;
					    
					    return 0;
					}
				r4.
				r5.

		67. 1623. 中缀表达式	1130
			0. bug
			1. 笔记
				0. 很神奇
					1. 原来以前看到的中缀表达式, 就是递归的问题
					2. 其实就是将最底下的信息, 一层一层的递归
					3. 规律:
						1. dfs(自己)
							if(有左儿子) dfs(左儿子)
								如果左儿子是叶子, dfs(左儿子)返回的值不用加 "()"
									因为我们有(a*2.35), 而不是((a) * (2.35)), 其中a是*的左儿子, a是叶子
								如果左儿子不是叶子, dfs(左儿子)返回值需要加 "()"
							if(有右儿子) dfs(右儿子)
								逻辑同上
							返回给自己的父亲: 左儿子 + 自己 + 右儿子
						2. 这里没有用 终止条件, 因为如果没有左右儿子, 就会直接返回自己.

			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					const int N = 25;

					int n;
					int l[N], r[N];
					string w[N];
					bool st[N], is_leaf[N];

					string dfs(int u)
					{
					    string left, right;
					    if (l[u] != -1)
					    {
					        left = dfs(l[u]);
					        if (!is_leaf[l[u]]) left = "(" + left + ")";
					    }
					    if (r[u] != -1)
					    {
					        right = dfs(r[u]);
					        if (!is_leaf[r[u]]) right = "(" + right + ")";
					    }

					    return left + w[u] + right;
					}

					int main()
					{
					    cin >> n;
					    for (int i = 1; i <= n; i ++ )
					    {
					        cin >> w[i] >> l[i] >> r[i];
					        if (l[i]) st[l[i]] = true;
					        if (r[i]) st[r[i]] = true;

					        if (l[i] == -1 && r[i] == -1) is_leaf[i] = true;
					    }

					    int root = 1;
					    while (st[root]) root ++ ;

					    cout << dfs(root) << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/317794/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					const int N = 30;
					string num[N];
					int n, l[N], r[N];
					bool hf[N], isl[N];

					string dfs(int u){
					    string left, right;
					    if(l[u] != -1){
					        left = dfs(l[u]);
					        if(!isl[l[u]]) left = '(' + left + ')';
					    }
					    if(r[u] != -1){
					        right = dfs(r[u]);
					        if(!isl[r[u]]) right = '(' + right + ')';
					    }
					    return left + num[u] + right;
					}

					int main()
					{
					    cin >> n;
					    for(int i = 1; i <= n; i++){
					        cin >> num[i] >> l[i] >> r[i];
					        hf[l[i]] = true, hf[r[i]] = true;
					        if(l[i] == -1 && r[i] == -1) isl[i] = true;
					    }

					    int root = 1;
						while (hf[root]) root ++ ;

					    string res = dfs(root);
					    cout << res << endl;
					    return 0;
					}
				r2.
				r3.
				r4.
				r5.

		68. 1636. 最低公共祖先	1143
			0. bug
				1. 正确:
					int na = pos[a], nb = pos[b];
					错误:
						int na = pos.count(a), nb = pos.count(b);
			1. 笔记
				0.
					1. 离散化
						为什么需要离散化?
							1. 因为给的数字可能会很大, 不超过int, 说明可能是 10 ^9
								如果给了1000个很分散的数字, 你用哈希表去查, 也会很慢
							2. 所以把分散的数字映射到 0 ~ N-1, 然后用数组去装, 这样就会很快
						需要4个东西:
							1.
								1. 一个是原始的数字: seq[N]: 存原始的数字, 例如一个很大的数字
								2. 映射: 从原始数字, 到编号: pos[num] = i, 将这个原始数字num, 映射到0~N-1
									你会发现, 映射的时候, 最好都是从小到大的, 就是原始的数字小的话, 映射到的编号也比较小
									所以我们更愿意用中序遍历的顺序存原始数字
							2.
								3. 前序遍历的编号: pre[N]: 存的都是0 ~N-1的数字, 但是顺序是前序的顺序
								4. 中序遍历的编号: in[N]: 同上
						如何使用:
							1. 知道编号i, 求数字: seq[i];		其中pre[N], in[N]存的就是编号
							2. 知道数字num, 求编号: pos[num];
						输入:
							for (int i = 0; i < n; i ++ )
						    {
						        cin >> pre[i]; 存的是原始的num.
						        seq[i] = pre[i]; seq[]存的也是原始的num
						    }

						    sort(seq, seq + n); 将原始的num设置成中序
						    for (int i = 0; i < n; i ++ )
						    {
						        pos[seq[i]] = i; 这一步, 就是完成了离散化中的映射, 就是把一个值, 映射到了0~N-1
						        in[i] = i;
						    }

						    for (int i = 0; i < n; i ++ ) pre[i] = pos[pre[i]]; 现在前序遍历里面存的也是 0~N-1的编号
					2. build()	的时候, 求出了什么东西? p[N], depth[N]
						1. 每个节点的父亲: 因为后面是爬山法, 需要知道每个节点的父亲
							注意是 p[build()] = root;
						2. 每个节点的depth: 其中root的depth是0, 后面的儿子的depth+1 
							因为后面的爬山法, 需要知道谁比较深
						3. 爬山法, 三句话, 其中na和nb就是树中的节点编号. 我们能保证最后na == nb, 因为最差的情况会走到root
							while(na != nb){
				                if(d[na] >= d[nb]) na = p[na];
				                else nb = p[nb];
				            }
					2. 爬山法:
						谁在tree的底下, 就往自己的父亲爬
						结果三种情况:
							1. 两者都不等于原来的自己
								if (a != x && a != y) printf("LCA of %d and %d is %d.\n", seq[x], seq[y], seq[a]);
					            
							2. a不是原来的自己: 说明b是a的祖先
								else if (a == x) printf("%d is an ancestor of %d.\n", seq[x], seq[y]);
					            
							3. b不是原来的自己: 说明a是b的祖先
								else printf("%d is an ancestor of %d.\n", seq[y], seq[x]);
				1. 思路:
					1. 离散化存储
					2. build()的时候:
						1. 记得存当前节点的层数
						2. 记得更新儿子的父亲是自己
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 10010;

					int m, n;
					int in[N], pre[N], seq[N];
					unordered_map<int, int> pos;
					int p[N], depth[N];

					int build(int il, int ir, int pl, int pr, int d)
					{
					    int root = pre[pl];
					    int k = pre[seq[root]]; //或者: int k = root; 因为中序遍历的值(0~N-1)和下标是相等的, 因为in[i] = i;

					    depth[root] = d;

					    下面要表达的是: p[build(左儿子/右儿子)] = 自己root;
					    if (il < k) p[build(il, k - 1, pl + 1, pl + 1 + (k - 1 - il), d + 1)] = root;
					    if (k < ir) p[build(k + 1, ir, pl + 1 + (k - 1 - il) + 1, pr, d + 1)] = root;

					    return root;
					}

					int main()
					{
					    cin >> m >> n;
					    for (int i = 0; i < n; i ++ )
					    {
					        cin >> pre[i];
					        seq[i] = pre[i];
					    }

					    sort(seq, seq + n);
					    for (int i = 0; i < n; i ++ )
					    {
					        pos[seq[i]] = i; 这一步, 就是完成了离散化, 就是把一个值, 映射到了0~N-1
					    }

					    for (int i = 0; i < n; i ++ ){
					    	pre[i] = pos[pre[i]]; 现在前序遍历里面存的也是 0~N-1的编号
					    	in[i] = pos[seq[i]];
					    }


					    build(0, n - 1, 0, n - 1, 0);

					    while (m -- )
					    {
					        int a, b;
					        cin >> a >> b;

					        if (pos.count(a) && pos.count(b))
					        {
					            a = pos[a], b = pos[b];
					            int x = a, y = b;

					            while (a != b)
					                if (depth[a] < depth[b]) b = p[b];
					                else a = p[a];

					            if (a != x && a != y) printf("LCA of %d and %d is %d.\n", seq[x], seq[y], seq[a]);
					            else if (a == x) printf("%d is an ancestor of %d.\n", seq[x], seq[y]);
					            else printf("%d is an ancestor of %d.\n", seq[y], seq[x]);
					        }
					        else if (pos.count(a) == 0 && pos.count(b) == 0)
					            printf("ERROR: %d and %d are not found.\n", a, b);
					        else if (pos.count(a) == 0)
					            printf("ERROR: %d is not found.\n", a);
					        else
					            printf("ERROR: %d is not found.\n", b);
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/317814/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 10010;
					int pre[N], in[N], seq[N];
					unordered_map<int, int> pos;
					int p[N], depth[N];

					int build(int il, int ir, int pl, int pr, int d){
					    int root = pre[pl];
					    int k = root;

					    depth[root] = d; 
					    if(il < k) p[build(il, k - 1, pl + 1 , pl + 1 + ( k - 1 - il), d + 1)] = root;
					    if(k < ir) p[build(k + 1, ir, pl + 1 + (k - il), pr, d + 1)] = root;

					    return root;

					}


					int main(){
					    int m, n;
					    cin >> m >> n;
					    for(int i = 0; i < n; i++){
					        cin >> pre[i];
					        seq[i] = pre[i];
					    }

					    sort(seq, seq + n);
					    for(int i = 0 ; i < n; i ++){
					        pos[seq[i]] = i;
					        in[i] = i;
					    }

					    for(int i = 0; i < n; i++) pre[i] = pos[pre[i]];

					    int root = build(0, n-1, 0, n-1, 0);

					    while(m--){
					        int a, b;
					        cin >> a >> b;

					        if(pos.count(a) && pos.count(b)){
					            int na =  pos[a], nb = pos[b];
					            int x = na, y = nb;

					            while(na != nb){
					                if(depth[na] > depth[nb]) na = p[na];
					                else nb = p[nb];
					            }

					            if(na != x && nb != y) printf("LCA of %d and %d is %d.\n", seq[x], seq[y], seq[na]);
					            else if(na == x) printf("%d is an ancestor of %d.\n", seq[x], seq[y]);
					            else printf("%d is an ancestor of %d.\n", seq[y], seq[x]);
					        }
					        else if(!pos.count(a) && pos.count(b)) printf("ERROR: %d is not found.\n", a);
					        else if(pos.count(a) && !pos.count(b)) printf("ERROR: %d is not found.\n", b);
					        else printf("ERROR: %d and %d are not found.\n", a, b);
					    }

					    return 0;
					}
				r2.
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 100010;

					int pre[N], in[N], seq[N];
					unordered_map<int, int> pos;
					int d[N], p[N];
					int n, m;
					int a, b;


					int build(int il, int ir, int pl, int pr, int depth){
					    int root = pre[pl];
					    int k = pos[seq[root]];
					    
					    d[root] = depth;
					    if(il < k) p[build(il, k - 1, pl + 1, pl + 1 + (k - 1 - il), depth + 1)] = root;
					    if(k < ir) p[build(k + 1, ir, pl + 1 + ( k - il), pr, depth + 1)] = root;
					    
					    return root;
					    
					}


					int main(){
					    cin >> m >> n;
					    for(int i = 0 ; i < n; i++){
					        cin >> pre[i];
					        seq[i] = pre[i];
					    }
					    
					    sort(seq, seq + n);
					    for(int i = 0; i < n; i++){
					        pos[seq[i]] = i;
					    }
					    
					    for(int i = 0; i < n; i++){
					        pre[i] = pos[pre[i]];
					        in[i] = pos[seq[i]];
					    }
					    
					    int root = build(0, n-1, 0, n-1, 0);
					    
					    while(m--){
					        cin >> a >> b;
					        if(pos.count(a) && pos.count(b)){
					            int na = pos[a], nb = pos[b];
					            int x = na, y = nb;
					            
					            while(na != nb){
					                if(d[na] > d[nb]) na = p[na];
					                else nb = p[nb];
					            }
					            
					            if(na != x && nb != y) printf("LCA of %d and %d is %d.\n", a, b, seq[na]);
					            else if(na == x) printf("%d is an ancestor of %d.\n", a, b);
					            else printf("%d is an ancestor of %d.\n", b, a);
					        }
					        else if(!pos.count(a) && !pos.count(b)) printf("ERROR: %d and %d are not found.\n", a, b);
					        else if(!pos.count(a)) printf("ERROR: %d is not found.\n", a);
					        else printf("ERROR: %d is not found.\n", b);
					    }
					    return 0;
					}
				r3.
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 100010;
					int pre[N], in[N], d[N], p[N];
					int seq[N];
					unordered_map<int, int> pos;
					int n, m;
					int a, b;

					int build(int il, int ir, int pl, int pr, int depth){
					    int root = pre[pl];
					    int k = pos[seq[root]];
					    
					    d[root] = depth;
					    if(il < k){
					        int left = build(il, k - 1, pl + 1, pl + 1 + ( k - 1 - il), depth + 1);
					        p[left] = root;
					    }
					    if(k < ir) {
					        int right = build(k + 1, ir, pl + 1 + ( k - il), pr, depth + 1);
					        p[right] = root;
					    }
					    return root;
					}

					int main(){
					    cin >> m >> n;
					    for(int i = 0; i < n; i++){
					        cin >> pre[i];
					        seq[i] = pre[i];
					    }
					    
					    sort(seq, seq + n);
					    for(int i = 0; i < n; i++) pos[seq[i]] = i;
					    for(int i = 0; i < n; i++){
					        pre[i] = pos[pre[i]];
					        in[i] = pos[seq[i]];
					    }
					    
					    int root = build(0, n - 1, 0, n - 1, 0);
					    
					    while(m--){
					        cin >> a >> b;
					        if(pos.count(a) && pos.count(b)){
					            int na = pos[a], nb = pos[b];
					            int x = na, y = nb;
					            
					            while(na != nb){
					                 if(d[na] > d[nb]) na = p[na];
					                 else nb = p[nb];
					            }
					            
					            if(na != x && nb != y) printf("LCA of %d and %d is %d.\n", a, b, seq[na]);
					            else if(na == x) printf("%d is an ancestor of %d.\n", a, b);
					            else printf("%d is an ancestor of %d.\n", b, a);
					        }
					        else if(!pos.count(a) && !pos.count(b)) printf("ERROR: %d and %d are not found.\n", a, b);
					        else if(!pos.count(a)) printf("ERROR: %d is not found.\n", a);
					        else printf("ERROR: %d is not found.\n", b);
					        
					    }
					    return 0;
					}
				r4.
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 100010;
					int pre[N], in[N], p[N], d[N];
					unordered_map<int, int> pos;
					int seq[N];
					int n, m;
					int a, b;

					int build(int il, int ir, int pl, int pr, int depth){
					    int root = pre[pl];
					    int k =  pos[seq[root]];
					    d[root] = depth;
					    if(il < k){
					        int left = build(il, k - 1, pl + 1, pl + 1 + ( k - 1 - il), depth + 1);
					        p[left] = root;
					    }
					    if(k < ir){
					        int right = build(k + 1, ir, pl + 1 + ( k - il), pr, depth + 1);
					        p[right] = root;
					    }
					    return root;
					}

					int main(){
					    cin >> m >> n;
					    for(int i = 0; i < n; i++){
					        cin >> pre[i];
					        seq[i] = pre[i];
					    }
					    
					    sort(seq, seq + n);
					    for(int i = 0 ; i < n ; i++) pos[seq[i]] = i;
					    for(int i = 0; i < n; i++){
					        pre[i] = pos[pre[i]];
					        in[i] = pos[seq[i]];
					    }
					    
					    int root = build(0, n - 1, 0, n - 1, 0);
					    
					    while(m--){
					        cin >> a >> b;
					        if(pos.count(a) && pos.count(b)){
					            int na = pos[a], nb = pos[b];
					            int x = na, y = nb;
					            
					            while(na != nb){
					                if(d[na] >= d[nb]) na = p[na];
					                else nb = p[nb];
					            }
					            
					            if(na != x && nb != y) printf("LCA of %d and %d is %d.\n", a, b, seq[na]);
					            else if(na == x) printf("%d is an ancestor of %d.\n", a, b);
					            else printf("%d is an ancestor of %d.\n", b, a);
					        }
					        else if(!pos.count(a) && !pos.count(b)) printf("ERROR: %d and %d are not found.\n", a, b);
					        else if(!pos.count(a)) printf("ERROR: %d is not found.\n", a);
					        else printf("ERROR: %d is not found.\n", b);
					    }
					    
					    return 0;
					    
					}
				r5.

		69. 1644. 二叉树中的最低公共祖先	1151
			0. bug
			1. 笔记
				1. 同上题
				2. 但是这道题, 不是二叉搜索树, 所以离散化的步骤:
					cin >> m >> n;
				    for(int i = 0; i < n; i++){	题目显示给了中序输入
				        cin >> seq[i];	
				        pos[seq[i]] = i; 离散化: 总之就是value 和 编号
				        in[i] = i;
				    }
				    for(int i = 0; i < n; i++){ 题目显示给了pre序输入
				        cin >> pre[i];
				        pre[i] = pos[pre[i]];
				    }
				    
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>
					#include <unordered_map>

					using namespace std;

					const int N = 10010;

					int m, n;
					int in[N], pre[N], seq[N];
					unordered_map<int, int> pos;
					int p[N], depth[N];

					int build(int il, int ir, int pl, int pr, int d)
					{
					    int root = pre[pl];
					    int k = root;

					    depth[root] = d;

					    if (il < k) p[build(il, k - 1, pl + 1, pl + 1 + (k - 1 - il), d + 1)] = root;
					    if (k < ir) p[build(k + 1, ir, pl + 1 + (k - 1 - il) + 1, pr, d + 1)] = root;

					    return root;
					}

					int main()
					{
					    cin >> m >> n;

					    for (int i = 0; i < n; i ++ )
					    {
					        cin >> seq[i];
					        pos[seq[i]] = i;
					        in[i] = i;
					    }

					    for (int i = 0; i < n; i ++ )
					    {
					        cin >> pre[i];
					        pre[i] = pos[pre[i]];
					    }

					    build(0, n - 1, 0, n - 1, 0);

					    while (m -- )
					    {
					        int a, b;
					        cin >> a >> b;
					        if (pos.count(a) && pos.count(b))
					        {
					            a = pos[a], b = pos[b];
					            int x = a, y = b;
					            while (a != b)
					                if (depth[a] > depth[b]) a = p[a];
					                else b = p[b];

					            if (a != x && a != y) printf("LCA of %d and %d is %d.\n", seq[x], seq[y], seq[a]);
					            else if (a == x) printf("%d is an ancestor of %d.\n", seq[x], seq[y]);
					            else printf("%d is an ancestor of %d.\n", seq[y], seq[x]);
					        }
					        else if (pos.count(a) == 0 && pos.count(b) == 0)
					            printf("ERROR: %d and %d are not found.\n", a, b);
					        else if (pos.count(a) == 0)
					            printf("ERROR: %d is not found.\n", a);
					        else
					            printf("ERROR: %d is not found.\n", b);
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/317828/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1. TLE: 果然没有离散化就还是TLE
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					const int N = 10010;
					int in[N], pre[N], d[N], p[N];
					unordered_map<int, int> pos;
					int n, m;
					int a, b;

					int build(int il, int ir, int pl, int pr, int depth){
					    int root = pre[pl];
					    int k = pos[root];
					    d[root] = depth;
					    if(il < k){
					        int left = build(il, k - 1, pl + 1, pl + 1 + ( k -  1 - il), depth + 1);
					        p[left] = root;
					    }
					    if(k < ir){
					        int right = build(k + 1, ir, pl + 1 + ( k - il), pr, depth + 1);
					        p[right] = root;
					    }
					    return root;
					}

					int main(){
					    cin >> m >> n;
					    for(int i = 0; i < n; i++){
					        cin >> in[i];
					        pos[in[i]] = i;
					    }
					    for(int i = 0; i < n; i++) cin >> pre[i];

					    int root = build(0, n - 1, 0 , n - 1, 0);
					    
					    while(m--){
					        cin >> a >> b;
					        if(pos.count(a) && pos.count(b)){
					            int x = a, y = b;

					            while(a != b){
					                if(d[a] >= d[b]) a = p[a];
					                else b = p[b];
					            }

					          if(a != x && b != y) printf("LCA of %d and %d is %d.\n", x, y, a);
					            else if(a == x) printf("%d is an ancestor of %d.\n", x, y);
					            else printf("%d is an ancestor of %d.\n", y, x);
					        }
					        else if(!pos.count(a) && !pos.count(b)) printf("ERROR: %d and %d are not found.\n", a, b);
					        else if(!pos.count(a)) printf("ERROR: %d is not found.\n", a);
					        else printf("ERROR: %d is not found.\n", b);
					    }
					    return 0;

					}
				r2.
					#include <iostream>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 100010;
					int pre[N], in[N], p[N], d[N];
					unordered_map<int, int> pos;
					int seq[N];
					int n, m;
					int a, b;

					int build(int il, int ir, int pl, int pr, int depth){
					    int root = pre[pl];
					    int k =  pos[seq[root]];
					    d[root] = depth;
					    if(il < k){
					        int left = build(il, k - 1, pl + 1, pl + 1 + ( k - 1 - il), depth + 1);
					        p[left] = root;
					    }
					    if(k < ir){
					        int right = build(k + 1, ir, pl + 1 + ( k - il), pr, depth + 1);
					        p[right] = root;
					    }
					    return root;
					}

					int main(){
					    cin >> m >> n;
					    for(int i = 0; i < n; i++){
					        cin >> seq[i];
					        pos[seq[i]] = i;
					        in[i] = i;
					    }
					    for(int i = 0; i < n; i++){
					        cin >> pre[i];
					        pre[i] = pos[pre[i]];
					    }
					    
					    int root = build(0, n - 1, 0, n - 1, 0);
					    
					    while(m--){
					        cin >> a >> b;
					        if(pos.count(a) && pos.count(b)){
					            int na = pos[a], nb = pos[b];
					            int x = na, y = nb;
					            
					            while(na != nb){
					                if(d[na] >= d[nb]) na = p[na];
					                else nb = p[nb];
					            }
					            
					            if(na != x && nb != y) printf("LCA of %d and %d is %d.\n", a, b, seq[na]);
					            else if(na == x) printf("%d is an ancestor of %d.\n", a, b);
					            else printf("%d is an ancestor of %d.\n", b, a);
					        }
					        else if(!pos.count(a) && !pos.count(b)) printf("ERROR: %d and %d are not found.\n", a, b);
					        else if(!pos.count(a)) printf("ERROR: %d is not found.\n", a);
					        else printf("ERROR: %d is not found.\n", b);
					    }
					    
					    return 0;
					    
					}
				r3.
					#include <iostream>
					#include <unordered_map>

					using namespace std;
					const int N = 10010;
					int pre[N], in[N], d[N], p[N];
					unordered_map<int, int> pos;
					int seq[N];
					int n, m;
					int a, b;

					int build(int il, int ir, int pl, int pr, int depth){
					    int root = pre[pl];
					    int k = pos[seq[root]];
					    d[root] = depth;
					    if(il < k){
					        int left = build(il, k - 1, pl + 1, pl + 1 + ( k - 1 - il), depth + 1);
					        p[left] = root;
					    }
					    if(k < ir){
					        int right = build(k + 1, ir, pl + 1 + ( k - il), pr, depth + 1);
					        p[right] = root;
					    }
					    return root;
					}


					int main(){
					    cin >> m >> n;
					    for(int i = 0; i < n; i++){
					        cin >> seq[i];
					        pos[seq[i]] = i;
					        in[i] = i;
					    }
					    for(int i = 0; i < n; i++){
					        cin >> pre[i];
					        pre[i] = pos[pre[i]];
					    }
					    
					    int root = build(0, n - 1, 0, n - 1, 0);
					    
					    while(m--){
					        cin >> a >> b;
					        if(pos.count(a) && pos.count(b)){
					            int na = pos[a], nb = pos[b];
					            int x = na, y = nb;
					            
					            while(na != nb){
					                if(d[na] >= d[nb]) na = p[na];
					                else nb = p[nb];
					            }
					            
					            if(na != x && nb != y) printf("LCA of %d and %d is %d.\n", a, b, seq[na]);
					            else if(na == x) printf("%d is an ancestor of %d.\n", a, b);
					            else printf("%d is an ancestor of %d.\n", b, a);
					        }
					        else if(!pos.count(a) && !pos.count(b)) printf("ERROR: %d and %d are not found.\n", a, b);
					        else if(!pos.count(a)) printf("ERROR: %d is not found.\n", a);
					        else printf("ERROR: %d is not found.\n", b);
					    }
					    return 0;
					}
				r4.
				r5.

6. 图论
	
	16. 2020年11月4日16:25:10
		
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
		
		70. 849. Dijkstra求最短路 I 	模板题
			0. bug
			1. 笔记
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
			2. 注释
				1. y
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

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/308477/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
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
					            if (!st[j] && (t == -1 || dist[t] > dist[j]))
					                t = j;

					        if(t == n) break;
					        for (int j = 1; j <= n; j ++ )
					            {
					                //cout << "t : " << t <<" i: "<< i << " dist[t]: " <<dist[t] << "g[t][j]: " << g[t][j] <<endl; 
					                dist[j] = min(dist[j], dist[t] + g[t][j]);
					                 
					            }

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

			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		71. 850. Dijkstra求最短路 II 	模板题
			0. bug
			1. 笔记
				见注释
			2. 注释
				1. y
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
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		72. 1475. 紧急情况	1003
			0. bug
				1. 老师看到说城市编号是0开始的,所以用了int i = 0
					for(int i = 0; i < n; i++) cin >> w[i];
				2. 正确:
					int t = -1;
	        		for (int j = 0; j < n; j ++ )
			            if (!st[j] && (t == -1 || dist[t] > dist[j])) 是 !st[j]
			                t = j;
			        st[t] = true;
			        错误:
			        int t = -1;
	        		for (int j = 0; j < n; j ++ )
			            if (!st[t] && (t == -1 || dist[t] > dist[j])) 不是 !st[t]
			                t = j;
			        st[t] = true;
			    3. 记得初始为正无穷:
			    	memset(d, 0x3f, sizeof d);
			1. 笔记
				1. 
					spfa,bellman ford在pat不考
					1. spfa可以求最大值,可是不能用来计数,因为有些边会重复计数(某些边会被更新多次)
					2. 用dikjstra算法,pat经常考
					3. 如果点数是n在1000以下,可以用邻接矩阵. n>=1万,一定要用邻接表. n在中间值的话,自己衡量
					4. dijkstra
						1. 朴素版
							for(){for(){}}
							时间:O(n^2 + m)
							适合于边数不多的时候
								因为边数多的时候,m==n^2,O(n^2+n^2) ?
						2. 堆优化
							O(m*logn)
							适合于边数多的时候
								因为边数多的时候,m==n^2,O(n^2*logn)
				2. 
					1. d[][], 两个点之间的距离, 题目给的
					2. dist[], 某个点到起点的最短距离
					3. st[], 某个点是否计算/放松过它所有的临边
				3. for() 有n个点, 所以放松n次
					{
						for(){} 遍历n个点, 找到没有计算过dist[], 并且距离起点最近的点, 这个点是t

						for(){} 遍历n个点, 放松点t的所有临边, 并且给这些更新dist[邻点]

						st[t] = true; 说明已经计算/放松点t的所有临边
					}
				4, 考察了:
					1. 最短路, 最大权
					2. 最短路径的个数
				5. dijkstra():
					1. 在所有的点中, 找一个合适的灵魂
					2. 用这个灵魂, 更新其他的点
				6. 初始的变量:
					const int N = 1010;
					int n, m, S, T;			点边等
					int w[N], d[N][N];				input的值: 权重, 距离
					int dist[N], cnt[N], sum[N];	我们加工的: 最短距离, 最短路条数, 最大权值
					bool st[N];						dijkstra过程用到的
			2. 注释
				1. y
					#include <cstring>
					#include <iostream>

					using namespace std;

					const int N = 510;

					int n, m, S, T;
					int w[N], d[N][N];
					int dist[N], cnt[N], sum[N];
					bool st[N];

					void dijkstra()
					{
					    memset(dist, 0x3f, sizeof dist);
					    dist[S] = 0, cnt[S] = 1, sum[S] = w[S];

					    for (int i = 0; i < n; i ++ )
					    {
					        int t = -1;
					        for (int j = 0; j < n; j ++ )
					            if (!st[j] && (t == -1 || dist[t] > dist[j]))
					                t = j;
					        st[t] = true;

					        for (int j = 0; j < n; j ++ )
					            if (dist[j] > dist[t] + d[t][j])
					            {
					                dist[j] = dist[t] + d[t][j];
					                cnt[j] = cnt[t];
					                sum[j] = sum[t] + w[j];
					            }
					            else if (dist[j] == dist[t] + d[t][j])
					            {
					                cnt[j] += cnt[t];
					                sum[j] = max(sum[j], sum[t] + w[j]);
					            }
					    }
					}

					int main()
					{
					    cin >> n >> m >> S >> T;

					    for (int i = 0; i < n; i ++ ) cin >> w[i];

					    memset(d, 0x3f, sizeof d);
					    while (m -- )
					    {
					        int a, b, c;
					        cin >> a >> b >> c;
					        d[a][b] = d[b][a] = min(d[a][b], c);
					    }

					    dijkstra();

					    cout << cnt[T] << ' ' << sum[T] << endl;

					    return 0;
					}
				2. b
					#include <cstring>
					#include <iostream>

					using namespace std;

					const int N = 510;

					int n, m, S, T;
					int w[N]; 权重:点权
					int d[N][N]; 用了邻接矩阵
					int dist[N], cnt[N], sum[N]; 最短距离, 最短路的数量, 最大点权和
					bool st[N]; 某个点是否用过

					void dijkstra()
					{
					    memset(dist, 0x3f, sizeof dist); 起始都是正无穷
					    dist[S] = 0; 先初始化起点的距离, 也就是S到S点的最短距离==0
					    cnt[S] = 1; 从起点出发的路径只有一种
					    sum[S] = w[S]; 起点的点权就是w[起点]

					    for (int i = 0; i < n; i ++ ) 也是, 放松所有的点
					    {
					        int t = -1;
					        for (int j = 0; j < n; j ++ )
					            if (!st[j]当前的点j没有被用过 && (t == -1:还没有找到任何一个点|| dist[t] > dist[j] 当前的点j的距离更小))
					                t = j; 找到了更新其他店的点j,赋值给t
					        说明我们找到了目前为止, 没有计算过距离的所有点中, 到S点的最短距离的点: t. 因为dist[t]是全部没有计算过的点中, 最短的点
					        在第一次走到这里时,是i == 0, 也就是t应该是就是起点S, 因为所有的dist[j], 除了dist[S]==0, 都是正无穷

					        st[t] = true;

					        for (int j = 0; j < n; j ++ ) 遍历所有的其他点
					            if (dist[j] > dist[t] + d[t][j])	 dist[j]代表着从S到j点的最短距离
					            {
					                dist[j] = dist[t] + d[t][j];	
					                cnt[j] = cnt[t]; 			这个相当于是说,因为走到j现在是一条新的最短路径,这条路径个数是cnt[t]
					                sum[j] = sum[t] + w[j];
					            }
					            else if (dist[j] == dist[t] + d[t][j]) 又遇到了一个从S到j点的最短距离
					            {
					                cnt[j] += cnt[t]; 两个路径合并
					                sum[j] = max(sum[j], sum[t] + w[j]);  这个才是这道题的逻辑: 就是我们需要的是. 取最大的救援力量
					            }

					        第一次走到这里, 是i == 0, 也就是更新了起点S的所有临边, 所以这些邻点的dist[]都从正无穷更新到一个更小的值
					    }
					}

					int main()
					{
					    cin >> n >> m >> S >> T; 读入点,边,起点,终点

					    for (int i = 0; i < n; i ++ ) cin >> w[i]; 老师看到说城市编号是0开始的,所以用了int i = 0, 

					    memset(d, 0x3f, sizeof d); 刚开始距离都是正无穷
					    while (m -- )
					    {
					        int a, b, c;
					        cin >> a >> b >> c;
					        d[a][b] = d[b][a] = min(d[a][b], c); 无向图,存的是最短的权
					    }

					    dijkstra();

					    cout << cnt[T] << ' ' << sum[T] << endl;
					    输出:最短路的数量
					    如果有多个最短路,输出权值最大的最短路的权值

					    return 0;
					}
			3. 5次
				r1.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 510;
					int n, m, S, T;
					int w[N], d[N][N], dist[N];
					bool st[N];
					int cnt[N], sum[N];

					void dijkstra(){
					    memset(dist, 0x3f, sizeof dist);
					    dist[S] = 0;
					    cnt[S] = 1;
					    sum[S] = w[S];

					    for(int i = 0; i < n ; i++){
					        int t = -1;
					        for(int j = 0; j < n; j++){
					            if(!st[j] && (t == -1 || dist[j] < dist[t]))
					                t = j;
					        }

					        st[t] = true;
					        for(int j = 0; j < n; j++){
					            if(dist[t] + d[t][j] < dist[j]){
					                dist[j] = dist[t] + d[t][j];
					                cnt[j] = cnt[t];
					                sum[j] = sum[t] + w[j];
					            }else if(dist[t] + d[t][j] == dist[j]){
					                cnt[j] += cnt[t];
					                sum[j] = max(sum[j], sum[t] + w[j]);
					            }
					        }
					    }
					    
					}

					int main(){
					    cin >> n >> m >> S >> T;
					    for(int i = 0; i < n; i++) cin >> w[i];

					    memset(d, 0x3f, sizeof d);
					    for(int i = 0 ; i < m ; i++){
					        int a, b, c;
					        cin >> a >> b >> c;
					        d[a][b] = d[b][a] = min(d[a][b], c);
					    }
					    dijkstra();
					    cout << cnt[T] << " " << sum[T] << endl;
					    return 0;
					}
				r2.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 1010;
					int n, m, S, T;
					int d[N][N], w[N];
					int dist[N], cnt[N], sum[N];
					bool st[N];

					void dijkstra(){
					    memset(dist, 0x3f, sizeof dist);
					    dist[S] = 0;
					    cnt[S] = 1;
					    sum[S] = w[S];
					    
					    for(int i = 0; i < n; i++){
					        int t = -1;
					        for(int j = 0; j < n; j++){
					            if(!st[j] && (t == -1 || dist[j] < dist[t]))
					                t = j;
					        }
					        
					        st[t] = true;
					        for(int j = 0; j < n; j++){
					            if(dist[t] + d[t][j] < dist[j]){
					                dist[j] = dist[t] + d[t][j];
					                cnt[j] = cnt[t];
					                sum[j] = sum[t] + w[j];
					            }else if(dist[t] + d[t][j] == dist[j]){
					                cnt[j] += cnt[t];
					                sum[j] = max(sum[j], sum[t] + w[j]);
					            }
					        }
					    }
					}

					int main(){
					    cin >> n >> m >> S >> T;
					    for(int i = 0; i < n; i++) cin >> w[i];
					    
					    memset(d, 0x3f, sizeof d);
					    while(m--){
					        int a, b, c;
					        cin >> a >> b >> c;
					        d[a][b] = d[b][a] = min(d[a][b], c);
					    }
					    
					    dijkstra();
					    cout << cnt[T] << " " << sum[T];
					    return 0;
					}
				r3.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 1010;
					int n, m, S, T;
					int w[N], d[N][N];
					int dist[N], cnt[N], sum[N];
					bool st[N];
					int a, b, c;

					void dijkstra(){
					    dist[S] = 0;
					    cnt[S] = 1;
					    sum[S] = w[S];
					    
					    for(int i = 0; i < n; i++){
					        int t = -1;
					        for(int j = 0; j < n; j++){
					            if(!st[j] && (t == -1 || dist[j] < dist[t]))
					                t = j;
					        }
					        
					        st[t] = true;
					        for(int j = 0; j < n; j ++){
					            if(dist[t] + d[t][j] < dist[j]){
					                dist[j] = dist[t] + d[t][j];
					                cnt[j] = cnt[t];
					                sum[j] = sum[t] + w[j];
					            }else if(dist[t] + d[t][j] == dist[j]){
					                cnt[j] += cnt[t];
					                sum[j] = max(sum[j], sum[t] + w[j]);
					            }
					        }
					    }
					}

					int main(){
					    memset(d, 0x3f, sizeof d);
					    memset(dist, 0x3f, sizeof dist);
					    cin >> n >> m >> S >> T;
					    for(int i = 0 ; i < n ; i++) cin >> w[i];
					    while(m--){
					        cin >> a >> b >> c;
					        d[a][b] = d[b][a] = min(d[a][b], c);
					    }
					    
					    dijkstra();
					    cout << cnt[T] << " " << sum[T] << endl;
					    return 0;
					}
				r4.
					#include <iostream>
					#include <cstring>

					using namespace std;
					const int N = 1010;
					int n, m, S, T;
					int w[N], d[N][N];
					int dist[N], cnt[N], sum[N];
					bool st[N];
					int a, b, c;

					void dijkstra(){
					    dist[S] = 0;
					    cnt[S] = 1;
					    sum[S] = w[S];
					    
					    for(int i = 0; i < n ; i++){
					        int t = -1;
					        for(int j = 0; j < n; j++){
					            if(!st[j] && (t == -1 || dist[j] < dist[t]))
					                t = j;
					        }
					        
					        st[t] = true;
					        for(int j = 0; j < n; j++){
					            if(dist[t] + d[t][j] < dist[j]){
					                dist[j] = dist[t] + d[t][j];
					                cnt[j] = cnt[t];
					                sum[j] = sum[t] + w[j];
					            }else if(dist[t] + d[t][j] == dist[j]){
					                cnt[j] += cnt[t];
					                sum[j] = max(sum[j], sum[t] + w[j]);
					            }
					        }
					        
					        
					        
					    }
					}

					int main(){
					    memset(d, 0x3f, sizeof d);
					    memset(dist, 0x3f, sizeof dist);
					    cin >> n >> m >> S >> T;
					    for(int i = 0; i < n; i++) cin >> w[i];
					    while(m--){
					        cin >> a >> b >> c;
					        d[a][b] = d[b][a] = min(d[a][b], c);
					    }
					    
					    dijkstra();
					    cout << cnt[T] << " " << sum[T] << endl;
					    return 0;
					}
				r5.

		73. 1507. 旅行计划	1030
			0. bug
			1. 笔记
				1. 双关键字: 最短距离, 最小cost
					if (dist[j] > dist[t] + d[t][j]) 我们优先的是,dist更小的
		            {
		                dist[j] = dist[t] + d[t][j];
		                cost[j] = cost[t] + c[t][j]; 即便之前的cost小,也要放弃,因为现在的路更短
		                pre[j] = t; 记录路径
		            }
		            else if (dist[j] == dist[t] + d[t][j] && cost[j] > cost[t] + c[t][j]) 
		            	如果dist一样, 但是cost更小, 因为题目说: 首先输出从起点城市到终点城市的最短路径（花费最少的）经过的所有城市，
		            {
		                cost[j] = cost[t] + c[t][j];
		                pre[j] = t;
		            }
				2. 记录路径
					因为需要反向输出路径,所以依次插入vec,然后反向输出
				    vector<int> path;
				    for (int i = T; i != S; i = pre[i]) path.push_back(i); 插入了T,...,但是没有插入S

				    cout << S;
				    for (int i = path.size() - 1; i >= 0; i -- ) cout << ' ' << path[i]; 反向输出
				    cout << ' ' << dist[T] << ' ' << cost[T] << endl;
				3. 总结:
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
			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 510;

					int n, m, S, T;
					int d[N][N], c[N][N]; 记录临界矩阵,还有两个点之间的cost
					int dist[N], cost[N], pre[N];  dist是S点到n点的最短距离, cost是S点到n点的最小话费, pre是
					bool st[N]; 是否经过这个点

					你会发现, d, c, dist, cost这四个都会初始化为正无穷

					void dijkstra()
					{
					    memset(dist, 0x3f, sizeof dist);
					    memset(cost, 0x3f, sizeof cost); 初始化

					    dist[S] = 0, cost[S] = 0;
					    for (int i = 0; i < n; i ++ )
					    {
					        int t = -1;
					        for (int j = 0; j < n; j ++ )
					            if (!st[j] && (t == -1 || dist[t] > dist[j]))
					                t = j;
					        st[t] = true;

					        for (int j = 0; j < n; j ++ )
					            if (dist[j] > dist[t] + d[t][j]) 我们优先的是,dist更小的
					            {
					                dist[j] = dist[t] + d[t][j];
					                cost[j] = cost[t] + c[t][j]; 即便之前的cost小,也要放弃,因为现在的路更短
					                pre[j] = t; 记录路径
					            }
					            else if (dist[j] == dist[t] + d[t][j] && cost[j] > cost[t] + c[t][j]) 如果dist一样, 但是cost更小
					            {
					                cost[j] = cost[t] + c[t][j];
					                pre[j] = t;
					            }
					    }
					}

					int main()
					{
					    cin >> n >> m >> S >> T;
					    memset(d, 0x3f, sizeof d);
					    memset(c, 0x3f, sizeof c);

					    while (m -- )
					    {
					        int a, b, x, y;
					        cin >> a >> b >> x >> y; x:距离, y:话费
					        if (x < d[a][b])
					        {
					            d[a][b] = d[b][a] = x;
					            c[a][b] = c[b][a] = y;
					        }
					        else if (x == d[a][b] && y < c[a][b])
					        {
					            c[a][b] = c[b][a] = y;
					        }
					    }

					    dijkstra();

					    因为需要反向输出路径,所以依次插入vec,然后反向输出
					    vector<int> path;
					    for (int i = T; i != S; i = pre[i]) path.push_back(i); 插入了T,...,但是没有插入S

					    cout << S;
					    for (int i = path.size() - 1; i >= 0; i -- ) cout << ' ' << path[i]; 反向输出
					    cout << ' ' << dist[T] << ' ' << cost[T] << endl;

					    return 0;
					}
			3. 5次
				r1.
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 510;

					int n, m, S, T;
					int d[N][N], c[N][N];
					int dist[N], cost[N], pre[N];
					bool st[N];

					void dijkstra()
					{
					    memset(dist, 0x3f, sizeof dist);
					    memset(cost, 0x3f, sizeof cost);

					    dist[S] = 0, cost[S] = 0;
					    for (int i = 0; i < n; i ++ )
					    {
					        int t = -1;
					        for(int j = 0; j < n; j++){
					            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
					        }
					        st[t] = true;
					        for(int j = 0; j < n; j++){
					            if(dist[t] + d[t][j] < dist[j]){
					                dist[j] = dist[t] + d[t][j];
					                cost[j] = cost[t] + c[t][j];
					                pre[j] = t;
					            }else if(dist[t] + d[t][j] == dist[j] && cost[t] + c[t][j] < cost[j]){
					                cost[j] = cost[t] + c[t][j];
					                pre[j] = t;
					            }
					        }
					    }
					}

					int main()
					{
					    cin >> n >> m >> S >> T;
					    memset(d, 0x3f, sizeof d);
					    memset(c, 0x3f, sizeof c);

					    while (m -- )
					    {
					        int a, b, x, y;
					        cin >> a >> b >> x >> y;
					        if (x < d[a][b])
					        {
					            d[a][b] = d[b][a] = x;
					            c[a][b] = c[b][a] = y;
					        }
					        else if (x == d[a][b] && y < c[a][b])
					        {
					            c[a][b] = c[b][a] = y;
					        }
					    }

					    dijkstra();

					   vector<int> path;
					    for(int i = T; i != S; i = pre[i]) path.push_back(i);

					    cout << S;
					    for(int i = path.size() - 1; i >= 0; i--) cout << " " << path[i];
					    cout << " " << dist[T] << " " << cost[T] << endl;

					    return 0;
					}
				r2.
					#include <iostream>
					#include <vector>
					#include <cstring>

					using namespace std;

					const int N = 510;
					int d[N][N], c[N][N];
					int dist[N], cost[N], pre[N];
					bool st[N];
					int n, m, S, T;
					int a, b, x, y;

					void dijkstra(){
					    memset(dist, 0x3f, sizeof dist);
					    memset(cost, 0x3f, sizeof cost);
					    
					    dist[S] = 0;
					    cost[S] = 0;
					    
					    for(int i = 0; i < n; i++){
					        int t = -1;
					        for(int j = 0; j < n; j++){
					            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
					        }
					        
					        st[t] = true;
					        for(int j = 0; j < n; j++){
					            if(dist[t] + d[t][j] < dist[j]){
					                dist[j] = dist[t] + d[t][j];
					                cost[j] = cost[t] + c[t][j];
					                pre[j] = t;
					            }
					            else if(dist[t] + d[t][j] == dist[j] && cost[t] + c[t][j] < cost[j]){
					                cost[j] = cost[t] + c[t][j];
					                pre[j] = t;
					            }
					        }
					    }
					}

					int main(){
					    cin >> n >> m >> S >> T;
					    memset(d, 0x3f, sizeof d);
					    memset(c, 0x3f, sizeof c);

					    while(m--){
					        cin >> a >> b >> x >> y;
					        d[a][b] = d[b][a] = min(d[a][b], x);
					        c[a][b] = c[b][a] = min(c[a][b], y);
					    }
					    
					    dijkstra();
					    vector<int> p;
					    for(int i = T; i != S; i = pre[i]) p.push_back(i);
					    cout << S;
					    for(int i = p.size()-1; i >= 0; i--) cout << " " << p[i];
					    cout << " " << dist[T] << " " << cost[T] << endl;
					    return 0;
					}
				r3.
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 1010;
					int d[N][N], c[N][N];
					int dist[N], cost[N], pre[N];
					bool st[N];
					vector<int> p;
					int n, m, S, T;
					int a, b, x, y;

					void dijkstra(){
					    memset(dist, 0x3f, sizeof dist);
					    memset(cost, 0x3f, sizeof cost);
					    dist[S] = 0;
					    cost[S] = 0;
					    for(int i = 0; i < n; i++){
					        int t = -1;
					        for(int j = 0; j < n; j++){
					            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
					        }
					        
					        st[t] = true;
					        for(int j = 0; j < n ; j++){
					            if(dist[t] + d[t][j] < dist[j]){
					                dist[j] = dist[t] + d[t][j];
					                cost[j] = cost[t] + c[t][j];
					                pre[j] = t;
					            }else if(dist[t] + d[t][j] == dist[j] && cost[t] + c[t][j] < cost[j]){
					                cost[j] = cost[t] + c[t][j];
					                pre[j] = t;
					            }
					        }
					    }
					    
					    for(int i = T; i != S; i = pre[i]) p.push_back(i);
					    cout << S;
					    for(int i = p.size()-1; i >= 0; i--) cout << ' ' << p[i];
					    cout << ' ' << dist[T] << ' ' << cost[T] << endl;
					}

					int main(){
					    cin >> n >> m >> S >> T;
					    memset(d, 0x3f, sizeof d);
					    memset(c, 0x3f, sizeof c);
					    for(int i = 0; i < m; i++){
					        cin >> a >> b >> x >> y;
					        d[a][b] = d[b][a] = min(d[a][b], x);
					        c[a][b] = c[b][a] = min(c[a][b], y);
					    }
					    
					    dijkstra();
					    return 0;
					}
				r4.
				r5.

		only_one 74. 1518. 团伙头目 	1034
			0. bug
				1. 很容易错:
					错误:
						vector<string, int> res;
					正确:
						vector<pair<string, int>> res;
				2. 我的逻辑错了:
					正确: 一个连通分量的通话时长, 应该每一对人的通话, 而不是某个人的 total
						int dfs(int id){
						    st[id] = true;
						    int sum = 0;//int sum = total[id];
						    cnt.push_back(id);

						    vector<pair<int, int>> vec = rec[id];
						    for(auto item : vec){
						        sum += item.second;
						        int name = item.first;
						        if(!st[name]){
						            sum += dfs(name);
						        }
						    }

						    return sum;
						}
					错误:
						我弄成total了:
						int dfs(int id){
						    st[id] = true;
						    int sum = total[id]; //错误, 不应该是total
						    cnt.push_back(id);

						    vector<pair<int, int>> vec = rec[id];
						    for(auto item : vec){
						        //忘了写: sum += item.second;
						        int name = item.first;
						        if(!st[name]){
						            sum += dfs(name);
						        }
						    }

						    return sum;
						}
				3. 有时候for(int i : num) 和 for(int i = 0; i < num.size(); i++)
					的结果很容易写错:
					正确:
						for(int id : cnt){
			                if(total[id] > m){
			                    m = total[id]; 
			                    maxid = id;
			                }
			            }
			        错误:
			        	for(int id : cnt){
			                if(total[cnt[id]] > m){ //错了啊! 是total[id]
			                    m = total[cnt[id]]; //错了啊!
			                    maxid = id;
			                }
			            }
			1. 笔记
				1. 其实更多的考察,你是怎么储存数据的:
					1. 记录每个人的全部通话时间: total
					2. 记录每个人的: 对方是谁, 通话时长
				2. 老师没有用map
					其实你可以用离散化:
					byb:
					for(int i = 0; i < n; i++){
				        string x, y;
				        int c;
				        cin >> x >> y >> c;
				        if(mp.count(x) == 0) mp[x] = ++ ind; 
				        if(mp.count(y) == 0) mp[y] = ++ ind;
				        int a = mp[x] , b = mp[y];
				        names[a] = x, names[b] = y;
				        rec[a].push_back({b, c});
				        rec[b].push_back({a, c});
				        total[a] += c;
				        total[b] += c;
				    }
				    所以map里面一共有ind个数据
				    	for(int id = 1; id <= ind; id++){}
				3. 考察连通分量:
					1. 连通分量的权重和
					2. 连通分量中的所有元素, 所有元素谁的total最大
			2. 注释
				1. y
				2. b
					#include <cstring>
					#include <iostream>
					#include <vector>
					#include <algorithm>
					#include <unordered_map>

					using namespace std;

					int n, k;
					unordered_map<string, vector<pair<string, int>>> g; string:每个人, vector<pair<string, int>>: 和string人的通话时间int
					unordered_map<string, int> total; string人的总的通话时间total
					unordered_map<string, bool> st; 判重数组, 因为题目可能有环,为了防止重复搜,所以设置这个,每个点只搜索一次

					int dfs(string ver, vector<string> &nodes) 需要用引用&node. dfs()这里是深度遍历一个图
					{
					    st[ver] = true;
					    nodes.push_back(ver);

					    int sum = 0;
					    for (auto edge : g[ver]) edge就是vector<pair<string, int>> 中的其中一个pair<string,int>
					    {
					        sum += edge.second; 需要用+= 该节点的通过时长
					        string cur = edge.first; 去临边
					        if (!st[cur]) sum += dfs(cur, nodes); 需要用+=, 如果临边没有遍历过, 那就去临边
					    }

					    return sum;
					}

					int main()
					{
					    cin >> n >> k;
					    while (n -- )
					    {
					        string a, b;
					        int t;
					        cin >> a >> b >> t;
					        g[a].push_back({b, t}); 将点b和边t都存储
					        g[b].push_back({a, t});
					        total[a] += t;	a的总权值+t
					        total[b] += t;
					    }

					    vector<pair<string, int>> res; string是一个团队的头目,int是团队的人数
					    for (auto item : total) 遍历所有的人
					    {
					        string ver = item.first; 人
					        vector<string> nodes; 这个人所在的连通分量的所有的节点(人),会存到node里面
					        int sum = dfs(ver, nodes) / 2;  返回的是以ver所在的连通分量中的这个分量的全部权值
					        之后会解释,为什么:
					        	1. 为什么for (auto item : total) 遍历所有的人
					        		因为你从dfs的代码可以看出来,如果已经看到过的人,在dfs()中st[ver] == true的人,再经过(auto item : total)的时候,nodes.size() == 1,也就只有他自己
					        	2. 为什么sum /= 2
					        		因为在dfs()中,sum += edge.second;是不需要判断是否是st[ver]的
					        		只有判断是否要继续递归找的时候,才会判断是否是st[ver]的
					        		所以sum的确是加了2倍
					        		或者, 你思考一个例子: 假设最简单的情况, 就只有两个人打电话,通话时长是m
					        			那么用老师的方法, sum = 0, sum += m, sum += m. 最后的确是2m

					        if (nodes.size() > 2 && sum > k) 需要满足题目的要求: 大于等于3人, 大于k分钟
					        {
					            string boss = nodes[0]; 找到最大通话时长的人
					            for (string node : nodes)
					                if (total[boss] < total[node])
					                    boss = node;
					            res.push_back({boss, (int)nodes.size()}); 注意,需要转换成(int)
					        }
					    }

					    sort(res.begin(), res.end());

					    cout << res.size() << endl;
					    for (auto item : res) cout << item.first << ' ' << item.second << endl;

					    return 0;
					}
			3. 5次
				r1.
					#include <iostream>
					#include <vector>
					#include <unordered_map>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					unordered_map<string, int> total;
					unordered_map<string, bool> st;
					unordered_map<string, vector<pair<string, int>>> rec;
					vector<pair<string, int>> res;
					int n, k;
					int m;
					string ms;
					int clcnt;

					int dfs(string name, int& clcnt){
					    st[name] = true;
					    auto vec = rec[name];
					    int sum = total[name];
					    clcnt += 1;
					    if(sum > m){
					        m = sum;
					        ms = name;
					    }
					    for(auto& p :  vec){
					        string other = p.first;
					        if(!st[other]){
					            sum += dfs(other, clcnt);
					            // clcnt += 1;
					        }
					    }
					    return sum;
					}

					int main(){
					    cin >> n >> k;
					    string a, b;
					    int c;
					    for(int i = 0 ; i < n; i++){
					        cin >> a >> b >> c;
					        rec[a].push_back({b, c});
					        rec[b].push_back({a, c});
					        total[a] += c;
					        total[b] += c;
					    }

					    for(auto& item : total){
					        string name = item.first;
					        clcnt = 0;
					        m = -1;
					        ms = "";
					        int sum = dfs(name, clcnt) / 2;
					        if(sum > k && clcnt > 2){
					            res.push_back({ms, clcnt});
					        }
					    }
					    sort(res.begin(), res.end());
					    cout << res.size() << endl;
					    for(auto i : res) cout << i.first << ' ' << i.second << endl;
					    return 0;
					}
				r2. ***** byb: 离散化
					#include <iostream>
					#include <unordered_map>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 1010;
					int ind;
					unordered_map<string, int> mp;
					string names[N];
					unordered_map<int, vector<pair<int, int>>> rec;
					int total[N];
					bool st[N];
					int n, k;
					vector<int> cnt;
					vector<pair<string, int>> res;

					int dfs(int id){
					    st[id] = true;
					    int sum = 0;//int sum = total[id];
					    cnt.push_back(id);

					    vector<pair<int, int>> vec = rec[id];
					    for(auto item : vec){
					        sum += item.second;
					        int name = item.first;
					        if(!st[name]){
					            sum += dfs(name);
					        }
					    }

					    return sum;
					}

					int main(){
					    cin >> n >> k;
					    for(int i = 0; i < n; i++){
					        string x, y;
					        int c;
					        cin >> x >> y >> c;
					        if(mp.count(x) == 0) mp[x] = ++ ind;
					        if(mp.count(y) == 0) mp[y] = ++ ind;
					        int a = mp[x] , b = mp[y];
					        names[a] = x, names[b] = y;
					        rec[a].push_back({b, c});
					        rec[b].push_back({a, c});
					        total[a] += c;
					        total[b] += c;
					    }
					    
					    for(int id = 1; id <= ind; id++){

					        int sum = 0;
					        cnt.clear();
					        if(!st[id]){
					            sum = dfs(id) / 2;
					        }

					        int m = 0;
					        int maxid = -1;
					        if(cnt.size() >= 3 && sum > k){
					            for(int id : cnt){
					                if(total[id] > m){
					                    m = total[id]; //m = total[cnt[id]];
					                    maxid = id;
					                }
					            }
					            res.push_back({names[maxid], (int)cnt.size()});
					        }

					    }
					    

					    sort(res.begin(), res.end());
					    cout << res.size() << endl;
					    for(auto item : res){
					        cout << item.first << ' ' << item.second << endl;
					    }

					    return 0;
					}
				r3.
				r4.
				r5.

		75. 1577. 条条大路通罗马	1087
			0. bug
				1. cnt[j] += cnt[t]; 无论如何,都是多了cnt[t]条到j点的边, 这个不受信服度影响
					上面这一句,是写在下面的ifelse的外面. 
					if (cost[j] < cost[t] + w[j]){}
					else if (cost[j] == cost[t] + w[j]) {}
				2. 打印:
					正确:
						vector<int> p; 
					    for(int i = T; i != S; i = pre[i]) p.push_back(i);
					    cout << amt[T] << ' ' << dist[T] << ' ' << sum[T] << ' ' <<  int(sum[T] / cnt[T]) << endl;
					    cout << city[S];
					    for(int i = p.size()-1; i >= 0; i--) cout << "->" << city[p[i]];
					    cout << endl;
					错误: 错了两次 (微笑)
						 cout << city[S];
					    for(int i = p.size()-1; i >= 0; i--) cout << "->" << city[i]; 应该是city[p[i]];
					    cout << endl;

			1. 笔记
				1.
					考察很全面
						第一关键字: 最短路
						第二关键字: 最大点权
						第三关键字: 最大点权的前提下,点数最少
						路径输出
						映射:
							1. unordered_map<string,int>
			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <cstring>
					#include <unordered_map>
					#include <vector>

					using namespace std;

					const int N = 210;

					int n, m;
					int w[N]; 某个点的权重
					int d[N][N]; 点和点之间的距离
					bool st[N]; 是否遍历过
					int dist[N], cnt[N], cost[N], sum[N], pre[N];
					 最短距离，最短路数量，最大点权(幸福度)，最小点数, 最短路径的前一个点


					string city[N];
					unordered_map<string, int> mp; 将string城市名 映射成 编号1-N

					void dijkstra()
					{
					    memset(dist, 0x3f, sizeof dist);
					    dist[1] = 0, cnt[1] = 1; 应为起点城市没有幸福感, 所以sum[1]不需要初始化, 也就是算平均幸福度的时候, 不用除以初始城市

					    for (int i = 0; i < n; i ++ )
					    {
					        int t = -1; 也就是为灵魂t找到一个归宿j
					        for (int j = 1; j <= n; j ++ ) 不包括了j==0
					            if (!st[j] && (t == -1 || dist[t] > dist[j]))  t没有归宿 || j是更好的归宿
					                t = j;
					        st[t] = true;

					        for (int j = 1; j <= n; j ++ ) 不包括了j==0
					            if (dist[j] > dist[t] + d[t][j])
					            {
					                dist[j] = dist[t] + d[t][j]; t到j比之前的dist[j]更近
					                cnt[j] = cnt[t]; 路径数量更新成t的, 因为j和t是需要链接起来的两个城市
					                cost[j] = cost[t] + w[j]; 权重也边了
					                sum[j] = sum[t] + 1; 经过的节点数是sum[t]的基础上+1
					                pre[j] = t; 上一个节点是t
					            }
					            else if (dist[j] == dist[t] + d[t][j])
					            {
					                cnt[j] += cnt[t]; 无论如何,都是多了cnt[t]条到j点的边, 这个不受信服度影响
					                if (cost[j] < cost[t] + w[j]) 如果新的t到j的走法,幸福度更高. 那么我们肯定要走t->j的路
					                {
					                    cost[j] = cost[t] + w[j]; 更新信服度
					                    sum[j] = sum[t] + 1; 因为信服度更高,所以肯定是走t->j这条路,所以是经过的节点数是sum[t]的基础上+1
					                    pre[j] = t; 更新路径
					                }
					                else if (cost[j] == cost[t] + w[j]) 信服度相同
					                {
					                    if (sum[j] > sum[t] + 1) 看是否点数更少. 如果是true, 说明点数可以最小
					                    {
					                        sum[j] = sum[t] + 1; 更新点数
					                        pre[j] = t; 更新路径
					                    }
					                }
					                else
					                	不作为
					            }
					            else
					            	不作为
					    }
					}

					int main()
					{
					    cin >> n >> m >> city[1];
					    mp[city[1]] = 1;

					    for (int i = 2; i <= n; i ++ )
					    {
					        cin >> city[i] >> w[i];
					        mp[city[i]] = i; 建立映射
					    }

					    memset(d, 0x3f, sizeof d);
					    while (m -- )
					    {
					        string x, y;
					        int c;
					        cin >> x >> y >> c;
					        int a = mp[x], b = mp[y];
					        d[a][b] = d[b][a] = min(d[a][b], c); 双向边
					    }

					    dijkstra();

					    int T = mp["ROM"];
					    cout << cnt[T] << ' ' << dist[T] << ' ' << cost[T] << ' ' << cost[T] / sum[T] << endl;

					    vector<int> path;
					    for (int i = T; i != 1; i = pre[i]) path.push_back(i);

					    cout << city[1];
					    for (int i = path.size() - 1; i >= 0; i -- )
					        cout << "->" << city[path[i]];
					    cout << endl;

					    return 0;
					}

			3. 5次
				r1.
					#include <iostream>
					#include <unordered_map>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 210;
					int d[N][N], w[N];
					bool st[N];
					int dist[N], sum[N], cnt[N], pre[N], amt[N];
					int n, m;
					string city[N];
					unordered_map<string, int> mp;

					void dijkstra(){
					    memset(dist, 0x3f, sizeof dist);
					    int S = mp[city[0]];
					    dist[S] = 0, sum[S] = 0, cnt[S] = 0, pre[S] = -1, amt[S] = 1;
					    for(int i = 0; i < n; i++){
					        int t = -1;
					        for(int j = 0; j < n; j ++){
					            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
					        }
					        st[t] = true;
					        for(int j = 0; j < n ; j++){
					            if(dist[t] + d[t][j] < dist[j]){
					                dist[j] = dist[t] + d[t][j];
					                sum[j] = sum[t] + w[j];
					                cnt[j] = cnt[t] + 1;
					                amt[j] = amt[t];
					                pre[j] = t;
					            }else if(dist[t] + d[t][j] == dist[j]){
					                amt[j] += amt[t];
					                if(sum[t] + w[j] > sum[j]){
					                    sum[j] = sum[t] + w[j];
					                    cnt[j] = cnt[t] + 1;
					                    pre[j] = t;
					                }else if(sum[t] + w[j] == sum[j]){
					                    if(cnt[t] + 1 <  cnt[j]){
					                        cnt[j] = cnt[t] + 1;
					                        pre[j] = t;
					                    }
					                }
					            }
					        }
					    }
					    int T = mp["ROM"];
					    vector<int> p; 
					    for(int i = T; i != S; i = pre[i]) p.push_back(i);
					    cout << amt[T] << ' ' << dist[T] << ' ' << sum[T] << ' ' <<  int(sum[T] / cnt[T]) << endl;
					    cout << city[S];
					    for(int i = p.size()-1; i >= 0; i--) cout << "->" << city[p[i]];
					    cout << endl;
					}

					int main(){
					    cin >> n >> m >> city[0];
					    mp[city[0]] = 0;
					    for(int i = 1; i < n; i++){
					        cin >> city[i] >> w[i];
					        mp[city[i]] = i;
					    }

					    memset(d, 0x3f, sizeof d);
					    while(m--){
					        string x, y;
					        int c;
					        cin >> x >> y >> c;
					        int a = mp[x], b = mp[y];
					        d[a][b] = d[b][a] = min(d[a][b], c);
					    }

					    dijkstra();
					    return 0;

					}
				r2.
					#include <iostream>
					#include <unordered_map>
					#include <vector>
					#include <cstring>

					using namespace std;

					const int N = 210;
					int d[N][N], w[N];
					int dist[N], weight[N], pre[N], cnt[N], amt[N];
					string names[N];
					bool st[N];
					unordered_map<string, int> mp;
					int n, m;

					void dijkstra(){
					    memset(dist, 0x3f, sizeof dist);
					    dist[1] = 0, weight[1] = 0, amt[1] = 1;
					    for(int i = 1; i <= n; i++){
					        int t = -1;
					        for(int j = 1; j <= n; j++){
					            if(!st[j] && ( t == -1 || dist[j] < dist[t])) t = j;
					        }
					        st[t] = true;
					        for(int j = 1; j <= n; j++){
					            if(dist[t] + d[t][j] < dist[j]){
					                dist[j] = dist[t] + d[t][j];
					                weight[j] = weight[t] + w[j];
					                amt[j] = amt[t];
					                pre[j] = t;
					                cnt[j] = cnt[t] + 1;
					            }else if(dist[t] + d[t][j] == dist[j] ){
					                amt[j] += amt[t];
					                if(weight[t] + w[j] > weight[j]){
					                    weight[j] = weight[t] + w[j];
					                    cnt[j] = cnt[t] + 1;
					                    pre[j] = t; 
					                }else if(weight[t] + w[j] == weight[j]){
					                    if(cnt[t] + 1 < cnt[j])
					                    {
					                        cnt[j] = cnt[t] + 1;
					                        pre[j] = t;
					                    }
					                }
					            }
					        }
					    }

					    int T = mp["ROM"];
					    printf("%d %d %d %d\n", amt[T], dist[T], weight[T], (int)(weight[T] / cnt[T]));
					    vector<int> path;
					    for(int i = T; i != 1; i = pre[i]) path.push_back(i);
					    cout << names[1];
					    for(int i = path.size()-1 ; i >= 0; i--) cout << "->" << names[path[i]];
					    cout << endl;
					}

					int main(){
					    cin >> n >> m;
					    string start;
					    cin >> start;
					    mp[start] = 1;
					    names[1] = start;

					    string a;
					    int b;
					    memset(d, 0x3f, sizeof d);
					    for(int i = 2; i <= n; i++){
					        cin >> a >> b;
					        mp[a] = i;
					        names[i] = a;
					        w[i] = b;
					    }

					    string x, y;
					    while(m--){
					        cin >> x >> y >> b;
					        int o = mp[x], p = mp[y];
					        d[o][p] = d[p][o] = min(d[o][p], b);
					    }

					    dijkstra();
					    return 0;
					}
				r3.
				r4.
				r5.

		76. 1601. 在线地图 	1111
			0. bug
				1. 重新初始化st和pre
					memset(st, 0, sizeof st);
					memset(pre, 0, sizeof pre);
				2. 正确:
					int t = -1;
			        for(int j = 0; j < n; j++){
			            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
			        }
			        错误:
			        	int t = -1;
				        for(int j = 0; j < n; j++){
				            if(!st[j] && (t == -1 || dist[j] < dist[t] + d[t][j])) t = j; 千万不能加这一句 + d[t][j] 啊!
				        }

			1. 笔记
				0. 考察了:
					1. 双关键词查找路径
					2. 记录路径
				1. 如果两个vector的里面是int 或者 char
					可以直接用if(vec1 == vec2)判断相等
			2. 注释
				1. y
				2. b
					#include <cstring>
					#include <iostream>
					#include <vector>

					using namespace std;

					const int N = 510;

					int n, m, S, T;
					int d1[N][N], d2[N][N];
					int dist1[N], dist2[N], pre[N];
					bool st[N];

					 返回最小值int,路线string.pair<int, string> dijkstra(int d1[][N], int d2[][N], int type) 
					注意写法:int d1[][N], int d2[][N],但是老师解释:C++里函数参数为数组时，第一维的长度可以不写。
					另外, d1,d2在这个函数中是局部变量, 虽然有全局变量也叫d1,d2,但是优先局部变量
					{
					    memset(dist1, 0x3f, sizeof dist1);
					    memset(dist2, 0x3f, sizeof dist2);
					    memset(st, 0, sizeof st); 因为dijkstra需要调用两次, 所以需要重新设置st
					    dist1[S] = dist2[S] = 0;

					    for (int i = 0; i < n; i ++ )
					    {
					        int t = -1;
					        for (int j = 0; j < n; j ++ )
					            if (!st[j] && (t == -1 || dist1[t] > dist1[j]))
					                t = j;
					        st[t] = true;
					        for (int j = 0; j < n; j ++ )
					        {
					            int w;
					            if (type == 0) w = d2[t][j]; type == 0的时候, 第一权值也就是参数d1, 第二权值w是参数d2

					            else w = 1; 如果最快路线不唯一，则输出经过路口最少的那条路线（保证唯一）。

					            if (dist1[j] > dist1[t] + d1[t][j]) 第一个权值的比较
					            {
					                dist1[j] = dist1[t] + d1[t][j]; 这里的dist1, 是指的第一权值的dist, 也就是dist1[N]既可以是代表最短路,也可以代表最快路
					                dist2[j] = dist2[t] + w; 无条件更新第二个权值. 
					                如果第一个权值是 最短路线, 第二个权值 就是最快的路, w == d2[t][j]
					                如果第一个权值是 最块路线, 第二个权值 就是经过路口最少的,也就是经过边数最少的路, w == 1                
					                pre[j] = t;
					            }
					            else if (dist1[j] == dist1[t] + d1[t][j]) 第二个权值比较
					            {
					                if (dist2[j] > dist2[t] + w)
					                {
					                    dist2[j] = dist2[t] + w;
					                    pre[j] = t;
					                }
					            }
					        }
					    }

					    vector<int> path;
					    for (int i = T; i != S; i = pre[i]) path.push_back(i); 反向推入

					    pair<int, string> res; int是最短路是多长 或者 最快的路多块, string是路径
					    res.first = dist1[T]; 从dist里面找到dist1[T], 也就是S到T的最短路是多长 或者 最快的路多块
					    res.second = to_string(S); 将S从int变成string
					    for (int i = path.size() - 1; i >= 0; i -- )
					        res.second += " -> " + to_string(path[i]); 反向输出
					    return res;
					}

					int main()
					{
					    cin >> n >> m;

					    memset(d1, 0x3f, sizeof d1);
					    memset(d2, 0x3f, sizeof d2);

					    while (m -- )
					    {
					        int a, b, t, c, d;
					        cin >> a >> b >> t >> c >> d;
					        if (d1[a][b] > c) d1[a][b] = c, d2[a][b] = d;
					        else if (d1[a][b] == c && d2[a][b] > d) d2[a][b] = d;
					        if (!t)
					        {
					            if (d1[b][a] > c) d1[b][a] = c, d2[b][a] = d;
					            else if (d1[b][a] == c && d2[b][a] > d) d2[b][a] = d;
					        }
					    }

					    cin >> S >> T;

					    auto A = dijkstra(d1, d2, 0);
					    auto B = dijkstra(d2, d1, 1);

					    if (A.second != B.second) 如果两种路径不一样,两个都输出: 一个输出的最快(不唯一就输出边数最少的), 一个输出的最短(不唯一就输出最快的)
					    {
					        printf("Distance = %d: %s\n", A.first, A.second.c_str());
					        printf("Time = %d: %s\n", B.first, B.second.c_str());
					    }
					    else 路径相同
					    {
					        printf("Distance = %d; Time = %d: %s\n", A.first, B.first, A.second.c_str());
					    }

					    return 0;
					}
			3. 5次
				r1.
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 510;
					int d[N][N], c[N][N];
					int dist[N], cost[N], pre[N], cnt[N];
					bool st[N];
					vector<int> v1;
					vector<int> v2;
					int n, m;
					int S, T;
					int Dis, Time;

					string dij1(){
					    memset(dist, 0x3f, sizeof dist);
					    memset(cost, 0x3f, sizeof cost);
					    memset(st, 0, sizeof st);
					    dist[S] = 0, cost[S] = 0, pre[S] = -1;
					    for(int i = 0; i < n; i++){
					        int t = -1;
					        for(int j = 0; j < n; j++){
					            if(!st[j] && (t == -1 || dist[j] < dist[t])) t = j;
					        }
					        st[t] = true;
					        for(int j = 0; j < n; j++){
					            if(dist[t] + d[t][j] < dist[j]){
					                dist[j] = dist[t] + d[t][j];
					                cost[j] = cost[t] + c[t][j];
					                pre[j] = t;
					            }else if(dist[t] + d[t][j] == dist[j] && cost[t] + c[t][j] < cost[j]){
					                cost[j] = cost[t] + c[t][j];
					                pre[j] = t;
					            }   
					        }
					    }
					    for(int i = T; i != S; i = pre[i]) v1.push_back(i);
					    string res = to_string(S);
					    for(int i = v1.size() - 1; i >= 0; i --) res += (" -> " + to_string(v1[i]));
					    Dis = dist[T];
					    return res;
					}

					string dij2(){
					    memset(dist, 0x3f, sizeof dist);
					    memset(cost, 0x3f, sizeof cost);
					    memset(st, 0, sizeof st);
					    memset(pre, 0, sizeof pre);
					    dist[S] = 0, cost[S] = 0, pre[S] = -1, cnt[S] = 1;
					    for(int i = 0; i < n; i++){
					        int t = -1;
					        for(int j = 0; j < n; j++){
					            if(!st[j] && (t == -1 || cost[j] < cost[t])) t = j;
					        }
					        st[t] = true;
					        for(int j = 0; j < n; j++){
					            if(cost[t] + c[t][j] < cost[j]){
					                cost[j] = cost[t] + c[t][j];
					                cnt[j] = cnt[t] + 1;
					                pre[j] = t;
					            }else if(cost[t] + c[t][j] == cost[j] && cnt[t] + 1 < cnt[j]){
					                cnt[j] = cnt[t] + 1;
					                pre[j] = t;
					            }   
					        }
					    }
					    for(int i = T; i != S; i = pre[i]) v2.push_back(i);
					    Time = cost[T];
					    string res = to_string(S);
					    for(int i = v2.size() - 1; i >= 0; i --) res += (" -> " + to_string(v2[i]));
					    return res;
					}

					int main(){
					    cin >> n >> m;
					    memset(d, 0x3f, sizeof d);
					    memset(c, 0x3f, sizeof c);
					    while(m--){
					        int a, b, t;
					        int x, y;
					        cin >> a >> b >> t >> x >> y;
					        d[a][b] = min(d[a][b], x);
					        c[a][b] = min(c[a][b], y);
					        if(!t){
					            d[b][a] = min(d[b][a], x);
					            c[b][a] = min(c[b][a], y);
					        }
					    }
					    cin >> S >> T;
					    string res1 = dij1();
					    string res2 = dij2();

					    
					    if(v1 == v2)
					        printf("Distance = %d; Time = %d: %s\n", Dis, Time, res1.c_str());
					    else{
					        printf("Distance = %d: %s\n", Dis, res1.c_str());
					        printf("Time = %d: %s\n", Time, res2.c_str());
					    }
					    return 0;


					}
				r2.
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 510;
					int n, m;
					int d[N][N], c[N][N];
					int dist[N], cost[N], pre[N], cnt[N];
					bool st[N];
					int S, T;
					vector<int> v1;
					vector<int> v2;
					int dis, ti;

					void dijkstra1(){
					    memset(dist, 0x3f, sizeof dist);
					    memset(cost, 0x3f, sizeof cost);
					    dist[S] = 0, cost[S] = 0, pre[S] = -1;
					    for(int i = 0; i < n; i ++){
					        int t = -1;
					        for(int j = 0; j < n; j++){
					            if(!st[j] && ( t == -1 || dist[j] < dist[t])) t = j;
					        }

					        st[t] = true;
					        for(int j = 0; j < n; j++){
					            if(dist[t] + d[t][j] < dist[j]){
					                dist[j] = dist[t] + d[t][j];
					                cost[j] = cost[t] + c[t][j];
					                pre[j] = t;
					            }else if(dist[t] + d[t][j] == dist[j]){
					                if(cost[t] + c[t][j] < cost[j]){
					                    cost[j] = cost[t] + c[t][j];
					                    pre[j] = t;
					                }
					            }
					        }
					    }
					    for(int i = T; i != -1; i = pre[i]) v1.push_back(i);
					    dis = dist[T];
					}


					void dijkstra2(){
					    memset(dist, 0x3f, sizeof dist);
					    memset(cost, 0x3f, sizeof cost);
					    memset(pre, 0, sizeof pre);
					    memset(st, 0, sizeof st);

					    cost[S] = 0, pre[S] = -1, cnt[S] = 1;
					    for(int i = 0; i < n; i++){
					        int t = -1;
					        for(int j = 0; j < n; j++){
					            if(!st[j] && ( t == -1 || cost[j] < cost[t])) t = j; 
					        }
					        st[t] = true;
					        for(int j = 0; j < n; j++){
					            if(cost[t] + c[t][j] < cost[j]){
					                cost[j] = cost[t] + c[t][j];
					                pre[j] = t;
					            }else if(cost[t] + c[t][j] == cost[j] && cnt[t] + 1 < cnt[j]){
					                cnt[j] = cnt[t] + 1;
					                pre[j] = t;
					            } 
					        }
					    }

					    for(int i = T; i != -1; i = pre[i]) v2.push_back(i);
					    ti = cost[T];

					}

					string print(vector<int> v){
					    string res = "";
					    for(int i = v.size()-1; i >= 0; i--){
					        if(i == 0) res += to_string(v[i]);
					        else{
					            res += (to_string(v[i]) + " -> ");
					        }
					    }
					    return res;
					}
					int main(){
					    cin >> n >> m;
					    int a, b, t, x, y;
					    memset(d, 0x3f, sizeof d);
					    memset(c, 0x3f, sizeof c);
					    while(m--){
					        cin >> a >> b >> t >> x >> y;
					        d[a][b] = min(d[a][b], x);
					        c[a][b] = min(c[a][b], y);
					        if(!t){
					            d[b][a] = min(d[b][a], x);
					            c[b][a] = min(c[b][a], y);
					        }
					    }
					    cin >> S >> T;
					    dijkstra1();
					    dijkstra2();

					    string r1 = print(v1);
					    string r2 = print(v2);
					    if(v1 == v2){
					        printf("Distance = %d; Time = %d: %s\n", dis, ti, r1.c_str());
					    }
					    else{
					        printf("Distance = %d: %s\n", dis, r1.c_str());
					        printf("Time = %d: %s\n", ti, r2.c_str());
					    }
					    return 0;
					}
				r3.
				r4.
				r5.

	17. 2020年11月6日11:56:20

		77. 1615. 哈密顿回路	1122
			0. bug
				1. bug! 很简单的题目, 但是容易错.
					不要忘记判断是否每个点都走了一遍:
						1. 用st[node[i]] = true标记需要检测的nodes中走过的点
						2. 然后判断是否每个点都走了:
							正确:
							for(int i = 1; i <= n; i++){ //bug!!
						        if(!st[i]) return false;
						    }
						    错误:
						    for(int i = 1; i <= t; i++){ 不是t(nodes的个数), 而是n, 也就是图中点的个数
						        if(!st[i]) return false;
						    }
			1. 笔记
				1.
				 	哈密顿回路:
						1. 既然是回路:起点与终点相同
						2. 所有点走都一遍,都仅走一次
						3. 所以一共走了n+1个点,因为起点走了两次
						因为题目是给了路径, 所以我们还要判断路径是不是合法,也就是需要判断题目的两个点之间是否有边
						另外老师判断了复杂度,是可以在0.3s之内完成的
			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 210;

					int n, m;
					bool g[N][N], st[N];
					int nodes[N * 2];

					bool check(int cnt)
					{
					    if (nodes[0] != nodes[cnt - 1] 起点与终点不相同|| cnt != n + 1 是否一共走了n+1个点) return false;

					    memset(st, 0, sizeof st);
					    for (int i = 0; i < cnt - 1; i ++ )
					    {
					        st[nodes[i]] = true; 题目给的路径,都走了哪些点
					        if (!g[nodes[i]][nodes[i + 1]]) 判断题目的两个点之间是否有边
					            return false;
					    }

					    for (int i = 1; i <= n; i ++ )
					        if (!st[i]) 如果有一个点没有走过,就是false
					            return false;

					    这里没有判断每个点仅走一次是因为: 一共走了n+1个点, 如果有一个点没有走过, 说明另一个点走了几次

					    return true;
					}

					int main()
					{
					    cin >> n >> m;
					    while (m -- )
					    {
					        int a, b;
					        cin >> a >> b;
					        g[a][b] = g[b][a] = true;
					    }

					    int k;
					    cin >> k;
					    while (k -- )
					    {
					        int cnt;
					        cin >> cnt;
					        for (int i = 0; i < cnt; i ++ ) cin >> nodes[i]; 讲题目给的路径上的所有点输入

					        if (check(cnt)) puts("YES");
					        else puts("NO");
					    }

					    return 0;
					}
			3. 5次
				r1.
					#include <iostream>
					#include <cstring>

					using namespace std;
					const int N = 210;
					int n, m;
					bool g[N][N];
					int nodes[N * 2];
					bool st[N];

					bool check(int t){
					    if(t != n + 1) return false;
					    if(nodes[0] != nodes[t - 1]) return false;
					    
					    for(int i = 1; i <= n; i++){ //bug!!
					        if(!st[i]) return false;
					    }
					    
					    for(int i = 1; i < t; i++){
					        if(!g[nodes[i-1]][nodes[i]]) return false;
					    }
					    
					    return true;
					}

					int main(){
					    cin >> n >> m;
					    while(m--){
					        int a, b;
					        cin >> a >> b;
					        g[a][b] = g[b][a] = true;
					    }

					    int k;
					    cin >> k;
					    while(k--){
					        int t;
					        cin >> t;
					        memset(nodes, 0, sizeof nodes);
					        memset(st, 0, sizeof st);
					        for(int i = 0; i < t ; i++){
					            cin >> nodes[i];
					            st[nodes[i]] = true;
					        }
					        bool res = check(t);
					        if(res) cout << "YES" << endl;
					        else cout << "NO" << endl;
					    }
					    return 0;
					}
				r2.
				r3.
				r4.
				r5.

		78. 1619. 欧拉路径,一笔画问题	1126
			0. bug
				虽然很简单,可还是错了一些:
					1. 忘记这是无向图:
						记得g[a][b] = g[b][a] = true;
					2. dfs()遍历求得连通分量的所有节点个数:
						正确:
							int dfs(int u){
							    st[u] = true;
							    int res = 1;
							    for(int i = 1; i <= n; i++){
							        if(!st[i] && g[u][i]) res += dfs(i);
							    }
							    return res;
							}
						错误:
							for(int i = 1; i <= n; i++){
						        if(!st[u]) res += dfs(i); 忘记判断g[u][i], 并且st[u]也错了
						    }
			1. 笔记
				1. 
					欧拉:每条边只能走一次,一笔画问题
						1. 欧拉回路:图是连通的,所有点的degree是偶数
						2. 欧拉路径:图是连通的,有两个点的degree是奇数,其余的点的degree是偶数
						3. 非欧拉:
							1. 图不连通,
							2. 或者图是连通的, 但是1个点,2个点或 3个以上点 的degree是奇数

					图的连通:1. dfs 2.并查集
			2. 注释
				1. y
				2. b
					#include <cstring>
					#include <iostream>

					using namespace std;

					const int N = 510;

					int n, m;
					bool g[N][N], st[N];
					int d[N];

					int dfs(int u)
					{
					    st[u] = true;

					    int res = 1; 因为一旦走入了dfs(u),就要把u这个点的个数算上, 所以是res = 1
					    for (int i = 1; i <= n; i ++ ) 题目说了是编号是1-N,所以从1开始
					        if (!st[i] && g[u][i]) 遍历临点,而且是没有走过的临点
					            res += dfs(i);

					    return res;
					}

					int main()
					{
					    cin >> n >> m;
					    for (int i = 0; i < m; i ++ )
					    {
					        int a, b;
					        cin >> a >> b; a,b的值都是>=1的,因为题目说了所有点的编号从 1∼N。
					        g[a][b] = g[b][a] = true;
					        d[a] ++, d[b] ++ ; a和b的degree都要++,即便题目输入了两次a,b我们认为ab之间有平行边,同样degree依旧要++
					    }

					    int cnt = dfs(1); 返回的是节点1开始走的连通分量的节点个数, 题目说了是编号是1-N,所以dfs(1)

					    cout << d[1];
					    for (int i = 2; i <= n; i ++ ) cout << ' ' << d[i];
					    cout << endl;

					    if (cnt == n) 图是连通的: 因为只有当每个点都遍历到了, 一个不多一个不少, 才能说是连通的. 一个不多(用st[u]保证,只能走一次), 一个不少(如果少了就说明不连通)
					    {
					        int s = 0; s是计算degree是奇数的点的个数
					        for (int i = 1; i <= n; i ++ )
					            if (d[i] % 2)
					                s ++ ; 

					        if (s == 0) puts("Eulerian");
					        else if (s == 2) puts("Semi-Eulerian");
					        else puts("Non-Eulerian");
					    }
					    else puts("Non-Eulerian"); 说明不连通

					    return 0;
					}

			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					const int N = 510;
					int d[N];
					bool g[N][N];
					int n, m;
					bool st[N];

					int dfs(int u){
					    st[u] = true;
					    int res = 1;
					    for(int i = 1; i <= n; i++){
					        if(!st[i] && g[u][i]) res += dfs(i);
					    }
					    return res;
					}

					int main(){
					    cin >> n >> m;
					    int a, b;
					    while(m--){
					        cin >> a >> b;
					        g[a][b] = g[b][a] = true;
					        d[a]++;
					        d[b]++;
					    }

					    int sum = dfs(1);

					    cout << d[1];
					    for(int i = 2; i <= n; i ++)
					        cout << ' ' << d[i];
					    cout << endl;

					    if(sum != n){
					        cout << "Non-Eulerian" << endl;
					    }else{
					        int is = 0;
					        for(int i = 1; i <= n; i++){
					            if(d[i] % 2) is ++;
					        }
					        if(is == 0) cout << "Eulerian" << endl;
					        else if(is == 2) cout << "Semi-Eulerian" << endl;
					        else cout << "Non-Eulerian" << endl;
					    }
					    return 0;
					}
				r2.
				r3.
				r4.
				r5.

		none 79. 1624. 地铁地图	1131
			0. bug
			1. 笔记
				1. 
					0. 这道题的一个技巧在于, 
					1. 整个地图是一个连通图,但是连通图里面的每个边也是有区别的,就是line线路的区别
					2. 题目是想少换乘,所以希望是在同一个line上
					3. 老师的加工在于,将同一个line上的所有点都两两链接了.
						但是这不代表成为了稠密图
						因为我们一共有n个点, 假设5条线的点数是abcde, 那么a+b+c+d+e == n
						稠密图是n里面所有点两两链接, 因为n是1w(见下), 所以稠密图是10^8条边, 但是我们只有100w条边(见下), 所以是稠密图的百分之一,属于稀疏图
						但是现在只是a,b,c,d,e分别地两两链接,并没有成为稠密图
					4. 这样的话,少换乘,就可以变成:经过的节点较少的边,因为两两链接之后,可以同一个线路上的点a跨到点z(因为链接了)

				1. 时间复杂度
					首先看规模:
						1. 最多100个line,每个line最多100个站
						2. 所以最多100*100个站点,也就是1w个点
						3. 每个line的站点可以链接100*99/2条边, 一共100个line,所以总共差不多100w条边(老师说100w不算多, 因为题目是0.4s, 我们允许千万级别的边)
					如果是朴素dijkstra
						1. n^2+m 是10^8, 因为站点有1w == 10^4个, 会超时, 因为题目限制了0.4s
					如果是堆优化:
						1. m*logn, 也就是100w * 一个常数, 可以在0.4s完成
				2. 空间复杂度
					用邻接矩阵是不可以的: 因为有1w个点,需要开1w*1w的矩阵, 10^8, 用bool存是100MB, 超出了范围
					用邻接表是可以的: 因为有100w条边,假设用bool存, 100w == 10^6 == 1MB(因为1M == 10^6)

				3. 老师debug:
					1. 用exit(0),判断到exit(0)的位置之前,有没有报错
			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <cstring>
					#include <queue>

					#define x first  在使用pair的时候,喜欢用xy来代替first,second
					#define y second

					using namespace std;

					typedef pair<int, int> PII;

					const int N = 10010, M = 1000010;

					int n;
					int h[N], e[M], w[M], line[M] M边是属于第几号线, ne[M], idx; 用邻接表
					int dist[N], cnt[N] 走过的边的数量 , pre[N];
					int stops[N];
					string info[N]; 从哪个线路过来的, 从线路的哪个点到哪个点
					bool st[N];

					string get_number(int x) 假设x是站点987, 但是我们需要输出的是0987
					{
					    char res[5];
					    sprintf(res, "%04d", x);
					    return res;
					}

					string get_number2(int x){
						string res = to_string(x)
						while(res.size() < 4) res = '0' + res; 注意是while
						return res;
					}
					void add(int a, int b, int c, int id)
					{
						你的a是站点标号999
						你通过h[a]获得了token:idx
						通过idx可以知道e[idx],也就是999可以前往的其他站点号例如888
						通过idx可以知道w[idx],也就是999到888的距离(也就是我们站点间隔:min(j - k, m - 1 - j + k);), 注意是只有999到888,如果是999到其他例如777的话是其他的token
					    通过idx还可以知道999所属的line
					    e[idx] = b, (w[idx] = c, line[idx] = id), ne[idx] = h[a], h[a] = idx ++ ;
					}

					双关键词找路径:
					1. 第一关键词, 两个站点的距离: 也就是min(j - k, m - 1 - j + k);
					2. 距离相同, 找较少换乘的: 
					void dijkstra(int start, int end)
					{
					    memset(dist, 0x3f, sizeof dist);
					    memset(cnt, 0x3f, sizeof cnt); 因为我们要找最少换乘的,所以先设置成正无穷
					    memset(st, 0, sizeof st);

					    priority_queue<PII, vector<PII>, greater<PII>> heap; 小根堆,所以先退出距离某个站点最近的站点
					    heap.push({0, start}); 加入n到起点的距离, 加入起点的临点n, 这里是初始化,所以n是起点,起点到起点的距离是0
					    dist[start] = cnt[start] = 0; 是start点的cnt:走过的边的数量 初始为0

					    我喜欢老师这个debug的方法, 在这里: int iii = 0;
					    while (heap.size())
					    {
					        auto t = heap.top(); 堆顶
					        heap.pop();

					        int ver = t.y; ver是站点标号999
					        if (ver == end) break;
					        if (st[ver]) continue;
					        st[ver] = true;

					        if(++ iii > 3) exit(0); 我喜欢老师这个debug的方法, 也就是while走了3次就会break

					        for (int i = h[ver]; ~i; i = ne[i]) ~i 是 i == -1
					        {
					            int j = e[i]; j也就是站点999的可到达站点888
					            if (dist[j] > dist[ver] + w[i]) 第一关键词: w[i]是999和888之间的距离: min(j - k, m - 1 - j + k);
					            {
					                dist[j] = dist[ver] + w[i];
					                cnt[j] = cnt[ver] + 1; 因为有更近的,所以即便要换乘,也是无条件的换
					                						cnt是处理换乘逻辑的
											                换乘的举例:
											                假设一共4个线路, abcd是一个, ax是一个, xy是一个, yd是一个
											                	   x --> y 
											                	/			\   
											                 a --> b --> c --> d
											                 两种方法的距离都是一样的: abcd, axyd
											                 但是其中abcd不需要换乘: 也就时cnt[d] = cnt[a] + 1 == 0 + 1 == 1, 因为建图的时候就已经存在一条ad直接连通的线了, 但是
											                 但是我们将来计算axyd的时候, 因为是属于3条不同的线路, 所以ax虽然可以cnt[x] == 1,但是走xy的时候, cnt一定是增加的, 所以不会考虑xy这个走法
					                pre[j] = ver;

					                info[j] = "Take Line#" + to_string(line[i]) + " from " + 
					                    get_number(ver) + " to " + get_number(j) + "."; 之所以这么写,是因为我们默认现在求到的就是最后路径打印的一部分.
					                
					                heap.push({dist[j], j}); 将距离push进去, 还有临点jpush进去
					                因为第一判断条件:距离dist[j]更新了,所以需要push到heap中
					            }
					            else if (dist[j] == dist[ver] + w[i]) 
					            {
					                if (cnt[j] > cnt[ver] + 1)
					                {
					                    cnt[j] = cnt[ver] + 1;
					                    pre[j] = ver;
					                    info[j] = "Take Line#" + to_string(line[i]) + " from " + 
					                        get_number(ver) + " to " + get_number(j) + ".";
					                }
					                else
					            	不作为

					                因为第一判断条件没有变,所以不需要push到heap
					            }
					            else
					            	不作为
					        }
					    }

					    cout << dist[end] << endl;
					    vector<string> path;
					    for (int i = end; i != start; i = pre[i])
					        path.push_back(info[i]);

					    for (int i = path.size() - 1; ~i; i -- )
					        cout << path[i] << endl;
					}

					int main()
					{
					    cin >> n;
					    memset(h, -1, sizeof h); 邻接表清空
					    for (int i = 1; i <= n; i ++ ) n是线路line数
					    {
					        int m;
					        cin >> m;
					        for (int j = 0; j < m; j ++ ) cin >> stops[j]; 一个线路里面的每个站点,每次更新for(i++)后,stop会从stop[0]开始更新

					        for (int j = 0; j < m; j ++ )
					            for (int k = 0; k < j; k ++ ) 这里是k < j,也就是四个点会连6条边,0+1+2+3=6,4个点,6条边
					            {
					                int len;
					                if (stops[0] != stops[m - 1]) len = j - k;
					                else len = min(j - k, m - 1 - j + k);
					                图像是这样的:
					                0 -a-> k ----b---> j -c-> m-1
					                所以b段是J-k, c段是m-1-j + (k-0) = m-1-j+k
					                min(j - k, m - 1 - j + k);

					                add(stops[j], stops[k], len, i); stop[i]是站点号,例如999, len是2者间隔,然后i是line数
					                add(stops[k], stops[j], len, i); 双向边
					            }
					    }

					    int k;
					    cin >> k;
					    while (k -- )
					    {
					        int start, end;
					        cin >> start >> end;
					        dijkstra(start, end);
					    }

					    return 0;
					}

			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		80. 1627. 顶点覆盖	1134
			0. bug
				1. 记得bool st[N]每一轮询问都要初始化
					memset(st, 0, sizeof st);
			1. 笔记
				1.
					1. 题目要求的是能否覆盖所有边的点, 什么意思呢?
						举例:	
							2,3,4,5构成了一个环, 然后2和6链接, 5和7链接
								看上去像个机器人,一个环+两个触角
								所以2,3,4,5就是覆盖所有边的
							2,3,4,5构成了一个环, 2和6链接, 5和7链接, 7和8链接
								看上去像个机器人,一个环+一个短触角+一个长触角
								2,3,4,5不能覆盖所有的边,例如78之间的边就不能覆盖
					2. 思路:
						1. 遍历所有的边, 看是否边的两个端点, 至少有一个在题目给的点集合李曼
					3. 复杂度:
						1. 遍历所有边: 一共有1w条边
						2. 一共100次询问
						3. 总共100*1w = 100w的复杂度
						4. 这个复杂度很低, 老师说,不涉及最短路的复杂度都很低
				2. 其实很简单, 但是注意两点:
					1. 我们的宗旨: 遍历所有的边, 然后看下边的两个端点是否在test的测试顶点中
					2. 看上去需要用set, 但是其实只需要用一个bool st[N]就好了
			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 10010;

					int n, m;
					struct Edge
					{
					    int a, b;
					}e[N];
					bool st[N];

					int main()
					{
					    cin >> n >> m;
					    for (int i = 0; i < m; i ++ ) cin >> e[i].a >> e[i].b;

					    int k;
					    cin >> k;
					    while (k -- )
					    {
					        int cnt;
					        cin >> cnt;

					        memset(st, 0, sizeof st);
					        while (cnt -- )
					        {
					            int x;
					            cin >> x;
					            st[x] = true;
					        }

					        int i;
					        for (i = 0; i < m; i ++ )
					            if (!st[e[i].a] && !st[e[i].b])  这道题默认我们的集合是对的, 如果发现两个端点都不满足就是false
					                break;

					        if (i == m) puts("Yes");
					        else puts("No");
					    }

					    return 0;
					}
			3. 5次
				r1.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 10010;

					struct edge{
					    int a, b;
					}edges[N];

					int n, m;
					bool st[N];

					int main(){
					    cin >> n >> m;
					    for(int i = 0; i < m; i++){
					        cin >> edges[i].a >> edges[i].b;
					    }
					    int k;
					    cin >> k;
					    while(k--){
					        int c;
					        cin >> c;
					        int t;
					        memset(st, 0, sizeof st);
					        while(c--){
					            cin >> t;
					            st[t] = true;
					        }
					        bool res = true;
					        for(int i = 0; i < m; i++){
					            if(!st[edges[i].a] && !st[edges[i].b]){
					                res = false;
					                break;
					            }
					        }
					        if(res) cout << "Yes" << endl;
					        else cout << "No" << endl;
					    }
					    return 0;
					}
				r2.
				r3.
				r4.
				r5.

		81. 1632. 第一次接触	1139
			0. bug
				这道题还是挺顺的..
				不过有几个容易错的:
					1. 最好用string读每个名
					2. 判断是否是女生:
						a[0] == '-' 或者 a.size() == 5
					3. names[N] 最好存的是不带有'-'的名字, 因为输出的时候不需要'-'
					4. 判断从哪个vector boys还是girl取出答案:
						vector<int> v1 = boys, v2 = boys; 先默认成boy, 然后再改
				        if(a.size() == 5) v1 = girls;
				        if(b.size() == 5) v2 = girls;
				    5. 记得排序:
				    	sort(res.begin(), res.end());
				    6. 我用add()逻辑, 所以没有用老师的删除重复元素:
				    	byb: 
				    	int add(string a){
						    if(a[0] == '-'){
						        if(mp.count(a) == 0){
						            mp[a] = ++ ind;
						            names[ind] = a.substr(1);
						            girls.push_back(ind);
						        }
						    }else{
						        if(mp.count(a) == 0){
						            mp[a] = ++ ind;
						            names[ind] = a;
						            boys.push_back(ind);
						        }
						    }
						    return mp[a];
						}

			1. 笔记
				1.
					1. 题目要求的: 找出两个人c,d; 构造出a,c,d,b的关系
					2. ac一定是同性, db一定是同性. cd同不同性根据题目给出的ab同不同性
					3. 复杂度:
						时间
							1. 因为一共存在300个人,所以a找c,有300种找法
							2. c找d也有300种找法(d需要满足是c的朋友 && b的朋友)
							3. 100次询问, 所以是300*300*100 = 9w次运算, 时间复杂度低
						空间
							1. 因为最多300人,所以可以通过邻接矩阵求
					4. 这道题困难的地方在于处理输入输出
						1. 首先,输入的是4位数编号, 而不是1-N的标号, 
							老师用哈希表存了4位数编号到1-N编号的映射
							同时用num[]存了从1-N标号到4位数编号的映射, 因为题目输出是4位数编号
						2. 应该采用string读入4位编号,而不是用int读入4位编号
							1. 因为存在-0000, 如果用int读的话, 不会读成-0, 可能会读成0, 就无法判断性别
						3. 老师用了两个vec来存男女的数据

					5. 总结:
						1. 哈希表: 通过无性别4数, 得到1-N
						2. num[]: 通过1-N, 获得无性别4数, 因为题目要求的数无性别的输出
						3. g[][]: ind采用1-N编号
						4. vec<int> 男女: int就是1-N编号
					6. 所以:
						1. 如果输入不恶心的话, 就直接当做普通题目处理, 只需要g[][], vec<int> boy, vec<int> girl
						2. 但是题目输入恶心, 所以需要我们从4位数判断是男是女, 还需要映射到1-N, 还需要从1-N映射回来
				2. 这道题: 想清楚了就不难.
					1. 其实就是找到距离为1的方法, 也就只有一个牵线搭桥的人
					2. 不过我们需要将人分成两种: boys 和 girls
					3. 然后是在这两个类中 判断是否g[a][b] == true 
				3. 输入如果需要删除重复元素:
					sort(boys.begin(), boys.end()); 
					boys.erase(unique(boys.begin(), boys.end()), boys.end()); 删掉重复元素
			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <cstring>
					#include <unordered_map>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 310;

					int n, m;
					unordered_map<string, int> mp; 哈希表存了4位数编号到1-N编号的映射
					string num[N]; num[]存了从1-N标号到4位数编号的映射, 因为题目输出是4位数编号
					int id; 1-N编号
					bool g[N][N]; 邻接矩阵
					vector<int> boys, girls;

					int main()
					{
					    cin >> n >> m;
					    while (m -- )
					    {
					        string a, b;
					        cin >> a >> b;
					        string x = a, y = b;
					        if (x.size() == 5) x = x.substr(1); 如果是5个字符,说明是负数,现在x = x.substr(1)之后x是不带有性别的
					        if (y.size() == 5) y = y.substr(1);
					        if (mp.count(x) == 0) mp[x] = ++ id, num[id] = x; 如果之前没有遇见过这个人x, 就插入mp和num. mp存的是不带性别的, num存的也是不带性别的
					        if (mp.count(y) == 0) mp[y] = ++ id, num[id] = y;

					        int px = mp[x], py = mp[y]; px,py是我们1-N编号
					        g[px][py] = g[py][px] = true; 在邻接矩阵里面加入

					        if (a[0] != '-') boys.push_back(px);  处理男女的时候, 插入的是1-N编号, 注意这里可能会重复插入
					        else girls.push_back(px);
					        if (b[0] != '-') boys.push_back(py);
					        else girls.push_back(py);
					    }

					    sort(boys.begin(), boys.end()); 
					    boys.erase(unique(boys.begin(), boys.end()), boys.end()); 删掉重复元素
					    sort(girls.begin(), girls.end());
					    girls.erase(unique(girls.begin(), girls.end()), girls.end());

					    int k;
					    cin >> k;

					    while (k -- )
					    {
					        vector<pair<string, string>> res;
					        string x, y;
					        cin >> x >> y;

					      	如果题目给的ab是男男,我们就要从男找c, 从男找d
					      	如果题目给的ab是女女,我们就要从女找c, 从女找d
					        vector<int> p = boys, q = boys; 先默认是都找男
					        if (x[0] == '-') p = girls, x = x.substr(1); 改为找女, 并且x也变成没有性别的4位编号
					        if (y[0] == '-') q = girls, y = y.substr(1);

					        int a = mp[x], b = mp[y]; 变成1-N编号

					        for (int c : p) 从p中取出所有的人, 注意这个人可能会是a, 所以后面有了c != a, 当然存在p==q也就是同找男男或者女女,所以我们需要 c!=b
					            for (int d : q)
					            {
					                if (c != a && c != b && d != a && d != b && g[a][c] && g[c][d] && g[d][b]) 其实还可以加上 c!=d, 但是因为如果c==d的话g[c][d]肯定是false,所以加不加c!=d无所谓 
					                    res.push_back({num[c], num[d]});
					            }

					        sort(res.begin(), res.end()); 也就是4位数的排序, 安排续输出. 第一关键词是第一个朋友的排序, 第二个关键词是第二个朋友
					        cout << res.size() << endl;
					        for (auto p : res) cout << p.first << ' ' << p.second << endl;
					    }

					    return 0;
					}
			3. 5次
				r1. 1c1a
					#include <iostream>
					#include <cstring>
					#include <unordered_map>
					#include <algorithm>
					#include <vector>

					using namespace std;

					const int N = 310;
					bool g[N][N];
					vector<int> boys, girls;
					unordered_map<string, int> mp;
					string names[N];
					int ind;
					int n, m, k;
					vector<pair<string, string>> res;

					int add(string a){
					    if(a[0] == '-'){
					        if(mp.count(a) == 0){
					            mp[a] = ++ ind;
					            names[ind] = a.substr(1);
					            girls.push_back(ind);
					        }
					    }else{
					        if(mp.count(a) == 0){
					            mp[a] = ++ ind;
					            names[ind] = a;
					            boys.push_back(ind);
					        }
					    }
					    return mp[a];
					}

					int main(){
					    cin >> n >> m;
					    string a, b;
					    while(m--){
					        cin >> a >> b;
					        int x = add(a);
					        int y = add(b);
					        g[x][y] = g[y][x] = true;
					    }

					    cin >> k;
					    while(k--){
					        cin >> a >> b;
					        vector<int> v1 = boys, v2 = boys;
					        res.clear();
					        if(a.size() == 5) v1 = girls;
					        if(b.size() == 5) v2 = girls;

					        int x = mp[a], y = mp[b];
					        for(int i1 : v1)
					            for(int i2 : v2)
					                if(i1 != x && i1 != y)
					                    if(i2 != x && i2 != y)
					                        if(g[x][i1] && g[i1][i2] && g[i2][y]) res.push_back({names[i1], names[i2]});
					        
					        sort(res.begin(), res.end());
					        cout << res.size() << endl;
					        for(int i = 0; i < res.size() ; i++) cout << res[i].first << " " << res[i].second << endl;
					    }

					    return 0;
					}
				r2.
				r3.
				r4.
				r5.

		82. 1635. 最大团	1142
			0. bug
				1. 逻辑错了:判断是否是最大的团
					错误: 
						bool check2(){
						    for(int i = 1; i <= n; i ++){
						        if(!st[i]){
						            for(int item : nodes) if(!g[item][i]) return false; 
						            	如果一个不是, 不能直接return false
						            		我们要看到所有的节点都不是, 才能return false. 
						            	只要存在一个节点可以更大, 那就return true(可以更大)
						        }
						    }
						    return true;
						}
						bool Ismax = haslarger();
				        if(Ismax) cout << "Yes" << endl;
				        else cout << "Not max" << endl;
					正确:
						bool haslarger(){
						    for(int i = 1; i <= n; i ++){
						        if(!st[i]){
						            bool valid = true;
						            for(int item : nodes){
						                if(!g[item][i]) 
						                {
						                    valid = false;
						                    break;
						                }
						            }
						            if(valid) return true; 
						            如果这个节点i是可以让当前团变大, 就返回true
						        }
						    }
						    return false; 我们要看到所有的节点都不是, 才能return false. 
						}
						bool hasm = haslarger();
				        if(hasm) cout << "Not Maximal" << endl; 有更大的, 所以 当前团 不是最大
				        else cout << "Yes" << endl;

			1. 笔记
				1. 
					1. 题目要求: 
						1. 是否是团: 看给定的点集中的所有点是否都和其他点相连接
						2. 是否是最大团: 看剩余的点(就是全集中, 除了给定的点集之外的其他点), 是否和点集中的点全部链接
							1. 是的话, 说明当前点集不是最大团
							2. 不是: 当前点集是最大团
					2. 复杂度:
						1. 判断是否是团:199个点和其他198个点相比 : 199*198 所以可以两个forloop
						2. 判断是否是最大团: 剩余的1个点 和 点集中的199个点比:  1*199
						3. 100次询问: 100*(199*199) = 100*200*200 = 200w, 0.02s可以搞定

			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 210;

					int n, m;
					bool g[N][N], st[N];
					int vers[N];

					bool check_clique(int cnt)
					{
					    for (int i = 0; i < cnt; i ++ )
					        for (int j = 0; j < i; j ++ )
					            if (!g[vers[i]][vers[j]]) 
					                return false;
					    return true;
					}

					bool check_maximum(int cnt)
					{
					    memset(st, 0, sizeof st);
					    for (int i = 0; i < cnt; i ++ )
					        st[vers[i]] = true;

					    for (int i = 1; i <= n; i ++ )
					        if (!st[i])  只处理点集之外的其他点
					        {
					            bool success = true;
					            for (int j = 0; j < cnt; j ++ )
					                if (!g[i][vers[j]])
					                {
					                    success = false; 我觉得也可以直接return false
					                    break;
					                }

					            if (success) return false; 
					        }

					    return true;
					}

					int main()
					{
					    cin >> n >> m;
					    while (m -- )
					    {
					        int a, b;
					        cin >> a >> b;
					        g[a][b] = g[b][a] = true;
					    }

					    int k;
					    cin >> k;
					    while (k -- )
					    {
					        int cnt;
					        cin >> cnt;
					        for (int i = 0; i < cnt; i ++ ) cin >> vers[i];
					        if (check_clique(cnt))
					        {
					            if (check_maximum(cnt)) puts("Yes");
					            else puts("Not Maximal");
					        }
					        else puts("Not a Clique");
					    }

					    return 0;
					}
			3. 5次
				r1.

				r2.
				r3.
				r4.
				r5.

		83. 1639. 拓扑顺序	1146
			0. bug
			1. 笔记
				1. 
					1. 思路很简单
						1. 首先我们知道有向图的每条边的信息, 记录每条边的起点和终点
						2. 给了一个需要判断的序列, 我们存一个映射 p[点的id] = 顺序
						3. 我们看每一条边, 是否p[起点id] < p[终点id]
						4. 你可以画图, 是真的就是这个性质
					2. 复杂度:
						1. 一共10000条边, 每条边都要比较起点在p[]的顺序是不是在终点前面
						2. 一共100次询问, 所以是100*10000 = 100w
				2. 重要:
					bool tp(){
					    for(int i = 0; i < m; i++){
					        if(rec[edges[i].a] > rec[edges[i].b]) return false;
					    	每一条边edge, 的左右两个端点 a,b. 是否在给定的测试中 rec[] 都是a的顺序在b的左边
					    }
					    return true;
					}
			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 1010, M = 10010;

					int n, m;
					struct Edge
					{
					    int a, b;
					}e[M];
					int p[N];

					int main()
					{
					    cin >> n >> m;
					    for (int i = 0; i < m; i ++ ) cin >> e[i].a >> e[i].b;

					    int k;
					    cin >> k;

					    bool is_first = true; 如果是第一个要输出的询问次数, 前面就没有空格
					    for (int i = 0; i < k; i ++ ) k次询问
					    {
					        for (int j = 1; j <= n; j ++ ) 将这次询问的每个点的顺序记录
					        {
					            int x;
					            cin >> x;
					            p[x] = j; p[点的id] = 顺序
					        }

					        bool success = true;
					        for (int j = 0; j < m; j ++ )
					            if (p[e[j].a] > p[e[j].b]) 对于不存在的边,也就没有必要判断了
					            {
					                success = false;
					                break;
					            }

					        if (!success)
					        {
					            if (is_first) is_first = false; 只会执行一次,就是第一次
					            else cout << ' ';
					            cout << i; 所以最后的输出是"a b c d",即a的前面没有空格

					        }
					    }

					    cout << endl;

					    return 0;
					}
			3. 5次
				r1.
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 10010;
					struct edge{
					    int a, b;
					}edges[N];

					int n, m, k;
					int rec[N];

					bool tp(){
					    for(int i = 0; i < m; i++){
					        if(rec[edges[i].a] > rec[edges[i].b]) return false;
					    }
					    return true;
					}


					int main(){
					    cin >> n >> m;
					    for(int i = 0; i < m; i++){
					        int a, b;
					        cin >> a >> b;
					        edges[i].a = a;
					        edges[i].b = b;
					    }

					    cin >> k;
					    bool isfirst = true;
					    for(int i = 0; i < k ; i++){
					        memset(rec, 0, sizeof rec);
					        for(int i = 0; i < n; i++){
					            int a;
					            cin >> a;
					            rec[a] = i;
					        }
					        if(!tp()){
					            if(isfirst){
					                isfirst = false;
					                cout << i;
					            }else{
					                cout << " " << i;
					            }
					        }
					    }
					    cout << endl;
					    return 0;
					}
				r2.
				r3.
				r4.
				r5.

		none 84. 1643. 旅行商问题	1150
			0. bug
			1. 笔记
				1.
					简单回路: 
						1. 两个点之间存在一条边
						2. 每个点都遍历了
						3. 起点 == 终点
						4. 点数 == n+1
					debug:
						1. segmentfault: 数组越界

			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 210, INF = 0x3f3f3f3f;

					int n, m;
					int d[N][N], vers[310];
					bool st[N];

					int main()
					{
					    cin >> n >> m;
					    memset(d, 0x3f, sizeof d);
					    for (int i = 0; i < m; i ++ )
					    {
					        int a, b, c;
					        cin >> a >> b >> c;
					        d[a][b] = d[b][a] = c;
					    }

					    int k;
					    cin >> k;

					    int min_dist = INF, min_id;
					    for (int T = 1; T <= k; T ++ )
					    {
					        int cnt;
					        cin >> cnt;
					        for (int i = 0; i < cnt; i ++ ) cin >> vers[i]; 读取询问的两个点

					        int sum = 0;
					        bool success = true;
					        memset(st, 0, sizeof st);
					        for (int i = 0; i + 1 < cnt; i ++ )
					        {
					            int a = vers[i], b = vers[i + 1];
					            if (d[a][b] == INF) 如果这两个点没有链接
					            {
					                sum = -1; sum是成了-1,表示不是路
					                success = false;
					                break;
					            }
					            else sum += d[a][b]; 
					            	有链接
					            st[a] = true; 
					            	我很好奇, 这不应该还剩一个最后一个st[]没有设置成true吗, 所以这里是cnt-1个设置成了true
					        }
					        st[vers[cnt-1]] = true; 我自己添加的.

					        sum == -1
					        	不是路
					        	有两个点之间没有边

					        sum > 0 但是 st[0]到st[n-1]存在false
					        	没有走完所有点

					        sum > 0 && cnt == n+1 && st[0]到st[n-1]都是true && vers[0] == vers[cnt-1]
					        	简单回路
					        	所以可以cnt中前cnt-1个设置成st[a] = true;

					        sum > 0 && cnt > n+1 && st[0]到st[n-1]都是true
					        	不是简单回路


					        for (int i = 1; i <= n; i ++ )
					            if (!st[i])
					            {
					                success = false;
					                break;
					            }

					        if (vers[0] != vers[cnt - 1]) success = false;

					        if (sum == -1) printf("Path %d: NA (Not a TS cycle)\n", T);
					        else
					        {
					            if (!success) printf("Path %d: %d (Not a TS cycle)\n", T, sum);
					            else
					            {
					                if (cnt == n + 1) printf("Path %d: %d (TS simple cycle)\n", T, sum);
					                else printf("Path %d: %d (TS cycle)\n", T, sum);

					                if (min_dist > sum)
					                {
					                    min_dist = sum;
					                    min_id = T;
					                }
					            }
					        }
					    }

					    printf("Shortest Dist(%d) = %d\n", min_id, min_dist);

					    return 0;
					}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		none 85. 1648. 顶点着色	1154
			0. bug
			1. 笔记
				1.
					简单,因为询问是给出了颜色,让我们判断对错, 而不是让我们自己设计颜色
					思路是:
					1. 记录每条边的起点和终点
					2. 判断这个起点和终点的颜色(因为询问中给出了每个点的颜色)
					3. 如果颜色相同,就是false
					4. 最后也需要输出颜色的种类数, 用unordered_set来存
			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <cstring>
					#include <unordered_set>

					using namespace std;

					const int N = 10010;

					int n, m;
					struct Edge
					{
					    int a, b;
					}e[N];
					int color[N];

					int main()
					{
					    cin >> n >> m;
					    for (int i = 0; i < m; i ++ ) cin >> e[i].a >> e[i].b; 起点终点

					    int k;
					    cin >> k;
					    while (k -- )
					    {
					        for (int i = 0; i < n; i ++ ) cin >> color[i]; 询问

					        bool success = true;
					        for (int i = 0; i < m; i ++ )
					            if (color[e[i].a] == color[e[i].b]) 判断是否颜色相同
					            {
					                success = false;
					                break;
					            }

					        if (success)
					        {
					            unordered_set<int> S;
					            for (int i = 0; i < n; i ++ ) S.insert(color[i]); 存颜色个数
					            printf("%d-coloring\n", S.size());
					        }
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

		none 86. 1495. 公共自行车管理	1018
			0. bug
			1. 笔记
				1. 题目中说明只会沿着最短路从起点走到终点，然后就不能进行其他操作了。
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>
					#include <vector>

					using namespace std;

					const int N = 510, INF = 0x3f3f3f3f;

					int C, n, S, m;
					int c[N];
					int g[N][N];
					int dist[N];
					bool st[N];

					vector<int> path, ans;
					int send = INF, bring = INF;

					void dijkstra()
					{
					    memset(dist, 0x3f, sizeof dist);
					    dist[S] = 0;

					    for (int i = 0; i < n; i ++ )
					    {
					        int t = -1;
					        for (int j = 0; j <= n; j ++ )
					            if (!st[j] && (t == -1 || dist[j] < dist[t]))
					                t = j;

					        st[t] = true;
					        for (int j = 0; j <= n; j ++ )
					            dist[j] = min(dist[j], dist[t] + g[t][j]);
					    }
					}

					void dfs(int u, int s, int mins)
					{
					    if (u)
					    {
					        s -= (C + 1) / 2 - c[u];
					        mins = min(mins, s);
					    }

					    if (u == S)
					    {
					        int sd = abs(min(mins, 0));
					        int bg = s + sd;

					        if (sd < send) ans = path, send = sd, bring = bg;
					        else if (sd == send && bg < bring) ans = path, bring = bg;

					        return;
					    }

					    for (int i = 1; i <= n; i ++ )
					        if (dist[u] == g[u][i] + dist[i])
					        {
					            path.push_back(i);
					            dfs(i, s, mins);
					            path.pop_back();
					        }
					}

					int main()
					{
					    cin >> C >> n >> S >> m;
					    for (int i = 1; i <= n; i ++ ) cin >> c[i];

					    memset(g, 0x3f, sizeof g);
					    for (int i = 0; i < m; i ++ )
					    {
					        int x, y, z;
					        cin >> x >> y >> z;
					        g[x][y] = g[y][x] = min(g[x][y], z);
					    }

					    dijkstra();

					    path.push_back(0);   
					    dfs(0, 0, 0);

					    cout << send << ' ' << 0;
					    for (int i = 1; i < ans.size(); i ++ )
					        cout << "->" << ans[i];
					    cout << " " << bring << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/323564/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		none 87. 1558. 加油站	1072
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 1020, INF = 0x3f3f3f3f;

					int n, m, k, D;
					int g[N][N];
					int dist[N];
					bool st[N];

					int get(string s)
					{
					    if (s[0] == 'G') return n + stoi(s.substr(1));
					    return stoi(s);
					}

					void dijkstra(int start, int &mind, int &sumd)
					{
					    memset(dist, 0x3f, sizeof dist);
					    memset(st, 0, sizeof st);

					    dist[start] = 0;
					    for (int i = 0; i < n + m; i ++ )
					    {
					        int t = -1;
					        for (int j = 1; j <= n + m; j ++ )
					            if (!st[j] && (t == -1 || dist[j] < dist[t]))
					                t = j;

					        st[t] = true;

					        for (int j = 1; j <= n + m; j ++ )
					            dist[j] = min(dist[j], dist[t] + g[t][j]);
					    }

					    for (int i = 1; i <= n; i ++ )
					        if (dist[i] > D)
					        {
					            mind = -INF;
					            return;
					        }

					    mind = INF, sumd = 0;
					    for (int i = 1; i <= n; i ++ )
					    {
					        mind = min(mind, dist[i]);
					        sumd += dist[i];
					    }
					}

					int main()
					{
					    cin >> n >> m >> k >> D;

					    memset(g, 0x3f, sizeof g);
					    while (k -- )
					    {
					        string a, b;
					        int z;
					        cin >> a >> b >> z;
					        int x = get(a), y = get(b);

					        g[x][y] = g[y][x] = min(g[x][y], z);
					    }

					    int res = -1, mind = 0, sumd = INF;
					    for (int i = n + 1; i <= n + m; i ++ )
					    {
					        int d1, d2;
					        dijkstra(i, d1, d2);

					        if (d1 > mind) res = i, mind = d1, sumd = d2;
					        else if (d1 == mind && d2 < sumd) res = i, sumd = d2;
					    }

					    if (res == -1) puts("No Solution");
					    else printf("G%d\n%.1lf %.1lf\n", res - n, (double)mind, (double)sumd / n + 1e-8);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/323579/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		none 88. 1562. 微博转发 	1076
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <queue>

					using namespace std;

					const int N = 1010, M = 100010;

					int n, m;
					int h[N], e[M], ne[M], idx;
					bool st[N];

					void add(int a, int b)
					{
					    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
					}

					int bfs(int start)
					{
					    queue<int> q;
					    memset(st, 0, sizeof st);

					    q.push(start);
					    st[start] = true;

					    int res = 0;
					    for (int step = 0; step < m; step ++ )
					    {
					        int sz = q.size();
					        res += sz;

					        for (int i = 0; i < sz; i ++ )
					        {
					            int t = q.front();
					            q.pop();

					            for (int j = h[t]; ~j; j = ne[j])
					            {
					                int k = e[j];
					                if (!st[k])
					                {
					                    st[k] = true;
					                    q.push(k);
					                }
					            }
					        }
					    }

					    return res + q.size() - 1;
					}

					int main()
					{
					    scanf("%d%d", &n, &m);

					    memset(h, -1, sizeof h);
					    for (int i = 1; i <= n; i ++ )
					    {
					        int cnt;
					        scanf("%d", &cnt);
					        while (cnt -- )
					        {
					            int x;
					            scanf("%d", &x);
					            add(x, i);
					        }
					    }

					    int k;
					    scanf("%d", &k);
					    while (k -- )
					    {
					        int x;
					        scanf("%d", &x);
					        printf("%d\n", bfs(x));
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/324375/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

7. 数学
		89. 1533. 1 的个数	1049
			0. bug
			1. 笔记
				1.	
					1. 暴力枚举一定会超时:
						1. 因为假设是判断最大的数字, 2^30 = 十几亿 = 10^9(因为2^31 = 30亿)
						2. 那么我们要遍历从1到十几亿每个数字的1有多少个, 因为10^9有10位数
						3. 所以10^9*10 = 10^10, 一定超时了
					2. 思路
						假设一个数字是bar(abcdefgh), 其中bar()就是代表一个数字上面加上-
						我们需要一个一个遍历所有的数字, 假设我们当前遍历到了d
						我们是判断, 比这个bar(abcdefgh)小的所有数字中,有多少是bar(abc1efgh)
						有多少呢?需要分情况讨论:
							1. 假设d == 0, 求比bar(abc0efgh)小的所有数字中,有多少是第4位数字是1, 也就是bar(___1____)
								分析
									前3位___的取值是bar(000)到bar(abc)-1, 因为如果是bar(abc)的话, bar(abc1____)肯定是大于我们题目给的bar(abc0efgh)
										bar(000)到bar(abc)-1一共有bar(abc)个数字
									后4位____的取值是bar(0)到bar(999), 例如, 假设bar(abc)是123, 题目给定的就是1230efgh, 比1230efgh要小的数字,就包括了12219999. 其中前三位是bar(abc)-1, 后4位是9999
										bar(0)到bar(999)一共有10^4个数字
								总结
									bar(abc) * 10^4种可能

							2. 假设d == 1, 求比bar(abc1efgh)小的所有数字中,有多少是第4位数字是1, 也就是bar(___1____)
								分析
									假设
										前3位___的取值是bar(000)到bar(abc)-1, 那么后4位____的取值是bar(0000)到bar(9999)
										因为前三位比我们题目给的数bar(abc1efgh)小, 所有后4位想怎么样都行
										这种情况一共有bar(abc)*10^4种可能
									假设
										前3位___的取值是bar(abc), 那么后4位____的取值是bar(0000)到bar(efgh)
										因为前三位比我们题目给的数等于bar(abc1efgh), 所有后4位必须<=bar(efgh)
										这种情况一共有bar(efgh)+1种可能
								总结
									bar(abc)*10^4 
									+ bar(efgh)+1 种可能
							3. 假设d > 1, 例如d == 8, 求比bar(abc8efgh)小的所有数字中,有多少是第4位数字是1, 也就是bar(___1____)
								分析:这个就很灵活了
									前3位___的取值是bar(000)到bar(abc), 后4位____的取值是bar(0)到bar(9999), 怎么都不会超出bar(abc8efgh)
								总结
									(bar(abc)+1) * 10^4
					3. 总结:
						1. d == 0
							bar(abc)*10^4
						2. d == 1
							bar(abc)*10^4 + bar(efgh)+1
						3. d > 1
							(bar(abc)+1) * 10^4
					4. 所以我们预处理,需要bar(abc), bar(efgh), 后面的位数n
			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <vector>

					using namespace std;

					int calc(int n)
					{
					    vector<int> nums;
					    while (n) nums.push_back(n % 10), n /= 10; 每次推入的是个位数, 所以个位数的ind == 0

					    int res = 0;
					    for (int i = nums.size() - 1; i >= 0; i -- ) 从最高位开始, 所以想想画面: ind == 0 (hgfedcba) ind == size-1
					    {
					        int d = nums[i];
					        int left = 0, right = 0, power = 1; left就是上面的bar(abc), right就是bar(efgh), power就是后面的n位
					        for (int j = nums.size() - 1; j > i; j -- ) left = left * 10 + nums[j]; 	获得bar(abc),就是先计算a,然后*10+b,*10+c. 其中a的ind == size-1
					        for (int j = i - 1; j >= 0; j -- ) 
					        {
					            right = right * 10 + nums[j]; 或者bar(efgh),就是从e开始, *10+f, *10+g..., 所以是从i-1开始
					            power *= 10; 后面有几位
					        }

					        同上的分析
					        if (d == 0) res += left * power;
					        else if (d == 1) res += left * power + right + 1;
					        else res += (left + 1) * power;
					    }

					    return res;
					}

					int main()
					{
					    int n;
					    cin >> n;

					    cout << calc(n) << endl;

					    return 0;
					}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		90. 1545. 质因子	1059
			0. bug
			1. 笔记
				1. 给定一个整数 N，找出它的所有质因子
			2. 注释
				1. y
				2. b
					#include <iostream>

					using namespace std;

					int main()
					{
					    int n;
					    cin >> n;

					    printf("%d=", n);
					    if (n == 1) puts("1");
					    else
					    {
					        bool is_first = true;
					        for (int i = 2; i <= n / i; i ++ ) 就是从最小,找质因子
					            if (n % i == 0) 说明i是n的一个质因子
					            {
					                int k = 0;
					                while (n % i == 0) n /= i, k ++ ; 看有多少个这个质因子

					                if (!is_first) cout << '*'; 因为第一个输出的数字前不能有乘号*
					                else is_first = false;

					                cout << i;
					                if (k > 1) cout << "^" << k; 输入幂次
					            }

					        if (n > 1) 如果还剩一个n,说明n本身就是质因子, 因为我们上面的的是for (int i = 2; i <= n / i; i ++ ) ,所以i一定不会 == n
					        {
					            if (!is_first) cout << '*';
					            cout << n;
					        }
					    }

					    return 0;
					}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		91. 1567. 有理数的和	1081
			0. bug
			1. 笔记
				1.
					思路: 就是求两个分数的和
					debug: float point exception: 说明我们除0了
			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					typedef long long LL;

					LL gcd(LL a, LL b)
					{
					    return b ? gcd(b, a % b) : a;
					}

					int main()
					{
					    LL a = 0, b = 1;

					    int n;
					    cin >> n;
					    for (int i = 0; i < n; i ++ )
					    {
					        LL c, d;
					        scanf("%lld/%lld", &c, &d);

					        LL t = gcd(c, d);
					        c /= t, d /= t;

					        t = gcd(b, d);
					        a = d / t * a + b / t * c;
					        b = b / t * d;

					        t = gcd(a, b);
					        a /= t, b /= t;
					    }

					    if (b == 1) cout << a;
					    else
					    {
					        if (a >= b) printf("%lld ", a / b), a %= b;
					        printf("%lld/%lld", a, b);
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/310015/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					#include <iostream>

					using namespace std;

					typedef long long LL;

					LL gcd(LL a, LL b) 最大公约数
					{
					    return b ? gcd(b, a % b) : a; 辗转相除, 不是很清楚, 背吧
					}

					int main()
					{
					    LL a = 0, b = 1; 最开始的分子a和分母b, 其中b = 1, 否则float point exception

					    int n;
					    cin >> n;
					    for (int i = 0; i < n; i ++ )
					    {
					        LL c, d;
					        scanf("%lld/%lld", &c, &d); 读入分子分母, 读入的时候是按照lld读入

					        LL t = gcd(c, d); 最大公约数
					        c /= t, d /= t;  分子分母约分

					        a/b + c/d = (ad + bc) / bd, 最后将(ad+bc)赋值给a, bd赋值给b
					        t = gcd(b, d);
					        a = d / t * a + b / t * c; 担心bd分母溢出, 所以找出公约数, 然后分子(ad+bc)/t, 分母bd/t, 分子分母都除以t才能保证值不变
					        b = b / t * d;

					        t = gcd(a, b); 最后继续约分
					        a /= t, b /= t;
					    }

					    if (b == 1) cout << a; 说明是整数
					    else
					    {
					        if (a >= b) printf("%lld ", a / b), a %= b; 假分数
					        printf("%lld/%lld", a, b);
					    }

					    return 0;
					}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		92. 1578. 有理数运算	1088
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					typedef long long LL;

					LL gcd(LL a, LL b)
					{
					    return b ? gcd(b, a % b) : a;
					}

					void print(LL a, LL b)
					{
					    LL d = gcd(a, b);
					    a /= d, b /= d;

					    if (b < 0) a *= -1, b *= -1;
					    bool is_minus = a < 0;

					    if (is_minus) cout << "(";

					    if (b == 1) cout << a;
					    else
					    {
					        if (abs(a) >= b) printf("%lld ", a / b), a = abs(a) % b;
					        printf("%lld/%lld", a, b);
					    }

					    if (is_minus) cout << ")";
					}

					void add(LL a, LL b, LL c, LL d)
					{
					    print(a, b), cout << " + ", print(c, d), cout << " = ";
					    a = a * d + b * c;
					    b = b * d;
					    print(a, b), cout << endl;
					}

					void sub(LL a, LL b, LL c, LL d)
					{
					    print(a, b), cout << " - ", print(c, d), cout << " = ";
					    a = a * d - b * c;
					    b = b * d;
					    print(a, b), cout << endl;
					}

					void mul(LL a, LL b, LL c, LL d)
					{
					    print(a, b), cout << " * ", print(c, d), cout << " = ";
					    a = a * c;
					    b = b * d;
					    print(a, b), cout << endl;
					}

					void div(LL a, LL b, LL c, LL d)
					{
					    print(a, b), cout << " / ", print(c, d), cout << " = ";
					    if (!c) puts("Inf");
					    else
					    {
					        a = a * d;
					        b = b * c;
					        print(a, b), cout << endl;
					    }
					}

					int main()
					{
					    LL a, b, c, d;
					    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);

					    add(a, b, c, d);
					    sub(a, b, c, d);
					    mul(a, b, c, d);
					    div(a, b, c, d);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/310030/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
					输入 long int ,也就是int, 而不是longlong
					#include <iostream>

					using namespace std;

					typedef long long LL; 防止溢出

					LL gcd(LL a, LL b)
					{
					    return b ? gcd(b, a % b) : a; 适用于负数
					}

					void print(LL a, LL b)
					{
					    LL d = gcd(a, b);
					    a /= d, b /= d;

					    if (b < 0) a *= -1, b *= -1; 如果分母是负数, 需要把符号挪到分子
					    bool is_minus = a < 0;

					    if (is_minus) cout << "("; 如果是负数, 需要输入括号

					    if (b == 1) cout << a; 整数
					    else
					    {
					        if (abs(a) >= b) printf("%lld ", a / b), a = abs(a) % b; 输出的是假分数
					        printf("%lld/%lld", a, b);
					    }

					    if (is_minus) cout << ")";
					}

					void add(LL a, LL b, LL c, LL d)
					{
					    print(a, b), cout << " + ", print(c, d), cout << " = ";
					    a = a * d + b * c;
					    b = b * d;
					    print(a, b), cout << endl;
					}

					void sub(LL a, LL b, LL c, LL d)
					{
					    print(a, b), cout << " - ", print(c, d), cout << " = ";
					    a = a * d - b * c;
					    b = b * d;
					    print(a, b), cout << endl;
					}

					void mul(LL a, LL b, LL c, LL d)
					{
					    print(a, b), cout << " * ", print(c, d), cout << " = ";
					    a = a * c;
					    b = b * d;
					    print(a, b), cout << endl;
					}

					void div(LL a, LL b, LL c, LL d)
					{
					    print(a, b), cout << " / ", print(c, d), cout << " = ";
					    if (!c) puts("Inf");
					    else
					    {
					        a = a * d;
					        b = b * c;
					        print(a, b), cout << endl;
					    }
					}

					int main()
					{
					    LL a, b, c, d;
					    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);

					    add(a, b, c, d);
					    sub(a, b, c, d);
					    mul(a, b, c, d);
					    div(a, b, c, d);

					    return 0;
					}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		93. 1586. 连续因子	1096
			0. bug
			1. 笔记
				1.
					思路:
						1. 既然是要找出序列, 我们就枚举序列
						2. 序列的枚举: 1. 需要第一个数, 2. 需要后面的n个数
						3. 从2开始, 看后面3,4,5..是否可以整除
						4. 如果2不行,再从3开始,看后面4,5,6..是否可以整除
			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <vector>

					using namespace std;

					int main()
					{
					    int n;
					    cin >> n;

					    vector<int> res;
					    for (int i = 2; i <= n / i; i ++ ) 从2开始, 一直到sqrt(t)
					        if (n % i == 0) 如果能整除,就继续看i+1, i+2
					        {
					            vector<int> seq; 
					            for (int m = n, j = i; m % j == 0; j ++ ) j从i开始, m是被整除之后的剩下的数
					            {
					                seq.push_back(j); 将答案插入
					                m /= j;
					            }
					            我们看样例630, 630=5*6*7 * 3 = 210*3
					            所以j = 5,6,7, 当前的点j==7的时候, m /= j是 210 /= 7 == 3, 之后判断m%j == 1 % 8 == 1 != 0
					            就一定会break

					            假设j是从2开始, 点j==2的时候, m/=j 是630/=2 == 315, 之后判断m%j == 315 % 3 != 0
					            也会break,但是break之后的seq.size()并不大

					            假设后面遇到了新的j = x,y,z, 也可以满足630=x*y*z. 其中x > 5
					            那么我们也不会更新res, 因为更新的条件是严格大于, 而不是大于等于
					            这么做的原因: 题目要求,如果多个序列的长度相同, 那么取第一个数字最小的. 


					            if (seq.size() > res.size()) res = seq; 是严格大于
					        }

					    if (res.empty()) res.push_back(n);

					    cout << res.size() << endl;
					    cout << res[0];
					    for (int i = 1; i < res.size(); i ++ ) cout << '*' << res[i];

					    return 0;
					}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		94. 1593. 整数分解	1103
			0. bug
			1. 笔记
				1.	
					这道题的正规解法是二维费用的背包问题
					https://www.acwing.com/solution/content/13018/
					https://www.acwing.com/problem/content/1595/

					和: 169, 是体积(也就是其中一个限制条件)
					几个数字: 5, 是重量(另一个限制条件)
					每个数字: 1,4,9,16.., 也是体积
					每个数字都看成一个空箱子, 例如数字1代表体积是1的空箱, 数字4代表体积是16的空箱
					我们需要找到5个数字,让他们的体积之和 == 169

					题目体积的取值是1-400, 假设只需要找一个数字, 那么我们找到数字20(它的体积是400)就已经足够了
					所以我们能找的数字是1-20

					所以,题目可以看成,你有20个物品(数字1-20),每个物品的价值是1-20(数字n的价值是n),每个物品的体积是1-400(数字n的体积是n*n),每个物品的重量是1
					我们需要满足的限制条件是:选取k个物品,他们的体积之和是n,他们的重量之和是k.
					在满足上面的限制的所有物品,求出物品价值最高的.
					这是个完全背包问题,每个物品可以选多次.

					而原来的题目是:给定一个数字n,要你分解成k个数字的平方和的形式,我们希望k个数字的和最大.一个数字可以选多次

					复杂度:
						1. 体积的取值是1-400, 选取的物品个数是1-400, 一共有最多20种物品, 所以复杂度是400*400*20=320w < 

					状态表示
					因为是两维度,所以我们需要3个参数
					f(i,j,k)
						表示了某个集合:
							所有只考虑前i个物品
						表示了该集合的属性:
			2. 注释
				1. y
				2. b
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 410;

					int n, k, p;
					int f[21][N][N];

					int power(int a, int b)
					{
					    int res = 1;
					    for (int i = 0; i < b; i ++ ) res *= a;
					    return res;
					}

					int main()
					{
					    cin >> n >> k >> p;

					    memset(f, -0x3f, sizeof f); 初始化负无穷
					    f[0][0][0] = 0; 唯一能取到的状态

					    int m;
					    for (m = 1; ; m ++ )
					    {
					        int v = power(m, p);
					        if (v > n) break;

					        for (int i = 0; i <= n; i ++ )
					            for (int j = 0; j <= k; j ++ )
					            {
					                f[m][i][j] = f[m - 1][i][j];

					                if (i >= v && j >= 1) f[m][i][j] = max(f[m][i][j], f[m][i - v][j - 1] + m);
					            }
					    }

					    m -- ;

					    if (f[m][n][k] < 0) puts("Impossible");
					    else
					    {
					        printf("%d = ", n);
					        bool is_first = true;
					        while (m)
					        {
					            int v = power(m, p);
					            while (n >= v && k && f[m][n - v][k - 1] + m == f[m][n][k])
					            {
					                if (is_first) is_first = false;
					                else printf(" + ");

					                printf("%d^%d", m, p);
					                n -= v, k --;
					            }

					            m -- ;
					        }
					    }

					    return 0;
					}
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		95. 1594. 数段之和	1104
			0. bug
			1. 笔记
				1.
					1. i * (n-i+1)
						举例
						
					2. double 防止溢出
			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					int main()
					{
					    int n;
					    cin >> n;
					    long double res = 0;
					    for (int i = 1; i <= n; i ++ )
					    {
					        long double x;
					        cin >> x;

					        res += x * i * (n - i + 1);
					    }

					    printf("%.2Lf", res);

					    return 0;
					}
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		96. 1602. 卡住的键盘	1062
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 200;

					int st[N];

					int main()
					{
					    int k;
					    string str;
					    cin >> k >> str;

					    for (int i = 0; i < str.size(); i ++ )
					    {
					        int j = i + 1;
					        while (j < str.size() && str[j] == str[i]) j ++ ;
					        int len = j - i;
					        if (len % k) st[str[i]] = 1;
					        i = j - 1;
					    }

					    string res;
					    for (int i = 0; i < str.size(); i ++ )
					    {
					        if (!st[str[i]]) cout << str[i], st[str[i]] = 2;

					        if (st[str[i]] == 1) res += str[i];
					        else
					        {
					            res += str[i];
					            i += k - 1;
					        }
					    }

					    cout << endl << res << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/324389/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		97. 1606. C 语言竞赛	1116
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 10010;

					int Rank[N];
					int st[N];

					void init()
					{
					    for (int i = 2; i < N; i ++ )
					        if (!st[i])
					        {
					            st[i] = 1;
					            for (int j = i * 2; j < N; j += i)
					                st[j] = 2;
					        }
					}

					int main()
					{
					    init();

					    int n;
					    cin >> n;
					    for (int i = 1; i <= n; i ++ )
					    {
					        int id;
					        cin >> id;
					        Rank[id] = i;
					    }

					    int k;
					    cin >> k;
					    while (k -- )
					    {
					        int id;
					        cin >> id;

					        printf("%04d: ", id);
					        if (!Rank[id]) puts("Are you kidding?");
					        else if (Rank[id] == -1) puts("Checked");
					        else
					        {
					            int t = st[Rank[id]];
					            if (t == 0) puts("Mystery Award");
					            else if (t == 1) puts("Minion");
					            else puts("Chocolate");

					            Rank[id] = -1;
					        }
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/324400/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		98. 1646. 谷歌的招聘	1152
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 1010, M = 40000;

					int n, k;
					bool st[M];
					int primes[M], cnt;

					void init()
					{
					    for (int i = 2; i < M; i ++ )
					        if (!st[i])
					        {
					            primes[cnt ++ ] = i;
					            for (int j = i * 2; j < M; j += i)
					                st[j] = true;
					        }
					}

					bool check(int x)
					{
					    for (int i = 0; primes[i] <= x / primes[i]; i ++ ) 注意还需要满足primes[i] < a，因为只能尝试比自己小的质因子。
					        if (x % primes[i] == 0)
					            return false;
					    return true;
					}

					int main()
					{
					    init();

					    string str;
					    cin >> n >> k >> str;

					    for (int i = 0; i + k <= n; i ++ )
					    {
					        int t = stoi(str.substr(i, k));
					        if (check(t))
					        {
					            cout << str.substr(i, k) << endl;
					            return 0;
					        }
					    }

					    puts("404");

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/324426/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

8. 动态规划
		99. 1479. 最大子序列和	1007
			0. bug
			1. 笔记
			2. 注释
				1. y
				2. b
					#include <iostream>

					using namespace std;

					const int N = 10010;

					int n;
					int w[N];

					int main()
					{
					    cin >> n;
					    for (int i = 1; i <= n; i ++ ) cin >> w[i];

					    int res = -1, l, r;
						我们是用f[i]来存右端点是i的所有子序列的最大值, 因为每次更新f[i]只用到了f[i-1],更早以前的信息都不会用到了
						所以完全可以用一个变量f来存,而不是用一个数组来存
					    for (int i = 1, f = -1, start; i <= n; i ++ )
					    {
					        if (f < 0) f = 0, start = i; 如果是负数,就重头再来. 或者写成 f = w[i] + max(0, f);
					        f += w[i];
					        if (res < f) 所有区间都没有交集, 否则就可以合并成更大的数
					        {
					            res = f;
					            l = w[start], r = w[i];
					        }
					    }

					    if (res < 0) res = 0, l = w[1], r = w[n];

					    cout << res << ' ' << l << ' ' << r << endl;

					    return 0;
					}

			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		100. 1529. 最佳彩色带	1045
			0. bug
			1. 笔记
			2. 注释
				1. y
					图中的四个子集可以完全被这三个状态包含。
					#include <iostream>

					using namespace std;

					const int N = 210, M = 10010;

					int n, m, l;
					int p[N], s[M];
					int f[N][M]; 

					int main()
					{
					    cin >> n;

					    cin >> m;
					    for (int i = 1; i <= m; i ++ ) cin >> p[i];

					    cin >> l;
					    for (int i = 1; i <= l; i ++ ) cin >> s[i];

					    for (int i = 1; i <= m; i ++ )
					        for (int j = 1; j <= l; j ++ )
					        {
					            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
					            if (p[i] == s[j]) f[i][j] = max(f[i][j], f[i][j - 1] + 1);
					        }

					    cout << f[m][l] << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/311103/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		101. 1554. 找更多硬币	1068
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>

					using namespace std;


					const int N = 10010, M = 110;

					int n, m;
					int a[N];
					bool f[N][M];

					int main()
					{
					    cin >> n >> m;
					    for (int i = 1; i <= n; i ++ ) cin >> a[i];

					    sort(a + 1, a + n + 1, greater<int>());

					    f[0][0] = true;
					    for (int i = 1; i <= n; i ++ )
					        for (int j = 0; j <= m; j ++ )
					        {
					            f[i][j] = f[i - 1][j];
					            if (j >= a[i]) f[i][j] |= f[i - 1][j - a[i]];
					        }

					    if (!f[n][m]) puts("No Solution");
					    else
					    {
					        bool is_first = true;
					        while (n)
					        {
					            if (m >= a[n] && f[n - 1][m - a[n]])
					            {
					                if (is_first) is_first = false;
					                else cout << ' ';
					                cout << a[n];
					                m -= a[n];
					            }

					            n -- ;
					        }
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/311120/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		102. 1583. PAT 计数		1093
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 100010, MOD = 1e9 + 7;

					int n;
					char s[N], p[] = " PAT";
					int f[N][4];

					int main()
					{
					    cin >> s + 1;
					    n = strlen(s + 1);

					    f[0][0] = 1;
					    for (int i = 1; i <= n; i ++ )
					        for (int j = 0; j <= 3; j ++ ) 
					        {
					            f[i][j] = f[i - 1][j];
					            if (s[i] == p[j]) f[i][j] = (f[i][j] + f[i - 1][j - 1]) % MOD;
					        }

					    cout << f[n][3] << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/311139/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		103. 1591. 快速排序	1101
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <vector>

					using namespace std;

					const int N = 100010, INF = 2e9;

					int n;
					int a[N], l[N], r[N];

					int main()
					{
					    cin >> n;
					    for (int i = 1; i <= n; i ++ ) cin >> a[i];
					    for (int i = 1; i <= n; i ++ ) l[i] = max(l[i - 1], a[i]);
					    r[n + 1] = INF;
					    for (int i = n; i; i -- ) r[i] = min(r[i + 1], a[i]);

					    vector<int> res;
					    for (int i = 1; i <= n; i ++ )
					        if (l[i - 1] < a[i] && a[i] < r[i + 1])
					            res.push_back(a[i]);

					    cout << res.size() << endl;
					    if (res.size())
					    {
					        cout << res[0];
					        for (int i = 1; i < res.size(); i ++ ) cout << ' ' << res[i];
					    }
					    cout << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/311152/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

9. 哈希表
		104. 1532. 找硬币 	1048
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <unordered_set>

					using namespace std;

					int main()
					{
					    int n, m;
					    cin >> n >> m;

					    unordered_set<int> S;
					    int v1 = 1e9, v2;
					    for (int i = 0; i < n; i ++ )
					    {
					        int x;
					        cin >> x;
					        int y = m - x;
					        if (S.count(y))
					        {
					            S.insert(x);
					            if (x > y) swap(x, y);
					            if (x < v1) v1 = x, v2 = y;
					        }
					        else S.insert(x);
					    }

					    if (v1 == 1e9) puts("No Solution");
					    else cout << v1 << ' ' << v2 << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/311167/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		105. 1549. 集合相似度	1063
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <unordered_set>

					using namespace std;

					const int N = 55;

					int n;
					unordered_set<int> S[N];

					int main()
					{
					    scanf("%d", &n);

					    for (int i = 1; i <= n; i ++ )
					    {
					        int m;
					        scanf("%d", &m);
					        while (m -- )
					        {
					            int x;
					            scanf("%d", &x);
					            S[i].insert(x);
					        }
					    }

					    int k;
					    scanf("%d", &k);
					    while (k -- )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);
					        int nc = 0;
					        for (auto x : S[a]) nc += S[b].count(x);
					        int nt = S[a].size() + S[b].size() - nc;
					        printf("%.1lf%%\n", (double)nc / nt * 100);
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/311183/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		106. 1610. 朋友数	1120
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <set>

					using namespace std;

					int main()
					{
					    int n;
					    cin >> n;

					    set<int> S;
					    while (n -- )
					    {
					        int x;
					        cin >> x;
					        int s = 0;
					        while (x) s += x % 10, x /= 10;
					        S.insert(s);
					    }

					    cout << S.size() << endl;

					    bool is_first = true;
					    for (auto x : S)
					    {
					        if (is_first) is_first = false;
					        else cout << ' ';
					        cout << x;
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/311187/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		107. 1637. 漏掉的数字	1144
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <unordered_set>

					using namespace std;

					int main()
					{
					    int n;
					    cin >> n;

					    unordered_set<int> S;
					    while (n -- )
					    {
					        int x;
					        cin >> x;
					        S.insert(x);
					    }

					    int res = 1;
					    while (S.count(res)) res ++ ;

					    cout << res << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/311198/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		108. 1642. 危险品装箱	1149
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <unordered_set>

					using namespace std;

					const int N = 10010;

					int n, m;
					int a[N], b[N];

					int main()
					{
					    scanf("%d%d", &n, &m);
					    for (int i = 0; i < n; i ++ ) scanf("%d%d", &a[i], &b[i]);

					    while (m -- )
					    {
					        int k;
					        scanf("%d", &k);
					        unordered_set<int> S;
					        while (k -- )
					        {
					            int x;
					            scanf("%d", &x);
					            S.insert(x);
					        }

					        bool success = true;
					        for (int i = 0; i < n; i ++ )
					            if (S.count(a[i]) && S.count(b[i]))
					            {
					                success = false;
					                break;
					            }

					        if (success) puts("Yes");
					        else puts("No");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/311212/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		109. 1564. 哈希 		1078
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					const int N = 10010;

					int s, n;
					int h[N];

					bool is_prime(int x)
					{
					    if (x == 1) return false;

					    for (int i = 2; i * i <= x; i ++ )
					        if (x % i == 0)
					            return false;

					    return true;
					}

					int find(int x)
					{
					    int t = x % s;

					    for (int k = 0; k < s; k ++ )
					    {
					        int i = (t + k * k) % s;
					        if (!h[i]) return i;
					    }

					    return -1;
					}

					int main()
					{
					    cin >> s >> n;

					    while (!is_prime(s)) s ++ ;

					    for (int i = 0; i < n; i ++ )
					    {
					        int x;
					        cin >> x;
					        int t = find(x);

					        if (t == -1) printf("-");
					        else
					        {
					            h[t] = x;
					            printf("%d", t);
					        }

					        if (i != n - 1) printf(" ");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/316841/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		110. 1630. 期终成绩	1137
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <unordered_map>
					#include <algorithm>
					#include <vector>
					#include <cmath>

					using namespace std;

					struct Student
					{
					    string id;
					    int p, m, f, s;

					    Student(): p(-1), m(-1), f(-1), s(0) {}

					    void calc()
					    {
					        if (f >= m) s = f;
					        else s = round(m * 0.4 + f * 0.6);
					    }

					    bool operator< (const Student& t) const
					    {
					        if (s != t.s) return s > t.s;
					        return id < t.id;
					    }
					};

					int main()
					{
					    int p, m, n;
					    cin >> p >> m >> n;

					    unordered_map<string, Student> hash;
					    string id;
					    int s;
					    for (int i = 0; i < p; i ++ )
					    {
					        cin >> id >> s;
					        hash[id].id = id;
					        hash[id].p = s;
					    }

					    for (int i = 0; i < m; i ++ )
					    {
					        cin >> id >> s;
					        hash[id].id = id;
					        hash[id].m = s;
					    }

					    for (int i = 0; i < n; i ++ )
					    {
					        cin >> id >> s;
					        hash[id].id = id;
					        hash[id].f = s;
					    }

					    vector<Student> students;
					    for (auto item : hash)
					    {
					        auto stu = item.second;

					        stu.calc();
					        if (stu.p >= 200 && stu.s >= 60)
					            students.push_back(stu);
					    }

					    sort(students.begin(), students.end());

					    for (auto s : students)
					        cout << s.id << ' ' << s.p << ' ' << s.m << ' ' << s.f << ' ' << s.s << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/316865/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		111. 1638. 哈希 - 平均查找时间	1145
			0. bug
			1. 笔记
				1. 
					在哈希表h[ ] ，插入完所有数之后，哈希表没有全部满
					进行查询m个数字时

					如果哈希表中不存在这个数字，但是
					if (!h[i] || h[i] == x) return i;
					刚刚这个地方是0，还是算 成功探测到这个数字嘛？

					疑问就是，查询的数字不在哈希表里面，难道不应该是算Tsize + 1嘛？
					yxc   4个月前     回复
					PAT的某些题目确实很奇怪，不太清楚题目为何这样规定，但他就是这么来计算标准答案的。所以我们在题面中给大家特殊声明了这一点： 如果查找了 TSize 次，每次查找的位置上均有数，但都不等于要查找的数，则认为查找时间是 TSize+1。
			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					const int N = 10010;

					int s, n, m;
					int h[N];

					bool is_prime(int x)
					{
					    if (x == 1) return false;

					    for (int i = 2; i * i <= x; i ++ )
					        if (x % i == 0)
					            return false;

					    return true;
					}

					int find(int x, int &cnt)
					{
					    int t = x % s;

					    cnt = 1;
					    for (int k = 0; k < s; k ++, cnt ++ )
					    {
					        int i = (t + k * k) % s;
					        if (!h[i] || h[i] == x) return i;
					    }

					    return -1;
					}

					int main()
					{
					    cin >> s >> n >> m;

					    while (!is_prime(s)) s ++ ;

					    for (int i = 0; i < n; i ++ )
					    {
					        int x, count;
					        cin >> x;

					        int t = find(x, count);
					        if (t == -1) printf("%d cannot be inserted.\n", x);
					        else h[t] = x;
					    }

					    int cnt = 0;
					    for (int i = 0; i < m; i ++ )
					    {
					        int x, count;
					        cin >> x;
					        find(x, count);
					        cnt += count;
					    }

					    printf("%.1lf\n", (double)cnt / m);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/316852/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

10. 并查集
		112. 836. 合并集合 模拟题
			0. bug
			1. 笔记
				1.
					最后判断两个元素是否在一个集合中，直接使用p[x]==p[y]来判断为啥不行呢，
					之前在合并路径压缩后p[x]和find(x)不应该是一个结果的吗。
						p[x]不一定表示x的根节点。
			2. 注释
				1. y
					#include <cstring>
					#include <iostream>
					#include <algorithm>

					using namespace std;

					const int N = 100010;

					int n, m;
					int p[N];

					int find(int x)
					{
					    if (p[x] != x) p[x] = find(p[x]);
					    return p[x];
					}

					int main()
					{
					    cin >> n >> m;
					    for (int i = 1; i <= n; i ++ ) p[i] = i;

					    while (m -- )
					    {
					        char op;
					        int x, y;
					        cin >> op >> x >> y;
					        if (op == 'M') p[find(x)] = find(y);
					        else
					        {
					            if (find(x) == find(y)) puts("Yes");
					            else puts("No");
					        }
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/316906/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		113. 1485. 战争中的城市	1013
			0. bug
			1. 笔记
				1. 这道题真的很有意思, 可以看视频01:55, 也就是如果删除掉了一个点x, 那么所有和这个点x有关的边e (也就是边e的一个端点是x), 这个边e就不存在了
					不存在之后, 剩余的图, 有多少连通块, 假设有n个连通块, 那么我们需要(n-1)条边链接这n个连通块, 从而变成唯一的联通块
				2. 思路:
					1. 对于每个边e, 看他的两个端点, 如果两个端点都不包括被摧毁的x, 那么说明这个边e是保留的
					2. 既然边e的两个端点a,b是链接起来的, 那么我们就合并两个部分:
						int pa = find(a), pb = find(b);
		                if (pa != pb)
		                {
		                    p[pa] = pb; pa的父亲 == pb
		                    cnt -- ; 最后的cnt就是联通块个数
		                }
		        3. 复杂度:
		        	1. 对于k个询问, 每个询问都要遍历m个边(因为要判断这个边是否和删除的点x相关)
		        		所以复杂度是k*m
		        		刚好题目说了k*m < 350w, 然后题目限制是0.4s, 也就是4000w, 所以是够的!
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 1010, M = 500010;

					int n, m, k;
					int p[N];

					struct Edge
					{
					    int a, b;
					}e[M];

					int find(int x)
					{
					    if (p[x] != x) p[x] = find(p[x]);
					    return p[x];
					}

					int main()
					{
					    scanf("%d%d%d", &n, &m, &k);

					    for (int i = 0; i < m; i ++ ) scanf("%d%d", &e[i].a, &e[i].b);

					    while (k -- )
					    {
					        int x;
					        scanf("%d", &x); 要删除的城市, 要删除的点 : x

					        for (int i = 1; i <= n; i ++ ) p[i] = i;

					        int cnt = n - 1;
					        for (int i = 0; i < m; i ++ )
					        {
					            int a = e[i].a, b = e[i].b;
					            if (a != x && b != x) 说明这条边e 和我们要删除的点不想管
					            {
					                int pa = find(a), pb = find(b);
					                if (pa != pb)
					                {
					                    p[pa] = pb;
					                    cnt -- ;
					                }
					            }
					        }

					        printf("%d\n", cnt - 1);
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/316877/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		114. 1604. 家产	1604
			0. bug
			1. 笔记
				很棒的题目!
				1. 最多7k条边, 因为最多1k个点, 每个点最多7个临点(父母+5个孩子)
				2. 很厉害的几个技巧:
					1. 自己创建边e:
						e[m ++ ] = {id, father};
						最后,一共有m条边
					2. 合并的依据: 一个边的两个点需要被合并
						其余信息的合并, c, ha, hc的合并的时机:
							都写在一起.
							c的合并: c[pb] += c[pa];	 注意, 初始化是for(int i = 0; i < N; i++) c[i] = 1;
						for (int i = 0; i < m; i ++ )
					    {
					        int a = e[i].a, b = e[i].b;

					        st[a] = st[b] = true;
					        int pa = find(a), pb = find(b);
					        if (pa != pb)
					        {
					            if (pb > pa) swap(pa, pb); 看谁的id小, 谁就是老大
					            c[pb] += c[pa];		我们只更新老大的信息: c, hc, ha
					            hc[pb] += hc[pa];
					            ha[pb] += ha[pa];
					            p[pa] = pb;
					        }
					    }
					3. 我们是遍历了全部的点: for(int i = 0; i < N; i++)注意是N!
						但是因为我们用了st[t] = true, 标记, 所以不怕
					4. 遍历所有点的时候, 如何找到每个家族的boss:
						for (int i = 0; i < N; i ++ )
					        if (st[i] && p[i] == i) 也就是: p[i] == i的就是boss
					            family.push_back({i, c[i], hc[i], ha[i]});
					5. operator比较的时候:
						因为老师认为:
							比较(ha / c) ? (t.ha / t.c) 可能会存在除不尽,小数的差异. 所以:
							采用了乘法 if (ha * t.c != t.ha * c) return ha * t.c > t.ha * c;
			2. 注释
				1. y
					#include <iostream>
					#include <algorithm>
					#include <vector>

					using namespace std;

					const int N = 10010;

					int n;
					int p[N], c[N], hc[N], ha[N];
					p: 并查集, c: 家族的人数, hc: 家族的房子数, ha: 家族的房子面积
					bool st[N];

					struct Edge
					{
					    int a, b;
					}e[N];

					struct Family
					{
					    int id, c, hc, ha;

					    bool operator< (const Family &t) const
					    {
					        // ha / c ? t.ha / t.c
					        if (ha * t.c != t.ha * c) return ha * t.c > t.ha * c;
					        return id < t.id;
					    }
					};

					int find(int x)
					{
					    if (p[x] != x) p[x] = find(p[x]);
					    return p[x];
					}

					int main()
					{
					    cin >> n;

					    int m = 0;
					    for (int i = 0; i < n; i ++ )
					    {
					        int id, father, mother, k;
					        cin >> id >> father >> mother >> k;

					        st[id] = true;
					        if (father != -1) e[m ++ ] = {id, father};
					        if (mother != -1) e[m ++ ] = {id, mother};
					        for (int j = 0; j < k; j ++ )
					        {
					            int son;
					            cin >> son;
					            e[m ++ ] = {id, son};
					        }

					        cin >> hc[id] >> ha[id];
					    }

					    for (int i = 0; i < N; i ++ ) p[i] = i, c[i] = 1;
					    for (int i = 0; i < m; i ++ )
					    {
					        int a = e[i].a, b = e[i].b;

					        st[a] = st[b] = true;
					        int pa = find(a), pb = find(b);
					        if (pa != pb)
					        {
					            if (pb > pa) swap(pa, pb);
					            c[pb] += c[pa];
					            hc[pb] += hc[pa];
					            ha[pb] += ha[pa];
					            p[pa] = pb;
					        }
					    }

					    vector<Family> family;
					    for (int i = 0; i < N; i ++ )
					        if (st[i] && p[i] == i)
					            family.push_back({i, c[i], hc[i], ha[i]});

					    sort(family.begin(), family.end());

					    cout << family.size() << endl;
					    for (auto f : family)
					        printf("%04d %d %.3lf %.3lf\n", f.id, f.c, (double)f.hc / f.c, (double)f.ha / f.c);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/316891/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		115. 1608. 森林里的鸟	1118
			0. bug
			1. 笔记
				1. 这道题不难, 不过需要一个逻辑:
					之前求有多少个连通分量的方法:
						1. cnt = n; 其中n是总的节点数
						2. 然后每次if(find(a) != find(b)){合并; cnt--}
						3. 也就是 连通分量a = 总数n - 合并次数b
					现在求有多少个连通分量的方法:
						1. 因为不知道n是多少, 所以, 我就先计算合并次数b
							cnt = 0; 每次 if(find(a) != find(b)){合并; cnt++}
							最后当我知道总数n是多少, 
							连通分量a = 总数n - 合并次数cnt
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 10010;

					int n;
					int birds[10];
					int p[N];
					bool st[N];

					int find(int x)
					{
					    if (p[x] != x) p[x] = find(p[x]);
					    return p[x];
					}

					int main()
					{
					    scanf("%d", &n);

					    for (int i = 0; i < N; i ++ ) p[i] = i;

					    int cnt = 0;
					    for (int i = 0; i < n; i ++ )
					    {
					        int k;
					        scanf("%d", &k);
					        for (int j = 0; j < k; j ++ )
					        {
					            scanf("%d", &birds[j]);
					            st[birds[j]] = true;
					        }

					        for (int j = 1; j < k; j ++ )
					        {
					            int a = birds[j - 1], b = birds[j];
					            a = find(a), b = find(b);
					            if (a != b)
					            {
					                p[a] = b;
					                cnt ++ ;
					            }
					        }
					    }

					    int tot = 0;
					    for (int i = 0; i < N; i ++ ) tot += st[i];

					    printf("%d %d\n", tot - cnt, tot);

					    int q;
					    scanf("%d", &q);
					    while (q -- )
					    {
					        int a, b;
					        scanf("%d%d", &a, &b);
					        if (find(a) == find(b)) puts("Yes");
					        else puts("No");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/316903/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		116. 1597. 社会集群	1107
			0. bug
			1. 笔记
				1. 思路:
					1. 还是使用并查集:
						1. 每个hobby链上, 挂着每个人
							所以用vector<int> hobby[N]
						2. 然后从hobby的每个元素中, 将所有的人合并
							我之前的疑惑:
								如果把元素a的所有人合并
								把元素b的所有人合并
								那如果有一个人c有爱好a和爱好b
								那么怎么将a,b的所有人合并呢?
							这是一个愚蠢的问题
								因为当c和爱好a的所有人合并的时候,
								又当c和爱好b的所有人合并的时候,
								b和a的所有人, 自然就合并了, 因为这是并查集啊!
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>
					#include <vector>

					using namespace std;

					const int N = 1010;

					int n;
					vector<int> hobby[N];
					int p[N];
					int cnt[N];

					int find(int x)
					{
					    if (p[x] != x) p[x] = find(p[x]);
					    return p[x];
					}

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ )
					    {
					        int cnt;
					        scanf("%d:", &cnt);
					        while (cnt -- )
					        {
					            int h;
					            cin >> h;
					            hobby[h].push_back(i);
					        }
					    }

					    for (int i = 0; i < n; i ++ ) p[i] = i;

					    for (int i = 1; i <= 1000; i ++ )
					        for (int j = 1; j < hobby[i].size(); j ++ )
					        {
					            int a = hobby[i][0], b = hobby[i][j];
					            p[find(a)] = find(b);
					        }

					    for (int i = 0; i < n; i ++ ) cnt[find(i)] ++ ;

					    sort(cnt, cnt + n, greater<int>());

					    int k = 0;
					    while (cnt[k]) k ++ ;

					    cout << k << endl;
					    cout << cnt[0];
					    for (int i = 1; i < k; i ++ ) cout << ' ' << cnt[i];
					    cout << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/330505/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

11. 模拟
		117. 1480. 电梯	1008
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					int main()
					{
					    int n;
					    cin >> n;

					    int res = 0;
					    int last = 0;
					    while (n -- )
					    {
					        int cur;
					        cin >> cur;

					        if (last < cur) res += (cur - last) * 6;
					        else res += (last - cur) * 4;
					        res += 5;

					        last = cur;
					    }

					    cout << res << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/324440/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		118. 1483. 世界杯投注	1011
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					int main()
					{
					    double res = 1;
					    for (int i = 0; i < 3; i ++ )
					    {
					        double w, t, l;
					        cin >> w >> t >> l;
					        double x = max(w, max(t, l));
					        if (x == w) cout << "W ";
					        else if (x == t) cout << "T ";
					        else cout << "L ";
					        res *= x;
					    }

					    printf("%.2lf\n", (res * 0.65 - 1) * 2);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/324452/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		119. 1486. 排队等候	1014
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <queue>
					#include <unordered_map>

					using namespace std;

					const int N = 20;

					int n, m, k, Q;
					int sum[N];
					queue<int> q[N];

					int main()
					{
					    cin >> n >> m >> k >> Q;

					    unordered_map<int, int> hash;
					    for (int i = 1; i <= k; i ++ )
					    {
					        int s;
					        cin >> s;

					        int t = 0;
					        for (int j = 0; j < n; j ++ )
					            if (i <= n * m)
					            {
					                if (q[j].size() < q[t].size()) t = j;
					            }
					            else
					            {
					                if (q[j].front() < q[t].front()) t = j;
					            }

					        sum[t] += s;
					        if (i > n * m) q[t].pop();
					        q[t].push(sum[t]);

					        if (sum[t] - s < 540) hash[i] = sum[t];
					    }

					    while (Q -- )
					    {
					        int id;
					        cin >> id;
					        if (hash.count(id)) printf("%02d:%02d\n", hash[id] / 60 + 8, hash[id] % 60);
					        else puts("Sorry");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/324473/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		120. 1515. U 形 Hello World	1031
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 100;

					char g[N][N];

					int main()
					{
					    string str;
					    cin >> str;

					    int n = str.size();
					    int n1 = (n + 2) / 3;
					    int n2 = n + 2 - n1 * 2;

					    int k = 0;
					    for (int i = 0; i < n1; i ++ ) g[i][0] = str[k ++ ];
					    for (int i = 1; i < n2; i ++ ) g[n1 - 1][i] = str[k ++ ];
					    for (int i = n1 - 2; i >= 0; i -- ) g[i][n2 - 1] = str[k ++ ];

					    for (int i = 0; i < n1; i ++ )
					    {
					        for (int j = 0; j < n2; j ++ )
					            if (g[i][j]) cout << g[i][j];
					            else cout << ' ';
					        cout << endl;
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/324486/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		121. 1525. 独一无二	1041
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>

					using namespace std;

					const int N = 100010;

					int n;
					int a[N], c[N];

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ )
					    {
					        cin >> a[i];
					        c[a[i]] ++ ;
					    }

					    for (int i = 0; i < n; i ++ )
					        if (c[a[i]] == 1)
					        {
					            cout << a[i] << endl;
					            return 0;
					        }

					    puts("None");
					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/324522/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		122. 1526. 洗牌机	1042
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 60;

					int k;
					int q[N], p[N], w[N];

					void print(int x)
					{
					    if (x <= 13) cout << 'S' << x;
					    else if (x <= 26) cout << 'H' << x - 13;
					    else if (x <= 39) cout << 'C' << x - 26;
					    else if (x <= 52) cout << 'D' << x - 39;
					    else cout << 'J' << x - 52;
					}

					int main()
					{
					    cin >> k;
					    for (int i = 1; i <= 54; i ++ ) cin >> q[i];
					    for (int i = 1; i <= 54; i ++ ) p[i] = i;

					    while (k -- )
					    {
					        memcpy(w, p, sizeof w);
					        for (int i = 1; i <= 54; i ++ ) p[q[i]] = w[i];
					    }

					    for (int i = 1; i <= 54; i ++ )
					    {
					        print(p[i]);
					        if (i != 54) cout << ' ';
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/324515/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		123. 1531. 课程学生列表	1047
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 2510;

					int n, k;
					vector<string> lesson[N];

					int main()
					{
					    scanf("%d%d", &n, &k);

					    char str[5];
					    while (n -- )
					    {
					        int cnt;
					        scanf("%s%d", str, &cnt);
					        while (cnt -- )
					        {
					            int l;
					            scanf("%d", &l);
					            lesson[l].push_back(str);
					        }
					    }

					    for (int i = 1; i <= k; i ++ )
					    {
					        printf("%d %d\n", i, lesson[i].size());
					        sort(lesson[i].begin(), lesson[i].end());
					        for (auto id : lesson[i])
					            printf("%s\n", id.c_str());
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/324513/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		124. 1540. 主导颜色	1054
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <unordered_map>

					using namespace std;

					int main()
					{
					    int n, m;
					    scanf("%d%d", &n, &m);

					    unordered_map<int, int> cnt;
					    for (int i = 0; i < n * m; i ++ )
					    {
					        int x;
					        scanf("%d", &x);
					        if ( ++ cnt[x] > n * m / 2)
					        {
					            printf("%d\n", x);
					            break;
					        }
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/324520/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		125. 1542. 老鼠和大米	1056
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 1010;

					int n, m;
					int w[N], ans[N];

					int main()
					{
					    cin >> n >> m;
					    for (int i = 0; i < n; i ++ ) cin >> w[i];
					    vector<int> cur(n);

					    for (int i = 0; i < n; i ++ ) cin >> cur[i];

					    while (cur.size() > 1)
					    {
					        vector<int> next;
					        int remain = (cur.size() + m - 1) / m;

					        for (int i = 0; i < cur.size();)
					        {
					            int j = min((int)cur.size(), i + m);

					            int t = i;
					            for (int k = i; k < j; k ++ )
					                if (w[cur[k]] > w[cur[t]])
					                     t = k;
					            next.push_back(cur[t]);
					            for (int k = i; k < j; k ++ )
					                if (k != t)
					                    ans[cur[k]] = remain + 1;

					            i = j;
					        }

					        cur = next;
					    }

					    ans[cur[0]] = 1;

					    cout << ans[0];
					    for (int i = 1; i < n; i ++ ) cout << ' ' << ans[i];
					    cout << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/330514/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		126. 1548. 才华与德行	1062
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 100010;


					int n, L, H;
					struct Person
					{
					    int id, moral, talent;
					    int level;

					    int total() const
					    {
					        return moral + talent;
					    }

					    bool operator< (const Person &t) const
					    {
					        if (level != t.level) return level < t.level;
					        if (total() != t.total()) return total() > t.total();
					        if (moral != t.moral) return moral > t.moral;
					        return id < t.id;
					    }
					}p[N];

					int main()
					{
					    scanf("%d%d%d", &n, &L, &H);

					    int m = 0;
					    for (int i = 0; i < n; i ++ )
					    {
					        int id, moral, talent;
					        scanf("%d%d%d", &id, &moral, &talent);
					        if (moral < L || talent < L) continue;
					        int level;
					        if (moral >= H && talent >= H) level = 1;
					        else if (moral >= H && talent < H) level = 2;
					        else if (moral < H && talent < H && moral >= talent) level = 3;
					        else level = 4;

					        p[m ++ ] = {id, moral, talent, level};
					    }

					    sort(p, p + m);

					    printf("%d\n", m);
					    for (int i = 0; i < m; i ++ )
					        printf("%08d %d %d\n", p[i].id, p[i].moral, p[i].talent);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/330521/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		127. 1551. A + B 和 C 1065
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					typedef long long LL;

					bool check(LL a, LL b, LL c)
					{
					    LL d = a + b;
					    if (a >= 0 && b >= 0 && d < 0) return true;
					    if (a < 0 && b < 0 && d >= 0) return false;
					    return a + b > c;
					}

					int main()
					{
					    int n;
					    cin >> n;

					    for (int i = 1; i <= n; i ++ )
					    {
					        LL a, b, c;
					        scanf("%lld%lld%lld", &a, &b, &c);
					        if (check(a, b, c)) printf("Case #%d: true\n", i);
					        else printf("Case #%d: false\n", i);
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/330531/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		128. 1555. 数字黑洞	1069
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <vector>
					#include <algorithm>

					using namespace std;

					vector<int> get(int n)
					{
					    int nums[4];
					    for (int i = 0; i < 4; i ++ )
					    {
					        nums[i] = n % 10;
					        n /= 10;
					    }

					    sort(nums, nums + 4);
					    int a = 0;
					    for (int i = 0; i < 4; i ++ ) a = a * 10 + nums[i];

					    reverse(nums, nums + 4);
					    int b = 0;
					    for (int i = 0; i < 4; i ++ ) b = b * 10 + nums[i];

					    return {b, a};
					}

					int main()
					{
					    int n;
					    cin >> n;

					    do
					    {
					        auto t = get(n);
					        printf("%04d - %04d = %04d\n", t[0], t[1], t[0] - t[1]);

					        n = t[0] - t[1];
					    } while (n && n != 6174);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/330537/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		129. 1566. 研究生入学	1080
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>
					#include <vector>

					using namespace std;

					const int N = 40010, M = 110, K = 5;

					int n, m, k;
					int cnt[N];
					int wish[N];
					vector<int> uty[M];

					struct Person
					{
					    int id, ge, gi;
					    int wish[K];

					    int total() const
					    {
					        return ge + gi;
					    }

					    bool operator< (const Person &t) const
					    {
					        if (total() != t.total()) return total() > t.total();
					        return ge > t.ge;
					    }

					    bool operator== (const Person &t) const
					    {
					        return ge == t.ge && gi == t.gi;
					    }
					}p[N];

					int main()
					{
					    scanf("%d%d%d", &n, &m, &k);
					    for (int i = 0; i < m; i ++ ) scanf("%d", &cnt[i]);
					    for (int i = 0; i < n; i ++ )
					    {
					        p[i].id = i;
					        scanf("%d%d", &p[i].ge, &p[i].gi);

					        for (int j = 0; j < k; j ++ )
					            scanf("%d", &p[i].wish[j]);
					    }

					    sort(p, p + n);

					    memset(wish, -1, sizeof wish);
					    for (int i = 0; i < n;)
					    {
					        int j = i + 1;
					        while (j < n && p[i] == p[j]) j ++ ;

					        for (int t = i; t < j; t ++ )
					            for (int u = 0; u < k; u ++ )
					            {
					                int w = p[t].wish[u];
					                if (cnt[w] > uty[w].size())
					                {
					                    wish[t] = w;
					                    break;
					                }
					            }

					        for (int t = i; t < j; t ++ )
					            if (wish[t] != -1)
					                uty[wish[t]].push_back(p[t].id);

					        i = j;
					    }

					    for (int i = 0; i < m; i ++ )
					    {
					        if (uty[i].size())
					        {
					            sort(uty[i].begin(), uty[i].end());
					            printf("%d", uty[i][0]);
					            for (int j = 1; j < uty[i].size(); j ++ )
					                printf(" %d", uty[i][j]);
					        }
					        puts("");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/330563/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		130. 1569. 成绩单	1083
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 110;

					int n;
					struct Person
					{
					    string name, id;
					    int grade;

					    bool operator< (const Person &t) const
					    {
					        return grade > t.grade;
					    }
					}p[N];

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ ) cin >> p[i].name >> p[i].id >> p[i].grade;

					    int g1, g2;
					    cin >> g1 >> g2;

					    int m = 0;
					    for (int i = 0; i < n; i ++ )
					        if (p[i].grade >= g1 && p[i].grade <= g2)
					            p[m ++ ] = p[i];

					    if (!m) puts("NONE");
					    else
					    {
					        sort(p, p + m);
					        for (int i = 0; i < m; i ++ )
					            cout << p[i].name << ' ' << p[i].id << endl;
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/330572/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		131. 1582. 买还是不买	1092
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <unordered_map>

					using namespace std;

					int main()
					{
					    string a, b;
					    cin >> a >> b;

					    unordered_map<char, int> S;
					    for (auto c : a) S[c] ++ ;
					    for (auto c : b) S[c] -- ;

					    int sp = 0, sn = 0;
					    for (auto item : S)
					        if (item.second > 0) sp += item.second;
					        else sn -= item.second;

					    if (sn) printf("No %d\n", sn);
					    else printf("Yes %d\n", sp);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/330578/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		132. 1585. 校园内的汽车	1095
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>
					#include <unordered_map>
					#include <vector>

					using namespace std;

					struct Event
					{
					    int tm, status;

					    bool operator< (const Event &t) const
					    {
					        return tm < t.tm;
					    }
					};

					int get(vector<Event>& ets)
					{
					    int res = 0;
					    for (int i = 0; i < ets.size(); i += 2)
					        res += ets[i + 1].tm - ets[i].tm;

					    return res;
					}

					int main()
					{
					    int n, m;
					    scanf("%d%d", &n, &m);

					    unordered_map<string, vector<Event>> cars;

					    char id[10], status[10];
					    for (int i = 0; i < n; i ++ )
					    {
					        int hh, mm, ss;
					        scanf("%s %d:%d:%d %s", id, &hh, &mm, &ss, status);
					        int t = hh * 3600 + mm * 60 + ss;
					        int s = 0;
					        if (status[0] == 'o') s = 1;
					        cars[id].push_back({t, s});
					    }

					    vector<Event> events;
					    for (auto& item : cars)
					    {
					        auto& ets = item.second;
					        sort(ets.begin(), ets.end());
					        int k = 0;

					        for (int i = 0; i < ets.size(); i ++ )
					            if (ets[i].status == 0)
					            {
					                if (i + 1 < ets.size() && ets[i + 1].status == 1)
					                {
					                    ets[k ++ ] = ets[i];
					                    ets[k ++ ] = ets[i + 1];
					                    i ++ ;
					                }
					            }

					        ets.erase(ets.begin() + k, ets.end());
					        for (int i = 0; i < k; i ++ ) events.push_back(ets[i]);
					    }

					    sort(events.begin(), events.end());

					    int k = 0, sum = 0;
					    while (m -- )
					    {
					        int hh, mm, ss;
					        scanf("%d:%d:%d", &hh, &mm, &ss);
					        int t = hh * 3600 + mm * 60 + ss;

					        while (k < events.size() && events[k].tm <= t)
					        {
					            if (events[k].status == 0) sum ++ ;
					            else sum -- ;
					            k ++ ;
					        }

					        printf("%d\n", sum);
					    }

					    int maxt = 0;
					    for (auto& item : cars) maxt = max(maxt, get(item.second));

					    vector<string> res;
					    for (auto& item : cars)
					        if (get(item.second) == maxt)
					            res.push_back(item.first);

					    sort(res.begin(), res.end());

					    for (int i = 0; i < res.size(); i ++ ) printf("%s ", res[i].c_str());

					    printf("%02d:%02d:%02d\n", maxt / 3600, maxt % 3600 / 60, maxt % 60);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/330592/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		133. 1595. 螺旋矩阵	1105
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>
					#include <vector>

					using namespace std;

					const int N = 10010;

					int n;
					int w[N];

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ ) cin >> w[i];

					    sort(w, w + n, greater<int>());

					    int r, c;


					    for (int i = 1; i <= n / i; i ++ )
					        if (n % i == 0)
					        {
					            r = n / i;
					            c = i;
					        }

					    vector<vector<int>> res(r, vector<int>(c));

					    int dx[] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
					    for (int i = 0, x = 0, y = 0, d = 1; i < n; i ++ )
					    {
					        res[x][y] = w[i];
					        int a = x + dx[d], b = y + dy[d];
					        if (a < 0 || a >= r || b < 0 || b >= c || res[a][b])
					        {
					            d = (d + 1) % 4;
					            a = x + dx[d], b = y + dy[d];
					        }
					        x = a, y = b;
					    }

					    for (int i = 0; i < r; i ++ )
					    {
					        cout << res[i][0];
					        for (int j = 1; j < c; j ++ )
					            cout << ' ' << res[i][j];
					        cout << endl;
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/330601/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		134. 1599. 合影	1109
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 10010;

					int n, m;
					struct Person
					{
					    string name;
					    int h;
					    bool operator< (const Person &t) const
					    {
					        if (h != t.h) return h > t.h;
					        return name < t.name;
					    }
					}p[N];
					string line[N];

					int main()
					{
					    cin >> n >> m;

					    for (int i = 0; i < n; i ++ ) cin >> p[i].name >> p[i].h;
					    sort(p, p + n);

					    for (int i = 0, j = 0; i < m; i ++ )
					    {
					        int len = n / m;
					        if (!i) len += n % m;  // 特判最后一排
					        for (int r = len / 2 + 1, l = r - 1; l > 0 || r <= len; l --, r ++ )
					        {
					            if (r <= len) line[r] = p[j ++ ].name;
					            if (l > 0) line[l] = p[j ++ ].name;
					        }

					        cout << line[1];
					        for (int k = 2; k <= len; k ++ ) cout << ' ' << line[k];
					        cout << endl;
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/331536/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		135. 1614. 单身狗	1121
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>
					#include <unordered_set>

					using namespace std;

					const int N = 50010, M = 10010;

					struct Couple
					{
					    int a, b;
					}c[N];
					int ans[M];

					int main()
					{
					    int n, m;
					    scanf("%d", &n);
					    for (int i = 0; i < n; i ++ ) scanf("%d%d", &c[i].a, &c[i].b);

					    scanf("%d", &m);
					    unordered_set<int> S;
					    for (int i = 0; i < m; i ++ )
					    {
					        int id;
					        scanf("%d", &id);
					        S.insert(id);
					    }

					    for (int i = 0; i < n; i ++ )
					    {
					        int a = c[i].a, b = c[i].b;
					        if (S.count(a) && S.count(b))
					        {
					            S.erase(a);
					            S.erase(b);
					        }
					    }

					    int k = 0;
					    for (auto id : S) ans[k ++ ] = id;
					    sort(ans, ans + k);

					    printf("%d\n", k);

					    if (k)
					    {
					        printf("%05d", ans[0]);
					        for (int i = 1; i < k; i ++ ) printf(" %05d", ans[i]);
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/331549/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		136. 1621. N 皇后问题	1128
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 1010;

					int n;
					bool row[N], dg[N * 2], udg[N * 2];

					int main()
					{
					    int T;
					    scanf("%d", &T);

					    while (T -- )
					    {
					        scanf("%d", &n);

					        memset(row, 0, sizeof row);
					        memset(dg, 0, sizeof dg);
					        memset(udg, 0, sizeof udg);
					        bool success = true;
					        for (int y = 1; y <= n; y ++ )
					        {
					            int x;
					            scanf("%d", &x);
					            if (row[x] || dg[x + y] || udg[y - x + n]) success = false;
					            row[x] = dg[x + y] = udg[y - x + n] = true;
					        }

					        if (success) puts("YES");
					        else puts("NO");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/331562/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		137. 1622. 推荐系统	1129
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 50010;

					int n, m;
					int cnt[N];
					int top_k[11];

					int main()
					{
					    scanf("%d%d", &n, &m);

					    int k = 0;
					    for (int i = 0; i < n; i ++ )
					    {
					        int id;
					        scanf("%d", &id);
					        if (i)
					        {
					            printf("%d:", id);
					            for (int j = 0; j < k; j ++ ) printf(" %d", top_k[j]);
					            puts("");
					        }

					        cnt[id] ++ ;

					        bool exists = false;
					        for (int j = 0; j < k; j ++ )
					            if (top_k[j] == id)
					            {
					                exists = true;
					                break;
					            }
					        if (!exists) top_k[k ++ ] = id;
					        sort(top_k, top_k + k, [](int x, int y){
					            if (cnt[x] != cnt[y]) return cnt[x] > cnt[y];
					            return x < y;
					        });

					        k = min(k, m);
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/331589/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		138. 1625. 切整数	1132
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					int main()
					{
					    int T;
					    cin >> T;

					    while (T -- )
					    {
					        string number;
					        cin >> number;

					        int len = number.size() / 2;
					        int left = stoi(number.substr(0, len));
					        int right = stoi(number.substr(len));
					        int n = stoi(number);

					        if (left * right && n % (left * right) == 0) puts("Yes");
					        else puts("No");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/331597/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		139. 1633. 外观数列	1140
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					int main()
					{
					    int d, n;
					    cin >> d >> n;

					    string cur = to_string(d);
					    for (int k = 0; k < n - 1; k ++ )
					    {
					        string next;
					        for (int i = 0; i < cur.size();)
					        {
					            int j = i + 1;
					            while (j < cur.size() && cur[i] == cur[j]) j ++ ;
					            next += cur[i] + to_string(j - i);
					            i = j;
					        }
					        cur = next;
					    }

					    cout << cur << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/331608/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		140. 1640. 堆 	1147
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 1010;

					int n;
					int h[N];

					void dfs(int u)
					{
					    if (u * 2 <= n) dfs(u * 2);
					    if (u * 2 + 1 <= n) dfs(u * 2 + 1);

					    printf("%d", h[u]);
					    if (u != 1) printf(" ");
					}

					int main()
					{
					    int T;
					    scanf("%d%d", &T, &n);

					    while (T -- )
					    {
					        for (int i = 1; i <= n; i ++ ) scanf("%d", &h[i]);

					        bool lt = false, gt = false;
					        for (int i = 1; i <= n; i ++ )
					            for (int j = 0; j < 2; j ++ )
					                if (i * 2 + j <= n)
					                {
					                    int a = h[i], b = h[i * 2 + j];
					                    if (a < b) lt = true;
					                    else gt = true;
					                }

					        if (lt && gt) puts("Not Heap");
					        else if (lt) puts("Min Heap");
					        else puts("Max Heap");

					        dfs(1);
					        puts("");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/331617/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

12. 贪心
		141. 1521. 魔术卷	1037
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 100010;

					int n, m;
					int a[N], b[N];

					int main()
					{
					    scanf("%d", &n);
					    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
					    scanf("%d", &m);
					    for (int i = 0; i < n; i ++ ) scanf("%d", &b[i]);

					    sort(a, a + n);
					    sort(b, b + m);

					    int res = 0;
					    for (int i = 0, j = 0; i < n && j < m && a[i] < 0 && b[j] < 0; i ++, j ++ )
					        res += a[i] * b[j];

					    for (int i = n - 1, j = m - 1; i >= 0 && j >= 0 && a[i] > 0 && b[j] > 0; i --, j -- )
					        res += a[i] * b[j];

					    printf("%d\n", res);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/331627/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		142. 1522. 排成最小的数字		1038
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 10010;

					int n;
					string str[N];

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ ) cin >> str[i];

					    sort(str, str + n, [](string a, string b) {
					        return a + b < b + a;
					    });

					    string res;
					    for (int i = 0; i < n; i ++ ) res += str[i];

					    int k = 0;
					    while (k + 1 < res.size() && res[k] == '0') k ++ ;

					    cout << res.substr(k) << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/331643/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		143. 1553. 用 Swap(0, i) 操作进行排序		1067
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 100010;

					int n;
					int p[N];

					int main()
					{
					    scanf("%d", &n);
					    for (int i = 0; i < n; i ++ )
					    {
					        int id;
					        scanf("%d", &id);
					        p[id] = i;
					    }

					    int res = 0;
					    for (int i = 1; i < n;)
					    {
					        while (p[0]) swap(p[0], p[p[0]]), res ++ ;
					        while (i < n && p[i] == i) i ++ ;
					        if (i < n) swap(p[0], p[i]), res ++ ;
					    }

					    printf("%d\n", res);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/331658/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		144. 1556. 月饼	1070
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 1010;

					int n;
					double m;
					struct Cake
					{
					    double p, w;
					    bool operator< (const Cake &t) const
					    {
					        return p / w > t.p / t.w;
					    }
					}c[N];

					int main()
					{
					    cin >> n >> m;
					    for (int i = 0; i < n; i ++ ) cin >> c[i].w;
					    for (int i = 0; i < n; i ++ ) cin >> c[i].p;

					    sort(c, c + n);

					    double res = 0;
					    for (int i = 0; i < n && m > 0; i ++ )
					    {
					        double r = min(m, c[i].w);
					        m -= r;
					        res += c[i].p / c[i].w * r;
					    }

					    printf("%.2lf\n", res);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/338404/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		145. 1603. 整数集合划分	1113
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 100010;

					int n;
					int a[N];

					int main()
					{
					    scanf("%d", &n);
					    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
					    sort(a, a + n);

					    int s1 = 0, s2 = 0;
					    for (int i = 0; i < n / 2; i ++ ) s1 += a[i];
					    for (int i = n / 2; i < n; i ++ ) s2 += a[i];

					    printf("%d %d\n", n % 2, s2 - s1);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/338418/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		146. 1618. 结绳	1125
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 10010;

					int n;
					double a[N];

					int main()
					{
					    cin >> n;
					    for (int i = 0; i < n; i ++ ) cin >> a[i];
					    sort(a, a + n);

					    for (int i = 1; i < n; i ++ ) a[0] = (a[0] + a[i]) / 2;

					    printf("%d\n", (int)a[0]);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/338438/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		147. 1517. 是否加满油	1033
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 510;

					int c_max, d, d_avg, n;
					struct Stop
					{
					    double p, d;

					    bool operator< (const Stop& t) const
					    {
					        return d < t.d;
					    }
					}s[N];

					int main()
					{
					    cin >> c_max >> d >> d_avg >> n;
					    for (int i = 0; i < n; i ++ ) cin >> s[i].p >> s[i].d;
					    s[n] = {0, (double)d};

					    sort(s, s + n + 1);

					    if (s[0].d)
					    {
					        puts("The maximum travel distance = 0.00");
					        return 0;
					    }

					    double res = 0, oil = 0;
					    for (int i = 0; i < n;)
					    {
					        int k = -1;
					        for (int j = i + 1; j <= n && s[j].d - s[i].d <= c_max * d_avg; j ++ )
					            if (s[j].p < s[i].p)
					            {
					                k = j;
					                break;
					            }
					            else if (k == -1 || s[j].p < s[k].p)
					                k = j;

					        if (k == -1)
					        {
					            printf("The maximum travel distance = %.2lf\n", s[i].d + (double)c_max * d_avg);
					            return 0;
					        }

					        if (s[k].p <= s[i].p)
					        {
					            res += ((s[k].d - s[i].d) / d_avg - oil) * s[i].p;
					            i = k;
					            oil = 0;
					        }
					        else
					        {
					            res += (c_max - oil) * s[i].p;
					            oil = c_max - (s[k].d - s[i].d) / d_avg;
					            i = k;
					        }
					    }

					    printf("%.2lf\n", res);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/338470/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

13. 链表
		148. 1516. 共享	1032
			0. bug
				1. 读char 也是%c
					scanf("%d %c %d", &a, &b, &c)
				2. 题目的输入本身就会告诉你结尾: -1
					所以你可以直接:
						for(int i = h1; i != -1; i = ne[i]) st[i] = true;
			1. 笔记
				1. 其实非常简单, 就和以前学的链表很像
					2. 要记的模板:
					int head, e[N], ne[N];
					int ind;

					void init(){
						head = -1;
						ind = 0;
					}

					void add_head(int a){
						e[ind] = a, ne[ind] = head, head = ind++;
					}

					//假设之前是 (头结点) a --> b --> c --> d --> -1, 其中b是a的next,现在要变成a --> b --> e --> c --> d --> -1
					//其中b是第3个加入的节点, 在b的后面加上一个数, 这里的后面是next
					void add_k(int a, int k){ 在k的前面加上一个新的数字, 所以这个新的数字的next是k
						e[ind] = a, ne[ind] = ne[k], ne[k] = ind++; //也就是我ind要指向你k的下一位,你k指向我
					}


					void remove(int k){ 
						ne[k] = ne[ne[k]]; //我k不指向我的下一个了,我指向我next的next
					}

					void remove_head(){
						head = ne[head];
					}

					add规律:
						e[ind] = xx, ne[ind] = yy, yy = ind++;

						想象: 我先创建一个新的节点, 这个节点的e, 和ne要设置好, 最后我要给这个节点一个名分, 也就是让yy链接它
							
						xx是元素
						yy是head, 或者是ne[k]
							e[ind] = xx, ne[ind] = head, head = ind++;
								我ind的元素是xx, 我ind的下一个是旧头head, 新头head是我ind, 最后ind++
							e[ind] = xx, ne[ind] = ne[k], ne[k] = ind++;
								我ind的元素是xx, 我ind的下一个是它k的下一个ne[k], 它k的下一个现在是我ind, 最后ind++

					remove规律:
						yy = ne[yy]
							ne[k] = ne[ne[k]]; 
								k的下一个 是 k的下一个 的下一个
							head = ne[head];
								头 是 头的下一个

					最后是遍历
						for (int i = head; i != -1; i = ne[i]) cout << e[i] << ' ';
				2. scanf()一定要记得空格, 然后记得&
				3. 最好用string读, 因为遇到00002的话, 我们要是需要输出00002, 不能输出2
					不过老师还是用int读, 因为老师用了补齐5位的方式:
						printf("%05d\n", i);
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 100010;

					int n;
					int h1, h2, ne[N];
					char e[N];
					bool st[N];

					int main()
					{
					    scanf("%d%d%d", &h1, &h2, &n);
					    for (int i = 0; i < n; i ++ )
					    {
					        int address, next;
					        char data;
					        scanf("%d %c %d", &address, &data, &next);
					        e[address] = data, ne[address] = next;
					    }

					    for (int i = h1; i != -1; i = ne[i])
					        st[i] = true;

					    for (int i = h2; i != -1; i = ne[i])
					        if (st[i])
					        {
					            printf("%05d\n", i);
					            return 0;
					        }

					    puts("-1");

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/338478/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
					#include <iostream>

					using namespace std;

					const int N = 100010;
					int e[N], ne[N];
					bool st[N];

					int main(){
					    int h1, h2, n;
					    scanf("%d %d %d", &h1, &h2, &n);


					    for(int i = 0; i < n; i++){
					        int a, b;
					        char c;
					        scanf("%d %c %d", &a, &c, &b);

					        e[a] = c, ne[a] = b;
					    }

					    for(int i = h1; i != -1; i = ne[i]) st[i] = true;
					    for(int i = h2; i != -1; i = ne[i]){
					        if(st[i]){
					            printf("%05d\n", i);
					            return 0;
					        }
					    }
					    puts("-1");
					    return 0;

					}
				r2.
				r3.
				r4.
				r5.

		149. 1560. 反转链表	1074
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>
					#include <vector>

					using namespace std;

					const int N = 100010;

					int n, m;
					int h, e[N], ne[N];

					int main()
					{
					    scanf("%d%d%d", &h, &n, &m);

					    for (int i = 0; i < n; i ++ )
					    {
					        int address, data, next;
					        scanf("%d%d%d", &address, &data, &next);
					        e[address] = data, ne[address] = next;
					    }

					    vector<int> q;
					    for (int i = h; i != -1; i = ne[i]) q.push_back(i);

					    for (int i = 0; i + m - 1 < q.size(); i += m)
					        reverse(q.begin() + i, q.begin() + i + m);

					    for (int i = 0; i < q.size(); i ++ )
					    {
					        printf("%05d %d ", q[i], e[q[i]]);
					        if (i + 1 == q.size()) puts("-1");
					        else printf("%05d\n", q[i + 1]);
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/338492/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		150. 1587. 链表重复数据删除	1097
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 100010;

					int n;
					int h, e[N], ne[N];
					bool st[N];

					int main()
					{
					    scanf("%d%d", &h, &n);
					    for (int i = 0; i < n; i ++ )
					    {
					        int address, key, next;
					        scanf("%d%d%d", &address, &key, &next);
					        e[address] = key, ne[address] = next;
					    }

					    vector<int> a, b;
					    for (int i = h; i != -1; i = ne[i])
					    {
					        int v = abs(e[i]);
					        if (st[v]) b.push_back(i);
					        else
					        {
					            st[v] = true;
					            a.push_back(i);
					        }
					    }

					    for (int i = 0; i < a.size(); i ++ )
					    {
					        printf("%05d %d ", a[i], e[a[i]]);
					        if (i + 1 == a.size()) puts("-1");
					        else printf("%05d\n", a[i + 1]);
					    }
					    for (int i = 0; i < b.size(); i ++ )
					    {
					        printf("%05d %d ", b[i], e[b[i]]);
					        if (i + 1 == b.size()) puts("-1");
					        else printf("%05d\n", b[i + 1]);
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/338506/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		151. 1626. 链表元素分类	1133
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <vector>

					using namespace std;

					const int N = 100010;

					int n, k;
					int h, e[N], ne[N];

					int main()
					{
					    scanf("%d%d%d", &h, &n, &k);
					    for (int i = 0; i < n; i ++ )
					    {
					        int address, key, next;
					        scanf("%d%d%d", &address, &key, &next);
					        e[address] = key, ne[address] = next;
					    }

					    vector<int> a, b, c;
					    for (int i = h; i != -1; i = ne[i])
					    {
					        int v = e[i];
					        if (v < 0) a.push_back(i);
					        else if (v <= k) b.push_back(i);
					        else c.push_back(i);
					    }

					    a.insert(a.end(), b.begin(), b.end());
					    a.insert(a.end(), c.begin(), c.end());

					    for (int i = 0; i < a.size(); i ++ )
					    {
					        printf("%05d %d ", a[i], e[a[i]]);
					        if (i + 1 == a.size()) puts("-1");
					        else printf("%05d\n", a[i + 1]);
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/338515/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

14. 基础算法和数据结构
		152. 1506. 中位数	1029
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 200010;

					int n, m;
					int a[N], b[N], c[N * 2];

					int main()
					{
					    scanf("%d", &n);
					    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
					    scanf("%d", &m);
					    for (int i = 0; i < m; i ++ ) scanf("%d", &b[i]);

					    int k = 0, i = 0, j = 0;
					    while (i < n && j < m)
					        if (a[i] <= b[j]) c[k ++ ] = a[i ++ ];
					        else c[k ++ ] = b[j ++ ];
					    while (i < n) c[k ++ ] = a[i ++ ];
					    while (j < m) c[k ++ ] = b[j ++ ];

					    printf("%d\n", c[(n + m - 1) / 2]);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/338526/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		153. 1530. 最短距离 	1046
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 100010;

					int n, m;
					int s[N];

					int main()
					{
					    scanf("%d", &n);
					    for (int i = 1; i <= n; i ++ )
					    {
					        scanf("%d", &s[i]);
					        s[i] += s[i - 1];
					    }

					    scanf("%d", &m);
					    while (m -- )
					    {
					        int l, r;
					        scanf("%d%d", &l, &r);
					        if (l > r) swap(l, r);
					        printf("%d\n", min(s[r - 1] - s[l - 1], s[n] - s[r - 1] + s[l - 1]));
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/338531/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		154. 1571. 完美序列	1085
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 100010;

					int n, p;
					int a[N];

					int main()
					{
					    scanf("%d%d", &n, &p);
					    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);

					    sort(a, a + n);

					    int res = 0;
					    for (int i = 0, j = 0; i < n; i ++ )
					    {
					        while ((long long)a[j] * p < a[i]) j ++ ;
					        res = max(res, i - j + 1);
					    }

					    printf("%d\n", res);
					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/338548/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		155. 1581. 急性中风	1091
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <queue>

					using namespace std;

					const int M = 1286, N = 128, L = 60;

					int m, n, l, T;
					int g[L][M][N];
					struct Node
					{
					    int x, y, z;
					};

					int d[][3] = {
					    {1, 0, 0},
					    {-1, 0, 0},
					    {0, 1, 0},
					    {0, -1, 0},
					    {0, 0, 1},
					    {0, 0, -1},
					};

					int bfs(int x, int y, int z)
					{
					    queue<Node> q;
					    q.push({x, y, z});
					    g[x][y][z] = 0;

					    int cnt = 1;
					    while (q.size())
					    {
					        auto t = q.front();
					        q.pop();

					        for (int i = 0; i < 6; i ++ )
					        {
					            int a = t.x + d[i][0], b = t.y + d[i][1], c = t.z + d[i][2];
					            if (a >= 0 && a < l && b >= 0 && b < m && c >= 0 && c < n && g[a][b][c])
					            {
					                g[a][b][c] = 0;
					                q.push({a, b, c});
					                cnt ++ ;
					            }
					        }
					    }

					    return cnt;
					}

					int main()
					{
					    scanf("%d%d%d%d", &m, &n, &l, &T);

					    for (int i = 0; i < l; i ++ )
					        for (int j = 0; j < m; j ++ )
					            for (int k = 0; k < n; k ++ )
					                scanf("%d", &g[i][j][k]);

					    int res = 0;
					    for (int i = 0; i < l; i ++ )
					        for (int j = 0; j < m; j ++ )
					            for (int k = 0; k < n; k ++ )
					                if (g[i][j][k])
					                {
					                    int t = bfs(i, j, k);
					                    if (t >= T) res += t;
					                }

					    printf("%d\n", res);

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/339316/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		156. 1641. 狼人杀-简单版	1148
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 110;

					int n;
					int q[N];

					int judge(int k, int i, int j)  // 如果是假话，返回1；如果是真话，返回0
					{
					    int t = q[k];
					    if (t > 0)
					    {
					        if (t == i || t == j) return 1;
					        return 0;
					    }

					    t = -t;
					    if (t == i || t == j) return 0;
					    return 1;
					}

					int main()
					{
					    cin >> n;
					    for (int i = 1; i <= n; i ++ ) cin >> q[i];

					    for (int i = 1; i <= n; i ++ )
					        for (int j = i + 1; j <= n; j ++ )
					        {
					            int s = judge(i, i, j) + judge(j, i, j);
					            if (s != 1) continue;

					            s = 0;
					            for (int k = 1; k <= n; k ++ )
					                s += judge(k, i, j);

					            if (s != 2) continue;

					            cout << i << ' ' << j << endl;
					            return 0;
					        }

					    puts("No Solution");

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/339329/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		157. 1535. 弹出序列	1051
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <stack>

					using namespace std;

					const int N = 1010;

					int m, n, k;
					int a[N];

					bool check()
					{
					    stack<int> stk;
					    for (int i = 1, j = 0; i <= n; i ++ )
					    {
					        stk.push(i);
					        if (stk.size() > m) return false;

					        while (stk.size() && stk.top() == a[j])
					        {
					            stk.pop();
					            j ++ ;
					        }
					    }

					    return stk.empty();
					}

					int main()
					{
					    scanf("%d%d%d", &m, &n, &k);
					    while (k -- )
					    {
					        for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
					        if (check()) puts("YES");
					        else puts("NO");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/339339/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		158. 1541. 世界首富	1055
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <vector>
					#include <algorithm>

					using namespace std;

					const int N = 210;

					int n, m;
					struct Person
					{
					    string name;
					    int age, w;

					    bool operator< (const Person& t) const
					    {
					        if (w != t.w) return w > t.w;
					        if (age != t.age) return age < t.age;
					        return name < t.name;
					    }
					};

					vector<Person> ages[N];
					int idx[N];

					int main()
					{
					    scanf("%d%d", &n, &m);

					    char name[10];
					    for (int i = 0; i < n; i ++ )
					    {
					        int age, w;
					        scanf("%s%d%d", name, &age, &w);
					        ages[age].push_back({name, age, w});
					    }

					    for (auto& age : ages) sort(age.begin(), age.end());

					    for (int C = 1; C <= m; C ++ )
					    {
					        printf("Case #%d:\n", C);
					        int cnt, a, b;
					        scanf("%d%d%d", &cnt, &a, &b);

					        memset(idx, 0, sizeof idx);
					        bool exists = false;
					        while (cnt -- )
					        {
					            int t = -1;
					            for (int i = a; i <= b; i ++ )
					                if (idx[i] < ages[i].size())
					                {
					                    if (t == -1 || ages[i][idx[i]] < ages[t][idx[t]])
					                        t = i;
					                }

					            if (t == -1) break;
					            auto& p = ages[t][idx[t]];
					            idx[t] ++ ;

					            printf("%s %d %d\n", p.name.c_str(), p.age, p.w);
					            exists = true;
					        }

					        if (!exists) puts("None");
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/339362/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		159. 1543. 栈 	1057
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <set>
					#include <stack>

					using namespace std;

					stack<int> stk;
					multiset<int> up, down;

					void adjust()
					{
					    while (up.size() > down.size())
					    {
					        down.insert(*up.begin());
					        up.erase(up.begin());
					    }

					    while (down.size() > up.size() + 1)
					    {
					        auto it = down.end();
					        it -- ;
					        up.insert(*it);
					        down.erase(it);
					    }
					}

					int main()
					{
					    int n;
					    scanf("%d", &n);
					    char op[20];
					    while (n -- )
					    {
					        scanf("%s", op);
					        if (strcmp(op, "Push") == 0)
					        {
					            int x;
					            scanf("%d", &x);
					            stk.push(x);
					            if (up.empty() || x < *up.begin()) down.insert(x);
					            else up.insert(x);
					            adjust();
					        }
					        else if (strcmp(op, "Pop") == 0)
					        {
					            if (stk.empty()) puts("Invalid");
					            else
					            {
					                int x = stk.top();
					                stk.pop();
					                printf("%d\n", x);
					                auto it = down.end();
					                it -- ;
					                if (x <= *it) down.erase(down.find(x));
					                else up.erase(up.find(x));

					                adjust();
					            }
					        }
					        else
					        {
					            if (stk.empty()) puts("Invalid");
					            else
					            {
					                auto it = down.end();
					                it -- ;
					                printf("%d\n", *it);
					            }
					        }
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/339383/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		160. 1607. 爱丁顿数	1117
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>
					#include <algorithm>

					using namespace std;

					const int N = 100010;

					int n;
					int a[N];

					int main()
					{
					    scanf("%d", &n);
					    for (int i = 0; i < n; i ++ ) scanf("%d", &a[i]);
					    sort(a, a + n);

					    for (int i = n; i; i -- )
					        if (a[n - i] > i)
					        {
					            printf("%d\n", i);
					            return 0;
					        }

					    puts("0");
					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/339399/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		161. 1528. 火星购物	1044
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					const int N = 100010, INF = 1e9;

					int n, m;
					int s[N];

					int main()
					{
					    scanf("%d%d", &n, &m);
					    for (int i = 1; i <= n; i ++ )
					    {
					        scanf("%d", &s[i]);
					        s[i] += s[i - 1];
					    }

					    int res = INF;
					    for (int i = 1, j = 0; i <= n; i ++ )
					    {
					        while (s[i] - s[j + 1] >= m) j ++ ;
					        if (s[i] - s[j] >= m) res = min(res, s[i] - s[j]);
					    }

					    for (int i = 1, j = 0; i <= n; i ++ )
					    {
					        while (s[i] - s[j + 1] >= m) j ++ ;
					        if (s[i] - s[j] == res) printf("%d-%d\n", j + 1, i);
					    }

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/339426/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		162. 1524. 最长回文子串	1040
			0. bug
			1. 笔记
			2. 注释
				1. y
					#include <iostream>
					#include <cstring>

					using namespace std;

					int main()
					{
					    string str;
					    getline(cin, str);

					    int res = 0;
					    for (int i = 0; i < str.size(); i ++ )
					    {
					        int l = i - 1, r = i + 1;
					        while (l >= 0 && r < str.size() && str[l] == str[r]) l --, r ++ ;
					        res = max(res, r - l - 1);

					        l = i, r = i + 1;
					        while (l >= 0 && r < str.size() && str[l] == str[r]) l --, r ++ ;
					        res = max(res, r - l - 1);
					    }

					    cout << res << endl;

					    return 0;
					}

					作者：yxc
					链接：https://www.acwing.com/activity/content/code/content/339437/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.



99. 其他
	0. 注意
		1. 行末尾空格
		2. 模拟题,复杂的数据结构,复杂的几何题(pat没有),可以放在考试后面做

	1. 模拟题(更像是工程的,题目已经规定好了应该怎么做,你去实现就好了)
		1. 字符串问题
	2. 优化题(更像是考察算法)
		1. 排序
			1. 快排
			2. 归并
			3. 冒泡

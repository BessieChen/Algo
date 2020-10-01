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

		12. 1546. 它们是否相等	1060
			0. bug
			1. 笔记
			2. 注释
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.
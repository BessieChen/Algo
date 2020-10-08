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

					y总为什么down操作是b[t] < b[u * 2]？
					down操作不应该是把堆顶大的元素往下降吗。。。
						大根堆小根堆都能实现从小到大排序，如果用小根堆，那每次把最小值放到序列开头；如果用大根堆，那就每次把最大值放到序列结尾。

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
						if(r < size && after[r] > after[l]) t = r;
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
				r3.
				r4.
				r5.

	9. 2020年10月8日16:45:10

		40. 1579. 插入还是归并	1089
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
				r2.
				r3.
				r4.
				r5.

		41. 789. 数的范围 模板题
			0. bug
			1. 笔记
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
					2. 如果true, 你是想继续往左还是往右?
						1. 往左. r = mid, l = mid + 1;
						2. 往右, 小心啦!!, l = mid, r = mid - 1;
					
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
				r1.
				r2.
				r3.
				r4.
				r5.

		42. 838. 堆排序 	模板题
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
					链接：https://www.acwing.com/activity/content/code/content/273116/
					来源：AcWing
					著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
				2. b
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

5.  树
	7. 2020年10月6日14:27:39
		43. 826. 单链表	模板题
			0. bug
			1. 笔记
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
			3. 5次
				r1.
				r2.
				r3.
				r4.
				r5.

		44. 836. 合并集合	模板题
			0. bug
			1. 笔记
				0. 并查集是非常容易考到的数据结构
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
				r2.
				r3.
				r4.
				r5.
		
		45. 1476. 数叶子结点	1004
			0. bug
			1. 笔记
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
				r2.
				r3.
				r4.
				r5.

		46. 1497. 树的遍历	1020
			0. bug
			1. 笔记
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
				r2.
				r3.
				r4.
				r5.

		47. 1498. 最深的根	1021
			0. bug
			1. 笔记
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
				r2.
				r3.
				r4.
				r5.

		48. 1527. 判断二叉搜索树	1043
			0. bug
			1. 笔记
				1. build()
					只要一边的子树不行,那res就是false
					build()不能放在前面,否则就是无限循环了,应该是 
						1. 终止条件
						2. 做一些事
						3. 递归:调用自己
						4. 其他终止条件.
				2. 知道了
					1. 因为要后序所以是build(左), build(右), postorder[cnt++] = xx
					2. 如果是中序, 应该就是build(左), postorder[cnt++] = xx, build(右)
					3. 前序就是post, build(), build();
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
				r1.
				r2.
				r3.
				r4.
				r5.

		49. 1550. 完全二叉搜索树	1064
			0. bug
			1. 笔记
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
				r2.
				r3.
				r4.
				r5.
			

		50. 1576. 再次树遍历	1086
			0. bug
			1. 笔记
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
				r1.
				r2.
				r3.
				r4.
				r5.
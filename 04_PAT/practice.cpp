1. string
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
		1. 笔记
			1. A是65, a是97, 所以 c+=32就可以大写变成小写
			2. 保险起见,用for(string::size_type i = 0; i < s.size(); i++), 因为s.size()是string::size_type

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
			r2.
			r3.
			r4.
			r5.
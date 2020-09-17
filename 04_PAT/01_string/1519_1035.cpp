#include <iostream>

using namespace std;

const int N = 1010; // 要存的名字最多有多少个

string name[N], pwd[N];

//老师这里并没有修改输入的cur_pwd
string change(string cur_pwd){
	string res;
	for(auto i : cur_pwd){ //是从前往后遍历,例如abc,先遍历a
		if(i == '1') res += '@';
		else if( i == '0') res += '%';
		else if( i == 'l') res += 'L';
		else if(i == 'O') res += 'o';
		else res += i;
	}
	return res;
}
int main(){
	int n;
	cin >> n;
	int rec_n = n; //因为n会在后面被修改,但是原始的n还是需要用到.

	int m = 0; //记录有多少个修改过的pwd
	while(n--){
		string cur_id, cur_pwd;
		cin >> cur_id >> cur_pwd;

		string changed_pwd = change(cur_pwd);
		if(changed_pwd != cur_pwd){
			name[m] = cur_id;
			pwd[m] = changed_pwd;
			m++;
		}
	}

	if(!m) 
	{
	    if(rec_n == 1) puts("There is 1 account and no account is modified"); //注意是puts
    	else printf("There are %d accounts and no account is modified", rec_n);
	}
	else
	{
	   cout << m << endl;
	    for(int i = 0; i < m; i++){
	        cout << name[i] << " " << pwd[i] << endl;
	    }
	}
	return 0;

#include <iostream>

using namespace std;

const int N = 1010; // 要存的名字最多有多少个

string name[N], pwd[N];

//老师这里并没有修改输入的cur_pwd
string change(string cur_pwd){
	string res;
	for(auto i : cur_pwd){ //是从前往后遍历,例如abc,先遍历a
		if(i == '1') res += '@';
		else if( i == '0') res += '%';
		else if( i == 'l') res += 'L';
		else if(i == 'O') res += 'o';
		else res += i;
	}
	return res;
}
int main(){
	int n;
	cin >> n;
	int rec_n = n; //因为n会在后面被修改,但是原始的n还是需要用到.

	int m = 0; //记录有多少个修改过的pwd
	while(n--){
		string cur_id, cur_pwd;
		cin >> cur_id >> cur_pwd;

		string changed_pwd = change(cur_pwd);
		if(changed_pwd != cur_pwd){
			name[m] = cur_id;
			pwd[m] = changed_pwd;
			m++;
		}
	}

	if(!m) 
	{
	    if(rec_n == 1) puts("There is 1 account and no account is modified"); //注意是puts
    	else printf("There are %d accounts and no account is modified", rec_n);
	}
	else
	{
	   cout << m << endl;
	    for(int i = 0; i < m; i++){
	        cout << name[i] << " " << pwd[i] << endl;
	    }
	}
	return 0;

}
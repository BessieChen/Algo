#include <iostream>

using namespace std;

//1001

int main(){
	int a, b;
	//scanf("%d%d",a,b);
	cin >> a >> b;
	int c = a+b;
	//string num = to_string(c);
	string num;

	if(!c) num = "0"; //如果c是0的话,后面的都不会运行.例如while(d)
	int d = abs(c);
	while(d) num = char( d % 10 + '0') + num, d /= 10; //喜欢这一句, 注意是逗号! 注意是char()
	if(c < 0) num = '-' + num;


	string res;

	for(int i = num.size()-1, j = 0; i >= 0; i--){
		res = num[i] + res;
		j++;
		if(j  % 3 == 0 && i != 0 && num[i-1] != '-') res = ',' + res;
	}

	cout << res << endl;
	return 0;
}
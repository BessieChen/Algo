#include <iostream>
#include <cstring>

using namespace std;

typedef long long LL;

bool is_prime(LL n){
	if(n == 0 || n == 1) return false;

	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) //bug!!, 是n % i, 不是 n / i //能被2到sqrt(n)之间的数整除, 说明是合数
			return false;
	}
	return true;
}
bool check(int n, int d)
{
	if(!is_prime(n)) return false;

	LL res = 0;
	//底下的while,完成了了很多步骤, 将10进制的n转化成d进制, 翻转之后, 在得到10进制, res就是结果
	while(n){
		res = res * d + n % d;
		n /= d;
	}
	return is_prime(res);
}

int main(){
	int n, d;
	while(cin >> n >> d, n >= 1) //逗号表达式, 取得是最后一个值
	{
		if(check(n, d)) puts("Yes");
		else puts("No");
	}

	return 0;
}
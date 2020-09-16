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
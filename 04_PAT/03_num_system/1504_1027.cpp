#include <iostream>

using namespace std;

string get(int a){
	if(a <= 9) return a + '0';
	else return a - 10 + 'A';
}
int main(){
	int a[3];
	for(int i = 0; i < 3; i ++) scanf("%d", &a[i]);

	cout << "#";
	for(int i = 0; i < 3; i ++) cout << get(a[i] / 13) << get(a[i] % 13) << endl;

	return 0;
}
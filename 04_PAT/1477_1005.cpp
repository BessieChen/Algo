#include <iostream>

using namespace std;

int main(){
	string n;
	cin >> n;

	int num = 0;
	for(auto i : n) num += i - '0';

	char word[10][10] = {
		"zero","one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
	};

	string res = to_string(num);

	cout << word[res[0] - '0'];
	for(int i = 1; i < res.size(); i++) cout << " " << word[res[i] - '0'];

	return 0;
}
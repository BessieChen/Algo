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
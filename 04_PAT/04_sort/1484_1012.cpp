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
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
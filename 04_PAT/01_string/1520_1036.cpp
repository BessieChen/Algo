#include <iostream>

using namespace std;

string f_name, f_id; //女生中,最高成绩的那个人的name和id
string m_name, m_id; //男生中,最低成绩的那个人的name和id
int f_score, m_score;

int main(){
	int m;
	cin >> m;

	while(m--){
		 string cur_name, cur_gender, cur_id;
		 int cur_score; //因为要比较大小,所以不要设置成string,否则字典序排列8会>12

		 cin >> cur_name, cur_gender, cur_id, cur_score;

		 if(cur_gender == "M"){
		 	if(f_name.empty() || f_score < cur_score){ //如果还没有初始化,那就是empty() == true
		 		f_name = cur_name;
		 		f_score = cur_score;
		 		f_id = cur_id;
		 	}
		 }
		 else
		 {
		 	if(m_name.empty() || m_score > cur_score){
		 		m_name = cur_name;
		 		m_score = cur_score;
		 		m_id = cur_id;
		 	}
		 }
	}

	if(f_name.empty()) puts("Absent");
	else cout << f_name << " " << f_id;

	if(m_name.empty()) puts("Absent");
	else cout << m_name << " " << m_id;

	if(f_name.size() && m_name.size()) cout << abs(f_score - m_score) << endl;
	else puts("NA");

	return 0;
}
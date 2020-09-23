#include <iostream>
#include <algorithm> //sort
#include <vector>

using namespace std;

const int N = 110; //最多100个地区
const int M = 310; //每个地区最多300人

//构建student
struct Student{
	string id;
	int grade;
	int location;
	int local_rank;
	int global_rank;

	bool operator< (const Student& t) const{ //用于sort()的时候比较Student
		if(grade != t.grade) return grade > t.grade; //返回的是我优先,如果我的grade大的话,就是我优先
		else return id < t.id; //返回的是我优先
	}
};

vector<Student> local[N]; //不能写成vector<int> local[N], 因为我们在sort()的时候不单单要
vector<Student> global;

int main(){
	int n;
	cin >> n;

	for(int i = 0; i < n; i ++){ //这里的i可以当做地区名
		int m;
		cin >> m;
		while(m--){
			string id;
			int g;
			cin >> id >> g;
			local[i].push_back({id, g, i + 1}); //后面的会自动补齐,也就是0, 注意: 地区编号按输入顺序依次为 1∼N
		}

		//加下来对i地区的人进行排名,然后local_rank记录进去
		auto& l = local[i]; //l是vector<Student>
		sort(l.begin(), l.end()); //这里会用到标志服重载,所以grade大的,id小的在前面
		for(int j = 0; j < l.size(); j++){
			if(!j || l[j].grade != l[j-1].grade)
				l[j].local_rank = j+1;
			else
				l[j].local_rank = l[j-1].local_rank;

			global.push_back(l[j]);//因为最后需要全部内容打印, 所以我们将global存了全部内容
			//注意,这里不是push_back({id, grade, local_rank}), 而是直接将l[j], 也就是一个studnet插入了里面
		}
	}

	sort(global.begin(), global.end());
	for(int j = 0; j < global.size(); j++){
			if(!j || global[j].grade != global[j-1].grade)
				global[j].global_rank = j+1;
			else
				global[j].global_rank = global[j-1].global_rank;
	}

	//目前为止,global里面的每个学生,拥有了global_rank,然后global本身的排序也是题目要的
	cout << global.size() << endl;
	for(auto& s : global){
		cout << s.id << " " << s.global_rank <<" " << s.location << " " << s.local_rank << endl;
	}

	return 0;
}
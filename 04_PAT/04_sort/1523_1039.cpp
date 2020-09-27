#include <unordered_map>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

unordered_map<string, vector<int>> students; //这是哈希表

int main(){
	int n, m;
	cin >> n >> m;

	while(m--){
		int id, p;
		cin >> id >> p;
		while(p--){
			string name;
			cin >> name;
			students[name].push_back(id); //注意不是student[name] = p;
		}
	}

    //method 1
    /*
	for(auto& s : students){ //s是<string, vector<int>>, 所以记得是s.second
		sort(s.second.begin(), s.second.end());
	}

	while(n--){
		string name;
		cin >> name;
		cout << name << " " << students[name].size();
		for(auto& id : students[name]) //如果student[name]都没有就是不会走这个for loop
		        cout << " " << id;
		cout << endl;
	}
	*/
	
	//method 2
	while(n--){
	    string name;
	    cin >> name;
	    
	    cout << name << " " << students[name].size();
	    sort(students[name].begin(), students[name].end());
	    for(auto id : students[name]){
	        cout << " " << id;
	    }
	    cout << endl;
	}
	
	//method 1,2 end
	return 0;
}
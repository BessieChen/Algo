#include <iostream>
using namespace std;

int main(){
	int m;
	cin >> m;

	string open_id, open_time;
	string close_id, close_time;

	for(int i = 0; i < m ; i++){
		string id, in_time, out_time;
		cin >> id >> in_time >> out_time;

		if(i == 0 || in_time < open_time){
			open_id = id;
			open_time = in_time;
		}

		if(i == 0 || out_time > close_time){
			 close_id = id;
			close_time = out_time;
		}
	}

	cout << open_id << " " << close_id << endl;
	return 0;
}
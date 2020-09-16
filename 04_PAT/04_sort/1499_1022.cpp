#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm> //sort()
#include <set> //set<string> keywords

using namespace std;

struct Book{
	string id;
	string title;
	string author;
	set<string> keywords;
	string publisher;
	string year;
};
int main(){
	int n;
	cin >> n;

	vector<Book> books;
	for(int i = 0; i < n; i ++){
		string id;
		cin >> id;

		//以下是存在空格的,所以统一用getline()
		string title, author, keyword, publisher;
		getchar(); //读上一次的\n回车
		getline(cin, title);
		getline(cin, author);
		getline(cin , keyword);
		getline(cin, publisher);

		string year;
		cin >> year;

		set<string> keywords;
		stringstream kwcin(keyword);
		string kw;
		while( kwcin >> kw) keywords.insert(kw);

		books.push_back({id, title, author, keywords, publisher, year});
	}

	int m;
	cin >> m;
	getchar(); //getchar()应该出现一次,而不是出现在while里面,因为
	while(m --){

		string input; //因为input的格式有空格(2: Yue Chen),所以需要getline()
		//getchar(); //把\n读了, bug!! 不能每次都getchar()!!, 如果while里面出现getchar(),会发生第一个字符没了, 也就是本应是:"1: xxx", 但现在只剩": xxx""
		getline(cin, input); //会把\n也读了,所以后面不需要getchar();
		cout << input << endl;

		string content = input.substr(3); //我们需要的是从ind==3开始的字符: Yue Chen
		char request = input[0]; //如果是1, 说明要查title //bug, 注意是char, 不是string
		
		vector<string> res; //把所有结果的id都存在vector里面
		if(request == '1'){
			for(auto& b : books){ //注意我们用的是auto&, 而不是auto, 因为books式结构体,复制的话太慢,引用快
				if(b.title == content)
					res.push_back(b.id); //存的是b书的id
			}
		}
		else if(request == '2'){
			for(auto& b : books){
				if(b.author == content)
					res.push_back(b.id); //存的是b书的id
			}
		}
		else if(request == '3'){
			for(auto& b : books){
				if(b.keywords.count(content)) //这里是看b书的keyword包不包含content
					res.push_back(b.id); //存的是b书的id
			}
		}
		else if(request == '4'){
			for(auto& b : books){
				if(b.publisher == content)
					res.push_back(b.id); //存的是b书的id
			}
		}
		else{
			for(auto& b : books){
				if(b.year == content)
					res.push_back(b.id); //存的是b书的id
			}
		}

		if(res.empty()) cout << "Not Found" << endl;
		else {
			sort(res.begin(), res.end());//对id排序
			for(auto id : res) cout << id << endl;
		}
	}

	return 0;
}
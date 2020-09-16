#include <iostream>
#include <sstream>

using namespace std;

char name[][5] = { //bug, 记得是char[][], 不是int[][]
	"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec",
    "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou",
};

int get(string word){
	for(int i = 0; i < 25; i++){
		if(word == name[i]){
			if(i <= 12) return i;
			else return (i - 13 + 1) * 13; //bug, 一定记得-13 + 1, 因为我们是从name[13]开始,但是这个数字还要+1, 不然 0 * 13没东西..
		}
	}
	return -1; //执行不到
}

int main(){
	int n;
	cin >> n;
	getchar(); //一定要把/n干掉

	while( n --){
	    string input;
    	getline(cin, input); //bug, 记得要输入cin //读一整行
    
    	stringstream s(input);
    
    	if(input[0] <= '9'){ //说明是地球的文字
    		int num = 0;
    		s >> num; //很神奇,也就是将input,假设是string "91"变成了int 91
    		if(num <= 12) cout << name[num] << endl;
    		else{
    			cout << name[12 + num / 13]; //bug, 记得要+ 12, 例如13, 应该输出tam(对应的是name[13]), num / 13 == 1 
    			if(num % 13 == 0) cout << endl; //bug!是%13, 不是/13. 例如是13, 我们就直接输出tam, 因为没有余数
    			else cout << " " << name[num % 13] << endl; 
    		}
    	}
    	else{ //火星文
    		
    		//因为不确定到底会输入多少火星文,所以我们使用while
    		int num = 0; //bug!, 我发现,如果你只是写成int num; 之后在进入这个循环的时候, num并没有置为零!!
    		string word;
    		while(s >> word) {
    		    num += get(word); //一个字母, 老师通过判断是前12位还是后12位来判断是否*13
    		}
    		cout << num << endl;
    
    	}
	}

	return 0;
}
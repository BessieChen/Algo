#include <iostream>
#include <unordered_set>

using namespace std;

string origin, to_remove;

bool char_exist(char i){
    for(auto s : to_remove)
    {
        if( s == i) return true;
    }
    return false;
}
int main_TLE(){

    getline(cin, origin);
    getline(cin, to_remove);

    string res;

    for(auto i : origin)
    {
        if(!char_exist(i))
            res += i;
    }

    cout << res << endl;
    return 0;
}

int main(){
    getline(cin, origin);
    getline(cin, to_remove);

    unordered_set<char> hash;
    for(auto c : to_remove) hash.insert(c);

    string res;
    for(auto c : origin)
        if(!hash.count(c)) res += c;

    cout << res << endl;

    return 0;


}
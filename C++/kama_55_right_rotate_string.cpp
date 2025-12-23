#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;

int main(int argc, char const *argv[]) {
    int k;
    cin>>k;
    string s;
    cin>>s;
    int n = s.size();
    if(k>n){
        return -1;
    }
    string new_tail = s.substr(0, n-k);
    s.erase(s.begin(), s.begin()+n-k);
    s+=new_tail;
    cout<<s<<endl;

	// Solution s;
	// cout << "hello wrold" << endl;
	return 0;
}


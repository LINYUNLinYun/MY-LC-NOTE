#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
using namespace std;

int main(int argc, char const *argv[]) {
	// Solution s;
	stack<int> s;
	s.push(6);
	s.push(7);
	cout << s.top() << s.size();
	s.pop();
	cout<<s.top();
	cout << "hello wrold" << endl;
	return 0;
}


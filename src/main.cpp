#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
using namespace std;

int main(int argc, char const *argv[]) {
	// Solution s;
	queue<int> q;
	
	stack<int> s;
	s.push(6);
	s.push(7);
	cout << s.top() << s.size();
	s.pop();
	cout<<s.top();
	cout << "hello wrold" << endl;
	return 0;
}


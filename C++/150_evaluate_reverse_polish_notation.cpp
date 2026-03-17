#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 每个运算符都对应两个操作数，所以在检测到即将入栈一个运算符的时候，弹出两个操作数做运算
        // 本质上等于做了个括号 提高了优先级
        stack<int> st;
        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] == "+"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1 + op2);
            }
            else if(tokens[i] == "-"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1 - op2);
            }
            else if(tokens[i] == "*"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1 * op2);
            }
            else if(tokens[i] == "/"){
                int op2 = st.top();
                st.pop();
                int op1 = st.top();
                st.pop();
                st.push(op1 / op2);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
            
        }
        return st.top();
    }
};

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


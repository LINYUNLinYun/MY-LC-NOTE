#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    bool isValid(string s) {

        stack<char> left;
        int n = s.size();
        if(n%2 != 0){
            return false;
        }
        bool res = true;
        for(int i = 0;i<n;i++){
            // 是左括号就入栈
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                left.push(s[i]);
            }
            else{
                // 不是左括号就出栈一个看看两个括号是否匹配
                if(left.empty()){
                    res = false;
                    break;
                }
                char ch = left.top();
                left.pop();
                if(s[i] == ')' && ch != '('){
                    res = false;
                    break;
                }
                if(s[i] == ']' && ch != '['){
                    res = false;
                    break;
                }
                if(s[i] == '}' && ch != '{'){
                    res = false;
                    break;
                }
            }
        }
        if(!left.empty()){
            res = false;
        }
        return res;
    }
};
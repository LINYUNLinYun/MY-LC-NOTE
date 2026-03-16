#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(int i = s.size() -1;i >=0;i--){
            if(st.empty()){
                st.push(s[i]);
            }else{
                if(s[i]== st.top()){
                    st.pop();
                }else{
                    st.push(s[i]);

                }
            }
        }
        string res;
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        return res;        
    }
};
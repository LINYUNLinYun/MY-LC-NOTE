#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        int n = temperatures.size();
        if(n<2){
            return {0};
        }
        stack<int> s;
        vector<int> res(n,0);
        for(int i = 0;i<n;i++){
            if(s.empty()){
                s.push(i);
                continue;
            }
            while(!s.empty() && temperatures[s.top()] < temperatures[i]){
                res[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
            
        }
        return res;
    }
};
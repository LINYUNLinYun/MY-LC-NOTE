#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
#include <cmath>
#include <unordered_set>
using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordset;
        vector<int> dp(s.size()+1);
        dp[0] = 1;
        // 建表 查询
        for(auto w : wordDict){
            wordset.insert(w);
        }
        // dp负责记录下第i个下标前的子串是否能由words构成
        for(int i = 1;i<=s.size();i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && wordset.count(s.substr(j,i-j))){
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[s.size()] == 1;
    }
};
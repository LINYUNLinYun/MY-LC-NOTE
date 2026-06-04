#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm> 
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n<2){
            return 1;
        }
        vector<vector<int>> dp(n,vector<int>(n,0));
        // 边界条件
        for(int i = 0; i<n;i++){
            dp[i][i] = 1;
        }
        for(int i = n-1;i>0;i--){
            for(int j = 0;j<i;j++){
                // 如果首尾字符相等 那么等于2 + [i+1, j-1]
                if(s[j] == s[j + (n-i)]){
                    dp[j][j + (n-i)] += 2;
                    dp[j][j + (n-i)] += dp[j+1][j + (n-i)-1];
                    continue;
                }
                // 如果不相等， 说明首尾字符最多只有一个参与到最大回文子串
                dp[j][j + (n-i)] += max(dp[j+1][j + (n-i)],dp[j][j + (n-i)-1]);
            }
        }
        return dp[0][n-1];
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello world" << endl;
	return 0;
}


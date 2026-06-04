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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // dp[i][j] 表示 word1 的前i个字母 对 word2的前j个字母的编辑距离
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        // 边界条件
        for(int i = 0;i<=n;i++){
            dp[i][0] = i; 
        }
        for(int j = 0;j<=m;j++){
            dp[0][j] = j; 
        }

        for(int i = 1;i<n+1;i++){
            for(int j = 1;j<m+1;j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = min(1 + min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]);
                }else{
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[n][m];

    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


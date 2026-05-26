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
    inline int sum(vector<int>& nums, int begin, int end){
        int res = 0;
        for(int i = begin;i<end;i++){
            res+=nums[i];
        }
        return res;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = this->sum(nums,0,n);
        if((sum - target) < 0){
            return 0;
        }
        if((sum - target)&1 == 1){
            return 0;
        }
        // sum = pos + neg
        // tar = pos - neg
        int neg = (sum - target)/2;
        // 特别注意初始化
        vector<vector<int>> dp(n,vector<int>(neg+1,0));
        dp[0][0] = 1;
        for(int j = 0;j<neg+1;j++){
            dp[0][j] += (nums[0] == j);
        }
        for(int i = 1;i < n;i++){
            for(int j = 0;j<neg+1;j++){
                // j < nums[i] 不能选
                // dp[i][j] = dp[i-1][j]
                dp[i][j] = dp[i-1][j];
                // j >= nums[i] k可以考虑选
                // dp[i][j] = dp[i-1][j] + dp[i-1][j - nums[i]]
                if(j >= nums[i]){
                    dp[i][j] += dp[i-1][j - nums[i]];
                }
            }
        }
        return dp[n-1][neg];
    }
};


int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello world" << endl;
	return 0;
}


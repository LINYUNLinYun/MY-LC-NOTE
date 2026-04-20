#include <iostream>
#include <vector>
#include <unordered_map>
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
    void helper(vector<int> &nums, vector<vector<int>> &res, vector<int> path, int start){
        res.push_back(path);
        if(start == nums.size()){
            return;
        }
        for(int i = start;i<nums.size();i++){
            path.push_back(nums[i]);
            helper(nums, res, path, i+1);
            path.pop_back();
        }
        return;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        // int n = pow(2, nums.size());
        vector<vector<int>> res;
        helper(nums,res,{},0);
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


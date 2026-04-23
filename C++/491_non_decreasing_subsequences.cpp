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
    void helper(vector<int>& nums, vector<int> &path, vector<vector<int>> &res, int start){
        if(path.size()>=2){
            res.push_back(path);
            if(start == nums.size()){
                return;
            }
        }
        unordered_set<int> used;
        for(int i = start;i<nums.size();i++){
            // 不应该在push答案的时候再检查是否重复
            if((!path.empty() && nums[i] < path.back()) || used.count(nums[i])){
                continue;
            }
            used.insert(nums[i]);
            path.push_back(nums[i]);
            helper(nums,path,res,i+1);
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        helper(nums,path,res,0);
        return res;

    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


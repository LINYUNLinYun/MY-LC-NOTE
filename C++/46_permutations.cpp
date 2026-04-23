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
    void helper(vector<int> nums, vector<vector<int>> &res, vector<int> &path){
        if(nums.size()==0){
            res.push_back(path);
            return;
        }
        int num = nums.back();
        nums.pop_back();
        // n-1
        for(int i = 0;i<nums.size();i++){
            swap(num, nums[i]);
            path.push_back(num);
            helper(nums, res,path);
            path.pop_back();
            swap(num, nums[i]);
        }
        path.push_back(num);
        helper(nums, res,path);
        path.pop_back();
        nums.push_back(num);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        helper(nums,res,path);
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


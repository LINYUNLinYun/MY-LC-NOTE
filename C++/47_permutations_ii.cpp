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
    void helper(vector<vector<int>> &res, vector<int> &path, vector<int> &nums){
        if(nums.size() == 0){
            res.push_back(path);
            return;
        }
        int num = nums.back();
        nums.pop_back();
        unordered_set<int> used;
        used.insert(num);
        for(int i = 0;i<nums.size();i++){
            if(used.count(nums[i])){
                // 要能检测到这个数应出现过了 然后不进行这个递归
                continue;
            }
            used.insert(nums[i]);
            swap(nums[i], num);
            path.push_back(num);
            helper(res, path, nums);
            path.pop_back();
            swap(num, nums[i]);
        }
        path.push_back(num);
        helper(res, path, nums);
        path.pop_back();
        nums.push_back(num);
        return;

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        helper(res, path ,nums);
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


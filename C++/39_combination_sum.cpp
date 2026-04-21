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
    void helper(vector<int> &candidates,vector<int> path, int path_sum, const int &target, vector<vector<int>> &res, int start = 0){
        if(path_sum > target){
            return;
        }
        else if(path_sum == target){
            res.push_back(path);
            return;
        }
        else{
            for(int i = start; i< candidates.size();i++){
                path.push_back(candidates[i]);
                path_sum += candidates[i];
                if(path_sum > target){
                    path.pop_back();
                    break;
                }
                helper(candidates, path, path_sum, target, res, i);
                // 忘了回溯这个变量直接错完！！！！！所以说 不要多事加一个变量 你让他算一下怎么了
                path_sum-=candidates[i];
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        helper(candidates,{},0,target,res,0);
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


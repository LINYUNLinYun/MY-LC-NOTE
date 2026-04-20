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
    vector<pair<int,int>> map;
    void helper(vector<vector<int>> &res, vector<int> path, int start){
        res.push_back(path);
        if(start == map.size()){
            return;
        }
        for(int i = start; i < map.size();i++){
            // helper(res, path, start+1);
            for(int j = 0; j < map[i].second;j++){
                path.push_back(map[i].first);
                helper(res, path, i+1);
            }
            for(int j = 0; j < map[i].second;j++){
                path.pop_back();
            }
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(auto n : nums){
            if(map.empty() || n != map.back().first){
                map.emplace_back(n,1);
            }else{
                map.back().second++;
            }
        }
        vector<vector<int>> res;
        helper(res,{},0);
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


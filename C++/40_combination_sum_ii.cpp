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
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> sequence;

public:
    void dfs(int pos, int rest) {
        // 匹配成功
        if (rest == 0) {
            ans.push_back(sequence);
            return;
        }
        // 匹配失败
        if (pos == freq.size() || rest < freq[pos].first) {
            return;
        }
        // 往下一个地方递归
        dfs(pos + 1, rest);
        // 计算当前数字能放几个 避免数字重复使用
        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; ++i) {
            sequence.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        for (int i = 1; i <= most; ++i) {
            sequence.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        // 按升序建表
        for (int num: candidates) {
            if (freq.empty() || num != freq.back().first) {
                freq.emplace_back(num, 1);
            } else {
                ++freq.back().second;
            }
        }
        dfs(0, target);
        return ans;
    }
};

// ---------我的有缺陷的做法----------
class Solution {
    public:
    vector<pair<int,int>> map;
    void helper(int const &target, vector<int> path, int path_sum, vector<vector<int>> &res, int start = 0){
        if(path_sum > target){
            return;
        }
        else if(path_sum == target){
            res.push_back(path);
            return;
        }
        else{
            // 第一层循环：决定这一层递归取第几个pos的元素 
            for(int i = start; i < map.size();i++){
                int most = min((target - path_sum)/map[i].first, map[i].second);
                // 第二层循环：决定这一层递归取几个这个元素 避免了重复——保证了相同元素多次被取到时的个数唯一
                for(int j = 1; j <= most;j++){
                    path.push_back(map[i].first);
                    path_sum += map[i].first;
                    if(path_sum > target){
                        // 剪枝
                        continue;
                    }
                    helper(target, path, path_sum,res,i+1);
                }
                for(int j = 1; j <= most;j++){
                    path.pop_back();
                    path_sum -= map[i].first;
                }
            }
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> res;
        for(auto num : candidates){
            if(map.empty() || map.back().first != num){
                map.emplace_back(num, 1);
            }
            else{
                map.back().second++;
            }
        }
        // 1 2 2 2 5
        helper(target,{}, 0,res, 0);
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


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
    bool isOverlap(vector<int>& a, vector<int>& b) {
        // a[0]  <= b[0]
        // 这里实际上应该可以被优化 因为b1大于b0
        return b[0] <= a[1] || b[1] <= a[1];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        for(int i = 0; i < intervals.size(); i++) {
            if(res.empty() || !isOverlap(res.back(), intervals[i])){
                res.push_back(intervals[i]);
                continue;
            }else{
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello world" << endl;
	return 0;
}


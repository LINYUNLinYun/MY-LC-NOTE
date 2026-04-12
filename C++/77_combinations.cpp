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
    void helper(int n, int k, int start, vector<int> path, vector<vector<int>> &res){
        if(k == 0 ){
            return;
        }
        for(int i = start; i<= n - k + 1;i++){
            // combine()
            path.push_back(i);
            if(k == 1){
                res.push_back(path);
            }else{
                helper(n, k-1,i+1,path,res);
            }
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        helper(n, k, 1, {}, res);
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<string> change(vector<vector<int>> res_in){
        vector<string> res;
        for(auto s : res_in){
            string temp;
            for(int i =0;i<s.size();i++){
                if(temp.empty()){
                    temp+=to_string(s[i]);
                }else{
                    temp+="->";
                    temp+=to_string(s[i]);
                }
            }
            res.push_back(temp);

        }
        return res;
    }
    vector<vector<int>> res;
    vector<int> now_path;
    vector<string> binaryTreePaths(TreeNode* root) {
        // 根节点空判断
        if(root == nullptr){
            return change(res);
        }
        //首次到达
        if(now_path.size() == 0){
            now_path.push_back(root->val);
        }else{
            // now_path+="->";
            now_path.push_back(root->val);
        }
        if(root->left == nullptr && root->right == nullptr){
            // 每到一次叶子节点就记录一个
            res.push_back(now_path);
            // now_path.pop_back();
            // return res;
        }
        if(root->left){
            binaryTreePaths(root->left);
            now_path.pop_back();
        }
        if(root->right){
            binaryTreePaths(root->right);
            now_path.pop_back();
        }
        return change(res);
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;

	cout << "hello wrold" << endl;
	return 0;
}


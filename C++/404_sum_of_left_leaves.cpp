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
    int left(TreeNode* root, int &res){
        if(root->left){
            if(root->left->left == nullptr && root->left->right == nullptr){
                res+=root->left->val;
            }
            left(root->left, res);
        }
        if(root->right){
            left(root->right, res);
        }
        return 0;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        if(root == nullptr){
            return res;
        }
        left(root, res);
        return res;
    }
};

// 建一个[1,2,3,4,5]的完全树，用于测试
TreeNode* build_tree(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    return root;
}

int main(int argc, char const *argv[]) {
	Solution s;
	TreeNode* root = build_tree();
    int result = s.sumOfLeftLeaves(root);
	cout << "Sum of left leaves: " << result << endl;
	return 0;
}


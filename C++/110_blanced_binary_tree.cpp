#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
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
    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int left_d = maxDepth(root->left) +1;
        int right_d = maxDepth(root->right) + 1;
		return left_d > right_d ? left_d : right_d;
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        int l_d = maxDepth(root->left);
        int r_d = maxDepth(root->right);
        if(abs(l_d - r_d)>1){
            return false;
        }else{
            return isBalanced(root->left) && isBalanced(root->right);
        }

    }
};

int main(int argc, char const *argv[]) {
	Solution s;

	cout << "hello wrold" << endl;
	return 0;
}


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
    bool curr_path(TreeNode* root, int path = 0, const int num = 0){
        if(root == nullptr){
            return false;
        }
        path += root -> val;
        if(path == num && root->left == nullptr && root->right == nullptr){
            return true;
        }
        bool left_path = curr_path(root->left, path, num);
        bool right_path = curr_path(root->right, path, num);

        return right_path || left_path;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool res = true;
        if(root == nullptr ){
            res = false;
        }
        else{
            res = curr_path(root, 0, targetSum);
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


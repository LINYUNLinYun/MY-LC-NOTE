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
    
    pair<int,int> helper(TreeNode* root, bool &valid){
        if(root->left == nullptr && root->right == nullptr){
            return {root->val, root->val};
        }
        int left_min_num, left_max_num,right_min_num, right_max_num;
        if(root->left && root->right == nullptr){
            auto res = helper(root->left,valid);
            left_max_num = res.second;
            left_min_num = res.first;
            if(left_max_num >= root->val){
                // return {INT_MIN, INT_MAX};
                valid = false;
            }else{
                return {left_min_num, root->val};
            }
        }
        if(root->right && root->left == nullptr){
            auto res = helper(root->right, valid);
            right_max_num = res.second;
            right_min_num = res.first;
            if(right_min_num <= root->val){
                // return {INT_MIN, INT_MAX};
                valid = false;
            }else{
                return {root->val, right_max_num};
            }
        }
        if(root->right && root->left){
            auto res = helper(root->left,valid);
            left_max_num = res.second;
            left_min_num = res.first;

            res = helper(root->right, valid);
            right_max_num = res.second;
            right_min_num = res.first;

            if(right_min_num <= root->val || left_max_num >= root->val){
                // return {INT_MIN, INT_MAX};
                valid = false;
            }else{
                return {left_min_num, right_max_num};
            }
        }
        return {};
    }

    bool isValidBST(TreeNode* root) {
        if(root == nullptr){
            return false;
        }
        bool valid = true;
        auto res = helper(root, valid);

        return valid;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


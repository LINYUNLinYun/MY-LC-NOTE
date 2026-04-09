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
    TreeNode* getTrimmedNode(TreeNode* root, bool direction, int target){
        if(root == nullptr){
            return nullptr;
        }
        if(direction == 0){
            // left
            while(root->left){
                if(root->left->val <= target){
                    return root->left;
                }else{
                    root = root->left;
                }
            }
            return nullptr;
        }
        if(direction == 1){
            // riht
            while(root->right){
                if(root->right->val >= target){
                    return root->right;
                }else{
                    root = root->right;
                }
            }
            return nullptr;
        }
        return nullptr;
    }
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 对于bst来说。如果一个根节点的val大于high了，那么它的右子树可以全部剪枝；low同理
        // 如果根节点在low和high之间，那么应该递归检查它的left和right
        // 即使根节点大于high也不意味着它的左子树应该被剪枝，即left可能小于high
        if(root == nullptr){
            return nullptr;
        }
        if(root->val < low){
            root = getTrimmedNode(root, 1, low);
        }
        if(root->val > high){
            root = getTrimmedNode(root, 0, high);
        }
        if(root == nullptr){
            return nullptr;
        }
        if(root->left && root->left->val < low){
            root->left = getTrimmedNode(root->left, 1, low);
            trimBST(root->left, low, high);
        }
        if(root->right && root->right->val > high){
            root->right = getTrimmedNode(root->right, 0, high);
            trimBST(root->right, low, high);
        }
        return root;

    }
};
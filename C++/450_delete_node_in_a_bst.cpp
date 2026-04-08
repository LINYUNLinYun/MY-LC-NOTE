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
    TreeNode* deleteRootNode(TreeNode* root){
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)){
            return nullptr;
        }
        // 如果右子树存在 右成为新的根
        if(root->right){
            TreeNode* temp = root->right;
            // 找到最小节点
            while(temp->left){
                temp = temp->left;
            }
            temp->left = root->left;
            return root->right;
        }else{
            return root->left;
        }


    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }
        // 等价于对替换掉一个树的根节点
        // 左右子树都在
        if(root->val == key){
            return deleteRootNode(root);
        }
        if(root->left){
            if(root->left->val == key){
                root->left = deleteRootNode(root->left);
            }else{
                deleteNode(root->left,key);
            }
        }
        if(root->right){
            if(root->right->val == key){
                root->right = deleteRootNode(root->right);
            }else{
                deleteNode(root->right,key);
            }
        }
        return root;
    }
};
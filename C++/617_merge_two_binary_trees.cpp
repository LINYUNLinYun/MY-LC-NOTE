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
    // TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    //     // 对root1递归 root2同步递归
    //     // 都没有 终止
    //     if(root1 == nullptr && root2 == nullptr){
    //         return nullptr;
    //     }
        
    //     // 如果root1 && root2那就把2加到1
    //     if(root1 && root2){
    //         root1->val += root2->val;
    //         mergeTrees(root1->left, root2->left);
    //         mergeTrees(root1->right, root2->right);
    //     }
    //     // 如果 root1 || root2 沿着那一条走下去
    //     else if(root1 && root2 == nullptr){
    //         mergeTrees(root1->left, nullptr);
    //         mergeTrees(root1->right, nullptr);
    //     }
    //     else if(root2 && root1 == nullptr){
    //         mergeTrees(nullptr, root2->left);
    //         mergeTrees(nullptr, root2->right);
    //     }
    // }
    TreeNode* helper(TreeNode* root1, TreeNode* root2){
        root1->val += root2->val;
        // 如果都有左儿子
        if(root1->left && root2->left){
            helper(root1->left, root2->left);
        }
        // root1有左儿子
        else if(root1->left && root2->left == nullptr){
            // return root1;
        }
        // root2有左儿子
        else if(root1->left == nullptr && root2->left){
            root1->left = root2->left;
            // return root1;
        }

        // 如果都有右儿子
        if(root1->right && root2->right){
            helper(root1->right, root2->right);
        }
        // root1有右儿子
        else if(root1->right && root2->right == nullptr){
            // return root1;
        }
        // root2有右儿子
        else if(root1->right == nullptr && root2->right){
            root1->right = root2->right;
        }

        return root1;
    }
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr && root2 == nullptr){
            return nullptr;
        }
        else if(root1 && root2 == nullptr){
            return root1;
        }
        else if(root1 == nullptr && root2){
            return root2;
        }
        else{
            return helper(root1, root2);
        }
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


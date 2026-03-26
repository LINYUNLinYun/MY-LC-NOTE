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
    int getDepth(const TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        return getDepth(root->left) + 1;
    }

    int countNodes(TreeNode* root) {
        int res = 0;
        TreeNode* temp = root;
        while(temp){
            res+=1;                 // 添加本轮的根节点
            int l_d = getDepth(temp->left);
            int r_d = getDepth(temp->right);
            if(l_d == r_d){
                temp = temp->right;
                res+= (1 << l_d) -1; //位运算代替2的幂 完全二叉树的性质确保了可以用高度计算节点数
            }
            else{
                temp = temp->left;
                res+= (1 << r_d) -1; //位运算代替2的幂
            }


        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
	Solution s;

	cout << "hello wrold" << endl;
	return 0;
}


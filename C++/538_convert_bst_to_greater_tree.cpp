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
    void inorder(TreeNode* root, vector<TreeNode*> &inorder_roots){
        if(root == nullptr){
            return;
        }
        inorder(root->left, inorder_roots);
        inorder_roots.push_back(root);
        inorder(root->right, inorder_roots);
        return;
    
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }
        vector<TreeNode*> inorder_roots;
        inorder(root, inorder_roots);
        int n = inorder_roots.size();
        int sum = 0;
        for(int i = n-1;i >=0;i--){
            inorder_roots[i]->val+=sum;
            sum = inorder_roots[i]->val;
        }
        return root;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


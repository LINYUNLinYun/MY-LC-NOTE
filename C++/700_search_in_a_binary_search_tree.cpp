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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr){
            return nullptr;
        }
        if(val == root->val){
            return root;
        }
        if(val > root->val){
            return searchBST(root->right,val);
        }
        else{
            return searchBST(root->left,val);
        }
        return nullptr;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


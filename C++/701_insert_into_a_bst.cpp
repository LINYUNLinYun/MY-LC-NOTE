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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == nullptr){
            return new TreeNode(val);
        }
        TreeNode* root_temp = root;
        while(true){
            if(root->val > val){
                if(root->left){
                    root = root->left;
                }else{
                    root->left = new TreeNode(val);
                    break;
                }
            }else{
                if(root->right){
                    root = root->right;
                    // root = root->left;
                }else{
                    root->right = new TreeNode(val);
                    break;
                }
            }

        }
        return root_temp;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


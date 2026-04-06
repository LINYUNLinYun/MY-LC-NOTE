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
    int getEdgeNodeVal(TreeNode* root, int direction) {
        if(root == nullptr){
            return INT_MAX;
        }
        if(direction){
            while(root->right){
                root = root->right;
            }
            return root->val;
        }
        else{
            while(root->left){
                root = root->left;
            }
            return root->val;
        }
    }
    int helper(TreeNode* root){
        int abs_res = INT_MAX;
        if(root == nullptr){
            return abs_res;
        }
        if(root->left){
            int left_max = getEdgeNodeVal(root->left, 1);
            left_max = abs(left_max - root->val);
            abs_res = left_max < abs_res ? left_max : abs_res;
        }
        if(root->right){
            int right_min = getEdgeNodeVal(root->right, 0);
            right_min = abs(right_min - root->val);
            abs_res = right_min < abs_res ? right_min : abs_res;
        }
        int left_res = helper(root->left);
        int right_res = helper(root->right);
        abs_res = left_res < abs_res ? left_res : abs_res;
        abs_res = right_res < abs_res ? right_res : abs_res;
        return abs_res;
    }

    // 第二种做法  基于中序遍历
    void inorder(TreeNode* root, vector<int> &nums){
        if(root == nullptr){
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
        return;
    }

    int min_abs(TreeNode* root){
        vector<int> temp;
        inorder(root, temp);
        int res = INT_MAX;
        for(int i = 0;i<temp.size();i++){
            if(i!=0){
                res = min(res, abs(temp[i-1] - temp[i]));
            }
        }
        return res;
    }

    int getMinimumDifference(TreeNode* root) {
        // 如果bst的某个根节点存在最小差值 一定是它的左右子树的最右/左节点产生
        return helper(root);
    }
};
int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


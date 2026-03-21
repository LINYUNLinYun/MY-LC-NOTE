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
    void inOrderTraversal(TreeNode* root, vector<int>& res){
        if(root == nullptr){
            res.push_back(0);
            return;
        }
        if(root->left == nullptr && root->right == nullptr){
            res.push_back(-1);
            res.push_back(root->val);
            res.push_back(-1);
            return;
        }
        inOrderTraversal(root->left,res);
        res.push_back(root->val);
        inOrderTraversal(root->right,res);
        return;
    }   
    bool isSymmetric(TreeNode* root) {
        // 中序遍历的次序应该是对称的
        vector<int> order;
        inOrderTraversal(root,order);
        int n = order.size();
        bool isSymmetric = true;
        for(int i = 0;i<n/2;i++){
            if(order[i]!=order[n-i-1]){
                isSymmetric = false;
                break;
            }
        }
        return isSymmetric;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	queue<int> q;
	stack<int> s;
	s.push(6);
	s.push(7);
	cout << s.top() << s.size();
	s.pop();
	cout<<s.top();
	cout << "hello wrold" << endl;
	return 0;
}


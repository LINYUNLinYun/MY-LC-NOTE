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
    // 中序遍历
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
    
    static void get_depth(TreeNode* root, unordered_map<int, vector<int>>& node_depth, int depth = 0){
        if(root == nullptr){
            node_depth[depth].push_back(INT_MIN);
            return;
        }
        node_depth[depth].push_back(root->val);
        get_depth(root->left, node_depth, depth+1);
        get_depth(root->right, node_depth, depth+1);
    }

    bool isSymVec(const vector<int> input){
        bool res = true;
        int n = input.size();
        for(int  i = 0;i<n/2;i++){
            if(input[i]!=input[n-i-1]){
                res = false;
                break;
            }
        }
        return res;
    }

    bool isSymmetric(TreeNode* root) {
        // vector<pair<int, int>> node_depth;
        unordered_map<int, vector<int>> val_map;
        get_depth(root, val_map);
        bool res = true;
        for(auto m : val_map){
            if(!isSymVec(m.second)){
                res = false;
                break;
            }
        }
        return res;

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


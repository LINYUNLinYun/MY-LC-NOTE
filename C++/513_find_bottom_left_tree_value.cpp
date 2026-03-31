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

    int maxDepth(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        int left_d = maxDepth(root->left) +1;
        int right_d = maxDepth(root->right) + 1;
		return left_d > right_d ? left_d : right_d;
    }
    
    int findBottomLeftValue(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        // 获取最大深度
        int depth = maxDepth(root);
        // 队列 模拟层序遍历
        queue<pair<TreeNode*, int>> que;
        que.push({root, 1});
        int res = 0;
        // 当队列不为空
        while(!que.empty()){
            auto temp = que.front();
            que.pop();
            int now_head_depth = temp.second;
            TreeNode* now_head = temp.first;
            if(now_head_depth == depth){
                res = now_head->val;
                break;
            }
            if(now_head->left){
                que.push({now_head->left, now_head_depth+1});
            }
            if(now_head->right){
                que.push({now_head->right, now_head_depth+1});
            }
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


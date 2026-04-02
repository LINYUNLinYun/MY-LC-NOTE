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

/**v2.0 新版本写法 哈希表+左右指针*/

class Solution {
public:
    int post_index;
    unordered_map<int,int> map;     //记录中序遍历元素的下标 方便查询
    TreeNode* helper(int in_left, int in_right,  vector<int>& postorder){
        // 退出条件
        if(in_left > in_right){
            return nullptr;
        }
        post_index--;
        TreeNode* root = new TreeNode(postorder[post_index]);
        int in_index = map[root->val];
        
        root->right = helper(in_index+1, in_right,  postorder);
        root->left =  helper(in_left, in_index-1,  postorder);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // 建表
        for(int i = 0;i<inorder.size();i++){
            map[inorder[i]] = i;
        }
        post_index = postorder.size();
        // 获取最初的根节点
        return helper(0 , inorder.size()-1,  postorder);
    }
};



/*v1.0 老版本写法 为子树单独开容器 主打一个空间复杂度比较高
    然后查询用的是二层循环遍历 效率也比较一般
*/

// class Solution {
// public:
//     vector<int> getChildTree(vector<int>& father, vector<int>& target){
//         int n = target.size();  //获取目标树的长度 
//         int index = 0;
//         for(int i = 0; i< father.size();i++){
//             bool res = false;
//             for(int j = 0;j<n;j++){
//                 if(father[i] == target[j]){
//                     res = true;
//                     index = i;
//                     break;
//                 }
//             }
//             if(res){
//                 break;
//             }
//         }
//         vector<int> child(father.begin()+index, father.begin()+index+n);
//         return child;
//     }
//     TreeNode* recursiveTree(vector<int>& inorder, vector<int>& postorder, TreeNode* root){
//         if(inorder.size() == 0 || postorder.size()==0){
//             return nullptr;
//         }
//         // 寻找当前根节点
//         int root_val = postorder.back();
//         TreeNode* root_node = new TreeNode(root_val);
//         // root_node = temp;
//         int root_index = 0;
//         for(int i = 0;i<inorder.size();i++){
//             if(inorder[i] == root_val){
//                 root_index = i;
//                 break;
//             }
//         }

//         vector<int> inorder_left(inorder.begin(), inorder.begin()+root_index);

//         vector<int> inorder_right(inorder.begin()+root_index+1, inorder.end());

//         vector<int> postorder_left = getChildTree(postorder, inorder_left);
//         vector<int> postorder_right = getChildTree(postorder, inorder_right);
        
//         root_node->left =  recursiveTree(inorder_left, postorder_left, nullptr);
//         root_node->right = recursiveTree(inorder_right, postorder_right, nullptr);
//         // root_node->left = new TreeNode(postorder_left.back());
//         // root_node->right = new TreeNode(postorder_right.back());

//         return root_node;
//     }
//     TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
//         // 后序遍历的最后一个节点即为根节点

//         // 中序遍历的某个节点是根节点 它的左右即为根节点的左右子树
//         // 那么思路也很简单 先通过后序遍历找到当前树的根节点 然后在inorder中找到根 再把根的左右分为左右子树
//         // 关键在于得到了中序遍历对应的左右子树 怎么把对应的后续遍历的左右子树分离出来 好重复这个步骤
//         // 需要一个专门的函数 负责从后序中找出并返回左右子树

//         TreeNode* root;
//         root = recursiveTree(inorder, postorder, nullptr);

//         return root;
        
        
//     }
// };

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


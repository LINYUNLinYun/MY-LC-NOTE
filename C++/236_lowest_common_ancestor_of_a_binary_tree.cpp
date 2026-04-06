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
    void getNodePath(TreeNode* root, TreeNode* p, TreeNode* q, string path, vector<string> &paths){
        if(root == nullptr){
            return;
        }
        if(root == p){
            paths.push_back(path);
            
        }
        if(root == q){
            paths.push_back(path);
            
        }
        getNodePath(root->left, p, q, path+"0",paths);
        getNodePath(root->right, p, q, path+"1",paths);
        return;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<string> paths;
        getNodePath(root, p, q, "", paths);
        if(paths.size()!=2){
            return nullptr;
        }
        string p_path = paths[0];
        string q_path = paths[1];

        int index = 0;
        for(int i = 0;i < min(p_path.size(), q_path.size());i++){
            if(p_path[i] == q_path[i]){
                index++;
            }else{
                break;
            }
        }
        for(int i = 0; i< index;i++){
            if(p_path[i] == '0'){
                root = root->left;
            }else{
                root = root->right;
            }
        }
        return root;
        // getNodePath(root, q, "", paths);
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


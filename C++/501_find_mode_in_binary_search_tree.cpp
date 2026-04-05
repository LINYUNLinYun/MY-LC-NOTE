

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
    void inorder(TreeNode* root, vector<int> &nums){
        if(root == nullptr){
            return;
        }
        inorder(root->left, nums);
        nums.push_back(root->val);
        inorder(root->right, nums);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> nums;
        inorder(root, nums);
        vector<int> res;
        int max_count = 1;
        int now_count = 1;
        for(int i = 0;i<nums.size();i++){
            if(i!=0){
                if(nums[i] == nums[i-1]){
                    now_count+=1;
                    if(now_count > max_count){
                        res.clear();
                        res.push_back(nums[i]);
                        max_count = now_count;
                    }else if(now_count == max_count){
                        res.push_back(nums[i]);
                    }
                }
                else{
                    now_count=1;
                    if(now_count == max_count){
                        res.push_back(nums[i]);
                    }
                }
            }else{
                res.push_back(nums[i]);
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


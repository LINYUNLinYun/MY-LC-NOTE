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
    int max_index(int left, int right, const vector<int>& nums){
        if(left > right){
            return -1;
        }
        int max = INT_MIN;
        int index = 0;
        for(int i = 0;i < right - left + 1; i++){
            if(nums[i+left] > max){
                max = nums[i+left];
                index = i+left;
            }
        }
        return index;
    }
    TreeNode* helper(int left, int right, const vector<int>& nums){
        if(left > right){
            return nullptr;
        }
        int index = max_index(left, right, nums);
        TreeNode* root = new TreeNode(nums[index]);
        
        root->left = helper(left, index-1, nums);
        root->right = helper(index+1, right, nums);
        
        return root;

    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return helper(0, n-1, nums);

    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n<1){
            return 0;
        }
        int last_sum = nums[0];
        int max_sum = last_sum;
        for(int i = 1;i<n;i++){
            last_sum = max(nums[i], last_sum + nums[i]);
            max_sum = max(max_sum, last_sum);
        }
        return max_sum;
    }
    
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


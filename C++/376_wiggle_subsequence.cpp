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

// dp
class Solution {
public:
    int wiggleMaxLength_dp(vector<int>& nums) {
        int n = nums.size();
        // 一个元素一定是摆动序列
        if (n < 2) {
            return n;
        }
        vector<int> up(n), down(n);
        up[0] = down[0] = 1;
        for (int i = 1; i < n; i++) {
            // 当前数字大于上一个数字 说明存在一个正差
            if (nums[i] > nums[i - 1]) {
                // 上一个下降序列+1可以得到一个上升序列
                up[i] = max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                up[i] = up[i - 1];
                down[i] = max(up[i - 1] + 1, down[i - 1]);
            } else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }
    int wiggleMaxLength_dp2(vector<int>& nums) {
        int n = nums.size();
        // 一个元素一定是摆动序列
        if (n < 2) {
            return n;
        }
        int up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            // 当前数字大于上一个数字 说明存在一个正差
            if (nums[i] > nums[i - 1]) {
                // 上一个下降序列+1可以得到一个上升序列
                up = max(up, down+1);
                
            } else if (nums[i] < nums[i - 1]) {
                down = max(up + 1, down);
            }
        }
        return max(up,down);
    }
    // 贪心
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        // 一个元素一定是摆动序列
        if (n < 2) {
            return n;
        }
        int last_dx = 0;
        int max_lenght = 1;
        for(int i = 1;i<n;i++){
            int temp_dx = nums[i] - nums[i-1];
            if(temp_dx > 0 && last_dx == -1){
                max_lenght++;
                last_dx = 1;
            }
            else if(temp_dx < 0 && last_dx == 1){
                max_lenght++;
                last_dx = -1;
            }
            // 初始特殊判断
            else if(last_dx == 0){
                if(temp_dx == 0){
                    last_dx = last_dx;
                }else if(temp_dx<0){
                    max_lenght++;
                    last_dx = -1;
                }else if(temp_dx>0){
                    max_lenght++;
                    last_dx = 1;
                }
            }
        }
        return max_lenght;
    }

};


int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


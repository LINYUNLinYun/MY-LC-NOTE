#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        // 开两个数组 dp0表示到第i个房子不偷的最大价值 dp1表示到第i个房子偷的最大价值
        // 两个初始都为0 状态转移看代码
        // 具体说 上一次偷或不偷这轮都能转移到不偷 但上一轮偷了这一轮就只能去不偷
        int n = nums.size();
        vector<int> dp0(n+1,0);
        vector<int> dp1(n+1,0);
        for(int i = 0;i<n;i++){
            dp0[i+1] = max(dp1[i],dp0[i]);
            dp1[i+1] = max(nums[i]+dp0[i],dp1[i]);
        }
        return max(dp0[n],dp1[n]);
    }
};
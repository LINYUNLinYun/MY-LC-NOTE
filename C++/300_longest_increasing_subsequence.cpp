#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm> 
#include <stack>
#include <queue>
#include <cmath>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> d(n+1);
        int len =1;
        d[len] = nums[0];
        for(int i = 1;i<n;i++){
            if(nums[i] > d[len]){
                d[len+1] = nums[i];
                len+=1;
                continue;
            }
            int left= 1;
            int right = len;
            int pos = 0;
            // 找出第一个比nums[i]小的数
            while(left <= right){
                int mid = (left + right)/2;
                if(d[mid] < nums[i]){
                    pos = mid;
                    left = mid+1;
                }
                else{
                    right = mid-1;
                }
            }
            d[pos+1] = nums[i];
        }
        return len;
    }
};
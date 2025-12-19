#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        //很难绷的是这题和三数之和一个方法
        // int first = 0;
        for(int first = 0;first < n - 3;first++){
            if(first>0 && nums[first] == nums[first-1]){
                continue;
            }
            // 剪枝
            if((long)nums[first]+nums[first+1]+nums[first+2]+nums[first+3] > (long)target){
                break;
            }
            if((long)nums[first]+nums[n-1]+nums[n-2]+nums[n-3] < (long)target){
                continue;
            }
            for(int second = first+1;second<n-2;second++){
                if(second>first+1 && nums[second] == nums[second - 1]){
                    continue;
                }
                // 剪枝
                if((long)nums[first]+nums[second]+nums[second+1]+nums[second+2] > (long)target){
                    break;
                }
                if((long)nums[first]+nums[second]+nums[n-1]+nums[n-2] < (long)target){
                    continue;
                }
                int fourth = n -1;
                for(int third = second + 1;third<n-1;third++){
                    if(third>second+1 && nums[third] == nums[third-1]){
                        continue;
                    }
                    // 剪枝
                    if((long)nums[first]+nums[second]+nums[third]+nums[third] > (long)target){
                        continue;
                    }
                    long target_new = (long)target - nums[first] - nums[second]- nums[third];
                    while(third < fourth && nums[fourth] >target_new ){
                        fourth--;
                    }
                    if(third == fourth){
                        break;
                    }
                    if(target_new == nums[fourth]){
                        result.push_back({nums[first],nums[second],nums[third],nums[fourth]});
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
	
	cout << "hello wrold" << endl;
	return 0;
}


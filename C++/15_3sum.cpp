#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 从小到大排序
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        // 第一层循环，枚举first
        for(int first = 0;first<n;first++){
            // 当该元素与前一个重复就跳过
            if(first>0&&nums[first] == nums[first-1]){
                continue;
            }
            // third从末尾开始枚举，这个变量不应该放在第二层循环里
            // 因为third其实是可以记录历史信息的，如果上一次的second都觉得third不够小，这一轮的都不用考虑它后面的
            int third = n-1;
            // 第二层
            for(int second = first + 1; second<n;second++){
                // 重复，跳过
                if(second>first+1 && nums[second] == nums[second - 1]){
                    continue;
                }
                int target = -(nums[first] + nums[second]);
                // 检查下标，，，and 当第三个还大于target说明还没减到位，如果小于了剩下的third都不行全部排除
                while(second<third && target < nums[third]){
                    third--;
                }
                if(second == third){
                    break;
                }
                // 三数之和为0
                if(-target+nums[third] == 0){
                    result.push_back({nums[first], nums[second], nums[third]});
                    // break;
                }
            }

        }
        return result;
    }
};


int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


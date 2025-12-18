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

// class Solution {
// public:

    
//     bool isVectorEqualIgnoreOrder(const vector<int>& v1, const vector<int>& v2) {
//         // 第一步：先判断元素个数是否相同（个数不同直接返回false）
//         if (v1.size() != v2.size()) {
//             return false;
//         }

//         // 第二步：复制原vector（避免修改原数据的顺序）
//         vector<int> v1_copy = v1;
//         vector<int> v2_copy = v2;

//         // 第三步：对复制后的vector排序
//         sort(v1_copy.begin(), v1_copy.end());
//         sort(v2_copy.begin(), v2_copy.end());

//         // 第四步：比较排序后的vector（此时顺序统一，==可直接判断）
//         return v1_copy == v2_copy;
//     }

//     vector<vector<int>> threeSum(vector<int>& nums) {
//         vector<vector<int>> result;
//         unordered_map<int,pair<int,int>> hashTable;
//         int n = nums.size();
//         for(int i = 0;i<n;i++){
//             for(int j = i+1;j<n;j++){
//                 hashTable.insert({nums[i]+nums[j],{i,j}});
//             }
//         }
//         for(int i = 0;i<n;i++){
//             if(hashTable.count(-nums[i]) && hashTable[-nums[i]].first!=i && hashTable[-nums[i]].second!=i){
//                 vector<int> temp;
//                 temp.push_back(nums[i]);
//                 temp.push_back(nums[hashTable[-nums[i]].first]);
//                 temp.push_back(nums[hashTable[-nums[i]].second]);
//                 bool exist = false;
//                 for(const auto v : result){
//                     if(isVectorEqualIgnoreOrder(v,temp)){
//                         exist = true;
//                         break;
//                     }
//                 }
//                 if(!exist){
//                     result.push_back(temp);
//                 }
//             }
//         }
//         return result;
//     }
// };

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


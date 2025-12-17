#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;


using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 
        int n = nums.size();
        sort(nums.begin(), nums.end());     //排序
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};

class Solution {
public:

    
    // bool isVectorEqualIgnoreOrder(const vector<int>& v1, const vector<int>& v2) {
    //     // 第一步：先判断元素个数是否相同（个数不同直接返回false）
    //     if (v1.size() != v2.size()) {
    //         return false;
    //     }

    //     // 第二步：复制原vector（避免修改原数据的顺序）
    //     vector<int> v1_copy = v1;
    //     vector<int> v2_copy = v2;

    //     // 第三步：对复制后的vector排序
    //     sort(v1_copy.begin(), v1_copy.end());
    //     sort(v2_copy.begin(), v2_copy.end());

    //     // 第四步：比较排序后的vector（此时顺序统一，==可直接判断）
    //     return v1_copy == v2_copy;
    // }

    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>> result;
    //     unordered_map<int,pair<int,int>> hashTable;
    //     int n = nums.size();
    //     for(int i = 0;i<n;i++){
    //         for(int j = i+1;j<n;j++){
    //             hashTable.insert({nums[i]+nums[j],{i,j}});
    //         }
    //     }
    //     for(int i = 0;i<n;i++){
    //         if(hashTable.count(-nums[i]) && hashTable[-nums[i]].first!=i && hashTable[-nums[i]].second!=i){
    //             vector<int> temp;
    //             temp.push_back(nums[i]);
    //             temp.push_back(nums[hashTable[-nums[i]].first]);
    //             temp.push_back(nums[hashTable[-nums[i]].second]);
    //             bool exist = false;
    //             for(const auto v : result){
    //                 if(isVectorEqualIgnoreOrder(v,temp)){
    //                     exist = true;
    //                     break;
    //                 }
    //             }
    //             if(!exist){
    //                 result.push_back(temp);
    //             }
    //         }
    //     }
    //     return result;
    // }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


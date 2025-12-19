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
        unordered_map<int, pair<int,int>> hashTable;
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue;
            }
            for(int j = i+1;j<n;j++){
                if(j>i+1 && nums[j] == nums[j-1]){
                    continue;
                }
                hashTable.insert({nums[i]+nums[j], {i,j}});
            }
        } 
        for(auto iter = hashTable.begin();iter!=hashTable.end();){
            for(auto iter2 = ++iter;iter2!=hashTable.end();iter2++){
                if(iter->first+iter2->first == target){
                    if(nums[iter->second.first] != nums[iter2->second.first] && nums[iter->second.first] != nums[iter2->second.second]
                    && nums[iter->second.second] != nums[iter2->second.first] && nums[iter->second.second] != nums[iter2->second.second]){
                        result.push_back({nums[iter->second.first],nums[iter->second.second],nums[iter2->second.first],nums[iter2->second.second]});
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


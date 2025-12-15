#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        vector<int> result;
        for(int i = 0;i<nums.size();i++){
            
            if(hashTable.count(target - nums[i])){
                result.push_back(i);
                result.push_back(hashTable[target - nums[i]]);
                break;
            }
            hashTable[nums[i]] = i;
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
	cout << "hello wrold" << endl;
	return 0;
}



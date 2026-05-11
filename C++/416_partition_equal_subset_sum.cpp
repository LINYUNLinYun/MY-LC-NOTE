#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    inline int sum(vector<int>& nums, int begin, int end){
        int res = 0;
        for(int i = begin;i<end;i++){
            res+=nums[i];
        }
        return res;
    }
    // 给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
    bool canPartition(vector<int>& nums) {
        // 先做清洗
        int n = nums.size();
        int sum = this->sum(nums, 0,n);
        if(n<2 || sum & 1){
            return false;
        }
        int target = sum/2;
        int max_num = *max_element(nums.begin(),nums.end());
        if(max_num > target){
            return false;
        }

    }
};
int main(int argc, char const *argv[]) {
	// Solution s;
	queue<int> q;
	
	stack<int> s;
	s.push(6);
	s.push(7);
	cout << s.top() << s.size();
	s.pop();
	cout<<s.top();
	cout << "hello wrold" << endl;
	return 0;
}




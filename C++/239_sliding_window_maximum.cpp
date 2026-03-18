#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        // 最大堆
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < k; ++i) {
            q.emplace(nums[i], i);
        }
        vector<int> ans = {q.top().first};
        for (int i = k; i < n; ++i) {
            q.emplace(nums[i], i);
            while (q.top().second <= i - k) {
                q.pop();
            }
            ans.push_back(q.top().first);
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//         // 一个n的数组， k可以滑动n-k次
//         int n = nums.size();
//         vector<int> res;
//         // if( k == n){
//         //     res.push_back(nums[max_element(nums.begin(),nums.end()) - nums.begin()]);
//         // }
//         // queue<int> que;
//         // int maxnum = INT_MIN;
//         // int index = 0;
//         // // 填充K个
//         // while(que.size()<k){
//         //     que.push(nums[index]);
//         //     if(nums[index]>maxnum){
//         //         maxnum = nums[index];
//         //     }
//         //     index++;
//         // }
//         // res.push_back(maxnum);
//         for(int i =0;i<=n-k;i++){
//             int maxnum = INT_MIN;
//             // 剪枝
//             if(i!=0){
//                 int lastmax = res.back();
//                 if(nums[i + k -1] > lastmax){
//                     res.push_back(nums[i + k -1]);
//                     continue;
//                 }
//                 if(nums[i-1] < lastmax && nums[i + k -1] < lastmax){
//                     res.push_back(lastmax);
//                     continue;
//                 }
//             }
//             for(int j = 0;j<k;j++){
//                 if(nums[i+j] > maxnum){
//                     maxnum = nums[i+j];
//                 }
//             }
//             res.push_back(maxnum);
//         }
//         return res;
//     }
// };


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


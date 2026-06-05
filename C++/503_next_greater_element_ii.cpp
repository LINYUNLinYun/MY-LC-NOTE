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
    vector<int> nextGreaterElements(vector<int>& nums) {
        // 单调栈

        int n = nums.size();
        // unordered_map<int,int> tb;
        vector<int> res(n,-1);
        vector<int> isPush(n,0);
        stack<int> s;
        int count = 0;
        int i = 0;
        while(count< 2*n -1){
            i= count % n;
            // ==0 说明这个数还没处理过
            if(s.empty() && isPush[i]==0){
                s.push(i);   
                isPush[i] = 1;   
                count++; 
                continue;
            }
            while(!s.empty() && nums[s.top()] < nums[i]){
                res[s.top()] = nums[i];
                s.pop(); 
            }
            if(isPush[i]==0){
                s.push(i);
                isPush[i]=1;
            }
            count++;

        }
        return res;
    }
};

// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         // 单调栈
//         int m = nums1.size();
//         int n = nums2.size();
//         unordered_map<int,int> tb;
//         vector<int> res(m,-1);
//         stack<int> s;
//         for(int i = 0;i<n;i++){
//             if(s.empty()){
//                 s.push(i);   
//                 continue;
//             }
//             while(!s.empty() && nums2[s.top()] < nums2[i]){
//                 tb[nums2[s.top()]] = nums2[i];
//                 s.pop(); 
//             }
//             s.push(i);

//         }
//         for(int i = 0;i<m;i++){
//             if(tb.find(nums1[i]) != tb.end()){
//                 res[i] = tb[nums1[i]];
//             }
//         }
//         return res;
//     }
// };
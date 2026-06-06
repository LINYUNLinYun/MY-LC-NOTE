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
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // 单调栈
        int m = nums1.size();
        int n = nums2.size();
        unordered_map<int,int> tb;
        vector<int> res(m,-1);
        stack<int> s;
        for(int i = 0;i<n;i++){
            if(s.empty()){
                s.push(i);   
                continue;
            }
            while(!s.empty() && nums2[s.top()] < nums2[i]){
                tb[nums2[s.top()]] = nums2[i];
                s.pop(); 
            }
            s.push(i);

        }
        for(int i = 0;i<m;i++){
            if(tb.find(nums1[i]) != tb.end()){
                res[i] = tb[nums1[i]];
            }
        }
        return res;
    }
};
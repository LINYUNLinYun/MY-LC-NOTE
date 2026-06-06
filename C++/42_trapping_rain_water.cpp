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

    int trap_dp(vector<int>& height) {
        int n = height.size();
        // dp数组 记录的是下标i以及i左侧的最大值
        vector<int> left_max(n);
        vector<int> right_max(n);
        // 边界条件
        left_max[0] = height[0];
        right_max[n-1] = height[n-1];
        // 先预处理 动态规划数组
        for(int i =1;i<n;i++){
            left_max[i] = max(left_max[i-1], height[i]);
        }
        for(int i =n-2;i>=0;i--){
            right_max[i] = max(right_max[i+1], height[i]);
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            res+=min(left_max[i],right_max[i]) - height[i];
        }
        return res;
    }
    /*****************单调栈做法******************* */
    int trap_stack(vector<int>& height) {
        int n = height.size();
        int res = 0;

        stack<int> s;
        for(int i = 0;i<n;i++){
            while(!s.empty() && height[s.top()] < height[i]){
                int bottom_height = height[s.top()];
                s.pop();
                if(s.empty()){
                    // 只有底是没法形成坑的
                    break;
                }

                int curr_width =  i - s.top() - 1;
                int curr_height =  min(height[i], height[s.top()]) - bottom_height;
                res+=curr_height*curr_width;
            }
            s.push(i);
        }
        
        return res;
    }
    /*****************双指针做法******************* */
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;

        int left = 0;
        int left_max = 0;
        int right = n-1;
        int right_max = 0;

        while(left < right){
            left_max = max(height[left], left_max);
            right_max = max(height[right], right_max);
            // 说白了 想要存雨水一定要有坑 当left_max 更小的时候坑由left_max决定
            // 所以每次都从小的那个max那一边开始找坑
            if(left_max < right_max){
                res+=left_max - height[left];
                left++;
            }else{
                res+=right_max - height[right];
                right--;    
            }
        }
        return res;
    }
        



    /** ***************** 物理模拟滑动方法 鉴定为又麻烦又不好实现********************/
    // bool isButtom(vector<int>& height, int rainPosition){
    //     if(rainPosition == 0 || rainPosition == height.size()){
    //         return false;
    //     }
    //     int left =rainPosition;
    //     int right = rainPosition;
    //     bool left_ = false;
    //     bool right_ = false;
    //     while(left >= 0 && right <height.size()){
    //         if(height[left] == height[rainPosition]){
    //             left--;
    //         }else if(height[left] < height[rainPosition]){
    //             return false;
    //         }else{
    //             left_ = true;
    //         }

    //         if(height[right] == height[rainPosition]){
    //             right++;
    //         }else if(height[right] < height[rainPosition]){
    //             return false;
    //         }else{
    //             right_ = true;
    //         }
    //         if(left_ && right_){
    //             break;
    //         }
    //     }
    //     return left > 0 && right < height.size() - 1;
    // }
    // bool moveRain(vector<int>& height, int rainPosition){
    //     while(true){
    //         if(isButtom(height, rainPosition)){
    //             height[rainPosition]++;
    //             return true;
    //         }else{
    //             break;
    //         }
    //     }
    //     int i =rainPosition-1;
    //     while(i >=0){
    //         if(isButtom(height, i)){
    //             height[i]++;
    //             return true;
    //         }else{
    //             i--;
    //         }
    //     }
    //     i =rainPosition+1;
    //     while(i <height.size()){
    //         if(isButtom(height, i)){
    //             height[i]++;
    //             return true;
    //         }else{
    //             i++;
    //         }
    //     }
    //     return false;

    // }
    // int trap(vector<int>& height) {
    //     // 模拟重力势能
    //     // 每个位置都落下雨滴 先往左滑 -> 如果一路滑走直到边界 改为往右滑
    //     //                     往右滑 -> 如果一路滑走直到边界 说明这个位置存不了雨水 记录一下 
    //     //                                  - > 如果滑到一个坑（坑的定义为 左右两边均有比他高的）把这个坑高度加一
    //     int n = height.size();
    //     vector<bool> isRainCanStored(n, true);
    //     int res = 0;
    //     for(int i = 0;i<n;i++){
    //         // 下落一滴雨水 模拟它的滑动是否进入坑 不进入则去下一个位置
    //         while(moveRain(height, i)){
    //             res++;
    //         }
    //     }
    //     return res;
    // }
};

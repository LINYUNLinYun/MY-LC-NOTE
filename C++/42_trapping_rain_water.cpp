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
    bool isButtom(vector<int>& height, int rainPosition){
        if(rainPosition == 0 || rainPosition == height.size()){
            return false;
        }
        int left =rainPosition;
        int right = rainPosition;
        bool left_ = false;
        bool right_ = false;
        while(left >= 0 && right <height.size()){
            if(height[left] == height[rainPosition]){
                left--;
            }else if(height[left] < height[rainPosition]){
                return false;
            }else{
                left_ = true;
            }

            if(height[right] == height[rainPosition]){
                right++;
            }else if(height[right] < height[rainPosition]){
                return false;
            }else{
                right_ = true;
            }
            if(left_ && right_){
                break;
            }
        }
        return left > 0 && right < height.size() - 1;
    }
    bool moveRain(vector<int>& height, int rainPosition){
        while(true){
            if(isButtom(height, rainPosition)){
                height[rainPosition]++;
                return true;
            }else{
                break;
            }
        }
        int i =rainPosition-1;
        while(i >=0){
            if(isButtom(height, i)){
                height[i]++;
                return true;
            }else{
                i--;
            }
        }
        i =rainPosition+1;
        while(i <height.size()){
            if(isButtom(height, i)){
                height[i]++;
                return true;
            }else{
                i++;
            }
        }
        return false;

    }
    int trap(vector<int>& height) {
        // 模拟重力势能
        // 每个位置都落下雨滴 先往左滑 -> 如果一路滑走直到边界 改为往右滑
        //                     往右滑 -> 如果一路滑走直到边界 说明这个位置存不了雨水 记录一下 
        //                                  - > 如果滑到一个坑（坑的定义为 左右两边均有比他高的）把这个坑高度加一
        int n = height.size();
        vector<bool> isRainCanStored(n, true);
        int res = 0;
        for(int i = 0;i<n;i++){
            // 下落一滴雨水 模拟它的滑动是否进入坑 不进入则去下一个位置
            while(moveRain(height, i)){
                res++;
            }
        }
        return res;
    }
};

#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int lenght = nums.size();
        vector<int> result(lenght);
        int left = 0, right = lenght - 1;
        while(left < right){
            int left_sqr = nums[left]*nums[left];
            int right_sqr = nums[right]*nums[right];
            if(left_sqr < right_sqr){
                result[--lenght] = right_sqr;
                right--;
            }
            else{
                result[--lenght] = left_sqr;
                left++;
            }
        }
        result[--lenght] = nums[left]*nums[left];

        return result;
    }
};


int main(void) {
    int arrs[] = {0,1,2,2,3,0,4,2};
    // arrs = {3,2,2,3};
    int val = 2;
    std::vector<int> nums(arrs,arrs + sizeof(arrs)/sizeof(int));
//   cout << "hello wrold" << endl;
    Solution s;
    // cout<< s.removeElement2(nums,val)<<endl;
    // cout<<nums.size()<<endl;
    return 0;
}


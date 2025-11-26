#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int left = 0, right = 0;
        int lenght = nums.size();
        while(right < lenght){
            if(nums[left] == val ){
                if(nums[right]!=val && right > left){
                    int temp = nums[left];
                    nums[left] = nums[right];
                    nums[right] = temp;
                }
                else{
                    right++;
                }
            }
            else{
                left++;
                if(left == lenght){
                    break;
                }
            }
        }
        // for(int i = 0; i < lenght; i++){
        //     // cout<<nums[i]<<endl;
        // }
        return left;
    }

    int removeElement2(vector<int>& nums, int val) {
        int left = 0, right = 0;
        int lenght = nums.size();
        right = lenght - 1;
        while(left <= right){
            if(nums[left] == val){
                nums[left] = nums[right];
                right--;
            }
            else{
                left++;
            }
        }
        return left;
    }
};


int main(void) {
    int arrs[] = {0,1,2,2,3,0,4,2};
    // arrs = {3,2,2,3};
    int val = 2;
    std::vector<int> nums(arrs,arrs + sizeof(arrs)/sizeof(int));
//   cout << "hello wrold" << endl;
    Solution s;
    cout<< s.removeElement2(nums,val)<<endl;
    // cout<<nums.size()<<endl;
    return 0;
}


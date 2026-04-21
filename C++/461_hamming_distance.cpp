#include <iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for(int i =0;i<31;i++){
            bool x_ = x & 0b01;
            bool y_ = y & 0b01;
            if(x_ != y_){
                count++;
            }
            x = x>>1;
            y = y>>1;
        }
        return count;
    }
};
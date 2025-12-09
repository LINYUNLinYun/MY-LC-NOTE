#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int table[1001] = {0};      //看似只初始化了一个数组，实则都初始化了
        // cout<<table[29];
        for(int n : nums1){
            table[n] = 1;
        }
        vector<int> result;
        for(int j : nums2){
            if(table[j] == 1){
                result.push_back(j);
                table[j] = 0;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    cout << "hello wrold" << endl;
    Solution s;
    vector<int> a;
    vector<int> b;
    s.intersection(a, b);
    return 0;
}


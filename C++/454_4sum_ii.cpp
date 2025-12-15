#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int,int> hashTable1;
        // unordered_map<int,int> hashTable2;       
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                hashTable1[nums1[i]+nums2[j]]++;
            }
        }
        int result = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(hashTable1.count(-nums3[i]-nums4[j])){
                    result+=hashTable1[-nums3[i]-nums4[j]];
                }
                // hashTable2[nums3[i]+nums4[j]]++;
            }
        }
        // for(auto p : hashTable1){
        //     if(hashTable2.count(-p.first)){
        //         result+=p.second*hashTable2[-p.first];
        //     }
        // }
        return result;
    }
};

int main(int argc, char const *argv[]) {
	cout << "hello wrold" << endl;
	return 0;
}


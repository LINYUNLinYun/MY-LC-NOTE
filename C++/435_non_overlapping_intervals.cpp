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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),[](const vector<int>& a, const vector<int>& b){
            if(a[0] < b[0]){
                return true;
            }
            if(a[0] == b[0]){
                return a[1] < b[1];
            }
            return false;
        });
        vector<vector<int>> nonOverlap;
        for(int i =0;i<intervals.size();i++){
            if(nonOverlap.empty()){
                nonOverlap.push_back(intervals[i]);
            }else{
                if(intervals[i][0] < nonOverlap.back()[1]){
                    // 重叠了 保留右界小的那个
                    if(intervals[i][1] > nonOverlap.back()[1]){
                        continue;
                    }
                    if(intervals[i][1] < nonOverlap.back()[1]){
                        nonOverlap.back()[0] = intervals[i][0];
                        nonOverlap.back()[1] = intervals[i][1];
                    }
                }
                else{
                    nonOverlap.push_back(intervals[i]);
                }
            }
        }

        return intervals.size() - nonOverlap.size();

    }
};


int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello world" << endl;
	return 0;
}


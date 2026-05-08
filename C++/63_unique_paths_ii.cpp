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
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> f(m, vector<int>(n,0));
        for(int i = 0;i<m;i++){
            if(obstacleGrid[i][0] == 1){
                break;
            }
            f[i][0] = 1;
        }
        for(int i = 0;i<n;i++){
            if(obstacleGrid[0][i] == 1){
                break;
            }
            f[0][i] = 1;
        }
        for(int i =1;i<m;i++){
            for(int j =1;j<n;j++){
                if(obstacleGrid[i][j] == 1){
                    continue;
                }
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return obstacleGrid.back().back() == 1? 0: f.back().back();
    }
};



int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello world" << endl;
	return 0;
}


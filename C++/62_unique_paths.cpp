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
    int uniquePaths2(int m, int n) {
        // 2*2 2
        // 3*2 2*3 3 
        // 2*4 = 1*4 + 2*3 = 4
        // 3*3 6
        // 4*3 6 + 4 =10
        if(m==1 || n==1){
            return 1;
        }
        return uniquePaths(m-1,n) + uniquePaths(m,n-1);

    }
    int uniquePaths(int m, int n) {
        // 2*2 2
        // 3*2 2*3 3 
        // 2*4 = 1*4 + 2*3 = 4
        // 3*3 6
        // 4*3 6 + 4 =10
        // 先建一个二维数组
        vector<vector<int>> f(m, vector<int>(n));
        for(int i = 0;i<m;i++){
            f[i][0] = 1;
        }
        for(int i = 0;i<n;i++){
            f[0][i] = 1;
        }
        for(int i =1;i<m;i++){
            for(int j =1;j<n;j++){
                f[i][j] = f[i-1][j] + f[i][j-1];
            }
        }
        return f.back().back();
    }
};



int main(int argc, char const *argv[]) {
	Solution s;
    cout<<s.uniquePaths(3,7);
	cout << "hello world" << endl;
	return 0;
}


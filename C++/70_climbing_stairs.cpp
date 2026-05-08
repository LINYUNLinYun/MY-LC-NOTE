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
    vector<vector<long long>> matrix_mul(vector<vector<long long>>& a,vector<vector<long long>>& b){
        //2
        vector<vector<long long>> res = {{0,0},{0,0}};    //I
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a.size();j++){
                res[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j];
            }
        }
        return res;
    } 
    vector<vector<long long>> matrix_pow(vector<vector<long long>> mat,int n){
        // if(n==1){return mat}
        //2
        vector<vector<long long>> res = {{1,0},{0,1}};    //I
        while(n>0){
            if(n&1){
                res = matrix_mul(mat,res);
            }
            n >>= 1;
            mat = matrix_mul(mat,mat);
        }
        return res;
    } 
    int climbStairs(int n) {
        // n num
        // 1 1
        // 2 1+1 2
        // 3 1+1+1 2+1 1+2
        // 4 1+1+1+1 2+1+1 1+2+1 1+1+2 2+2
        int n_2 = 2, n_1 = 1;
        if(n == 1){
            return n_1;
        }
        if(n == 2){
            return n_2;
        }
        vector<vector<long long>> M = {{1,1},{1,0}};    //I
        M = matrix_pow(M,n - 2);
        return M[0][0]*n_2 + M[0][1]*n_1;
        

    }
};



int main(int argc, char const *argv[]) {
	Solution s;
    cout<< s.climbStairs(35);
	cout << "hello world" << endl;
	return 0;
}


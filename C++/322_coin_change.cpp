#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm> 
#include <stack>
#include <queue>
#include <cmath>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end(),[](int a, int b){
            return a<b;
        });
        vector<int> f(amount+1,-1);
        f[0] = 0;
        for(int i =0;i<=amount;i++){
            bool is_change = false;
            int min_num = INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(coins[j] > i){
                    break;
                }
                if(f[i-coins[j]]!=-1){
                    min_num = min(min_num,f[i-coins[j]]);
                    is_change = true;
                }
            }
            if(is_change){
                f[i] = min_num+1;
            }
        }
        return f[amount];
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello world" << endl;
	return 0;
}


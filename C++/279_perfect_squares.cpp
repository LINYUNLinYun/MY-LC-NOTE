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
    int numSquares(int n) {
        // f（i）表示最少需要多少个数的平方来表示整数 i
        // 显然 f0 = 0 边界情况  f1 = 1
        vector<int> f(n+1,0);
        // 遍历i，对于每个i: 遍历所有的1<= j <= sqrt(i), 考虑f[i-j^2]，则fi = 1+f[j^2] 
        // 只需对所有可能的j^2 找到最小的fi
        for(int i = 1;i<=n;i++){
            int min_num = INT_MAX;
            for(int j = 1;j*j<=i;j++){
                min_num = min(min_num, f[i-j*j]);
            }
            f[i] = min_num+1;
        }
        return f[n];
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello world" << endl;
	return 0;
}


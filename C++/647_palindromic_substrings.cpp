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
    int isP(const string &s, int i, int j = -1){
        int res = 0;
        if(j != -1){
            while(i>=0 && j < s.size()){
                if(s[i] == s[j]){
                    res++;
                }else{
                    break;
                }
                i--;
                j++;
            }
        }else{
            j = 0;
            while(i-j>=0 && i+j < s.size()){
                if(s[i-j] == s[i+j]){
                    res++;
                }else{
                    break;
                }
                j++;
            }
        }
        return res;
    }
    int countSubstrings(string s) {
        // 总共2n-1个回文中心 n个基数中心 n-1个偶数中心
        int n = s.size();
        if(n<2){
            return 1;
        }
        int res = 1;
        int i = 1;
        pair<int,int> j = {0,1};    //保证奇数和偶数中心边界同步
        while(i<n){
            res+= isP(s,i);
            res+= isP(s,j.first,j.second);
            i++;
            j.first++;
            j.second++;
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello world" << endl;
	return 0;
}


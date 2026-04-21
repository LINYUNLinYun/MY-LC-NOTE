#include <iostream>
#include <vector>
#include <unordered_map>
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
    bool isPalindrome(string s){
        int n = s.size();
        bool res =true;
        for(int i = 0; i < n/2; i++){
            if(s[i]!=s[n-i-1]){
                res = false;
                break;
            }
        }
        return res;
    }
    void helper(string s, vector<string> path, vector<vector<string>> &res){
        if(s.size() == 1){
            path.push_back(s);
            res.push_back(path);
            return;
        }
        for(int i = 1;i<s.size();i++){
            string s_left = s.substr(0, i);
            string s_right = s.substr(i, s.size()-i);
            if(isPalindrome(s_left)){
                if(isPalindrome(s_right) && s_right.size()>1){
                    path.push_back(s_left);
                    path.push_back(s_right);
                    res.push_back(path);
                    path.pop_back();
                    path.pop_back();
                }
                path.push_back(s_left);
                helper(s_right, path, res);
                path.pop_back();
            }
            else{
                continue;
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.size() == 1){
            return {{s}};
        }
        if(isPalindrome(s)){
            res.push_back({s});
        }
        helper(s, {}, res);
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


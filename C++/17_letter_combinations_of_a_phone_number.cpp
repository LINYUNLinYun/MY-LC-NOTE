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
    void helper(string digits, string path, vector<string> &res){
        if(digits.size() == 0){
            res.push_back(path);
            return;
        }
        char ch = digits.back();
        digits.pop_back();
        if(ch == '2'){
            helper(digits, path + "a", res);
            helper(digits, path + "b", res);
            helper(digits, path + "c", res);
        }
        if(ch == '3'){
            helper(digits, path + "d", res);
            helper(digits, path + "e", res);
            helper(digits, path + "f", res);
        }
        if(ch == '4'){
            helper(digits, path + "g", res);
            helper(digits, path + "h", res);
            helper(digits, path + "i", res);
        }
        if(ch == '5'){
            helper(digits, path + "j", res);
            helper(digits, path + "k", res);
            helper(digits, path + "l", res);
        }
        if(ch == '6'){
            helper(digits, path + "m", res);
            helper(digits, path + "n", res);
            helper(digits, path + "o", res);
        }
        if(ch == '7'){
            helper(digits, path + "p", res);
            helper(digits, path + "q", res);
            helper(digits, path + "r", res);
            helper(digits, path + "s", res);
        }
        if(ch == '8'){
            helper(digits, path + "t", res);
            helper(digits, path + "u", res);
            helper(digits, path + "v", res);
            // helper(digits, path + "s", res);
        }
        if(ch == '9'){
            helper(digits, path + "w", res);
            helper(digits, path + "x", res);
            helper(digits, path + "y", res);
            helper(digits, path + "z", res);
        }
    }

    vector<string> letterCombinations(string digits) {
        reverse(digits.begin(), digits.end());
        vector<string> res;
        helper(digits, "", res);
        return res;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


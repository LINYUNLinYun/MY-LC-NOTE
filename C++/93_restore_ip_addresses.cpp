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
    void helper(string s, vector<int> path, vector<string> &res, int point_num){
        int n = s.size();
        if(point_num == 0){
            // 检查当前数字是否合法
            if(s.empty()){
                return;
            }else{
                int num = stoi(s);
                if(s.size() > 1 && s[0] == '0'){
                    return;
                }else{
                    if(num > 255 || num < 0){
                        return;
                    }else{
                        path.push_back(num);
                        string temp;
                        for(int i = 0; i < path.size();i++){
                            if(i!=0){
                                temp+='.';
                            }
                            temp+=to_string(path[i]);
                        }
                        res.push_back(temp);
                        return;
                    }
                }
            }
        }
        // 说明要用过少的点分配很长的数 失败
        if(n < point_num + 1 || n > 3 * (point_num + 1)){
            return;
        }
        int most = min(3, n);
        for(int i = 0;i<most;i++){
            // 对当前串的头进行一次分割
            string temp = s.substr(0,i+1);
            int temp_num = stoi(temp);
            if((temp.size() > 1 && temp[0] == '0') || temp_num > 255 || temp_num < 0){
                return;
            }else{
                path.push_back(temp_num);
                helper(s.substr(i+1,s.size()-i-1), path, res, point_num-1);
                path.pop_back();
            }
        }

    }
    vector<string> restoreIpAddresses(string s) {
        if(s.size() < 4 || s.size() > 12 ){
            return {};
        }
        vector<string> res;
        helper(s,{},res,3);
        return res;

    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


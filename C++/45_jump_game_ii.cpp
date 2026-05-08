#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r){}
};

class Solution {
public:

    int helper(vector<int>& distance, int pos, int bias = 0){
        for(int i = 0; i < pos; i++){
            if(distance[i] - bias<= 0){
                return i;
            }
        }
        return -1;
    }
    // 最小跳跃次数
    int jump(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        int n = nums.size();
        // 每个位置的元素 距离 尾部元素的最大距离[3,1,0] -> [-1,0,0] 小于等于0说明完全可达
        // 同理一个元素能不能可达 j 即distance_to_back[i] >= n - j -1
        vector<int> distance_to_back(n, 0);
        for(int i = 0;i < n;i++){
            distance_to_back[i] = n- nums[i] - i -1;
        }
        // int max_reach = 0;
        int step = 0;
        // 从尾部往头部寻找 先找到能到尾的最远的 这个就是最优解，因为它一定比后面的可达，第二它最远，所以是满足可达且最远的最优解
        int now_pos = n-1;
        while(now_pos >= 0){
            int max = helper(distance_to_back, now_pos, n-1 - now_pos);
            step++;
            if(max == 0){
                break;
            }
            now_pos = max;
        }
        return step;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	queue<int> q;
	
	stack<int> s;
	s.push(6);
	s.push(7);
	cout << s.top() << s.size();
	s.pop();
	cout<<s.top();
	cout << "hello wrold" << endl;
	return 0;
}




#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
#include <stack>
#include <queue>
using namespace std;

class Solution {
public:
    static bool cmp(pair<int, int>& m, pair<int, int>& n){
        return m.second > n.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 由于是top k 所以先构造个小顶堆
        // decltype 用于推导函数指针的类型
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> que(cmp);
        // 哈希表维护频数 
        unordered_map<int,int> map;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            map[nums[i]]++;
        }
        for(auto p : map){
            if( que.size() < k){
                que.emplace(p.first,p.second);
            }else{
                if(p.second > que.top().second){
                    que.pop();
                    que.emplace(p.first,p.second);
                }
            }
        }
        vector<int> res;
        while(!que.empty()){
            res.push_back(que.top().first);
            que.pop();
        }
        return res;
    }
};

// // 时间复杂度NlogN因为维护的最大堆元素极端情况为n个
// class Solution {
// public:
//     vector<int> topKFrequent(vector<int>& nums, int k) {
//         // 由于是top k 所以先构造个最大堆
//         priority_queue<pair<int, int>> que;
//         // 哈希表维护频数
//         unordered_map<int,int> map;
//         int n = nums.size();
//         for(int i = 0;i<n;i++){
//             map[nums[i]]++;
//         }
//         for(auto p : map){
//             // que.emplace(p.second, p.first);
//             que.push({p.second, p.first});
//         }
//         vector<int> res;
//         while(res.size()<k){
//             res.push_back(que.top().second);
//             que.pop();
//         }
//         return res;
//     }
// };

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


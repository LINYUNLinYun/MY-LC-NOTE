#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int,bool> hashTable;
    vector<int> get_single_num(int n){
        vector<int> result;
        while(n != 0){
            result.push_back(n%10);
            n /= 10;
        }
        return result;
    }

    int get_sum(const vector<int>& n_i){
        int result=0;
        for(int i : n_i){
            result+=i*i;
        }
        return result;
    }

    bool isHappy(int n) {
        vector<int> history_num;
        int slow_num = n;
        int fast_num = n;
        while(true){
            slow_num = get_sum(get_single_num(slow_num));
            fast_num = get_sum(get_single_num(fast_num));
            fast_num = get_sum(get_single_num(fast_num));
            if(fast_num == 1){
                return true;
            }
            if(fast_num == slow_num){
                return false;
            }
        }
    }
    Solution(){
        // hashTable.insert({19,true});
        // hashTable.insert({82,true});
        // hashTable.insert({68,true});
    }
};

int main(int argc, char const *argv[]) {
	cout << "hello wrold" << endl;
    Solution s;
    auto a = s.isHappy(116);
    cout<<a<<endl;
    // for(auto ai:a){
    //     cout<<ai<<endl;
    // }
	return 0;
}


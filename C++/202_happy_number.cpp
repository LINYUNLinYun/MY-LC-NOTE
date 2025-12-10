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
            // cout<<n<<endl;
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
        if(hashTable.count(n)){
            return true;
        }
        else{
            vector<int> n_i = get_single_num(n);
            int new_n = get_sum(n_i);
        }
        vector
                
    }
    Solution(){
        hashTable.insert({19,true});
        hashTable.insert({82,true});
        hashTable.insert({68,true});
    }
};

int main(int argc, char const *argv[]) {
	cout << "hello wrold" << endl;
    Solution s;
    auto a = s.get_single_num(28);
    for(auto ai:a){
        cout<<ai<<endl;
    }
	return 0;
}


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hashTable1;
        int result = true;
        for(char c : magazine){
            hashTable1[c]++;
        }
        for(char c : ransomNote){
            if(hashTable1.count(c) && hashTable1[c]!=0){
                hashTable1[c]--;
            }
            else{
                result = false;
                break;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    s.canConstruct("asdawd","dawdawdaw");
    unordered_map<int, int> hashTable1;
    hashTable1[1]++;
    hashTable1[1]+=1;
    cout<<hashTable1[1]<<endl;
    hashTable1[1]--;
    cout<<hashTable1[1]<<endl;
    hashTable1.insert({2,0});
    hashTable1[1]--;
    for(auto p : hashTable1){
        cout<<p.first<<" "<<p.second<<endl;
    }
	cout << "hello wrold" << endl;
	return 0;
}


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        unordered_map<char, int> hashTable;
        for(char i : s){
            hashTable[i]++;
        }
        bool result = true;
        for(char j : t){
            if(hashTable[j] == 0){
                result = false;
                break;
            }else{
                hashTable[j]--;
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
  cout << "hello wrold" << endl;
  return 0;
}


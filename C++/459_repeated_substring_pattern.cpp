#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        bool isRepeated = false;
        for(int i =0;i<n/2;i++){
            string s1 = s.substr(0,i+1);
            string s2 = s.substr(i+1,i+1);
            if(s1 == s2){
                // break;
                int k = s1.size();
                if(n%k!=0){
                    continue;
                }
                isRepeated = true;
                for(int j = 0;j<n/k;j++){
                    string temp = s.substr(k*j, k);
                    // cout<<temp<<endl;
                    if(temp!=s1){
                        isRepeated = false;
                    }
                }
                if(isRepeated){
                    break;
                }

            }
            else{
                continue;
            }
        }      
        return isRepeated;
    }
};


int main(int argc, char const *argv[]) {
	Solution s;
    cout<<s.repeatedSubstringPattern("aabaaba")<<endl;
	cout << "hello wrold" << endl;
	return 0;
}


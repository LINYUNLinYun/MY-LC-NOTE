#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int k = needle.size();
        int result  = -1;
        if(k > n){
            return result;
        }
        for(int i =0; i < n - k + 1; i++){
            int isEuqle = true;
            for(int j = 0;j<k;j++){
                if(needle[j]!=haystack[i+j]){
                    isEuqle = false;
                    break;
                }
            }
            if(isEuqle){
                result = i;
                break;
            }
        }
        return result;
    }
};


int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


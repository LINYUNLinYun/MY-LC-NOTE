#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}



class Solution {
public:
    void reverseString(vector<char>& s) {
        char temp;
        int n = s.size();
        for(int i = 0; i<n/2;i++){
            temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
        }
    }
};
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;

class Solution {
public:
    void reverse_fromi2j(string& s,int i, int j){
        char temp;
        while(i<j){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;
            j--;
        }
    }
    string reverseStr(string s, int k) {
        int n = s.size();
        int count = 0;
        int reverse_head = 0;
        for(int i = 0;i<n;i++){
            count++;
            if(count%(2*k) == 0){
                reverse_fromi2j(s,reverse_head,reverse_head+k-1);
                reverse_head += 2*k;
                count%=2*k;
            }
        }
        if(count<k){
            //全部反转
            reverse_fromi2j(s,reverse_head,n-1);
        }
        else if(count>=k){
            reverse_fromi2j(s,reverse_head,reverse_head+k-1);
        }
        return s;
    }
};

int main(int argc, char const *argv[]) {
	// Solution s;
	cout << "hello wrold" << endl;
	return 0;
}


#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // bool isWordFront = false;
        string result;
        vector<string> temp;
        int n = s.size();
        int index = 0;
        while(index < n){
            cout<<index<<endl;
            if(s[index] == ' '){
                // continue;
                index++;
            }
            else{
                string word_temp;
                while(s[index]!=' ' && index < n){
                    word_temp+=s[index];
                    index++;
                }
                temp.push_back(word_temp);
                word_temp = "";
            }
        }
        int k = temp.size();
        cout<<k<<endl;
        for(int j = k-1;j>=0;j--){
            if(j==k-1){
                result+=temp[j];
            }
            else{
                result+=' ';
                result+=temp[j];
            }
        }
        return result;
    }
};

int main(int argc, char const *argv[]) {
	Solution s;
    cout<<s.reverseWords("sdaas asdada    awdawdawda  dawdawdaw ")<<endl;
	cout << "hello wrold" << endl;
	return 0;
}


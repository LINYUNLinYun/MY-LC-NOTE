#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm> 
using namespace std;

int main(int argc, char const *argv[]) {
	string s;
    cin>>s;
    string s_new;
    int n = s.size();
    if(n>0){
        for(int i = 0;i<n;i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                s_new+=s[i];
            }
            else{
                s_new+="number";
            }
        }
        cout<<s_new;
    }else{
        return -1;
    }
	return 0;
}


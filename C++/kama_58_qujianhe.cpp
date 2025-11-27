#include<iostream>
#include<vector>

using namespace std;

vector<int> prefixSum(const vector<int> nums, int n){
    vector<int> result(n + 1);
    result[0] = 0;
    for(int i = 1; i < n + 1; i++){
        result[i] = nums[i - 1] + result[i-1];
    }
    return result;
}

int main(){
    int n;
    cin>>n;
    if(n == 0){
        return 0;
    }
    vector<int> nums(n);
    for(int i = 0;i<n;i++){
        cin>>nums[i];
    }
    // for (int j = 0; j < n; j++) {
    //     cout << nums[j] <<endl;
    // }
    
    int left, right;
    vector<int> result;
    auto prefix = prefixSum(nums, n);
    // for(auto k : prefix){
    //     cout<<k<<endl;
    // }
    while(cin>>left && cin>>right){
        // cout<<left<<" "<<right<<endl;
        result.push_back(prefix[right] - prefix[left]);
    }

    for(auto k : result){
        cout<<k<<endl;
    }





    return 0;
}
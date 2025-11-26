#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> path(int n){
        vector<int> way;
        way.push_back(n);
        // 5 4 4 3 3 2 2 1 1 
        // 6 (5 4 3 2 1)*2
        for(int i = n - 1; i > 0; i--){
            way.push_back(i);
            way.push_back(i);
        }
        return way;
    }
    string direction = "r";

    string getDirection(string now_dire){
        string result;
        if(now_dire == "r"){
            result = "d";
        }
        else if(now_dire == "d"){
            result = "l";
        }
        else if(now_dire == "l"){
            result = "u";
        }
        else if(now_dire == "u"){
            result = "r";
        }
        return result;
    }

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        vector<int> way = path(n);
        int i = 0, j = 0;
        int count = 0;
        int now_dire_index = 0;
        for(int k = 1; k <= n*n; k++){
            result[i][j] = k;
            count++;
            if(way[now_dire_index] == count){
                now_dire_index++;
                direction = getDirection(direction);
                count = 0;
            }
            if(direction == "r"){
                j++;
            }
            else if(direction == "d"){
                i++;
            }
            else if(direction == "l"){
                j--;
            }
            else if(direction == "u"){
                i--;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    int n = 5;
    vector<vector<int>> result = sol.generateMatrix(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
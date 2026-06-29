#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<vector<int>> height;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y, vector<vector<int>>& arr) {
    int res = 0;
    if(arr[x][y] == 1){
        res+=1;
        arr[x][y] = 0;
    }else{
        return res;
    }
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
        }

        res += dfs(nx, ny, arr);
    }
    return res;
}

int main() {
    cin >> m >> n;

    height.resize(m, vector<int>(n));
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> height[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            vector<vector<int>> temp = height;
            temp[i][j] = 1;
            res = max(res, dfs(i,j,temp));
            
        }
    }

    cout<<res;
}
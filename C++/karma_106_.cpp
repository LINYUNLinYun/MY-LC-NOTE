#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<vector<int>> height;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y, vector<vector<int>>& arr,vector<vector<int>>& visited) {
    int res = 0;
    if(arr[x][y] == 0){
        visited[x][y] = 0;
        return 1;
    }
    if(visited[x][y] == 0){
        return 0;
    }
    if(visited[x][y] == 1){
        visited[x][y] = 0;
    }
    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            res+=1;
            continue;
        }
        
        res += dfs(nx, ny, arr,visited);
    }
    return res;
}

int main() {
    cin >> m >> n;
    
    height.resize(m, vector<int>(n));
    vector<vector<int>> temp = height;
    int res = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> height[i][j];
            temp[i][j] = 1;
        }
    }
    int center_x = m/2;
    int center_y = n/2;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(height[i][j] == 1){
                center_x = i;
                center_y = j;
            }
        }
    }
    res = dfs(center_x,center_y,height,temp);

    cout<<res;
}
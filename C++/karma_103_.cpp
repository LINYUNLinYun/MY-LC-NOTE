#include <iostream>
#include <vector>
using namespace std;

int m, n;
vector<vector<int>> height;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, vector<vector<bool>>& visited) {
    visited[x][y] = true;

    for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];

        if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
            continue;
        }

        if (visited[nx][ny]) {
            continue;
        }

        // 反向搜索：只能走向更高或等高的位置
        if (height[nx][ny] >= height[x][y]) {
            dfs(nx, ny, visited);
        }
    }
}

int main() {
    cin >> m >> n;

    height.resize(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> height[i][j];
        }
    }

    vector<vector<bool>> first(m, vector<bool>(n, false));
    vector<vector<bool>> second(m, vector<bool>(n, false));

    // 第一组边界：左边界和上边界
    // 在这里调用 dfs
    for (int i = 0; i < m; i++) {
        dfs(i,0,first);
    }
    for (int j = 0; j < n; j++) {
        dfs(0,j,first);
    }
    // 第二组边界：右边界和下边界
    // 在这里调用 dfs
    for (int i = 0; i < m; i++) {
        dfs(i,n-1,second);
    }
    for (int j = 0; j < n; j++) {
        dfs(m-1,j,second);
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (first[i][j] && second[i][j]) {
                cout << i << " " << j << '\n';
            }
        }
    }

    return 0;
}
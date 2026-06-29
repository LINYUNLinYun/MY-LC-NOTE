#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> reached_matrix;
int node_num, edge_num;

void set(int i, int j){
    reached_matrix[i-1][j-1] = 1;
    // 遍历所有能到达i的
    for(int k = 0;k<node_num;k++){
        if(reached_matrix[k][i-1] == 1){
            for(int n = 0;n<node_num;n++){
                reached_matrix[k][n] |= int(reached_matrix[j-1][n] == 1);
            }
        }
    }
}

bool get(int i, int j){
    return reached_matrix[i-1][j-1];
}

int main() {
    cin>>node_num>>edge_num;

    reached_matrix.resize(node_num,vector<int>(node_num,0));
    for(int i = 0;i<node_num;i++){
        reached_matrix[i][i] = 1;
    }
    int a , b;
    for(int i = 0;i<edge_num;i++){
        cin>>a>>b;
        set(a,b);
    }
    for(int i = 0;i<node_num;i++){
        if(reached_matrix[0][i]!=1){
            cout<<-1;
            return 0;
        }
    }
    cout<<1;

}
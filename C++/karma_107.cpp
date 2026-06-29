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


vector<int> parents;
//并查集查找
int find(int x){
    if(x == parents[x]){
        return x;
    }
    // 递归查找并修改它的爹
    return parents[x] = find(parents[x]);
}

bool join(int a, int b){
    int root_a = find(a);
    int root_b = find(b);
    if(root_a == root_b){
        // 有一样的根节点 说明会形成一个环
        return false;
    }
    parents[root_a] = root_b;
    return true;
}

int main() {
    cin>>node_num>>edge_num;

    reached_matrix.resize(node_num,vector<int>(node_num,0));
    parents.resize(node_num+1);
    for(int i = 1;i<=node_num;i++){
        parents[i] = i;
    }
    for(int i = 0;i<node_num;i++){
        reached_matrix[i][i] = 1;
    }
    int a , b;
    for(int i = 0;i<edge_num;i++){
        cin>>a>>b;
        join(a,b);
        // set(a,b);
        // set(b,a);
    }
    cin>>a>>b;
    // cout<<get(a,b);
    cout<<int(find(parents[a]) == find(parents[b]));
    

}
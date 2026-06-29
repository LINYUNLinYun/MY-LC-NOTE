#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> reached_matrix;
int node_num, edge_num;




void set(int i, int j){
    reached_matrix[i][j] = 1;
    // 遍历所有能到达i的
    for(int k = 0;k<node_num;k++){
        if(reached_matrix[k][i] == 1){
            for(int n = 0;n<node_num;n++){
                reached_matrix[k][n] |= int(reached_matrix[j][n] == 1);
            }
        }
    }
}

void set_single_edge(int i, int j){
    reached_matrix[i][j] = 1;
    // 遍历所有能到达i的
    
}


int indegree(const vector<vector<int>> &reached_matrix,int i){
    int res = 0;
    for(int j = 0;j<node_num;j++){
        res+=int(reached_matrix[j][i]);
    }
    return res;
}

bool get(int i, int j){
    return reached_matrix[i][j];
}

int main() {
    cin>>node_num>>edge_num;

    reached_matrix.resize(node_num,vector<int>(node_num,0));
    int a , b;
    for(int i = 0;i<edge_num;i++){
        cin>>a>>b;
        set_single_edge(a,b);
    }
    // 寻找源头
    queue<int> que;
    vector<int> res;
    vector<int> in_degree(node_num);
    for(int i = 0;i<node_num;i++){
        in_degree[i] = indegree(reached_matrix, i);
        if(in_degree[i] == 0){
            que.push(i);
        }
    }
    while(!que.empty()){
        int front = que.front();
        que.pop();
        res.push_back(front);
        for(int i = 0;i<node_num;i++){
            if(reached_matrix[front][i] == 1){
                in_degree[i]-=1;
                // que.push()
                if(in_degree[i] == 0){
                    que.push(i);
                }
            }
        }
    }
    if(res.size() < node_num){
        cout<<-1;
        return 0;
    }
    for(int i = 0;i<node_num-1;i++){
        cout<<res[i]<<" ";
    }
    cout<<res.back()<<endl;

}
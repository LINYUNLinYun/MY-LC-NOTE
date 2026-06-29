#include <iostream>
#include <vector>
using namespace std;

int n;
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
    cin>> n;
    parents.resize(n+1);
    for(int i = 1;i<=n;i++){
        parents[i] = i;
    }
    int a, b;
    int last_a = 0,last_b = 0;
    while(cin >> a >> b){
        bool con = join(a,b);
        if(!con){
            last_a = a;
            last_b = b;
        }
    }
    cout<< last_a << " "<<last_b;
    return 0;

}
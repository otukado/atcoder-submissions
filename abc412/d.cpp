#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> G;
bool visited[8];

void dfs(int pos) {
    visited[pos] = true;
    for(int i=0; i < G[pos].size(); i++) {
        int nex = G[pos][i];
        if(visited[nex] == false) dfs(nex);
    }
    return;
}

int main() {
    int N,M,v,u;
    cin >> N >> M;
    G.resize(N, vector<int>());
    int dub = 0;
    for(int i=0; i<M; i++) {
        cin >> v >> u;
        v--;
        u--;
        bool can_pv = true;
        bool can_pu = true;
        for(int j=0; G[v].size(); j++) {
            if(G[v][j] == u) {
                can_pv = false;
                break;
            }
        }
        for(int j=0; G[u].size(); j++) {
            if(G[u][j] == v) {
                can_pu = false;
                break;
            }
        }
        if(can_pu && can_pv) {
            G[v].push_back(u);
            G[u].push_back(v);
        }else dub ++;
    }

    

    for(int i=0; i<N; i++) visited[i] = false;
    int counter = 0;



    for(int i=0; i<N; i++) {
        if(visited[i] == false) {
            dfs(i);
            counter ++;
        }
    }
}
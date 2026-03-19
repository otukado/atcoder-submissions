#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<bool> seen;
vector<bool> can;
vector<vector<int>> graph;

set<ll> S;
vector<ll> A;

void dfs(int v, bool already) {
    seen[v] = true;
    bool first_time = false;
    if(S.contains(A[v])) {
        already = true;
    } else {
        first_time = true;
        S.insert(A[v]);
    }
    if(already) can[v] = true;

    for(auto &next : graph[v]) {
        if(seen[next]) {continue;}
        dfs(next, already);
    }
    if(first_time) {
        S.erase(A[v]);
    }
}

int main() {
    int n;
    cin >> n;
    A.resize(n);
    graph.resize(n);
    seen.resize(n, false);
    can.resize(n, false);

    for(int i=0; i<n; ++i) {
        cin >> A[i];
    }

    for(int i=0; i<n-1; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(0, false);

    for(int i=0; i<n; ++i) {
        if(can[i]) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
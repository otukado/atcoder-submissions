#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    for(int t=0; t<T; ++t) {
        int n, m; cin >> n >> m;
        vector<vector<int>> graph(n);
        vector<string> S(n);
        for(int i=0; i<n; ++i) {
            graph[i].push_back(i);
        }
        for(int i=0; i<m; ++i) {
            int u, v; cin >> u >> v;
            --u; --v;
            graph[u].push_back(v); graph[v].push_back(u);
        }
        int w; cin >> w;
        vector<int> start;
        for(int i=0; i<n; ++i) {
            cin >> S[i];
            if(S[i][0] == 'o') start.push_back(i);
        }
        bool can = false;
        auto seen = vector(n, vector(w, false));
        auto finished = vector(n, vector(w, false));
        auto dfs = [&](auto self, int v, int d) -> void {
            seen[v][d] = true;
            int next_d = (d + 1 + w) % w;
            for(const auto & next_v : graph[v]) {
                if(seen[next_v][next_d] && !finished[next_v][next_d]) can = true;
                else if(S[next_v][next_d] == 'o' && !can && !seen[next_v][next_d]) {
                    self(self, next_v, next_d);
                }
            }
            finished[v][d] = true;
        };
        for(const auto & s : start) {
            dfs(dfs, s, 0);
            if(can) break;
        }
        if(can) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
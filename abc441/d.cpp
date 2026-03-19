#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int l;
    ll n, m, s, t;
    cin >> n >> m >> l >> s >> t;
    vector<vector<pair<ll, ll>>> graph(n);
    for(int i=0; i<m; ++i) {
        ll u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        graph[u].push_back({v, c});
    }

    vector<queue<pair<ll, ll>>> ques(l+1);
    ques[0].push({0, 0});

    for(int i=0; i<l; ++i) {
        while(ques[i].size() > 0) {
            auto [P, C] = ques[i].front();
            for(int j=0; j<graph[P].size(); ++j) {
                ques[i+1].push({graph[P][j].first, C + graph[P][j].second});
            }
            ques[i].pop();
        }
    }

    vector<bool> can(n, false);
    while(ques[l].size() > 0) {
        auto [P, C] = ques[l].front();
        if(!can[P] && s <= C && C <= t) {
            can[P] = true;
        }
        ques[l].pop();
    }
    for(int i=0; i<n; ++i) {
        if(can[i]) cout << i+1 << " ";
    }
    cout << '\n';
}
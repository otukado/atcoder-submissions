#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll INF = 1LL<<60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m, y; cin >> n >> m >> y;
    vector<vector<pair<ll, ll>>> path(n+1);
    for(int i=0; i<m; ++i) {
        ll u, v, t; cin >> u >> v >> t;
        path[u].push_back(make_pair(v, t));
        path[v].push_back(make_pair(u, t));
    }


    for(int i=1; i<=n; ++i) {
        ll x; cin >> x;
        path[i].push_back(make_pair(0, x));
        path[0].push_back(make_pair(i, x + y));
    }

    priority_queue<pair<ll, ll>, std::vector<pair<ll, ll>>, std::greater<pair<ll, ll>>> que;
    vector<ll> visited(n+1, INF);
    visited[1] = 0;
    que.push({0, 1});
    while(!que.empty()) {
        auto [cost, node] = que.top();
        que.pop();
        if(visited[node] < cost) continue;
        for(int i=0; i<(int) path[node].size(); ++i) {
            int next_node = path[node][i].first;
            ll next_cost = cost + path[node][i].second;
            if(next_cost < visited[next_node]) {
                visited[next_node] = next_cost;
                que.push({next_cost, next_node});
            }
        }
    }
    for(int i=2; i<=n; ++i) {
        cout << visited[i] << " ";
    }
    cout << '\n';
}
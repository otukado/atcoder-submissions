#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    auto G = vector<vector<int>>(n);
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        G[a].push_back(b);
    }

    set<int> S;
    S.insert(0);
    queue<int> que;
    que.push(0);

    while(!que.empty()) {
        auto q = que.front();
        que.pop();
        for(int i=0; i<(int) G[q].size(); ++i) {
            if(!S.contains(G[q][i])) {
                S.insert(G[q][i]);
                que.push(G[q][i]);
            }
        }
    }
    cout << S.size() << '\n';
}
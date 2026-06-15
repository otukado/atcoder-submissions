#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m; cin >> n >> k >> m;
    vector<pair<ll, ll>> g(n);
    for(int i=0; i<n; ++i) {
        ll c, v; cin >> c >> v;
        g[i] = make_pair(v, c);
    }
    sort(g.rbegin(), g.rend());

    ll ans = 0;
    set<ll> S;
    for(int i=0; i<n; ++i) {
        if(!S.contains(g[i].second)) {
            S.insert(g[i].second);
            ans += g[i].first;
            --m; --k;
        } else {
            if(k > m) {
                ans += g[i].first;
                --k;
            }
        }
        if(k == 0) break;
    }
    cout << ans << '\n';
}
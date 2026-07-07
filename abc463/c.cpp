#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll INF = 1LL<<60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<ll, ll>> taka(n);
    vector<ll> mx(n+1, 0);
    for(int i=0; i<n; ++i) {
        cin >> taka[i].second >> taka[i].first;
    }
    for(int i=n-1; i>=0; --i) {
        mx[i] = max(mx[i+1], taka[i].second);
    }
    
    ll q; cin >> q;
    for(int i=0; i<q; ++i) {
        ll t; cin >> t;
        auto it = upper_bound(taka.begin(), taka.end(), make_pair(t, INF)) - taka.begin();
        if(it == 0) cout << mx[0] << '\n';
        else {
            cout << mx[it] << '\n';
        }
    }
}
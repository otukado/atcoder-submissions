#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    map<ll, ll> m;
    ll ans = 0;
    for(int i=0; i<n; ++i) {
        ll a; cin >> a;
        ans += a;
        if(m.contains(a)) {
            m[a] += a;
        } else {
            m.insert(make_pair(a, a));
        }
    }
    vector<ll> sorted;
    for(auto it = m.begin(); it != m.end(); ++it) {
        sorted.push_back(it->second);
    }
    sort(sorted.rbegin(), sorted.rend());
    int c = sorted.size();
    for(int i=0; i<min(c, k); ++i) {
        ans -= sorted[i];
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i=0; i<t; ++i) {
        int n, w;
        cin >> n >> w;
        auto C = vector<ll>(2 * w, 0);
        for(int j=0; j<n; ++j) {
            ll c; cin >> c;
            C[j % (2 * w)] += c;
        }

        ll ans = 0;
        for(int j=0; j<w; ++j) {
            ans += C[j];
        }
        ll x = ans;
        for(int j=0; j<2*w; ++j) {
            x -= C[j];
            x += C[(w + j + 2*w) % (2*w)];
            ans = min(ans, x);
        }
        cout << ans << '\n';
    }
}
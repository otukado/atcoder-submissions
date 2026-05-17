#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

// constexpr ll MOD = 998244353;
using mint = atcoder::modint998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x1, x2, x3; cin >> x1 >> x2 >> x3;
    int m = x1 + x2 + x3;
    vector<mint> prev;
    prev.push_back(1);
    for(int i=1; i<=m; ++i) {
        prev.push_back(prev[i-1] * i);
    }
    auto nCr = [&](ll n, ll r) -> mint {
        mint res = prev[n] / prev[r] / prev[n-r];
        return res.val();
    };
    mint ans = 0;
    for(int i=1; i<=min(x1, x2); ++i) {
        ans += (mint) (nCr(x2+1, i) * nCr(x1-1, i-1)) * nCr(x2 + x3 - i, x3);
    }
    cout << ans.val() << '\n';
}
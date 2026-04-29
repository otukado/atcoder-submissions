#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    auto A = vector(n, 0);
    auto B = vector(m, 0);
    auto A_wa = vector(n+1, 0);
    for(int i=0; i<n; ++i) cin >> A[i];
    for(int i=0; i<m; ++i) cin >> B[i];
    sort(A.begin(), A.end());
    for(int i=0; i<n; ++i) A_wa[i+1] = (A_wa[i] + A[i] + MOD) % MOD;

    ll ans = 0;
    for(int i=0; i<m; ++i) {
        auto it = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
        ans = (ans + (B[i] * it - A_wa[it] + MOD) % MOD + (A_wa[n] - A_wa[it] - (n-it) * B[i] + MOD) % MOD + MOD) % MOD;
    }
    cout << ans << '\n';
}
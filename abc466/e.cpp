#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ll INF = 1ll<<60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<ll> A(n);
    vector<ll> B(n);
    for(int i=0; i<n; ++i) {
        cin >> A[i] >> B[i];
    }

    auto dp = vector(n, vector(k+1, vector(2, -INF)));

    dp[0][0][0] = A[0];
    dp[0][1][1] = B[0];
    for(int i=1; i<n; ++i) {
        dp[i][0][0] = dp[i-1][0][0] + A[i]; // iが表、左にk個のかたまり
        dp[i][1][1] = dp[i-1][1][1] + B[i];
    }

    for(int i=1; i<n; ++i) {
        for(int j=1; j<(int) dp[i].size(); ++j) {
            dp[i][j][0] = max(dp[i-1][j][0] + A[i], dp[i-1][j][1] + A[i]);
            dp[i][j][1] = max(dp[i-1][j][1] + B[i], dp[i-1][j-1][0] + B[i]);
        }
    }

    ll ans = 0;
    for(int i=0; i<=k; ++i) {
        ans = max(ans, max(dp[n-1][i][0], dp[n-1][i][1]));
    }
    cout << ans << '\n';
}
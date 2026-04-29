#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    auto ABC = vector(3, vector(n, 0));
    for(int i=0; i<3; ++i) {
        for(int j=0; j<n; ++j) {
            cin >> ABC[i][j];
        }
    }

    auto dp = vector (3, vector(n+1, 0LL));
    for(int i=0; i<n; ++i) {
        dp[0][i+1] = dp[0][i] + ABC[0][i];
    }
    for(int i=1; i<=2; ++i) {
        for(int j=i; j<n; ++j) {
            dp[i][j+1] = max(dp[i][j], dp[i-1][j]) + ABC[i][j];
        }
    }
    cout << dp[2][n] << '\n';
}
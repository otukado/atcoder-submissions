#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr int MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;
    int n = S.size();
    auto same = vector(n+1, 0);
    char c = ' ';
    for(int i=0; i<n; ++i) {
        same[i+1] = same[i];
        if(c == S[i]) same[i+1] ++;
        c = S[i];
    }
    int ans = 0;
    for(int i=1; i<=n; ++i) {
        int it = upper_bound(same.begin(), same.end(), same[i]) - same.begin() - i;
        ans = (ans + it + MOD) % MOD;
    }
    cout << ans << '\n';
}
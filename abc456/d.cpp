#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    int n = S.size();
    map<char, ll> mp = {{'a', 0}, {'b', 0}, {'c', 0}};
    ll sum = 0;
    auto v = vector(n, 0);
    for(int i=0; i<n; ++i) {
        v[i] = (sum - mp[S[i]] + MOD + 1) % MOD;
        sum = (sum + MOD + v[i]) % MOD;
        mp[S[i]] = (mp[S[i]] + v[i] + MOD) % MOD;
    }
    int ans = 0;
    for(int i=0; i<n; ++i) {
        ans = (ans + v[i] + MOD) % MOD;
    }
    cout << ans << '\n';
}
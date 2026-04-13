#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    string s, t;
    cin >> s >> t;
    ll n = (ll) s.length();
    ll m = (ll) t.length();
    vector<vector<int>> alp(26, vector<int>(n+1, 0));
    ll ans = (n + 1) * n / 2;

    for(int i=1; i<=n; ++i) {
        int a = s[i-1] - 'a';
        for(int j=0; j<26; ++j) {
            alp[j][i] = alp[j][i-1] + bool(a == j);
        }
    }

    for(int i=0; i<n; ++i) {
        int idx = i;
        bool can = true;
        for(int j=0; j<m; ++j) {
            int trg = t[j] - 'a';
            int x = alp[trg][idx];
            auto it = lower_bound(alp[trg].begin() + idx, alp[trg].end(), x+1);
            if(it == alp[trg].end()) {
                can = false;
                break;
            }
            idx = it - alp[trg].begin();
        }
        if(!can) break;
        ans -= n - idx + 1;
    }
    cout << ans << '\n';
    return 0;
}
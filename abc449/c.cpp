#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, l, r;
    string s;
    cin >> n >> l >> r;
    cin >> s;
    ll ans = 0;
    vector<vector<int>> alp(26, vector<int>(n+1, 0));
    for(int i=0; i<n; ++i) {
        alp[s[i] - 'a'][i+1] = 1;
    }
    for(int i=0; i<26; ++i) {
        for(int j=0; j<n; ++j) {
            alp[i][j+1] += alp[i][j];
        }
    }
    for(int i=0; i<n; ++i) {
        int idx = s[i] - 'a';
        ans += alp[idx][min(n, r+i+1)] - alp[idx][min(n, l+i)];
    }
    cout << ans << '\n';
}
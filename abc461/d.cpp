#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w, k; cin >> h >> w >> k;
    vector<vector<int>> S(h+1, vector<int>(w+1, 0));
    for(int i=1; i<=h; ++i) {
        string s; cin >> s;
        for(int j=0; j<w; ++j) {
            S[i][j+1] = s[j];
        }
    }
    for(int i=1; i<=h; ++i) {
        for(int j=1; j<=w; ++j) {
            S[i][j] += S[i-1][j] + S[i][j-1];
        }
    }
    ll ans = 0;
    for(int i=1; i<=h; ++i) {
        auto it = lower_bound(S[i].begin(), S[i].end(), k+1) - S[i].begin() - 1;
        if()
    }
}
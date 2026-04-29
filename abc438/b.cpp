#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    string s, t;
    cin >> n >> m;
    cin >> s >> t;

    int ans = 100000;
    for(int i=0; i<=n-m; ++i) {
        int a = 0;
        for(int j=0; j<m; ++j) {
            a += (10 + s[i+j] - t[j]) % 10;
        }
        ans = min(ans, a);
    }
    cout << ans << '\n';
}
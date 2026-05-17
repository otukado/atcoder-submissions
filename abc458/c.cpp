#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    int n = s.size();
    ll ans = 0;
    for(int i=0; i<n; ++i) {
        if(s[i] == 'C') {
            ans += min(i+1, n-i);
        }
    }
    cout << ans << '\n';
}
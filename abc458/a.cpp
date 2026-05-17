#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    int n;
    cin >> s >> n;
    string ans = "";
    for(int i=n; i<(int) s.size()-n; ++i) {
        ans += s[i];
    }
    cout << ans << '\n';
}
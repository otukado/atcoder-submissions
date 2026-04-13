#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;
    
    int idx = 0;
    while(idx < n && s[idx] == 'o') idx++;
    
    string ans = "";
    for(int i=idx; i<n; ++i) {
        ans += s[i];
    }
    cout << ans << '\n';
}
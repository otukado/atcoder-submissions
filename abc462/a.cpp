#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s; cin >> s;
    string ans = "";
    for(int i=0; i<s.size(); ++i) {
        if(s[i] >= '0' && s[i] <= '9') {
            ans += s[i];
        }
    }
    cout << ans << '\n';
}
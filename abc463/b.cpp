#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    char x; cin >> x;
    bool can = false;
    for(int i=0; i<n; ++i) {
        string s; cin >> s;
        if(s[x - 'A'] == 'o') can = true;
    }
    if(can) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
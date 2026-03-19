#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    cin >> n;

    int m = 0;
    vector<string> S(n);
    for(int i=0; i<n; ++i) {
        cin >> S[i];
        m = max(m, int (S[i].length()));
    }

    for(int i=0; i<n; ++i) {
        string ans;
        int x = (m - S[i].length()) / 2;
        ans = std::string(x, '.') + S[i] + std::string(x, '.');
        cout << ans << '\n';
    }
}
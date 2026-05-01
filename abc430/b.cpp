#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> S(n);
    for(int i=0; i<n; ++i) cin >> S[i];
    set<vector<string>> sq;
    for(int i=0; i<=n-m; ++i) {
        for(int j=0; j<=n-m; ++j) {
            vector<string> a;
            for(int k=0; k<m; ++k) {
                a.push_back(S[i+k].substr(j, m));
            }
            sq.insert(a);
        }
    }
    cout << sq.size() << '\n';
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<unordered_set<int>> R(n);
    vector<unordered_set<int>> C(n);
    for(int i=0; i<m; ++i) {
        int r, c; cin >> r >> c;
        --r; --c;

        for(auto it = R[r].begin(); it != R[r].end(); ++it) {
            C[*it].erase(r);
        }
        R[r].clear();
        for(auto it = C[c].begin(); it != C[c].end(); ++it) {
            R[*it].erase(c);
        }
        C[c].clear();

        R[r].insert(c);
        C[c].insert(r);
    }

    int ans = 0;
    for(int i=0; i<n; ++i) {
        ans += (int) C[i].size();
    }
    cout << ans << '\n';
}
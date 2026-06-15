#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, int>> P(n);
    for(int i=0; i<n; ++i) {
        int x, y; cin >> x >> y;
        P[i] = make_pair(x, y);
    }
    sort(P.begin(), P.end());
    int min_y = 1000000;
    int ans = 0;
    for(int i=0; i<n; ++i) {
        if(P[i].second < min_y) {
            ++ans;
            min_y = P[i].second;
        }
    }
    cout << ans << '\n';
}
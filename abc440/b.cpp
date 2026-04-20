#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    auto horses = vector<pair<int, int>>(n);

    for(int i=0; i<n; ++i) {
        int t; cin >> t;
        horses[i] = {t, i+1};
    }
    sort(horses.begin(), horses.end());
    for(int i=0; i<3; ++i) {
        cout << horses[i].second << ' ';
    }
    cout << '\n';
}
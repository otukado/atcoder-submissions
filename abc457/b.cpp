#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<vector<int>> A;
    for(int i=0; i<n; ++i) {
        int l; cin >> l;
        auto a = vector(l, 0);
        for(int j=0; j<l; ++j) cin >> a[j];
        A.push_back(a);
    }
    int x, y; cin >> x >> y; --x; --y;
    cout << A[x][y] << '\n';
}
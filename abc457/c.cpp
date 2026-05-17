#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k; cin >> n >> k;
    vector<vector<ll>> A;
    for(int i=0; i<n; ++i) {
        int l; cin >> l;
        auto a = vector(l, 0LL);
        for(int j=0; j<l; ++j) cin >> a[j];
        A.push_back(a);
    }
    auto C = vector(n, 0LL);
    for(int i=0; i<n; ++i) cin >> C[i];
    int ans = 0;
    for(int i=0; i<n; ++i) {
        int x = A[i].size();
        if(k <= x * C[i]) {
            ans = A[i][(k-1)%x];
            break;
        }
        k -= x * C[i];
    }
    cout << ans << '\n';
}
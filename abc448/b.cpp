#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> C(m);
    vector<int> A(n), B(n);
    for(int i=0; i<m; ++i) {
        cin >> C[i];
    }
    for(int i=0; i<n; ++i) {
        cin >> A[i] >> B[i];
    }
    ll ans = 0;
    for(int i=0; i<n; ++i){
        int x = A[i]-1;
        ans += min(C[x], B[i]);
        C[x] = max(0, C[x] - B[i]);
    }
    cout << ans << '\n';
}
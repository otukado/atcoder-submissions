#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    auto A = vector(n, 0LL);
    auto B = vector(m, 0LL);
    for(int i=0; i<n; ++i) cin >> A[i];
    for(int i=0; i<m; ++i) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int ans = 0;
    int idx = 0;
    for(int i=0; i<m; ++i) {
        while(idx <= n-1 && A[idx] * 2 < B[i]) {
            idx ++;
        }
        if(idx > n-1) break;
        if(A[idx] * 2 >= B[i]) ans ++;
        idx ++;
    }
    cout << ans << '\n';
}
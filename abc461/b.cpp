#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    auto A = vector(n, 0);
    auto B = vector(n, 0);
    for(int i=0; i<n; ++i) cin >> A[i], A[i]--;
    for(int i=0; i<n; ++i) cin >> B[i], B[i]--;

    int ans = 0;
    for(int i=0; i<n; ++i) {
        if(B[A[i]] == i) ans ++;
    }
    if(ans == n) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
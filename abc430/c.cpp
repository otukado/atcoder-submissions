#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    string S;
    cin >> S;
    auto A = vector(n+1, 0);
    auto B = vector(n+1, 0);
    for(int i=0; i<n; ++i) {
        if(S[i] == 'a') {
            A[i+1] = A[i] + 1;
            B[i+1] = B[i];
        } else {
            A[i+1] = A[i];
            B[i+1] = B[i] + 1;
        }
    }
    ll ans = 0;
    for(int i=0; i<n; ++i) {
        int na = A[i]; int nb = B[i];
        int it_A = lower_bound(A.begin(), A.end(), na + a) - A.begin();
        int it_B = lower_bound(B.begin(), B.end(), nb + b) - B.begin();
        ans += max(0, it_B - it_A);
    }
    cout << ans << '\n';
}
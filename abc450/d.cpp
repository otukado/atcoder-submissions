#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll k;
    cin >> n >> k;
    vector<ll> A(n);
    for(int i=0; i<n; ++i) {
        ll a;
        cin >> a;
        A[i] = (a + k) % k;
    }
    sort(A.begin(), A.end());

    ll ans = A[n-1] - A[0];
    for(int i=1; i<n; ++i) {
        ans = min(A[i-1] + k - A[i], ans);
    }

    cout << ans << '\n';
}
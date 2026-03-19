#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ll n, k, x;
    cin >> n >> k >> x;
    vector<ll> A(n);
    vector<ll> wa(n+1, 0);
    for(int i=0; i<n; ++i) cin >> A[i];
    sort(A.begin(), A.end());
    reverse(A.begin(), A.end());
    for(int i=n-k; i<n; ++i) wa[i+1] = wa[i] + A[i];
    if(wa.back() < x) cout << -1 << '\n';
    else {
        int num = lower_bound(wa.begin(), wa.end(), x) - wa.begin();
        cout << num << '\n';
    }
}
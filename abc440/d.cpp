#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr auto INF = 1L << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    auto A = vector<ll>(n+1);
    auto B = vector<ll>(n+1, 0);
    for(int i=1; i<=n; ++i) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    for(int i=1; i<=n; ++i) {
        B[i] = A[i] - i;
    }
    A.push_back(INF);
    B.push_back(INF);

    for(int i=0; i<q; ++i) {
        ll x, y;
        cin >> x >> y;
        auto A_idx = upper_bound(A.begin(), A.end(), x) - A.begin() - 1;
        ll a = B[A_idx] + x - A[A_idx];

        auto B_idx = lower_bound(B.begin() + A_idx, B.end(), a + y - bool(A[A_idx] != x)) - B.begin() - 1;
        ll ans = a + y - bool(A[A_idx] != x) - B[B_idx] + A[B_idx];
        cout << ans << '\n';
    }
}
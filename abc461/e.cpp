#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;

    atcoder::segtree<ll, [](ll a, ll b) { return a + b; }, []{ return 0; }> stR(q);
    atcoder::segtree<ll, [](ll a, ll b) { return a + b; }, []{ return 0; }> stC(q);
    vector<int> R(n, -1);
    vector<int> C(n, -1);

    for(int i=0; i<q; ++i) {
        stR.set(i, 0);
        stC.set(i, 0);
    }

    ll ans = 0;
    for(int i=0; i<q; ++i) {
        int t; cin >> t;
        if(t == 1) {
            int r; cin >> r; --r;
            if(R[r] == -1) {
                ans += n;
                R[r] = i;                
            }
            else {
                int last = R[r];
                stR.set(last, 0);
                ans += stC.prod(last, i);
                R[r] = i;
            }
            stR.set(i, 1);
        } else {
            int c; cin >> c; --c;
            if(C[c] == -1) {
                ans -= stR.prod(0, i);
                C[c] = i;
            } else {
                int last = C[c];
                stC.set(last, 0);
                ans -= stR.prod(last, i);
                C[c] = i;
            }
            stC.set(i, 1);
        }
        cout << ans << '\n';
    }
}
#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;

int main(){
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    segtree<ll, [](ll a, ll b) { return a + b; }, []{ return 0; }> segmentTreeSum(600001);
    segtree<ll, [](ll a, ll b) { return a + b; }, []{ return 0; }> segmentTreeNum(600001);

    for(int i=0; i<N; i++) {
        cin >> A[i];
        ll s = segmentTreeSum.get(A[i]);
        ll t = segmentTreeNum.get(A[i]);
        segmentTreeSum.set(A[i], s + A[i]);
        segmentTreeNum.set(A[i], t + 1);
    }

    for(int i=0; i<Q; i++) {
        int q;
        cin >> q;
        if(q == 1) {
            ll x, y;
            cin >> x >> y;
            x--;

            ll Sum_x = segmentTreeSum.get(A[x]);
            segmentTreeSum.set(A[x], Sum_x - A[x]);
            ll Sum_y = segmentTreeSum.get(y);
            segmentTreeSum.set(y, Sum_y + y);
            ll Num_x = segmentTreeNum.get(A[x]);
            segmentTreeNum.set(A[x], Num_x - 1);
            ll Num_y = segmentTreeNum.get(y);
            segmentTreeNum.set(y, Num_y + 1);

            A[x] = y;
        } else {
            ll l, r;
            cin >> l >> r;
            ll ans;

            if(l >= r) {
                ans = l * N;
            } else {
                ans = segmentTreeNum.prod(0, l) * l + segmentTreeSum.prod(l, r) + segmentTreeNum.prod(r, 600001) * r;
            }
            cout << ans << endl;
        }
    }
}
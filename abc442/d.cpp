#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int op(int a, int b) {
    return a + b;
}
int e() {
    return 0;
}

int main() {
    int n, q;
    cin >> n >> q;
    atcoder::segtree<int, op, e> seg(n);
    for(int i=0; i<n; ++i) {
        int a;
        cin >> a;
        seg.set(i, a);
    }
    for(int i=0; i<q; ++i) {
        int num;
        cin >> num;
        if(num == 1) {
            int x;
            cin >> x;
            --x;
            int x_0 = seg.get(x);
            int x_1 = seg.get(x+1);
            seg.set(x, x_1);
            seg.set(x+1, x_0);
        } else {
            int l, r;
            cin >> l >> r;
            --l;
            int ans = seg.prod(l, r);
            cout << ans << '\n';
        }
    }
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for(int i=0; i<t; ++i) {
        ll a, b, x, y; cin >> a >> b >> x >> y;
        x = abs(x); y = abs(y);

        vector<ll> mov = {min(a, 3*b), min(b, 3*a)}; // 奇数, 偶数の順 (xのとき)

        ll ans = 0;
        ans += min(x, y) * 2 * min(mov[0], mov[1]);
        if(x > y) {
            int z = x - y;
            ans += (mov[0] + mov[1]) * (z / 2);
            if(z % 2 == 1) ans += mov[0];
        } else {
            int z = y - x;
            ans += (mov[0] + mov[1]) * (z / 2);
            if(z % 2 == 1) ans += mov[1];
        }
        cout << ans << '\n';
    }
}
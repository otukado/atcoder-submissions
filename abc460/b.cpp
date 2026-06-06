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
        ll x1, y1, x2, y2, r1, r2; cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        ll d2 = (x1 - x2) * (x1-x2) + (y1 - y2) * (y1 - y2);

        if(d2 <= (r1 + r2) * (r1 + r2) && d2 >= (r1 - r2) * (r1 - r2)) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}
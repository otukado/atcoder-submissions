#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, l, r, a, b; cin >> x >> y >> l >> r >> a >> b;
    int cost = 0;
    for(int i=a; i<b; ++i) {
        if(l <= i && i < r) cost += x;
        else cost += y;
    }
    cout << cost << '\n';
}
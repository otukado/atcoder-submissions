#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int count_black(const int& f, const int& l) {
    if(l >= 0 && f >= 0) {
        return l/2 - (f-1)/2;
    }
    if(l < 0 && f < 0) {
        return (l+1)/2 - f/2;
    }
    else {
        return l/2 - f/2;
    }
}

int main() {
    int l, r, d, u;
    cin >> l >> r >> d >> u;
    ll ans = 0;
    int fir, last;
    if(r >= 0 && 0 >= l){
        ans += count_black(d, u);
        if(u >= 0 && d <= 0) ans ++;
        fir = 1;
        last = max(abs(l), abs(r));
    } else {
        fir = min(abs(l), abs(r));
        last = max(abs(l), abs(r));
    }
    for(int i=fir; i<=last; ++i) {
        ll line = 0;
        if(i % 2 == 1) {
            // 交互
            line += max(count_black(i, u), 0) + max(count_black(d, -i), 0);
        } else {
            // 交互
            line += max(count_black(i+1, u), 0) + max(count_black(d, -i-1), 0);
            // -i から i まで
            line += min(i, u) - max(-i, d) + 1;
        }
        if(l <= 0 && 0 <= r && i<=min(abs(l), abs(r))) {
            ans += 2 * line;
        } else {
            ans += line;
        }
    }

    std::cout << ans << '\n';
}
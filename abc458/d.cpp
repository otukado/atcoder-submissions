#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    multiset<int> S;

    ll x; int q; cin >> x >> q;
    S.insert(x);
    auto it = S.begin();
    for(int i=0; i<q; ++i) {
        ll a, b; cin >> a >> b;
        if(a > b) {
            ll c = a; a = b; b = c;
        }
        S.insert(a); S.insert(b);
        if(a == b) {
            if(*it <= a) it++;
            else it--;
        } else if (a >= *it) {
            it ++;
        } else if(b < *it) {
            it --;
        }
        cout << *it << '\n';
    }
}
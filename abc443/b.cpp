#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    ll c = 0;
    while(1) {
        ans += n + c;
        if(ans >= k) break;
        c++;
    }
    cout << c << '\n';
}
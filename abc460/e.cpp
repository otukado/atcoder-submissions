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
        ll n, m; cin >> n >> m;
        int digit = log10(m)+1;
        vector<ll> ten(digit+1, 1);
        for(int i=1; i<=digit; ++i) {
            ten[i] = (ten[i-1] * 10 - 1 + m) % m;
        }
        for(int j=1; j<=digit; ++j) {

        }
    }
}
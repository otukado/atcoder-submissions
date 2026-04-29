#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; ++i) {
        int n;
        cin >> n;
        auto v = vector(n, 0LL);
        ll sum = 0;
        for(int j=0; j<n; ++j) {
            ll w, p;
            cin >> w >> p;
            v[j] = w + p;
            sum += p;
        }
        sort(v.begin(), v.end());

        int idx = 0;
        while(sum - v[idx] >= 0) {
            sum -= v[idx];
            ++idx;
        }
        cout << idx << '\n';
    }
}
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
        ll X, Y, K; cin >> X >> Y >> K;
        vector<ll> x;
        vector<ll> y;
        while(X > 0) {
            x.push_back(X);
            X /= K;
        }
        x.push_back(0);
        while(Y > 0) {
            y.push_back(Y);
            Y /= K;
        }
        y.push_back(0);

        ll ans = 0;
        int x_idx = 0;
        int y_idx = 0;
        while(x[x_idx] != y[y_idx]) {
            if(x[x_idx] > y[y_idx]) {
                ++x_idx;
            } else {
                ++y_idx;
            }
            ++ ans;
        }
        cout << ans << '\n';
    }
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> L(n);
    for(int i=0; i<n; ++i) {
        cin >> L[i];
    }

    int ans = 0;
    for(int i=0; i<(1<<n); ++i) {
        ll x = 1;
        int sm_ans = 0;
        for(int j=0; j<n; ++j) {
            if(i & (1<<j)) {
                if(x <= 0) {
                    x += L[j];
                    if(x > 0) sm_ans ++;
                } else {
                    x += L[j];
                }
            } else {
                if(x > 0) {
                    x -= L[j];
                    if(x <= 0) sm_ans ++;
                } else {
                    x -= L[j];
                }
            }
        }
        ans = max(ans, sm_ans);
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    ll con = 1000009;
    int n, d; cin >> n >> d;
    vector<ll> time(con, 0);

    for(int i=0; i<n; ++i) {
        int s, t; cin >> s >> t;
        t -= d;
        if(s > t) continue;
        time[s] += 1;
        time[t+1] -= 1;
    }

    ll ans = 0;
    for(int i=1; i<(int) time.size(); ++i) {
        time[i] += time[i-1];
        if(time[i] >= 2) {
            ans += time[i] * (time[i] - 1) / 2;
        }
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        ll N, H;
        cin >> N >> H;
        bool can = true;
        vector<vector<ll>> q;
        for(int j=0; j<N; j++) {
            ll t, l, u;
            cin >> t >> l >> u;
            q.push_back({t, l, u});
        }

        vector<ll> now(3, 0);
        now[1] = H;
        now[2] = H;
        for(int j=0; j<N; j++) {
            ll t = q[j][0];
            ll l = q[j][1];
            ll u = q[j][2];
            ll time = t - now[0];
            if(now[1] - time > u || now[2] + time < l) {
                can = false;
                break;
            }
            now ={t, max(now[1] - time, l), min(now[2]+ time, u)};
        }
        if(can) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;
    vector<pair<ll, ll>> people;
    ll R_min = 1000000000;
    ll R_max = 0;
    ll C_min = 1000000000;
    ll C_max = 0;
    for(int i=0; i<N; i++) {
        ll R, C;
        cin >> R >> C;
        people.push_back({R, C});
        R_max = max(R_max, R);
        R_min = min(R_min, R);
        C_max = max(C_max, C);
        C_min = min(C_min, C);
    }


    ll ans = 0;
    for(int i=0; i<N; i++) {
        ans = max(ans, abs(people[i].first - (R_max + R_min) / 2));
        ans = max(ans, abs(people[i].second - (C_max + C_min) / 2));
    }
    cout << ans << endl;
}
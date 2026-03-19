#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool through(ll o_x, ll o_y, ll e_x, ll e_y) {
    if(o_x == o_y && e_x == e_y && ((o_x < 0 && e_x >= 0) || (o_x > 0 && e_x <= 0))) return true;
    else if(o_x == -o_y && e_x == -e_y && ((o_x < 0 && e_x >= 0) || (o_x > 0 && e_x <= 0))) return true;
    else if(o_x == 0 && e_x == 0 && ((o_y < 0 && e_y >= 0) || (o_y > 0 && e_y <= 0)) && o_y % 2 == 0) return true;
    else if(o_y == 0 && e_y == 0 && ((o_x < 0 && e_x >= 0) || (o_x > 0 && e_x <= 0)) && o_x % 2 == 0) return true;
    else return false;
};


int main() {
    pair<ll, ll> Taka;
    pair<ll, ll> Aoki;
    cin >> Taka.first >> Taka.second >> Aoki.first >> Aoki.second;
    ll N, M, L;
    cin >> N >> M >> L;

    vector<pair<char, ll>> S;
    vector<pair<char, ll>> T;
    for(int i=0; i<M; i++) {
        char c;
        ll l;
        cin >> c >> l;
        if(c == 'D') c = 'U';
        else if(c == 'U') c = 'D';
        else if(c == 'L') c = 'R';
        else if(c == 'R') c = 'L';
        S.push_back({c, l});
    }
    for(int i=0; i<L; i++) {
        char c;
        ll l;
        cin >> c >> l;
        T.push_back({c, l});
    }

    vector<vector<pair<char, ll>>> ST;
    pair<ll, ll> current_T = {0, T[0].second};
    for(int i=0; i<M; i++) {
        pair<ll, ll> current_S = {i, S[i].second};
        ll T_index = current_T.first;
        ll S_index = current_S.first;
        ll T_length = current_T.second;
        ll S_length = current_S.second;
        while(S_length > 0) {
            if(S_length > T_length) {
                ST.push_back({{S[S_index].first, T_length}, {T[T_index].first, T_length}});
                S_length -= T_length;
                T_length = 0;
            } else {
                ST.push_back({{S[S_index].first, S_length}, {T[T_index].first, S_length}});
                T_length -= S_length;
                S_length = 0;
            }
            
            if(T_length == 0 && T_index + 1 < L) {
                T_index += 1;
                T_length = T[T_index].second;
            }
        }
        current_S = {S_index, S_length};
        current_T = {T_index, T_length};
    }

    pair<ll, ll> now_position = {Aoki.first - Taka.first, Aoki.second - Taka.second};
    pair<ll, ll> new_position = now_position;
    ll ans = 0;

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    for(int i=0; i<ST.size(); i++) {
        for(int j=0; j<2; j++) {
            char c = ST[i][j].first;
            int n;
            if(c == 'R') n = 0;
            else if (c == 'D') n = 1;
            else if (c == 'L') n = 2;
            else if(c == 'U') n = 3;
            ll b = ST[i][j].second;
            new_position = {new_position.first + b * dy[n], new_position.second + b * dx[n]};
        }
        ll o_x = now_position.second;
        ll o_y = now_position.first;
        ll e_x = new_position.second;
        ll e_y = new_position.first;
        ll b = ST[i][0].second;
        if(o_x == 0 && e_x == 0 && o_y == 0 && e_y == 0) ans += b;
        else if(through(o_x, o_y, e_x, e_y)) ans += 1;
        now_position = new_position;
    }
    cout << ans << endl;
}
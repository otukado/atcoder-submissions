#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr int INF = 1<<30;

bool yes (int s, int t, pair<int, int> S, pair<int, int> T) {
    if(S.first + 1 < T.first) return false;
    if(S.second == T.second) return false;
    if(S.first > t || T.first < s) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<vector<pair<int, int>>> S(n);
    vector<vector<pair<int, int>>> T(n);
    for(int i=0; i<m; ++i) {
        int l, r; cin >> l >> r; --l; --r;
        S[l].push_back(make_pair(r, i));
        T[r].push_back(make_pair(l, i));
    }
    for(int i=0; i<n; ++i) {
        sort(S[i].begin(), S[i].end());
        sort(T[i].begin(), T[i].end());
    }
    int q; cin >> q;

    vector<int> ds = {0, 0, -1, -1};
    vector<int> dt = {0, 1, 0, 1};
    for(int i=0; i<q; ++i) {
        int s, t; cin >> s >> t; --s; --t;
        bool can = false;
        const auto& ss = S[s]; const auto& tt = T[t];
        int s_pos = upper_bound(ss.begin(), ss.end(), make_pair(t, INF)) - ss.begin();
        if(s_pos != 0) s_pos --;
        int t_pos = lower_bound(tt.begin(), tt.end(),make_pair(s, -INF)) - tt.begin();
        for(int j=0; j<4; ++j) {
            int ns = s_pos + ds[j];
            int nt = t_pos + dt[j];
            if(ns >= 0 && ns < (int) ss.size() && nt >= 0 && nt < (int) tt.size()) {
                if(yes(s, t, ss[ns], tt[nt])) {
                    can = true;
                }
            }
        }
        if(can) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
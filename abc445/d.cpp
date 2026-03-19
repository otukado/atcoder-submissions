#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

struct rectangle {
    int id;
    ll height;
    ll width;
};

int main() {
    ll H, W, N;
    cin >> H >> W >> N;

    multimap<ll, rectangle> rec_h;
    multimap<ll, rectangle> rec_w;
    vector<pair<ll, ll>> ans(N, {0, 0});
    pair<ll, ll> top_left = {0, 0};

    for(int i=0; i<N; ++i) {
        ll h, w;
        cin >> h >> w;
        rectangle r = {i, h, w};
        rec_h.insert(make_pair(h, r));
        rec_w.insert(make_pair(w, r));
    }

    int counter = 0;
    while(counter < N){
        cout << counter << '\n';
        ll cur_h = H - top_left.first;
        ll cur_w = W - top_left.second;

        auto ret_h = rec_h.equal_range(cur_h);
        auto ret_w = rec_w.equal_range(cur_w);

        for(auto it = ret_h.first; it != ret_h.second; it++) {
            auto r = it->second;
            if(ans[r.id] == pair<ll,ll>{0LL, 0LL}) {
                ans[r.id] = {top_left.first + 1, top_left.second + 1};
                top_left.second += r.width;
                ++ counter;
            }
        }
        for(auto it = ret_w.first; it != ret_w.second; ++it) {
            auto r = it->second;
            if(ans[r.id] == make_pair(0LL, 0LL)) {
                ans[r.id] = {top_left.first + 1, top_left.second + 1};
                top_left.first += r.height;
                ++ counter;
            }
        }
    }

    for(int i=0; i<N; ++i) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    map<int, int> mp;
    vector<int> vec(n, 0);
    int min = 0;
    for(int i=0; i<n; ++i) {
        mp.insert(make_pair(i, 0));
    }
    for(int i=0; i<q; ++i) {
        int type; cin >> type;
        if(type == 1) {
            int x; cin >> x; --x;
            int tag = mp[x];
            mp[x] += 1;
            auto it = upper_bound(vec.begin(), vec.end(), tag) - 1 - vec.begin();
            vec[it] ++;
            auto m = lower_bound(vec.begin(), vec.end(), min + 1);
            if(m == vec.begin()) min ++;
        } else {
            int y; cin >> y;
            auto it = vec.end() - lower_bound(vec.begin(), vec.end(), y + min);
            cout <<  it << '\n';
        }
    }
}
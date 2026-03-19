#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main() {
    ll N, M;
    cin >> N >> M;
    set<pair<ll, ll>> block;
    int ans = 0;

    for(int i=0; i<M; i++) {
        ll r, c;
        cin >> r >> c;
        if(!block.contains({r-1, c-1}) && !block.contains({r-1, c}) && !block.contains({r-1, c+1}) && !block.contains({r, c-1}) && !block.contains({r, c}) && !block.contains({r, c+1}) && !block.contains({r+1, c-1}) && !block.contains({r+1, c}) && !block.contains({r+1, c+1})) {
            block.insert({r, c});
            ans += 1;
        }
    }
    cout << ans << endl;
}
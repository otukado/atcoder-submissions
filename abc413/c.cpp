#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int Q;
    cin >> Q;
    deque<vector<ll>> vec;

    for(int j=0; j<Q; j++) {
        int n;
        cin >> n;
        if(n == 1) {
            ll c, x;
            cin >> c >> x;
            vec.push_back({c, x});
        }else {
            ll k;
            ll ans = 0;
            cin >> k;

            while(1) {
                if(vec[0][0] > k) {
                    ans += k * vec[0][1];
                    vec[0][0] -= k;
                    break;
                }else {
                    k -= vec[0][0];
                    ans += vec[0][0] * vec[0][1];
                    vec.pop_front();
                    if(vec.size() == 0) break;
                }
            }
            cout << ans << endl;
        }
    }

}
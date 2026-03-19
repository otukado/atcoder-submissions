#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    int maxA = 0;
    for(int i=0; i<N; i++) {
        cin >> A[i];
        maxA = max(maxA, A[i]);
    }
    sort(A.begin(), A.end());

    vector<ll> wa(N+1);
    wa[0] = 0;
    for(int i=1; i<=N; i++) {
        wa[i] = wa[i-1] + A[i-1];
    }

    for(int i=0; i<Q; i++) {
        ll B;
        cin >> B;
        ll ans = 0;
        bool can = false;
        if(B <= maxA) {
            can = true;
            ll itr = lower_bound(A.begin(), A.end(), B-1) - A.begin();
            if(itr-1 >= 0) ans += wa[itr];
            ans += max(0LL, (B-1) * (N-itr));
        }
        if(can) cout << ans+1 << endl;
        else cout << -1 << endl;
    }
}
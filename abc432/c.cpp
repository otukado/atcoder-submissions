#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    ll X, Y;
    cin >> N >> X >> Y;
    vector<ll> A(N);
    ll d = gcd(X, Y);
    pair<ll, ll> xy = {Y / d, X / d};
    ll sa = xy.first - xy.second;

    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    bool can = true;
    ll ans = A[0];
    ll Min = A[0];

    for(int i=1; i<N; i++) {
        if((A[i] - A[0]) % sa != 0) {
            can = false;
            break;
        }
        ll n = Min - (A[i] - A[0]) / sa * xy.second;
        if(n < 0) {
            can = false;
            break;
        }
        ans += n;
    }
    
    if(can) cout << ans << endl;
    else cout << -1 << endl;
}
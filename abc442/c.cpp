#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<ll> doctor(n, n-1);
    for(int i=0; i<m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        --doctor[a]; --doctor[b];
    }
    for(int i=0; i<n; ++i) {
        ll x = doctor[i];
        ll ans = x * (x-1) * (x-2) / 6;
        cout << ans << " ";
    }
    cout << '\n';
}
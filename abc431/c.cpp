#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> head(n);
    vector<ll> body(m);
    for(int i=0; i<n; ++i) cin >> head[i];
    for(int i=0; i<m; ++i) cin >> body[i];
    sort(head.begin(), head.end());
    sort(body.begin(), body.end());
    bool can = true;
    for(int i=0; i<k; ++i) {
        if(head[i] > body[m - k + i]) {
            can = false;
            break;
        }
    }
    if(can) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
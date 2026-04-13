#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<ll>> C(n, vector<ll> (n, 0));
    for(int i=0; i<n; ++i) {
        for(int j=i+1; j<n; ++j) {
            cin >> C[i][j];
        }
    }

    bool can = false;
    for(int a=0; a<n; ++a) {
        for(int b=a; b<n; ++b) {
            for(int c=b; c<n; ++c) {
                if(C[a][c] > C[a][b] + C[b][c]) {
                    can = true;
                    break;
                }
            }
            if(can) break;
        }
        if(can) break;
    }
    if(can) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int x, n, q;
    cin >> x >> n;
    vector<int> W(n);
    for(int i=0; i<n; ++i) cin >> W[i];

    vector<bool> rob(n,false);
    int wei = x;
    cin >> q;
    for(int i=0; i<q; ++i) {
        int p;
        cin >> p;
        --p;
        if(rob[p]) {
            rob[p] = false;
            wei -= W[p];
        } else {
            rob[p] = true;
            wei += W[p];
        }
        cout << wei << '\n';
    }
}
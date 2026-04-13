#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int h, w, q;
    cin >> h >> w >> q;
    for(int i=0; i<q; ++i) {
        int num, e;
        cin >> num >> e;
        if(num == 1) {
            cout << e * w << '\n';
            h -= e;
        } else {
            cout << e * h << '\n';
            w -= e;
        }
    }
}
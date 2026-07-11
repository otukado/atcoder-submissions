#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    bool happy = false;
    for(int i=0; i<n; ++i) {
        int x; cin >> x;
        if(x >= 0) happy = true;
    }
    if(happy) cout << "No" << '\n';
    else cout << "Yes" << '\n';
}
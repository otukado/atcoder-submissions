#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, x;
    cin >> n >> x;
    for(int i=0; i<n; ++i) {
        int a;
        cin >> a;
        if(a < x) {
            x = a;
            cout << 1 << '\n';
        }else {
            cout << 0 << '\n';
        }
    }
}
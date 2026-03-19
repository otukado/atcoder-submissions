#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int p, q, x, y;
    cin >> p >> q >> x >> y;
    if(0 <= x - p && x - p <= 99 && 0 <= y - q && y - q <= 99) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}
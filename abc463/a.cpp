#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y; cin >> x >> y;

    int a = x / 16;
    if(a * 16 == x && a * 9 == y) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
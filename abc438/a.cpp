#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d, f;
    cin >> d >> f;

    int ans = 7 - (d - f) % 7;
    cout << ans << '\n';
}
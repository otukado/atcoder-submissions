#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int h, b;
    cin >> h >> b;
    int ans = 0;
    if(h > b) ans = h - b;
    cout << ans << '\n';
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    cin >> n;
    int ans = pow(2, n) - 2 * n;
    cout << ans << '\n';
}
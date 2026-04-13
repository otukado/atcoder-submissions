#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const double pi = 3.14159265358979;
int main() {
    int d;
    cin >> d;
    double ans = pi * d * d / 4;
    cout << fixed << setprecision(15) << ans << '\n';
}
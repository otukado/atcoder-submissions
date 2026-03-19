#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, m;
    cin >> n >> m;
    if(m * 2 - 1 <= n) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}
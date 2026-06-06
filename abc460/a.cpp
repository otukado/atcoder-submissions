#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    int counter = 0;
    while(m != 0) {
        m = n % m;
        ++counter;
    }
    cout << counter << '\n';
}
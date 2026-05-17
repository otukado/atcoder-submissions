#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    auto A = vector(n, 0);
    for(int i=0; i<n; ++i) cin >> A[i];
    int x; cin >> x; --x;
    cout << A[x] << '\n';
}
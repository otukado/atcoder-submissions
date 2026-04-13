#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i=n; i>0; --i) {
        cout << i;
        if(i != 1) cout << ",";
    }
    cout << '\n';
    return 0;
}
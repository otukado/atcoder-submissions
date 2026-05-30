#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "HelloWorld";
    int x; cin >> x; --x;
    string ans = "";
    for(int i=0; i<10; ++i) {
        if(x != i) ans += s[i];
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string ans = string(n-s.length(), 'o');
    ans += s;
    cout << ans << endl;
}
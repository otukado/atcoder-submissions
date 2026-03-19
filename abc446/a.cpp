#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    string S;
    cin >> S;
    string ans;
    S[0] += 'a' - 'A';
    ans = "Of" + S;
    cout << ans << '\n';
}
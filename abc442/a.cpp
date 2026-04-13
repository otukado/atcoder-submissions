#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    string s;
    cin >> s;
    int ans = 0;
    for(int i=0; i<int(s.size()); ++i) {
        if(s[i] == 'i' || s[i] == 'j') ans ++;
    }
    cout << ans << '\n';
}
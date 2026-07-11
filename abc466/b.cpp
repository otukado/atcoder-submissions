#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> ball(m, -1);
    for(int i=0; i<n; ++i) {
        int c, s; cin >> c >> s;
        --c;
        if(ball[c] < s) ball[c] = s;
    }
    for(int i=0; i<m; ++i) {
        cout << ball[i] << " ";
    }
    cout << '\n';
}
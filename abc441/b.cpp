#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, m, q;
    string s, t;
    cin >> n >> m >> s >> t >> q;
    set<char> taka, ao;
    for(int i=0; i<n; ++i) taka.insert(s[i]);
    for(int i=0; i<m; ++i) ao.insert(t[i]);

    for(int i=0; i<q; ++i) {
        string w;
        cin >> w;
        bool Ao = true;
        bool Taka = true;

        for(int j=0; j<w.length(); ++j) {
            if(!taka.contains(w[j])) Taka = false;
            if(!ao.contains(w[j])) Ao = false;
        }
        if(!Ao) cout << "Takahashi" << '\n';
        else if(!Taka) cout << "Aoki" << '\n';
        else cout << "Unknown" << '\n';
    }
}
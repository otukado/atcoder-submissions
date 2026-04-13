#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> AB(n);
    for(int i=0; i<n; ++i) {
        cin >> AB[i].first >> AB[i].second;
        AB[i].second --;
    }

    int m;
    cin >> m;
    vector<string> S(m);
    vector<vector<bool>> exist(n, vector<bool>(26, false));
    for(int i=0; i<m; ++i) {
        string s;
        cin >> s;
        S[i] = s;
        for(int j=0; j<n; ++j) {
            auto [l, a] = AB[j];
            if((int)s.length() == l) {
                exist[j][s[a] - 'a'] = true;
            }
        }
    }

    for(int i=0; i<m; ++i) {
        bool can = false;
        string s = S[i];
        if((int)s.length() == n) {
            can = true;
            for(int j=0; j<n; ++j) {
                if(!exist[j][s[j] - 'a']) {
                    can = false;
                    break;
                }
            }
        }
        if(can) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
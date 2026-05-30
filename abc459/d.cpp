#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for(int i=0; i<t; ++i) {
        string s; cin >> s;
        int n = s.size();
        vector<pair<int, char>> alp(26);
        for(int j=0; j<26; ++j) {
            alp[j] = make_pair(0, 'a' + j);
        }
        for(int j=0; j<n; ++j) {
            alp[s[j] - 'a'].first ++;
        }
        sort(alp.rbegin(), alp.rend());
        vector<vector<char>> group(alp[0].first);
        int m = alp[0].first;
        int idx= 0;
        int al_idx=0;
        while(true) {
            if(al_idx >= 26) break;
            if(alp[al_idx].first <= 0) al_idx++;
            else {
                group[idx].push_back(alp[al_idx].second);
                alp[al_idx].first--;
                idx = (idx + 1) % m;
            }
        }
        bool can = true;
        for(int j=1; j<(int) group.size(); ++j) {
            if(group[j-1].back() == group[j][0]) {
                can = false;
                break;
            }
        }
        if(can) {
            cout << "Yes" << '\n';
            for(int j=0; j<(int) group.size(); ++j) {
                for(int k=0; k<(int) group[j].size(); ++k) {
                    cout << group[j][k];                }
            }
            cout << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}
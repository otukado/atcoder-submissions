#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> alp = {{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    int n; cin >> n;
    string ans = "";
    vector<string> s(n);
    for(int i=0; i<n; ++i) {
        cin >> s[i];
        for(int j=0; j<(int) alp.size(); ++j) {
            for(int k=0; k<(int) alp[j].size(); ++k) {
                if(s[i][0] == alp[j][k]) {
                    ans += to_string(j + 2);
                }
            }
        }
    }
    cout << ans << '\n';
}
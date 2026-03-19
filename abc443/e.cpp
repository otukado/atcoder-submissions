#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; ++i) {
        int n, c;
        cin >> n >> c;
        vector<string> S;
        vector<vector<bool>> can(n, vector<bool>(n, false));
        vector<int> empty;
        for(int j=0; j<n; ++j) {
            can[j][c-1] = true;
        }

        for(int j=0; j<n; ++j) {
            string s;
            cin >> s;
            S.push_back(s);
        }

        for(int j=0; j<n; ++j) {
            int a = 0;
            for(int k=n-1; k>=0; --k) {
                if(S[j][k] == '#') {
                    a = k;
                    break;
                }
            }
            empty.push_back(a);
        }

        queue<vector<int, int>> que;
        que.push({})
    }
}
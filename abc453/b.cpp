#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, x;
    cin >> t >> x;
    vector<int> A(t+1);
    for(int i=0; i<=t; ++i) {
        cin >> A[i];
    }
    vector<pair<int, int>> ans;
    ans.push_back(make_pair(0, A[0]));
    for(int i=1; i<=t; ++i) {
        if(abs(A[i] - ans.back().second) >= x) {
            ans.push_back(make_pair(i, A[i]));
        }
    }
    for(int i=0; i<(int) ans.size(); ++i) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }
}
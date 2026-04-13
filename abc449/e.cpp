#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    vector<pair<int, int>> sorted(m, {0, 0});
    for(int i=0; i<m; ++i) sorted[i].second = i;
    for(int i=0; i<n; ++i) {
        int a;
        cin >> a;
        A[i] = a;
        sorted[a-1].first++;
    }
    sort(sorted.begin(), sorted.end());

    vector<ll> times(m+1);
    times[0] = n;
    for(int i=0; i<m; ++i) {
        int itr = lower_bound(sorted.begin(), sorted.end(), i) - sorted.begin();
        times[i+1] = times[i] + itr;
    }

    int q;
    cin >> q;
    vector<pair<ll, int>> X(q);
    vector<int> ans(q);
    for(int i=0; i<q; ++i) {
        ll x;
        cin >> x;
        X[i] = {x, i};
    }
    sort(X.begin(), X.end());

    for(int i=0; i<q; ++i) {
        
    }
}
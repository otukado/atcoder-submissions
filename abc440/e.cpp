#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x;
    cin >> n >> k >> x;
    
    auto A = vector<ll>(n);
    for(int i=0; i<n; ++i) cin >> A[i];

    sort(A.rbegin(), A.rend());

    unordered_set<set<int>> S;
    auto s = vector<ll>(n, 0);
    s[0] = n;

    priority_queue<pair<ll, vector<ll>>> que;
    vector<ll> ans;

    que.push(make_pair(A[0] * n, s));
    for(int i=0; i<x; ++i) {
        auto q = que.top();
        que.pop();
        ans.push_back(q.first);
        
    }
}
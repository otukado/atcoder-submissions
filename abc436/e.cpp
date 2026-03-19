#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<bool> seen;
vector<vector<int>> group;

void dfs(const vector<int>& permutation, int now, int x) {
    seen[now] = true;
    group[x].push_back(now);
    if(!seen[permutation[now]]) dfs(permutation, permutation[now], x);
}

int main() {
    int N;
    cin >> N;
    vector<int> P(N);
    for(int i=0; i<N; i++) {
        int n;
        cin >> n;
        n --;
        P[i] = n;
    }

    seen.assign(N, false);
    int count = 0;
    for(int i=0; i<N; i++) {
        if(!seen[i]) {
            group.push_back({});
            dfs(P, i, count);
            count ++;
        }
    }

    ll ans = 0;
    for(int i=0; i<count; i++) {
        ll x = group[i].size();
        ans += x * (x-1) / 2;
    }
    cout << ans << endl;
}
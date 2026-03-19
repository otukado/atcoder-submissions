#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int K, X, N;
vector<string> ans;
vector<string> S;

void dfs(int i, string s) {
    if(i == K) {
        ans.push_back(s);
        return;
    }
    for(int j=0; j<N; j++) {
        dfs(i+1, s + S[j]);
    }
}

int main() {
    cin >> N >> K >> X;
    S.resize(N);
    for(int i=0; i<N; i++) {
        cin >> S[i];
    }
    dfs(0, "");
    sort(ans.begin(), ans.end());
    cout << ans[X-1] << endl;
}
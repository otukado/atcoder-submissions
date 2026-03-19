#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    cin >> n;
    vector<int> W(n);
    vector<ll> H(n);
    vector<ll> B(n);
    int sum = 0;
    for(int i=0; i<n; ++i){
        cin >> W[i] >> H[i] >> B[i];
        sum += W[i];
    }
    
    vector<vector<ll>> dp(n+1, vector<ll>((sum/2) + 1, 0));
    for(int i=0; i<n; ++i) {
        for(int w=0; w<=(sum/2); ++w) {
            if(w < W[i]) dp[i+1][w] = dp[i][w] + B[i];
            else dp[i+1][w] = max(dp[i][w] + B[i], dp[i][w - W[i]] + H[i]);
        }
    }
    cout << dp[n].back() << '\n';
}
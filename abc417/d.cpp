#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<vector<ll>> pre(N,vector<ll>(3));
    vector<ll> b_sum(N+1, 0);
    for(int i=0; i<N; i++) {
        cin >> pre[i][0] >> pre[i][1] >> pre[i][2];
        b_sum[i+1] = b_sum[i] + pre[i][2];
    }

    vector<vector<int>> dp(N+1, vector<int>(1001, 0));
    for(int i=0; i<=1000; i++) {
        dp[N][i] = i;
    }
    for(int i=N-1; i>=0; i--) {
        for(int j=0; j<=1000; j++) {
            if(j <= pre[i][0]) {
                dp[i][j] = dp[i+1][j+pre[i][1]];
            }else{
                dp[i][j] = dp[i+1][max(0ll, j - pre[i][2])];
            }
        }
    }

    auto ans = [&dp, &N, &pre, &b_sum](int x) -> ll {
        if(x - b_sum[N] > 1000) {
            return x - b_sum[N];
        }else {
            int it = lower_bound(b_sum.begin(), b_sum.end(), x - 1000) - b_sum.begin();
            x = dp[it][x - b_sum[it]];
            return x;
        }
    };

    int Q;
    cin >> Q;
    for(int i=0; i<Q; i++) {
        int x;
        cin >> x;
        cout << ans(x) << endl;
    }
}
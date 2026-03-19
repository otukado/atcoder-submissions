#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll DIVISOR = 998244353;

int main() {
    string S;
    cin >> S;
    ll ans = 0;
    vector<vector<int>> nums(10, vector<int>(S.length(), 0));
    vector<ll> fact(S.length()+1);
    vector<ll> inv(S.length()+1);
    vector<ll> fact_inv(S.length()+1);

    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i<=S.length(); i++) {
        fact[i] = fact[i - 1] * i % DIVISOR;
        inv[i] = DIVISOR - inv[DIVISOR% i] * (DIVISOR / i) % DIVISOR;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % DIVISOR;
    }
    nums[S[0] - '0'][0] = 1;
    for(int i=1; i<S.size(); i++) {
        char c = S[i];
        nums[c - '0'][i] = 1;
        for(int j=0; j<10; j++) {
            nums[j][i] += nums[j][i-1];
        }
    }

    for(int i=0; i<S.size(); i++) {
        char c = S[i];
        if(c != '0') {
            int n = nums[c - '1'][i];
            int m = nums[c - '0'].end()[-1] - nums[c - '0'][i];
            if(n != 0) ans = (ans + fact[n + m] * fact_inv[m + 1] % DIVISOR * fact_inv[n - 1]) % DIVISOR;
        }
    }
    cout << ans << endl;
}
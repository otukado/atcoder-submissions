#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        int N;
        string S;
        cin >> N >> S;

        vector<bool> dp(1<<N, false);
        dp[0] = true;
        for(int j=0; j<(1<<N); j++) {
            if(dp[j]) {
                for(int k=0; k<N; k++) {
                    if(!(j & (1 << k))) {
                        int next = j + (1 << k);
                        if(S[next-1] == '0') dp[next] = true;
                    }
                    
                }
            }
        }
        if(dp[(1<<N) - 1]) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}
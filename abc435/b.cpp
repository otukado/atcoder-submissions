#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> wa(N+1);
    wa[0] = 0;
    for(int i=0; i<N; i++) {
        cin >> A[i];
        wa[i+1] = wa[i] + A[i];
    }

    ll ans = 0;
    for(int l=1; l<=N; l++) {
        for(int r=l+1; r<=N; r++) {
            ll sum = wa[r] - wa[l-1];
            bool can = true;
            for(int i=l-1; i<=r-1; i++) {
                if(sum % A[i] == 0) {
                    can = false;
                    break;
                }
            }
            if(can) {
                ans+=1;
            }
        }

    }
    cout << ans << endl;
}
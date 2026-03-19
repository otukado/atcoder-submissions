#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        int N;
        cin >> N;
        vector<ll>S;
        ll s;
        for(int j=0; j<N; j++) {
            cin >> s;
            S.push_back(s);
        }
        ll Sf = S[0];
        ll Se = S[S.size()-1];
        S.pop_back();
        S.erase(S.begin());
        ranges::sort(S);
        S.push_back(1000000009);

        int c=0;
        int nc = -1;
        int ans = 0;
        ll nS = Sf;
        bool can = true;
        while(2 * nS < Se){
            c = lower_bound(S.begin(), S.end(), nS * 2 + 1) - S.begin() -1;
            if (c <= nc) {
                can = false;
                break;
            }
            nS = S[c];
            nc = c;
            ans ++;
        }
        if(can) {
            cout << ans+2 << endl;
        }else {
            cout << -1 << endl;
        }
    }
}
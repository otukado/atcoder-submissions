#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main () {
    int N;
    ll K;
    cin >> N >> K;
    ll M = pow(2, N);
    ll base = K / M;
    ll remainder = K % M;
    vector<string> S;
    vector<ll> ans;

    for(int i=0; i<(1<<N); i++) {
        string s = "";
        for(int j=0; j<N; j++) {
            if(i&(1<<j)) s += "1";
            else s += "0";
        }
        S.push_back(s);
    }
    
    for(int i=0; i<(1<<N); i++) {
        ll value = stoll(S[i], nullptr ,2);
        if(value < remainder) ans.push_back(base + 1);
        else ans.push_back(base);
    }

    if(remainder == 0) cout << "0" << endl;
    else cout << "1" << endl;

    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
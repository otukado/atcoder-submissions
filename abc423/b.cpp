#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int count(vector<bool> ok){
    vector<bool> can(ok.size()+1, false);
    can[0] = true;
    can.back() = true;
    for(int i=0; i<ok.size(); i++) {
        if(!ok[i]) break;
        if(!can[i+1]) can[i+1] = true;
    }
    for(int i=ok.size(); i>0; i--) {
        if(!ok[i-1]) break;
        if(!can[i-1]) can[i-1] = true;
    }
    int ans = 0;
    for(int i=0; i<can.size(); i++) if(!can[i]) ans += 1;
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<bool> is_open(N,false);
    for(int i=0; i<N; i++) {
        int l;
        cin >> l;
        if(!l) is_open[i] = true;
    }

    int ans = count(is_open);
    cout << ans << endl;
}
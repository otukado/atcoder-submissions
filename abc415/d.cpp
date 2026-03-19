#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;


int main(){
    ull N, M;
    cin >> N >> M;
    vector<tuple<ull, ull, ull>> AB;

    for(int i=0; i<M; i++) {
        ull a, b;
        cin >> a >> b;
        AB.push_back({a - b, a, b});
    }

    sort(AB.begin(), AB.end());

    ull now = N;
    ull ans = 0;
    for(int i=0; i<M; i++) {
        if(now >= get<1>(AB[i])) {
            ull x = (now - get<1>(AB[i])) / get<0>(AB[i])+ 1;
            now -= get<0>(AB[i]) * x;
            ans += x;
        }
    }
    cout << ans << endl;
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    cin >> n;
    map<ll, int> M;
    int ans = 1;
    for(int i=0; i<n; ++i) {
        ll a;
        cin >> a;
        if(M.contains(a)) {
            if(M.contains(a-1)) {
                int m = M[a-1];
                int p = M[a];
                M.erase(a-1);
                M[a] = max(m+1, p);
                ans = max(ans, m+1);
            }
        } else {
            if(M.contains(a-1)) {
                int m = M[a-1];
                M.erase(a-1);
                M.insert(make_pair(a, m+1));
                ans = max(ans, m+1);
            } else {
                M.insert(make_pair(a, 1));
            }
        }
    }
    cout << ans << '\n';
}
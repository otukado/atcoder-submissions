#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; ++i) {
        int n, d;
        cin >> n >> d;
        vector<ll> A(n);
        vector<ll> A_wa(n+1, 0);
        vector<ll> B(n);
        vector<ll> B_wa(n+1, 0);
        for(int j=0; j<n; ++j) {
            cin >> A[j];
            A_wa[j+1] = A_wa[j] + A[j];
        }
        ll gone = 0;
        for(int j=0; j<n; ++j) {
            cin >> B[j];
            gone += B[j];
            if(j - d + 1 >= 0) {
                gone = max(A_wa[j - d + 1], gone);
            }
        }
        cout << A_wa.back() - gone << '\n';
    }
}
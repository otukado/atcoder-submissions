#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ll n, t;
    cin >> n >> t;
    vector<ll> A(n);
    for (int i=0; i<n; ++i) {
        cin >> A[i];
    }

    ll close = 0;
    ll when_open = 0;
    
    for (int i=0; i<n; ++i) {
        if(A[i] > when_open) {
            when_open = A[i] + 100;
            if(when_open < t) close += 100;
            else close += t - when_open + 100;
        }
    }
    cout << t - close << '\n';
}
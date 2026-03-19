#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    cin >> n;
    vector<ll> A(n);
    for(int i=0; i<n; ++i) {
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    bool flag1 = true;
    bool flag2 = true;
    ll candidate1 = A.back() + A[0];
    ll candidate2 = A.back();

    if(n % 2 == 1) flag1 = false;
    for(int i=0; i*2 < n; ++i) {
        if(A[i] + A[n - i - 1] != candidate1) flag1 = false;
    }
    
    int it = lower_bound(A.begin(), A.end(), candidate2) - A.begin();

    if(it % 2 == 1) flag2 = false;
    for(int i=0; i*2 < it; ++i) {
        if(A[i] + A[it - i - 1] != candidate2) flag2 = false;
    }

    if(flag2) cout << candidate2 << " ";
    if(flag1) cout << candidate1;
    cout << '\n';
}
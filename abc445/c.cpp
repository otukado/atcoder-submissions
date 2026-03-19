#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> ans(n);
    for(int i=0; i<n; ++i) {
        cin >> A[i];
    }

    for(int i=n-1; i>=0; --i) {
        if(A[i] == i + 1) {
            ans[i] = i;
        } else {
            ans[i] = ans[A[i] - 1];
        }
    }

    for(int i=0; i<n; ++i) {
        cout << ans[i] + 1 << ' ';
    }
    cout << '\n';
}
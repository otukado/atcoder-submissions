#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

vector<int> wa(2000000, 0);
vector<int> ans(2000000, 0);

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i=0; i<n; ++i) {
        cin >> A[i];
        wa[A[i]] += 1;
    }

    int m = 0;
    for(int i=(int) (wa.size()) - 2; i>0; --i) {
        wa[i] += wa[i+1];
    }

    for(int i=1; i<(int) (wa.size()); ++i) {
        wa[i] += wa[i-1] / 10;
        ans[i] = wa[i] % 10;
        if(wa[i] != 0) m = i;
    }

    for(int i=m; i>0; --i) {
        cout << ans[i];
    }
    cout << '\n';
}
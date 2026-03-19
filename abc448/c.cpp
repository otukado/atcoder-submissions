#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    vector<int> A_copy(n);
    for(int i=0; i<n; ++i) {
        cin >> A[i];
    }
    copy(A.begin(), A.end(), A_copy.begin());
    sort(A_copy.begin(), A_copy.end());

    vector<int> sml(6);
    copy(A_copy.begin(), A_copy.begin() + (min(6, int (A_copy.size()))), sml.begin());
    for(int i=0; i<q; ++i) {
        int k;
        cin >> k;
        vector<int> B(k);
        for(int j=0; j<k; ++j) {
            int b;
            cin >> b;
            B[j] = A[b-1];
        }
        sort(B.begin(), B.end());

        int ans;
        bool ex = false;
        for(int j=0; j<k; ++j) {
            if(sml[j] != B[j]) {
                ans = sml[j];
                ex = true;
                break;
            }
        }
        if(!ex) ans = sml[k];
        cout << ans << '\n';
    }
}
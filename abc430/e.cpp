#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for(int i=0; i<t; ++i) {
        string A, B;
        cin >> A >> B;
        const int n = A.size();
        const string& check = B + A + A;
        vector<int> Z = atcoder::z_algorithm(check);
        int ans = -1;
        for(int j=n; j<3 * n; ++j) {
            if(Z[j] >= n) {
                ans = j - n;
                break;
            }
        }
        cout << ans << '\n';
    }
}
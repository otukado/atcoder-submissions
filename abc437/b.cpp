#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int h, w, n;
    cin >> h >> w >> n;
    vector<vector<int>> A(h, vector<int>(w));
    vector<int> B(n);
    for(int i=0; i<h; ++i) {
        for(int j=0; j<w; ++j) {
            cin >> A[i][j];
        }
    }
    for(int i=0; i<n; ++i) {
        cin >> B[i];
    }

    int ans = 0;
    for(int i=0; i<h; i++) {
        int count = 0;
        for(int j=0; j<w; j++) {
            for(int k=0; k<n; k++) {
                if(A[i][j] == B[k]) count ++;
            }
        }
        ans = max(ans, count);
    }
    cout << ans << '\n';
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    auto A = vector(3, vector(6, 0));
    for(int i=0; i<3; ++i) {
        for(int j=0; j<6; ++j) {
            cin >> A[i][j];
        }
    }

    vector<vector<int>> B =
    {{4, 4, 5, 5, 6, 6},
     {5, 6, 4, 6, 4, 5},
     {6, 5, 6, 4, 5, 4}};

    int ac = 0;
    for(int i=0; i<6; ++i) {
        int a = 1;
        for(int j=0; j<3; ++j) {
            int b = 0;
            for(int k=0; k<6; ++k) {
                if(B[j][i] == A[j][k]) ++b;
            }
            a *= b;
        }
        ac += a;
    }
    double ans = ac / 216.0;

    cout << fixed << setprecision(15) << ans << '\n';
}
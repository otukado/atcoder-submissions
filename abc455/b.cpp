#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<string> S(h);
    for(int i=0; i<h; ++i) cin >> S[i];
    int ans = 0;
    for(int h_1 = 0; h_1 < h; ++h_1) {
        for(int h_2=h_1; h_2 < h; ++h_2) {
            for(int w_1=0; w_1<w; ++w_1) {
                for(int w_2=w_1; w_2<w; ++w_2) {
                    bool can = true;
                    for(int i=h_1; i<=h_2; ++i) {
                        for(int j=w_1; j<=w_2; ++j) {
                            if(S[i][j] != S[h_1 + h_2 - i][w_1 + w_2 - j]) {
                                can = false;
                                break;
                            }
                        }
                    }
                    if(can) ans ++;
                }
            }
        }
    }
    cout << ans << '\n';
}
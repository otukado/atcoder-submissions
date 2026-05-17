#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w; cin >> h >> w;
    auto X = vector(h, vector(w, 4));
    for(int i=0; i<h; ++i) {
        for(int j=0; j<w; ++j) {
            if(i == 0) X[i][j]--;
            if(i == h-1) X[i][j]--;
            if(j == 0) X[i][j] --;
            if(j == w-1) X[i][j] --;
            cout << X[i][j] << " ";
        }
        cout << '\n';
    }
}
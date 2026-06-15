#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n; cin >> n;
    vector<vector<int>> gift(n);
    for(int i=0; i<n; ++i) {
        int k; cin >> k;
        for(int j=0; j<k; ++j) {
            int A; cin >> A; --A;
            gift[A].push_back(i+1);
        }
    }

    for(int i=0; i<n; ++i) {
        int x = gift[i].size();
        cout << x << ' ';
        for(int j=0; j<x; ++j) {
            cout << gift[i][j] << ' ';
        }
        cout << '\n';
    }
}
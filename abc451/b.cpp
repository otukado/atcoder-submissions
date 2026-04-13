#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> AB(m, vector<int>(2, 0));
    for(int i=0; i<n; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        ++ AB[a][0];
        ++ AB[b][1];
    }
    for(int i=0; i<m; ++i) {
        cout << AB[i][1] - AB[i][0] << '\n';
    }
}
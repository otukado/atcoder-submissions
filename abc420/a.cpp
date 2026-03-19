#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int x, y;
    cin >> x >> y;
    int ans = (x + y) % 12;
    if(ans == 0) ans = 12;
    cout << ans << endl;

    int H, W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
}
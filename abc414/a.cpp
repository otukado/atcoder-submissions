#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, L, R;
    cin >> N >> L >> R;
    int ans = 0;
    for(int i=0; i<N; i++) {
        int x, y;
        cin >> x >> y;
        if(x <= L && y >= R) ans ++;
    }
    cout << ans << endl;
}
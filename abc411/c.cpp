#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    vector<bool> grid(N+2, false);
    int ans = 0;
    for(int i=0; i<Q; i++) {
        int a;
        cin >> a;
        if(grid[a]) grid[a] = false;
        else grid[a] = true;
        
        if(grid[a-1] == grid[a] && grid[a] == grid[a+1]) ans -= 1;
        else if(grid[a-1] != grid[a] && grid[a] != grid[a+1]) ans += 1;
        cout << ans << endl;
    }
}
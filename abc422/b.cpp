#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool is_ok(vector<vector<bool>> grid, int i, int j) {
    int count = 0;
    if(grid[i-1][j]) count += 1;
    if(grid[i+1][j]) count += 1;
    if(grid[i][j-1]) count += 1;
    if(grid[i][j+1]) count += 1;
    if(count == 2 || count == 4) return true;
    else return false;
};

int main () {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i=0; i<H; i++) {
        cin >> S[i];
    }
    
    vector<vector<bool>> black (H+2, vector<bool>(W+2, false));
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            if(S[i].at(j) == '#') black[i+1][j+1] = true;
        }
    }

    bool flag = true;
    for(int i=1; i<=H; i++) {
        for(int j=1; j<=W; j++) {
            if(black[i][j] && !is_ok(black, i, j)) {
                flag = false;
                break;
            }
        }
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
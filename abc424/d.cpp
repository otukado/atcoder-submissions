#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool is_square (int Y, int X, vector<vector<bool>> grid) {
    if(grid[Y][X] && grid[Y][X+1] && grid[Y+1][X] && grid[Y+1][X+1]) return true;
    else return false;
};

int how_many_blacks(int Y, int X, vector<vector<bool>> grid) {
    int count = 0;
    if(grid[Y][X]) count ++;
    if(grid[Y+1][X]) count ++;
    if(grid[Y][X+1]) count ++;
    if(grid[Y+1][X+1]) count ++;
    return count;
};

vector<vector<bool>> disband_blacks(int Y, int X, vector<vector<bool>> grid) {
    grid[Y][X] = false;
    grid[Y+1][X] = false;
    grid[Y][X+1] = false;
    grid[Y+1][X+1] = false;
    return grid;
};

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; i++) {
        int h, w;
        cin >> h >> w;
        vector<vector<bool>> black(h+2, vector<bool>(w+2, false));
        for(int j=1; j<=h; j++) {
            string s;
            cin >> s;
            for(int k=1; k<=w; k++) {
                if(s.at(k-1) == '#') black[j][k] = true;
            }
        }
        
        vector<vector<bool>> squares(h+2, vector<bool>(w+2, false));
        for(int j=1; j<=h; j++) {
            for(int k=1; k<=w; k++) {
                if(is_square(j, k, black)) squares[j][k] = true;
            }
        }

        int ans = 0;
        for(int k=1; k<=h; k++) {
            for(int j=1; j<=w; j++) {
                if(squares[j][k]) {
                    if(how_many_blacks(j, k, squares) > 1) {
                        squares = disband_blacks(j, k, squares);
                    }else {
                        if(how_many_blacks(j, k-1, squares) > 1) {
                            squares = disband_blacks(j, k-1, squares);
                        }else {
                            squares = disband_blacks(j, k, squares);
                        }
                    }
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
}
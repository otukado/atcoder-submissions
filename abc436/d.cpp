#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int H, W;
    cin >> H >> W;
    vector<vector<char>> grid (H, vector<char>(W));
    vector<vector<bool>> path(H, vector<bool>(W, false));
    queue<pair<int, int>> que;
    vector<vector<pair<int, int>>> alp(26);
    vector<bool> alp_path(26, false);
    vector<vector<int>> num(H, vector<int>(W, 0));
    for(int i=0; i<H; i++) {
        string S;
        cin >> S;
        for(int j=0; j<W; j++) {
            char c = S.at(j);
            grid[i][j] = c;
            if(c >= 'a' && c <= 'z') {
                alp[c - 'a'].push_back({i, j});
            }
        }
    }
    
    que.push({0, 0});
    path[0][0] = true;
    bool can = false;

    vector<int> dh = {1, 0, -1, 0};
    vector<int> dw = {0, 1, 0, -1};

    while(que.size() > 0) {
        pair<int, int> next = que.front();
        que.pop();
        char c = grid[next.first][next.second];
        if(c >= 'a' && c <= 'z') {
            if(!alp_path[c-'a']) {
                alp_path[c-'a'] = true;
                for(int i=0; i<alp[c-'a'].size(); i++) {
                int h = alp[c-'a'][i].first;
                int w = alp[c-'a'][i].second;
                if(!path[h][w]) {
                    path[h][w] = true;
                    que.push({h, w});
                    num[h][w] = num[next.first][next.second] + 1;
                }
            }
            }
        }

        for(int i=0; i<4; i++) {
            int h = next.first + dh[i];
            int w = next.second + dw[i];
            if(h >= 0 && h < H && w >= 0 && w < W) {
                if(!path[h][w] && grid[h][w] != '#') {
                    path[h][w] = true;
                    que.push({h, w});
                    num[h][w] = num[next.first][next.second] + 1;
                }
            }
        }

        if(next == pair<int, int> {H-1, W-1}) {
            can = true;
            break;
        }
    }
    if(can) cout << num[H-1][W-1] << endl;
    else cout << -1 << endl;

}
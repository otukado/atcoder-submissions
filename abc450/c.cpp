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
    vector<vector<bool>> S(h+2, vector<bool>(w+2, false));
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    for(int i=1; i<=h; ++i) {
        for(int j=1; j<=w; ++j) {
            char s;
            cin >> s;
            if(s == '.') S[i][j] = true;
        }
    }

    queue<pair<int, int>> que;
    for(int i=0; i<w; ++i) {
        if(S[1][i]) {
            S[1][i] = false;
            que.push(make_pair(1, i));
        }
        if(S[h][i]) {
            S[h][i] = false;
            que.push(make_pair(h, i));
        }
    }
    for(int i=0; i<h; ++i) {
        if(S[i][1]) {
            S[i][1] = false;
            que.push(make_pair(i, 1));
        }
        if(S[i][w]) {
            S[i][w] = false;
            que.push(make_pair(i, w));
        }
    }
    while(que.size() > 0) {
        auto [x, y] = que.front();
        que.pop();
        for(int i=0; i<4; ++i) {
            if(S[x + dx[i]][y + dy[i]]) {
                S[x + dx[i]][y + dy[i]] = false;
                que.push(make_pair(x + dx[i], y + dy[i]));
            }
        }
    }

    int ans = 0;
    for(int i=2; i<h; ++i) {
        for(int j=2; j<w; ++j) {
            if(S[i][j]) {
                ans ++;
                queue<pair<int, int>> bfs;
                S[i][j] = false;
                bfs.push(make_pair(i, j));
                while(bfs.size() > 0) {
                    auto [x, y] = bfs.front();
                    bfs.pop();
                    for(int k=0; k<4; ++k) {
                        if(S[x + dx[k]][y + dy[k]]) {
                            S[x + dx[k]][y + dy[k]] = false;
                            bfs.push(make_pair(x + dx[k], y + dy[k]));
                        }
                    }
                }
            }
        }
    }
    cout << ans << '\n';
}
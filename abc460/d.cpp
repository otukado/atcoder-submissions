#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w; cin >> h >> w;
    vector<string> S(h);
    auto black_grid = vector(h, vector(w, -1));
    auto white_grid = vector(h, vector(w, -1));
    auto around_white = vector(h, vector(w, false));
    for(int i=0; i<h; ++i) {
        cin >> S[i];
    }
    char f = S[0][0];
    bool can = true;
    for(int i=0; i<h; ++i) {
        for(int j=0; j<w; ++j) {
            if(S[i][j] != f) {
                can = false;
                break;
            }
        }
    }
    if(can) {
        for(int i=0; i<h; ++i) {
            for(int j=0; j<w; ++j) {
                cout << '.';
            }
            cout << '\n';
        }
        return 0;
    }
    queue<pair<pair<int, int>, int>> que;
    array<int, 8> dx = {1, 1, 1, 0, 0, -1, -1, -1};
    array<int, 8> dy = {1, 0, -1, 1, -1, 1, 0, -1};
    for(int i=0; i<h; ++i) {
        for(int j=0; j<w; ++j) {
            if(S[i][j] == '#') {
                black_grid[i][j] = -2;
                que.push(make_pair(make_pair(i, j), -2));
            }
        }
    }
    while(que.size() > 0) {
        auto [pir, num] = que.front();
        auto [p, q] = pir;
        que.pop();
        for(int i=0; i<8; ++i) {
            int np = p + dx[i]; int nq = q + dy[i];
            if(np >= 0 && np < h && nq >= 0 && nq < w && black_grid[np][nq] == -1) {
                if(num == -2) black_grid[np][nq] = 0;
                else black_grid[np][nq] = black_grid[p][q] + 1;
                que.push(make_pair(make_pair(np, nq), black_grid[np][nq]));
            }
        }
    }
    for(int i=0; i<h; ++i) {
        for(int j=0; j<w; ++j) {
            if(S[i][j] == '.') {
                white_grid[i][j] = -2;
                que.push(make_pair(make_pair(i, j), -2));
            }
        }
    }
    while(que.size() > 0) {
        auto [pir, num] = que.front();
        auto [p, q] = pir;
        que.pop();
        for(int i=0; i<8; ++i) {
            int np = p + dx[i]; int nq = q + dy[i];
            if(np >= 0 && np < h && nq >= 0 && nq < w && white_grid[np][nq] == -1) {
                if(num == -2) white_grid[np][nq] = 0;
                else white_grid[np][nq] = white_grid[p][q] + 1;
                que.push(make_pair(make_pair(np, nq), white_grid[np][nq]));
            }
        }
    }
    for(int i=0; i<h; ++i) {
        for(int j=0; j<w; ++j) {
            if(S[i][j] == '#') {
                if(white_grid[i][j] % 2 == 0) cout << '#';
                else cout << '.';
            }
            else if(black_grid[i][j] % 2 == 0) cout << '.';
            else cout << '#';
        }
        cout << '\n';
    }
}
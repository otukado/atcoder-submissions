#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int H, W;
    cin >> H >> W;
    int sh, sw;
    vector<vector<char>> A(H,vector<char>(W));
    for(int i=0; i<H; i++) {
        for(int j=0; j<W; j++) {
            cin >> A[i][j];
            if(A[i][j] == 'S') sh = i, sw = j;
        }
    }

    vector<vector<int>> dist_o(H, vector<int>(W, -1));
    vector<vector<int>> dist_u(H, vector<int>(W, -1));
    vector<int> dh = {-1, 1, 0, 0};
    vector<int> dw = {0, 0, -1, 1};
    deque<vector<int>> dq;

    dist_o[sh][sw] = 0;
    dq.push_back({sh, sw, 0});
    while(!dq.empty()) {
        int nh = dq.front()[0];
        int nw = dq.front()[1];
        int nd = dq.front()[2];
        dq.pop_front();
        for(int i=0; i<4; i++) {
            int next_h = nh + dh[i];
            int next_w = nw + dw[i];
            if(0 <= next_h && next_h < H && 0 <= next_w && next_w < W) {
                if(A[next_h][next_w] == 'G') {
                    if(nd == 0) {
                        cout << dist_o[nh][nw] + 1 << endl;
                        return 0;
                    }else {
                        cout << dist_u[nh][nw] + 1 << endl;
                        return 0;
                    }
                }
                if(A[next_h][next_w] == '.' || A[next_h][next_w] == 'S') {
                    if(nd == 0) {
                        if(dist_o[next_h][next_w] == -1) {
                            dist_o[next_h][next_w] = dist_o[nh][nw] + 1;
                            dq.push_back({next_h, next_w, nd});
                        }
                    }else {
                        if(dist_u[next_h][next_w] == -1) {
                            dist_u[next_h][next_w] = dist_u[nh][nw] + 1;
                            dq.push_back({next_h, next_w, nd});
                        }
                    }
                }
                if(A[next_h][next_w] == '?') {
                    if(nd == 0) {
                        if(dist_u[next_h][next_w] == -1) {
                            dist_u[next_h][next_w] = dist_o[nh][nw] + 1;
                            dq.push_back({next_h, next_w, 1});
                        }
                    }else {
                        if(dist_o[next_h][next_w] == -1) {
                            dist_o[next_h][next_w] = dist_u[nh][nw] + 1;
                            dq.push_back({next_h, next_w, 0});
                        }
                    }
                }
                if(A[next_h][next_w] == 'o') {
                    if(nd == 0) {
                        if(dist_o[next_h][next_w] == -1) {
                            dist_o[next_h][next_w] = dist_o[nh][nw] + 1;
                            dq.push_back({next_h, next_w, nd});
                        }
                    }
                }
                if(A[next_h][next_w] == 'x') {
                    if(nd == 1) {
                        if(dist_u[next_h][next_w] == -1) {
                            dist_u[next_h][next_w] = dist_u[nh][nw] + 1;
                            dq.push_back({next_h, next_w, nd});
                        }
                    }
                }
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
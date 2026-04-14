#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

struct coordinate {
    int x;
    int y;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;

    auto S = vector (h+2, vector (w+2, '#'));
    coordinate s_i_j, g_i_j;
    for(int i=0; i<h; ++i) {
        string s;
        cin >> s;
        for(int j=0; j<w; ++j) {
            S[i+1][j+1] = s[j];
            if(s[j] == 'S') s_i_j = {j+1, i+1};
            if(s[j] == 'G') g_i_j = {j+1, i+1};
        }
    }

    constexpr auto dx = array {1, 0, -1, 0};
    constexpr auto dy = array {0, 1, 0, -1};
    constexpr auto dir = array {'R', 'D', 'L', 'U'};

    auto que = queue<pair<int, coordinate>> ();
    auto seen = vector (h+2, vector (w+2, vector (4, false)));
    auto prev = vector (h+2, vector (w+2, vector (4, -1)));
    bool can = false;

    auto can_next = [&](int d, coordinate c){
        if(seen[c.y][c.x][d]) return false;
        if(S[c.y + dy[d]][c.x + dx[d]] == '#') return false;
        return true;
    };

    auto to_next = [&](int d, coordinate c, int pre) {
        if(can_next(d, c)) {
            que.emplace(d, coordinate{c.x + dx[d], c.y + dy[d]});
            seen[c.y][c.x][d] = true;
            prev[c.y + dy[d]][c.x + dx[d]][d] = pre;
        }
        return;
    };

    que.emplace(0, s_i_j);
    while(!que.empty()) {
        auto q = que.front();  que.pop();
        int d = q.first;
        auto [x, y] = q.second;

        if(S[y][x] == 'G') {
            can = true;
            break;
        }
        if(S[y][x] == 'S' || S[y][x] == '.') {
            for(int i=0; i<4; ++i) {
                to_next(i, q.second, d);
            }
        }
        if(S[y][x] == 'o') {
            to_next(d, q.second, d);
        }
        if(S[y][x] == 'x') {
            for(int i=0; i<4; ++i) {
                if(d != i) to_next(i, q.second, d);
            }
        }
    }

    auto[s_x, s_y] = s_i_j;
    auto[x, y] = g_i_j;
    vector<int> ans;
    for(int i=0; i<4; ++i) {
        if(prev[y][x][i] != -1) {
            ans.push_back(i);
            break;
        }
    }
    
    if(!can) {
        cout << "No" << '\n';
        return 0;
    }

    while(s_y != y || s_x != x) {
        int b = ans.back();
        if(prev[y][x][b] == -1) {
            break;
        }
        ans.push_back(prev[y][x][b]);
        y -= dy[b];
        x -= dx[b];
    }

    reverse(ans.begin(), ans.end());
    
    cout << "Yes" << '\n';
    for(int i=1; i<(int)ans.size(); ++i) {
        cout << dir[ans[i]];
    }
    cout << '\n';
}
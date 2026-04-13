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
    
    vector<vector<char>> S(h+2, vector<char>(w+2, '#'));
    pair<int, int> s_i_j, g_i_j;
    for(int i=0; i<h; ++i) {
        string s;
        cin >> s;
        for(int j=0; j<w; ++j) {
            S[i+1][j+1] = s[j];
            if(s[j] == 'S') s_i_j = make_pair(i+1, j+1);
            if(s[j] == 'G') g_i_j = make_pair(i+1, j+1);
        }
    }

    constexpr auto dx = array {1, 0, -1, 0};
    constexpr auto dy = array {0, 1, 0, -1};
    constexpr auto dir = array {'R', 'U', 'L', 'D'};

    auto que = queue<pair<int, coordinate>> (); 
    auto seen = vector (h+2, vector (w+2, vector (4, false)));
}
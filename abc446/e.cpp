#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int m, a, b;
    cin >> m >> a >> b;
    vector<vector<vector<pair<int, int>>>> S(m, vector<vector<pair<int, int>>>(m));
    for(int i=0; i<m; ++i) {
        for(int j=0; j<m; ++j) {
            int s_2 = (a * j + b * i + m) % m;
            S[j][s_2].push_back(make_pair(i, j));
        }
    }
    vector<vector<bool>> zero(m, vector<bool>(m, false));
    queue<pair<int, int>> que;
    int counter = 2 * m - 1;
    for(int i=0; i<m; ++i) {
        zero[0][i] = true;
        que.push(make_pair(0, i));
    }
    for(int i=1; i<m; ++i) {
        zero[i][0] = true;
        que.push(make_pair(i, 0));
    }

    while(que.size() > 0) {
        auto [x, y] = que.front();
        que.pop();
        for(auto [p, q]: S[x][y]) {
            if(!zero[p][q]) {
                zero[p][q] = true;
                counter ++;
                que.push(make_pair(p, q));
            }
        }
    }
    cout << m * m - counter << '\n';
}
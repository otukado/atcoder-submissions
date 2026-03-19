#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int N;
vector<vector<int>> grid;
vector<bool> visited(N, false);
vector<int> ans;

bool dfs(int now, int y) {
    visited[now] = true;
    if(y == now + 1) {
        return true;
    }
    else {
        for(int i=0; i<grid[now].size(); i++) {
            int next = grid[now][i];
            if(!visited[next]) {
                ans.push_back(next + 1);
                if(dfs(next, y)) return true;
                ans.pop_back();
            }
        }
        return false;
    }
}

int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        int M, X, Y;
        cin >> N >> M >> X >> Y;
        grid.assign(N, vector<int>());
        for(int j=0; j<M; j++) {
            int u, v;
            cin >> u >> v;
            grid[u-1].push_back(v-1);
            grid[v-1].push_back(u-1);
        }
        for(int j=0; j<N; j++) {
            sort(grid[j].begin(), grid[j].end());
        }

        visited.assign(N, false);
        ans = {X};
        dfs(X-1, Y);

        for(int j=0; j<ans.size(); j++) {
            cout << ans[j] << " ";
        }
        cout << endl;
    }
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> ans(N, vector<int>(N, -1));
    ans[0][(N-1)/2] = 1;
    pair<pair<int, int>, int> last = {{0, ((N-1) / 2)}, 1};

    for(int i=0; i<N*N-1; i++) {
        int r = last.first.first;
        int c = last.first.second;
        int k = last.second;
        if(ans[(N +r - 1) % N][(N + c + 1) % N] == -1) {
            ans[(N + r - 1) % N][(N + c + 1) % N] = k+1;
            last = {{(N + r - 1) % N, (N + c + 1) % N}, k+1};
        }else {
            ans[(N + r + 1) % N][c] = k+1;
            last = {{(N + r + 1) % N, c}, k+1};
        }
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}
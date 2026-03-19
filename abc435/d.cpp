#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;




int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> graph(N);
    for(int i=0; i<M; i++) {
        int X, Y;
        cin >> X >> Y;
        X--; Y--;
        graph[Y].push_back(X);
    }

    vector<bool> already_black(N, false);
    queue<int> que;
    int Q; cin >> Q;
    for(int i=0; i<Q; i++) {
        int t, v;
        cin >> t >> v;
        v--;
        if(t == 1) {
            que.push(v);
            while(que.size() > 0) {
                int q = que.front();
                que.pop();
                if(!already_black[q]) {
                    already_black[q] = true;
                    for(int j=0; j<graph[q].size(); j++) {
                        que.push(graph[q][j]);
                    }
                }
            }
        } else {
            if(already_black[v]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
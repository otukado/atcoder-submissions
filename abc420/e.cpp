#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) :par(n) {
        for(int i=0; i<n; i++) par[i] = i;
    }

    int root(int x) {
        if(par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void merge(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if(rx == ry) return;
        par[ry] = rx;
    }
};

int main() {
    int N, Q;
    cin >> N >> Q;
    UnionFind uf(N);
    vector<bool> black(N, false);
    vector<int> black_count(N, 0);
    for(int i=0; i<Q; i++) {
        int t;
        cin >> t;
        if(t == 1) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            if(uf.root(u) != uf.root(v)) {
                black_count[uf.root(u)] += black_count[uf.root(v)];
                uf.merge(u, v);
            }
        }else if(t == 2) {
            int v;
            cin >> v;
            v--;
            if(black[v]) {
                black[v] = false;
                black_count[uf.root(v)] --;
            } else {
                black[v] = true;
                black_count[uf.root(v)] ++;
            }
        }else {
            int v;
            cin >> v;
            v--;
            if(black_count[uf.root(v)] > 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}
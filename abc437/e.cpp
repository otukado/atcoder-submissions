#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;


struct Node {
    Node* parent;
    vector<Node*> children;
    int value;

    Node(int _value) : value(_value) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // auto A = vector(n+1, vector(0, pair{0, 0}));
    // auto rank = vector(n, pair(-1, -1));

    vector<Node*> nodes(n+1);

    for(int i=1; i<=n; ++i) {
        int x, y; cin >> x >> y;

        nodes[i] = new Node(y);
        nodes[i]->parent = nodes[x];
        nodes[x]->children.push_back(nodes[i]);
    }

    stack<pair<int, int>> dfs;
    dfs.emplace(0, 0);
    while(!dfs.empty()) {
        auto d = dfs.top(); dfs.pop();
        for(int i=0; i<(int) A[d.first].size(); ++i) {
            dfs.emplace(A[d.first][i].first, A[d.first][i]);
        }
    }
}
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

struct Node {
    Node* parent;
    vector<Node*> children;
    int id;
    int depth;

    Node(int val): id(val){}
    Node(Node* par, int i, int dep): parent(par), id(i), depth(dep){}
};

using mint = atcoder::modint998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m; cin >> m;
    vector<Node*> nodes(m);
    Node* root = new Node(-1);
    nodes[0] = new Node(root, 0, 0);
    for(int i=1; i<m; ++i) nodes[i] = new Node(i);
    for(int i=1; i<m; ++i) {
        int p; cin >> p; --p;
        nodes[i]->parent = nodes[p];
        nodes[p]->children.push_back(nodes[i]);
    }
    vector<vector<Node*>> depth;
    vector<ll> candy(m);
    vector<ll> want(m);
    vector<ll> per(m, 0);
    auto dfs = [&](auto self, Node* & nextNode) -> void {
        if(nextNode->id != 0) nextNode->depth = nextNode->parent->depth + 1;
        if((int) depth.size() <= nextNode->depth) depth.push_back({});
        depth[nextNode->depth].push_back(nextNode);
        for(auto child: nextNode->children) {
            self(self, child);
        }
    };
    dfs(dfs, nodes[0]);
    for(int i=0; i<m; ++i) cin >> candy[i];
    for(int i=0; i<m; ++i) cin >> want[i];
    for(int i=(int) depth.size()-1; i>=0; --i) {
        for(int j=0; j<(int) depth[i].size(); ++j) {
            int idx = depth[i][j]->id;
            per[idx] = candy[idx];
            if(depth[i][j]->children.size() != 0) {
                for(auto child: depth[i][j]->children) {
                    per[idx] += per[child->id] - want[child->id];
                }
            }
        }
    }

    vector<mint> prev;
    prev.push_back(1);
    int M = 1000009;
    for(int i=1; i<=M; ++i) {
        prev.push_back(prev[i-1] * i);
    }
    auto fact = [&](ll n, ll r) -> mint {
        mint res = 1;
        for(int i=0; i<r; ++i) {
            res *= (n - i);
        }
        return res;
    };
    auto nCr = [&](ll n, ll r) -> mint {
        if(n < r) return 0;
        mint res = fact(n, r) / prev[r];
        return res;
    };

    mint ans = 1;
    for(int i=0; i<m; ++i) {
        mint x = nCr(per[i], want[i]);
        ans *= x;
    }
    cout << ans.val() << '\n';
}
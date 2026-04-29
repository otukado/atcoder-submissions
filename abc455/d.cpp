#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

struct Node {
    Node* parent = nullptr;
    Node* children = nullptr;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;
    vector<Node*> card(2 * n);
    for(int i=0; i<n; ++i) {
        card[i] = new Node();
        card[i+n] = new Node();
        card[i]->parent = nullptr;
        card[i]->children = card[i+n];
        card[i+n]->parent = card[i];
        card[i+n]->children = nullptr;
    }

    for(int i=0; i<q; ++i) {
        int c, p; cin >> c >> p;
        c += n-1; p += n-1;
        card[c]->parent = card[p];
        card[p]->children = card[c];
    }
    for(int i=0; i<n; ++i) {
        int a = 0;
        auto next = card[i];
        while(true) {
            if(next->children == nullptr || next != next->children->parent) break;
            next = next->children;
            ++a;
        }
        cout << a << ' ';
    }
    cout << '\n';
}
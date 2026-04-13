#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int q;
    cin >> q;
    multiset<ll> tree;
    for(int i=0; i<q; ++i) {
        int n;
        ll h;
        cin >> n >> h;
        if(n == 1) {
            tree.insert(h);
        } else {
            while(tree.size() > 0) {
                auto m = tree.begin();
                if(*m > h) break;
                tree.erase(m);
            }
        }
        cout << (int) tree.size() << '\n';
    }
}
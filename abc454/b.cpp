#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    bool q_1 = true;
    set<int> person;
    set<int> cloth;
    for(int i=0; i<n; ++i) {
        int f;
        cin >> f;
        if(person.contains(f)) q_1 = false;
        person.insert(f);
        cloth.insert(f);
    }
    if(q_1) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    if((int) cloth.size() == m) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
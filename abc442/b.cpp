#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int vol = 0;
    bool on = false;
    int q;
    cin >> q;
    for(int i=0; i<q; ++i) {
        int a;
        cin >> a;
        if(a == 1) vol ++;
        else if(a == 2) {
            if(vol >= 1) vol --;
        } else {
            on = !on;
        }
        if(vol >= 3 && on) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}
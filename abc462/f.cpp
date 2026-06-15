#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    for(int i=0; i<t; ++i) {
        string s; cin >> s;
        int k; cin >> k;
        int n = s.size();
        auto ABC = vector(n-2, 3);
        for(int i=0; i<n-2; ++i) {
            if(s[i] == 'A') {
                ABC[i] -= 1;
            } else if(s[i] == 'B') {
                ABC[i+1] -= 1;
            } else if(s[i] == 'C') {
                ABC[i+2] -= 1;
            }
        }

        int count = 0;
        array<int, 4> neighbor = {-2, -1, 1, 2};
        for(int i=0; i<n-2; ++i) {
            if(ABC[i] == 0) {
                ++count;
                
            }
        }

    }
}
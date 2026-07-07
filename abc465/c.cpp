#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; string s;
    cin >> n >> s;
    vector<int> ans(n);
    bool reverse = false;
    int l = 0;
    int r = n-1;
    for(int i=n-1; i>=0; --i) {
        if(s[i] == 'o') {
            if(reverse) {
                ans[r] = i + 1;
                --r;
                reverse = false;
            } else {
                ans[l] = i + 1;
                ++l;
                reverse = true;
            }
        } else {
            if(reverse) {
                ans[l] = i + 1;
                ++l;
            } else {
                ans[r] = i + 1;
                --r;
            }
        }
    }
    for(int i=0; i<n; ++i) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}
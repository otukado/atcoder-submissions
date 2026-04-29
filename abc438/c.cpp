#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    stack<int> ans;
    for(int i=0; i<n; ++i) {
        int a;
        cin >> a;
        if(ans.size() >= 3) {
            int f = ans.top(); ans.pop();
            int s = ans.top(); ans.pop();
            int t = ans.top(); ans.pop();
            if(f != s || s != t || t != a) {
                ans.push(t);
                ans.push(s);
                ans.push(f);
                ans.push(a);
            }
        } else {
            ans.push(a);
        }
    }
    cout << (int) ans.size() << '\n';
}
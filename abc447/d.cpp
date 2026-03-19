#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    string s;
    cin >> s;
    vector<int> A, B, C;
    for(int i=0; i<s.size(); ++i) {
        if(s[i] == 'A') A.push_back(i);
        else if(s[i] == 'B') B.push_back(i);
        else C.push_back(i);
    }

    int b = 0; int c = 0;
    int ans = 0;
    for(int i=0; i<A.size(); ++i) {
        int n = A[i];
        auto b_it = lower_bound(B.begin()+b, B.end(), n);
        if(b_it == B.end()) break;
        int m = *b_it;
        b = b_it - B.begin() + 1;
        auto c_it = lower_bound(C.begin()+c, C.end(), m);
        if(c_it == C.end()) break;
        c = c_it - C.begin() + 1;
        ans ++;
        if(b_it == B.end()) break;
        if(c_it == C.end()) break;
    }
    cout << ans << '\n';
}
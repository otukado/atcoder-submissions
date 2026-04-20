#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i=0; i<t; ++i) {
        string A, B;
        cin >> A >> B;

        auto to_short = [&](string S) {
            stack<char> x;
            int num = 0;
            for(int j=0; j<(int) S.length(); ++j) {
                if(x.empty()) {
                    for(int k=0; k<num; ++k) {
                        x.push('x');
                    }
                    x.push(S[j]);
                    num = 0;
                }
                else {
                    char c = S[j];
                    char y = x.top();
                    if(c == 'x') ++num;
                    else if(c == ')' && num == 2 && y == '(') {
                        x.pop();
                    }
                    else {
                        for(int k=0; k<num; ++k) {
                            x.push('x');
                        }
                        num = 0;
                        x.push(c);
                    }
                }
            }
            for(int j=0; j<num; ++j) {
                x.push('x');
            }
            string ans = "";
            for(int j=0, sz=(int) x.size(); j<sz; ++j) {
                ans += x.top();
                x.pop();
            }
            return ans;
        };
        if(to_short(A) == to_short(B)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
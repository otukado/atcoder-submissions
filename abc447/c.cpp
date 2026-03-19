#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    string s, t;
    cin >> s >> t;

    string s_another;
    string t_another;
    for(int i=0; i<s.size(); ++i){
        if(s[i] != 'A') s_another.push_back(s[i]);
    }
    for(int i=0; i<t.size(); ++i) {
        if(t[i] != 'A') t_another.push_back(t[i]);
    }

    if(s_another != t_another) {
        cout << -1 << '\n';
        return 0;
    } else {
        vector<int> s_bet(s_another.size() + 2, 0);
        vector<int> t_bet(t_another.size() + 2, 0);

        int now = 0;
        for(int i=0; i<s.size(); ++i) {
            if(s[i] == 'A') s_bet[now] ++;
            else now++;
        }
        now = 0;
        for(int i=0; i<t.size(); ++i) {
            if(t[i] == 'A') t_bet[now] ++;
            else now++;
        }
        int ans = 0;
        for(int i=0; i<s_bet.size(); ++i) {
            ans += abs(s_bet[i] - t_bet[i]);
        }
        cout << ans << '\n';
        return 0;
    }
}
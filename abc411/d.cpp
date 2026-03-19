#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, Q;
    cin >> N >> Q;
    string ans="";
    vector<pair<int, int>> q(Q);
    vector<string> st;
    for(int i=0; i<Q; i++) {
        cin >> q[i].first >> q[i].second;
        if(q[i].first == 2) {
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            st.push_back(s);
        }
    }

    int now = N+1;
    int st_num = st.size()-1;
    for(int i=Q-1; i>=0; i--) {
        if(q[i].first == 3) {
            if(now == N+1) now = q[i].second;
        }
        else if(q[i].first == 2) {
            if(now == q[i].second) {
                ans += st[st_num];
            }
            st_num --;
        }else {
            if(now == q[i].second) {
                now = N+1;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}
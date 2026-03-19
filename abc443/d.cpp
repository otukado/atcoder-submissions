#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int t;
    cin >> t;
    for(int i=0; i<t; ++i) {
        int n;
        cin >> n;
        vector<int> R(n+1);
        vector<bool> already(n+1, false);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
        int done = 0;
        ll ans = 0;
        for(int j=1; j<=n; ++j) {
            cin >> R[j];
            que.push({R[j], j});
        }

        while(done < n) {
            auto [f, s] = que.top();
            que.pop();
            if (!already[s] && R[s] >= f) {
                already[s] = true;
                ans += R[s] - f;
                R[s] = f;
                done ++;
                for (int j=-1; j<=1; j+=2) {
                    if(s + j <= n && s + j >= 0) que.push({f+1, s+j});
                }
            }
        }
        cout << ans << '\n';
    }
}
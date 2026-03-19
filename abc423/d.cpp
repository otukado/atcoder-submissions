#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> group;
    for(int i=0; i<N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        group.push_back({a, b, c});
    }
    int headcount = 0;
    ll now = 0;
    
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>> ,greater<>> que;
    for(int i=0; i<N; i++) {
        while(headcount + group[i][2] > K) {
            now = que.top().first;
            headcount -= que.top().second;
            que.pop();
        }
        if(group[i][0] > now) now = group[i][0];
        que.push({now + group[i][1], group[i][2]});
        headcount += group[i][2];
        cout << now << endl;
    }
}
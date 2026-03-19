#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<pair<ll, ll>> point(N);
    for(int i=0; i<N; i++) {
        cin >> point[i].first >> point[i].second;
    }

    vector<pair<ll, ll>> line(N, pair<ll, ll>());
    for(int i=0; i<N; i++) {
        for(int j=i+1; j<N; j++) {
            ll a = point[i].first - point[j].first;
            ll b = point[i].second - point[j].second;
            if(a < 0) {
                a = -a;
                b = -b;
            }
            int d = gcd(abs(a), abs(b));
            line.push_back({a / d, b / d});
        }
    }

    
}
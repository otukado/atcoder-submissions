#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ll X;
    cin >> X;
    vector<pair<ll, ll>> div1;
    vector<pair<ll, ll>> div2;
    if((1-4*X) > 0) {
        for(ll i=1; i*i <= 1 - 4 * X; i++) {
            if((1 - 4 * X) % i == 0) {
                div2.push_back({i, (1 - 4 * X) / i});
                div1.push_back({-i, -(1 - 4 * X) / i});
            }
        }
    }else {
        for(ll i=1; i*i <= -(1 - 4 * X); i++) {
            if((1 - 4 * X) % i == 0) {
                div2.push_back({-i, -(1 - 4 * X) / i});
                div1.push_back({i, (1 - 4 * X) / i});
            }
        }
    }
    vector<ll> ans1;
    for(ll i=0; i<div1.size(); i++) {
        if((div1[i].first + div1[i].second - 2) % 4 == 0) {
            ans1.push_back((div1[i].first + div1[i].second - 2) / 4);
        }
    }
    vector<ll> ans2;
    for(ll i=0; i<div2.size(); i++) {
        if((div2[i].first + div2[i].second - 2) % 4 == 0) {
            ans2.push_back((div2[i].first + div2[i].second - 2) / 4);
        }
    }
    cout << ans1.size() + ans2.size() << endl;
    for(ll i=0; i<ans1.size(); i++) {
        cout << ans1[i] << " ";
    }
    reverse(ans2.begin(), ans2.end());
    for(ll i=0; i<ans2.size(); i++) {
        cout << ans2[i] << " ";
    }
    cout << endl;
}
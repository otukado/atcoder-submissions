#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k; cin >> n >> k;
    vector<pair<int, int>> nuno(n);
    for(int i=0; i<n; ++i) {
        cin >> nuno[i].first >> nuno[i].second;
    }

    auto compare_nuno = [&](const pair<int, int>& a, const pair<int, int>& b) -> bool{
        if(a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    };
    sort(nuno.begin(), nuno.end(), compare_nuno);


    auto is_ok = [&](const int& x){
        int num = 0;
        int current = -1000000000;
        for(int i=0; i<n; ++i) {
            if(current + x <= nuno[i].first) {
                current = nuno[i].second;
                ++num;
            }
        }
        if(num >= k) return true;
        else return false;
    };
    int ok = -1;
    int ng = 1000000000;
    while(abs(ng - ok) > 1) {
        int mid = (ok + ng) / 2;
        if(is_ok(mid)) ok = mid;
        else ng = mid;
    }
    if(ok == 0) cout << -1 << '\n';
    else cout << ok << '\n';
}
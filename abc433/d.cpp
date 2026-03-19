#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    vector<vector<ll>> nums(10);
    ull ans = 0;

    for(int i=0; i<N; i++) {
        ull a;
        cin >> A[i];
        a = A[i];
        int d = std::to_string(a).length();
        ll r = a % M;
        nums[d - 1].push_back(r);
    }

    for(int i=0; i<10; i++) {
        sort(nums[i].begin(), nums[i].end());
    }

    for(int i=0; i<N; i++) {
        ll r = A[i] % M;
        for(int j=0; j<10; j++) {
            r = (r * 10) % M;
            ll x = (M - r) % M;
            if(nums[j].size() > 0) {
                ans += upper_bound(nums[j].begin(), nums[j].end(), (M - r) % M) - lower_bound(nums[j].begin(), nums[j].end(), x);
            }
        }
    }
    cout << ans << endl;
}
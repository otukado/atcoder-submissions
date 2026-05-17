#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

constexpr ll INF = 3e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, k; cin >> n >> k;
    auto A = vector(n, 0LL);
    ll min_a = INF;
    for(int i=0; i<n; ++i) {
        cin >> A[i];
        min_a = min(min_a, A[i]);
    }

    auto can = [&](ll x) -> bool {
        ll K = 0;
        for(int i=0; i<n; ++i) {
            if(A[i] < x) {
                ll diff = x - A[i];
                ll counter = (diff + i) / (i + 1);
                K += counter;

                if(K > k) return false;
            }
        }
        return true;
    };

    ll ok = min_a;
    ll ng = INF;

    while(abs(ok - ng) > 1) {
        ll mid = ok + (ng - ok) / 2;
        if(can(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << '\n';
}
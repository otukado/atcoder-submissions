#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int right_left(int r, int l, vector<bool> is_open) {
    int count = 0;
    for(int i=l; i<=r; i++) {
        if(!is_open[i]) count++;
    }
    return count;
}

int main() {
    int N, H;
    cin >> N >> H;
    vector<bool> is_open(N,true);

    int l = H;
    int r = H-1;
    for(int i=0; i<N; i++) {
        int d;
        cin >> d;
        if(d) is_open[i] = false;
        else {
            r = max(r, i);
            l = min(l, i);
        }
    }

    ll ans = right_left(r, l, is_open) + r - l + 1;
    cout << ans << endl;
}
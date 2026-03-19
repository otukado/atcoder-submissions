#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    string T;
    cin >> N >> T;
    vector<int> zero_counter(N+1, 0);

    for(int i=0; i<N; i++) {
        if(T[i] == '0') {
            zero_counter[i+1] = 1;
        }
    }

    for(int i=1; i<=N; i++) {
        zero_counter[i] += zero_counter[i-1];
    }

    ll even_count = 0;
    ll odd_count = 0;
    for(int i=0; i<=N; i++) {
        if(zero_counter[i] % 2 == 1) odd_count++;
        else even_count++;
    }

    ll ans = even_count * (even_count - 1) / 2 + odd_count * (odd_count - 1) / 2;
    cout << ans << endl;
}
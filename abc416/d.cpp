#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        ll N, M;
        ull sum = 0;
        cin >> N >> M;
        vector<int> A, B;
        for(int j=0; j<N; j++) {
            int a;
            cin >> a;
            A.push_back((a + M) % M);
            sum += (a + M) % M;
        }
        for(int j=0; j<N; j++) {
            int b;
            cin >> b;
            B.push_back((b + M) % M);
            sum += (b + M) % M;
        }
        sort(A.begin(), A.end());
        reverse(A.begin(), A.end());
        sort(B.begin(), B.end());

        int now = 0;
        for(int j=0; j<N; j++) {
            auto x = lower_bound(B.begin(), B.end(), M - A[j]);
            if(x == B.end() || now == N) break;
            sum -= M;
            now = max(now + 1, int(x - B.begin()) + 1);
        }
        cout << sum << endl;
    } 
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, M;
    cin>> N >> M;
    vector<ll> A(N), B(M);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<M; i++) cin >> B[i];

    for(int i=0; i<M; i++) {
        auto it = lower_bound(A.begin(), A.end(), B[i]);
        if(it != A.end() && B[i] == A[it-A.begin()]) {
            A.erase(it);
        }
    }
    for(int i=0; i<A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}
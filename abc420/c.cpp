#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    ll N, Q;
    cin >> N >> Q;
    vector<ll> A(N);
    vector<ll> B(N);
    ull sum_min_AB = 0;
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    for(int i=0; i<N; i++) {
        cin >> B[i];
        sum_min_AB += min(A[i], B[i]);
    }

    for(int i=0; i<Q; i++) {
        string c;
        ll X, V;
        cin >> c >> X >> V;
        X--;
        if(c == "A") {
            if(A[X] < B[X]) {
                if(B[X] < V) sum_min_AB += B[X] - A[X];
                else sum_min_AB += V - A[X];
            }else {
                if(B[X] < V) sum_min_AB += B[X]- B[X];
                else sum_min_AB += V - B[X];
            }
            A[X] = V;
        }else {
            if(B[X] < A[X]) {
                if(A[X] < V) sum_min_AB += A[X] - B[X];
                else sum_min_AB += V - B[X];
            }else {
                if(A[X] < V) sum_min_AB += A[X]- A[X];
                else sum_min_AB += V - A[X];
            }
            B[X] = V;
        }
        cout << sum_min_AB << endl;
    }
}
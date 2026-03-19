#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    int A[N];
    int B[N];
    for (int i=0; i<N; i++) {
        cin >> A[i] >> B[i];
    }
    int c = 0;
    for(int i=0; i<N; i++) {
        if(A[i] < B[i]) {
            c++;
        }
    }
    cout << c << endl;
}
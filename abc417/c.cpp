#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> A_i(N);
    vector<int> A_j(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
        A_i[i] = A[i] + i + 1;
        A_j[i] = i - A[i] + 1; 
    }
    sort(A_i.begin(), A_i.end());
    sort(A_j.begin(), A_j.end());
    
    ll ans = 0;
    for(int i=0; i<N; i++) {
        int e = upper_bound(A_i.begin(), A_i.end(), A_j[i]) - lower_bound(A_i.begin(), A_i.end(), A_j[i]);
        ans += e;
    }
    cout << ans << endl;
}
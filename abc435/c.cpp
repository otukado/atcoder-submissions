#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }

    int has = 1;
    int ans = 0;
    for(int i=0; i<N; i++) {
        if(A[i] > has) {
            has = A[i];
        }
        ans ++;
        has --;
        if(has == 0) {
            break;
        }
    }
    cout << ans << endl;
}
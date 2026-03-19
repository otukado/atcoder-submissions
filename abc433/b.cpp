#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
        vector<int> A(N);
    for(int i=0; i<N; i++) {
        cin >> A[i];
    }
    
    for(int i=0; i<N; i++) {
        bool flag = false;
        for (int j = i; j >= 0; j--) {
            if(A[i] < A[j]) {
                cout << j+1 << endl;
                flag = true;
                break;
            }
        }
        if(!flag) cout << -1 << endl;
    }
}
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
    int X;
    cin >> X;
    bool can = false;
    for(int i=0; i<N; i++) {
        if(A[i] == X) {
            can = true;
            break;
        }
    }
    if(can) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}
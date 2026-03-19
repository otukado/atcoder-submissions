#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, L, R;
    string S;
    cin >> N >> L >> R >> S;
    bool ok = true;
    for(int i=L-1; i<R; i++) {
        if(S[i] != 'o') ok = false;
    }
    if(ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
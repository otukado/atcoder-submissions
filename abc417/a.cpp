#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, A, B;
    string S;
    cin >> N >> A >> B >> S;
    for(int i=A; i<N-B; i++) {
        cout << S[i];
    }
    cout << endl;
}
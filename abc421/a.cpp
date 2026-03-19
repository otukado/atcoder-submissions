#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    for(int i=0; i<N; i++) {
        cin >> S[i];
    }
    int X;
    string Y;
    cin >> X >> Y;
    if(S[X-1] == Y) cout << "Yes" << endl;
    else cout << "No" << endl;
}
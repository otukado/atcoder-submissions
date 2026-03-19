#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<int> D(N-1);
    for(int i=0; i<N-1; i++) {
        cin >> D[i];
    }
    
    for(int i=0; i<N-1; i++) {
        int ans = 0;
        for(int j=i; j<N-1; j++) {
            ans += D[j];
            cout << ans << " ";
        }
        cout << endl;
    }
}
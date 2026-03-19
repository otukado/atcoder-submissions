#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    string S, T;
    int N, M;
    cin >> N >> M >> S >> T;
    vector<int> v (N+1, 0);
    vector<int> v_wa (N+1);

    for(int i=0; i<M; i++) {
        int L, R;
        cin >> L >> R;
        L--; R--;

        v[L] ++;
        v[R+1] --;
    }
    
    v_wa[0] = v[0];
    for(int i=1; i<N; i++) {
        v_wa[i] = v_wa[i-1] + v[i];
    }
    
    for(int i=0; i<N; i++) {
        if(v_wa[i] % 2 == 0) cout << S[i];
        else cout << T[i];
    }
    cout << endl;
}
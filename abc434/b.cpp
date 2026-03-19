#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int M, N;
    cin >> N >> M;
    vector<vector<int>> birds(M);
    for(int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        a --;
        birds[a].push_back(b);
    }

    for(int i=0; i<M; i++) {
        double sum = 0;
        for (int j=0; j<birds[i].size(); j++) {
            sum += birds[i][j];
        }
        cout << fixed << setprecision(20) << double (sum / birds[i].size()) << endl;
    }
}
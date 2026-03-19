#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;
    vector<vector<int>> clouds;
    vector<vector<int>> sky(2002, vector<int>(2002, 0));
    vector<vector<int>> only_one_sky(2002, vector<int>(2002, 0));
    for(int i=0; i<N; i++) {
        int u, d, l, r;
        cin >> u >> d >> l >> r;
        clouds.push_back({u, d, l, r});

        sky[u][l] ++;
        sky[d+1][l] --;
        sky[u][r+1] --;
        sky[d+1][r+1] ++;
    }
    
    ll count = 0;
    for(int i=1; i<=2001; i++) {
        for(int j=0; j<2001; j++) {
            sky[i][j+1] += sky[i][j];
        }
    }
    for(int i=0; i<2001; i++) {
        for(int j=1; j<=2001; j++) {
            sky[i+1][j] += sky[i][j];
            if(sky[i+1][j] > 0) count ++;
            if(sky[i+1][j] == 1) only_one_sky[i+1][j] = 1;
        }
    }

    for(int i=0; i<=2001; i++) {
        for(int j=0; j<2001; j++) {
            only_one_sky[i][j+1] += only_one_sky[i][j];
        }
    }
    for(int i=0; i<2001; i++) {
        for(int j=0; j<=2001; j++) {
            only_one_sky[i+1][j] += only_one_sky[i][j];
        }
    }

    for(int i=0; i<N; i++) {
        int u = clouds[i][0];
        int d = clouds[i][1];
        int l = clouds[i][2];
        int r = clouds[i][3];
        cout << 2000 * 2000 + only_one_sky[u-1][l-1] + only_one_sky[d][r] - count - only_one_sky[u-1][r] - only_one_sky[d][l-1] << endl;
    }
}
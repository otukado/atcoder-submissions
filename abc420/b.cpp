#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for(int i=0; i<N; i++) {
        cin >> S[i];
    }

    vector<int> point(N, 0);
    for(int i=0; i<M; i++) {
        int n_0 = 0;
        int n_1 = 0;
        for(int j=0; j<N; j++) {
            if(S[j][i] == '0') n_0++;
            else n_1++;
        }
        for(int j=0; j<N; j++) {
            if(n_0 < n_1) {
                if(S[j][i] == '0') point[j]++;
            } else {
                if(S[j][i] == '1') point[j]++;
            }
        }
    }

    vector<int> ans;
    int max = 0;
    for(int j=0; j<N; j++) {
        if(max < point[j]) {
            max = point[j];
            ans.clear();
            ans.push_back(j+1);
        } else if(max == point[j]) {
            ans.push_back(j+1);
        }
    }
    for(int i=0; i<ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
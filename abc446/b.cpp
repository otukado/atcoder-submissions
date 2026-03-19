#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<bool> drink_list(m);
    vector<int> user_list(n);

    for(int i=0; i<n; ++i) {
        int l;
        cin >> l;
        vector<int> X(l);
        for(int j=0; j<l; ++j) {
            cin >> X[j];
        }

        bool isWater = true;
        for(int j=0; j<l; ++j) {
            if(!drink_list[X[j] - 1]) {
                user_list[i] = X[j];
                drink_list[X[j] - 1] = true;
                isWater = false;
                break;
            }
        }
        if(isWater) user_list[i] = 0;
    }

    for(int i=0; i<n; ++i) {
        cout << user_list[i] << '\n';
    }
}
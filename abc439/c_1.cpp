#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n = 1000;
    vector<int> x2;
    vector<int> good_vec;
    for(int i=1; i * i<=n; ++i) x2.push_back(i * i);
    for(int i=0; i<x2.size() - 1; ++i) {
        for(int j=i+1; j<x2.size(); ++j) {
            if(x2[i] + x2[j] > n) break;
            good_vec.push_back(x2[i] + x2[j]);
        }
    }

    sort(good_vec.begin(), good_vec.end());
    int now = 0;
    for(int i=0; i<good_vec.size()-1; ++i) {
        if(now != good_vec[i] && good_vec[i] != good_vec[i+1]) cout << good_vec[i] << ",";
        now = good_vec[i];
    }
    if(now != good_vec.back()) cout << good_vec.back();
    cout << '\n';
}
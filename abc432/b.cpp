#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int x;
    cin >> x;
    vector<int> X;
    while(x != 0) {
        X.push_back(x % 10);
        x /= 10;
    }
    
    sort(X.begin(), X.end());
    
    int y = lower_bound(X.begin(), X.end(), 1) - X.begin();

    cout << X[y];
    for(int i=0; i<X.size(); i++) {
        if(i != y) cout << X[i];
    }
}
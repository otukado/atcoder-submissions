#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    cin >> n;
    bool flag = true;
    
    int x = n % 10;
    for(int i = 0; i < 3; ++i) {
        if(x != n % 10) flag = false;
        n /= 10;
    }

    if(flag) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
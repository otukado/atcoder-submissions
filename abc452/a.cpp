#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int m, d;
    cin >> m >> d;
    bool can = false;
    if(m == 1 && d == 7) can = true;
    else if (m == 3 && d == 3) can = true;
    else if (m == 5 && d == 5) can = true;
    else if (m == 7 && d == 7) can = true;
    else if (m == 9 && d == 9) can = true;

    if(can) cout << "Yes" << '\n';
    else cout << "No" << '\n';
    
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int X, Y, Z;
    cin >> X >> Y >> Z;
    if((X-Z*Y) >= 0 && (X - Z*Y) % (Z - 1) == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
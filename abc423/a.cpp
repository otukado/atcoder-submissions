#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int X, C;
    cin >> X >> C;
    int y = X / (1000 + C);
    cout << y * 1000 << endl;
}
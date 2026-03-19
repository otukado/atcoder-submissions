#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main () {
    int T;
    cin >> T;
    for(int i=0; i<T; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        cout << min(min(a, c), (a + b + c) / 3) << endl;
    }
}
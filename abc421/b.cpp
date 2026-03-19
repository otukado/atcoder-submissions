#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll rev(ll x) {
    ll ans;
    string s = to_string(x);
    reverse(s.begin(), s.end());
    ans = stoll(s);
    return ans;
}


int main() {
    ll X, Y;
    cin >> X >> Y;
    vector<ll> fib;
    fib.push_back(X);
    fib.push_back(Y);
    for(int i=2; i<10; i++) {
        ll f = rev(fib[i-2] + fib[i-1]);
        fib.push_back(f);
    }
    cout << fib[9] << endl;
}
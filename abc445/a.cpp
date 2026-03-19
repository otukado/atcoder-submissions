#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    string S;
    cin >> S;
    if(S.front() == S.back()) {
        cout << "Yes" << '\n';
    } else {
        cout << "No" << '\n';
    }
}
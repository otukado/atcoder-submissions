#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main () {
    string S;
    cin >> S;
    char w = S.at(0);
    char s = S.at(2);
    if(s < '8') s += 1;
    else {
        w += 1;
        s = '1';
    }
    cout << w << "-" << s << endl;
}
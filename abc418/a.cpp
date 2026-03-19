#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    string T = "tea";
    bool can = true;
    if(N < 3) {
        can = false;
    }else {
        for(int i=0; i<3; i++) {
            if(S[N-1-i] != T[2-i]) {
                can = false;
                break;
            }
        }
    }
    if(can) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
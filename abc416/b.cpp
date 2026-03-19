#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    string S;
    cin >> S;
    vector<char> T(S.size());

    for(int i=0; i<S.size(); i++) {
        if(S[i] == '#') T[i] = '#';
        else T[i] = 'o';
    }

    int n = 0;
    bool first_o = true;
    for(int i=0; i<S.size(); i++) {
        if(T[i] == 'o') {
            bool ok = false;
            for(int j=i; j >= n; j--) {
                if(T[j] == '#') {
                    ok = true;
                    break;
                }
            }
            n = i;
            if(ok) T[i] = 'o';
            else T[i] = '.';
            if(first_o) {
                T[i] = 'o';
                first_o = false;
            }
        }
    }
    for(int i=0; i<T.size(); i++) {
        if(T[i] == 'o') {
            cout << 'o';
        }else if(T[i] == '#') { 
            cout << '#';
        }else cout << '.';
    }
    cout << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    string S;
    cin >> S;
    ll count = 0;
    vector<pair<int, int>> T;
    pair<char, int> current = {'9', 0};
    pair<char, int> old = {'1', 0};
    for(int i=0; i<S.length(); i++) {
        if(S[i] != current.first) {
            if(current.first - old.first == 1) {
                count += min(current.second, old.second);
            }
            old = current;
            current = {S[i], 1};
        }else {
            current.second += 1;
        }
    }
    if(current.first - old.first == 1) {
        count += min(current.second, old.second);
    }
    cout << count << endl;
}
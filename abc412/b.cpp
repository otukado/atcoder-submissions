#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string S,T;
    cin >> S >> T;
    vector<char> R;

    for(int i=1; i<S.size(); i++) {
        if('A' <= S.at(i) && S.at(i) <='Z') {
            R.push_back(S.at(i-1));
        }
    }
    int counter=0;
    for(int i=0; i<R.size(); i++) {
        for(int j=0; j<T.size(); j++) {
            if(R[i] == T[j]) {
                counter++;
                break;
            }
        }
    }
    if(counter == R.size()) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}
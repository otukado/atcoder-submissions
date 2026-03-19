#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    string S;
    cin >> S;
    int c = 0;
    vector<int> vec;
    for(int i=0; i<S.size(); i++) {
        if(S.at(i) == '#') {
            vec.push_back(i);
            c++;
        }
    }
    for(int i=0; i< c; i += 2) {
        cout << vec[i] + 1 << "," << vec[i+1] + 1 << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    ull c = 0;
    vector<ull> L;
    vector<string> T;
    bool can = true;
    for(int i=0; i<N; i++) {
        string s;
        ull l;
        cin >> s >> l;
        if(l > 100) {
            can = false;
            break;
        }
        L.push_back(l);
        T.push_back(s);
        c += l;
    }

    if(c > 100 || !can) {
        cout << "Too Long" << endl;
    }else {
        string S;
        for(int i=0; i<T.size(); i++) {
            for(int j=0; j<L[i]; j++) {
                S += T[i];
            }
        }
        cout << S << endl;
    }
}
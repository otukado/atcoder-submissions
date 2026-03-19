#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    string S;
    cin >> N >> S;
    vector<int> As;
    vector<int> Bs;
    for(int i=0; i<N*2; i++) {
        if(S.at(i) == 'A') As.push_back(i);
    }

    ll A_ans = 0;
    ll B_ans = 0;
    for(int i=0; i<As.size(); i++) {
        A_ans += abs(As[i] - 2 * i);
    }
    for(int i=0; i<As.size(); i++) {
        B_ans += abs(As[i] - 2 * i - 1);
    }
    cout << min(A_ans, B_ans) << endl;
}
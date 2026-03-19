#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> solved (n, 0);
    for(int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        solved[a] ++;
        if(solved[a] == m) cout << a+1 << " ";
    }
    cout << endl;
}
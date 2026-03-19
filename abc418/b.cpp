#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    string S;
    cin >> S;
    int n = S.size();
    double ans = 0.0;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            string sub = S.substr(i, j-i+1);
            if(sub.size() >= 3 && sub[0] == 't' && sub[sub.size()-1] == 't') {
                int count = 0;
                for(int k=1; k<sub.size()-1; k++) {
                    if(sub[k] == 't') count ++;
                }
                ans = max(ans, count / (double)(sub.size()-2));
            }
        }
    }
    cout << fixed << setprecision(15) << ans << endl;
}
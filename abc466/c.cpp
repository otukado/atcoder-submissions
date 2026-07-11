#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int n; cin >> n;

    
    vector<int> ans(n+1, 1);
    for(int i=1; i<n; ++i) {
        int r = min(max(ans[i-1] + 1, i + 1), n);
        ans[i] = max(ans[i-1], i);

        while(true) {
            cout << "? " <<  i << " " << r << endl;

            string res; cin >> res;
            if(res == "Yes") {
                ans[i] = r;
                r++;
                if(r > n) break;
            } else {
                break;
            }
        }

    }

    int answer = 0;
    for(int i=1; i<n; ++i) {
        answer += ans[i] - i;
    }

    cout << "! " << answer << endl;
}
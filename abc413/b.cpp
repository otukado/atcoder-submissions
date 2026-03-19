#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<string> S;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        S.push_back(s);
    }
    vector<string> ans;
    ans.push_back(S[0] + S[1]);

    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            bool can = true;
            string t = S[i] + S[j];
            for(int k=0; k<ans.size(); k++) {
                if(i == j) {
                    can = false;
                    break;
                }
                if(t == ans[k]) {
                    can = false;
                    break;
                }
            }
            if(can) {
                ans.push_back(t);
            }
        }
    }

    int A = ans.size();
    cout << A << endl;

}
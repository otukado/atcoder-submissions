#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    string s;
    cin >> s;
    vector<int> alphabet(26, 0);
    for(int i=0; i<int (s.size()); ++i) {
        alphabet[s[i] - 'a'] ++;
    }
    int m = 1;
    set<char> chr;
    for(int i=0; i<26; ++i) {
        if(alphabet[i] == m) chr.insert('a' + i);
        else if(m < alphabet[i]) {
            chr.clear();
            chr.insert('a' + i);
            m = alphabet[i];
        }
    }

    string ans;
    for(int i=0; i<s.size(); ++i) {
        if(!chr.contains(s[i])) ans.push_back(s[i]);
    }
    cout << ans << '\n';
}
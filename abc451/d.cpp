#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

ll lim = 1e9;
unordered_set<ll> good;
vector<string> two;
void nex (const string & s) {
    for(int i=0; i<(int) two.size(); ++i) {
        string t = two[i];
        if(s.length() + t.length() > 9) return;

        t = s + t;
        ll t_n = std::stoll(t);
        if(!good.contains(t_n)) {
            good.insert(t_n);
            nex(t);
        }
    }
    return;
}

int main() {
    for(ll i=1; i<lim; i*=2) {
        two.push_back(to_string(i));
    }
    nex("");

    vector<ll> sorted;
    for(auto it = good.begin(); it != good.end(); ++it) {
        sorted.push_back(* it);
    }
    sort(sorted.begin(), sorted.end());

    int n;
    cin >> n;
    cout << sorted[n-1] << '\n';
}
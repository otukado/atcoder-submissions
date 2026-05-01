#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

class Person {
public:
    ll x;
    Person * left;
    Person * right;
    ll value = 0;

    Person(ll _value) : x(_value) {}
    ll new_value(char c) {
        ll res = value;
        if(c == 'l') value = min(abs(left->x - x), value);
        else if (c == 'r') value = min(abs(right->x - x), value);
        else value = min(abs(right->x - x), abs(left->x - x));
        res = value - res;
        return res;
    }
};

ll INF = 1LL<<60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<ll, int> X;
    vector<Person*> P(n+2);
    X.insert(make_pair(0, 0));
    X.insert(make_pair(INF, n+1));
    P[0] = new Person(0);
    P[n+1] = new Person(INF);
    P[0] -> right = P[n+1];
    P[n+1] -> left = P[0];


    auto ans = vector(n+1, 0LL);
    for(int i=1; i<=n; ++i) {
        ll x; cin >> x;
        auto r_it = X.lower_bound(x);
        P[i] = new Person(x);
        auto R = P[r_it->second];
        auto L = R->left;
        P[i] -> left = L;
        P[i] -> right = R;

        ans[i] = ans[i-1] + P[i]->new_value('b');
        if(L == P[0] && R == P[n+1]) {
            ans[i] += x;
        } else if (L == P[0] && R != P[n+1]) {
            ans[i] += x - R->x;
        }
        P[X[L->x]]->right = P[i];
        ans[i] += P[X[L->x]]->new_value('r');

        P[X[R->x]]->left = P[i];
        ans[i] += P[X[R->x]]->new_value('l');
        X.insert(make_pair(x, i));
    }
    for(int i=1; i<=n; ++i) {
        cout << ans[i] << '\n';
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int Q;
    cin >> Q;
    vector<int> bag;
    for(int i=0; i<Q; i++) {
        int n;
        cin >> n;
        if(n == 1) {
            int x;
            cin >> x;
            bag.push_back(x);
        }else {
            sort(bag.begin(), bag.end());
            cout << bag[0] << endl;
            reverse(bag.begin(), bag.end());
            bag.pop_back();
        }
    }
}
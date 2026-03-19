#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int N, M;
    cin >> N >> M;
    int a;
    int ans = 0;
    for(int i=0; i<N; i++) {
        cin >> a;
        ans += a;
    }
    if(ans <= M) {
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    int N;
    cin >> N;
    int ans = 0;
    for(int i=0; i<=N; i++) {
        ans += i;
    }
    cout << ans;
}
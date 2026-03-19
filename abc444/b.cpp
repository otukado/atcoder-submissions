#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int digit_sum(int n) {
    int sum = 0;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    int c = 0;

    for(int i=1; i<=n; ++i) {
        if(digit_sum(i) == k) c++;
    }
    cout << c << '\n';
}
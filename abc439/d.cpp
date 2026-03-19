#include <bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
using ull = unsigned long long;

int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<ll, ll>> A(n);
    for(int i=0; i<n; ++i) {
        std::cin >> A[i].first;
        A[i].second = i;
    }

    std::sort(A.begin(), A.end());

    std::vector<std::pair<ll, bool>> A7;
    std::vector<std::pair<ll, bool>> A5;
    std::vector<std::pair<ll, bool>> A3;
    for(int i=0; i<n; ++i) {
        A7.push_back({A[i].first / 7, (A[i].first % 7 == 0)});
        A5.push_back({A[i].first / 5, (A[i].first % 5 == 0)});
        A3.push_back({A[i].first / 3, (A[i].first % 3 == 0)});
    }

    int count = 0;
}
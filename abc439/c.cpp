#include <bits/stdc++.h>
#include <atcoder/all>
using ll = long long;
using ull = unsigned long long;



int main() {
    int n;
    std::cin >> n;
    std::vector<int> x2;
    std::vector<int> good_vec;
    for(int i=1; i * i<=n; ++i) x2.push_back(i * i);
    for(const int i : std::views::iota(0, (int)std::ranges::size(x2) - 1)) {
        for(const int j : std::views::iota(i+1, (int)std::ranges::size(x2))) {
            if(x2[i] + x2[j] > n) break;
            good_vec.push_back(x2[i] + x2[j]);
        }
    }

    std::ranges::sort(good_vec);

    std::vector<int> ans;
    int now = 0;
    for(int i=0; i<(int)good_vec.size() - 1; ++i) {
        if(now != good_vec[i] && good_vec[i] != good_vec[i+1]) ans.push_back(good_vec[i]);
        now = good_vec[i];
    }
    if(good_vec.size() != 0 && now != good_vec.back()) ans.push_back(good_vec.back());
    std::cout << ans.size() << '\n';
    for(int i=0; i<(int)ans.size(); ++i) std::cout << ans[i] << " ";
    std::cout << '\n';
}
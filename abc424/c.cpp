#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> skill(N);
    vector<bool> has(N, false);
    queue<int> get;
    ll counter = 0;
    for(int i=0; i<N; i++) {
        int a, b;
        cin >> a >> b;
        if(a == 0 && b == 0) {
            get.push(i);
            has[i] = true;
        }else {
            skill[a-1].push_back(i);
            if(a != b) skill[b-1].push_back(i);
        }
    }

    while(get.size() > 0){
        int g = get.front();
        counter += 1;
        for(int i=0; i<skill[g].size(); i++) {
            if(!has[skill[g][i]]) {
                has[skill[g][i]] = true;
                get.push(skill[g][i]);
            }
        }
        get.pop();
    }
    cout << counter << endl;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main(){
    vector<int> abc(3);
    cin >> abc[0] >> abc[1] >> abc[2];
    sort(abc.begin(), abc.end());
    cout << abc[2] << abc[1] << abc[0];
}
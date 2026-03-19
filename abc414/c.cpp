#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    int A;
    ll N;
    cin >> A >> N;
    int dig = 1;
    ull ans = 0;
    int digits_10 = log10(N) + 1;

    for(int i=1; i <= 11; i++) {
        ull n = 0;
        if(i % 2 == 0) {
            for(int j=0; j<i/2; j++) {
                    if(j != 0 && k != 0) {
                        n += pow(10, j) * k + pow(10, i - j) * k;
                    }
            }
        }else {
            for(int j=0; j<i/2; j++) {
                for(int k=0; k<=9; k++) {
                    if(j != 0 && k != 0) {
                        n += pow(10, j) * k + pow(10, i - j) * k;
                    }
                }
            }
        }
    }  
}
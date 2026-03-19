#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    bool can = true;
        int digits_10 = log10(N) + 1;
        int digits_A = log10(N) / log10(A) + 1;
        for(int i=0; i<digits_10/2; i++) {
            ll dig_s = pow(10, i+1);
            ll dig_b = pow(10, digits_10-i);
            if(dig_s =! dig_b) {
                can = false;
                break;
            }
        }
        for(int i=0; i<digits_A/2; i++) {
            ll dig_s = pow(A, i+1);
            ll dig_b = pow(A, digits_A-i);
            if(dig_s =! dig_b) {
                can = false;
                break;
            }
        }
}
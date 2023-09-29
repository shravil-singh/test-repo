#include <bits/stdc++.h>
using namespace std;

unsigned long long bin_pow(unsigned long long x, int y, int mod) {
    unsigned long long ans = 1;
    x %= mod;
    while (y > 0) {
        if (y & 1) {
            ans *= x;
            ans %= mod;
        }
        y >>= 1;
        x *= x;
        x %= mod;
    }
    return ans;
}

unsigned long long modInv(unsigned long long n, int mod) {
        return bin_pow(n, mod - 2, mod); 
}

unsigned long long nCr(unsigned long long n, int r, int mod) {
    if (n < r) return 0;
    if (r == 0) return 1;

    unsigned long long fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % mod;

    return (fac[n] * modInv(fac[r], mod) % mod) * (modInv(fac[n - r], mod) % mod) % mod;
}

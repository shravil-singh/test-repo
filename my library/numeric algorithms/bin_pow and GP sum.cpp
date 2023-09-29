#include <bits/stdc++.h>
#define ll long long
using namespace std;

static long long mod = 1e9 + 7;

// (x ^ y) % mod
int power(long long x, long long y) {
    long long ans = 1ll;
    x %= mod;
    if (x == 0) {
        return 0;
    }
    while (y > 0) {
        if (y & 1) {
            ans *= x;
            ans %= mod;
        }
        y >>= 1ll;
        x *= x;
        x %= mod;
    }
    ans %= mod;
    return (int)ans;
}

auto gp_sum = [&](const auto &self, int a, int n, const int mod) -> int {
        if (n == 0) return 1;
        int res = 1LL * (1 + a) * self(self, (1LL * a * a) % mod, n / 2, mod) % mod;
        if (n % 2 == 0) res = (res - power(a, n + 1, mod) + mod) % mod;
        return res;
};



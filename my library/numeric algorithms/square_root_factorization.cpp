#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> primeFactors(int n) {
    unordered_map<int, int> mp;
    while (n % 2 == 0) {
        mp[2]++;
        n = n / 2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2) {
        while (n % i == 0) {
            mp[i]++;
            n = n / i;
        }
    }
    if (n > 2) mp[n]++;
    return mp;
}
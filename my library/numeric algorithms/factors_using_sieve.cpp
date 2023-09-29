#include "bits/stdc++.h"
using namespace std;

#define MAXN int(1e6 + 5)

int spf[MAXN];

void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)
		spf[i] = i;
	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;
	for (int i = 3; i * i < MAXN; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j < MAXN; j += i)
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

unordered_map<int, int> getFactorization(int x)
{
    unordered_map<int, int> mp;
	while (x != 1) {
        mp[spf[x]]++;
		x = x / spf[x];
	}
	return mp;
}


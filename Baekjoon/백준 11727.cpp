#include <bits/stdc++.h>

using namespace std;

const int MOD = 10007;

int cache[1110];

int tiling(int n) {
	if (n == 1) return 1;
	if (n == 2) return 3;
	int& ret = cache[n];
	if (ret != -1) return ret;

	return ret = (tiling(n - 1) + 2 * tiling(n - 2)) % MOD;
}

int main() {
	int n;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << tiling(n) << endl;
}

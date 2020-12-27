#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int cache[110], cache2[110];

int tiling(int n) {
	if (n <= 1) return 1;
	int& ret = cache[n];
	if (ret != -1) return ret;

	return ret = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

int main() {
	int tc, n;
	cin >> tc;
	while(tc--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		cout << tiling(n) << endl;
	}
}

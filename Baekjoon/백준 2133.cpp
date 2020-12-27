#include <bits/stdc++.h>

using namespace std;

int cache[1110];

int tiling(int n) {
	if (n == 0) return 1;
	if (n == 1) return 0;
	if (n == 2) return 3;
	int& ret = cache[n];
	if (ret != -1) return ret;

	int sum  = 3 * tiling(n - 2);
	for (int i = 3; i <= n; i++) {
		if (i % 2 == 0) {
			sum += 2 * tiling(n - i);
		}
	}
	return ret = sum;
}

int main() {
	int n;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << tiling(n) << endl;
}

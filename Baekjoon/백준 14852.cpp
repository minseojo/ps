/*
시간 초과 
#include <bits/stdc++.h>

using namespace std;

const int MOD = 100000007;
int cache[1111000];

int tiling(int n) {
	if (n == 0) return 1;
	if (n == 2) return 7;
	if (n == 1) return 2;
	int& ret = cache[n];
	if (ret != -1) return ret;
	int sum = (2 * tiling(n - 1) + 3 * tiling(n - 2));
	for (int i = 3; i <= n; i++) {
		sum += (tiling(n - i) * 2) % MOD;
	}
	return ret = sum % MOD;
}

int main() {
	int n;
	memset(cache, -1, sizeof(cache));
	cin >> n;
	cout << tiling(n) << endl;
}
*/

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;
long dp[1000001][2];

long DPtiling(int x) {
	dp[0][0] = 0;
	dp[1][0] = 2;
	dp[2][0] = 7;
	dp[2][1] = 1;
	for (int i = 3; i <= x; i++) {
		dp[i][1] += (dp[i - 3][0] + dp[i - 1][1]) % MOD;
		dp[i][0] += (2 * dp[i - 1][0] + 3 * dp[i - 2][0] + 2 * dp[i][1]) % MOD;
	}
	return dp[x][0];
}

int main() {
	int n;
	cin >> n;
	cout << DPtiling(n) << endl;
    
    return 0;
}

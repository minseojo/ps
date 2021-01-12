#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
long long a[1001][11] = { {0}, {1,1,1,1,1,1,1,1,1,1,1}, };
int n;

long long sum_solve(int n, int start) {
	long long sum=0;
	for (int i = start; i <= 10; i++) {
		sum += a[n-1][i];
	}

	return sum;
}

long long solve() {
	for (int i = 2; i <= 1000; i++) {
		for (int j = 1; j <= 10; j++) {
			a[i][j] = sum_solve(i, j)%MOD;
		}
	}
	long long sum = 0;
	for (int i = 1; i <= 10; i++) {
		sum += a[n][i];
	}

	return sum%MOD;
}

int main() {
	cin >> n;
	cout << solve();

	return 0;
}

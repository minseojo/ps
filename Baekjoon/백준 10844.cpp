//Âü°í https://lipcoder.tistory.com/entry/%EC%89%AC%EC%9A%B4-%EA%B3%84%EB%8B%A8-%EC%88%98-%EB%B0%B1%EC%A4%80-10844%EB%B2%88
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000000;
int a[100][100] = { {-1}, { 0,1,1,1,1,1,1,1,1,1 } };
int n;

int solve() {
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) a[i][j] = a[i - 1][j + 1] % MOD;
			else if (j == 9) a[i][j] = a[i - 1][j - 1] % MOD;
			else a[i][j] = (a[i - 1][j - 1] + a[i - 1][j + 1]) % MOD;
		}
	}

	long long sum = 0;
	for (int i = 0; i <= 9; i++) {
		sum += a[n][i];
	}

	return sum % MOD;
}

int main() {
	cin >> n;
	cout << solve();
	return 0;
}

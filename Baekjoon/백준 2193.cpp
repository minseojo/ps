#include <bits/stdc++.h>
using namespace std;

long long a[90] = { 1, 1 };
int n;

long long solve() {
	for (int i = 2; i < 90; i++) {
		a[i] = a[i - 1] + a[i - 2];
	}

	return a[n-1];
}

int main() {
	cin >> n;
	cout << solve();
	return 0;
}

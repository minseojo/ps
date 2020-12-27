#include <bits/stdc++.h>

using namespace std;

int arr[11111]{ -1 , -1 };

int main() {
	int m, n;
	cin >> m >> n;
	for (int i = 2; i <= 10000; i++) arr[i] = i;

	for (int i = 2; i <= 10000; i++) {
		for (int j = i + i; j <= 10000; j += i) {
			arr[j] = -1;
		}
	}

	int sum = 0, MIN = -1;
	for (int i = m; i <= n; i++) {
		if (arr[i] != -1) {
			if (MIN == -1)  MIN = arr[i];
			sum += arr[i];
		}
	}
	if (MIN != -1) {
		cout << sum << endl;
		cout << MIN;
	}
	else cout << MIN;

	return 0;
}

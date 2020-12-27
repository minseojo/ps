#include<bits/stdc++.h>

using namespace std;

int arr[123456 * 2 +1] = { 1,1 };

int main() {
	for (int i = 2; i <= 123456 * 2 + 1; i++) {
		for (int j = i + i; j <= 123456 *2 + 1; j += i) {
			arr[j] = 1;
		}
	}
	while (1) {
		int n;
		cin >> n;
		if (n == 0) break;
		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (arr[i] == 0) cnt++;
		}
		cout << cnt << endl;
	}

	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int arr[101];
long long n, sum = 0;
bool check[101];

int gcd(int a, int b) {
	return (b) ? gcd(b, a % b) : (a);
}

void f(int pos, int index) {
	if (pos == 2) {
		int cnt = 0;
		int aa = 1, bb = 1;
		for (int i = 0; i < n; i++) {
			if (check[i] && cnt == 0) {
				aa = arr[i]; cnt++;
			}
			if (check[i] && cnt == 1) bb = arr[i];
		}
		sum += gcd(aa, bb);
		return;
	}

	for (int i = index; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			f(pos + 1, i+1);
			check[i] = false;
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		memset(arr, 0, sizeof(arr));
		cin >> n;
		sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		f(0, 0);
		cout << sum << endl;
	}
}

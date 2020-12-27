#include <bits/stdc++.h>

using namespace std;

int arr[1111] = { 0,1 };
int ret[1111];
int n, cnt = 0;
bool check[1111];

void f(int pos, int sum) {
	if (cnt == 1) return;
	if (pos == 3) {
		if (sum == n) {
			for (int i = 0; i < 3; i++) {
				cout << ret[i] <<  " ";
			}
			cnt++;
		}
		return;
	}
	for (int i = 2; i < n; i++) {
		if (arr[i] != 1) {
			check[i] = true;
			ret[pos] = i;
			f(pos + 1, sum + i);
			check[i] = false;
		}
	}
}

int main() {
	int tc;
	cin >> tc;
	for (int i = 2; i <= 1000; i++) {
		for (int j = i + i; j <= 1000; j += i) {
			arr[j] = 1;
		}
	}
	while (tc--) {
		cin >> n;
		cnt = 0;
		memset(check, -1, sizeof(check));
		f(0, 0);
		cout << endl;
	}

	return 0;
}

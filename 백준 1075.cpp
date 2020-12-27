#include<bits/stdc++.h>

using namespace std;

int main() {
	long long n, f;
	cin >> n >> f;
	
	n = n / 100;
	n = n * 100;

	int  cnt = 0;
	while (1) {
		if (n % f == 0) break;
		n++;
		cnt++;
	}
	for (int i = 0; i <= 9; i++) {
		if (cnt == i) {
			cout << "0" << cnt;
			return 0;
		}
	}
	cout << cnt;

	return 0;
}

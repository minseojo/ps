#include <bits/stdc++.h>

using namespace std;

int arr[1111][1111];

int main() {
	long long n, total = 0; // 총 컴퓨터수
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			total += arr[i][j];
		}
	}
	if (total % 2 == 1) total++;
	long long left = 0, right = 10000000;
	while (left  <= right) {
		long long c = 0; // 절반 컴퓨터
		long long mid = (left + right) / 2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] >= mid) {
					c += mid;
				}
				else {
					c += arr[i][j];
				}
			}
		}
		if (c >= total / 2) right = mid-1;
		else left = mid+1;
	}
	cout << right+1;

	return 0;
}

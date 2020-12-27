#include <bits/stdc++.h>

using namespace std;

int arr[222];
int cache[222][222];
int k, n;

// 앞에 나온 숫자 뒤에 체크 함수
// 4 1 2 3 => ({4,1}, {4,2} {4,3}, {1,2}, {1,3}, {2,3} + 자기자신) 체크
void f(int index) {
	for (int i = 1; i <= n; i++) {
		if (arr[i] == -1 && cache[index][i] == 0) {
			cache[index][i]++;
		}
	}
}

int main() {
	cin >> k >> n;
	for (int i = 1; i <= k; i++) {
		memset(arr, -1, sizeof(arr));
		for (int j = 1; j <= n; j++) {
			int x;
			cin >> x;
			f(x);
			arr[x] = 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cache[i][j] == 0) {
				cnt++;
			}
		}
	}
	
	cout << cnt;

	return 0;
}

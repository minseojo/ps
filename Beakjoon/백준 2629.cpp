#include <bits/stdc++.h>

using namespace std;

int cache[15500][33];
int arr[33];
int Find[33];
int n, m;

void f(int w, int cnt) {
	if (cnt > n) return;
	int& ret = cache[w][cnt];
	if (ret != -1) return;
	ret = 77;

	// 같은 저울에 올리는 경우.
	f(w + arr[cnt], cnt + 1);

	// 무게가 같은경우.
	f(w, cnt + 1);

	// 반대편 저울에 올리는 경우.
	f(abs(w-arr[cnt]) , cnt + 1);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> Find[i];
	}

	memset(cache, -1, sizeof(cache));
	f(0, 0);

	for (int i = 0; i < m; i++) {
		if (Find[i] <= 15000 &&cache[Find[i]][n] == 77) cout << "Y ";
		else cout << "N ";
	}

	return 0;
}

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

	// ���� ���￡ �ø��� ���.
	f(w + arr[cnt], cnt + 1);

	// ���԰� �������.
	f(w, cnt + 1);

	// �ݴ��� ���￡ �ø��� ���.
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

#include <bits/stdc++.h>

using namespace std;

vector<int> v[1111];
int cache[1111];
int arr[1111];

int f(int index) {
	// 각 방에 자리가 이미 있으면 재귀 탈출.
	if (cache[index] != -1) return 0;
	cache[index] = 1;
	
	for (int i = 0; i < v[index].size(); i++) {
		int x = v[index][i];
		if (!arr[x] || f(arr[x])) {
			arr[x] = index;
			return 1;
		}
	}

	// 모든 방에 남는자리가 없으면 함수 탈출.
	return 0;
}

int main() {
	int n, m, k, w;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> w;
			v[i].push_back(w);
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		// 2번을 매칭시킴
		for (int j = 0; j < 2; j++) {
			// 다음 인덱스가 들어갈때마다 모든 방 체크 초기화.
			memset(cache, -1, sizeof(cache));
			if (f(i)) cnt++;
		}
	}

	cout << cnt << endl;

	return 0;
}


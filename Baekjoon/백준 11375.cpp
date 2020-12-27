#include <bits/stdc++.h>

using namespace std;

vector<int> v[1111];
int cache[1111];
int arr[1111];

int f(int index) {

	// ������ ��Ȳ�� ��ġ�� ��� ��Ȳ ��� Ż��.
	if (cache[index] != -1) return 0;
	cache[index] = 1;
	
	for (int i = 0; i < v[index].size(); i++) {
		int x = v[index][i];
		if (!arr[x] || f(arr[x])) {
			arr[x] = index;
			return 1;
		}
	}
	
	// ��� ��Ȳ�� ��ġ�� ��� �Լ� Ż��.
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
		// ���� �ε����� �������� �ʱ�ȭ.
		memset(cache, -1, sizeof(cache));
		if (f(i)) cnt++;
	}
	cout << cnt;
}


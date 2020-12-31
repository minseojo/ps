#include <bits/stdc++.h>
using namespace std;

int arr[1110][1110];
int list3[1111];
int list2[1111];
bool check[1111];
int n, team_a, team_b, mn = 987654321, c;

void f(int pos, int idx) {
	if (pos == n / 2 +1) {
		team_a = 0, team_b = 0;
		memset(list2, 0, sizeof(list2));
		int cnt = 1;
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				list2[cnt] = i;
				cnt++;
			}
			cout <<  list3[i] << " ";
		}
		cout << endl;
		for (int i = 1; i < pos; i++) {
			for (int j = 1; j < pos; j++) {
				if (i == j) continue;
				team_a += arr[list3[i]][list3[j]];
				team_b += arr[list2[i]][list2[j]];
			}
		}

		c = abs(team_a - team_b);
		mn = std::min(mn, c);
		return;
	}

	for (int i = idx; i <= n; i++) {
		if (check[i]) continue;
		check[i] = true;
		list3[pos] = i;
		f(pos + 1, i);
		check[i] = false;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	f(1, 1);

	cout << mn;
	return 0;
}

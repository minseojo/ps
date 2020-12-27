#include <bits/stdc++.h>

using namespace std;

vector<int> v[1111];
int stat[55][5];
bool check[1111];
int  bin[1111];

bool f(int index) {
	for (int i = 0; i < v[index].size(); i++) {
		int x = v[index][i];
		if (check[x]) continue;
		check[x] = true;
		if (!bin[x] || f(bin[x])) {
			bin[x] = index;
			return 1;
		}
	}

	return 0;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> stat[i][1] >> stat[i][2] >> stat[i][3];
	}

	for (int i = 1; i <= n - 1; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (stat[i][1] == stat[j][1] && stat[i][2] == stat[j][2] && stat[i][3] == stat[j][3]) {
				v[i].push_back(j);
			}
			else if (stat[i][1] >= stat[j][1] && stat[i][2] >= stat[j][2] && stat[i][3] >= stat[j][3]) {
				v[i].push_back(j);
			}
			else if (stat[i][1] <= stat[j][1] && stat[i][2] <= stat[j][2] && stat[i][3] <= stat[j][3]) {
				v[j].push_back(i);
			}
		}
	}
	
	int cnt = 0;
	for(int k=0; k<2; k++) {
	for (int i = 1; i <= n; i++) {
		memset(check, 0, sizeof(check));
		if (f(i)) cnt++;
		}
	}

	cout << n - cnt;

	return 0;
}

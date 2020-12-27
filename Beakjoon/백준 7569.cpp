#include <bits/stdc++.h>
using namespace std;

int m, n, h;
int arr[101][101][101];
queue<pair<pair<int, int>, int> > q;
int dy[6] = { 0,0,0,0,1,-1 };
int dx[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 1,-1,0,0,0,0 };
int cache[101][101][101];
int cnt = -1;

void bfs() {
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		while (size--) {
			int z = q.front().first.first;
			int y = q.front().first.second;
			int x = q.front().second;
			q.pop();
			for (int i = 0; i < 6; i++) {
				int nz = z + dz[i];
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (nz >= 1 && ny >= 1 && nx >= 1 && nz <= h && ny <= n && nx <= m && cache[nz][ny][nx] != 1  && arr[nz][ny][nx] != -1) {
					cache[nz][ny][nx] = 1;
					arr[nz][ny][nx] = 1;
					q.push({ {nz,ny},nx });
				}
			}
		}
	}

	bool flag = false;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				if (arr[i][j][k] == 0) {
					flag = true;
				}
			}
		}
	}
	if (flag) cout << -1;
	else cout << cnt;
}

int main() {
	cin >> m >> n >> h;  // x y z
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= m; k++) {
				cin >> arr[i][j][k];
				if (arr[i][j][k] == 1) {
					cache[i][j][k] = 1;
					q.push({ {i,j}, k });
				}
			}
		}
	}

	bfs();

	return 0;
}

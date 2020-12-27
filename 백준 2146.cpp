#include <bits/stdc++.h>

using namespace std;

int arr[111][111];
bool visited[111][111];
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int n;
queue<int> q;

void dfs(int y, int x, int index) {
	visited[y][x] = true;
	arr[y][x] = index;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (visited[ny][nx] || arr[ny][nx] == 0) continue;
		dfs(ny, nx, index);
	}
}

int c;
bool flag = false;

void bfs(int index) {
	c = -1;
	flag = false;
	while (!q.empty()) {
		if (flag == true) break;
		int size = q.size();
		c++;
		while (size--) {
			if (flag == true) break;
			int y = q.front() / 1000;
			int x = q.front() % 1000;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
				if (arr[ny][nx] != 0 && arr[ny][nx] != index) {
					flag = true;
					break;
				}
				if (visited[ny][nx]) continue;
				visited[ny][nx] = true;
				q.push(ny * 1000 + nx);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && !visited[i][j]) {
				cnt++;
				dfs(i, j, cnt);
			}
		}
	}
	int ret = 987654321;
	for (int k = 1; k <= cnt; k++) {
		q = queue<int>();
		memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == k) {
					q.push(i * 1000 + j); // q/1000 = y, q%1000 = x
				}
			}
		}
		bfs(k);
		ret = std::min(ret, c);
	}

	cout << ret;

	return 0;
}

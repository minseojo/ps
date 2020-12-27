#include <bits/stdc++.h>

using namespace std;

int arr[1111][1111];
int n, m;
queue<pair<int, int> > q;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
bool cache[1111][1111];
int cnt = -1;

void bfs() {
	while (!q.empty()) {
		int size = q.size();
		cnt++;
		while(size--) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = y + dy[i];
				int nx = x + dx[i];
				if (ny <= n && nx <= m && ny >= 1 && nx >= 1 && cache[ny][nx] == false && arr[ny][nx] != -1) {
					arr[ny][nx] = 1;
					cache[ny][nx] = true;
					q.push({ ny,nx });
				}
			}
		}
	}
	bool flag = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == 0) {
				flag = true;
			}
		}
	}

	if (flag) cout << -1;
	else cout << cnt;
}

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push({ i,j });
			}
		}
	}
	
	bfs();

	return 0;
}

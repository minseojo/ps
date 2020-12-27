#include <bits/stdc++.h>

using namespace std;

vector<int> v[111];
bool check[111];
int cnt = 0;
queue<int> q;

void dfs(int n) {
	cnt++;
	check[n] = true;
	for (int i = 0; i < v[n].size(); i++) {
		int x = v[n][i];
		if (!check[x]) {
			dfs(x);
		}
	}
}

void bfs(int n) {
	q.push(n);
	check[n] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < v[x].size(); i++) {
			int y = v[x][i];
			if (!check[y]) {
				check[y] = true;
				cnt++;
				q.push(y);
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	//dfs(1);
	bfs(1);
	//cout << cnt-1; 
	cout << cnt;
}

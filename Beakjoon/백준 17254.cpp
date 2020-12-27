#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, string> > v;

bool comp(pair<pair<int, int>, string> &a, pair<pair<int, int>, string> &b) {
	if (a.first.second != b.first.second) return a.first.second < b.first.second;
	return a.first.first < b.first.first;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		string c;
		cin >> a >> b >> c;
		v.push_back({ {a,b},c });
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < v.size(); i++) cout << v[i].second;

	return 0;
}

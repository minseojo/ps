#include <bits/stdc++.h>

using namespace std;

int n, k, cnt = 0;
int arr[11];
bool check[11];
bool cache[99999999];
vector<string> v;
set<string> s; // set�� ���ڵ� ���ڵ� �ߺ��� ������. �����ϴ� ������ ������� ���ĵǼ� �Է�

void f(int index, int k2, string sum) {
	if (k2 == k) {
		s.insert(sum);

	}
	for (int i = 0; i < n; i++) {
		if (!check[i]) {
			check[i] = true;
			f(i, k2 + 1, sum + to_string(arr[i]));
			check[i] = false;
		}
	}
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	f(0, 0, "");
	/*
	int retcnt = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!cache[stoi(v[i])]) {
			cache[stoi(v[i])] = true;
			retcnt++;
		}
	}
	cout << retcnt;
	*/
	cout << s.size();
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

pair<int, int> arr[100000];

bool comp(pair<int,int> a, pair<int,int>  b) {
	if (a.second < b.second) return 1;
	else return 0;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		arr[i].first = a;
	}
	for (int i = 0; i < n; i++) {
		int b;
		cin >> b;
		arr[i].second = b;
	}
	sort(arr, arr + n, comp);
	
	long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i].first + i * arr[i].second;
	}
	cout << sum;

	return 0;
}



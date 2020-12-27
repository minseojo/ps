#include <bits/stdc++.h>

using namespace std;

int arr[25];
vector<int> v;

int main() {
	int a, b, n;
	cin >> a >> b >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += arr[n-i] * pow(a, i-1);
	}

	while (sum > 0) {
		v.push_back(sum % b);
		sum = sum / b;
	}
	reverse(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}

	return 0;
}

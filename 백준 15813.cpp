#include <bits/stdc++.h>

using namespace std;

int arr[26];

int main() {
	int n;
	for (int i = 65; i < 98; i++) {
		arr[i] = i-64;
	}
	cin >> n;
	string s;
	cin >> s;
	int sum = 0;
	for (int i = 0; i < s.size(); i++) {
		sum += arr[s[i]];
	}
	cout << sum;
}

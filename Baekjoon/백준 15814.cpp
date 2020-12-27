#include <bits/stdc++.h>

using namespace std;

int arr[26];

int main() {
	string s;
	cin >> s;
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		char temp = s[a];
		s[a] = s[b];
		s[b] = temp;
	}
	cout << s;
	
}

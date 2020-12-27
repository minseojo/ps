#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, cnt = 0;
	cin >> n;
	int x = 665;
	string s;
	while (1) {
		x++;
		s = to_string(x);
		if (s.find("666") != -1) cnt++;
		if (cnt == n) {
			cout << s;
			return 0;
		}
	}
}

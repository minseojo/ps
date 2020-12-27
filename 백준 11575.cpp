#include <bits/stdc++.h>

using namespace std;

int bin[1111111]; //알파벳 암호문
int alpha[100];

int main() {
	for (int i = 65; i < 98; i++) alpha[i] = i - 65;
	int tc;
	cin >> tc;
	while (tc--) {
		int a, b;
		string s;
		cin >> a >> b >> s;
		memset(bin, 0, sizeof(bin));
		for (int i = 0; i < s.size(); i++) {
			bin[i] = (a * alpha[s[i]] + b) % 26 + 65;
		}
		for (int i = 0; i < s.size(); i++) {
			cout << char(bin[i]);
		}
		cout << endl;
	}

	return 0;
}

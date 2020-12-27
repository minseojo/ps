#include <bits/stdc++.h>

using namespace std;

int main() {
	int sum = 0;
	string s;
	cin >> s;
	stack<int> v;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
			int a = v.top();
			v.pop();
			int b = v.top();
			v.pop();
			if (s[i] == '*') sum = b * a;
			else if (s[i] == '/') sum = b / a;
			else if (s[i] == '+') sum = b + a;
			else sum = b - a;
			v.push(sum);
		}
		else {
			v.push(s[i]-'0');
		}
	}
	cout << sum;

	return 0;
}

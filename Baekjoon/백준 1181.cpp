#include <bits/stdc++.h>
using namespace std;
 
bool comp(string a, string b) {
	if (a.size() < b.size()) return 1;
	else if (a.size() > b.size()) return 0;
	else return a < b;
}

int main()
{
	int n;
	cin >> n;
	vector<string> v;
	string s[20000];
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n, comp);
	for (int i = 0; i < n; i++) {
		if (i > 0 && s[i] == s[i - 1]) continue;
		cout << s[i] << endl;
	}
	return 0;
}

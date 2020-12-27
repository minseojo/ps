#include <bits/stdc++.h>

using namespace std;

string arr[1011];

int main() {
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		string s2 = "";
		for (int j = i; j < s.size(); j++) {
			s2 += s[j];
		}
		arr[i] = s2;
	}
	sort(arr, arr + s.size());

	for (int i = 0; i < s.size(); i++) {
		cout << arr[i] << endl;
	}
}

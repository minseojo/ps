#include <bits/stdc++.h>
using namespace std;

string s[1001];

int getsum(string a) {
	int sum = 0;
	//������ ��츸 ���� 
	for (int i = 0; i < a.size(); i++) {
		if (a[i] - '0' >= 0 && a[i] - '0' <= 9) sum += a[i] - '0';
	}
	return sum;
}

bool comp(string a, string b) {
	// ���̰� �ٸ� ��� (������������ ����) 
	if (a.size() < b.size()) return 1;
	else if (a.size() > b.size()) return 0;
	// ���̰� ���� ���
	else {
		int asum = getsum(a);
		int bsum = getsum(b);
		if (asum != bsum) return asum < bsum;
		else return a < b;
	}
	return a < b;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	sort(s, s + n, comp);
	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	}
	return 0;
}

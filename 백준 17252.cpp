#include <bits/stdc++.h>

using namespace std;

vector<long long> v;
long long n;
bool flag = false;

void f(long long index, long long sum) {
	if (sum == 0) flag = true;
	if (index == v.size() || sum < 0) return;
	
	f(index + 1, sum); // 넘어가기
	f(index + 1, sum - v[index]); // 빼기
}

int main() {
	cin >> n;
	long long a = 2147483647;
	long long b = 1;
	while (a >= b) {
		v.push_back(b);
		b = b * 3;
	}
	if (n == 0) {
		cout << "NO";
		return 0;
	}
	f(0, n);
	if (flag) cout << "YES";
	else cout << "NO";

	return 0;
}

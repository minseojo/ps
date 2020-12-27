#include <bits/stdc++.h>
using namespace std;

int MAX = 100000;
int n, k;
bool cache[110000];
queue<int> q;

int f(int index, int cnt) {
	q.push(index);
	cache[index] = 1;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front();
			q.pop();
			// ±âÀú
			if (x == k) return cnt;
			
			if (x + 1 <= MAX && !cache[x + 1]) {
				q.push(x + 1);
				cache[x + 1] = 1;
			}
			if (x > 0 && !cache[x - 1]) {
				q.push(x - 1);
				cache[x - 1] = 1;
			}
			if (x * 2 <= MAX && !cache[x * 2]) {
				q.push(x * 2);
				cache[2 * x] = 1;
			}
		}
		cnt++;
	}
}
int main()
{
	cin >> n >> k;
	cout << f(n, 0);

	return 0;
}

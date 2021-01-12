#include <bits/stdc++.h>
using namespace std;

int a[1000];
int cache[1000];
int n;

int solve(int end) {
	int &ret = cache[end-1];
	if(ret!=-1) return ret;
	ret=0;
	for(int i=end-1; i>=0; i--) {
		if(a[end] < a[i])
			ret = std::max(ret, solve(i)+1);	
	}
	return ret;
}

int main() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	cout << solve(n);

	return 0;
}

#include <bits/stdc++.h>
using namespace std;

int a[1000];
int cache[1000];
int n;

int solve(int start) {
	int &ret = cache[start+1];
	if(ret!=-1) return ret;
	ret=0;
	for(int i=start+1; i<n; i++) {
		if(a[start] < a[i])
			ret = std::max(ret, solve(i)+a[i]);
	}
	return ret;
}

int main() {
	cin >> n;
	memset(cache, -1, sizeof(cache));
	for(int i=0; i<n; i++) {
		cin >> a[i];
	}
	cout << solve(-1);
	
	return 0;
}

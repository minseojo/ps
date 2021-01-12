#include <bits/stdc++.h>
using namespace std;

int prime[1000001];

int main() {
	int n;
	for(int i=2; i<=1000001; i++) {
		for(int j=i+i; j<=1000001; j+=i) {
			prime[j] = -1;
		}
	}
	
	while(1) {
		cin >> n;
		if(n==0) break;
		int cnt=0;
		for(int i=n+1; i<=2*n; i++) {
			if(prime[i]!=-1) cnt++;
		}
		cout << cnt << endl;
	}
	
	return 0;
} 

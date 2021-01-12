#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	if(n==1) return 0;
	
	for(int i=2; i<=sqrt(n); i++) {
		if(n%i==0) {
			n/=i;
			cout << i << endl;
			i--;
		}
	}
	if(n>1) cout << n;

	return 0;
} 

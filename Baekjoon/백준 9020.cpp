#include <bits/stdc++.h>
using namespace std;

int prime[10001] = {-1, -1};
int arr[10001];

int main() {
	int tc, n, resultA, resultB;
	cin >> tc;
	for(int i=2; i<=10001; i++) {
		for(int j=i+i; j<=10001; j+=i) {
			prime[j] = -1;
		}
	}
	
	while(tc--) {
		cin >> n;
		int cnt=0;
		memset(arr, 0, sizeof(arr));
		for(int i=2; i<=n; i++) {
			if(prime[i]!=-1) {
				arr[cnt] = i;
				cnt++;
			}
		}
		int mn=10001;
		for(int i=0; i<cnt; i++) {
			int sum=0;
			for(int j=0; j<cnt; j++) {
				sum = arr[i] + arr[j];
				if(sum==n && abs(arr[i]-arr[j]) < mn) {
					mn=abs(arr[i]-arr[j]);
					resultA = arr[i];
					resultB = arr[j];
				}
			}
		}
		if(resultA>resultB) cout << resultB << " " << resultA <<endl;
		else cout << resultA << " " <<resultB << endl;
	}
	
	return 0;
} 

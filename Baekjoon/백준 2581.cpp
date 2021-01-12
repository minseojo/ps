#include <bits/stdc++.h>
using namespace std;

int arr[10001] = {-1, -1 };

int main() {
	int m, n;
	cin >> m >> n;
	
	for(int i=2; i<=10001; i++) {
		for(int j=i+i; j<=10001; j+=i) {
			arr[j] = -1;
		}
	}
	int cnt=0, mn=0, sum=0, flag=0;
	for(int i=m; i<=n; i++) {
		if(arr[i]!=-1) {
			if(flag!=1) mn = i;
			sum+=i;
			flag=1;
		}
	}
	if(flag==1) {
		cout << sum << endl;
		cout << mn;
	}
	else cout << -1;
	
	return 0;
}

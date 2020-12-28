#include <bits/stdc++.h>

using namespace std;
int n, result = 0;
int col[15];

bool promising(int i) {
	for(int j=0; j<i; j++) {
		if(col[i] == col[j] || abs(col[i]-col[j]) == i-j) {
			return false;
		}
	}
	return true;
}

void queen(int i) {
	if(i == n) {
		result++;
	}
	else {
		for(int j=0; j<n; j++) {
			col[i] = j;
			if(promising(i)) {
				queen(i+1);
			}
		}
	}
}

int main() {
	cin >> n;
	queen(0);
	cout << result;
	
	return 0;
}

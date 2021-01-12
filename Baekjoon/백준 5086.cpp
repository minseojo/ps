#include <bits/stdc++.h>
using namespace std;

int main() {
	while(1) {
		int a,b;
		cin >> a >> b;
		if(!a && !b) break;
		if(b%a==0) cout << "factor" << endl;
		else if(a%b==0) cout << "multiple" << endl;
		else cout << "neither" << endl;
	}

	return 0;
} 

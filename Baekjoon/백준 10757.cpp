#include <bits/stdc++.h>
using namespace std;

int sum[10001];
int main() {
	string a, b;
	cin >> a >> b;
	if(a.size() < b.size()) swap(a,b);
	int index_a = a.size()-1;
	int index_b = b.size()-1;

	for(int i=0; i<a.size(); i++) {
		if(i <= index_b) {
			sum[i] = a[index_a-i]-'0' + b[index_b-i]-'0'; 
		}		
		else {
			sum[i] = a[index_a-i]-'0';
		}
	}
	int size=0;
	for(int i=0; i<a.size(); i++) {
		if(sum[i]>9) {
			if(i==a.size()-1) size++;
			sum[i+1] +=sum[i]/10;
			sum[i] = sum[i]%10;
		}
	}
	
	for(int i=a.size()-1+size; i>=0; i--) {
		cout << sum[i];
	}
	
	return 0;
}

/* 
<���� ������ �̿��� �ŵ�����> - �׳� ��ͷ� �� ��� O(n) 
�ð� ���⵵: O(log(n)) 
*/
#include <bits/stdc++.h>
using namespace std;

int y; 
int Recursive_Power(int x, int n) { // x�� n�� 
	if(n==1) return x; // n�� 1�ΰ�� �ڱ��ڽ� ���� 
	
	if(n%2==0) { // n�� ¦�� �� �� 
		y = Recursive_Power(x, n/2);
		return y*y;	
	}
	
	else { // n�� Ȧ�� �� �� 
		y = Recursive_Power(x, (n-1)/2);
		return y*y*x;
	}
}

int main() {
	int x, n;
	cin >> x >> n; // x^n (x�� n��) 
	cout << Recursive_Power(x, n);

	return 0;
}

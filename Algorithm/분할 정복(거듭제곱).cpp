/* 
<분할 정복을 이용한 거듭제곱> - 그냥 재귀로 할 경우 O(n) 
시간 복잡도: O(log(n)) 
*/
#include <bits/stdc++.h>
using namespace std;

int y; 
int Recursive_Power(int x, int n) { // x의 n승 
	if(n==1) return x; // n이 1인경우 자기자신 리턴 
	
	if(n%2==0) { // n이 짝수 일 때 
		y = Recursive_Power(x, n/2);
		return y*y;	
	}
	
	else { // n이 홀수 일 때 
		y = Recursive_Power(x, (n-1)/2);
		return y*y*x;
	}
}

int main() {
	int x, n;
	cin >> x >> n; // x^n (x의 n승) 
	cout << Recursive_Power(x, n);

	return 0;
}

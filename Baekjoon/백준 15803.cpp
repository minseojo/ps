#include <bits/stdc++.h>

using namespace std;

int main()
{
	double x1, x2, x3, y1, y2, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	// 분모가 0이 되는 상황을 없애주기 위해 구분함.

	if (x1 != x2 && x2 != x3 && x1 != x3) { 
		if ((y2 - y1) / (x2 - x1) == (y3 - y2) / (x3 - x2))
			cout << "WHERE IS MY CHICKEN?";
		else cout << "WINNER WINNER CHICKEN DINNER!";
	}
	else {
		if ((x2 - x1) / (y2 - y1) == (x3 - x2) / (y3 - y2))
			cout << "WHERE IS MY CHICKEN?";
		else cout << "WINNER WINNER CHICKEN DINNER!";
	}

	return 0;
}

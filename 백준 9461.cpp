#include <bits/stdc++.h>

using namespace std;

long long arr[111] = { 1,1,1,2,2,3 };

int main() {

	for (int i = 5; i <= 100; i++) {
		arr[i + 1] = arr[i] + arr[i - 4];
	}

	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		cout << arr[n-1] << endl;
	}

	return 0;
}
/*
1 1 1 2 2 3 4 5 7 9 12 16 21 28 37 49 65 86 135
      
1+3 1+4 2+5 2+7 3+9 4+12 5+16 7+21 9+28 12+37 16+49 21+65 28+86

    1   2			 3
  1       3			 4
1          4		 5
       2     5		 7
        2      7	 9
         3      9    12
		   4     12  16
		    5     16 21
			 7     21 28
			  9    28 37     21 28 37 49 65 86
			   12 37   49
			    16 49  65
				 21 65 86

*/

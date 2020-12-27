/*
계획:
타일링 문제에서 구한 전체 타일링 경우의 수에서 대칭 타일링 경우의 수를 구해 빼준다.
=> 대칭 타일링 경우의 수를 구해줘야 함.


문제 해결:

1. 대칭 타일링의 개수는 n이 홀수인 경우와, 짝수인 경우로 나뉜다.
2. n이 홀수 인 경우, 대칭이 되기 위해서는 ㅁㅁ | ㅁㅁ 이런 경우이다.
3. n이 짝수인 경우, 대칭이 되기 위해서는 ㅁㅁㅁㅁ또는 ㅁ ㅁ | | ㅁ ㅁ 이런 경우이다.
4. 각 경우에서, 왼쪽 대칭 부분을 구하면 오른쪽 대칭 부분도 알아서 결정된다. 
	따라서 빈 부분을 채우는 방법과 1:1 대응이다.
5. (2, 3, 4)에 따라서
       n이 홀수인 경우 ret = (ret - tiling(n / 2));
       n이 짝수인 경우 ret = (ret - tiling((n / 2) -1)); 
6.  tiling(n) =  1000000008,
	tiling(n/2) = 100이면,
    tling(n) - tling(n/2)는 -99로 음수가 나올 수 있으므로, MOD 값을 더해주고 나눠준다.
*/
#include <bits/stdc++.h>
using namespace std;

int MOD = 1000000007;
int cache[110], cache2[110];

int tiling(int n) {
	if (n <= 1) return 1;
	int& ret = cache[n];
	if (ret != -1) return ret;
	return ret = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

int asymtiling(int n) {
	
	if (n <= 2)	return 0;
	int& ret = cache2[n];
	if (ret != -1) return ret;
	ret = tiling(n);
	ret = (ret - tiling(n / 2) + MOD ) % MOD;
	if(n % 2 == 0) ret = (ret - tiling((n / 2) -1) + MOD) % MOD;   // tiling((n/2)-1) => tiling((n-1)/2) 같은 의미
	return ret;
}

int main() {
	int tc, n;
	cin >> tc;
	while(tc--) {
		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));
		cin >> n;
		cout << asymtiling(n) << endl;
	}
	return 0;
}

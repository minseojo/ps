/*
��ȹ:
Ÿ�ϸ� �������� ���� ��ü Ÿ�ϸ� ����� ������ ��Ī Ÿ�ϸ� ����� ���� ���� ���ش�.
=> ��Ī Ÿ�ϸ� ����� ���� ������� ��.


���� �ذ�:

1. ��Ī Ÿ�ϸ��� ������ n�� Ȧ���� ����, ¦���� ���� ������.
2. n�� Ȧ�� �� ���, ��Ī�� �Ǳ� ���ؼ��� ���� | ���� �̷� ����̴�.
3. n�� ¦���� ���, ��Ī�� �Ǳ� ���ؼ��� ���������Ǵ� �� �� | | �� �� �̷� ����̴�.
4. �� ��쿡��, ���� ��Ī �κ��� ���ϸ� ������ ��Ī �κе� �˾Ƽ� �����ȴ�. 
	���� �� �κ��� ä��� ����� 1:1 �����̴�.
5. (2, 3, 4)�� ����
       n�� Ȧ���� ��� ret = (ret - tiling(n / 2));
       n�� ¦���� ��� ret = (ret - tiling((n / 2) -1)); 
6.  tiling(n) =  1000000008,
	tiling(n/2) = 100�̸�,
    tling(n) - tling(n/2)�� -99�� ������ ���� �� �����Ƿ�, MOD ���� �����ְ� �����ش�.
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
	if(n % 2 == 0) ret = (ret - tiling((n / 2) -1) + MOD) % MOD;   // tiling((n/2)-1) => tiling((n-1)/2) ���� �ǹ�
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

/*

��ȹ
m�ϱ��� Ȯ���� �޸������̼� �ϸ鼭 m���� �Ǹ� Ȯ���� �����Ѵ�.
 
�� double���� memset�� �ȵȴ�.
=> ������ ���� �ʱ�ȭ �ϰų�, fill_n�� �̿��Ѵ�.

*/
#include <bits/stdc++.h>

using namespace std;

double cache[1100][2200];
int n, m;
double climb(int days, int climbed) {
	if (days == m) return climbed >= n ? 1 : 0;
	double& ret = cache[days][climbed];
	if (ret != -1) return ret;
	return ret = 0.25*(climb(days + 1, climbed + 1)) + 0.75*(climb(days + 1, climbed + 2));
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		// memset(cache, -1.0, sizeof(cache)); double���� memset�� ������ �ȵ�.
		// fill_n ����
		for (int i = 0; i < 1001; i++) {
			for (int j = 0; j < 2002; j++) {
				cache[i][j] = -1;
			}
		}
		cin >> n >> m;
		printf("%.10f\n", climb(0, 0));
	}

	return 0;
}

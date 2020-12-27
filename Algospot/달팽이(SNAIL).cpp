/*

계획
m일까지 확률을 메모이제이션 하면서 m일이 되면 확률을 리턴한다.
 
☆ double형은 memset이 안된다.
=> 포문을 통해 초기화 하거나, fill_n을 이용한다.

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
		// memset(cache, -1.0, sizeof(cache)); double형은 memset이 적용이 안됨.
		// fill_n 가능
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

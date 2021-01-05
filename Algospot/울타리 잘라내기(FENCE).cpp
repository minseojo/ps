#include <bits/stdc++.h>
using namespace std;

int h[20000];
int n, ret;

int solve(int left, int right) {
	//판자가 1개인 경우 
	if (left == right) {
		return h[left];
	}
	int mid = (left + right) / 2;
	//왼쪽, 오른쪽 분할 
	int ret = max(solve(left, mid), solve(mid+1, right));
	
	int low = mid;
	int high = mid+1;
	int height = min(h[low], h[high]);
	
	//중간부분에 걸친 경우 
	ret = std::max(ret, height*2);
	
	//양쪽으로 한 칸씩 확장
	//이때 왼쪽, 오른쪽 중 더 큰 쪽으로 확장한다.
	while (left < low || high < right) {
		//오른쪽으로 확장 
		if (high < right && (low == left || h[low-1] < h[high+1])) {
			high++;
			height = min(height, h[high]);
		}
		//왼쪽으로 확장 
		else {
			low--;
			height = min(height, h[low]);
		}
		// 확장한 후 사각형의 넓이 
		ret = max(ret, height * (high - low + 1));
	}
	return ret;
}

int main() {	
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> h[i];
		}
		cout << solve(0, n-1) << endl;
	}

	return 0;
}

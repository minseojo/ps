#include <bits/stdc++.h>
using namespace std;

int h[20000];
int n, ret;

int solve(int left, int right) {
	//���ڰ� 1���� ��� 
	if (left == right) {
		return h[left];
	}
	int mid = (left + right) / 2;
	//����, ������ ���� 
	int ret = max(solve(left, mid), solve(mid+1, right));
	
	int low = mid;
	int high = mid+1;
	int height = min(h[low], h[high]);
	
	//�߰��κп� ��ģ ��� 
	ret = std::max(ret, height*2);
	
	//�������� �� ĭ�� Ȯ��
	//�̶� ����, ������ �� �� ū ������ Ȯ���Ѵ�.
	while (left < low || high < right) {
		//���������� Ȯ�� 
		if (high < right && (low == left || h[low-1] < h[high+1])) {
			high++;
			height = min(height, h[high]);
		}
		//�������� Ȯ�� 
		else {
			low--;
			height = min(height, h[low]);
		}
		// Ȯ���� �� �簢���� ���� 
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

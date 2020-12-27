#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7; // �� �ε���
bool check[7]; // �湮 üũ
vector<int> arr[8]; // 1���� 7���� �ε��� ó�� ��) arr[1] = 1 

void bfs(int start) {
	queue<int> q;
	q.push(start);			// 1
	check[start] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for (int i = 0; i < arr[x].size(); i++) {
			int y = arr[x][i];
			if (!check[y]) {
				q.push(y);			 //	2 3		4 5 6 7
				check[y] = true;          
			}
		}
	}
}

int main() {
	// 1�� 2 ����
	arr[1].push_back(2);
	arr[2].push_back(1);

	// 1�� 3 ����
	arr[1].push_back(3);
	arr[3].push_back(1);

	// 2�� 3 ����
	arr[2].push_back(3);
	arr[3].push_back(2);

	// 2�� 4 ����
	arr[2].push_back(4);
	arr[4].push_back(2);

	// 2�� 5 ����
	arr[2].push_back(5);
	arr[5].push_back(2);

	// 3�� 6 ����
	arr[3].push_back(6);
	arr[6].push_back(3);

	// 3�� 7 ����
	arr[3].push_back(7);
	arr[7].push_back(3);

	// 4�� 5 ����
	arr[4].push_back(5);
	arr[5].push_back(4);

	// 6�� 7 ����
	arr[6].push_back(7);
	arr[7].push_back(6);

	bfs(1);

	return 0;
}

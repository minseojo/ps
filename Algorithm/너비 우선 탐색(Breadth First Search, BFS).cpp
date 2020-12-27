#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7; // 총 인덱스
bool check[7]; // 방문 체크
vector<int> arr[8]; // 1부터 7까지 인덱스 처리 예) arr[1] = 1 

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
	// 1과 2 연결
	arr[1].push_back(2);
	arr[2].push_back(1);

	// 1과 3 연결
	arr[1].push_back(3);
	arr[3].push_back(1);

	// 2와 3 연결
	arr[2].push_back(3);
	arr[3].push_back(2);

	// 2와 4 연결
	arr[2].push_back(4);
	arr[4].push_back(2);

	// 2와 5 연결
	arr[2].push_back(5);
	arr[5].push_back(2);

	// 3과 6 연결
	arr[3].push_back(6);
	arr[6].push_back(3);

	// 3과 7 연결
	arr[3].push_back(7);
	arr[7].push_back(3);

	// 4와 5 연결
	arr[4].push_back(5);
	arr[5].push_back(4);

	// 6과 7 연결
	arr[6].push_back(7);
	arr[7].push_back(6);

	bfs(1);

	return 0;
}

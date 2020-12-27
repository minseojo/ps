#include <iostream>

using namespace std;

int parent[11];

// 부모 노드를 찾는 함수
int getParent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = getParent(parent[x]);
}

// 두 부모 노드를 합치는 함수
int unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	// 더 작은 값 으로 합침
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// 같은 부모를 가지는지 확인하는 함수
int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	else return 0;
}

int main() {
	for (int i = 1; i <= 10; i++) {
		parent[i] = i;
	}
	// 1 2 3 4 연결 
	unionParent(1, 2);
	unionParent(2, 3);
	unionParent(3, 4);
	// 5 6 7 8 연결 
	unionParent(5, 6);
	unionParent(6, 7);
	unionParent(7, 8);
	cout << "1과 5는 연결되어 있나요? " << findParent(1, 5) << endl;
	// 2 8 연결  => 1 2 3 4 5 6 7 8 모두 연결 
	unionParent(2, 8);
	cout << "1과 5는 연결되어 있나요? " << findParent(1, 5) << endl;
	return 0;
}

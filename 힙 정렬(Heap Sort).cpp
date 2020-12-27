#include <iostream>

using namespace std;

int n = 8;
int heap[8] = { 7, 6, 5, 8, 3, 5, 1, 6 };

// 최대 힙 구성
void maxHeap() {
	for (int i = 1; i < n; i++) {
		int c = i;
		while (c != 0) {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		}
	}
}

// 힙 정렬
void heapSort() {
	for (int i = n - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		while (c < i) {
			c = 2 * root + 1;
			//자식 중에 더 큰 값을 찾기
			if (c < i - 1 && heap[c] < heap[c + 1]) {
				c++;
			}
			// 부모보다 자식이 크면 교환
			if (c < i && heap[root] < heap[c]) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		}
	}
}
int main() {
	cout << "최대 힙 구성 전: ";
	for (int i = 0; i < n; i++) {
		cout << heap[i] << " ";
	}
	cout << "\n\n";
	// 최대 힙 구성
	maxHeap();
	cout << "최대 힙 구성 후: ";
	for (int i = 0; i < n; i++) {
		cout << heap[i] << " ";
	}
	cout <<"\n\n";
	// 힙 정렬
	heapSort();
	cout << "최대 힙 정렬 후: ";
	for (int i = 0; i < n; i++) {
		cout << heap[i] << " ";
	}
	return 0;
}

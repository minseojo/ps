#include <iostream>
#include <vector>
#include <algorithm>
/*
ũ�罺Į �˰��� 
������ ���� = E,	������ ���� = V��� �� ��, 
�ð� ���⵵ = O(ElogV) 
*/ 
using namespace std;

int n = 8;
int parent[8];

// �θ� ��带 ã�� �Լ�
int getParent(int x) {
	if (parent[x] == x) return x;
	else return parent[x] = getParent(parent[x]);
}

// �� �θ� ��带 ��ġ�� �Լ�
int unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	// �� ���� �� ���� ��ħ
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

// ���� �θ� �������� Ȯ���ϴ� �Լ�
int findParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return 1;
	return 0;
}


// ���� Ŭ���� ����
class Edge {
public:
	int node[2];
	int distance;
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator < (Edge& edge) {
		return this->distance < edge.distance;
	}
};
int main() {

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));
	
	// ������ ����� �������� �������� ����
	sort(v.begin(), v.end());
	
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		// ����Ŭ�� �߻����� �ʴ� ��� �׷����� ���� 
		if (!findParent(v[i].node[0], v[i].node[1])) {
			sum += v[i].distance;
			unionParent(v[i].node[0], v[i].node[1]);
		}
	}
	
	cout << sum << endl; 
	
	return 0;
}

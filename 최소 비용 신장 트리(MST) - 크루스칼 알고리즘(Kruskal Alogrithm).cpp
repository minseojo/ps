#include <iostream>
#include <vector>
#include <algorithm>
/*
크루스칼 알고리즘 
간선의 개수 = E,	정점의 개수 = V라고 할 때, 
시간 복잡도 = O(ElogV) 
*/ 
using namespace std;

int n = 8;
int parent[8];

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
	return 0;
}


// 간선 클래스 선언
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
	
	// 간선의 비용을 기준으로 오름차순 정렬
	sort(v.begin(), v.end());
	
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		// 사이클이 발생하지 않는 경우 그래프에 포함 
		if (!findParent(v[i].node[0], v[i].node[1])) {
			sum += v[i].distance;
			unionParent(v[i].node[0], v[i].node[1]);
		}
	}
	
	cout << sum << endl; 
	
	return 0;
}

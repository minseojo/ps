#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > v;
int cache[110][100010];
int n, k;

int f(int index, int w) {

	if (index == n) return 0;
	int& ret = cache[index][w];
	if (ret != -1) return ret;
	ret = 0;

	// 물건을 담지 않는 경우
	int ret2 = f(index+1, w);
	
	// 물건을 담을경우
	if (k >= w + v[index].first) {
		ret = v[index].second + f(index + 1, w + v[index].first);
	}

	ret = std::max(ret, ret2);
	return ret;
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int W, V;
		cin >> W >> V;
		v.push_back({ W,V });
	}
	memset(cache, -1, sizeof(cache));
	cout << f(0, 0);

	return 0;
}

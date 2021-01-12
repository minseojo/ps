#include <bits/stdc++.h>
using namespace std;

pair<int, int> v[1001];
int main() {
	int y,x;
	
	for(int i=0; i<3; i++) {
		cin >> y >> x;
		v[i].first = y;
		v[i].second = x;
	}
	sort(v, v+3);

	if(v[0].first == v[2].first) cout << v[1].first << " ";
	else if(v[1].first == v[2].first) cout << v[0].first << " ";
	else cout << v[2].first << " ";
	
	if(v[0].second == v[2].second) cout << v[1].second;
	else if(v[1].second == v[2].second) cout << v[0].second;
	else cout << v[2].second;
	return 0;
} 

// 다른 답안 (비트연산자 xor)
#include <stdio.h>

int main()
{
  int x1,x2,x3;
  int y1,y2,y3;

  scanf("%d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3);

  printf("%d %d\n", x1 ^ x2 ^ x3, y1 ^ y2 ^ y3);

  return 0;
} 

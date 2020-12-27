/*

계획

jominseo.tistory.com/24 에서 구했던 (check)maxPath함수를 이용하여 카운트 세준다.


문제 해결

1. 두 가지 경로, 아래 또는 오른쪽 아래로 각각 다른 루트를 전부 탐색하여 크거나 같을 경우, 재귀를 계속 들어가면서 최종 값이 같으면 카운트를 1늘려준다.

*/
#include <bits/stdc++.h>
using namespace std;
 
int arr[101][101];
int cache[101][101];
int ccache[101][101];
int n;
 
int maxPath(int y, int x)
{   
    if (y == n - 1) return arr[y][x];
    int& ret = cache[y][x];
    if (ret != -1)  return ret;
    return ret = arr[y][x] + std::max(maxPath(y + 1, x), maxPath(y + 1, x + 1));
}
 
int count(int y, int x)
{
    int& ret = ccache[y][x];
    if (y == n-1) return 1;
    if (ret != -1) return ret;
    ret = 0;
    if (maxPath(y+1, x) >= maxPath(y+1, x+1))  ret += count(y+1, x);
    if (maxPath(y+1, x+1) >= maxPath(y+1, x))  ret += count(y+1, x+1);
    return ret;
}
 
 
int main()
{
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        memset(ccache, -1, sizeof(ccache));
        memset(cache, -1, sizeof(cache));
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cin >> arr[i][j];
            }
        }
        cout << count(0, 0) << endl;
    }
 
    return 0;
}

/*

��ȹ

jominseo.tistory.com/24 ���� ���ߴ� (check)maxPath�Լ��� �̿��Ͽ� ī��Ʈ ���ش�.


���� �ذ�

1. �� ���� ���, �Ʒ� �Ǵ� ������ �Ʒ��� ���� �ٸ� ��Ʈ�� ���� Ž���Ͽ� ũ�ų� ���� ���, ��͸� ��� ���鼭 ���� ���� ������ ī��Ʈ�� 1�÷��ش�.

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

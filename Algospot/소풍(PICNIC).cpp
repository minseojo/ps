/*

��ȹ

ģ��[], ¦ ����[]�� ���� ����� ¦ ���θ� üũ�� �ش�. ¦�� �ƴ϶�� ģ��[]�� �̿��� ã���ش�.

 

���� �ذ�

ģ��[] = areFriends[], ¦ ����[] = taken[]
1. ¦�� �ƴ� ģ������ ¦�� ã���ֱ� ���� firstFree�� -1�� �ʱ�ȭ�ϰ� ¦�� ���θ� 0~n���� ã�´�.
2. ���� ¦�� �ƴ϶�� firstFree�� ¦�� ���� ģ���� ��ȣ i�� �ʱ�ȭ�ϰ� �����.
3. firstFree�� �ڱ� �ڽŰ� ¦�� �� �� �����Ƿ� firstFree+1���� n���� ���鼭 firstFree�� ģ���Ӱ� ���ÿ�
���� ¦�� �ƴ� ģ���� ã�´�. �� ������ �����ϸ� taken[firstFree]�� ���� ģ�� taekn[i]�� true�� �ٲ��ش�.
4. �� ������ �ݺ��Ѵ�.

*/
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
 
int areFriends[10][10];
bool taken[10];
int n;
 
int countPairings(bool taken[10])
{
    int firstFree = -1;
    for (int i = 0; i < n; i++) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }
    if (firstFree == -1) return 1;
    
    int ret = 0;
    for (int i = firstFree + 1; i < n; i++) {
        if (!taken[i] && areFriends[firstFree][i]) {
            taken[firstFree] = taken[i] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[i] = false;
        }
    }
 
    return ret;
}
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t, m;
    cin >> t;
    for (int T = 0; T < t; T++) {
        memset(areFriends, 0, sizeof(areFriends));
        memset(taken, 0, sizeof(taken));
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            areFriends[a][b] = areFriends[b][a] = true;
        }
        cout << countPairings(taken) << endl;
    }
 
    return 0;
}


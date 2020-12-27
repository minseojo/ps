/*

계획

친구[], 짝 여부[]를 따로 만들어 짝 여부를 체크해 준다. 짝이 아니라면 친구[]를 이용해 찾아준다.

 

문제 해결

친구[] = areFriends[], 짝 여부[] = taken[]
1. 짝이 아닌 친구들의 짝을 찾아주기 위해 firstFree를 -1로 초기화하고 짝의 여부를 0~n까지 찾는다.
2. 만약 짝이 아니라면 firstFree를 짝이 없는 친구의 번호 i로 초기화하고 멈춘다.
3. firstFree는 자기 자신과 짝이 될 수 없으므로 firstFree+1부터 n까지 돌면서 firstFree의 친구임과 동시에
아직 짝이 아닌 친구를 찾는다. 이 조건을 만족하면 taken[firstFree]와 그의 친구 taekn[i]를 true로 바꿔준다.
4. 이 과정을 반복한다.

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


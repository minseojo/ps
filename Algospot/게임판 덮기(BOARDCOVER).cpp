#include <bits/stdc++.h>
using namespace std;
 
int n, m;
int board[21][21];
// 게임판 채우는 보드 유형
int coverType[4][3][2] = {
    {{0,0},{1,0},{0,1}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}}
};
 
//게임판의 x,y 위치에서
//delta가 1이면 게임판 덮기
//delta가 -1이면 게임판 덮은거를 다시 덮음 => 초기화
bool Set(int y, int x, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; i++) {
        //x,y를 기준으로 type번째 도형의 모습
        int ny = y + coverType[type][i][0];
        int nx = x + coverType[type][i][1];
        //도형이 게임판 밖으로 나가거나 다른 도형과 겹치는지 확인
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            ok = false;
        // 중복되서 2인경우 넘어감 && 보드를 모두 다 채운후 원래상태로 되돌린다.
        else if ((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}
 
int cover() {
    int y = -1;
    int x = -1;
    // 빈칸 찾기
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        if (y!=-1 || x!=-1) break;
    }
 
    //모든 칸을 채운 경우
    if (y==-1 || x==-1) return 1;
 
    int ret = 0;
    for (int type = 0; type < 4; type++) {
        //board(y,x)를 덮을 수 있으면 덮고 다음 재귀 호출
        if (Set(y, x, type, 1))
            ret += cover();
        //덮었던 블록을 치운다
        Set(y, x, type, -1);
    }
    return ret;
}
 
int main() {
    int tc;
    cin >> tc;
 
    int y, x;
    while (tc--) {
        cin >> n >> m;
        string tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            for (int j = 0; j < m; j++) {
                if (tmp[j] == '#')
                    board[i][j] = 1;
            }
        }
        cout << cover() << endl;
        memset(board, 0, sizeof(board));
    }
 
    return 0;
}

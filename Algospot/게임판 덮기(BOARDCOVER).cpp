#include <bits/stdc++.h>
using namespace std;
 
int n, m;
int board[21][21];
// ������ ä��� ���� ����
int coverType[4][3][2] = {
    {{0,0},{1,0},{0,1}},
    {{0,0},{0,1},{1,1}},
    {{0,0},{1,0},{1,1}},
    {{0,0},{1,0},{1,-1}}
};
 
//�������� x,y ��ġ����
//delta�� 1�̸� ������ ����
//delta�� -1�̸� ������ �����Ÿ� �ٽ� ���� => �ʱ�ȭ
bool Set(int y, int x, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; i++) {
        //x,y�� �������� type��° ������ ���
        int ny = y + coverType[type][i][0];
        int nx = x + coverType[type][i][1];
        //������ ������ ������ �����ų� �ٸ� ������ ��ġ���� Ȯ��
        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            ok = false;
        // �ߺ��Ǽ� 2�ΰ�� �Ѿ && ���带 ��� �� ä���� �������·� �ǵ�����.
        else if ((board[ny][nx] += delta) > 1)
            ok = false;
    }
    return ok;
}
 
int cover() {
    int y = -1;
    int x = -1;
    // ��ĭ ã��
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
 
    //��� ĭ�� ä�� ���
    if (y==-1 || x==-1) return 1;
 
    int ret = 0;
    for (int type = 0; type < 4; type++) {
        //board(y,x)�� ���� �� ������ ���� ���� ��� ȣ��
        if (Set(y, x, type, 1))
            ret += cover();
        //������ ����� ġ���
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

/*

��ȹ

���ϵ�ī�� ���ڿ� w, ���ϸ� ���ڿ� s�� �ް�, �޸������̼��� �̿��� ����� �����ϸ鼭 ���Ѵ�.


���� �ذ�

1. cache�� -1�� �ʱ�ȭ ���ѳ��� ��ͷ� ����, -1�� �ƴ� ���� �̹� ������ ��Ȳ �̹Ƿ� �����Ѵ�.
2. w�� s���ڿ��� ������ �ʰ�, w�� ���ڿ��� '?'�� ��� �Ǵ� w�� s�� �ٸ� �� ���� ��ͷ� ����.
3. �������� ���� ���� w.size, s.size�� W, S�� ������ ���� ����  1�� �����Ѵ�.
4. ���ϵ�ī�� ���� *�� ������ ���� �Ѿ�� �ǰ�, ���ڿ��� ���� �� �ִ�.

       �Ѿ�� ��� -> check(W+1, S)
       ���ڿ� ����� ��� -> S < s.size() && check(W, S+1)
       �� ������ �����ϸ�, 1�� �����Ѵ�.
5. �� ���� ���� false

*/
#include <bits/stdc++.h>
using namespace std;
 
int cache[101][101];
string w, s;
 
bool check(int W, int S) {
    int& ret = cache[W][S];
    if (ret != -1) return ret;
    while (S < s.size() && W < w.size() && (w[W] == '?' || w[W] == s[S]))
        return ret = check(W + 1, S + 1);
 
    if (W == w.size() && S
        == s.size()) return ret = 1;
    if (w[W] == '*') {
        if (check(W + 1, S) || S < s.size() && check(W, S + 1))
            return ret = 1;
    }
 
    return ret = 0;
}
 
int main()
{
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> w;
        int n;
        cin >> n;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            memset(cache, -1, sizeof(cache));
            cin >> s;
            if (check(0, 0))
                v.push_back(s);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << endl;
    }
 
    return 0;
}


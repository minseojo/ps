/*

계획

와일드카드 문자열 w, 파일명 문자열 s를 받고, 메모이제이션을 이용해 결과를 저장하면서 비교한다.


문제 해결

1. cache를 -1로 초기화 시켜놓고 재귀로 들어간다, -1이 아닌 경우는 이미 수행한 상황 이므로 리턴한다.
2. w와 s문자열이 끝나지 않고, w의 문자열이 '?'인 경우 또는 w와 s가 다를 때 까지 재귀로 들어간다.
3. 사이즈의 수를 세는 w.size, s.size와 W, S가 같으면 같은 경우로  1을 리턴한다.
4. 와일드카드 에서 *을 만나는 경우는 넘어가도 되고, 문자열을 만들 수 있다.

       넘어가는 경우 -> check(W+1, S)
       문자열 만드는 경우 -> S < s.size() && check(W, S+1)
       이 조건을 충족하면, 1을 리턴한다.
5. 이 외의 경우는 false

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


#include <bits/stdc++.h>
using namespace std;
 
int n, i, j;
string s, t, st;
int cache[10001][3];

int check(int index, int count) {
    if (index == n - 2 && count == 2) return 1;
  
    int& ret = cache[index][count];
    if (ret != -1)  return ret;
    ret = 0;
    
    if (count == 0) {
        if (index < n - 2 && s[index] == t[index]) ret = max(ret, check(index + 1, count));
        if (t[index] == st[i]) ret = std::max(ret, check(index, count + 1));
    }
    else if (count == 1) {
        if (index < n - 2 && s[index] == t[index + 1]) ret = max(ret, check(index + 1, count));
        if (t[index + 1] == st[j]) ret = std::max(ret, check(index, count));
    }
    else {
        if (s[index] == t[index + 2]) ret = std::max(ret,check(index + 1, count));
    }

    return ret;
}

int main()
{
    cin >> n >> st >> t >> i >> j;
    for (int k = 0; k < n; k++) {
        if(k == i || k ==j) continue;
            s += st[k];
    }
    memset(cache, -1, sizeof(cache));
    if (check(0, 0)) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}

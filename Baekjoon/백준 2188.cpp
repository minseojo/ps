#include <bits/stdc++.h>
using namespace std;

vector<int> v[220];
int bin[220];
int cache[220];

int f(int index) {
    if (cache[index] != -1) return 0;
    cache[index] = 1;
    for (int i = 0; i < v[index].size(); i++) {
        int x = v[index][i];
        if (!bin[x] || f(bin[x])) {
            bin[x] = index;
            return 1;
        }
    }
    return 0;
}

int main() {
    int n, m, k, a;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> a;
            v[i].push_back(a);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        memset(cache, -1, sizeof(cache));
        if (f(i)) cnt++;
    }
    cout << cnt;

    return 0;
}

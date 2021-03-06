/*
域塙:
展析元 庚薦拭辞 姥廃 穿端 展析元 井酔税 呪拭辞 企暢 展析元 井酔税 呪研 姥背 皐層陥.
=> 企暢 展析元 井酔税 呪研 姥背操醤 敗.


庚薦 背衣:

1. 企暢 展析元税 鯵呪澗 n戚 筈呪昔 井酔人, 側呪昔 井酔稽 蟹感陥.
2. n戚 筈呪 昔 井酔, 企暢戚 鞠奄 是背辞澗 けけ | けけ 戚訓 井酔戚陥.
3. n戚 側呪昔 井酔, 企暢戚 鞠奄 是背辞澗 けけけけ暁澗 け け | | け け 戚訓 井酔戚陥.
4. 唖 井酔拭辞, 図楕 企暢 採歳聖 姥馬檎 神献楕 企暢 採歳亀 硝焼辞 衣舛吉陥. 
	魚虞辞 朔 採歳聖 辰酔澗 号狛引 1:1 企誓戚陥.
5. (2, 3, 4)拭 魚虞辞
       n戚 筈呪昔 井酔 ret = (ret - tiling(n / 2));
       n戚 側呪昔 井酔 ret = (ret - tiling((n / 2) -1)); 
6.  tiling(n) =  1000000008,
	tiling(n/2) = 100戚檎,
    tling(n) - tling(n/2)澗 -99稽 製呪亜 蟹臣 呪 赤生糠稽, MOD 葵聖 希背爽壱 蟹寛層陥.
*/
#include <bits/stdc++.h>
using namespace std;

int MOD = 1000000007;
int cache[110], cache2[110];

int tiling(int n) {
	if (n <= 1) return 1;
	int& ret = cache[n];
	if (ret != -1) return ret;
	return ret = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

int asymtiling(int n) {
	
	if (n <= 2)	return 0;
	int& ret = cache2[n];
	if (ret != -1) return ret;
	ret = tiling(n);
	ret = (ret - tiling(n / 2) + MOD ) % MOD;
	if(n % 2 == 0) ret = (ret - tiling((n / 2) -1) + MOD) % MOD;   // tiling((n/2)-1) => tiling((n-1)/2) 旭精 税耕
	return ret;
}

int main() {
	int tc, n;
	cin >> tc;
	while(tc--) {
		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));
		cin >> n;
		cout << asymtiling(n) << endl;
	}
	return 0;
}

#include <bits/stdc++.h>

using namespace std;

int arr[30];

int main()
{
	string s;
	cin >> s;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			arr[s[i] - 'a']++;
		}
		if (s[i] >= 'A' && s[i] <= 'Z') {
			arr[s[i] - 'A']++;
		}
	}
	int mx = 0, cnt = 0, mxi = 0;
	for (int i = 0; i < 30; i++) {
		if (arr[i] > mx) {
			cnt = 0;
			mx = arr[i];
			mxi = i;
		}
		else if (arr[i] == mx) cnt++;
	}
	printf("%c", cnt >= 1 ? '?' : mxi + 'A');

	return 0;
}

/*

map ÀÌ¿כ 

#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int l = s.length();
	map<char, int> mp;
	for(int i=0;i<l;i++)
		mp[s[i]]++;
	int mx = 0, mxi = 0;
	bool flag = false;
	for(int i=0;i<26;i++)
	{
		int tmp = mp[i+'a']+mp[i+'A'];
		if(mx<tmp)
		{
			mx = tmp;
			mxi = i;
			flag = false;
		}
		else if(mx==tmp) flag = true;
	}
	printf("%c", flag?'?':'A'+mxi);

	return 0;
}
*/

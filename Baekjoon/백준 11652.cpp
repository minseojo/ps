#include <bits/stdc++.h>

using namespace std;
long long arr[100001];
pair<int, long long> ret_arr[100001];

bool comp(pair<int, long long> a, pair<int, long long> b) {
	if(a.first<b.first) return 1;
	else if(a.first == b.first) {
		if(a.second>b.second) return 1;
		else return 0;
	}
	else return 0;
}
/*
1. .first가 오름차순 
2. .first같으면 내림차순 
*/
int main() {
	int n;
	cin >> n;	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	} 
	sort(arr, arr+n);
	
	int index = 0, flag=0;
	for(int i=0; i<n-1; i++) {
		if(arr[i] == arr[i+1]) {
			ret_arr[index].first++;
			ret_arr[index].second=arr[i];
			flag=1;
		}
		else index++;
	}

	sort(ret_arr, ret_arr+index+1, comp);
	if(flag == 1) cout<<ret_arr[index].second;
	else cout << arr[0];
	
	return 0;
}


#include <bits/stdc++.h>

using namespace std;
long long arr[100001];

int main() {
	int n;
	cin >> n;	
	for(int i=0; i<n; i++) {
		cin >> arr[i];
	} 
	sort(arr, arr+n);
	
	int index = 0, cnt=0, mx=0;
	for(int i=0; i<n-1; i++) {
		if(arr[i] == arr[i+1]) {
			cnt++;
			if(cnt > mx) {
				mx=cnt;
				index=i;
			}
		}
		else cnt=0;
	}
	cout << arr[index];
	
	return 0;
}

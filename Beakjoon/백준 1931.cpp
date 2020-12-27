#include <bits/stdc++.h>

using namespace std;
pair<int, int> arr[100001];

bool comp(pair<int, int> a, pair<int, int> b) {
	if(a.second < b.second) return 1;
	else if(a.second == b.second) {
		if(a.first < b.first) return 1;
		else return 0;
	}
	else return 0;	
}

int main() {
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr+n , comp);
	
	int result = 0, start = arr[0].first;
	for(int i=0; i<n; i++) {
		if(start <= arr[i].first) {
			start = arr[i].second;
			result++;
		}	
	}
	cout << result;
	
	return 0;
}

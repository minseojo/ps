#include <bits/stdc++.h>

using namespace std;

int arr[555];

int main()
{
	int h, w;
	cin >> h >> w;
	for (int i = 0; i < w; i++) {
		cin >> arr[i];
	}
	int left = 0, right = 0, sum = 0;
	
	for (int i = 1; i < w; i++) {
		left = 0, right = 0;
		for (int j = 0; j <= i; j++) left = std::max(left, arr[j]);
		for (int j = i; j < w; j++) right = std::max(right, arr[j]);

		sum += std::min(left, right) - arr[i];
	}
	cout << sum;
 }

#include <bits/stdc++.h>
using namespace std;
 
int arr[1001];
 
int main()
{
    int c,retcnt=0;
    cin >> c;
    for (int i = 0; i < c; i++) {
        int n, L, cnt=0, num=0;
        double min = 2e9;
        cin >> n >> L;
        fill_n(arr, 1001, 0);
        for (int j = 0; j < n; j++) cin >> arr[j];
        
        for (int j = 0; j < n-L+1; j++) {
            double sum = 0;
            if (cnt == 1) {
                L++; j = 0; cnt = 0;
            }
            for (int k = j; k <j+L; k++) {
                sum += arr[k];
                if (j == n - L && k == L + j - 1) {
                    cnt = 1; j = 0;
                }
                if (j == 0 && k == n-1) break;
            }
            if ((double)sum/L < min) min = (double)sum/L;
        }
 
        printf("%.12f\n", min);
    }
 
    return 0;
}

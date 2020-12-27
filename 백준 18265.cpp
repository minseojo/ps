#include <bits/stdc++.h>

using namespace std;

int arr[8] = { 1,2,4,7,8,11,13,14};

int main() {
	int n;
	cin >> n;
	int x = n / 8;
	if (n % 8 == 0) x--;
	cout <<  arr[(n - 1)%8] + x * 15;
}

/*
* 배수 없앨 때 규칙  
  
<3 * 5>  3의 배수, 5의 배수일 때, 박수치면 (3*5)15씩 차이남. 
1  2   4  7  8 11 13 14   +15
16 17 19 23 24 26 28 29   +15
31 32 34 37 38 41 43 44   +15
46 47 ...            59   +15

ex) 3 * 7    3의 배수, 7의 배수일 때 박수치면 (3*7)21씩 차이남. 
1   2   4   5   8   10   11   16   17   19   20   +21
22  23  25  26  29  31   32   37   38   40   41   +21

*/

/*
#include <bits/stdc++.h>
#define endl '\n'
typedef long long int lld;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define INF INT_MAX
using namespace std;
#define m 1000000000
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);	
	long long n;
	cin>>n;

	long long l=1, r=2000000000;
	long long ans=0;
	while(l<r)
	{
		long long mid=(l+r)/2;
		long long t1=mid/3, t2=mid/5, t3=mid/15;
		long long t4=0;
		if(mid%3==0 || mid%5==0) t4=1;
		//cout<<mid<<" "<<mid-t1-t2+t3+t4<<endl;
		if(mid-t1-t2+t3+t4>n) {
		r = mid-1; // 현재 값이 mid일때 미드 포함 작은 수의 갯수 
		}
		else {
			l = mid+1;
			ans= mid;
		}
 	}
 	//cout<<ans<<endl;
 	while(1)
 	{
 		if(ans%3==0 || ans%5==0)
 		{
 			ans++;
 		}
 		else break;
 	}
 	if(n==m) cout<<ans+1;
 	else cout<<ans<<endl;
 	//cout<<1874999999%15;

	return 0;
}
/*

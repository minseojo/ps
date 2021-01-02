#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int arr[16];
// [0] = ����� �ð� ����, [[1,6]]= ����� �ð� 
 
int Clock[10][6] = {
   	{3,0,1,2},
   	{4,3,7,9,11},
   	{4,4,10,14,15},
   	{5,0,4,5,6,7},
   	{5,6,7,8,10,12},
   	{4,0,2,14,15},
   	{3,3,14,15},
   	{5,4,5,7,14,15},
   	{5,1,2,3,4,5},
   	{5,3,4,5,9,13},
};

// ����� �ð踦 +3�� �����δ�. 
void move_clock(int cNum) {
   	for(int i=1; i<=Clock[cNum][0]; i++) {
      	if((arr[Clock[cNum][i]] += 3) > 12) {
         	arr[Clock[cNum][i]] = 3;
      	}
   	}
}


int solve(int cNum) {
	// 0~9���� ����� �ð���� +3�� ���ְ�(cNum==10), �� �ð���� 12�� ����Ű���� �� 
   	if(cNum == 10) {
      	for(int i=0; i<16; i++) {
         	if(arr[i]!=12) return INF; //�ϳ��� 12�� ����Ű�� �ʴ� ���, �ȸ����� 
      	}
      	return 0; // ��� 12�� ���, ������ => ret = ���� ���� cnt��
   }
   
   	int ret = INF;
   	for(int cnt=0; cnt<4; cnt++) { // 3, 6, 9, 12, 15=3, 18=6, 21=9, 24=12 ... ��� �����Ƿ� 4���̻���ʹ� �ǹ̰� ���� 
		ret = std::min(ret, cnt+solve(cNum+1));
		move_clock(cNum);
   	}
   	
   	return ret;
}

int main() {
   	int tc;
   	cin >> tc;
   	while(tc--) {
      	for(int i=0; i<16; i++) {
        	cin >> arr[i];
      	}
      	int result = solve(0);
      	if(result==INF) cout << -1 << endl;
    	else cout << result << endl;
   }
   
	return 0;
}

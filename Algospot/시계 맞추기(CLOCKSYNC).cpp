#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int arr[16];
// [0] = 연결된 시계 개수, [[1,6]]= 연결된 시개 
 
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

// 연결된 시계를 +3씩 움직인다. 
void move_clock(int cNum) {
   	for(int i=1; i<=Clock[cNum][0]; i++) {
      	if((arr[Clock[cNum][i]] += 3) > 12) {
         	arr[Clock[cNum][i]] = 3;
      	}
   	}
}


int solve(int cNum) {
	// 0~9까지 연결된 시계들을 +3씩 해주고(cNum==10), 그 시계들이 12를 가르키는지 비교 
   	if(cNum == 10) {
      	for(int i=0; i<16; i++) {
         	if(arr[i]!=12) return INF; //하나라도 12를 가리키지 않는 경우, 안맞춰짐 
      	}
      	return 0; // 모두 12인 경우, 맞춰짐 => ret = 가장 적은 cnt값
   }
   
   	int ret = INF;
   	for(int cnt=0; cnt<4; cnt++) { // 3, 6, 9, 12, 15=3, 18=6, 21=9, 24=12 ... 모두 같으므로 4번이상부터는 의미가 없음 
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

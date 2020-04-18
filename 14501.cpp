#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int t[16];
int p[16];
int maxx = 0;

void asd(int s, int a) { // s는 시작날짜, a는 여태 모은 이익 s를 돈받는날이라고 생각.
	if ( s  > n+1 ) return; // n+1일 날까지 될 수 있음 왜냐면 1부터 시작하므로
	if (a > maxx) maxx = a;
	 // 밑에 포문이 돌아야 일을 함.
	for (int i = s; i <= n; i++) { // n 날까지 일함.
		int sum = a + p[i]; // 이익 더함
		int day = i + t[i]; // i날 일함 // n일날 1일 일하면 n+1되고. n+1일날 퇴사이므로 그날까지도 일 가능
		asd(day, sum); // 뒤로 재귀
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) { // 1일부터 n일
		scanf_s("%d %d", &t[i], &p[i]);
	}
	for (int i = 1; i <= n; i++) { 
		asd(i + t[i], p[i]); // 시작. i날에 일하고 난 뒤
	}
	cout << maxx;
	
}
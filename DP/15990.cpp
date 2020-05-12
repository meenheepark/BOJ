#include <iostream>
using namespace std;
/*
사이트 : 백준
문제번호 : 15990
분류 : 다이나믹프로그래밍
설명 : 1,2,3 더하기  - 같은수 두번이상 반복 x d[n][1] = d[n-1][2] + d[n-1][3]
마지막에 오는 수가 1,2,3
숫자 제한이 커졌음
*/
int long long d[1000001][4]; // 여기를 롱롱으로 써줘야함 열은 1,2,3 마지막 수가 무엇인지 나타냄

int main() {
	int n;
	int mod = 1000000009;
	cin >> n;
	for (int k = 0; k < n; k++) {
		int r;
		cin >> r;
		for (int i = 1; i <= r; i++) {
			if (i - 1 >= 0) {
				d[i][1] = d[i - 1][2] + d[i - 1][3];
				if (i == 1) {
					d[i][1] = 1;
				}
			}
			if (i - 2 >= 0) {
				d[i][2] = d[i - 2][1] + d[i - 2][3];
				if (i == 2) {
					d[i][2] = 1;
				}
			}
			if (i - 3 >= 0) {
				d[i][3] = d[i - 3][1] + d[i - 3][2];
				if (i == 3) {
					d[i][3] = 1;
				}
			}
			d[i][1] %= mod;
			d[i][2] %= mod;
			d[i][3] %= mod;
		} // 겹치지않음
		cout << (d[r][1] + d[r][2] + d[r][3]) % 1000000009 << endl;
	}
}
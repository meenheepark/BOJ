#include <iostream>
using namespace std;
/*
사이트 : 백준
문제번호 : 9095
분류 : 다이나믹프로그래밍
설명 : 1,2,3 더하기 d[n] = d[n-1] + d[n-2] + d[n-3]
*/
int d[12];

int main() {
	int n;
	cin >> n;
	for (int k = 0; k < n; k++) {
		int r;
		cin >> r;
		d[0] = 1; // 1,2,3 모두 안사용 하는 방법의 수 1 
		d[1] = 1;
		d[2] = 2;
		for (int i = 3; i <= r; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		cout << d[r] << endl;
	}
}
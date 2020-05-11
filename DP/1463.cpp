#include <iostream>
using namespace std;
/*
사이트 : 백준 
문제번호 : 1463
분류 : 다이나믹프로그래밍
설명 : n 3가지 방법으로 1만드는 연산의 수 구하기, 재귀통해서 함. 
*/
int d[1000000];

int go(int n) { // 재귀이므로 top-down
	if (n == 1) return 0;
	if (d[n] > 0) return d[n];
	d[n] = go(n - 1) + 1;
	if (n % 2 == 0) {
		int temp = go(n / 2) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	if (n % 3 == 0) {
		int temp = go(n / 3) + 1;
		if (d[n] > temp) d[n] = temp;
	}
	return d[n];
}

int main() {
	int n;
	cin >> n;
	go(n);
	cout << d[n];
}

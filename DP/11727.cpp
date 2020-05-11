#include <iostream>
using namespace std;
/*
사이트 : 백준
문제번호 : 11727
분류 : 다이나믹프로그래밍
설명 : 2xN 타일 채우는 방법의 수 d[n] = d[n-1] + 2*d[n-2]
*/
int d[1001];

int main() {
	int n;
	cin >> n;
	d[1] = 1;
	d[2] = 3; // d2
	for (int i = 3; i <= n; i++) {
		d[i] = (d[i - 1] + 2*d[i - 2]) % 10007;
	}
	cout << d[n];
}
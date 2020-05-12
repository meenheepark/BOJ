#include <iostream>
#include <algorithm>
using namespace std;
/*
사이트 : 백준
문제번호 : 16294
분류 : 다이나믹프로그래밍
설명 : 커드구매하기 2 이건 최솟값을 구해야 함 d[i] = min(p[i] + d[i-j]) 이 때 j는 다 탐색
*/

int p[10001];
int d[10001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}

	for (int i = 1; i <= n; i++) {
		d[i] = 10000000; //최댓값을 넣어줌
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = min(d[i], p[j] + d[i - j]);
		}
	}
	cout << d[n] << endl;
}
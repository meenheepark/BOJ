#include <iostream>
#include <algorithm>
using namespace std;
/*
사이트 : 백준
문제번호 : 1912
분류 : 다이나믹프로그래밍
설명 : 연속합
점화식 : max(a[i], d[i-1]+a[i])
*/

int a[100001];
int d[100001]; 


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) { // d는 i번째 수로 끝나는 것
		d[i] = a[i]; // 자신 혼자
		if (i == 0) continue;
		if ( d[i] < d[i-1] + a[i] ) { //증가 j에서 시작 i에서 끝
			d[i] = d[i-1] +  a[i]; // j 까지의 합에 나 추가
		}
	}
	int maxx = d[0];
	for (int i = 1; i < n; i++) { 
		if (maxx < d[i]) maxx = d[i];
	}
	cout << maxx << endl;
}

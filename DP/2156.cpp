#include <iostream>
#include <algorithm>
using namespace std;
/*
사이트 : 백준
문제번호 : 2156
분류 : 다이나믹프로그래밍
설명 : 포도주시식
점화식 : 
*/
long long d[10001][3]; // 열은 3가지 경우, i번째 포도주를 마시지 않으면 0, 마시면1, 연속 2  
long long a[10001];


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	d[0][0] = d[0][1] = d[0][2] = 0;
	for (int i = 1; i <= n; i++) {
		d[i][0] = max({d[i - 1][0], d[i - 1][1], d[i - 1][2]}); // i 번째거 마시지 않는 겨웅
		d[i][1] = d[i - 1][0] + a[i]; // 그 전거는 마시지 않았음 이번거만 마심
		d[i][2] = d[i - 1][1] + a[i]; // 연속 마심 저번, 이번
	}
	cout << max({ d[n][0], d[n][1], d[n][2] });
}
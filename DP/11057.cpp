#include <iostream>
using namespace std;
/*
사이트 : 백준
문제번호 : 11057
분류 : 다이나믹프로그래밍
설명 : 오르막 수
주의할점 마지막이 i일때 오르막수이므로 i보다 작은 것들 다 계산
*/
long long d[1001][10]; // 여기를 롱롱으로 써줘야함 열은 마지막 수가 무엇인지

int main() {
	int n;
	int mod = 10007;
	cin >> n;
	for (int i = 0; i <= 9; i++) { // 0으로 시작가능
		d[1][i] = 1;
	} // 길이가 1인경우는 그냥 다 초기화 해야함
	for (int l = 2; l <= n; l ++) {
		for (int i = 0; i <= 9; i++) {
			d[l][i] = 0;
			for (int k = 0; k <= i; k++) { // 마지막 길이가 i일때 그것보다 작은 모든 수 
				d[l][i] += d[l - 1][k];
				d[l][i] %= mod;
			}
		}
	}
	// 답이 길이가 n일때 모든 경우의 합
	long long ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans+=d[n][i];
	}
	ans %= mod;
	cout << ans;
}
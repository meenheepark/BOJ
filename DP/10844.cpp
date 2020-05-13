#include <iostream>
using namespace std;
/*
사이트 : 백준
문제번호 : 10844
분류 : 다이나믹프로그래밍
설명 : 쉬운 계단 수
점화식 : d[l][i] = d[l-1][i-1]+d[l-1][i+1]
주의할점 - i-1,i+1이 조건의 끝일때!
*/
long long d[101][10]; // 여기를 롱롱으로 써줘야함 열은 마지막 수가 무엇인지

int main() {
	int n;
	int mod = 1000000000;
	cin >> n;
	for (int i = 1; i <= 9; i++) { // 0으로 시작하는 수는 없어서 시작 1로함
		d[1][i] = 1;
	} // 길이가 1인경우는 그냥 다 초기화 해야함
	for (int l = 2; l <= n; l ++) {
		for (int i = 0; i <= 9; i++) {
			d[l][i] = 0;
			if (i - 1 >= 0) { // 숫자범위는 0부터
				d[l][i] += d[l - 1][i - 1];
			}
			if (i + 1 <= 9) { // 숫자범위는 9까지
				d[l][i] += d[l - 1][i + 1];
			}
			d[l][i] %= mod;
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
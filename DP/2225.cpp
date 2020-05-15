#include <iostream>
#include <algorithm>
using namespace std;
/*
사이트 : 백준
문제번호 : 2225
분류 : 다이나믹프로그래밍
설명 : 합분해
점화식에 변수가 있으면 범위를 잡아주어야 한다.
d[k][n] = 모든 d[k-1][n-l]의 합(경우의 수의 합이니까) l의 범위는 0부터 n까지
*/

long long d[201][201];
long long mod = 1000000000;

int main() {
	int n, k; // k개 더해서 n 만들기
	cin >> n >> k; // 변수가 두개이므로 점화식에도 변수 두개
	d[0][0] = 1LL;
	for (int j = 1; j <= k; j++) {
		for (int i = 0; i <= n; i++) {
			for (int l = 0; l <= i; l++) {
					d[j][i] += d[j - 1][i-l]; //마지막 수는 l일때
					d[j][i] %= mod;
			}
		}
	}
	
	cout <<d[k][n]<< endl;
}

#include <iostream>
#include <algorithm>
using namespace std;
/*
사이트 : 백준
문제번호 : 9465
분류 : 다이나믹프로그래밍
설명 : 스티커 - 2XN에서 뜯음
점화식 : d[l][0] = max(d[l-1][0],d[l-1][1],d[l-1][2])
점수있는 스티커를 떼는 가장 큰 점수
브루트포스는 선택에 따라 뒤에있는 것 다 조사
이문제는 최대최대최대로 구할수있으므로 디피가능
*/
long long d[100001][3]; // 열은 3가지 경우 위/아래 ox xo xx long long 해야함 열 중심으로 봄
// 열이 0이면 안뜯음, 1이면 위뜯음, 2이면아래뜯음
// 0 이면 i-1에서는 ox xo xx 가능 세개중 최댓값
// 1이면  i-1에서는 xx xo 가능
// 2이면  i-1에서는 ox xx 가능 뗀거는 점수 더해줘야함
long long card[100001][2];


int main() {
	int n;
	cin >> n;
	for (int k = 0; k < n; k++) {
		int r;
		cin >> r;
		for (int j = 1; j <= r; j++) {
			cin >> card[j][0];
		}
		for (int j = 1; j <= r; j++) {
			cin >> card[j][1];
		}
		d[0][0] = d[0][1] = d[0][2] = 0;
		for (int i = 1; i <= r; i++) {
			d[i][0] = max({ d[i - 1][0], d[i - 1][1], d[i - 1][2] });
			d[i][1] = max(d[i - 1][0], d[i - 1][2]) + card[i][0];
			d[i][2] = max(d[i - 1][0], d[i - 1][1]) + card[i][1];
		}
		long long ans = max({ d[r][0], d[r][1], d[r][2] });
		cout << ans << endl;

	}
}
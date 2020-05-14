#include <iostream>
#include <algorithm>
using namespace std;
/*
사이트 : 백준
문제번호 : 11722
분류 : 다이나믹프로그래밍
설명 : 가장 긴 감소 부분 수열
점화식 : d[i] = max(d[j])+1
dp로 풀려면 그 전까지 답이 최대, 즉 j까지 답이 정답이어야 함
가장 긴 증가 수열에서 뒤집거나 조건을 바꿈 작게
*/

int a[1001];
int d[1001];


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		d[i] = 1; // 자신이 처음으로 포함될 경우
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i] && d[i] < d[j] + 1) { // 최대로 포함되는수.나보다 더 작고 그것을 포함한 길이가 더 클때
				d[i] = d[j] + 1; // j 까지의 합에 나 추가
			}
		}
	}
	int maxx = 0;
	for (int i = 0; i < n; i++) {
		if (maxx < d[i]) {
			maxx = d[i];
		}
	}
	cout << maxx << endl;
}

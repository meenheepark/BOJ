#include <iostream>
#include <algorithm>
using namespace std;
/*
사이트 : 백준
문제번호 : 11054
분류 : 다이나믹프로그래밍
설명 : 가장 긴 바이토닉 부분 수열
점화식 : d[i] = max(d[j])+1
dp로 풀려면 그 전까지 답이 최대, 즉 j까지 답이 정답이어야 함
가장 긴 증가 수열에서 뒤집거나 조건을 바꿈 작게
*/

int a[1001];
int d[1001]; // 감소 끝
int in[1001]; // 증가 시작


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) { // 증가수열
		d[i] = 1; // 자신이 처음으로 포함될 경우
		for (int j = 0; j < i; j++) { // i번째 수로 끝나는 증가 또는 감소 부분수열 개수구하기
			if (a[j] < a[i] && d[i] < d[j] + 1) { //증가 j에서 시작 i에서 끝
				d[i] = d[j] + 1; // j 까지의 합에 나 추가
			}
		}
	}
	for (int i = n-1; i >= 0; i--) { // 감소수열 
		in[i] = 1;
		for (int j = i+1; j < n; j++) { // i번째 수로 끝나는 증가 또는 감소 부분수열 개수구하기
			if (a[j] < a[i] && in[i] < in[j] + 1) { // 다음 것이 나보다 작다
				in[i] = in[j] + 1; // j 까지의 합에 나 추가
			}
		}
	}
	int maxx = 0;
	for (int i = 0; i < n; i++) {
		if (maxx < d[i] + in[i] - 1) {
			maxx = d[i] + in[i] - 1;
		}
	}
	cout << maxx << endl;
}

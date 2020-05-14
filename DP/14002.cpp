#include <iostream>
#include <algorithm>
using namespace std;
/*
사이트 : 백준
문제번호 : 14002
분류 : 다이나믹프로그래밍
설명 : 가장 긴 증가하는 부분수열 4 
점화식 : d[i] = max(d[j])+1
dp로 풀려면 그 전까지 답이 최대, 즉 j까지 답이 정답이어야 함
앞 문제에서 무슨 수열인지 출력
*/

int a[1001];
int d[1001];
int v[1001];

void go(int p) { // 거꾸로 탐색하면서 찾기
	if (p == -1) { // 끝 즉 처음이면 리턴. 
		return;
	}
	go(v[p]); // 이전으로 가기
	cout << a[p] << ' '; // 처음부터출력
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		d[i] = 1; // 자신이 처음으로 포함될 경우
		v[i] = -1;
		for (int j = 0; j < i; j++) {
			if (a[j] < a[i] && d[i] < d[j] + 1) { // 최대로 포함되는수.나보다 더 작고 그것을 포함한 길이가 더 클때
				d[i] = d[j] + 1;
				v[i] = j; // 증가하는것, 즉 포함되는 인덱스 저장
			}
		} k++;
	}
	int maxx = 0;
	int p;
	for (int i = 0; i < n; i++) {
		if (maxx < d[i]) {
			maxx = d[i];
			p = i;
		}
	}
	cout << maxx << endl;
	go(p);
}

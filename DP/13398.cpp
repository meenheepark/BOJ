#include <iostream>
#include <algorithm>
using namespace std;
/*
사이트 : 백준
문제번호 : 13398
분류 : 다이나믹프로그래밍
설명 : 연속합 2
삭제한 것을 모두 탐색하는 것은 시간이 오래걸리므로, 왼쪽부터 오른쪽부터 연속합의 최대를 구함
*/

int a[100001];
int dl[100001];
int dr[100001];


int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) { // d는 i번째 수로 끝나는 것
		dl[i] = a[i]; // 자신 혼자
		if (i == 0) continue;
		if ( dl[i] < dl[i-1] + a[i] ) { //증가 j에서 시작 i에서 끝
			dl[i] = dl[i-1] +  a[i]; // j 까지의 합에 나 추가
		}
	}

	for (int i = n-1; i >= 0; i--) { // d는 i번째 수로 끝나는 것
		dr[i] = a[i]; // 자신 혼자
		if (i == n-1) continue;
		if (dr[i] < dr[i+1] + a[i]) { //증가 j에서 시작 i에서 끝
			dr[i] = dr[i+1] + a[i]; // j 까지의 합에 나 추가
		}
	}

	int maxx = dl[0];
	for (int i = 1; i < n; i++) {
		if (maxx < dl[i]) maxx = dl[i];
	} // 제거하지 않아도 되므로 

	for (int i = 1; i < n-1; i++) {
		int k = dl[i - 1] + dr[i + 1];
		if (maxx < k) maxx = k;
	}
	cout << maxx<< endl;
}

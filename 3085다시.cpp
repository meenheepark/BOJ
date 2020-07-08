#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 3085
문제 이름 : 사탕게임
문제 설명 : 
*/

int n;
char b[51][51];
int check() { // 현재 바꾼 맵에서 최대로 먹을수 있는 것 체크
	int m = 1;
	for (int i = 0; i < n; i++) { // 가로로 체크
		int cnt = 1;
		for (int j = 1; j < n; j++) {
			if (b[i][j] == b[i][j - 1]) {
				cnt++;
			}
			else {
				m = max(m, cnt);
				cnt = 1;
			}
		}
		m = max(m, cnt);
	}
	for (int i = 0; i < n; i++) { // 세로로 체크
		int cnt = 1;
		for (int j = 0; j < n-1; j++) {
				if (b[j][i] == b[j+1][i]) {
					cnt++;
				}
				else {
					m = max(m, cnt);
					cnt = 1;
				}
		}
		m = max(m, cnt);
	}
	return m;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf_s("%c", &b[i][j]);
		}
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
				swap(b[i][j], b[i][j+1]);
				result = max(result, check());
				swap(b[i][j], b[i][j+1]);

				swap(b[j][i], b[j+1][i]);
				result = max(result, check());
				swap(b[j][i], b[j+1][i]);	
		}
	}
	cout << result;
}
/*
범위는 n안에서, 인접한 네 방향에 있는 어떤것과라도 바꿨을때 max_보다 커지면 대입. 최종적으로 맥스 출력
*/


#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int r, c, t;
int a[51][51] = { 0 };
int cp[51][51] = { 0 };
int dx[4] = { -1, 1, 0,0 };
int dy[4] = { 0 , 0, -1,1 };
queue <int> mq;
int wy;
int wx;

void mun(int i,int j) {
	int num = 0;
	for (int k = 0; k < 4; k++) {
		int x = i+dx[k];
		int y = j + dy[k];
		if (a[x][y] != -1 && x >= 0 && x < r && y >= 0 && y < c) {
			num++; // 퍼진 갯수 추가
			cp[x][y] += (a[i][j] / 5);
		}
	}
	cp[i][j] = cp[i][j] - (cp[i][j] / 5) * num;
}

void wind(int x, int y) {

	for (int i = wx - 1; i >= 1; i--) {
		cp[i][0] = cp[i - 1][0];
	}
	// 우측에서 좌측으로
	for (int i = 0; i < c - 1; i++) {
		cp[0][i] = cp[0][i + 1];
	}
	// 아래에서 위
	for (int i = 0; i < wx; i++) {
		cp[i][c - 1] = cp[i + 1][c - 1];
	}
	// 좌에서 우
	for (int i = c - 1; i >= 1; i--) {
		cp[wx][i] = cp[wx][i - 1];
	}
	// 정화 공기로 채워진 장소
	cp[wx][1] = 0;


	// 아래방향 순환
	// 아래에서 위 방향으로
	for (int i = wx + 2; i < r - 1; i++) {
		cp[i][0] = cp[i + 1][0];
	}
	// 좌측에서 우측으로
	for (int i = 0; i < c - 1; i++) {
		cp[r - 1][i] = cp[r - 1][i + 1];
	}
	// 위에서 아래
	for (int i = r - 1; i > wx + 1; i--) {
		cp[i][c - 1] = cp[i - 1][c - 1];
	}
	// 좌에서 우
	for (int i = c - 1; i >= 1; i--) {
		cp[wx + 1][i] = cp[wx + 1][i - 1];
	}
	// 정화 공기로 채워진 장소
	cp[wx + 1][1] = 0;
}

int main() {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> a[i][j];
			if (a[i][j] == -1) {
				wx = i;
				wy = j;
			}
		}
	}
	wx--;

	for (int i = 0; i < t; i++) { // 1초간 벌어지는 일 t번.
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				a[i][j] = cp[i][j];
			}
		}
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (a[i][j] > 0) {
					mun(i, j);
				}
				wind(wx,wy);
			}
		}

	}
	int sum = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sum+= cp[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << cp[i][j] << " ";
		}
		cout << endl;
	}
	cout << sum;
}
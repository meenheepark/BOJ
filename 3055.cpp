#include <iostream>
#include <queue>
using namespace std;
int r, c;
char b[51][51]; // 최대로 만들어버림
int a[51][51] = { 0 }; // 갈수있는 시간을 적는 배열
int z[51][51] = { 0 };
bool check[51][51] = {false}; // 방문했는지 체크하는 배열
bool check2[51][51] = { false };
int x[4] = { -1,1,0,0 };
int y[4] = { 0,0,-1,1 };

void bfs(int xxx, int yyy) {
	queue <pair<int,int>> q;
	q.push(make_pair(xxx, yyy));
	while (!q.empty()) {
		int aa = q.front().first;
		int bb = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int o = aa + x[i];
			int p = bb + y[i];
			if (o >=0 && o <r && p >= 0 && p <c ) {
				if (a[o][p] == 0 && b[o][p] == '.') { // 방문 안했다면
					a[o][p] = a[aa][bb]+1;
					q.push(make_pair(o, p));
				}
			}
		}

	}
}

void bfs2(int xxx, int yyy) { // 고슴도치 bfs
	queue <pair<int, int>> q2;
	q2.push(make_pair(xxx, yyy));
	int num = 0;
	check2[xxx][yyy] = true;
	while (!q2.empty()) {
		int aa = q2.front().first;
		int bb = q2.front().second;
		q2.pop();
		check2[aa][bb] = true;
		for (int i = 0; i < 4; i++) {
			int o = aa + x[i];
			int p = bb + y[i];
			if (o >= 0 && o < r && p >= 0 && p < c) {
				if (z[o][p] == 0 && (b[o][p] == '.' || b[o][p] == 'D')) { // 방문 안했다면
					if (a[o][p] == 0) {
						z[o][p] = z[aa][bb] + 1;
						q2.push(make_pair(o, p));
					}
					else {
						if (a[o][p] > z[aa][bb] + 1) {
							z[o][p] = z[aa][bb] + 1;
							q2.push(make_pair(o, p));
						}
					}
				}
			}
		}
		num++;
	}
}

int main() {
	cin >> r >> c;
	char k;
	int xs, ys, xd, yd;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> k;
			b[i][j] = k;
			if (k =='S') {
				xs = i;
				ys = j;
			}
			if (k == 'D') {
				xd = i;
				yd = j;
			}
		}
	} // 입력 다 받고
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (b[i][j] == '*') {
				bfs(i, j);
				//cout << i << j << endl;
			}
		}
	}


	
	bfs2(xs, ys);
/*
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << a[i][j];
		}
		cout << endl;
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << z[i][j];
		}
		cout << endl;
	}
*/

	if (z[xd][yd] != 0) {
		cout << z[xd][yd] << endl;
	}
	else {
		cout << "KAKTUS";
	}
	//cout << a[xs][ys];
}
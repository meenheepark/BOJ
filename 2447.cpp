#include <iostream>
using namespace std;

char star[3000][3000];
int n;

void re(int num, int x, int y) {
	if (num == 1) {
		star[x][y] = '*';
		return;
	}

	int div = num / 3;
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cnt++;
			if (cnt != 5) re(div, x + i * div, y + j * div);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < 2188; i++) {
		for (int j = 0; j < 2188; j++) {
			star[i][j] = ' ';
		}
	}
	re(n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << star[i][j];
		}
		cout << endl;
	}
}
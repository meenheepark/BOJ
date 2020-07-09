#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 1018
문제 이름 : 체스판다시칠하기
문제 설명 : 
*/

int n, m;
int mini = 64; // 최소로 칠해야하는 수
char ches[51][51];
int result = 0;
int blk[51][51];

void check(int idx_i, int idx_j) { // 시작인덱스
	int cnt = 0;
	int prev = 0;
	for (int i = 0; i < 8; i++) {
		prev = blk[idx_i + i-1][idx_j + 7];
		for (int j = 0; j < 7; j++) {
			if (j == 0) {
				if (i != 0 && prev != blk[idx_i + i][idx_j + j]) { // 같지않으면 나를 바꾸기
					cnt++;
					blk[idx_i + i][idx_j + j] = prev;
				}
				if (blk[idx_i + i][idx_j + j] == blk[idx_i + i][idx_j + j + 1]) {
					cnt++;
					if (blk[idx_i + i][idx_j + j+1] == 0) blk[idx_i + i][idx_j + j + 1] = 1;
					else blk[idx_i + i][idx_j + j+1] = 0;
				}
			}
			else if (j != 0 && blk[idx_i + i][idx_j + j] == blk[idx_i + i][idx_j + j + 1]) { // 색칠해야하는 경우
				cnt++;
				//cout << "x y" << idx_i + i << idx_j + j << endl;
				if (blk[idx_i + i][idx_j + j + 1] == 0) {blk[idx_i + i][idx_j + j + 1] = 1; }
				else { blk[idx_i + i][idx_j + j + 1] = 0;  }
			}
			
		}
	}
	//cout << cnt << endl;
	int k;
	k = min(cnt, 64 - cnt);
	mini = min(mini, k);
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << blk[i][j];
		}
		cout << endl;
	}*/
	 //첫블럭을 색칠할때와 안할때 전체는 cnt , 64 - cnt이므로 더 작은것을 min에 넣는다.
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> ches[i][j];
			if (ches[i][j] == 'B') { blk[i][j] = 0; }
			else{ blk[i][j] = 1; }
		}
	}

	for (int i = 0; i + 7 < n; i++) {
		for (int j = 0; j + 7 < m; j++) {
			check(i, j);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (ches[i][j] == 'B') { blk[i][j] = 0; }
					else { blk[i][j] = 1; }
				}
			}
		}
	}

	
	cout << mini << endl;
}
/*
8 8
BBBBBBBB
BBBBBBBB
BBBBBBBB
BBBBBBBB
BBBBBBBB
BBBBBBBB
BBBBBBBB
BBBBBBBB
*/


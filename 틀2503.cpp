#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 2503
문제 이름 : 숫자야구
문제 설명 : 
*/

int n;
int num[1001];
int p[3][10];
int ball[10]; // 볼이면 1로.
int k[100][3][10];

int check(int i, int q, int s, int b) { // i는 가능성이 있는것, q는 물어본 것.
	int s_cnt = 0, b_cnt = 0;
	int i_1 = i / 100, i_2 = (i % 100) / 10, i_3 = (i % 100) % 10;
	int q_1 = q / 100, q_2 = (q % 100) / 10, q_3 = (q % 100) % 10; // 세자릿수쪼개기

	if (i_1 == 0|| i_2 == 0|| i_3 == 0 || i_1 == i_2 || i_2 == i_3 || i_1 == i_3) { // 각각다른수여야하므로, 0이 있으면안됨
		return 0;
	}

	if (i_1 == q_1) s_cnt++;
	if (i_2 == q_2) s_cnt++;
	if (i_3 == q_3) s_cnt++;

	if (i_1 == q_2 || i_1 == q_3) b_cnt++;
	if (i_2 == q_1 || i_2 == q_3) b_cnt++;
	if (i_3 == q_1 || i_3 == q_2) b_cnt++;

	if (s == s_cnt && b == b_cnt) {
		return 1;
	}
	return 0;
}

int main()
{
	cin >> n;
	vector <int> ball;
	for (int i = 0; i < n; i++) {
		int q, s, b;
		cin >> q >> s >> b;
		for (int i = 123; i <= 987; i++) {
			if (num[i] == 0) {
				num[i] = !check(i, q, s, b);
			}
		}
		
	}
	int result = 0;
	for (int i = 123; i <= 987; i++) {
		if (num[i] == 0) {
			result++;
		}
	}

	cout << result << "\n";
}
/*

*/


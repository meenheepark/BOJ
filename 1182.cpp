#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 1182
문제 이름 : 부분수열의 합
문제 설명 : 
*/

int n, s, cnt = 0;
int ary[21];

void check(int idx, int sum) { // 나 자신을 더한것도 돌고 안더한것도 돌고, 범위는 인덱스내부.
	if (idx == n) { // 마지막에가서까지 더하는 경우도 있어서 이렇게해줘여함
		if (sum == s) { cnt++;}
		return;
	}
	check(idx + 1, sum + ary[idx]); // 더하거나
	check(idx + 1, sum); // 안더하거나
}

int main()
{
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> ary[i];
	}
	check(0, 0);
	if (s == 0) cnt--; // 아무것도 안더할 경우를 빼줘여함....이거완전 함정.
	cout << cnt;


}
/*

*/


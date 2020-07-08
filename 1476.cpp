#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
백준
문제 번호 : 1476
문제 이름 : 날짜계산
문제 설명 : 점화식 세울것..
*/
int e, s, m; // 15, 28, 19
int year;
int main()
{
	cin >> e >> s >> m;
	int year = 1;
	while (1) {
		if ((year - e) % 15 == 0 && (year - s) % 28 == 0 && (year - m) % 19 == 0) {
			cout << year;
			break;
		}
		year++;
	}

}
/*
15로 나눠서 맞는지 보고 28로 나눠서 보기 19로 나눳 보기.
세개 다 나눈 나머지가 같은 것.
*/


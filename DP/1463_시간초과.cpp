#include <iostream>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 1463
문제 이름 : 1로만들기
문제 설명 : 연산하는 최솟값구하기, 3으로나누기,2로나누기 1빼기
시간초과가 되기쉽다.. 했던것은 찍어두고 다시 안하는 메모이제이션이 필요함....
memset(a, 65, sizeof(a)); 배열초기화@@@
*/
const int MAX = 1000001;
int n;
int dp[MAX];


int check(int num) {
	if (num == 1) return 0;
	if (dp[num] != -1) return dp[num]; // 이미구한거있으면.

	int result = check(num - 1) + 1;
	if (num % 3 == 0) {
		result = min(check(num / 3)+1, result);
	}
	if (num % 2 == 0) {
		result = min(check(num / 2)+1, result);
	}
	dp[n] = result;
	return result; // 계산횟수
}

int main()
{
	cin >> n;
	fill(dp, dp + MAX, -1);
	cout << check(n);

}
/*

*/


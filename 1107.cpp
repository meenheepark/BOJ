#include <iostream>
#include <vector>
using namespace std;
/*
백준
문제 번호 : 1107
문제 이름 : 리모컨
문제 설명 : 999999에서 500000까지 내려가는 경우도 있어서(버튼 9만가능)이러면 범위 1000000까지잡아야함
*/
int m;
int minn = 1000000; // 최소 버튼 횟수 .. 사실 최대 100만번
int broken[11]; // 고장난 리모컨 번호는 1로 세팅
int goal; // 가고자 하는 채널번호

int check(int a) { // 해당 번호로 갈 수 있는지 리턴. 못가면 0번리턴
	int len = 0;
	if (a == 0) {
		return broken[0] ? 0 : 1; // broken0이 0이면 1 1이면 0리턴
	}
	while (a) {
		len++;
		if (broken[a % 10] == 1) return 0; // 하나라도 안되는 버튼이 있으면 0리턴
		a /= 10; // 한자릿수 위 검사
	}
	return len; // 할수있는 자릿수 리턴.
}

int main()
{
	cin >> goal;
	cin >> m; // k혹은. 비슷한 곳 가서 위아래 찾기중에 더 작은것 출력
	int k = goal - 100; // k는 그냥 100에서 위또는 아래로만 내려서 찾기.
	if (k < 0) k = k * (-1);
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		broken[k] = 1;
	}
	int r, buttonlen;
	for (int i = 0; i < 1000001; i++) {
		r = check(i); // 전수검사함
		if (r != 0) { // 해당 숫자로 갈수가 있음. 거기서 목표로 갈수있는지?
			int a = goal - i;
			if (a < 0) a = a * (-1);
			if (a < minn) {
				minn = a; // 최소횟수를 계속 업뎃
				buttonlen = r; // 숫자 몇번누를것인지.
			}
		}
	}
	int num2 = minn + buttonlen;
	if (k < num2) {
		cout << k;
	}
	else {
		cout << num2;
	}

}
/*

*/


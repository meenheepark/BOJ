#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 2231
문제 이름 : 분해합
문제 설명 : 
*/

int n;
int main()
{
	cin >> n;
	for (int i = 0; i <= 1000000; i++) {
		int sum = i;
		int k = i;
		while (k != 0) {
			int r = k % 10;
			sum += r;
			k /= 10;
		}
		if (sum == n) {
			cout << i;
			return 0;
		}
	}
	cout << "0";
}
/*
216보다 작은수 중에 그 수와 자릿수를 더해서 주어진n과 같으면 출력.. 가장 작은 생성자라면 아래에서부터 구해야하는지?
숫자는 9가 최대니까 자릿수만큼 9를 뺀것에서 해본다..??
사실 그게 아니어도n이 1000000밖에 안돼서 다해봐도 될것같음.
*/


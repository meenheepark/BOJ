#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 10448
문제 이름 : 유레카이론
문제 설명 : 삼각수 세개의 합으로 나타낼수있으면 1, 아니면 0출력
*/

int n;

int check(int k) {
	int sum = k;
	int en = 0;
	for (int i = 1; i <= 100; i++) { // 주어진수에서 삼각수 하나 빼고
		sum = k;
		int num = (i * (i + 1)) / 2; // 삼각수 구함.
		sum -= num;
		for (int j = 1; j <= 100; j++) { // 두번째삼각수빼고
			int sum2 = sum;
			int num2 = (j * (j + 1)) / 2; // 삼각수 구함.
			sum2 -= num2;
			for (int r = 1; r <= 47; r++) { // 세번째 삼각수까지 뺐을때 0이면 리턴. 아니면 1리턴.
				int sum3 = sum2;
				int num3 = (r * (r + 1)) / 2; // 삼각수 구함.
				sum3 -= num3;
				if (sum3 == 0) {
					return 1;
				}
			}
		}
	}
	return 0;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		int result = check(k);
		cout << result << "\n";
	}
}
/*
삼각수는 n(n+1)/2 이거..
*/


#include <iostream>
#include <algorithm>
using namespace std;
/*
사이트 : 백준
문제번호 : 1699
분류 : 다이나믹프로그래밍
설명 : 제곱수의 합
주어진 자연수 n을 제곱수들의 합으로 나타내고 그 항의 최소갯수
d[n] = min(d[n-i^2] + 1) i제곱으은 일보다 크고 엔보다 작음
*/

int d[100001];


int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		d[i] = i; 
		for (int j = 1; j * j <= i; j++) {
			if (d[i] > d[i - j*j] + 1) { // 마지막이 i 제곱인것
				d[i] = d[i - j*j] + 1; //제이 제곱을 뺀것보다 하나 많다. 그것은 아이제곱
			}
		}
	}
	cout <<d[n]<< endl;
}

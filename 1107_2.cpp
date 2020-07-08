#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
백준
문제 번호 : 2309
문제 이름 : 일곱난쟁이
문제 설명 : 
*/


int main()
{
	vector <int> v;
	for (int i = 0; i < 9; i++) {
		int k;
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		sum += v[i];
	}
	int sum2 = sum;
	int check = 0;
	for (int a = 0; a < 8; a++) {
		sum2 -= v[a];
		for (int b = a + 1; b < 9; b++) {
			int r = sum2 - v[b];
			if (r == 100) {
				check = 1;
				v[a] = 0;
				v[b] = 0;
				break;
			}
		}
		if (check == 1) break;
		sum2 = sum;
	}
	for (int i = 0; i < 9; i++) {
		if (v[i] != 0) {
			cout << v[i] << "\n";
		}
	}
}
/*

*/


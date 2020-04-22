#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[4] = { 0 }; // 탄사람
int b[4] = { 0 }; // 내린사람
int c[4] = { 0 };

int main() {
	for (int i = 0; i < 4; i++) {
		scanf_s("%d %d", &a[i], &b[i]);
	}
	int sum = 0;
	int max = 0;
	for (int i = 0; i < 4; i++) {
		c[i] = (b[i] - a[i]);
		sum += c[i];
		//cout << sum << endl;
		if (max < sum) max = sum;
	}

	cout << max;

}
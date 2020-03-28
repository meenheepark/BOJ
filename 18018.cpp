#include <iostream>
#include <algorithm>
using namespace std;


int n, m,sum=0;
int main() {
	cin >> n;
	int a[1000001];
	int min = 1000000;
	int max = -1000000; // 범위에 유의할것
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (min > a[i]) min = a[i];
		if (max < a[i]) max = a[i];
	}

	printf("%d %d\n", min, max);
}
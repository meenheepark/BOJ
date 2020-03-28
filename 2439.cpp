#include <iostream>
using namespace std;
int a[1000001], b = -1000001, s = 1000001, n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k < n-i; k++) {
			printf(" ");
		}
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		cout << endl;
	}
}



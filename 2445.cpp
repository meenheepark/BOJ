#include <iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		for (int k = 0; k < 2*(n-i); k++) {
			printf(" ");
		}
		for (int k = 0; k < i; k++) {
			printf("*");
		}
		cout << endl;
	}
	for (int i = 1; i < n ; i++)
	{
		for (int k = 0; k < n-i; k++) {
			printf("*");
		}
		for (int k = 0; k < 2 * (i); k++) {
			printf(" ");
		}
		for (int k = 0; k < n - i; k++) {
			printf("*");
		}
		cout << endl;
	}
}


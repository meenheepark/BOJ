#include <iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int k = 1; k <= n-i; k++) {
			printf(" ");
		}
		for (int k = 1; k < i+1; k++) {
			printf("*");
		}
		cout << endl;
	}
	for (int i = 1; i < n ; i++)
	{
		for (int k = 1; k <= i; k++) {
			printf(" ");
		}
		for (int k = 1; k <= n-i; k++) {
			printf("*");
		}
		cout << endl;
	}
}


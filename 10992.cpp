#include <iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		{
			for (int k = 1; k <= n - i; k++) {
				printf(" ");
			}
			if (i == 1 || i == n) {
				for (int k = 1; k <= 2 * i - 1; k++) {
					printf("*");
				}
			}
			else {
				printf("*");
				for (int j = 1; j <= 2 * (i-1) - 1; j++) {
					printf(" ");
				}
				printf("*");
			}
			cout << endl;
		}
}


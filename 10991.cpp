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
		for (int k = 1; k < 2*i; k++) {
			if(k%2 == 0) printf(" ");
			if (k % 2 == 1) printf("*");
		}
		cout << endl;
	}
}


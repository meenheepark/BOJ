#include <iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < i; k++) {
			printf(" ");
		}
		for (int k = 0; k < n-i; k++) {
			printf("*");
		}

		cout << endl;
	}
}



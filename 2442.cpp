#include <iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n-i-1; k++) {
			printf(" ");
		}
		for (int k = 0; k < 2*(i+1)-1; k++) {
			printf("*");
		}

		cout << endl;
	}
}


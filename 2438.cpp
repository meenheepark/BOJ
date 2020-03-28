#include <iostream>
using namespace std;
int a[1000001], b = -1000001, s = 1000001, n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < i+1; k++) {
			printf("*");
		}
		cout << endl;
	}
}



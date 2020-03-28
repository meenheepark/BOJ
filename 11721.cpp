#include <iostream>
#include <string.h>
using namespace std;

int n, sum=0;
int main() {
	char a[100];
	cin >> a;
	int k;
	for (int i = 0; i < strlen(a) ; i++) {
		cout << a[i];
		if (i % 10 == 9) {
			cout << endl;
		}
	}

}
#include <iostream>
#include <string.h>
using namespace std;

int n, sum=0;
int main() {
	cin >> n;
	for (int i = 1; i< 10; i++) {
		printf("%d * %d = %d\n", n, i, n*i);
	}

}
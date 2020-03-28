#include <iostream>
#include <string.h>
using namespace std;


int n, m,sum=0;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += i;
	}
	cout << sum;
}
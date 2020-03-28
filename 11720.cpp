#include <iostream>
#include <string>
using namespace std;

int n, sum=0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		scanf_s("%1d", &k);
		sum += k;
	}
	cout << sum;
}
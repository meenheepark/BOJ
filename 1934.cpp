#include <iostream>
using namespace std;
int gcd(int a, int b);

int main() {
	int t,g;
	int a, b;
	int r[45000] = {0};
	cin >> t ;
	for (int i = 0; i < t; i++) {
		cin >> a >> b ;
		g = gcd(a, b);
		r[i] = a * b / g;
	}
	g = gcd(a, b);
	for (int i = 0; i < t; i++) {
		cout << r[i]<< endl;
	}
	return 0;
}

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}
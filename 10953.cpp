#include <iostream>
#include <vector>
using namespace std;

int a, b, t;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		scanf_s("%d, %d", &a, &b);
		cout <<a + b<<endl;
	}
	char c;
	for (int i = 0; i < t; i++) {
		cin >> a >> c >> b;
		cout <<a + b<<endl;
	}
	return 0;
} // , 찍는법


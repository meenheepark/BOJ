#include <iostream>
using namespace std;
int gcd(int a, int b);

int main() {
	int t,g = 0;
	int a = 0;
	int r[100] = {0};
	int z[100] = { 0 };
	sum = 0;
	cin >> t ;
	for (int i = 0; i < t; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> r[j];
		}
		for (int z = 0; z < k-1; z++) {
			for (int j = z; j < k; j++) {
				if(r[z] > r[j+1]) g = gcd(r[z], r[j + 1]);
				else g = gcd(r[j+1], r[z]);
				sum += g;
			}
		}
		z[i] = sum;
		cin >> endl;
	}
	for (int i = 0; i < t; i++) {
		cout << z[i]<< endl;
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
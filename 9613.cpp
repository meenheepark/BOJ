#include <iostream>
using namespace std;
int gcd(int a, int b);

int main() {
	int t,k,g = 0;
	int a = 0;
	int r[100] = {0};
	int z[100] = { 0 };
	int sum = 0;
	cin >> t ;
	for (int i = 0; i < t; i++) {
		cin >> k;
		for (int j = 0; j < k; j++) {
			cin >> r[j];
		}
		for (int z = 0; z < k-1; z++) {
			for (int j = z+1; j < k; j++) {
				if(r[z] > r[j]) g = gcd(r[z], r[j ]);
				else g = gcd(r[j], r[z]);
				sum += g;
			}
		}
		z[i] = sum;
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
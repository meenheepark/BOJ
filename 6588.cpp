#include <iostream>
using namespace std;
bool prime(int n);
const MAX = 1000000;

int main() {
	int a,i;
	int check[1000000] = { 0 };
	while (true) {
		cin >> a;
		if (a == 0) break;
		for (i = 2; i < a / 2; i++) {
			if (prime(i)&&prime(a-i)){
				check[i] = i;
				cout << a << '=' << check[i] << '+' << a - check[i] << endl;
		}
	}
	return 0;
}

bool prime(int n){ 
	if (n < 2) { return false; }
	for (int i = 2; i*i <= n; i++) 
	{ 
		if (n % i == 0) { return false; }
	}
	return true;
}
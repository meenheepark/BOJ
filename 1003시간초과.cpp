#include <iostream> 
using namespace std;

int t, n;
int zero = 0;
int one = 0;

int fibonacci(int n) {
	if (n == 0) {
		zero++;
		return 0;
	}
	else if (n == 1) {
		one++;
		return 1;
	}
	else {
		int k = n - 1;
		return fibonacci(k) + fibonacci(k-1);
	}
};

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		fibonacci(n);
		cout << zero << " " << one << endl;
		zero = 0;
		one = 0;
	}
}
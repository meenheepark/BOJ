#include <iostream> 
using namespace std;

int t, x;
int dp[41];
int fibonacci(int n) {
	if (n <= 0) {
		dp[0] = 0;
		return 0;
	}
	else if (n == 1) {
		dp[1] = 1;
		return 1;
	}
	if (dp[n] != 0) { // 이미 방문 했으므로
		return dp[n];
	}
	else {
		return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
};


int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> x;
		if (x == 0) {
			printf("1 0\n");
		}
		else if (x == 1) {
			printf("0 1\n");
		}
		else {
			fibonacci(x);
			printf("%d %d\n", dp[x - 1], dp[x]); // 공식이있음111
		}
	}
}
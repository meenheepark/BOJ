#include <iostream>

using namespace std;
int n;
int D[1001] = {0};

int dp(int k) {
	if (k == 1) return 1;
	else if (k == 2) return 2;
	if (D[k] != 0) {
		return D[k];
	}
	else {
		D[k] = (dp(k - 1) + dp(k - 2)) % 10007;
		return D[k];
	}
}

int main() {
	cin >> n;
	int num = 0;
	cout << dp(n);
}
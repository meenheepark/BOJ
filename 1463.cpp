#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;
int main() {
	cin >> n;
	int dp[1000001];
	dp[0] = dp[1] = 0;
	for (int i = 2; i <= n; i++) { // 0부터 시작해서 n을 만들어가는 과정.. 빼는건 필요없음
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0) dp[i] = min(dp[i], dp[i / 3] + 1);
	}
	cout << dp[n];
}
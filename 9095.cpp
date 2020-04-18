#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n;

int main() {
	cin >> n;
	for (int j = 0; j < n; j++) {
		int d[11];
		int k;
		cin >> k;
		d[1] = 1;
		d[2] = 2;
		d[3] = 4;
		for (int i = 4; i <= k; i++) {
			d[i] = d[i - 1] + d[i - 2] + d[i - 3];
		}
		cout << d[k] << endl;
	}

}
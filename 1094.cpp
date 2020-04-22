#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
int x;

int main() {
	cin >> x;
	vector <int> v;
	v.push_back(64);
	int sum = 64;
	int min = 0;
	while (sum>x) {
		//printf("ds");
		int k = v[min] / 2;
		if (sum - k >= x) {
			v[min] = k;
			sum -= k;
		}
		else {
			v[min] = k;
			v.push_back(k);
		}
		for (int i = 0; i < v.size(); i++) {
			if (v[min] >= v[i]) {
				v[min] = v[i];
				min = i;
			}
		}
		if (sum == x) break;
	}

	cout << v.size();
}
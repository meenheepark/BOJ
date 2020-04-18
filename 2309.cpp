#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[9];

int main() {
	vector <int> a;
	int sum = 0;
	for (int i = 0; i < 9; i++) {
		cin >> n;
		a.push_back(n);
		sum += n;
	}
	//cout << sum << endl;
	sort(a.begin(), a.end());
	int z = 0;
	int b = 0;
	int g,r;

	for (int i = 0; i < 9; i++) {
		int g = sum;
		g = g - a[i];
		//cout << g;
		for (int j = i+1; j < 9; j++) {
			r = g - a[j];
			if (r == 100) {
				z = i;
				b = j;
				break;
			}
		}
	}
	vector <int> k;
	for (int i = 0; i < 9; i++) {
		if (i != z && i != b) k.push_back(a[i]);
	}
	for (int i = 0; i < 7; i++) {
		cout << k[i] << endl;
	}
}
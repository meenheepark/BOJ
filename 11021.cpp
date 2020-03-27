#include <iostream>
#include <vector>
using namespace std;

int a, b, t;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		cout <<"Case #"<<i+1<<": "<<a + b<<endl;
	}
	return 0;
}
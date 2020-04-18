#include <iostream>
using namespace std;
int n;
int i;
int main() {
	cin >> n;
	int num = 0;
	if (n < 100) num = n;
	else num = 99; // 백보다 작을땐 무조건임
	for (int j = 100; j <= n; j++) {
		int a = 0;
		int i = j; // 조건문에 있는 변수 건들지 말것
		int b;
		bool check = true;
		b = a;
		int k = i % 10; 
		i = i / 10;
		int r = i % 10;
		a = k - r; // 새로운 찻수
		do{
			b = a;  
			k = i % 10; 
			i = i / 10;
			r = i % 10 ;
			a = k - r; // 새로운 찻수
			//cout << 'i'<< i << endl;
			//cout << 'a'<< a << endl;
			//cout << 'b' << b << endl;
			if (b != a) {
				check = false;
			}
			//cout << i << endl;
		} while (i / 10 != 0);
		if (check == true)  num++;
	}
	cout << num;
}
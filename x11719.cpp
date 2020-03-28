#include <iostream>
#include <string>
using namespace std;
int main() {
	string text;
	while (getline(cin, text)) { // 빈줄가능?
		cout << text << endl;
	}
}
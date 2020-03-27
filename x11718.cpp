#include <iostream>
#include <string>
#include <vector>
using namespace std;
 // 문자열을 통째로 저장하는 string 자료형
 // 한줄을 입력받아 저장할 수 있는 getline함수 사용
int a, b, t;
int main() {
	string str;
	while (1) {
		getline(cin, str);
		if (str == "") break; // 안받으면 끝냄
		cout << str << endl;
	}
	return 0;
}
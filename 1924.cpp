#include <iostream>
#include <string.h>
using namespace std;

string day[7] = {"SUN", "MON", "TUE", "WED", "THU" , "FRI", "SAT" };
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int n, m,sum=0;
int main() {
	cin >> n >> m;
	sum += m;
	for (int i = 0; i < n-1; i++) {
		sum += month[i];
	}
	int k = (sum % 7);
	cout << day[k];
}
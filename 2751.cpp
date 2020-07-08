#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
백준
문제 번호 : 2751
문제 이름 : 수 정렬하기 2
문제 설명 : endl이 시간이 오래걸린다.. "\n"으로 바꿀것. 그리고 ios_base::sync_with_stdio(false);이것 추가
입출력 시간이 빨라짐
*/
int n;
int a[1000001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    vector <int> v;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        v.push_back(k);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) {
        cout << v[i] << "\n";
    }
}


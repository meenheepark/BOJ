#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#include <vector>
int t, n,m,k;
//우선순위 큐에 중요도를 넣게 되면 C++에서 제공하는 STL에서 자동으로 크기가 큰 순으로 정렬 해줍니다.
int main() {
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		queue <pair<int, int>> q;
		priority_queue <int> pq;
		int sum = 0;
		for (int j = 0; j < n; j++) {
			cin >> k;
			q.push({ j, k });
			pq.push(k);
		}
		while (!q.empty()) {
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value) {
				pq.pop();
				sum++;
				if (index == m) {
					cout << sum << endl;
					break;
				}
			}
			else {
				q.push({ index, value });
			}
		}
	}


}
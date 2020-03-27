#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> g[2000]; // 한 정점에 이어진 리스트
bool exe[2000][2000]; //  존재 유무
vector <pair <int, int>> edges; // 간선들
int main() {
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		edges.push_back({ from, to });
		edges.push_back({ to, from });
		g[from].push_back(to);
		g[to].push_back(from);
		exe[from][to] = true;
		exe[to][from] = true;
	}
	m *= 2; // 방향 없어서 두번입력하므로 두배 해줘서 포문 돌림
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			int A = edges[i].first;
			int B = edges[i].second;
			int C = edges[j].first;
			int D = edges[j].second; // 두개의 간선 만듦
			if (A == B || A == C || A == D || B == C || B == D || C == D) {
				continue; // continue문은 break같음. 밑에 실행안하고 다음반복 실행.
			//같은 친구 관계가 두 번 이상 주어지는 경우는 없다. A-D까지 검사
			}
			if (!exe[B][C]) {
				continue;
			}
			for (int E : g[D]) {
				if (A == E || B == E || C == E || D == E) {
					continue; // E간선 검사
				}
				cout << 1 << endl;
				return 0;
			}
		}
	}
	cout << 0 << '\n';
	return 0;
}